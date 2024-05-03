#include "C_Sprite.hpp"
#include "Object.hpp"

C_Sprite::C_Sprite(Object* owner) : Component(owner), currentTextureId(-1)
{
}

void C_Sprite::Load(const std::string& filePath)
{
    if(allocator)
    {
        int textureId = allocator->Add(filePath);
        if(textureId >= 0 && textureId != currentTextureId)
        {
            currentTextureId = textureId;
            std::shared_ptr<sf::Texture> texture = allocator->Get(textureId);
            sprite.setTexture(*texture);
        }
    }
}

void C_Sprite::Load(int id)
{
    if(id >= 0 && id != currentTextureId)
    {
        //The smart_pointer allows us to not rely on duplicates in the ResourceAllocator
        //as each call to Load for the same resource uses a reference to that unique resource 
        //in the ResourceAllocator
        currentTextureId = id;
        std::shared_ptr<sf::Texture> texture = allocator->Get(id);
        sprite.setTexture(*texture);
    }
}

void C_Sprite::Draw(Window& window)
{
    window.Draw(sprite);
}

void C_Sprite::LateUpdate(float deltaTime)
{
    sprite.setPosition(owner->transform->GetPosition());
}

void C_Sprite::SetTextureAllocator(ResourceAllocator<sf::Texture>* allocator)
{
    this->allocator = allocator;
}

void C_Sprite::SetTextureRect(int x, int y, int width, int height)
{
    sprite.setTextureRect(sf::IntRect(x, y, width, height));
}

void C_Sprite::SetTextureRect(const sf::IntRect& rect)
{
    sprite.setTextureRect(rect);
}

void C_Sprite::SetScale(float x, float y)
{
    sprite.setScale(x, y);
}