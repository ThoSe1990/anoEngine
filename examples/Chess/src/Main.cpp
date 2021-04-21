

#include "ezEngine/ezEngine.hpp"

#include "lua/sol.hpp"

#include "Constants.hpp"


sol::state lua;

void InitializeLua()
{
    lua.open_libraries(sol::lib::base, sol::lib::os, sol::lib::math);
    lua.script_file("./assets/scripts/config.lua");

    sol::optional<int> chespieces_velocity_exists = lua["config"]["chespieces_velocity"];
    Constants::chespieces_velocity = (chespieces_velocity_exists == sol::nullopt) ? Constants::chespieces_velocity : lua["config"]["chespieces_velocity"];

    sol::optional<int> chessboard_offset_exists = lua["config"]["chessboard_offset"];
    Constants::chessboard_offset = (chessboard_offset_exists == sol::nullopt) ? Constants::chessboard_offset : lua["config"]["chessboard_offset"];    
}

void LoadAssets()
{
    lua.script_file("./assets/scripts/assets.lua");
    sol::table chessboardAssets = lua["chessboard_assets"];

    unsigned int index = 0;
    while (true)
    {
        sol::optional<sol::table> exists = chessboardAssets[index];
        if (exists == sol::nullopt)
            break;
        sol::table asset = chessboardAssets[index];
        std::string type = asset["type"];
        if (type.compare("texture") == 0)
        {
            std::string id = asset["id"];
            std::string file = asset["file"];  
            ezEngine::AddTexture(id, file.c_str());
        }
        index++;
    }
}



int main(int argc, char* argv[]) 
{

    ezEngine::Initialize();

    while (ezEngine::IsRunning()) 
    {
        ezEngine::ProcessInput();
        ezEngine::Update();
        ezEngine::Render();
    }

    ezEngine::Destroy();

    return 0;
}

