#ifndef Animation_hpp
#define Animation_hpp

#include <vector>

struct FrameData
{
    int id; //Texture id (from texture allocator)
    int x; //x position of sprite in texture
    int y; //y position of sprite in texture
    int width; //Width of sprite
    int height; //Height of sprite
    float displayTimeSeconds; //How long to display the frame
};

enum struct FacingDirection
{
    None,
    Left,
    Right
};

class Animation
{
public:
    Animation(FacingDirection direction);

    void AddFrame(int textureId, int x, int y, 
        int width, int height, float frameTime);

    const FrameData* GetCurrentFrame() const;

    bool UpdateFrame(float deltaTime);

    void Reset();

    void SetDirection(FacingDirection dir);
    FacingDirection GetDirection() const;

private:
    void IncrementFrame();

    //Stores all frames for out animation
    std::vector<FrameData> frames;

    //Current frame
    int currentFrameIndex;

    //We use this to decide when to transition to the next frame
    float currentFrameTime;

    FacingDirection direction;
};

#endif /* Animation_hpp */
