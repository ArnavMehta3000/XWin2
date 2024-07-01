#pragma once

#ifndef _WIN32
#error XWin2 requires Windows!
#endif

#ifndef _WINDOWS_
#include <Windows.h>
#endif

#ifdef _UNICODE
#define XWIN2_STR LPCWSTR
#else
#define XWIN2_STR LPCSTR
#endif

#ifndef XWIN2_WND_CLASS_NAME
#define XWIN2_WND_CLASS_NAME TEXT("XWin2WindowClass")
#endif

#include <queue>
#include <variant>


namespace XWin2
{
	static const UINT s_windowClassStyle = CS_VREDRAW | CS_HREDRAW | CS_DBLCLKS;
	inline LRESULT WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	namespace Events
	{
		enum class KeyCode
		{
			None              = 0,
			LeftMouseButton   = VK_LBUTTON,
			RightMouseButton  = VK_RBUTTON,
			BreakMouseButton  = VK_CANCEL,
			MiddleMouseButton = VK_MBUTTON,
			X1MouseButton     = VK_XBUTTON1,
			X2MouseButton     = VK_XBUTTON2,
			Backspace         = VK_BACK,
			Tab               = VK_TAB,
			Clear             = VK_CLEAR,
			Enter             = VK_RETURN,
			Shift             = VK_SHIFT,
			Control           = VK_CONTROL,
			Pause             = VK_PAUSE,
			CapsLock          = VK_CAPITAL,
			Kana              = VK_KANA,
			Hangul            = VK_HANGUL,
			IMEOn             = VK_IME_ON,
			Junja             = VK_JUNJA,
			Escape            = VK_ESCAPE,
			Convert           = VK_CONVERT,
			NonConvert        = VK_NONCONVERT,
			Accept            = VK_ACCEPT,
			ModeChange        = VK_MODECHANGE,
			Space             = VK_SPACE,
			PageUp            = VK_PRIOR,
			PageDown          = VK_NEXT,
			End               = VK_END,
			Home              = VK_HOME,
			Left              = VK_LEFT,
			Up                = VK_UP,
			Right             = VK_RIGHT,
			Down              = VK_DOWN,
			Select            = VK_SELECT,
			Print             = VK_PRINT,
			Execute           = VK_EXECUTE,
			PrintScreen       = VK_SNAPSHOT,
			Insert            = VK_INSERT,
			Delete            = VK_DELETE,
			Help              = VK_HELP,
			LeftWindow        = VK_LWIN,
			RightWindow       = VK_RWIN,
			Apps              = VK_APPS,
			Sleep             = VK_SLEEP,
			Numpad0           = VK_NUMPAD0,
			Numpad1           = VK_NUMPAD1,
			Numpad2           = VK_NUMPAD2,
			Numpad3           = VK_NUMPAD3,
			Numpad4           = VK_NUMPAD4,
			Numpad5           = VK_NUMPAD5,
			Numpad6           = VK_NUMPAD6,
			Numpad7           = VK_NUMPAD7,
			Numpad8           = VK_NUMPAD8,
			Numpad9           = VK_NUMPAD9,
			Multiply          = VK_MULTIPLY,
			Add               = VK_ADD,
			Separator         = VK_SEPARATOR,
			Subtract          = VK_SUBTRACT,
			Decimal           = VK_DECIMAL,
			Divide            = VK_DIVIDE,
			F1                = VK_F1,
			F2                = VK_F2,
			F3                = VK_F3,
			F4                = VK_F4,
			F5                = VK_F5,
			F6                = VK_F6,
			F7                = VK_F7,
			F8                = VK_F8,
			F9                = VK_F9,
			F10               = VK_F10,
			F11               = VK_F11,
			F12               = VK_F12,
			F13               = VK_F13,
			F14               = VK_F14,
			F15               = VK_F15,
			F16               = VK_F16,
			F17               = VK_F17,
			F18               = VK_F18,
			F19               = VK_F19,
			F20               = VK_F20,
			F21               = VK_F21,
			F22               = VK_F22,
			F23               = VK_F23,
			F24               = VK_F24,
			NumLock           = VK_NUMLOCK,
			ScrollLock        = VK_SCROLL,
			LeftShift         = VK_LSHIFT,
			RightShift        = VK_RSHIFT,
			LeftControl       = VK_LCONTROL,
			RightControl      = VK_RCONTROL,
			LeftAlt           = VK_LMENU,
			RightAlt          = VK_RMENU,
			BrowserBack       = VK_BROWSER_BACK,
			BrowserForward    = VK_BROWSER_FORWARD,
			BrowserRefresh    = VK_BROWSER_REFRESH,
			BrowserStop       = VK_BROWSER_STOP,
			BrowserSearch     = VK_BROWSER_SEARCH,
			BrowserFavorites  = VK_BROWSER_FAVORITES,
			BrowserHome       = VK_BROWSER_HOME,
			VolumeMute        = VK_VOLUME_MUTE,
			VolumeDown        = VK_VOLUME_DOWN,
			VolumeUp          = VK_VOLUME_UP,
			MediaNextTrack    = VK_MEDIA_NEXT_TRACK,
			MediaPrevTrack    = VK_MEDIA_PREV_TRACK,
			MediaStop         = VK_MEDIA_STOP,
			MediaPlayPause    = VK_MEDIA_PLAY_PAUSE,
			LaunchMail        = VK_LAUNCH_MAIL,
			LaunchMediaSelect = VK_LAUNCH_MEDIA_SELECT,
			LaunchApp1        = VK_LAUNCH_APP1,
			LaunchApp2        = VK_LAUNCH_APP2,
			OEM1              = VK_OEM_1,
			OEMPlus           = VK_OEM_PLUS,
			OEMComma          = VK_OEM_COMMA,
			OEMMinus          = VK_OEM_MINUS,
			OEMPeriod         = VK_OEM_PERIOD,
			OEM2              = VK_OEM_2,
			OEM3              = VK_OEM_3,
			OEM4              = VK_OEM_4,
			OEM5              = VK_OEM_5,
			OEM6              = VK_OEM_6,
			OEM7              = VK_OEM_7,
			OEM8              = VK_OEM_8,
			OEM102            = VK_OEM_102,
			Process           = VK_PROCESSKEY,
			Attn              = VK_ATTN,
			Crsel             = VK_CRSEL,
			Exsel             = VK_EXSEL,
			EraseEof          = VK_EREOF,
			Play              = VK_PLAY,
			Zoom              = VK_ZOOM,
			Pa1               = VK_PA1,
			OemClear          = VK_OEM_CLEAR,
		};

		enum class EventType
		{
			None,
			Activate,
			Close,
			Destroy,
			Move,
			Moving,
			EnterSizeMove,
			Size,
			Sizing,
			ExitSizeMove,
			Keyboard,
			Mouse
		};


		struct ActivateEvent
		{
			enum class ActivateReason
			{
				Inactive,
				ClickActive,
				Active,
			};

			ActivateReason Reason;
			HWND WindowHandle;
			bool IsMinimized;

			ActivateEvent(WPARAM wParam, LPARAM lParam)
				: Reason(ActivateReason(LOWORD(wParam)))
				, WindowHandle(reinterpret_cast<HWND>(lParam))
				, IsMinimized(HIWORD(wParam) != 0)
			{
			}
		};

		struct CloseEvent
		{
			HWND WindowHandle;

			CloseEvent(HWND hWnd) : WindowHandle(hWnd) {}
		};

		struct DestroyEvent
		{
			HWND WindowHandle;

			DestroyEvent(HWND hWnd) : WindowHandle(hWnd) {}
		};

		struct MoveEvent
		{
			int PosX;
			int PosY;

			MoveEvent(LPARAM lParam) : PosX((int)(short)LOWORD(lParam)), PosY((int)(short)HIWORD(lParam)) {}
		};

		struct MovingEvent
		{
			RECT* Rect;

			MovingEvent(LPARAM lParam) : Rect(reinterpret_cast<RECT*>(lParam)) {}
		};

		struct EnterSizeMoveEvent
		{
			HWND WindowHandle;

			EnterSizeMoveEvent(HWND hWnd) : WindowHandle(hWnd) {}
		};

		struct SizeEvent
		{
			enum class ResizeType
			{
				Restored,
				Minimized,
				MaxShow,
				Maximized,
				MaxHide,
			};

			ResizeType Type;
			int Width;
			int Height;

			SizeEvent(WPARAM wParam, LPARAM lParam)
				: Type(ResizeType(LOWORD(wParam)))
				, Width((int)(short)LOWORD(lParam))
				, Height((int)(short)HIWORD(lParam))
			{}
		};

		struct SizingEvent
		{
			enum class ResizeEdge
			{
				Bottom      = 6,
				BottomLeft  = 7,
				BottomRight = 8,
				Left        = 1,
				Right       = 2,
				Top         = 3,
				TopLeft     = 4,
				TopRight    = 5,
			};

			ResizeEdge Edge;
			RECT* Rect;

			SizingEvent(WPARAM wParam, LPARAM lParam)
				: Edge(ResizeEdge(wParam))
				, Rect(reinterpret_cast<RECT*>(lParam))
			{}
		};

		struct ExitSizeMoveEvent
		{
			HWND WindowHandle;

			ExitSizeMoveEvent(HWND hWnd) : WindowHandle(hWnd) {}
		};

		struct KeyboardEvent
		{
			enum class KeyState
			{
				Pressed,
				Held,
				Released,
			};

			KeyCode Key;
			KeyState State;
			//WORD RepeatCount;

			KeyboardEvent(WPARAM wParam, LPARAM lParam)
			{
				WORD vkCode        = LOWORD(wParam);
				WORD keyFlags      = HIWORD(lParam);
				WORD scanCode      = LOBYTE(keyFlags);
				bool isExtendedKey = (keyFlags & KF_EXTENDED) == KF_EXTENDED;

				if (isExtendedKey)
					scanCode = MAKEWORD(scanCode, 0xE0);

				switch (vkCode)
				{
				case VK_SHIFT:   // converts to VK_LSHIFT or VK_RSHIFT
				case VK_CONTROL: // converts to VK_LCONTROL or VK_RCONTROL
				case VK_MENU:    // converts to VK_LMENU or VK_RMENU
					vkCode = LOWORD(MapVirtualKeyW(scanCode, MAPVK_VSC_TO_VK_EX));
					break;
				}

				bool wasKeyDown    = (keyFlags & KF_REPEAT) == KF_REPEAT;
				bool isKeyReleased = (keyFlags & KF_UP) == KF_UP;
				//RepeatCount        = LOWORD(lParam);
				Key                = static_cast<KeyCode>(vkCode);

				if (isKeyReleased)
					State = KeyState::Released;
				else if (wasKeyDown)
					State = KeyState::Held;
				else
					State = KeyState::Pressed;
			}
		};

		struct MouseEvent
		{
			enum class EventType
			{
				ButtonDown,
				ButtonUp,
				DoubleClick,
				Move,
				Wheel,
				HWheel
			};

			EventType Type;
			KeyCode Button;
			int PosX;
			int PosY;
			int WheelDelta;
			bool IsCtrlDown;
			bool IsAltDown;
			bool IsShiftDown;

			MouseEvent(EventType type, WPARAM wParam, LPARAM lParam)
				: Type(type)
				, Button(KeyCode::None)
				, PosX(0)
				, PosY(0)
				, WheelDelta(0)
				, IsCtrlDown(false)
				, IsAltDown(false)
				, IsShiftDown(false)
			{
				POINTS pt = MAKEPOINTS(lParam);
				PosX = pt.x;
				PosY = pt.y;
				
				WPARAM key = wParam;

				switch (Type)
				{
					case EventType::ButtonDown:  [[fallthrough]];
					case EventType::ButtonUp:    [[fallthrough]];
					case EventType::DoubleClick: [[fallthrough]];
					case EventType::Move:
					{
						break;
					}
					
					case EventType::Wheel: [[fallthrough]];
					case EventType::HWheel:
					{
						key = GET_KEYSTATE_WPARAM(wParam);
						WheelDelta = GET_WHEEL_DELTA_WPARAM(wParam);
						break;
					}
				}

				IsCtrlDown = key & MK_CONTROL;
				IsAltDown = key & MK_ALT;
				IsShiftDown = key & MK_SHIFT;

				if (key & MK_LBUTTON)
					Button = KeyCode::LeftMouseButton;
				else if (key & MK_MBUTTON)
					Button = KeyCode::MiddleMouseButton;
				else if (key & MK_RBUTTON)
					Button = KeyCode::RightMouseButton;
				else if (key & MK_XBUTTON1)
					Button = KeyCode::X1MouseButton;
				else if (key & MK_XBUTTON2)
					Button = KeyCode::X2MouseButton;
			}
		};
	}


