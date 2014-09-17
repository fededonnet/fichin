
#include <SFML/Window/Event.hpp>
#include <fichin/fGame.hpp>
#include <fichin/input/fKeyboard.hpp>
#include <fichin/input/fMouse.hpp>

fGame *fGame::_singletonInst = nullptr;		

//////////////////////////////////////////////

void fGame::init(const sf::VideoMode &vm)
{
	_window.create(vm, "");
	_window.setFramerateLimit(60);
	_window.setKeyRepeatEnabled(false);
	fKeyboard::init();
	fMouse::init(_window);
	srand (time(NULL));
}

//////////////////////////////////////////////

fGame &fGame::getGame()
{
	if(_singletonInst == nullptr){
		_singletonInst = new fGame;
	}
	return *_singletonInst;
}

//////////////////////////////////////////////

fGame::fGame()
: _currentScene(nullptr)
, _nextScene(nullptr)
, _sceneSwitchRequested(false) {
	
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
	while (!gameOver)
	{
		while(_window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				gameOver = true;
			}					
		}
		
		fKeyboard::update();
		fMouse::update();
		dt = clock.restart().asSeconds();
		_currentScene->update(dt);		
		_window.clear(_currentScene->getBgColor());
		_currentScene->getCamera().update(dt);
		_window.setView(_currentScene->getCamera());
		_currentScene->draw(_window, states);
		_window.display();
		
		if(_sceneSwitchRequested)
		{
			_sceneSwitchRequested = false;
			_currentScene->destroy();
			delete _currentScene;
			_currentScene = _nextScene;
			_currentScene->init();
		}
	}
	
	return 0;
}

//////////////////////////////////////////////

void fGame::switchScene(fScene *nextScene)
{		
	_nextScene = nextScene;
	_sceneSwitchRequested = true;	
}

//////////////////////////////////////////////

fScene *fGame::getCurrentScene()
{
	return _currentScene;
}

//////////////////////////////////////////////

sf::Vector2u fGame::getWindowSize() const
{
	return _window.getSize();
}

