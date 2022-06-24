#include <Siv3D.hpp> // OpenSiv3D v0.6.3
#include "Player.h"

void Main()
{
	// JSON
	const JSON settings = JSON::Load(U"config/settings.json");
	if (not settings) {
		throw Error{ U"Failed to load `settings.json`." };
	}

	// ===== JSON Input =====
	// 
	// Window size (Default width : 800, height : 600)
	const int32 width = settings[U"WindowSize"][U"width"].get<int32>();
	const int32 height = settings[U"WindowSize"][U"height"].get<int32>();

	// ======================

	Window::Resize(width, height);

	Player player;
	player.Initialize(Vec2(width / 2, height / 2), 100);

	while (System::Update())
	{
		Window::SetTitle(U"Graph-Bullet");

		player.Draw();

		player.Move();
		player.PositionClamp(width, height);
	}
}
