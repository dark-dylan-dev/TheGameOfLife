module;

#include <SFML/Graphics.hpp>
#include <concepts>
#include <locale>
#include <string>

export module GameMenus;

import GameConsole;

// Keeps the variables alive
namespace {
	// Ensures that loadMenus() is only called once
	bool calledLoadMenus = false;
	// --- Start menu --- //
	// ...Rectangles
	sf::RectangleShape playButton;
	sf::RectangleShape settingsButton;
	sf::RectangleShape quitButton;
	// ...Textures (<element>Texture)
	sf::Texture startMenuBackgroundTexture("../assets/img/startMenu/background.png");
	// ...Sprites
	sf::Sprite startMenuBackground(startMenuBackgroundTexture);
	// ...Colors (<element>Color)
	sf::Color buttonColorHovered(200U, 200U, 200U);
	// ...Fonts
	sf::Font pixelMix("../assets/fonts/pixelmix.ttf");
	// ...Texts
	sf::Text titleText(pixelMix);
	sf::Text playButtonText(pixelMix);
	sf::Text settingsButtonText(pixelMix);
	sf::Text quitButtonText(pixelMix);
	sf::Text footerText(pixelMix);

	// --- Settings menu --- //

	// --- In game HUD --- //
}

////////////////////////////////////////////////////////////
/// \brief Concepts used for templates
////////////////////////////////////////////////////////////
template<typename T>
concept CanBeCentered = requires(T elem) {
	{elem.getGlobalBounds()} -> std::same_as<sf::FloatRect>;
};

////////////////////////////////////////////////////////////
/// \brief Useful for centering drawable content
////////////////////////////////////////////////////////////
template <CanBeCentered T>
static sf::Vector2f centerShape(const T& shape) {
	return sf::Vector2f{shape.getLocalBounds().size / 2.f };
}

////////////////////////////////////////////////////////////
/// \brief Enumeration of the different application menus
////////////////////////////////////////////////////////////
export enum Menu {
	Start,    /// < Start menu, shows when the app starts.
	Settings, /// < Settings menu, shows when you enter the settings.
	In_Game   /// < In game menu, more like an HUD that shows in game.
};

////////////////////////////////////////////////////////////
/// \brief Enumeration of the different supported languages.
////////////////////////////////////////////////////////////
export enum Language {
	English, /// < English language, default if no locale found
	French,  /// < French language,
	Spanish, /// < Spanish language
	German   /// < German language
};

////////////////////////////////////////////////////////////
/// \brief Returns the user's language, defaults to english.
////////////////////////////////////////////////////////////
std::pair<std::string, std::string> getNormalizedLangCode() {
    std::string userLanguage = std::setlocale(LC_ALL, "");

	// Handle fallbacks
	if (userLanguage == "" || userLanguage == "C" || userLanguage == "POSIX")
		return std::pair("English", "en");

	std::unordered_map<std::string, std::string> languages = {
		{"en", "English"},
		{"fr", "French"},
		{"es", "Spanish"},
		{"de", "German"}
	};

	// Values that can be safely returned
	if (userLanguage == "en" || userLanguage == "fr" || userLanguage == "es" || userLanguage == "de")
		return std::pair(languages[userLanguage], userLanguage);

	// POSIX / UNIX style
	if (userLanguage.size() >= 3 && userLanguage[2] == '_') {
		userLanguage = userLanguage.substr(0, 2);
		if (userLanguage == "en" || userLanguage == "fr" || userLanguage == "es" || userLanguage == "de")
			return std::pair(languages[userLanguage], userLanguage);
		return std::pair("English", "en");
	}

	// Windows style
    if (const size_t underscore = userLanguage.find('_'); underscore != std::string::npos) {
		userLanguage = userLanguage.substr(0, underscore);
		std::transform(userLanguage.begin(), userLanguage.end(), userLanguage.begin(), ::tolower);
		userLanguage = userLanguage.substr(0, 2);
		if (userLanguage == "en" || userLanguage == "fr" || userLanguage == "es" || userLanguage == "de")
			return std::pair(languages[userLanguage], userLanguage);
		return std::pair("English", "en");
	}

	// Defaults to English.
	Console::Log("Unsupported language : \"" + userLanguage + "\", defaulting to English.", PROBLEM);
    return std::pair("English", "en");
}

////////////////////////////////////////////////////////////
/// \brief Loads every element contained in all game menus
///
/// \param toSpecify : Language to specify
////////////////////////////////////////////////////////////
export void loadMenus(Language& toSpecify) {
	if (calledLoadMenus)
		return;

	Console::Log("Detected language : " + getNormalizedLangCode().first);
	// Specifying the game language
	if (getNormalizedLangCode().second == "en") toSpecify = English;
	else if (getNormalizedLangCode().second == "fr") toSpecify = French;
	else if (getNormalizedLangCode().second == "es") toSpecify = Spanish;
	else if (getNormalizedLangCode().second == "de") toSpecify = German;
	Console::Log("Loading menus...");

	calledLoadMenus = true;
}

