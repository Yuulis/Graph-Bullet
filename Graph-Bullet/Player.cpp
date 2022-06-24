#include "stdafx.h"
#include "Player.h"
#include <Siv3D.hpp> // OpenSiv3D v0.6.3

void Player::Debug() {
	Print << U"Player position : (" << m_position.x << U", " << m_position.y << U")";
	Print << U"Player HP : " << m_hp;
}

void Player::Initialize(Vec2 position, int hp) {
	this->m_position = position;
	this->m_hp = hp;
}

void Player::Draw() {
	Triangle{ m_position, 20 }.draw(Palette::Yellow);
}

void Player::Move() {
	const double delta = (Scene::DeltaTime() * 200);

	if ((KeyLeft | KeyA).pressed())
	{
		m_position.x -= delta;
	}

	if ((KeyRight | KeyD).pressed())
	{
		m_position.x += delta;
	}

	if ((KeyUp | KeyW).pressed())
	{
		m_position.y -= delta;
	}

	if ((KeyDown | KeyS).pressed())
	{
		m_position.y += delta;
	}
}

void Player::PositionClamp(int width, int height) {
	if (m_position.x < 10) {
		m_position.x = 10;
	}

	if (m_position.x > width - 10) {
		m_position.x = width - 10;
	}

	if (m_position.y < 10) {
		m_position.y = 10;
	}

	if (m_position.y > height - 10) {
		m_position.y = height - 10;
	}
}
