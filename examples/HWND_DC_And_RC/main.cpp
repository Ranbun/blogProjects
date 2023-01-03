#include <Windows.h>
#include <glad/glad.h>
#include <iostream>
#include "triangle.h"
#include <gl/glu.h>

HMODULE glModleInst;
HMODULE glInst;

// load gl function
static void* cWGLGetProcAddr(const char *name)
{
    auto ret = wglGetProcAddress(name);
    if (ret == nullptr)
    {
        ret = GetProcAddress(glModleInst, name);
    }
    return ret;
}

[[maybe_unused]] void display()
{
#if  0
    /* rotate a triangle around */
    glClearColor(0.3,0.4,0.4,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0,  1,0);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-1, -1,0.0);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(1, -1,0.0);
    glEnd();
    glFlush();
#endif

#if 0
    auto mySphere = gluNewQuadric();
    gluQuadricDrawStyle(mySphere,GLU_LINE);
    gluSphere(mySphere,1.0,12,12);
#endif

}


LONG WINAPI WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    static PAINTSTRUCT ps;

    switch(uMsg) {
        case WM_PAINT:
            // display();
            BeginPaint(hWnd, &ps);
            EndPaint(hWnd, &ps);
            return 0;
        case WM_SIZE:
            glViewport(0, 0, LOWORD(lParam), HIWORD(lParam));
            PostMessage(hWnd, WM_PAINT, 0, 0);
            return 0;
        case WM_CHAR:
            switch (wParam)
            {
                case 27:			/* ESC key */
                    PostQuitMessage(0);
                    break;
                case 0:
                    break;
            }
            return 0;
        case WM_CLOSE:
            PostQuitMessage(0);
            return 0;

        default:
            return DefWindowProc(hWnd, uMsg, wParam, lParam);
    }
}

HWND
CreateOpenGLWindow(char* title, int x, int y, int width, int height,
                   BYTE type, DWORD flags)
{
    int         pf;
    HDC         hDC;
    HWND        hWnd;
    WNDCLASS    wc;
    PIXELFORMATDESCRIPTOR pfd;
    static HINSTANCE hInstance = nullptr;

    /* only register the window class once - use hInstance as a flag. */
    if (!hInstance) {
        hInstance = GetModuleHandle(nullptr);  // 获取当前的模块
        wc.style         = CS_OWNDC;        // ?创建Opengl窗口必须设置为此
        wc.lpfnWndProc   = (WNDPROC)WindowProc;
        wc.cbClsExtra    = 0;
        wc.cbWndExtra    = 0;
        wc.hInstance     = hInstance;
        wc.hIcon         = LoadIcon(nullptr, IDI_WINLOGO);
        wc.hCursor       = LoadCursor(nullptr, IDC_ARROW);
        wc.hbrBackground = nullptr;
        wc.lpszMenuName  = nullptr;
        wc.lpszClassName = "OpenGL";

        if (!RegisterClass(&wc)) {
            MessageBox(nullptr, "RegisterClass() failed:  "
                             "Cannot register window class.", "Error", MB_OK);
            return nullptr;
        }
    }

    hWnd = CreateWindow("OpenGL", title, WS_OVERLAPPEDWINDOW |
                                         WS_CLIPSIBLINGS | WS_CLIPCHILDREN,
                        x, y, width, height, nullptr, nullptr, hInstance, nullptr);

    if (hWnd == nullptr) {
        MessageBox(nullptr, "CreateWindow() failed:  Cannot create a window.",
                   "Error", MB_OK);
        return nullptr;
    }

    hDC = GetDC(hWnd);

    memset(&pfd, 0, sizeof(pfd));
    pfd.nSize        = sizeof(pfd);
    pfd.nVersion     = 1;          
    pfd.dwFlags      = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | flags;
    pfd.iPixelType   = type;
    pfd.cColorBits   = 32;

    pf = ChoosePixelFormat(hDC, &pfd);
    if (pf == 0) {
        MessageBox(nullptr, "ChoosePixelFormat() failed:  "
                         "Cannot find a suitable pixel format.", "Error", MB_OK);
        return nullptr;
    }

    if (SetPixelFormat(hDC, pf, &pfd) == FALSE) {
        MessageBox(nullptr, "SetPixelFormat() failed:  "
                         "Cannot set format specified.", "Error", MB_OK);
        return nullptr;
    }

    DescribePixelFormat(hDC, pf, sizeof(PIXELFORMATDESCRIPTOR), &pfd);

    ReleaseDC(hWnd,hDC);

    return hWnd;
}

int main()
{
    auto glInst = LoadLibraryA("opengl32.dll");
    if (glInst == NULL)
    {
        return -1;
    }

    HDC hDC;				/* device context */
    HGLRC hRC;				/* opengl context */
    HWND  hWnd;				/* window */
    MSG   msg;				/* message */

    glInst = LoadLibraryA("opengl32.dll");
    glModleInst = glInst;

    char * windowName = "OpenGL Window";
    hWnd = CreateOpenGLWindow(windowName, 100, 100, 640, 480, PFD_TYPE_RGBA, 0);
    if (hWnd == nullptr)
        exit(1);

    hDC = GetDC(hWnd);
    hRC = wglCreateContext(hDC);
    wglMakeCurrent(hDC, hRC);

    // debug load OpenGL Functions
    if (gladLoadGLLoader(cWGLGetProcAddr) == 0)
    {
        return -1;
    }

    ShowWindow(hWnd, SW_SHOW);

    // OpenGLb版本
    std::cout<<glGetString(GL_VERSION)<<std::endl;

    Triangle obj;
    obj.create(hDC, hRC);

    while(GetMessage(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
        obj.draw();
    }

    wglMakeCurrent(nullptr, nullptr);
    ReleaseDC(hWnd,hDC);
    wglDeleteContext(hRC);
    DestroyWindow(hWnd);

    return static_cast<int>(msg.wParam);
}                                                    