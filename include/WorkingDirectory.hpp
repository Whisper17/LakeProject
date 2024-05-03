#ifndef WorkingDirectory_hpp
#define WorkingDirectory_hpp

#include <string> 

class WorkingDirectory
{
public:
    WorkingDirectory();

    std::string& Get()
    {
    return path;
    }

private:

    std::string path;
};

#endif /* WorkingDirectory_hpp */
