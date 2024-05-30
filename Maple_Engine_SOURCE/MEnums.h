#pragma once

namespace maple::enums {

	enum class eComponentType {
		Transform,
		SpriteRenderer,
		Script,
		Camera,

		End,
	};

	enum class eLayerType {
		None,
		BackGround,
		Player,
		Max = 16,
	};

	enum class eResourceType {
		Texture,
		AudioClip,
		Prefab,
		End,

	};
}