	class WindowClass
	{
	public:
		WindowClass(HINSTANCE hInstance,
			UINT style = s_windowClassStyle,
			XWIN2_STR className = XWIN2_WND_CLASS_NAME,
			HICON hIcon = NULL,
			HCURSOR hCursor = ::LoadCursorW(nullptr, IDC_ARROW),
			HBRUSH hbrBackground = NULL,
			XWIN2_STR lpszMenuName = NULL)
			: m_hInstance(hInstance)
			, m_isValid(false)
		{
			WNDCLASSEX wc{};
			ZeroMemory(&wc, sizeof(WNDCLASSEX));

			wc.cbSize        = sizeof(WNDCLASSEX);
			wc.style         = style;
			wc.hInstance     = hInstance;
			wc.lpfnWndProc   = XWin2::WndProc;
			wc.lpszClassName = XWIN2_WND_CLASS_NAME;
			wc.hIcon         = hIcon;
			wc.hCursor       = hCursor;
			wc.hbrBackground = hbrBackground;
			wc.lpszMenuName  = lpszMenuName;

			m_isValid = (RegisterClassEx(&wc) != NULL);
		}

		~WindowClass()
		{
			if (m_isValid)
			{
				::UnregisterClass(XWIN2_WND_CLASS_NAME, m_hInstance);
			}
		}

