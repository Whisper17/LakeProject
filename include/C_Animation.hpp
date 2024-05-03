#ifndef C_Animation_hpp
#define C_Animation_hpp

#include "Component.hpp"
#include "Animation.hpp"
#include "C_Sprite.hpp"

enum class AnimationState
{
    None,
    Idle,
    Walk
};

class C_Animation : public Component
{
public:
    C_Animation(Object* owner);

    void Awake() override;

    void Update(float deltaTime) override;

    //Add animation to object. We need its state as well
    //so that we can switch to it
    void AddAnimation(AnimationState state, 
        std::shared_ptr<Animation> animation);

    //Set current animation state
    void SetAnimationState(AnimationState animationState);

    //Returns current animation state
    const AnimationState& GetAnimationState() const;

    void SetAnimationDirection(FacingDirection dir);

private:
    std::shared_ptr<C_Sprite> sprite;
    std::map<AnimationState, std::shared_ptr<Animation>> animations;

    //We store a reference to the current animation so we can quickly update and draw it
    std::pair<AnimationState, std::shared_ptr<Animation>> currentAnimation;
};

#endif /* C_Animation_hpp */
