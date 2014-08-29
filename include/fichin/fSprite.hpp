#ifndef __FSPRITE_HPP__
#define __FSPRITE_HPP__

#include "fichin/fActor.hpp"
#include "fichin/components/fSpriteRenderer.hpp"
#include "fichin/components/fKinematicController.hpp"

/////////////////////////////////////////////////
/// Un actor especializado que puede dibujarse en pantalla
/////////////////////////////////////////////////
class fSprite: public fActor, public sf::Transformable, public fSpriteRenderer, public fKinematicController{
public:
	fSprite();
	void update(float dt);
	void draw(sf::RenderTarget &w, sf::RenderStates s) const;
};

#endif // __FSPRITE_HPP__

