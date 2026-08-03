#include <DX3D/Core/Base.h>
#include "DX3D/Window/Window.h"
#include <Windows.h>

static LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {

	switch (msg)
	{

	case WM_CLOSE:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hwnd, msg, wparam, lparam);
	}

	return 0;
}

dx3d::Window::Window(const WindowDesc& desc): dx3d::Base(desc.baseDesc)
{
	auto registerWindowClassFunction = []()
	{
		//initialize it with default values/lazy intialization
		WNDCLASSEX wc{};

		wc.cbSize = sizeof(WNDCLASSEX);
		wc.lpszClassName = L"DX3DWindow";
		wc.lpfnWndProc = &WindowProcedure; //default window procedure, we will override it later

		return RegisterClassEx(&wc);
	};

	static const ATOM windowClassId = std::invoke(registerWindowClassFunction);


	if (!windowClassId) {
		throw std::runtime_error("RegisterClassEx has encountered an unforseen exception!");
	}

	RECT rect{ 0, 0, 2560, 1440 }; //desired client area size

	AdjustWindowRect(&rect, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, false);

	m_handle = CreateWindowExW(NULL, MAKEINTATOM(windowClassId), L"YunoGasai | C++ 3D Game", 
		WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, CW_USEDEFAULT, CW_USEDEFAULT, 
		rect.right - rect.left, rect.bottom - rect.top, NULL, NULL, NULL, NULL);

	if (!m_handle) {
		throw std::runtime_error("CreateWindowEx has encountered an unforseen exception!");
	}

	ShowWindow(static_cast<HWND>(m_handle), SW_SHOW);

}

dx3d::Window::~Window()
{
	DestroyWindow(static_cast<HWND>(m_handle));
}
