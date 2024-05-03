#include "SceneGame.hpp"

SceneGame::SceneGame(WorkingDirectory& workingDir,
    ResourceAllocator<sf::Texture>& textureAllocator)
    : workingDir(workingDir), textureAllocator(textureAllocator),
        mapParser(textureAllocator)
{
}

void SceneGame::OnCreate()
{
    std::shared_ptr<Object> character = std::make_shared<Object>();

    //Add the components
    auto sprite = character->AddComponent<C_Sprite>();
    character->transform->SetPosition(100,678);
    sprite->SetTextureAllocator(&textureAllocator);
    
    auto movement = character->AddComponent<C_KeyboardMovement>();
    movement->SetInput(&input);
    
    auto animation = character->AddComponent<C_Animation>();

    int vikingTextureId = textureAllocator.Add(workingDir.Get() + "viking.png");
    
    const int frameWidth = 165;
    const int frameHeight = 145;

    std::shared_ptr<Animation> idleAnimation = std::make_shared<Animation>(FacingDirection::Right);

    const float idleAnimFrameSeconds = 0.2f;

    idleAnimation->AddFrame(vikingTextureId, 600, 0,
        frameWidth, frameHeight, idleAnimFrameSeconds);
    idleAnimation->AddFrame(vikingTextureId, 800, 1,
        frameWidth, frameHeight, idleAnimFrameSeconds);
    idleAnimation->AddFrame(vikingTextureId, 0, 145,
        frameWidth, frameHeight, idleAnimFrameSeconds);
    idleAnimation->AddFrame(vikingTextureId, 200, 145,
        frameWidth, frameHeight, idleAnimFrameSeconds);

    animation->AddAnimation(AnimationState::Idle, idleAnimation);
    
    // Create the animation.
	std::shared_ptr<Animation> walkAnimation =
		std::make_shared<Animation>(FacingDirection::Right); 
    const float walkAnimFrameSeconds = 0.15f;
	
	// Create the frames.
    walkAnimation->AddFrame(vikingTextureId, 600, 290, 
		frameWidth, frameHeight, walkAnimFrameSeconds); 
    walkAnimation->AddFrame(vikingTextureId, 800, 290, 
		frameWidth, frameHeight, walkAnimFrameSeconds);
    walkAnimation->AddFrame(vikingTextureId, 0, 435, 
		frameWidth, frameHeight, walkAnimFrameSeconds);
    walkAnimation->AddFrame(vikingTextureId, 200, 435, 
		frameWidth, frameHeight, walkAnimFrameSeconds);
    walkAnimation->AddFrame(vikingTextureId, 400, 435, 
		frameWidth, frameHeight, walkAnimFrameSeconds);
    
	// Add animation to our Viking.
	animation->AddAnimation(AnimationState::Walk, walkAnimation);
    
    objects.Add(character);

    sf::Vector2i mapOffset(0, 128);
    std::vector<std::shared_ptr<Object>> levelTiles
        = mapParser.Parse(workingDir.Get() + "Test Map 1.tmx", mapOffset);

    objects.Add(levelTiles);
}

void SceneGame::OnDestroy()
{
}

void SceneGame::ProcessInput()
{
    input.Update();
}

void SceneGame::Update(float deltaTime)
{
    objects.ProcessRemovals();
    objects.ProcessNewObjects();
    objects.Update(deltaTime);
}

void SceneGame::LateUpdate(float deltaTime)
{
    objects.LateUpdate(deltaTime);
}

void SceneGame::Draw(Window& window)
{
    //This will draw our new sprite component
    objects.Draw(window);
}