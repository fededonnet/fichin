#include <fichin/components/fSpriteRenderer.hpp>
#include <fichin/fResourceManager.hpp>
#include <fichin/fGame.hpp>

/////////////////////////////////////////////////

fSpriteRenderer::fSpriteRenderer(sf::Transformable &t):
_transform(&t),
_blendMode(sf::BlendMode::BlendAlpha),
_texture(nullptr),
_textureRect(nullptr),
_flipX(false),
_flipY(false)
{
	
}

/////////////////////////////////////////////////

void fSpriteRenderer::updatePositions()
{
	int width, height;
	if(_textureRect != NULL){
		width = _textureRect->width;
		height = _textureRect->height;
	}else{
		sf::Vector2u texSize = _texture->getSize();
		width = texSize.x;
		height = texSize.y; 
	}
	_vertices[0].position = sf::Vector2f(0.f, 0.f);
	_vertices[1].position = sf::Vector2f(0.f, height);
	_vertices[2].position = sf::Vector2f(width, 0.f);	
	_vertices[3].position = sf::Vector2f(width, height);	
}

/////////////////////////////////////////////////

void fSpriteRenderer::updateTexCoords()
{
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
	_vertices[2].texCoords = sf::Vector2f(_flipX?left:right, _flipY?bottom:top);
	_vertices[3].texCoords = sf::Vector2f(_flipX?left:right, _flipY?top:bottom);	
}

/////////////////////////////////////////////////

void fSpriteRenderer::draw(sf::RenderTarget &target, sf::RenderStates states) const
	{
		if(_texture != NULL){
			states.transform *= _transform->getTransform();
			states.texture = _texture;
			states.blendMode = _blendMode;
			target.draw(_vertices, 4, sf::TrianglesStrip, states);
		}
	}

/////////////////////////////////////////////////

void fSpriteRenderer::setTexture(const std::string &textureName)
{
	setTexture(fResourceManager::loadFromFile<sf::Texture>(textureName));
}

/////////////////////////////////////////////////

void fSpriteRenderer::setColor(const sf::Color &color)
{
	for(int i = 0; i<4; ++i){
		_vertices[i].color = color;
	}	
}

/////////////////////////////////////////////////

const sf::Color &fSpriteRenderer::getColor()
{
	return _vertices[0].color;
}

/////////////////////////////////////////////////

sf::Uint8 fSpriteRenderer::getAlpha()
{
	return _vertices[0].color.a;	
}

/////////////////////////////////////////////////

void fSpriteRenderer::setAlpha(sf::Uint8 alpha)
{
	for(int i = 0; i<4; ++i){
		_vertices[i].color.a = alpha;
	}
}

/////////////////////////////////////////////////

void fSpriteRenderer::setTextureRect(const sf::IntRect *rect)
{
	_textureRect = rect;
	updateTexCoords();
	updatePositions();
}

/////////////////////////////////////////////////

void fSpriteRenderer::setTexture(const sf::Texture &texture)
{
	_texture = &texture;
	setTextureRect();
}

/////////////////////////////////////////////////

void fSpriteRenderer::setTexture(const sf::Texture *texture, const sf::IntRect *rect)
{
	_texture = texture;
	_textureRect = rect;
	updateTexCoords();
	updatePositions();
}

////////////////////////////////////////////////////////////////////////////////

void fSpriteRenderer::flipX(bool flip)
{ 
	_flipX = flip;
	updateTexCoords();
}

////////////////////////////////////////////////////////////////////////////////

void fSpriteRenderer::flipY(bool flip)
{
	_flipY = flip;
	updateTexCoords();
}

////////////////////////////////////////////////////////////////////////////////

void fSpriteRenderer::centerOrigin()
{
	sf::Vector2f center;
	if(_textureRect != nullptr){
		center.x = _textureRect->width/2.0;
		center.y = _textureRect->height/2.0;
	}else if(_texture != nullptr){
		center.x = _texture->getSize().x/2.0;
		center.y = _texture->getSize().y/2.0;
	}else{
		center.x = center.y = 0;
	}
	_transform->setOrigin(center.x, center.y);
}

////////////////////////////////////////////////////////////////////////////////

bool fSpriteRenderer::isOnScreen()
{
	if(_texture)
	{
		const sf::FloatRect cameraRegion = fGame::getGame().getCurrentScene()->getCamera().getBounds();
		const sf::Vector2f &pos = _transform->getPosition();
		const sf::Vector2f &origin = _transform->getOrigin();
		const sf::Vector2u &texSize = _texture->getSize();
		sf::FloatRect spriteRect;
		spriteRect.left  	= pos.x - origin.x;
		spriteRect.width 	= _textureRect != nullptr?_textureRect->width:texSize.x;
		spriteRect.top 		= pos.y - origin.y;
		spriteRect.height 	= _textureRect != nullptr?_textureRect->height:texSize.y;
		return cameraRegion.intersects(spriteRect);
	}
	else
	{
		return false;
	}
}