		inline HINSTANCE GetHInstance() const
		{
			return m_hInstance;
		}

		inline bool IsValid() const
		{
			return m_isValid;
		}

		inline operator bool() const
		{
			return m_isValid;
		}

		WindowClass(const WindowClass&) = delete;
		void operator=(const WindowClass&) = delete;


	private:
		HINSTANCE m_hInstance;
		bool      m_isValid;
	};


	class Window
	{
	public:
		struct Event
		{
			Events::EventType Type = Events::EventType::None;
			std::variant<std::monostate,
				Events::ActivateEvent,
				Events::CloseEvent,
				Events::DestroyEvent,
				Events::MoveEvent,
				Events::MovingEvent,
				Events::EnterSizeMoveEvent,
				Events::SizeEvent,
				Events::SizingEvent,
				Events::ExitSizeMoveEvent,
				Events::KeyboardEvent,
				Events::MouseEvent> EventData;

			Event()                                     : Type(Events::EventType::None)         , EventData(std::monostate{}) {}
			Event(Events::ActivateEvent activateEvent)  : Type(Events::EventType::Activate)     , EventData(activateEvent)    {}
			Event(Events::CloseEvent closeEvent)        : Type(Events::EventType::Close)        , EventData(closeEvent)       {}
			Event(Events::DestroyEvent closeEvent)      : Type(Events::EventType::Destroy)      , EventData(closeEvent)       {}
			Event(Events::MoveEvent moveEvent)          : Type(Events::EventType::Move)         , EventData(moveEvent)        {}
			Event(Events::MovingEvent movingEvent)      : Type(Events::EventType::Moving)       , EventData(movingEvent)      {}
			Event(Events::EnterSizeMoveEvent moveEvent) : Type(Events::EventType::EnterSizeMove), EventData(moveEvent)        {}
			Event(Events::SizeEvent sizeEvent)          : Type(Events::EventType::Size)         , EventData(sizeEvent)        {}
			Event(Events::SizingEvent sizeEvent)        : Type(Events::EventType::Sizing)       , EventData(sizeEvent)        {}
			Event(Events::ExitSizeMoveEvent moveEvent)  : Type(Events::EventType::ExitSizeMove) , EventData(moveEvent)        {}
			Event(Events::KeyboardEvent keyboardEvent)  : Type(Events::EventType::Keyboard)     , EventData(keyboardEvent)    {}
			Event(Events::MouseEvent mouseEvent)        : Type(Events::EventType::Mouse)        , EventData(mouseEvent)       {}
		};

