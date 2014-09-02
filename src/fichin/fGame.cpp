#include <SFML/Window/Event.hpp>
#include <fichin/fGame.hpp>
#include <fichin/input/fKeyboard.hpp>
#include <fichin/input/fMouse.hpp>

//////////////////////////////////////////////

fGame::fGame(sf::VideoMode vm):
_sceneSwitchRequested(false)
{
	_window.create(vm, "");
	_window.setFramerateLimit(60);
	_window.setKeyRepeatEnabled(false);
	fKeyboard::init();
	fMouse::init(_window);
	srand (time(NULL));
}

//////////////////////////////////////////////

int fGame::run(fScene *scene)
{
	_currentScene = scene;
	_currentScene->init();
	bool gameOver = false;

	sf::RenderStates states;
	sf::Event e;	
	sf::Clock clock;
	
	float dt = .0f;
	
	/// bucle de juego
	while (!gameOver) {
		while(_window.pollEvent(e)) {
			if (e.type == sf::Event::Closed) {
				gameOver = true;
			}					
		}	
		fKeyboard::update();
		fMouse::update();
		dt = clock.restart().asSeconds();
		scene->update(dt);		
		_window.clear(sf::Color::Black);
		scene->draw(_window, states);
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

void fGame::switchScene(fScene *nextScene){
	_nextScene = nextScene;
	_sceneSwitchRequested = true;
}

//////////////////////////////////////////////

