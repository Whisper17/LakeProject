#ifndef Bitmask_hpp
#define Bitmask_hpp

#include <stdint.h>

class Bitmask
{
public:
    Bitmask();

    //Overwrites bitmask
    void SetMask(Bitmask& other);

    //Return binary representation of bitmask
    uint32_t GetMask() const;

    //Returns True if bit at pos = 1, else False
    bool GetBit(int pos) const;

    //Sets bit at specified pos to 1 or 0 (True or False)
    void SetBit(int pos, bool on);

    //Sets bit at pos to 1
    void SetBit(int pos);

    //Sets bit at pos to 0
    void ClearBit(int pos);

    //Set all bits to 0
    void Clear();

private:
    uint32_t bits;
};

#endif /* Bitmask_hpp */
