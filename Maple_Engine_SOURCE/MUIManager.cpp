#include "MUIManager.h"
#include "MUIHUD.h"
#include "MUIButton.h"

namespace maple {

	std::unordered_map<eUIType, UIBase*> UIManager::mUIs = {};
	std::stack<UIBase*> UIManager::mUIBases = {};
	std::queue<eUIType> UIManager::mRequestUiQueue = {};
	UIBase* UIManager::mActiveUI = nullptr;


	void UIManager::Initialize() {
		// UI 객체 생성해주기
		//UIHUD* hud = new UIHUD();
		//mUIs.insert(std::make_pair(eUIType::HpBar, hud));

		//UIButton* button = new UIButton();
		//mUIs.insert(std::make_pair(eUIType::Button, button));
	}

	void UIManager::OnLoad(eUIType type) {
		std::unordered_map<eUIType, UIBase*>::iterator iter
			= mUIs.find(type);

		if (iter == mUIs.end()) {
			OnFail();
			return;
		}

		OnComplete(iter->second);
	}

	void UIManager::Update() {
		std::stack<UIBase*> uiBases = mUIBases;
		while (!uiBases.empty()) {
			UIBase* uiBase = uiBases.top();
			if (uiBase) {
				uiBase->Update();
				uiBases.pop();
			}
		}

		if (mRequestUiQueue.size() > 0) {
			eUIType requestUI = mRequestUiQueue.front();
			mRequestUiQueue.pop();
			OnLoad(requestUI);
		}
	}

	void UIManager::LateUpdate() {
		std::stack<UIBase*> uiBases = mUIBases;
		while (!uiBases.empty()) {
			UIBase* uiBase = uiBases.top();
			if (uiBase) {
				uiBase->LateUpdate();
				uiBases.pop();
			}
		}
	}

	void UIManager::Render() {
		if (mUIBases.size() <= 0)
			return;

		std::vector<UIBase*> buff;

		UIBase* uibase = nullptr;
		while (mUIBases.size() > 0) {
			uibase = mUIBases.top();
			mUIBases.pop();

			buff.push_back(uibase);
		}
		std::reverse(buff.begin(), buff.end());

		for (UIBase* ui : buff) {
			ui->Render();
			mUIBases.push(ui);
		}
	}

	void UIManager::OnComplete(UIBase* addUI) {
		if (addUI == nullptr)
			return;

		addUI->Initialize();
		addUI->Active();
		addUI->Update();

		// 만약에 현재 추가된 ui가 전체화면이라면
		// 전체화면인 ui 말고 나머지를 전부 비활성화
		if (addUI->IsFullScreen()) {
			std::stack<UIBase*> uiBases = mUIBases;
			while (!uiBases.empty()) {
				UIBase* uiBase = uiBases.top();
				uiBases.pop();
				if (uiBase) {
					uiBase->InActive();
				}
			}
		}

		mUIBases.push(addUI);
		mActiveUI = nullptr;
	}

	void UIManager::OnFail() {
		mActiveUI = nullptr;
	}
	
	void UIManager::Release() {
		for (auto iter : mUIs) {
			delete iter.second;
			iter.second = nullptr;
		}
	}

	void UIManager::Push(eUIType type) {
		mRequestUiQueue.push(type);
	}

	void UIManager::Pop(eUIType type) {
		if (mUIBases.size() <= 0)
			return;

		// 해당 ui 한개만 스택에서 제외
		std::stack<UIBase*> tempStack;

		UIBase* uibase = nullptr;
		while (mUIBases.size() > 0) {
			uibase = mUIBases.top();
			mUIBases.pop();

			if (uibase->GetType() != type) {
				tempStack.push(uibase);
				continue;
			}

			if (uibase->IsFullScreen()) {
				std::stack<UIBase*> uiBases = mUIBases;
				while (!uiBases.empty()) {
					UIBase* uiBase = uiBases.top();
					uiBases.pop();
					if (uiBase) {
						uiBase->Active();
						break;
					}
				}
			}
			uibase->UIClear();
		}
		
		while (tempStack.size() > 0) {
			uibase = tempStack.top();
			tempStack.pop();
			mUIBases.push(uibase);
		}
	}

}
