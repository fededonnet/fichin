#include "fichin/components/SpriteRenderer.hpp"

SpriteRenderer::SpriteRenderer(){
	_flipX = _flipY = false;
	_texture = NULL;
	_textureRect = NULL;
	//_blendMode = sf::BlendMode::BlendAlpha;
}

void SpriteRenderer::setTransformable(const sf::Transformable &t){
	_transform = &t;
}

void SpriteRenderer::updatePositions() {
	int width, height;
	if(_textureRect != NULL){
		width = _textureRect->width;
		height = _textureRect->height;
	}else{
		sf::Vector2u texSize = _texture->getSize();
		width = texSize.x;
		height = texSize.y; 
	}
	width = _textureRect?_textureRect->height:_texture->getSize().y;
	_vertices[0].position = sf::Vector2f(0.f, 0.f);
	_vertices[1].position = sf::Vector2f(0.f, height);
	_vertices[2].position = sf::Vector2f(width, height);
	_vertices[3].position = sf::Vector2f(width, 0.f);
	
	// 1-2
	// | |
	// 0 3
}

void SpriteRenderer::updateTexCoords(){
	float left, right, top, bottom;
	if(_textureRect != NULL){
		left   = _textureRect->left;
		right  = _textureRect->left + _textureRect->width;
		top    = _textureRect->top;
		bottom = _textureRect->top + _textureRect->height;
	}else{
		left   = top = 0;
		const sf::Vector2u &texSize = _texture->getSize();
		right  = texSize.x;
		bottom = texSize.y;
	}
	_vertices[0].texCoords = sf::Vector2f(_flipX?right:left, _flipY?bottom:top);
	_vertices[1].texCoords = sf::Vector2f(_flipX?right:left, _flipY?top:bottom);
	_vertices[2].texCoords = sf::Vector2f(_flipX?left:right, _flipY?top:bottom);
	_vertices[3].texCoords = sf::Vector2f(_flipX?left:right, _flipY?bottom:top);
}

void SpriteRenderer::drawTo(sf::RenderTarget &target, sf::RenderStates states) const {
	if(_texture != NULL){
		states.transform *= _transform->getTransform();
		states.texture = _texture;
		states.blendMode = _blendMode;
		target.draw(_vertices, 4, sf::Quads, states);
	}
}


void SpriteRenderer::setColor(const sf::Color &color){
	for(int i = 0; i<4; ++i){
		_vertices[i].color = color;
	}	
}

const sf::Color &SpriteRenderer::getColor(){
	return _vertices[0].color;
}

sf::Uint8 SpriteRenderer::getAlpha(){
	return _vertices[0].color.a;	
}

void SpriteRenderer::setAlpha(sf::Uint8 alpha){
	for(int i = 0; i<4; ++i){
		_vertices[i].color.a = alpha;
	}
}


void SpriteRenderer::setTextureRect(const sf::IntRect *rect){
	_textureRect = rect;
	updateTexCoords();
	updatePositions();
}


void SpriteRenderer::setTexture(const sf::Texture &texture){
	_texture = &texture;
	setTextureRect();
}


void SpriteRenderer::setTexture(const sf::Texture *texture, const sf::IntRect *rect){
	_texture = texture;
	_textureRect = rect;
	updateTexCoords();
	updatePositions();
}
