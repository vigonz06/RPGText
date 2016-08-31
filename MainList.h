#ifndef MAINLIST
#define MAINLIST

#include <string>
#include <vector>

template<class T>
class List
{
protected:

	std::vector<T> list;

	bool search(const std::string &id, int &pos, int &ini, int &fin);

public:

	List() { list.clear(); }
	~List() { list.clear(); }

	T get(const std::string &id);

	bool destroy(const std::string &id);
	bool insert(T elem);

	bool load(const std::string &id);
	void save(const std::string &id);
};

template<class T>
bool List<T>::search(const std::string &id, int &pos, int &ini, int &fin)
{
	if (ini <= fin)
	{
		pos = (ini + fin) / 2;

		if (list[pos].getId() == id) return true;

		if (list[pos].getId() < id) ini = pos + 1;

		if (list[pos].getId() > id) fin = pos - 1;
		
	}
	else
	{
		pos = ini;

		return false;
	}
}

template <class T>
T List<T>::get(const std::string &id)
{
	int pos = 0, ini = 0, fin = list.size() - 1;

	if (search(id, pos, ini, fin)) return list[pos];
}

template <class T>
bool List<T>::destroy(const std::string &id)
{
	int pos = 0, ini = 0, fin = list.size() - 1;

	if (search(id, pos, ini, fin))
	{
		list.erase(pos);

		return true;
	}
	else return false;
}

template <class T>
bool List<T>::insert(T elem)
{
	int pos = 0, ini = 0, fin = list.size() - 1;

	if (!search(elem.getId(), pos, ini, fin))
	{
		list.insert(pos, elem);

		return true;
	}
	else return false;
}

template <class T>
bool List<T>::load(const std::string &id)
{
	std::ifstream file;
	bool right;
	T elem;

	file.open(name);

	if (file.is_open())
	{
		right = true;

		while (right)
		{
			elem = new T;

			if (!elem.load(file))
			{
				right = false;
			}
			else insert(elem);
		}

		file.close();

		return true;
	}
	else return false;
}

template <class T>
void List<T>::save(const std::string &id)
{
	std::ofstream file;

	file.open(name);

	for (T i : list)
	{
		i.save(file);
	}

	file << "XXX";

	file.close();
}

#endif