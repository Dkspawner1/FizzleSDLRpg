#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <unordered_map>
#include <iostream>

class ResourceManager {
public:
    static SDL_Texture* loadTexture(const std::string& filePath, SDL_Renderer* renderer);
    void addTexture(const std::string& id, const std::string& filePath, SDL_Renderer* renderer);
    SDL_Texture* getTexture(const std::string& id) const;
    ~ResourceManager();
private:
    std::unordered_map<std::string, SDL_Texture*> textures;
};

#endif // RESOURCEMANAGER_H