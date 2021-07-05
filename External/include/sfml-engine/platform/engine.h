#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <assert.h>
#include <algorithm> 
#include <unordered_map>
#include "SFML/Graphics.hpp"

class TextureHandle
{
    public:
        TextureHandle(const std::string& fileName, std::unique_ptr<sf::Texture> texture)
        : m_fileName(fileName), m_texture(std::move(texture))
        {
            m_isLoaded = true;            
        }

        TextureHandle(): m_isLoaded(false){}
        std::string GetFileName() {return m_fileName;}
        sf::Texture & GetTexture() const { return *m_texture;}
        bool GetIsLoaded() const {return m_isLoaded;}
    private:
        std::string m_fileName;
        std::unique_ptr<sf::Texture> m_texture;
        bool m_isLoaded;
};

class Resources
{
    public:
        Resources(Resources const& ) = delete;
        Resources &operator = (Resources const& ) = delete;
        ~Resources() = default;

        static Resources& Get()
        {
            static Resources instance;
            return instance;
        }

        template<class Resource>
        const Resource& GetResource (const std::string & fileName);
        template<class Resource>
        bool LoadResource(const std::string & fileName);
        //specializations
        template<>
        const TextureHandle & GetResource<TextureHandle>(const std::string & fileName);
        template<>
        bool LoadResource<sf::Texture>(const std::string & fileName);
    private:
        Resources(){}

        std::unordered_map < std::string, std::unique_ptr<sf::Texture> > m_textures;
        std::vector<std::unique_ptr<TextureHandle>> m_texturesHandles;
        
};

template<>
inline const TextureHandle & Resources::GetResource(const std::string & fileName)
{
    auto iterator = std::find_if(m_texturesHandles.begin(), m_texturesHandles.end(),
    [&](std::unique_ptr<TextureHandle>& handle) {return handle->GetFileName() == fileName; });
    
    TextureHandle handle;
    if(iterator != m_texturesHandles.end())
        return *(*iterator);
    
    return handle;
}

template<>
inline bool Resources::LoadResource<sf::Texture>(const std::string & fileName)
{
    auto texture = std::make_unique<sf::Texture>();
    bool isLoaded = texture->loadFromFile(fileName);
    
    if( isLoaded )
    {
        //m_textures[fileName] = std::move(texture);
        auto handle = std::make_unique<TextureHandle>(fileName, std::move(texture));
        m_texturesHandles.push_back(std::move(handle));
    }
    return isLoaded;
}