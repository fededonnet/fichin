#include <fichin/fGame.hpp>
#include "PlayScene.hpp"

const int windowWidth = 800;
const int windowHeight = 600;

void PlayScene::init(){
	// crea un sprite
	a = new fSprite();
	// posiciona el sprite
	a->setPosition(100, 100);
	// asigna una textura al sprite
	a->setTexture("assets/img/SoccerBall.png");
	// cambia la velocidad en X del sprite
	a->setVelocityX(30);
	// agrega esfml-graphics sfml-audio sfml-network sfml-window sfml-systeml sprite a la escena
	add(a);
}

void PlayScene::update(float dt){
	fScene::update(dt);
}


int main(int argc, char *argv[]){
	fGame g(sf::VideoMode(windowWidth, windowHeight));
	g.run(new PlayScene());
	return 0;
}

