#ifndef C_KeyboardMovement_hpp
#define C_KeyboardMovement_hpp

#include "Component.hpp"
#include "Input.hpp"
#include "C_Animation.hpp"

class C_KeyboardMovement : public Component
{
public:
    C_KeyboardMovement(Object* owner);

    void SetInput(Input* input);
    void SetMovementSpeed(int moveSpeed);

    void Update(float deltaTime) override;

    void Awake() override;

private:
    int moveSpeed;
    Input* input;

    std::shared_ptr<C_Animation> animation;
};

#endif /* C_KeyboardMoment_hpp */
