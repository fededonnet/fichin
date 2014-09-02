#ifndef __PLAYSCENE_HPP__
#define __PLAYSCENE_HPP__

#include <fichin/fScene.hpp>
#include <fichin/fSprite.hpp>

class PlayScene: public fScene{
public:
	void init();
	void update(float dt);
	
private:
	fSprite *a;
};

#endif	// __PLAYSCENE_HPP__

