#ifndef ObjectCollection_hpp
#define ObjectCollection_hpp

#include <memory>
#include <vector>

#include "Object.hpp"
#include "S_Drawable.hpp"

class ObjectCollection
{
public:
    void Add(std::shared_ptr<Object> object);
    void Add(std::vector<std::shared_ptr<Object>>& Objects);
    
    void Update(float deltaTime);
    void LateUpdate(float deltaTime);
    void Draw(Window& window);

    void ProcessNewObjects();
    void ProcessRemovals();

private:
    std::vector<std::shared_ptr<Object>> objects;
    std::vector<std::shared_ptr<Object>> newObjects;
    S_Drawable drawables;
};

#endif /* ObjectCollection_hpp */