#include "Game.hpp"

Game::Game() :
	m_window(sf::VideoMode::getDesktopMode(), "The Game Of Life", sf::Style::Default)
{
	std::cout << "Game instanciated at " << this << '\n';
	m_deltaTime = 0.f;
	m_isRunning = true;
}

Game::~Game() {
	std::cout << "Game destroyed at " << this << '\n';
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
	return;
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