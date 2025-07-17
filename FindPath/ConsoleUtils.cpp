#include "ConsoleUtils.h"

#include <iostream>

std::string ConsoleUtils::getInput(const std::string prompt)
{
	std::cout << prompt << ": ";
	std::string input;
	std::getline(std::cin, input);
	return input;
}

void ConsoleUtils::clearScreen()
{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}