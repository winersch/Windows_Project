#pragma once 
#include "MGameObject.h"
#include "CommonInclude.h"
#include "MInput.h"
#include "MTime.h"

namespace maple {
	
	
	GameObject::GameObject() {
	}

	GameObject::~GameObject() {
	}

	void GameObject::SetPosition(float x, float y) {
		mX = x;
		mY = y;
	}
	float GameObject::GetPositionX() {
		return mX;
	}
	float GameObject::GetPositionY() {
		return mY;
	}

	void GameObject::Update() {
		float speed = 100.0f;
		speed += Time::DeltaTime();
		if (Input::GetKey(eKeyCode::A)) {
			if (mX >= 0.0f) {
				mX -= speed * Time::DeltaTime();
			}
		}
		if (Input::GetKey(eKeyCode::D)) {
			if (mX <= 1366.0f) {
				mX += speed * Time::DeltaTime();
			}
		}
		if (Input::GetKey(eKeyCode::W)) {
			if (mY >= 0.0f) {
				mY -= speed * Time::DeltaTime();
			}
		}
		if (Input::GetKey(eKeyCode::S)) {
			if (mY <= 760) {
				mY += speed * Time::DeltaTime();
			}
		}
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
			PostQuitMessage(0);
		}
	}
	
	void GameObject::LateUpdate() {
	}
	void GameObject::Render(HDC hdc) {
		HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));

		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);


		Rectangle(hdc, mX, mY, 100 + mX, 100 + mY);

		
		SelectObject(hdc, oldBrush);

		DeleteObject(blueBrush);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);

		SelectObject(hdc, oldPen);
		DeleteObject(redPen);
	}
}

