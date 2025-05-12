module;

#include <SFML/Graphics.hpp>

export module GameSetup;

import GameConsole;

// Keeps the variables alive
namespace {
	sf::Image cursorImg;
	sf::Image appIcon;
	sf::Cursor cursor(sf::Cursor::Type::Arrow);
}

////////////////////////////////////////////////////////////
/// \brief Loads images used by the app.
////////////////////////////////////////////////////////////
export void loadImages() {
	Console::Log("Loading images...");
	if (!cursorImg.loadFromFile("../assets/cursors/pointer.png")) {
		Console::Log("Cursor texture didn't successfully load.", PROBLEM);
	}
	if (!appIcon.loadFromFile("../assets/img/icon.png")) {
		Console::Log("Window icon didn't successfully load.", PROBLEM);
	}
}

////////////////////////////////////////////////////////////
/// \brief Sets up the mouse cursor.
/// 
/// \param Window affected by the cursor modification
////////////////////////////////////////////////////////////
export void setupCursor(sf::RenderWindow& window) {
	Console::Log("Setting up the mouse cursor...");
	cursor = sf::Cursor(cursorImg.getPixelsPtr(), cursorImg.getSize(), {0U, 0U});
	window.setMouseCursor(cursor);
}

////////////////////////////////////////////////////////////
/// \brief Sets up the window icon
/// 
/// \param Window affected by the icon modification
////////////////////////////////////////////////////////////
export void setupIcon(sf::RenderWindow& window) {
	Console::Log("Setting up the window icon...");
	window.setIcon(appIcon);
}