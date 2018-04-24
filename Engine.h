#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"

using namespace sf;

class Engine
{
private:
	//The texture holder
	TextureHolder textureHolder;

	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;

	//A regular RenderWindow
	RenderWindow m_Window;

	//The main views
	View m_MainView;
	View m_HudView;

	//Delcare a sprite and a Texture
	//for the background
	Sprite m_BackgroundSprite;
	Texture m_BackgroundTexture;

	//Is the game currently playing?
	bool m_Playing = false;

	//How much time is left in the current level
	float m_TimeRemaining = 10;
	Time m_GameTimeTotal;

	//Is it time for a new/first level?
	bool m_NewLevelRequired = true;
	//Private functions for internal use only
	void input();
	void update(float dtAsSeconds);
	void draw();

public:
	//The enging constructor
	Engine();

	//Run will call all the private functions
	void run();
};