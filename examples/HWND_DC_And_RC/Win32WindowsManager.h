#ifndef WIN32WINDOWSMANAGER_H_
#define WIN32WINDOWSMANAGER_H_

#include <iostream>
#include <windows.h>
#include <winuser.h>
#include <cassert>

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
        case WM_DESTROY:
            PostQuitMessage(0); //一定要加啊
            break;
        default:
            break;
    }

    return DefWindowProc(hWnd, message, wParam, lParam);
}


class WindowManager
{
public:
    WindowManager()
    = default;
    ~WindowManager()
    = default;

    static HWND createWin32Window()
    {
        [[maybe_unused]] const wchar_t CLASS_NAME[]  = L"Sample Window Class";
        WNDCLASS wc = { 0 };
        wc.lpfnWndProc   = WndProc;
        wc.cbClsExtra = sizeof(wc);
        wc.lpszClassName = "OpenGL Text Window";

        if(!RegisterClass(&wc))
        {
            std::cout<<"RegisterClass Failed"<<std::endl;
            assert(false);
        }

        auto hwnd =  CreateWindow("OpenGL Text Window","OpenGL Text Window",WS_OVERLAPPEDWINDOW,100,100,640,480,nullptr,nullptr,nullptr,nullptr);

        if (!hwnd)
        {
            std::cout<<"Create Window Failed"<<std::endl;
            assert(hwnd->unused);
        }

        ShowWindow(hwnd, SW_SHOW);

        return hwnd;
    }


};



#endif // WIN32WINDOWSMANAGER_H_