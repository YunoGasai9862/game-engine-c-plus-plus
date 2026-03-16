#include <DX3D/Core/Base.h>
#include "DX3D/Window/Window.h"
#include <Windows.h>
#include <stdexcept>
dx3d::Window::Window() :
	Base()
{
	//initialize it with default values/lazy intialization
	WNDCLASSEX wc{};

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.lpszClassName = L"DX3DWindow";
	wc.lpfnWndProc = DefWindowProc; //default window procedure, we will override it later

	ATOM windowClassId = RegisterClassEx(&wc);


	if (!windowClassId) {
		throw std::runtime_error("RegisterClassEx has encountered an unforseen exception!");
	}

	RECT rect{ 0, 0, 2560, 1440 }; //desired client area size

	AdjustWindowRect(&rect, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, false);

	m_handle = CreateWindowExW(NULL, MAKEINTATOM(windowClassId), L"YunoGasai | C++ 3D Game", 
		WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, CW_USEDEFAULT, CW_USEDEFAULT, 
		rect.right - rect.left, rect.bottom - rect.top, NULL, NULL, NULL, NULL);

}

dx3d::Window::~Window()
{
}
