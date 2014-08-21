#ifndef __SPRITERENDERER_HPP__
#define __SPRITERENDERER_HPP__

#include <SFML/Graphics/BlendMode.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

class SpriteRenderer{
public:
	SpriteRenderer();
	void setTransformable(const sf::Transformable &t);
	inline void flipX(bool flip = true){ _flipX = flip; updateTexCoords(); };
	inline void flipY(bool flip = true){ _flipY = flip; updateTexCoords(); };
	
	void setColor(const sf::Color &color);
	inline const sf::Color &getColor();
	
	void setAlpha(sf::Uint8 alpha);
	sf::Uint8 getAlpha();
	
	inline void setBlendMode(sf::BlendMode blend) {_blendMode = blend;};
	inline sf::BlendMode getBlendMode(){return _blendMode;};
	
	void setTexture(const sf::Texture &texture);
	void setTexture(const sf::Texture *texture, const sf::IntRect *rect = NULL);
	
	// especifica el subrectangulo de textura (NULL para toda la textura)
	void setTextureRect(const sf::IntRect *rect = NULL);
	
	inline const sf::IntRect &getTextureRect() {return *_textureRect; };
	
	void drawTo(sf::RenderTarget &target, sf::RenderStates states) const;
	
protected:
	void updatePositions();
	void updateTexCoords();
	
private:
	const sf::Transformable *_transform;
	sf::Vertex _vertices[4];
	sf::BlendMode _blendMode;
	const sf::Texture *_texture;
	const sf::IntRect *_textureRect;
	bool _flipX, _flipY;
};

#endif	// __SPRITERENDERER_HPP__
