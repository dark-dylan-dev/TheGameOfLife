#pragma once

// SFML
#include <SFML/Graphics.hpp>

// STD
#include <iostream>

class Game {
private:
	sf::RenderWindow m_window;
	sf::Clock Clock;
	bool m_isRunning;
	float m_deltaTime;

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