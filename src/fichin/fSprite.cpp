#include "fichin/fSprite.hpp"
#include <SFML/System/Vector2.hpp>


fSprite::fSprite()
{
	fSpriteRenderer::setTransformable(*this);
	fKinematicController::setTransformable(*this);
}


/////////////////////////////////////////////////

void fSprite::update(float dt){
	fKinematicController::update(dt);
}

/////////////////////////////////////////////////

void fSprite::draw(sf::RenderTarget &w, sf::RenderStates s) const{
	drawTo(w, s);
}
