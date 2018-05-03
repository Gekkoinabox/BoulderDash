#include "stdafx.h"
#include "Engine.h"

void Engine::draw()
{
	//Rub out the last frame
	m_Window.clear(Color::White);

	//Set background view
	m_Window.setView(m_BackgroundMainView);
	
	//Draw the background
	m_Window.draw(m_BackgroundSprite);
	//Switch to m_MainView
	m_Window.setView(m_MainView);

	//Draw the HUD
	m_Window.setView(m_HudView);
	//Show everything we have just drawn
	m_Window.display();
}