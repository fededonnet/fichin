#ifndef SCENE_HPP
#define SCENE_HPP
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

/////////////////////////////////////////////////
/// Representa una escena genérica del juego
/////////////////////////////////////////////////
class Scene {
public:
	virtual void init(){};
	virtual void destroy(){};
	virtual void update(float dt){};
	virtual void draw(sf::RenderTarget &w, sf::RenderStates s) const {};
};

#endif

