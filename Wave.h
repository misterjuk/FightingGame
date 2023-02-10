#pragma once
#include "Enemy.h"
#include <iostream>
#include <list>
class Wave
{
private:
	std::list<Enemy*> m_CurrentWave{};
	Point2f* m_LeftSpawnPosition{new Point2f(0.0f,130.0f)};
	Point2f* m_RightSpawnPosition{ new Point2f(700.0f,130.0f) };
public:
	Wave();
	void CreateWave(int numberOfEnemies);
	void Update(float deltaTime);
	void Draw();
	std::list<Enemy*>* GetCurrentWave();
};