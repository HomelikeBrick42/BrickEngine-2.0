#pragma once

#include "BrickCore/Input.h"

namespace BrickEngine {

	class WindowsInput : public Input
	{
	protected:
		virtual bool IsKeyPressedImpl(int keycode) override;

		virtual bool IsMouseButtonPressedImpl(int button) override;
		virtual std::pair<float, float> GetMousePositionImpl() override;
		virtual void SetMousePositionImpl(const std::pair<float, float>& position) override;
		virtual float GetMouseXImpl() override;
		virtual float GetMouseYImpl() override;
	};

}
