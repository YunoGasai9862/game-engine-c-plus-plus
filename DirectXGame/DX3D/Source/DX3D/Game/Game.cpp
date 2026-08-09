#include "DX3D/Game/Game.h"
#include <DX3D/Window/Window.h>
#include <DX3D/Graphics/GraphicsEngine.h>
#include <DX3D/Core/Logger.h>

dx3d::Game::Game() : dx3d::Base({ *m_loggerPtr }), m_loggerPtr(std::make_unique<Logger>(Logger::LogLevel::Info))
{
	m_graphicsEngine = std::make_unique<GraphicsEngine>();
	m_display = std::make_unique<Window>();

	m_loggerPtr->log(Logger::LogLevel::Info, "Game created successfully.");

}

dx3d::Game::~Game()
{
	m_loggerPtr->log(Logger::LogLevel::Info, "Game deallocation started.");
}