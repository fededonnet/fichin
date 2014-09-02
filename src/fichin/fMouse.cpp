#include <fichin/input/fMouse.hpp>

fMouse::fMouseStatus fMouse::_currentStatus;
fMouse::fMouseStatus fMouse::_formerStatus;
sf::Window *fMouse::_window;

////////////////////////////////////////////////////////////////////////////////

bool fMouse::pressed(sf::Mouse::Button button){
	return sf::Mouse::isButtonPressed(button);
}

////////////////////////////////////////////////////////////////////////////////

bool fMouse::justPressed(sf::Mouse::Button button){
	sf::Mouse::isButtonPressed(button)?_currentStatus.buttonStatus |= 1<<button : _currentStatus.buttonStatus &= (0xffffffff ^ (1<<button));
	return (_currentStatus.buttonStatus & (1<<button)) != 0 && (_formerStatus.buttonStatus & (1<<button)) == 0;
}

////////////////////////////////////////////////////////////////////////////////

bool fMouse::justReleased(sf::Mouse::Button button){
	sf::Mouse::isButtonPressed(button)?_currentStatus.buttonStatus |= 1<<button : _currentStatus.buttonStatus &= (0xffffffff ^ (1<<button));
	return (_formerStatus.buttonStatus & (1<<button)) != 0 && (_currentStatus.buttonStatus & (1<<button)) == 0;
}

////////////////////////////////////////////////////////////////////////////////

const sf::Vector2i &fMouse::getPosition(){
	// TODO: debería devolver la posición respecto de la ventana de juego
	return _currentStatus.pos;
}

////////////////////////////////////////////////////////////////////////////////

void fMouse::setPosition(const sf::Vector2i &pos){
	sf::Mouse::setPosition(pos, *_window);
	_currentStatus.pos = pos;
}

////////////////////////////////////////////////////////////////////////////////

void fMouse::init(sf::Window &w){
	_currentStatus.buttonStatus = 0;
	_currentStatus.pos.x = _currentStatus.pos.y = 0;
	_formerStatus.buttonStatus = 0;
	_formerStatus.pos.x = _formerStatus.pos.y = 0;
	_window = &w;
}

////////////////////////////////////////////////////////////////////////////////

void fMouse::update(){
	_formerStatus = _currentStatus;
	_currentStatus.pos = sf::Mouse::getPosition(*_window);
}

////////////////////////////////////////////////////////////////////////////////

void fMouse::show(bool show){
	_window->setMouseCursorVisible(show);
}

////////////////////////////////////////////////////////////////////////////////

void fMouse::hide(){
	_window->setMouseCursorVisible(false);
}
