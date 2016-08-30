#ifndef PLAYER
#define PLAYER

#include <string>
#include <fstream>

struct Player
{
	std::string id;
	int health;
	int power;

	//Coord coord;

	std::string getId() { return id; }

	bool load(const std::string &name);
	void save(const std::string &name);
};

bool Player::load(const std::string &name)
{
	std::ifstream file;

	file.open(name);

	if (file.is_open())
	{
		file >> id;
		file >> health;
		file >> power;

		//file >> coord.x;
		//file >> coord.y;

		file.close();

		return true;
	}
	else return false;
}

void Player::save(const std::string &name)
{
	std::ofstream file;

	file.open(name);

	file << id << std::endl
		<< health << std::endl
		<< power << std::endl;
		//coord.x << std::endl
		//coord.y << std::endl
}

#endif