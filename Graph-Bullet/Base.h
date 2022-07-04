#pragma once

const int player_maxBullet = 50;
const int player_bulletSpeed = 10;

struct Bullet
{
	Vec2 position;
	bool isShot;
};
