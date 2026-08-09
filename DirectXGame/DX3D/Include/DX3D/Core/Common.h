#pragma once
#include <DX3D/Core/Core.h>
#include <DX3D/Core/Logger.h>


namespace dx3d
{
	struct BaseDesc
	{
		Logger& logger;
	};

	struct WindowDesc
	{
		BaseDesc baseDesc;
	};

	struct GraphicsEngineDesc
	{
		BaseDesc baseDesc;
	};

	struct RenderSystemDesc
	{
		BaseDesc baseDesc;
	};
}