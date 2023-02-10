#include "pch.h"
#include "Enemy.h"
Enemy::Enemy()
	: m_Position{ new Point2f(0.0f,0.0f)}
{
	//m_Sprite->Load("");
}
Enemy::Enemy(Point2f& position, Direction direction)
	: m_Position{&position},
	m_Direction{direction}
{

}
void Enemy::Update(float deltaTime)
{
	switch (m_Direction)
	{
	case Direction::Left:
		m_Position->x -= m_Speed * deltaTime;
		break;
	case Direction::Right:
		m_Position->x += m_Speed * deltaTime;
		break;
	}
}
void Enemy::Draw()
{
	SetColor(1.0, 1.0f, 0.0f);
	DrawRect(*m_Position, 100.0f, 100.0f, 1.0f);
}
Direction Enemy::GetDirection()
{
	return m_Direction;
}
Rectf* Enemy::GetEnemyRectf()
{
	m_EnemyRectf = Rectf(
		m_Position->x,
		m_Position->y,
		/*m_Sprite->m_Texture.width,
		m_Sprite->m_Texture.height*/
		100.0f,
		100.0f
	);
	return &m_EnemyRectf;
}
void Enemy::GetHit()
{
	m_Health--;
	if (m_Health <= 0)
	{
		Die();
	}
	// change return type to something like enemyState, if after hit enemy is dead
	// return that state to the player to delete this ememy from the current wave
}
void Enemy::Die()
{
	//delete(this);
}