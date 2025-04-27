set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.2
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(TheGameOfLife "main.cpp" "Game.cpp")
target_compile_features(TheGameOfLife PRIVATE cxx_std_17)
target_link_libraries(TheGameOfLife PRIVATE sfml-system sfml-window sfml-graphics sfml-audio sfml-network)