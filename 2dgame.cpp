#include <windows.h>

// Window dimensions
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

// Game state variables
int playerX = 100;
int playerY = 100;

// Main game loop
void GameLoop(HWND hwnd)
{
    // Get device context for drawing
    HDC hdc = GetDC(hwnd);
    
    // Set color to blue
    SetDCBrushColor(hdc, RGB(0, 0, 255));
    
    // Draw player at current position
    Rectangle(hdc, playerX, playerY, playerX + 50, playerY + 50);
    
    // Release device context
    ReleaseDC(hwnd, hdc);
    
    // Move player position
    playerX += 5;
    playerY += 5;
    
    // Check for collision with screen edges
    if (playerX > WINDOW_WIDTH - 50 || playerX < 0)
    {
        playerX -= 5;
    }
    
    if (playerY > WINDOW_HEIGHT - 50 || playerY < 0)
    {
        playerY -= 5;
    }
}

// Window message handler
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_PAINT:
            GameLoop(hwnd);
            break;
            
        case WM_CLOSE:
            DestroyWindow(hwnd);
            break;
            
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
            
        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    
    return 0;
}

// Entry point of the program
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // Register window class
    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "MyWindowClass";
    RegisterClass(&wc);
    
    // Create window
    HWND hwnd = CreateWindowEx(0, "MyWindowClass", "My Game", WS_OVERLAPPEDWINDOW, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, NULL, NULL, hInstance, NULL);
    
    // Show window
    ShowWindow(hwnd, nCmdShow);
    
    // Enter message loop
    MSG msg = { 0 };
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    return msg.wParam;
}
