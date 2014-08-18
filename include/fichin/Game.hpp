#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include "fichin/Scene.hpp"

/////////////////////////////////////////////////
/// Representa un juego, lleva el control de
/// la ventana y el gameloop
/////////////////////////////////////////////////
class Game {   
public:
	Game(sf::VideoMode);
	void switchScene(Scene *nextScene);
	int run(Scene *scene);
	
private:
	Scene *_currentScene;       /// puntero a la escena actual
	Scene *_nextScene;          /// puntero a la proxima escena
	bool _sceneSwitchRequested; /// indica si debe realizarse un cambio de escena
	sf::RenderWindow _window;	/// la ventana de juego
};

#endif
