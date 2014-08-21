#ifndef ACTOR_HPP
#define ACTOR_HPP

#include <SFML/Graphics/Drawable.hpp>

/////////////////////////////////////////////////
/// Representa un actor genérico que puede
/// agregarse a una escena
/////////////////////////////////////////////////
class Actor: public sf::Drawable{
public:
	virtual void update(float dt){};
	virtual void draw(sf::RenderTarget &w, sf::RenderStates s) const {};
	bool getActive() { return isActive;}
	void setActive(bool isActive) { this->isActive = isActive;}
	
private:
	bool isActive;
};

#endif

