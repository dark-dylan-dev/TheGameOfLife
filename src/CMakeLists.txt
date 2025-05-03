# Adding files
add_executable(TheGameOfLife "main.cpp" "Game.cpp")
target_sources(TheGameOfLife PUBLIC FILE_SET CXX_MODULES FILES "Modules/std.ixx" "Modules/GameConsole.ixx" "Modules/GameSetup.ixx" "Modules/GameMenus.ixx")

# Requires C++23
target_compile_features(TheGameOfLife PRIVATE cxx_std_23)

# Including SFML 2.6.2
include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.2
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

target_link_libraries(TheGameOfLife PRIVATE sfml-system sfml-window sfml-graphics sfml-audio sfml-network)