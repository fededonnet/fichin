#ifndef __FSPRITESHEET_HPP__
#define __FSPRITESHEET_HPP__
#include <vector>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "fichin/fResourceManager.hpp"

class fSpritesheet{
public:
	const sf::IntRect &getRect(int i) const {
		return _rects[i];
	}
	
	const sf::Texture &getTexture() const {
		return *_texture;
	}
	
	unsigned int getRectCount() const {
		return _rects.size();
	}
	
	fSpritesheet(const sf::Texture &texture, int frameWidth, int frameHeight = -1);

private:
	const sf::Texture *_texture;
	std::vector<sf::IntRect> _rects;
};

#endif // __FSPRITESHEET_HPP__
