cmake_minimum_required(VERSION 3.15)
project(FizzleRpg)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the MSYS2 MinGW64 path
set(MINGW_PATH "C:/msys64/mingw64")

# Find SDL2 package
find_package(SDL2 REQUIRED PATHS "${MINGW_PATH}/lib/cmake/SDL2")

# Find SDL_image package
find_package(SDL2_image REQUIRED PATHS "${MINGW_PATH}/lib/cmake/SDL2_image")

# Find EnTT package
find_package(EnTT REQUIRED PATHS "${MINGW_PATH}/lib/cmake/EnTT")

# Add source files from src directory and Resources directory
file(GLOB_RECURSE SOURCES "src/**/*.cpp" "Resources/*.cpp")

# Create the executable
add_executable(FizzleRpg ${SOURCES} main.cpp)

# Include directories for headers
target_include_directories(FizzleRpg PRIVATE
        ${SDL2_INCLUDE_DIRS}
        ${SDL2_IMAGE_INCLUDE_DIRS}  # Include SDL_image headers
        ${ENTT_INCLUDE_DIRS}         # Include EnTT headers
        src
)

# Link libraries
target_link_libraries(FizzleRpg PRIVATE
        SDL2::SDL2main
        SDL2::SDL2
        SDL2_image::SDL2_image      # Link SDL_image library
)