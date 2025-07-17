#pragma once
#include "Node.h"
#include <string>

//#define DEBUG

namespace LogManager
{
	void log(const std::string msg);

	void goToLog(Node& node);

	void goBackLog(Node& node);
}