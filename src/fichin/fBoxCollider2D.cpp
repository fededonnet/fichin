#include "fichin/components/fBoxCollider2D.hpp"
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

fBoxCollider2D::fBoxCollider2D(sf::Transformable *t)
: _transform(t) 
, _rect(0.0f,0.0f,0.0f,0.0f)
, _renderShape(sf::Vector2f(0.0f,0.0f)) {
	_renderShape.setFillColor(sf::Color::Transparent);
	_renderShape.setOutlineColor(sf::Color::Red);
	_renderShape.setOutlineThickness(1.0f);	
	
}

fBoxCollider2D::~fBoxCollider2D() {
	
}

void fBoxCollider2D::setBox(int width, int height, bool draw, CollideMask mask) {
	_size.x = width;
	_size.y = height;
	_collideMask = mask;
	_draw = draw;	
	_rect.width = width;
	_rect.height = height;
	
	_renderShape.setSize(_size);
	_renderShape.setPosition(0,0);
	_renderShape.setOrigin(width/2.0f,height/2.0f);
	
	//---*Necesitamos "asignar" estos valores al _rect:
	update(0.0f);
}

void fBoxCollider2D::setCollideMask(CollideMask mask) {
	_collideMask = mask;
}

void fBoxCollider2D::update(float dt) {
	updateRect();
}

void fBoxCollider2D::updateRect() {
	sf::Vector2f pos 	= _transform->getPosition();
	sf::Vector2f scale 	= _transform->getScale();
	_rect.left	 		= pos.x - ((_size.x * scale.x)/2);
	_rect.top 	 	 	= pos.y - ((_size.y * scale.y)/2);
	_rect.width  	 	= pos.x + ((_size.x * scale.x)/2);
	_rect.height 	 	= pos.y + ((_size.y * scale.y)/2);
	
	if(_draw) {
		_renderShape.setSize(sf::Vector2f(_size.x * scale.x, _size.y * scale.y));
		_renderShape.setOrigin((_size.x * scale.x)/2.0f,(_size.y * scale.y)/2.0f);
		_renderShape.setPosition(pos);		
	}
}

void fBoxCollider2D::draw(sf::RenderTarget &w, sf::RenderStates s) const {
	if(_draw) {
		w.draw(_renderShape,s);
	}
}

bool fBoxCollider2D::contains(sf::Vector2f const& point) {	
	if(_size.x == 0.0f || _size.y == 0.0f) {
		return false;
	}
	return ((point.x >= _rect.left && point.x <= _rect.width) && (point.y >= _rect.top && point.y <= _rect.height));	
}

bool fBoxCollider2D::contains(float pointX, float pointY) {
	if(_size.x == 0.0f || _size.y == 0.0f) {
		return false;
	}
	return ((pointX >= _rect.left && pointX <= _rect.width) && (pointY >= _rect.top && pointY <= _rect.height));
}


bool fBoxCollider2D::overlaps(sf::Rect<int> const& otherRect) {
	if(_size.x == 0.0f || _size.y == 0.0f) {
		return false;
	}
	return ((_rect.width >= otherRect.left  && _rect.left <=  otherRect.width) && (_rect.height >= otherRect.top  && _rect.top <= otherRect.height));	
}

bool fBoxCollider2D::overlaps(fBoxCollider2D* other) {
	return overlaps(other->getBoxCollider2DRect());	
}
