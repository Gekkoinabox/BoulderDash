#include "stdafx.h"
#include "Engine.h"

Engine::Engine()
{
	//Get the screen resolution
	//and create an SFML Window and View
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	m_Window.create(VideoMode(resolution.x, resolution.y), 
		"Boulder Dash",
		Style::Fullscreen);

	//Initialize the fullscreen view
	m_MainView.setSize(resolution);
	m_HudView.reset(FloatRect(0, 0, resolution.x, resolution.y));
	
	//Associate the sprite with the texture
	m_BackgroundSprite.setTexture(m_BackgroundTexture);

}

void Engine::run()
{
	//Timing
	Clock clock;

	//When the window opens
	while (m_Window.isOpen())
	{
		Time dt = clock.restart();
		//Update the total game time
		m_GameTimeTotal += dt;
		//Make a decimal fraction from the delta time
		float dtAsSeconds = dt.asSeconds();
		//Call each part of the game loop in turn
		input();
		update(dtAsSeconds);
		draw();
	}
}

void Engine::input()
{
	Event event;
	while (m_Window.pollEvent(event))
	{
		if (event.type == Event::KeyPressed)
		{
			//Handle the player quitting
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				m_Window.close();
			}

			//Handle the player starting the game
			if (Keyboard::isKeyPressed(Keyboard::Return))
			{
				m_Playing = true;
			}
		}
	}
}