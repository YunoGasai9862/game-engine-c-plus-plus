#pragma once
#include <DX3D/Core/Base.h>
#include <DX3D/Core/Core.h>

namespace dx3d
{
	class Game
	{
	public:
		Game();
		virtual ~Game();

		virtual void run() final;

	private:
		std::unique_ptr<Window> m_display {};
		bool m_isRunning { true };
	};
}
