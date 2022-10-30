#include "Win32WindowsManager.h"
#include <iostream>

int main()
{

    auto hWnd = WindowManager::createWin32Window();
    std::cout<<"hello world"<<std::endl;

#if 0
    MSG msg;
    while (GetMessage(&msg, NULL, NULL, NULL))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
#endif

    MSG msg;
    while(1)
    {
        GetMessage(&msg, NULL, NULL, NULL);
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}