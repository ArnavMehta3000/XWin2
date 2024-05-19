#include "XWin2.h"

int WINAPI wWinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR lpCmdLine,
	_In_ int nShowCmd
)
{
	XWin2::WindowClass wc(hInstance);
	if (!wc)
		return EXIT_FAILURE;

	XWin2::Window w(wc, L"My Window", 1280, 720, WS_OVERLAPPEDWINDOW);

	XWin2::Window::Event e;
	while (w.ProcessMessages(e))
	{
		if (e.Type == XWin2::Events::EventType::Close)
		{
			break;
		}

		if (e.Type == XWin2::Events::EventType::Mouse)
		{
			auto& mouseEvent = std::get<XWin2::Events::MouseEvent>(e.EventData);

			if (mouseEvent.Type == XWin2::Events::MouseEvent::EventType::ButtonDown)
			{
				if (mouseEvent.Button == XWin2::Events::KeyCode::LeftMouseButton)
				{
					OutputDebugStringA("Pressed left");
				}
			}
		}
	}

	return 0;
}
