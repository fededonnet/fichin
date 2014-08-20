#include "fichin/input/Mouse.hpp"
using namespace std;

Mouse::MouseStatus Mouse::_currentStatus;
Mouse::MouseStatus Mouse::_formerStatus;
sf::Window *Mouse::_window;

bool Mouse::pressed(sf::Mouse::Button button){
	return sf::Mouse::isButtonPressed(button);
}

bool Mouse::justPressed(sf::Mouse::Button button){
	sf::Mouse::isButtonPressed(button)?_currentStatus.buttonStatus |= 1<<button : _currentStatus.buttonStatus &= (0xffffffff ^ (1<<button));
	return (_currentStatus.buttonStatus & (1<<button)) != 0 && (_formerStatus.buttonStatus & (1<<button)) == 0;
}

bool Mouse::justReleased(sf::Mouse::Button button){
	sf::Mouse::isButtonPressed(button)?_currentStatus.buttonStatus |= 1<<button : _currentStatus.buttonStatus &= (0xffffffff ^ (1<<button));
	return (_formerStatus.buttonStatus & (1<<button)) != 0 && (_currentStatus.buttonStatus & (1<<button)) == 0;
}

const sf::Vector2i &Mouse::getPosition(){
	// TODO: debería devolver la posición respecto de la ventana de juego
	return _currentStatus.pos;
}

void Mouse::setPosition(const sf::Vector2i &pos){
	sf::Mouse::setPosition(pos, *_window);
	_currentStatus.pos = pos;
}

void Mouse::init(sf::Window &w){
	_currentStatus.buttonStatus = 0;
	_currentStatus.pos.x = _currentStatus.pos.y = 0;
	_formerStatus.buttonStatus = 0;
	_formerStatus.pos.x = _formerStatus.pos.y = 0;
	_window = &w;
}

void Mouse::update(){
	_formerStatus = _currentStatus;
	_currentStatus.pos = sf::Mouse::getPosition(*_window);
}


void Mouse::show(bool show){
	_window->setMouseCursorVisible(show);
}

void Mouse::hide(){
	_window->setMouseCursorVisible(false);
}
