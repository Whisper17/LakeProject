#include "Game.hpp"


Game::Game()
    : window("Lake Project v0.1.0")
{
    std::shared_ptr<SceneSplashScreen> splashScreen =
        std::make_shared<SceneSplashScreen>(workingDir,sceneStateMachine,
        window, textureAllocator);
        
    std::shared_ptr<SceneGame> gameScene =
        std::make_shared<SceneGame>(workingDir, textureAllocator);

    unsigned int splashScreenID = sceneStateMachine.Add(splashScreen);
    unsigned int gameSceneID = sceneStateMachine.Add(gameScene);

    splashScreen->SetSwitchToScene(gameSceneID);

    sceneStateMachine.SwitchTo(splashScreenID);

    deltaTime = clock.restart().asSeconds();
}
    
void Game::CaptureInput()
{
    sceneStateMachine.ProcessInput();
}

void Game::Update()
{
    window.Update();
    
    sceneStateMachine.Update(deltaTime);
}


void Game::CalculateDeltaTime()
{
    //Calculates the elapsed time between two consecutive runs of the main loop
    //Is then used to make the sprite movement independent from the frame rate in Update()
    deltaTime = clock.restart().asSeconds();
}


void Game::LateUpdate()
{
    sceneStateMachine.LateUpdate(deltaTime);
}

void Game::Draw()
{
    window.BeginDraw();

    // Drawing happens here
    sceneStateMachine.Draw(window);

    window.EndDraw();
}

bool Game::IsRunning() const
{
    return window.IsOpen();
}



