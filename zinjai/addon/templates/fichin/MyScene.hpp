#ifndef SCENE_H
#define SCENE_H

#include "fichin/Scene.hpp"

class MyScene: public Scene{
public:
	void init();
	void update(float dt);
	void draw(sf::RenderTarget &w, sf::RenderStates s) const;
	void destroy();
};

#endif

