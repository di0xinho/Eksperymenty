cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(main src/main.cpp "src/Game.cpp" "src/MenuState.cpp" "src/AssetManager.cpp" "src/StateMachine.cpp" "src/InputManager.cpp" "src/GameState.cpp" "src/PauseState.cpp" "src/SoundManager.cpp" "src/Player.cpp" "src/Platform.cpp" "src/Land.cpp" "src/Collision.cpp" "src/ScoreManager.cpp" "src/GameOverState.cpp")
target_compile_features(main PRIVATE cxx_std_17)

target_link_libraries(main PRIVATE sfml-graphics sfml-window sfml-system sfml-audio)

target_include_directories(main PRIVATE include)
