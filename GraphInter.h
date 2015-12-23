#ifndef GRAPHINTER
#define GRAPHINTER

#include <string>
#include "Menu.h"

class GraphInter
{
public:

	static GraphInter* get(); //Returns the single instance of grapHinter
	static void load(); //Creates the singleton
	static void close(); //Deletes the singleton

	void pause();
	std::string linea();
	inline void clearConsole() { system("cls"); };

	std::string valid_user();

	void enter(std::string &word);
	void enter(int &digit);

	//Output
	void display(std::string error);

private:

	static GraphInter* inter;

	GraphInter() {}//to prevent instantation

	int update(int key, int elem, int max_elems);

	int menu(Menu* menu);

	//Formatting strings
	std::string center_word(std::string word, int length, std::string arround);
	void tab_word(std::string word, int pos, int cont);
	std::string tab_word(std::string word);
};
#endif