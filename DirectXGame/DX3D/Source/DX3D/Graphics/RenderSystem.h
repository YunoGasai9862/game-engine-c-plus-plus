#pragma once
#include <DX3D/Core/Core.h>
#include <DX3D/Core/Base.h>
#include <d3d11.h>
#include <wrl.h>
//Option 2 — Project settings (Visual Studio):
//Right - click your project → Properties
//Go to Linker → Input → Additional Dependencies
//Add d3d11.lib to the list
namespace dx3d
{
	class RenderSystem final : public Base
	{
	public:
		explicit RenderSystem(const RenderSystemDesc& desc);
		virtual ~RenderSystem() override;

	private:
		Microsoft::WRL::ComPtr<ID3D11Device> m_d3d11Device{};
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> m_d3d11DeviceContext{};
	};
}