	public:
		Window(const WindowClass& windowClass, XWIN2_STR title, int width, int height, int posX, int posY, DWORD style , DWORD exStyle = NULL, HMENU hMenu = NULL, HWND parentWindow = NULL)
			: m_hWnd(NULL)
			, m_style(style)
			, m_exStyle(exStyle)
			, m_minWidth(200)
			, m_minHeight(200)
			, m_rawMouseX(0)
			, m_rawMouseY(0)
		{
			m_hWnd = ::CreateWindowEx(
				exStyle,
				XWIN2_WND_CLASS_NAME,
				title,
				style,
				posX, posY,
				width, height,
				parentWindow,
				hMenu,
				windowClass.GetHInstance(),
				this
			);

			constexpr auto HID_USAGE_PAGE_GENERIC = 0x01;
			constexpr auto HID_USAGE_GENERIC_MOUSE = 0x02;

			RAWINPUTDEVICE Rid[1];
			Rid[0].usUsagePage = HID_USAGE_PAGE_GENERIC;
			Rid[0].usUsage     = HID_USAGE_GENERIC_MOUSE;
			Rid[0].dwFlags     = RIDEV_INPUTSINK;
			Rid[0].hwndTarget  = m_hWnd;

			if (!RegisterRawInputDevices(Rid, 1, sizeof(Rid[0])))
			{
				OutputDebugString(TEXT("Failed to register raw input devices.\n"));
			}

			::ShowWindow(m_hWnd, SW_SHOWNORMAL);
		}

