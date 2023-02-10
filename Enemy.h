#include "pch.h"
#include "Sprite.h"
#pragma once
enum Direction {
	Left = 0,
	Right = 1
};
class Enemy
{
private:
	
	Direction m_Direction{Direction::Right};
	Point2f* m_Position{};
	Sprite* m_Sprite{};
	float m_Speed{4.0f};
	Rectf m_EnemyRectf{};

	int m_Health{2};
	void Die();
public:
	
	Enemy();
	Enemy(Point2f& position, Direction direction);
	void Update(float deltaTime);
	void Draw();
	Rectf* GetEnemyRectf();
	Direction GetDirection();
	void GetHit();
};
