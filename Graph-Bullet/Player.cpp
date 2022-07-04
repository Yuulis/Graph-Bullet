#include "stdafx.h"
#include "Base.h"
#include "Player.h"
#include <Siv3D.hpp> // OpenSiv3D v0.6.3

Player::Player(Vec2 position, int hp) {
	this->m_position = position;
	this->m_hp = hp;
	this->m_isAlive = true;

	memset(m_bullet, 0, sizeof(m_bullet));
	for (int i = 0; i < player_maxBullet; i++)
	{
		m_bullet[i].isShot = false;
	}

	m_shotTurn = 0;
}

void Player::Debug() {
	Print << U"Player position : (" << m_position.x << U", " << m_position.y << U")";
	Print << U"Player HP : " << m_hp;
}

void Player::Draw() {
	if (m_isAlive) {
		for (int i = 0; i < player_maxBullet; i++)
		{
			if (m_bullet[i].isShot) {
				Circle{ m_bullet[i].position, 3 }.draw();
			}
		}

		Triangle{ m_position, 20 }.draw(Palette::Yellow);
	}
}

void Player::Move() {
	const double delta = (Scene::DeltaTime() * 200);

	if (m_isAlive) {
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

void Player::Shot() {
	if (KeySpace.pressed() && m_shotTurn % 5 == 0) {
		for (int i = 0; i < player_maxBullet; i++)
		{
			if (!m_bullet[i].isShot) {
				m_bullet[i].isShot = true;
				m_bullet[i].position = m_position;
				break;
			}
		}
	}

	for (int i = 0; i < player_maxBullet; i++)
	{
		if (m_bullet[i].isShot) {
			m_bullet[i].position.y -= player_bulletSpeed;

			if (m_bullet[i].position.y < 3) {
				m_bullet[i].isShot = false;
			}
		}
	}
}

void Player::PlayerLoop() {
	Draw();
	Move();
	Shot();

	m_shotTurn++;
}
