#ifndef Tile_h
#define Tile_h

#include "ResourceAllocator.hpp"

// Stores common tile data.
struct TileInfo
{
    TileInfo() : tileId(-1)
    {
    }
    
    TileInfo(int textureId, unsigned int tileID, sf::IntRect textureRect) : textureId(textureId), tileId(tileId), textureRect(textureRect) { }
    
    int tileId;
    int textureId;
    sf::IntRect textureRect;
};

struct Tile
{
    std::shared_ptr<TileInfo> properties;
    int x;
    int y;
};

#endif /* Tile_h */
