#pragma once

#include "DXApp.h"

class TestApp : public DXApp
{
public:
    TestApp(HINSTANCE hInstance);
    ~TestApp();

    bool Init() override;
    void Update(float dt) override;
    void Render(float dt) override;
};

int WINAPI WinMain(__in HINSTANCE hInstance, __in HINSTANCE hPrevInstance, __in LPSTR lCmdLine, __in int nShowCmd)
{
    TestApp testApp(hInstance);

    if(!testApp.Init())
        return 1;

    return testApp.Run();
}

TestApp::TestApp(HINSTANCE hInstance) : DXApp(hInstance)
{
}

TestApp::~TestApp()
{
}

bool TestApp::Init()
{
    return DXApp::Init();
}

void TestApp::Update(float dt)
{
}

void TestApp::Render(float dt)
{
    m_pImmediateContext->ClearRenderTargetView(m_pRenderTargetView, DirectX::Colors::CornflowerBlue);
    m_pSwapChain->Present(0, 0);
}
