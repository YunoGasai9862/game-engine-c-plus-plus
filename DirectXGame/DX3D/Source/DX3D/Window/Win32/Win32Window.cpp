#include <DX3D/Core/Base.h>
#include "DX3D/Window/Window.h"
#include <Windows.h>

dx3d::Window::Window() :
	Base()
{
	//initialize it with default values/lazy intialization
	WNDCLASSEX wc{};

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.lpszClassName = L"DX3DWindow";
	wc.lpfnWndProc = DefWindowProc; //default window procedure, we will override it later

	RegisterClassEx(&wc);

	//CreateWindowEx(NULL, );
}

dx3d::Window::~Window()
{
}
