#include "LogManager.h"

#include <iostream>

void LogManager::log(const std::string msg)
{
#ifdef DEBUG
	std::cout << "LogManager: " << msg << std::endl;
#endif
}

void LogManager::goToLog(Node& node)
{
#ifdef DEBUG
	std::cout << "LogManager: Node number " << node.getNumber() << " was started exploring!" << std::endl;
#endif
}

void LogManager::goBackLog(Node& node)
{
#ifdef DEBUG
	std::cout << "LogManager: Node number " << node.getNumber() << " was finished exploring!" << std::endl;
#endif
}