#ifndef SPRITEACTOR_HPP
#define SPRITEACTOR_HPP

#include "fichin/Actor.hpp"
#include "fichin/components/SpriteRenderer.hpp"
#include "fichin/components/KinematicsController.hpp"

/////////////////////////////////////////////////
/// Un actor especializado que puede dibujarse en pantalla
/////////////////////////////////////////////////
class SpriteActor: public Actor, public sf::Transformable, public SpriteRenderer, public KinematicsController{
public:
	SpriteActor();
	void update(float dt);
	void draw(sf::RenderTarget &w, sf::RenderStates s) const;
};

#endif

