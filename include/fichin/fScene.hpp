#ifndef __FSCENE_HPP__
#define __FSCENE_HPP__
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include "fichin/fGroup.hpp"

/////////////////////////////////////////////////
/// Representa una escena genérica del juego
/////////////////////////////////////////////////
class fScene {
public:
	virtual void init(){};
	virtual void destroy(){};
	virtual void update(float dt){_members.update(dt);};
	virtual void draw(sf::RenderTarget &w, sf::RenderStates s) const {_members.draw(w, s);};	
	
	void add(fActor *a){_members.add(a);};
protected:
	fGroup _members;
};

#endif // __FSCENE_HPP__

