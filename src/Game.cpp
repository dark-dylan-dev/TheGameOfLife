#include "Game.hpp"

Game::Game() :
	m_window(sf::VideoMode::getDesktopMode(), "The Game Of Life", sf::Style::Fullscreen)
{
	m_deltaTime = 0.f;
	m_isRunning = true;
}

Game::~Game() 
{
	// May be used later
}

void Game::run() {
	init();

	while (m_isRunning) {
		pollEvents();
		updateLoop();
		render();
	}

	m_window.close();
}

void Game::init() {
	Console::Log("Initializing game...");

	// Init steps

	Console::Log("Finished game initialization.");
}

void Game::pollEvents() {
	sf::Event event;
	while (m_window.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			m_isRunning = false;
			break;
		}
	}
}

void Game::updateLoop() {
	m_deltaTime = Clock.restart().asSeconds();
}

void Game::render() {
	m_window.clear();

	// Draw

	m_window.display();
}