		Window(const WindowClass& windowClass, XWIN2_STR title, int width, int height, DWORD style , DWORD exStyle = NULL, HMENU hMenu = NULL, HWND parentWindow = NULL)
			: Window(windowClass, title, width, height, CalculateCenteredX(width), CalculateCenteredY(height), style, exStyle, hMenu, parentWindow)
		{
		}

		~Window()
		{
			if (m_hWnd)
			{
				::DestroyWindow(m_hWnd);
				m_hWnd = NULL;
			}
		}

		inline HWND GetHWnd() const
		{
			return m_hWnd;
		}

		inline operator HWND() const
		{
			return m_hWnd;
		}

		inline void GetClientSize(int& width, int& height) const
		{
			RECT rect{};
			::GetClientRect(m_hWnd, &rect);

			width = rect.right - rect.left;
			height = rect.bottom - rect.top;
		}

		inline void GetWindowSize(int& width, int& height) const
		{
			RECT rect{};
			::GetWindowRect(m_hWnd, &rect);

			width = rect.right - rect.left;
			height = rect.bottom - rect.top;
		}

		inline void GetWindowPosition(int& x, int& y) const
		{
			RECT rect{};
			::GetWindowRect(m_hWnd, &rect);

			x = rect.left;
			y = rect.top;
		}

		inline void SetMinDimensions(int width, int height)
		{
			m_minWidth = width;
			m_minHeight = height;
		}

		bool ProcessMessages(Event& event)
		{
			MSG msg{};
			if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}

			// Return event in queue
			if (!m_eventQueue.empty())
			{
				event = m_eventQueue.front();
				m_eventQueue.pop();
			}
			else
			{
				// No event in queue
				event = Event();
			}

			return true;
		}

		inline LRESULT MessageHandler(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

		Window(const Window&) = delete;
		void operator=(const Window&) = delete;

	private:
		static int CalculateCenteredX(int width)
		{
			RECT desktopRect{};
			::GetWindowRect(::GetDesktopWindow(), &desktopRect);
			return (desktopRect.right / 2) - (width / 2);
		}

		static int CalculateCenteredY(int height)
		{
			RECT desktopRect{};
			::GetWindowRect(::GetDesktopWindow(), &desktopRect);
			return (desktopRect.bottom / 2) - (height / 2);
		}

	private:
		HWND              m_hWnd;
		DWORD             m_style;
		DWORD             m_exStyle;
		int               m_minWidth;
		int               m_minHeight;
		int               m_rawMouseX;
		int               m_rawMouseY;
		std::queue<Event> m_eventQueue;
	};


