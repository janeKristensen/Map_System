#include "TextureHolder.h"
#include <assert.h>

TextureHolder* TextureHolder::m_s_Instance = nullptr;

TextureHolder::TextureHolder()
{
	assert(m_s_Instance == nullptr);
	m_s_Instance = this;
}

sf::Texture& TextureHolder::GetTexture(std::string const& filename)
{
	auto& m = m_s_Instance->m_Textures;

	auto keyValuePair = m.find(filename);

	if (keyValuePair != m.end())
	{
		//Yes. Return texture
		return keyValuePair->second;
	}
	else
	{
		//filename not found 
		//create new key value pair using the filename
		auto& texture = m[filename];
		texture.loadFromFile(filename);

		return texture;
	}
}