////////////////////////////////////////////////////////////
/// \brief Sets up a chosen menu relative to the current
///		   window size
///
/// \param window : Window affected by the menu setup
/// \param toSetup : Menu to be setup
////////////////////////////////////////////////////////////
export void setupMenu(const sf::RenderWindow& window, const Menu& toSetup) {
	const float xPercent = static_cast<float>(window.getSize().x) / 100.f;
	const float yPercent = static_cast<float>(window.getSize().y) / 100.f;

	const sf::Vector2f screenCenter = {
		static_cast<float>(window.getSize().x) / 2.f,
		static_cast<float>(window.getSize().y) / 2.f
	};

	switch (toSetup) {
		case Start:
			Console::Log("Loading the start menu...");
			// Play button
			playButton.setSize(sf::Vector2f(xPercent * 25.f, yPercent * 10.f));
			playButton.setOutlineThickness(3);
			playButton.setFillColor(sf::Color::White);
			playButton.setOutlineColor(sf::Color::Black);
			playButton.setPosition(screenCenter - centerShape(playButton) - sf::Vector2f{ 0.f, playButton.getSize().y });
			// ...Text
			playButtonText.setFont(pixelMix);
			playButtonText.setString("Play");
			playButtonText.setFillColor(sf::Color::Black);
			playButtonText.setPosition(playButton.getPosition() + centerShape(playButton) - centerShape(playButtonText));
			// Settings button
			settingsButton.setSize(sf::Vector2f(xPercent * 25.f, yPercent * 10.f));
			settingsButton.setOutlineThickness(3);
			settingsButton.setFillColor(sf::Color::White);
			settingsButton.setOutlineColor(sf::Color::Black);
			settingsButton.setPosition(screenCenter - centerShape(playButton));
			// ...Text
			settingsButtonText.setFont(pixelMix);
			settingsButtonText.setString("Settings");
			settingsButtonText.setFillColor(sf::Color::Black);
			settingsButtonText.setPosition(settingsButton.getPosition() + centerShape(settingsButton) - centerShape(settingsButtonText));
			// Quit button
			quitButton.setSize(sf::Vector2f(xPercent * 25.f, yPercent * 10.f));
			quitButton.setOutlineThickness(3);
			quitButton.setFillColor(sf::Color::White);
			quitButton.setOutlineColor(sf::Color::Black);
			quitButton.setPosition(screenCenter - centerShape(quitButton) + sf::Vector2f{ 0.f, quitButton.getSize().y });
			// ...Text
			quitButtonText.setFont(pixelMix);
			quitButtonText.setString("Quit");
			quitButtonText.setFillColor(sf::Color::Black);
			quitButtonText.setPosition(quitButton.getPosition() + centerShape(quitButton) - centerShape(quitButtonText));
			break;

	case Settings:
	case In_Game:
	default:
		break;
	}
}

////////////////////////////////////////////////////////////
/// \brief Polls the events of a specified menu
///
/// \param window : Window affected by the event polling
/// \param toPoll : Menu targeted by the event polling
////////////////////////////////////////////////////////////
export int pollGameEvents(sf::RenderWindow& window, Menu& toPoll) {
	// Note: This is a very long function, wrap the parts you don't want to modify.
	while (const std::optional event = window.pollEvent()) {
		if (event->is<sf::Event::Closed>()) {
			return -1;
		}
		// Start menu
		if (toPoll == Start) {
			// Mouse button pressed - Only triggers the buttons.
			if (const auto* mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>()) {
				if (mouseButtonPressed->button == sf::Mouse::Button::Left) {
					// Starts the game
					if (playButton.getGlobalBounds().contains(sf::Vector2<float>(mouseButtonPressed->position))) {
						toPoll = In_Game;
						return 0;
					}
					// Goes to the settings
					if (settingsButton.getGlobalBounds().contains(sf::Vector2<float>(mouseButtonPressed->position))) {
						toPoll = Settings;
						return 0;
					}
					// Terminates the game
					if (quitButton.getGlobalBounds().contains(sf::Vector2<float>(mouseButtonPressed->position))) {
						return -1;
					}
				}
			}
			// Mouse moved - Only colors the buttons.
			if (const auto* mouseMoved = event->getIf<sf::Event::MouseMoved>()) {
				if (playButton.getGlobalBounds().contains(sf::Vector2<float>(mouseMoved->position))) {
					playButton.setFillColor(buttonColorHovered);
				}
				else {
					playButton.setFillColor(sf::Color::White);
				}
				if (settingsButton.getGlobalBounds().contains(sf::Vector2<float>(mouseMoved->position))) {
					settingsButton.setFillColor(buttonColorHovered);
				}
				else {
					settingsButton.setFillColor(sf::Color::White);
				}
				if (quitButton.getGlobalBounds().contains(sf::Vector2<float>(mouseMoved->position))) {
					quitButton.setFillColor(buttonColorHovered);
				}
				else {
					quitButton.setFillColor(sf::Color::White);
				}
			}
		}
		// Settings menu
		else if (toPoll == Settings) {

		}
		// In game
		else if (toPoll == In_Game) {

		}
	}
	return 0;
}

////////////////////////////////////////////////////////////
/// \brief Draws a chosen menu on the chosen window
///
/// \param window : Window affected by the draw call
/// \param toDraw : Menu to be drawn
////////////////////////////////////////////////////////////
export void drawMenu(sf::RenderWindow &window, const Menu toDraw) {
	switch (toDraw) {
		case Start:
			window.draw(startMenuBackground);
			window.draw(playButton);
			window.draw(playButtonText);
			window.draw(settingsButton);
			window.draw(settingsButtonText);
			window.draw(quitButton);
			window.draw(quitButtonText);
			break;

	case Settings:
	case In_Game:
	default:
		break;
	}
}