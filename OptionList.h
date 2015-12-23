#ifndef OPTIONLIST
#define OPTIONLIST

#include "List.h"
#include <string>
#include <fstream>
#include "checkML.h"

class OptionList: public List<std::string>
{
public:

	bool load(std::ifstream &file);
};

bool OptionList::load(std::ifstream &file)
{
	int n;
	std::string* option;

	file >> n;

	for (int i = 0; i < n; i++)
	{
		option = new std::string;

		file >> *option;
		list[counter++] = option;

		if (file.fail()) return false;
	}
	return true;
}
#endif