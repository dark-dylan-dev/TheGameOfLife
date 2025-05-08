module;

#include <SFML/Graphics.hpp>

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
export void splashScreen(sf::RenderWindow& window) {}

////////////////////////////////////////////////////////////
/// \brief Loads images used by the app.
////////////////////////////////////////////////////////////
export void loadImages() {}

////////////////////////////////////////////////////////////
/// \brief Loads fonts used by the app.
////////////////////////////////////////////////////////////
export void loadFonts() {}

////////////////////////////////////////////////////////////
/// \brief Sets up the mouse cursor.
/// 
/// \param Window affected by the cursor modification
////////////////////////////////////////////////////////////
export void setupCursor(sf::RenderWindow& window) {
	window.setMouseCursor(cursor);
}

////////////////////////////////////////////////////////////
/// \brief Sets up the window icon
/// 
/// \param Window affected by the icon modification
////////////////////////////////////////////////////////////
export void setupIcon(sf::RenderWindow& window) {
	window.setIcon(appIcon);
}