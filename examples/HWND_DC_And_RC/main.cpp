#include <windows.h>
#include <glad/glad.h>
#include <GL/gl.h>
#include <iostream>

//typedef void* (* GLADloadproc)(const char *name);

void display()
{
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
}


LONG WINAPI WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    static PAINTSTRUCT ps;

    switch(uMsg) {
        case WM_PAINT:
            display();
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
            }
            return 0;

        case WM_CLOSE:
            PostQuitMessage(0);
            return 0;
    }

    return DefWindowProc(hWnd, uMsg, wParam, lParam);
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
    static HINSTANCE hInstance = 0;

    /* only register the window class once - use hInstance as a flag. */
    if (!hInstance) {
        hInstance = GetModuleHandle(NULL);
        wc.style         = CS_OWNDC;
        wc.lpfnWndProc   = (WNDPROC)WindowProc;
        wc.cbClsExtra    = 0;
        wc.cbWndExtra    = 0;
        wc.hInstance     = hInstance;
        wc.hIcon         = LoadIcon(NULL, IDI_WINLOGO);
        wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
        wc.hbrBackground = NULL;
        wc.lpszMenuName  = NULL;
        wc.lpszClassName = "OpenGL";

        if (!RegisterClass(&wc)) {
            MessageBox(NULL, "RegisterClass() failed:  "
                             "Cannot register window class.", "Error", MB_OK);
            return NULL;
        }
    }

    hWnd = CreateWindow("OpenGL", title, WS_OVERLAPPEDWINDOW |
                                         WS_CLIPSIBLINGS | WS_CLIPCHILDREN,
                        x, y, width, height, NULL, NULL, hInstance, NULL);

    if (hWnd == NULL) {
        MessageBox(NULL, "CreateWindow() failed:  Cannot create a window.",
                   "Error", MB_OK);
        return NULL;
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
        MessageBox(NULL, "ChoosePixelFormat() failed:  "
                         "Cannot find a suitable pixel format.", "Error", MB_OK);
        return 0;
    }

    if (SetPixelFormat(hDC, pf, &pfd) == FALSE) {
        MessageBox(NULL, "SetPixelFormat() failed:  "
                         "Cannot set format specified.", "Error", MB_OK);
        return 0;
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

    hWnd = CreateOpenGLWindow("OpenGL", 100, 100, 640, 480, PFD_TYPE_RGBA, 0);
    if (hWnd == NULL)
        exit(1);

    hDC = GetDC(hWnd);
    hRC = wglCreateContext(hDC);
    wglMakeCurrent(hDC, hRC);

    ShowWindow(hWnd, SW_SHOW);




#if  0
    // debug load OpenGL Functions
    auto func_ret = wglGetProcAddress("glGenBuffers");

    if(func_ret == nullptr)
    {
        // func_ret = GetProcAddress()
        putchar(10);
    }

    int vao;
    glGenVertexArrays(1, reinterpret_cast<GLuint *>(&vao));

        auto glModleInst = glInst;
    if (GLADloadproc("glGenBuffers") == 0)
    {
        return -1;
    }

#endif

    std::cout<<glGetString(GL_VERSION)<<std::endl;

    while(GetMessage(&msg, hWnd, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    wglMakeCurrent(NULL, NULL);
    ReleaseDC(hWnd,hDC);
    wglDeleteContext(hRC);
    DestroyWindow(hWnd);

    return msg.wParam;
}