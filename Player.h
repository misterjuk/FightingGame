#include "pch.h"
#include "Sprite.h"
#include "utils.h"
#include "Enemy.h"
#include <list>
enum HitBoxType {
	LeftHitBox,
	RightHitBox
};
class Player {
private:
	
	Sprite* m_Sprite{};
	Point2f* m_Position{};

	Rectf* m_LeftHitBox{new Rectf(200.0f,130.0f,100.0f,50.0f)};
	Rectf* m_RightHitBox{ new Rectf(340.0f,130.0f,100.0f,50.0f) };
	
	bool CheckCollision(Rectf& rect1, Rectf& rect2);
	void DrawCollisions();
public:
	Player();
	Player(Point2f& position);
	void Update(float deltaTime);
	void Draw();
	void CheckHit(std::list<Enemy*>& currentWave, HitBoxType hitBoxType);
	void DoLeftAttack(std::list<Enemy*>& currentWave);

};