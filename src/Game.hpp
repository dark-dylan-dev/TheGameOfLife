#pragma once

// SFML
#include <SFML/Graphics.hpp>

// MODULES
import GameSetup;
import GameConsole;
import GameMenus;

class Game {
private:
	sf::RenderWindow m_window;
	sf::Clock Clock;
	bool m_isRunning;
	float m_deltaTime;
	Menu m_currentMenu;
	Language m_gameLanguage;

public:
	Game();
	~Game();

public:
	void run();

private:
	void init();
	void pollEvents();
	void updateLoop();
	void render();
};