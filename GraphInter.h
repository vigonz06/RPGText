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

	bool find(std::ifstream &file, std::string scentinel);
	std::string get(const std::string filename, std::string scentinel);
	Menu* substract(const std::string filename, std::string scentinel);

private:

	static GraphInter* inter;

	GraphInter() {}

	int update(int key, int elem, int max_elems);

	int menu(Menu* menu);

	void tab_word(std::string word, int pos, int cont);
	std::string tab_word(std::string word);

	std::string center_word(std::string word, int length, std::string arround);
	std::string put_right(std::string word, int length, std::string arround);
};
#endif
