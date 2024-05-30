#pragma once

#include "..\\Maple_Engine_SOURCE\\MResources.h"
#include "..\\Maple_Engine_SOURCE\\MTexture.h"


namespace maple {

	void LoadResources() {
		Resources::Load<graphics::Texture>(L"Map", L"..\\Resources\\img\\map\\map_pure.png");
		Resources::Load<graphics::Texture>(L"PacMan", L"..\\Resources\\img\\pacman\\0.png");


	}


}