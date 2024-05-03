cmake_minimum_required(VERSION 3.0.0)
project(LakeProject VERSION 0.1.0 LANGUAGES C CXX)

include_directories(${PROJECT_SOURCE_DIR}/include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

find_package(SFML COMPONENTS graphics CONFIG REQUIRED)

file(GLOB SOURCES src/*.cpp) 
#set(SOURCES 
#    src/Bitmask.cpp
#    src/C_KeyboardMovement.cpp
#    src/C_Sprite.cpp
#    src/C_Transform.cpp
#    src/Game.cpp
#    src/Input.cpp
#    src/Main.cpp
#    src/Object.cpp
#    src/ObjectCollection.cpp
#    src/SceneGame.cpp
#    src/SceneSplashScreen.cpp
#    src/SceneStateMachine.cpp
#    src/Window.cpp
#    src/WorkingDirectory.cpp) 

add_executable(LakeProject ${SOURCES})


target_link_libraries(LakeProject PRIVATE sfml-graphics)