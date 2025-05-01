module;

#include <SFML/Graphics.hpp>

export module GameMenus;

import GameConsole;

// Keeps the variables alive
namespace {
	// Start menu
	// ...Rectangles
	sf::RectangleShape playButton;
	sf::RectangleShape settingsButton;
	sf::RectangleShape quitButton;
	// ...Textures (<name>Texture)
	sf::Texture settingsButtonTexture;

	// Settings menu

	// In game HUD
}

////////////////////////////////////////////////////////////
/// \brief Enumeration of the different application menus
///
////////////////////////////////////////////////////////////
export enum Menu {
	Start,    // !< Start menu, shows when the app starts.
	Settings, // !< Settings menu, shows when you enter the settings.
	In_Game   // !< In game menu, more like an HUD that shows in game.
};

////////////////////////////////////////////////////////////
/// \brief Loads every element contained in all game menus
///
////////////////////////////////////////////////////////////
export void loadMenus() {
	// Start menu
	if (!settingsButtonTexture.loadFromFile("../assets/img/startMenu/settingsIcon.png"))
		Console::Log("Settings button icon couldn't be loaded.", PROBLEM);
}

////////////////////////////////////////////////////////////
/// \brief Sets up a chosen menu relative to the current
///		   window size
///
/// \param window : Window affected by the menu setup
/// \param toSetup : Menu to be setup
/// 
////////////////////////////////////////////////////////////
export void setupMenu(sf::RenderWindow& window, Menu toSetup) {
	float xPercent = window.getSize().x / 100.f;
	float yPercent = window.getSize().y / 100.f;

	sf::Vector2f screenCenter = {
		static_cast<float>(window.getSize().x) / 2.f,
		static_cast<float>(window.getSize().y) / 2.f
	};

	switch (toSetup) {
	case Start:
		break;

	case Settings:
		break;

	case In_Game:
		break;

	default:
		break;
	}
}

////////////////////////////////////////////////////////////
/// \brief Polls the events of a specified menu
///
/// \param window : Window affected by the the event polling
/// \param toPoll : Menu targetted by the event polling
/// 
////////////////////////////////////////////////////////////
export void pollMenuEvents(sf::RenderWindow& window, sf::Event& event, Menu toPoll) {
	switch (toPoll) {
	case Start:
		break;

	case Settings:
		break;

	case In_Game:
		break;

	default:
		break;
	}
}

////////////////////////////////////////////////////////////
/// \brief Draws a chosen menu on the chosen window
///
/// \param window : Window affected by the draw call
/// \param toDraw : Menu to be drawn
/// 
////////////////////////////////////////////////////////////
export void drawMenu(sf::RenderWindow& window, Menu toDraw) {
	switch (toDraw) {
	case Start:
		window.draw(playButton);
		window.draw(settingsButton);
		window.draw(quitButton);
		break;

	case Settings:
		break;

	case In_Game:
		break;

	default:
		break;
	}
}