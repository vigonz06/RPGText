#ifndef LIST
#define LIST

#include "GlobalConstants.h"
#include <string>
#include <fstream>

/*----------------------------
This is a base class for all the lists this program has
We have used a template to be able to work whith diferent
types of arguments.
The list is dynamic and resizes automatically when inserting elements.
On destruction deletes every dynamic object held.
To prevent this (ie elements held should not be destroyed), call erase in child destructor.
By default, the list orders itself according to the valor returned by getId method of
elements inserted. If you choose to override insert to prevent order, make sure you override
search as well (it is a binary search)
------------------------------*/

//Template for lists
template <class T>
class List
{
public:
    List() : counter(0), list(nullptr)
    {
        init(START_ELEMS);
    }
    ~List()
    {
        release();
    }

    inline bool full() const
    {
        return counter == dim;
    }
    inline int length() const
    {
        return counter;
    }

    T* operator [](int i)
    {
        return list[i];
    }

    void pushback(T* elem);//añadido
    int HowMany();//añadido
    T* returnElement(const int index);//añadido
    T* search(const std::string id);//añadido

    bool insert(T* elem);
    bool destroy(const std::string &id); //Deletes element and erases from list.

    //bool pop(T* elem); //Erases elem from list. WARNING: Does not delete!
    //void erase(); //Points list to null. Doesn't delete

    bool search(const std::string id, int &pos, int ini, int fin) const;
    T* get(const std::string &id);

    void save(const std::string &name);
    bool load(const std::string &name);

protected:
    int counter, dim;
    T** list;

    void shiftRight(const int pos);
    void shiftLeft(const int pos);

    void init(int dim);
    void release();
    void resize(int dim);
};


template<class T>
T* List<T>::search(const std::string id)
{
    for(int i = 0; i < counter; i++){
        if(list[i]->id == id){
            return list[i];
        }
    }
    return nullptr;
}

template<class T>
T* List<T>::returnElement(const int index)
{
    if(index <= counter){
        return list[index];
    }
    else{
        return nullptr;
    }
}


template<class T>
int List<T>::HowMany()
{
    return counter;
}



template<class T>
void List<T>::pushback(T* elem)
{
    insert(elem);
}

template<class T>
bool List<T>::insert(T* elem)
{
    if (full()) resize(dim + 1);
    int pos;
    int ini = 0, fin = counter - 1;
    search(elem->id, pos, ini, fin);
    shiftRight(pos);
    list[pos] = elem;
    counter++;
    return true;
}

template<class T>
bool List<T>::destroy(const std::string &id)
{
    int pos;
    int ini = 0, fin = counter - 1;
    if (search(id, pos, ini, fin))
    {
        delete list[pos];
        list[pos] = nullptr;
        return true;
    }
    else return false;
}

/*template<class T>
bool List<T>::pop(T* elem)
{
	int pos;
	int ini = 0, fin = counter - 1;
	if (search(elem->getId(), pos, ini, fin))
	{
		list[pos] = nullptr;
		return true;
	}
	else return false;
}
template<class T>
void List<T>::erase()
{
	for (int i = 0; i < counter; i++)
	{
		list[i] = nullptr;
	}
	counter = 0;
}*/

template<class T>
bool List<T>::search(const std::string id, int &pos, int ini, int fin) const
{
    if (ini <= fin)
    {
        pos = (ini + fin) / 2;

        if (list[pos]->id == id) return true;

        if (list[pos]->id < id) ini = pos + 1;

        if (list[pos]->id > id) fin = pos - 1;

        return search(id, pos, ini, fin);
    }
    else
    {
        pos = ini;

        return false;
    }
}

template<class T>
T* List<T>::get(const std::string &id)
{
    int pos = 0;
    int ini = 0, fin = counter - 1;
    if (search(id, pos, ini, fin))
    {
        return list[pos];
    }
    else
    {
        return nullptr;
    }
}

template<class T>
void List<T>::save(const std::string &name)
{
    std::ofstream file(name);

    for (int i = 0; i < this->length(); i++)
    {
        this->list[i]->save(file);
    }
    file.close();
}
template<class T>
bool List<T>::load(const std::string &name)
{
    std::ifstream file(name);
    bool right;
    T* elem;


    if (file.is_open())
    {
        right = true;

        while (right)
        {
            elem = new T;

            if (!elem->load(file))
            {
                delete elem;
                right = false;
            }
            else this->insert(elem);
        }

        file.close();

        return true;
    }
    else return false;
}

template<class T>
void List<T>::shiftRight(const int pos)
{
    for (int i = counter; i > pos; i--)
    {
        list[i] = list[i - 1];
    }
}

template <class T>
void List<T>::shiftLeft(const int pos)
{
    for (int i = pos; i < counter; i++)
    {
        list[i] = list[i + 1];
    }
}

template<class T>
void List<T>::init(int dim)
{
    if (dim <= 0)
    {
        list = nullptr;
        this->dim = 0;
    }
    else
    {
        list = new T*[dim];

        for (int i = 0; i < dim; i++)
        {
            list[i] = nullptr;
        }

        this->dim = dim;
    }
    this->counter = 0;
}

template<class T>
void List<T>::release()
{
    if (this->dim != 0)
    {
        for (int i = 0; i < this->counter; i++)
        {
            delete list[i];
            list[i] = nullptr;
        }
        delete[] list;
        list = nullptr;
        this->counter = 0;
        this->dim = 0;
    }
}

template<class T>
void List<T>::resize(int dim)
{
    if (dim > this->dim)
    {
        T** newlist = new T*[dim];

        for (int i = 0; i < counter; i++)
        {
            newlist[i] = list[i];
        }
        for (int i = counter; i < dim; i++)
        {
            newlist[i] = nullptr;
        }
        delete[] list;

        list = newlist;
        this->dim = dim;
    }
}
#endif
