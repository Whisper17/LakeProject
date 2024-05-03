#ifndef C_Sprite_hpp
#define C_Sprite_hpp

#include "Component.hpp"
#include "C_Transform.hpp"
#include "ResourceAllocator.hpp"


class C_Sprite : public Component
{
public:
    C_Sprite(Object* owner);

    //Loads a sprite from file
    void Load(const std::string& filePath);

    //We override the draw method so we can draw our sprite.
    void Draw(Window& window) override;

    void LateUpdate(float deltaTime) override;

    //overloaded Load method for texture id
    void Load(int id);

    void SetTextureAllocator(ResourceAllocator<sf::Texture>* allocator);

    void SetTextureRect(int x, int y, int width, int height);

    void SetTextureRect(const sf::IntRect& rect);

    void SetScale(float x, float y);

private:
    ResourceAllocator<sf::Texture>* allocator;
    sf::Sprite sprite;
    int currentTextureId;
};

#endif /* C_Sprite */