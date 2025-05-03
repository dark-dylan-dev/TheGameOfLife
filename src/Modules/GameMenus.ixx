module;

#include <SFML/Graphics.hpp>

export module GameMenus;

import std;
import GameConsole;

// Keeps the variables alive
namespace {
	// Ensures that loadMenus() is only called once
	bool calledLoadMenus = false;
	// For thread safety
	std::mutex mtx;
	// --- Start menu --- //
	// ...Rectangles
	sf::RectangleShape playButton;
	sf::RectangleShape settingsButton;
	sf::RectangleShape quitButton;
	// ...Sprites
	sf::Sprite startMenuBackground;
	// ...Textures (<element>Texture)
	sf::Texture startMenuBackgroundTexture;
	// ...Colors (<element>Color)
	sf::Color buttonColorHovered(200U, 200U, 200U);
	// ...Fonts
	sf::Font pixelMix;
	// ...Texts
	sf::Text titleText;
	sf::Text playButtonText;
	sf::Text settingsButtonText;
	sf::Text leaveButtonText;
	sf::Text footerText;

	// --- Settings menu --- //

	// --- In game HUD --- //
}

////////////////////////////////////////////////////////////
/// \brief Useful for centering shapes
///
////////////////////////////////////////////////////////////
static sf::Vector2f centerShape(const sf::Shape& shape) {
	return sf::Vector2f{shape.getLocalBounds().getSize() / 2.f };
}

////////////////////////////////////////////////////////////
/// \brief Useful for centering texts
///
////////////////////////////////////////////////////////////
static sf::Vector2f centerText(const sf::Text& text) {
	return sf::Vector2f{ 
		text.getLocalBounds().getSize() / 2.f - sf::Vector2f{ 0, text.getLocalBounds().top }
	};
}

////////////////////////////////////////////////////////////
/// \brief Enumeration of the different application menus
///
////////////////////////////////////////////////////////////
export enum Menu {
	Start,    /// < Start menu, shows when the app starts.
	Settings, /// < Settings menu, shows when you enter the settings.
	In_Game   /// < In game menu, more like an HUD that shows in game.
};

////////////////////////////////////////////////////////////
/// \brief Loads every element contained in all game menus
///
////////////////////////////////////////////////////////////
export void loadMenus() {
	if (calledLoadMenus)
		return;
	// --- Start menu --- //
	startMenuBackgroundTexture.loadFromFile("../assets/img/startMenu/background.png")
		? startMenuBackground.setTexture(startMenuBackgroundTexture)
		: Console::Log("Start menu background PNG file couldn't be loaded!", PROBLEM);

	if(!pixelMix.loadFromFile("../assets/fonts/pixelmix.ttf")) 
		Console::Log("PixelMix font couldn't be loaded", PROBLEM);

	// --- Settings menu --- //

	//...

	// --- In game HUD --- //

	//...

	calledLoadMenus = true;
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
		// Play button
		playButton.setSize(sf::Vector2f(xPercent * 25, yPercent * 10));
		playButton.setOutlineThickness(3);
		playButton.setFillColor(sf::Color::White);
		playButton.setOutlineColor(sf::Color::Black);
		playButton.setPosition(screenCenter - centerShape(playButton));
		playButtonText.setFont(pixelMix);
		playButtonText.setString("Play");
		playButtonText.setFillColor(sf::Color::Black);
		playButtonText.setPosition(screenCenter - centerText(playButtonText));
		// Settings button
		settingsButton.setSize(sf::Vector2f(xPercent * 25, yPercent * 10));
		settingsButton.setOutlineThickness(3);
		settingsButton.setFillColor(sf::Color::White);
		settingsButton.setOutlineColor(sf::Color::Black);
		settingsButton.setPosition(screenCenter - centerShape(playButton) + sf::Vector2f{0.f, playButton.getSize().y});
		settingsButtonText.setFont(pixelMix);
		settingsButtonText.setString("Settings");
		settingsButtonText.setFillColor(sf::Color::Black);
		settingsButtonText.setPosition(settingsButton.getPosition() + centerShape(settingsButton) - centerText(settingsButtonText));
		
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
	std::lock_guard<std::mutex> lock(mtx);
	sf::Vector2f mouseMovePos{ static_cast<float>(event.mouseMove.x), static_cast<float>(event.mouseMove.y) };
	sf::Vector2f mouseClickPos{ static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y) };
	switch (toPoll) {
	case Start:
		// Play button
		if (playButton.getGlobalBounds().contains(mouseMovePos))
			playButton.setFillColor(buttonColorHovered);
		else
			playButton.setFillColor(sf::Color::White);
		// Settings button
		if (settingsButton.getGlobalBounds().contains(mouseMovePos))
			settingsButton.setFillColor(buttonColorHovered);
		else
			settingsButton.setFillColor(sf::Color::White);
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
		//window.draw(startMenuBackground);
		window.draw(playButton);
		window.draw(playButtonText);
		window.draw(settingsButton);
		//window.draw(quitButton);
		break;

	case Settings:
		break;

	case In_Game:
		break;

	default:
		break;
	}
}