#ifndef __FANIMATIONCONTROLLER_HPP__
#define __FANIMATIONCONTROLLER_HPP__
#include "fichin/fAnimation.hpp"
#include "fichin/components/fSpriteRenderer.hpp"
#include "fichin/fSpritesheet.hpp"
#include <string>
#include <initializer_list>

class fAnimationController{
public:
	fAnimationController();
	void setRenderer(fSpriteRenderer &renderer);
	
	
	void playAnimation(const std::string &animName, bool restart = false);
	void playAnimation(const fAnimation &anim, bool restart = false);
	void addAnimation();
	
	void setSpritesheet(const fSpritesheet &spritesheet);
	void setSpritesheet(const std::string &name);
	void setSpritesheet(const std::string &texture, int frameWidth, int frameHeight = -1, const std::string &name = "");
	void setSpritesheet(const sf::Texture &texture, int frameWidth, int frameHeight = -1, const std::string &name = "");
	
	void setFrame(int frame);
	static void addAnimation(const std::string &animName, std::initializer_list<int> frames, float fps = 5, bool loop = true);
	
	void update(float dt);
	
private:
	const fSpritesheet *_spritesheet;
	fSpriteRenderer *_spriteRenderer;
	const fAnimation *_animation;
	float _frameElapsed;
	int _currentFrame;
	bool _isPlaying;
};
	

#endif // __FANIMATIONCONTROLLER_HPP__
