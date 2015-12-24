#include "Globalconstants.h"
#include "GraphInter.h"
#include "UtilsWin.h"
#include <iostream>
#include <iomanip>
#include <sstream>

GraphInter* GraphInter::inter = nullptr;

GraphInter* GraphInter::get()
{
	return inter;
}

void GraphInter::load()
{
	if (inter == nullptr)
	{
		inter = new GraphInter;
	}
}

void GraphInter::close()
{
	if (inter != nullptr)
	{
		delete inter;
		inter = nullptr;
	}
}

void GraphInter::pause()
{
	std::cin.sync();
	std::cin.get();
}

std::string GraphInter::linea()
{
	std::ostringstream line;

	line << std::setfill('-')
		<< std::setw(HORIZONTAL) << '-'
		<< std::setfill(' ');

	return line.str();
}

void GraphInter::enter(std::string &word)
{
	std::cin.sync();
	std::getline(std::cin, word);
	std::cin.clear();
}

void GraphInter::enter(int &digit)
{
	std::cin.sync();
	std::cin >> digit;
	std::cin.clear();
}

void GraphInter::display(std::string error)
{
	std::cout << error << std::endl;
}

bool GraphInter::find(std::ifstream &file, std::string scentinel)
{
	return true; //placeholder

	//to do David
	//la funcion debe localizar el centinela, 
	//y situar la variable archivo en esa posicion, 
	//de manera que lo proximo que se obtenga del archivo
	//sea lo correspondiente a dicho centinela
	//si no encuentra el centinela, devuelve false
}

std::string GraphInter::get(std::string filename, std::string scentinel)
{
	std::ifstream file;
	std::string line, text = "";

	file.open(filename);

	if (file.is_open())
	{
		if (find(file, scentinel))
		{
			do
			{
				std::getline(file, line);
				text += line + '\n';
			} while (line != "");

			file.close();

			return text;
		}
		else
		{
			file.close();

			return "Text not found";
		}
	}
	else return "File not found";
}

Menu* GraphInter::substract(std::string filename, std::string scentinel)
{
	std::ifstream file;
	Menu* menu;

	file.open(filename);

	if (file.is_open())
	{
		if (find(file, scentinel))
		{
			menu = new Menu;

			if (!menu->load(file))
			{
				delete menu;

				file.close();

				return nullptr;
			}
			else
			{
				file.close();

				return menu;
			}
		}
		else
		{
			file.close();

			return nullptr;
		}
	}
	else return nullptr;
}

int GraphInter::update(int key, int elem, int max_elems)
{
	if (key == UP) elem--;
	else if (key == DOWN) elem++;

	if (elem < 0) elem = max_elems - 1;
	else if (elem >= max_elems) elem = 0;

	if (key == ESCAPE) elem = max_elems - 1;
	return elem;
}

int GraphInter::menu(Menu* menu)
{
	int key = UP, elem = 0;

	do
	{
		display("Choose your desired option: ");

		for (int i = 0; i < menu->length(); i++)
		{
			tab_word(*(menu->operator[](i)), i, elem);
		}

		key = getKey();
		elem = update(key, elem, menu->length());

		clearConsole();

	} while (key != ENTER && key != ESCAPE);

	return elem;
}

void GraphInter::tab_word(std::string word, int pos, int cont)
{
	if (pos == cont)
	{
		word = "->" + word;
	}
	else
	{
		word = tab_word(word);
	}
	display(word);
}

std::string GraphInter::tab_word(std::string word)
{
	std::ostringstream tab;

	tab << std::setw(word.size() + 2) << word;

	return tab.str();
}

std::string GraphInter::center_word(std::string word, int length, std::string arround)
{
	if (word.size() != length)
	{
		for (int i = word.size(); i < length; i++)
		{
			if (word.size() % 2 == 0)
			{
				word = word + arround;
			}
			else if (word.size() % 2 == 1)
			{
				word = arround + word;
			}
		}
	}
	return word;
}

std::string GraphInter::put_right(std::string word, int length, std::string arround)
{
	if (word.size() != length)
	{
		for (int i = word.size(); i < length; i++)
		{
			word = arround + word;
		}
	}
	return word;
}
