#ifndef __FACTOR_HPP__
#define __FACTOR_HPP__

#include <SFML/Graphics/Drawable.hpp>

/////////////////////////////////////////////////
/// Representa un actor genérico que puede
/// agregarse a una escena
/////////////////////////////////////////////////
class fActor: public sf::Drawable{
public:
	virtual void update(float dt){};
	virtual void draw(sf::RenderTarget &w, sf::RenderStates s) const {};
	bool isAlive() { return _alive;};
	bool isVisible() { return _visible;};
	void kill() { _alive = _visible = false; };
	void setVisible(bool visible) { _visible = visible; };
	void revive() { _alive = true; };
	
private:
	bool _alive;
	bool _visible;
};

#endif // __FACTOR_HPP__

