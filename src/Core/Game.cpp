#include "Game.hpp"

Game::Game() :
	m_window(sf::VideoMode::getDesktopMode(), "The Game Of Life", sf::State::Fullscreen)
{
	m_deltaTime = 0.0f;
	m_refreshFPS = 0.0f;
	m_isRunning = true;
	m_currentMenu = Start;
	m_gameLanguage = English;
	m_window.setFramerateLimit(60);
}

Game::~Game() = default;

void Game::run() {
	init();

	while (m_isRunning) {
		pollEvents();
		updateLoop();
		render();
	}

	// Save shapes, progress and advancements here

	Console::Log("Game terminated");

	m_window.close();
}

void Game::init() {
	Console::Log("Initializing game...");

	loadImages();
	setupCursor(m_window);
	setupIcon(m_window);
	loadMenus(m_gameLanguage);
	setupMenu(m_window, Start);

	Console::Log("Finished game initialization.");
}

void Game::pollEvents() {
	if (pollGameEvents(m_window, m_currentMenu) != 0)
		m_isRunning = false;
}

void Game::updateLoop() {
	m_deltaTime = m_clock.restart().asSeconds();
	calculateFPS(m_deltaTime);
}

void Game::render() {
	m_window.clear();

	// Draw
	drawMenu(m_window, m_currentMenu);

	m_window.display();
}