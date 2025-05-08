#include "Game.hpp"

Game::Game() :
	m_window(sf::VideoMode::getDesktopMode(), "The Game Of Life", sf::State::Fullscreen)
{
	m_deltaTime = 0.f;
	m_isRunning = true;
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
	loadMenus();
	setupMenu(m_window, Start);

	Console::Log("Finished game initialization.");
}

void Game::pollEvents() {
	if (pollGameEvents(m_window, Start) != 0)
		m_isRunning = false;
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