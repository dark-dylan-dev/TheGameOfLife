module;

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

export module GameConsole;

////////////////////////////////////////////////////////////
/// \brief Enumeration of the different importance levels
/// of a console log
////////////////////////////////////////////////////////////
export enum ImportanceLevel {
	BASIC,   /// < Used for default messages
	PROBLEM, /// < Used to signal a mistake
	CRITICAL /// < Used to signal an error / an exception
};

////////////////////////////////////////////////////////////
/// \brief Outputs timed messages in the console
////////////////////////////////////////////////////////////
export class Console {
public:
	Console() = delete;
	static void Log(const std::string& message, const ImportanceLevel& importance = BASIC);
};

////////////////////////////////////////////////////////////
/// \brief Outputs timed messages in the console
///
/// \param message : Message to be printed
/// \param importance : Optional importance parameter,
/// default value is BASIC
////////////////////////////////////////////////////////////
export void Console::Log(const std::string& message, const ImportanceLevel& importance) {
	// Get a formatted HH:MM:SS string of the current time (e.g: 11:23:54)
	std::tm newTime;
	const std::time_t now = std::time(nullptr);
	std::string time;

	// Checks if localtime_s() was unsuccessful
	if (localtime_s(&newTime, &now) != 0) {
		time = "Unknown time";
	}
	else {
		std::ostringstream oss;
		oss << std::put_time(&newTime, "%H:%M:%S");
		time = oss.str();
	}

	// Prints console message depending on the importance level (default = BASIC)
	std::cout << "---" << '\n';
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
}