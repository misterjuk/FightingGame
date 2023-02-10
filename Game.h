#pragma once
using namespace utils;
#include "Player.h"
#include "Wave.h"
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "FightingGame" };

// Change the window dimensions here
float g_WindowWidth{ 640 };
float g_WindowHeight{ 360 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
Player* g_Player;
Point2f* g_PlayerPosition{new Point2f(g_WindowWidth / 2 -50.0f,g_WindowHeight / 2-50.0f)};
Wave* g_WaveManager{new Wave()};
// Declare your own functions here

#pragma endregion ownDeclarations

#pragma region gameFunctions											
void Start();
void Draw();
void Update(float elapsedSec);
void End();
#pragma endregion gameFunctions

#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key);
void OnKeyUpEvent(SDL_Keycode key);
void OnMouseMotionEvent(const SDL_MouseMotionEvent& e);
void OnMouseDownEvent(const SDL_MouseButtonEvent& e);
void OnMouseUpEvent(const SDL_MouseButtonEvent& e);
#pragma endregion inputHandling
