#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <unordered_map>

class ResourceManager {
public:
    static ResourceManager& getInstance() {
        static ResourceManager instance;
        return instance;
    }

    SDL_Texture* loadTexture(const std::string& filePath, SDL_Renderer* renderer);
    void addTexture(const std::string& id, const std::string& filePath, SDL_Renderer* renderer);
    SDL_Texture* getTexture(const std::string& id) const;
    ~ResourceManager();

private:
    ResourceManager() = default;
    ResourceManager(const ResourceManager&) = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;

    std::unordered_map<std::string, SDL_Texture*> textures;
};

#endif // RESOURCEMANAGER_H