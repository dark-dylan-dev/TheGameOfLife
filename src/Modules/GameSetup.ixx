module;

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

export module GameSetup;

import GameConsole;

// Keeps the variables alive
namespace {
	sf::Image cursorImg;
	sf::Cursor cursor;
	sf::Image appIcon;
}

////////////////////////////////////////////////////////////
/// \brief Loads images used by the app.
///
/// \param window : Window that prints the splash screen
/// 
////////////////////////////////////////////////////////////
export void splashScreen(sf::RenderWindow& window) {

}

////////////////////////////////////////////////////////////
/// \brief Loads images used by the app.
///
////////////////////////////////////////////////////////////
export void loadImages() {
	if (!cursorImg.loadFromFile("../assets/cursors/pointer.png"))
		Console::Log("Cursor pointer couldn't be loaded", PROBLEM);
	if (!appIcon.loadFromFile("../assets/img/icon.png"))
		Console::Log("Window icon couldn't be loaded", PROBLEM);
}

////////////////////////////////////////////////////////////
/// \brief Loads fonts used by the app.
///
////////////////////////////////////////////////////////////
export void loadFonts() {

}

////////////////////////////////////////////////////////////
/// \brief Sets up the mouse cursor.
/// 
/// \param Window affected by the cursor modification
/// 
////////////////////////////////////////////////////////////
export void setupCursor(sf::RenderWindow& window) {
	cursor.loadFromPixels(cursorImg.getPixelsPtr(), cursorImg.getSize(), sf::Vector2u{0U, 0U});
	window.setMouseCursor(cursor);
}

////////////////////////////////////////////////////////////
/// \brief Sets up the window icon
/// 
/// \param Window affected by the icon modification
/// 
////////////////////////////////////////////////////////////
export void setupIcon(sf::RenderWindow& window) {
	window.setIcon(appIcon.getSize().x, appIcon.getSize().y, appIcon.getPixelsPtr());
}