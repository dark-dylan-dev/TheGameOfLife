module;

#include <SFML/Graphics.hpp>
#include <iostream>

export module GameSetup;

import GameConsole;

// Keeps the variables alive
namespace {
	sf::Image cursorImg("../assets/cursors/pointer.png");
	sf::Cursor cursor(cursorImg.getPixelsPtr(), cursorImg.getSize(), sf::Vector2u(0U, 0U));
	sf::Image appIcon("../assets/img/icon.png");
}

////////////////////////////////////////////////////////////
/// \brief Loads images used by the app.
///
/// \param window : Window that prints the splash screen
////////////////////////////////////////////////////////////
export void splashScreen(sf::RenderWindow& window) {
	Console::Log("Setting up the splash screen...");
	// TODO: Add a splash screen.
}

////////////////////////////////////////////////////////////
/// \brief Loads images used by the app.
////////////////////////////////////////////////////////////
export void loadImages() {
	Console::Log("Loading images...");
}

////////////////////////////////////////////////////////////
/// \brief Loads fonts used by the app.
////////////////////////////////////////////////////////////
export void loadFonts() {
	Console::Log("Loading fonts...");
}

////////////////////////////////////////////////////////////
/// \brief Sets up the mouse cursor.
/// 
/// \param Window affected by the cursor modification
////////////////////////////////////////////////////////////
export void setupCursor(sf::RenderWindow& window) {
	Console::Log("Setting up the mouse cursor...");
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