#include "fichin/Game.hpp"
#include <SFML/Window/Event.hpp>

//////////////////////////////////////////////

Game::Game(sf::VideoMode vm){
	_window.create(vm, "");
}

//////////////////////////////////////////////

int Game::run(Scene *scene){
	_sceneSwitchRequested = false;
	_currentScene = scene;
	_currentScene->init();
	bool gameOver = false;
	sf::RenderStates states;
	//---*inicializa el generador de nro aleatorios:
	srand (time(NULL));
	//---*Objeto event:
	sf::Event e;	
	//---*Reloj (para obtener el delta time):
	sf::Clock clock;
	float dt = 0.0f;
	//---*Loop principal del Juego:
	while (!gameOver) {
		while(_window.pollEvent(e)) {
			if (e.type == sf::Event::Closed) {
				gameOver = true;
			}
		}	
		//---*Obtenemos el delta time del loop y reiniciamos el reloj:
		dt = clock.restart().asSeconds();
		//---*Actualizamos la escena:
		scene->update(dt);		
		//---*Limpiamos la pantalla (con color negro):
		_window.clear(sf::Color::Black);		
		//---*Dibujamos la escena:
		scene->draw(_window, states);
		//---*Mostramos el contenido del window:
		_window.display();		
		
		if(_sceneSwitchRequested){
			_sceneSwitchRequested = false;
			_currentScene->destroy();
			_currentScene = _nextScene;
			_currentScene->init();
		}
	}
	
	return 0;
}

//////////////////////////////////////////////

void Game::switchScene(Scene *nextScene){
	_nextScene = nextScene;
	_sceneSwitchRequested = true;
}

//////////////////////////////////////////////

