#pragma once

namespace maple::enums {

	enum class eComponentType {
		Transform,
		Collider,
		Script,
		SpriteRenderer,
		Animator,
		Camera,

		End,
	};

	enum class eLayerType {
		None,
		BackGround,
		Animal,
		Player,
		Particle,

		Max = 16,
	};

	enum class eResourceType {
		Texture,
		AudioClip,
		Animation,
		Prefab,
		End,

	};
}