	inline LRESULT WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
		case WM_NCCREATE:
		{
			LPCREATESTRUCT pCreateStruct = reinterpret_cast<LPCREATESTRUCT>(lParam);
			Window* pObj = reinterpret_cast<Window*>(pCreateStruct->lpCreateParams);
			::SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pCreateStruct->lpCreateParams));
			return ::DefWindowProc(hWnd, uMsg, wParam, lParam);
		}
		}

		Window* pObj = reinterpret_cast<Window*>(::GetWindowLongPtr(hWnd, GWLP_USERDATA));
		if (pObj)
			return pObj->MessageHandler(hWnd, uMsg, wParam, lParam);
		else
			return ::DefWindowProc(hWnd, uMsg, wParam, lParam);
	}

	inline LRESULT Window::MessageHandler(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
		case WM_ACTIVATE:
		{
			m_eventQueue.push(Event(Events::ActivateEvent(wParam, lParam)));
			return 0;
		}

		case WM_CLOSE:
		{
			m_eventQueue.push(Event(Events::CloseEvent(hWnd)));
			return 0;
		}

		case WM_DESTROY:
		{
			m_eventQueue.push(Event(Events::DestroyEvent(hWnd)));
			return 0;
		}

		case WM_GETMINMAXINFO:
		{
			MINMAXINFO* pMinMaxInfo = reinterpret_cast<MINMAXINFO*>(lParam);
			pMinMaxInfo->ptMinTrackSize.x = m_minWidth;
			pMinMaxInfo->ptMinTrackSize.y = m_minHeight;
			return 0;
		}

		case WM_MOVE:
		{
			m_eventQueue.push(Event(Events::MoveEvent(lParam)));
			return 0;
		}

		case WM_MOVING:
		{
			m_eventQueue.push(Event(Events::MovingEvent(lParam)));
			return 0;
		}

		case WM_ENTERSIZEMOVE:
		{
			m_eventQueue.push(Event(Events::EnterSizeMoveEvent(hWnd)));
			return 0;
		}

		case WM_SIZE:
		{
			m_eventQueue.push(Event(Events::SizeEvent(wParam, lParam)));
			return 0;
		}

		case WM_SIZING:
		{
			m_eventQueue.push(Event(Events::SizingEvent(wParam, lParam)));
			return 0;
		}

		case WM_EXITSIZEMOVE:
		{
			m_eventQueue.push(Event(Events::ExitSizeMoveEvent(hWnd)));
			return 0;
		}

		case WM_KEYDOWN:    [[fallthrough]];
		case WM_KEYUP:      [[fallthrough]];
		case WM_SYSKEYDOWN: [[fallthrough]];
		case WM_SYSKEYUP:
		{
			m_eventQueue.push(Event(Events::KeyboardEvent(wParam, lParam)));
			return 0;
		}

		case WM_MOUSEMOVE:
		{
			m_eventQueue.push(Event(
				Events::MouseEvent(Events::MouseEvent::EventType::Move, wParam, lParam)));
			return 0;
		}

		case WM_LBUTTONDOWN: [[fallthrough]];
		case WM_RBUTTONDOWN: [[fallthrough]];
		case WM_MBUTTONDOWN:
		{
			m_eventQueue.push(Event(
				Events::MouseEvent(Events::MouseEvent::EventType::ButtonDown, wParam, lParam)));
			return 0;
		}

		case WM_LBUTTONUP: [[fallthrough]];
		case WM_RBUTTONUP: [[fallthrough]];
		case WM_MBUTTONUP:
		{
			m_eventQueue.push(Event(
				Events::MouseEvent(Events::MouseEvent::EventType::ButtonUp, wParam, lParam)));
			return 0;
		}

		case WM_LBUTTONDBLCLK: [[fallthrough]];
		case WM_RBUTTONDBLCLK: [[fallthrough]];
		case WM_MBUTTONDBLCLK:
		{
			m_eventQueue.push(Event(
				Events::MouseEvent(Events::MouseEvent::EventType::DoubleClick, wParam, lParam)));
			return 0;
		}

		case WM_INPUT:
		{
			UINT dwSize = sizeof(RAWINPUT);
			static BYTE lpb[sizeof(RAWINPUT)];

			::GetRawInputData((HRAWINPUT)lParam, RID_INPUT, lpb, &dwSize, sizeof(RAWINPUTHEADER));

			RAWINPUT* raw = (RAWINPUT*)lpb;

			[[likely]]
			if (raw && raw->header.dwType == RIM_TYPEMOUSE)
			{
				m_rawMouseX = raw->data.mouse.lLastX;
				m_rawMouseY = raw->data.mouse.lLastY;
			}
			return true;
		}
		}

		return ::DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
}
