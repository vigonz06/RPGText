#ifndef MY_DATE
#define MY_DATE

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <sstream>
#include <string>
#include <ctime>

typedef std::time_t Date;

std::string showDate(Date d);

std::string upDate();

#endif // !MY_DATE