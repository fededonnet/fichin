#include <fichin/fSpritesheet.hpp>
#include <fichin/fResourceManager.hpp>

//////////////////////////////////////////////

fSpritesheet::fSpritesheet(const sf::Texture &texture, int frameWidth, int frameHeight){
	_texture = &texture;
	const sf::Vector2u &textureSize = _texture->getSize();
	if(frameHeight == -1) frameHeight = textureSize.y;
	
	for(unsigned i = 0; i<textureSize.y; i+=frameHeight){
		for(unsigned j = 0; j<textureSize.x; j+=frameWidth){
			_rects.emplace_back(j, i, frameWidth, frameHeight);
		}
	}
}
