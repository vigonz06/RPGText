#ifndef FILE
#define FILE

#include "Menu.h"
#include <string>
#include <fstream>

bool find(std::ifstream &file, std::string scentinel)
{
	std::string ignore;

	do
	{
		std::getline(file, ignore);
	} while (ignore != scentinel && !file.eof());

	if (ignore == scentinel) return true;

	else return false;
}

std::string get(std::string filename, std::string scentinel)
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

Menu* substract(std::string filename, std::string scentinel)
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

#endif