cmake_minimum_required(VERSION 3.15)
project(FizzleRpg)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the MSYS2 MinGW64 path
set(MINGW_PATH "C:/msys64/mingw64")

# Find SDL2 package
find_package(SDL2 REQUIRED PATHS "${MINGW_PATH}/lib/cmake/SDL2")

# Find EnTT package
find_package(EnTT REQUIRED PATHS "${MINGW_PATH}/lib/cmake/EnTT")

# Add source files from src directory, including subdirectories
file(GLOB_RECURSE SOURCES "src/**/*.cpp")

# Create the executable
add_executable(FizzleRpg ${SOURCES} main.cpp
        src/ECS/Components/ButtonComponent.h
        src/ECS/Systems/RenderSystem.h
        src/ECS/Systems/ButtonSystem.h)

# Include directories for headers
target_include_directories(FizzleRpg PRIVATE
        ${SDL2_INCLUDE_DIRS}
        ${ENTT_INCLUDE_DIRS}  # Include EnTT headers
        src
)

# Link libraries
target_link_libraries(FizzleRpg PRIVATE
        SDL2::SDL2main
        SDL2::SDL2
)