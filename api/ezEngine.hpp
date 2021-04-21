#ifndef _ezEngine_HPP_
#define _ezEngine_HPP_

#include <string>

namespace ezEngine
{

    void Initialize();
    bool IsRunning();
    void ProcessInput();
    void Update();
    void Render();
    void Destroy();
    void AddTexture(const std::string& textureId, const char* filePath);

}




#endif