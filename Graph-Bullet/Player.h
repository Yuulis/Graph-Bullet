#pragma once
class Player
{
private:
	Vec2 m_position;
	int m_hp;
	bool m_isAlive;
	Bullet m_bullet[player_maxBullet];

	int m_shotTurn;

public:
	Player(Vec2 position, int hp);
	void Debug();
	void Draw();
	void Move();
	void PositionClamp(int width, int height);
	void Shot();
	void PlayerLoop();
};
