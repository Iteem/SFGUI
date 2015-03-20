#include <SFGUI/Engines/Bob/TextureManager.hpp>
#include <SFGUI/Renderer.hpp>

namespace sfg {
namespace eng {
namespace bob {

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
}

PrimitiveTexture::Ptr TextureManager::GetTexture( std::shared_ptr<const sf::Image> image )
{
	TextureMap::const_iterator it( m_textures.find( image ) );
	if( it != m_textures.end() ) {
		return it->second;
	}

	if( !image ){
		return PrimitiveTexture::Ptr();
	}

	PrimitiveTexture::Ptr texture_handle( Renderer::Get().LoadTexture( *image ) );
	m_textures[image] = texture_handle;

	return texture_handle;
}

void TextureManager::UnloadTexture( std::shared_ptr<const sf::Image> image )
{
	m_textures.erase( image );
}

void TextureManager::swap( TextureManager& rhs )
{
	m_textures.swap(rhs.m_textures);
}

}
}
}

void swap( sfg::eng::bob::TextureManager& rhs, sfg::eng::bob::TextureManager& lhs )
{
	rhs.swap(lhs);
}