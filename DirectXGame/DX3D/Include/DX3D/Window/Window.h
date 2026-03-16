#pragma once
#include <DX3D/Core/Base.h>
namespace dx3d
{
	class Window: public Base
	{
	public:
		Window();

		//the compiler can ensure the correct function is being overridden
		virtual ~Window() override;

	private:
		void* m_handle{};
	};
}