#include "Game.hpp"

Game::Game() :
	m_window(sf::VideoMode::getDesktopMode(), "The Game Of Life", sf::Style::Default)
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

	// Init
	loadImages();
	setupCursor(m_window);
	setupIcon(m_window);
	loadMenus();
	setupMenu(m_window, Start);

	Console::Log("Finished game initialization.");
}

void Game::pollEvents() {
	sf::Event event;
	while (m_window.pollEvent(event)) {
		pollMenuEvents(m_window, event, Start);
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
	drawMenu(m_window, Start);

	m_window.display();
}