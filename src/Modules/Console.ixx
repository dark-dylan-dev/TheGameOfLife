module;

#include <string>
#include <time.h>
#include <iomanip>
#include <iostream>
#include <sstream>

export module GameConsole;

export enum ImportanceLevel {
	BASIC,
	PROBLEM,
	CRITICAL
};

export class Console {
public:
	static void Log(const std::string& message, ImportanceLevel importance = BASIC);
};

export void Console::Log(const std::string& message, ImportanceLevel importance) {
	// Get a formatted HH:MM:SS string of the current time (e.g: 11:23:54)
	tm newTime;
	std::time_t now = std::time(nullptr);
	localtime_s(&newTime, &now);
	std::ostringstream oss;
	oss << std::put_time(&newTime, "%H:%M:%S");
	std::string time = oss.str();

	// Prints console message depending on the importance level (default = BASIC)
	std::cout << "[" << time << "] ";

	switch (importance) {
	case BASIC:
		std::cout << "Info" << '\n'
			<< " > " << message << '\n';
		break;

	case PROBLEM:
		std::cout << "Issue" << '\n'
			<< " > " << message << '\n';
		break;

	case CRITICAL:
		std::cout << "Critical" << '\n'
			<< " > " << message << '\n';
		break;

	default:
		break;
	}

	std::cout << '\n';
}