#include "Console.hpp"

void Console::Log(const std::string& message, ImportanceLevel importance) {
	// Get a formatted HH:MM:SS string of the current time
	std::time_t now = std::time(nullptr);
	std::tm* localTime = std::localtime(&now);
	std::ostringstream oss;
	oss << std::put_time(localTime, "%H:%M:%S");
	std::string time = oss.str();

	// Prints console message depending on the importance level
	switch (importance) {

	case BASIC:
		std::cout << "[" << time << "] LOG" << '\n' 
			<< " > " << message << '\n' << '\n';
		break;

	case PROBLEM:
		std::cout << "[" << time << "] PROBLEM" << '\n'
			<< " > " << message << '\n' << '\n';
		break;

	case CRITICAL:
		std::cout << "[" << time << "] CRITICAL" << '\n'
			<< " > " << message << '\n' << '\n';
		break;

	default:
		break;

	}
}