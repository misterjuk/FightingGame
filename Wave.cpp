#include "pch.h"
#include "Wave.h"
Wave::Wave()
{

}
void Wave::CreateWave(int numberOfEnemies)
{
	for (int i = 0; i < numberOfEnemies; i++)
	{
		Direction randomDirection = static_cast<Direction>(rand() % 2);
		switch (randomDirection)
		{
		case Left:
			m_CurrentWave.push_back(new Enemy(*m_RightSpawnPosition, Direction::Left));
			break;
		case Right:
			m_CurrentWave.push_back(new Enemy(*m_LeftSpawnPosition, Direction::Right));
			break;
		}
	}
}
void Wave::Update(float deltaTime) {
	for (Enemy* enemy : m_CurrentWave)
	{
		enemy->Update(deltaTime);
	}
}
void Wave::Draw() {
	for (Enemy* enemy : m_CurrentWave)
	{
		enemy->Draw();
	}
}
std::list<Enemy*>* Wave::GetCurrentWave() 
{
	return &m_CurrentWave;
}