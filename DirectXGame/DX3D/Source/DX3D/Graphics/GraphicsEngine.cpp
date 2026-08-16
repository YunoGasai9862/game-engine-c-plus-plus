#include <DX3D/Graphics/GraphicsEngine.h>
#include <DX3D/Graphics/RenderSystem.h>
#include <DX3D/Core/Core.h>

dx3d::GraphicsEngine::GraphicsEngine(const GraphicsEngineDesc& desc): dx3d::Base(desc.baseDesc)
{
	m_renderSystem = std::make_unique<RenderSystem>();
}

dx3d::GraphicsEngine::~GraphicsEngine()
{

}