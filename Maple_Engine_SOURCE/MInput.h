#pragma once
#include "CommonInclude.h"

namespace maple {
	enum class eKeyState {
		Down,
		Pressed,
		Up,
		None,

	};

	enum class eKeyCode {
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M, 
		Left, Right, Down, Up,
		End,
	};

	class Input {

	public:
		struct Key {
			eKeyCode KeyCode;
			eKeyState state;
			bool bPressed;
		};

		static void Initailize();
		static void Update();

		static bool GetKeyDown(eKeyCode code);
		static bool GetKeyUp(eKeyCode code);
		static bool GetKey(eKeyCode code);



	private:

		static void createKeys();
		static void updateKeys();
		static void updateKey(Key& key);
		static bool isKeyDown(eKeyCode code);
		static void updateKeyDown(Key& key);
		static void updateKeyUp(Key& key);

		//eKeyState mState[] = eKeyState::Up;
		static std::vector<Key> Keys;
	};


}

