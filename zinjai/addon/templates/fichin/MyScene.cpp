#include <fichin/Game.hpp>
#include "MyScene.hpp"

const int windowWidth = 800;
const int windowHeight = 600;

void MyScene::init(){
	
}

void MyScene::update(float dt){
	
}

void MyScene::draw(sf::RenderTarget &w, sf::RenderStates s) const{
	
}

void MyScene::destroy(){
	
}


int main(int argc, char *argv[]){
	Game g(sf::VideoMode(windowWidth, windowHeight));
	g.run(new MyScene());
	return 0;
}

