cmake_minimum_required(VERSION 3.28 FATAL_ERROR)

# Setting up CMake variables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)

# Adding files
add_executable(TheGameOfLife
    "main.cpp"
)
target_sources(TheGameOfLife
        PRIVATE
        FILE_SET CXX_MODULES
        FILES
        Modules/GameSetup.cppm
        Modules/GameMenus.cppm
        Modules/GameConsole.cppm
        PRIVATE
        Game.cpp
        Game.hpp
)

# Requires C++23
target_compile_features(TheGameOfLife PRIVATE cxx_std_23)

# Including SFML 2.6.2
include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

target_link_libraries(TheGameOfLife PRIVATE SFML::System SFML::Window SFML::Graphics SFML::Audio SFML::Network)