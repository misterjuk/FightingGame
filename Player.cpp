#include "pch.h"
#include "Player.h"

Player::Player()
	: m_Position{new Point2f(0.0f,0.0f)}
{
	//m_Sprite->Load("");
}
Player::Player(Point2f& position)
	: m_Position{&position}
{
	
}
void Player::Update(float deltaTime)
{

}
void Player::Draw()
{
	SetColor(1.0, 0.0f, 0.0f);
	DrawRect(*m_Position,100.0f,100.0f,1.0f);


	DrawCollisions();
}
void Player::CheckHit(std::list<Enemy*>& currentWave, HitBoxType hitBoxType)
{
	for (Enemy* enemy : currentWave)
	{
		Direction enemyDirection = enemy->GetDirection();
		switch (hitBoxType)
		{
		case Left:
			if (enemyDirection == Direction::Right)
			{
				if (CheckCollision(*m_LeftHitBox, *enemy->GetEnemyRectf()))
				{
					
					std::cout << "LeftHitCollision" << std::endl;
				}
			}
			break;
		case RightHitBox:
			if (enemyDirection == Direction::Left)
			{
				if (CheckCollision(*m_RightHitBox, *enemy->GetEnemyRectf()))
				{
					std::cout << "RightHitCollision" << std::endl;
				}
			}
			break;
		}
	}
}
bool Player::CheckCollision(Rectf& rect1, Rectf& rect2)
{
	if (rect1.left <= rect2.left && rect1.left + rect1.width >= rect2.left
		/*&& rect1.bottom <= rect2.bottom && rect1.bottom + rect1.height >= rect2.bottom*/)
	{
			return true;	
	}
	else if (rect1.left <= rect2.left + rect2.width && rect1.left + rect1.width >= rect2.left + rect2.width
		/*&& rect1.bottom <= rect2.bottom + rect2.height && rect1.bottom + rect1.height >= rect2.bottom + rect2.height*/)
	{
			return true;
	}
	else return false;
}
void Player::DrawCollisions()
{
	SetColor(0.0f, 0.0f, 1.0f);
	DrawRect(*m_LeftHitBox, 1.0f);
	DrawRect(*m_RightHitBox, 1.0f);
}
void Player::DoLeftAttack(std::list<Enemy*>& currentWave)
{
	//DO ANIMATION AND OTHER STUFF
	CheckHit(currentWave, HitBoxType::LeftHitBox);
}