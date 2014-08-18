#include "fichin/SpriteActor.hpp"
#include <SFML/System/Vector2.hpp>


SpriteActor::SpriteActor()
{
	SpriteRenderer::setTransformable(*this);
	KinematicsController::setTransformable(*this);
}


/////////////////////////////////////////////////

void SpriteActor::update(float dt){
	KinematicsController::update(dt);
}

/////////////////////////////////////////////////

void SpriteActor::draw(sf::RenderTarget &w, sf::RenderStates s) const{
	drawTo(w, s);
}
