#include <fichin/fSprite.hpp>
#include <SFML/System/Vector2.hpp>

/////////////////////////////////////////////////

fSprite::fSprite():
fSpriteRenderer(static_cast<sf::Transformable &>(*this)),
fKinematicController(static_cast<sf::Transformable &>(*this)),
fAnimationController(static_cast<fSpriteRenderer &>(*this))
, fBoxCollider2D(this) {
	setCollidableObjectType(fActor::CollidableObjectType::SPRITE);
}

/////////////////////////////////////////////////

void fSprite::update(float dt){
	fKinematicController::updateKinematics(dt);
	fAnimationController::updateAnimation(dt);
	fBoxCollider2D::update(dt);
}

/////////////////////////////////////////////////

void fSprite::draw(sf::RenderTarget &w, sf::RenderStates s) const{
	fSpriteRenderer::draw(w, s);
	fBoxCollider2D::draw(w,s);
}
