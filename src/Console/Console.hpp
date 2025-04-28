#pragma once

#include <string>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>

enum ImportanceLevel {
	BASIC,
	PROBLEM,
	CRITICAL
};

class Console {
public:
	static void Log(const std::string& message, ImportanceLevel importance = BASIC);
};