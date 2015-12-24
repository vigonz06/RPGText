#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <algorithm>
#include "Date.h"
#include <time.h>

std::string showDate(Date d)
{
	std::ostringstream resultado;
	tm ltm;
	localtime_s(&ltm, &d);
	resultado << 1900 + ltm.tm_year << '/' << 1 + ltm.tm_mon << '/' 
		<< ltm.tm_mday << " (" << ltm.tm_hour << ':' << ltm.tm_min << ')';
	return resultado.str();
}

std::string upDate()
{
	Date date;

	date = time(0);

	return showDate(date);
}