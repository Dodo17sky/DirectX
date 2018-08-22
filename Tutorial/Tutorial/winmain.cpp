#pragma once

#include <Windows.h>

int WINAPI WinMain(__in HINSTANCE hInstance, __in HINSTANCE hPrevInstance, __in LPSTR lCmdLine, __in int nShowCmd)
{
    MessageBox(NULL, "Hello DirectX", "Test", NULL);

    return 0;
}