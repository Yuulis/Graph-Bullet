#pragma once
class Player
{
public:
	Vec2 m_position;
	int m_hp;

	void Debug();
	void Initialize(Vec2 position, int hp);
	void Draw();
	void Move();
	void PositionClamp(int width, int height);
};
