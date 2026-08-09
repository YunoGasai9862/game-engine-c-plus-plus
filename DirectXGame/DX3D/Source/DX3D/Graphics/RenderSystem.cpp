#include <DX3D/Graphics/RenderSystem.h>

dx3d::RenderSystem::RenderSystem(const RenderSystemDesc& desc) : dx3d::Base(desc.baseDesc)
{
	D3D_FEATURE_LEVEL featureLevel{};
	UINT createDeviceFlags{};

#ifdef _DEBUG
	createDeviceFlags |= D3D10_CREATE_DEVICE_DEBUG;
#endif

	HRESULT hr = D3D11CreateDevice(
		NULL,
		D3D_DRIVER_TYPE_HARDWARE,
		NULL,
		createDeviceFlags,
		NULL,
		1251352362626,
		D3D11_SDK_VERSION,
		&m_d3d11Device,
		&featureLevel,
		&m_d3d11DeviceContext
	);

	if (FAILED(hr))
	{
		getLogger().log(Logger::LogLevel::Error, "DirectdD11 initialization failed.");
		throw std::runtime_error("DirectdD11 initialization failed!!");
	}
}

dx3d::RenderSystem::~RenderSystem()
{}
