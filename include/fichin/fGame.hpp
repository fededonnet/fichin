#ifndef __FGAME_HPP__
#define __FGAME_HPP__

#include <SFML/Graphics/RenderWindow.hpp>
#include "fichin/fScene.hpp"

/////////////////////////////////////////////////
/// Representa un juego, lleva el control de
/// la ventana y el gameloop
/////////////////////////////////////////////////
class fGame {   
public:
	fGame(sf::VideoMode);
	void switchScene(fScene *nextScene);
	int run(fScene *scene);
	
private:
	fScene *_currentScene;       /// puntero a la escena actual
	fScene *_nextScene;          /// puntero a la proxima escena
	bool _sceneSwitchRequested; /// indica si debe realizarse un cambio de escena
	sf::RenderWindow _window;	/// la ventana de juego
};

#endif // __FGAME_HPP__
