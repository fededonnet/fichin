#include "fichin/components/fAnimationController.hpp"
#include <string>

fAnimationController::fAnimationController(){
	_spritesheet = nullptr;
	_spriteRenderer = nullptr;
	_animation = nullptr;
	_frameElapsed = 0;
	_currentFrame = 0;
	_isPlaying = false;
}

void fAnimationController::setRenderer(fSpriteRenderer &renderer){
	_spriteRenderer = &renderer;
}

void fAnimationController::playAnimation(const std::string &animName, bool restart){
	playAnimation(fResourceManager::get<fAnimation>(animName), restart);
}

void fAnimationController::playAnimation(const fAnimation &anim, bool restart){
	if(_animation != &anim || restart){
		_animation = &anim;
		_isPlaying = true;
		_frameElapsed = 0;
		_currentFrame = 0;
		setFrame(0);
	}
}

void fAnimationController::setSpritesheet(const fSpritesheet &spritesheet){
	_spritesheet = &spritesheet;
}

void fAnimationController::setSpritesheet(const std::string &name){
	_spritesheet = &fResourceManager::get<fSpritesheet>(name);
}

void fAnimationController::setSpritesheet(const std::string &textureName, int frameWidth, int frameHeight, const std::string &name){
	const sf::Texture &texture = fResourceManager::loadFromFile<sf::Texture>(textureName);
	frameHeight = frameHeight != -1?frameHeight:texture.getSize().y;
	//if(name == "") name = textureName+="_"+std::to_string(frameWidth)+"_"+std::to_string(frameHeight);
	setSpritesheet(texture, frameWidth, frameHeight, name!=""?name: "ss_"+textureName);
}

void fAnimationController::setSpritesheet(const sf::Texture &texture, int frameWidth, int frameHeight, const std::string &name){
	_spritesheet = &fResourceManager::load<fSpritesheet>(name, texture, frameWidth, frameHeight);
	_spriteRenderer->setTexture(texture);
	setFrame(0);
}


void fAnimationController::setFrame(int frame){
	_spriteRenderer->setTextureRect(&_spritesheet->getRect(frame));
}

void fAnimationController::update(float dt){
	if(_isPlaying && _animation != nullptr && _spritesheet != nullptr){
		_frameElapsed += dt;
		if(_frameElapsed >= _animation->getFrameDuration()){
			_frameElapsed -= _animation->getFrameDuration();
			++_currentFrame;
			if(_currentFrame < _animation->getFrameCount()){
				setFrame(_animation->getFrame(_currentFrame));
			}else if(_animation->loops()){
				_currentFrame = 0;
				setFrame(_animation->getFrame(_currentFrame));
			}else{
				_isPlaying = false;
			}
			
		}
	}
}


void fAnimationController::addAnimation(const std::string &animName, std::initializer_list<int> frames, float fps, bool loop){
	fResourceManager::load<fAnimation>(animName, animName, frames, fps, loop);
}
