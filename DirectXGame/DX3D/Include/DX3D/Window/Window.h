#pragma once
#include <DX3D/Core/Base.h>
#include <DX3D/Core/Common.h>

namespace dx3d
{
	class Window: public dx3d::Base
	{
	public:
		explicit Window(const WindowDesc& desc);
		Window();

		//the compiler can ensure the correct function is being overridden
		virtual ~Window() override;

	private:
		void* m_handle{};
	};
}