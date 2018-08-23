#pragma once
#include <memory>
#include "DXApp.h"
#include "SpriteBatch.h"
#include "SpriteFont.h"
#include "DDSTextureLoader.h"
#include "SimpleMath.h"
#include "Sprite.h"

class TestApp : public DXApp
{
public:
    TestApp(HINSTANCE hInstance);
    ~TestApp();

    bool Init() override;
    void Update(float dt) override;
    void Render(float dt) override;

private:
    std::unique_ptr<DirectX::SpriteBatch> spriteBatch;
    std::unique_ptr<DirectX::SpriteFont>  spriteFont;
    
    Sprite* sprite;
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
    Memory::SafeDelete(sprite);
}

bool TestApp::Init()
{
    if(!DXApp::Init())
        return false;

    // CREATE SPRITEBATCH OBJECTS
    spriteBatch.reset(new DirectX::SpriteBatch(m_pImmediateContext));

    // CREATE SPRITEFONT OBJECT
    spriteFont.reset(new DirectX::SpriteFont(m_pDevice, L"Arial.spritefont"));

    // CREATE A SIMPLE SPRITE
    sprite = new Sprite(DirectX::SimpleMath::Vector2(100, 100));
    sprite->Load(m_pDevice, L"img1.dds");

    return true;
}

void TestApp::Update(float dt)
{
}

void TestApp::Render(float dt)
{
    m_pImmediateContext->ClearRenderTargetView(m_pRenderTargetView, DirectX::Colors::CornflowerBlue);

    spriteBatch->Begin();

    // DRAW SPRITES, FONTS, ETC...
    sprite->Draw(spriteBatch.get());
    spriteFont->DrawString(spriteBatch.get(), L"Hello DirectX", DirectX::SimpleMath::Vector2(200, 200));

    spriteBatch->End();

    HR(m_pSwapChain->Present(0, 0));
}
