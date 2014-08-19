#include "fichin/input/MouseHandler.hpp"
MouseHandler::MouseHandler() {
	
}
	
MouseHandler::~MouseHandler() {
	
}

void MouseHandler::connect(EventType type, std::function<void(sf::Vector2i const&)> callback) {
	events[type] = callback;
}

void MouseHandler::disconnect(EventType type) {
	if (events.find(type) != events.end()) {
		events.erase(type);
	}
}

void MouseHandler::disconnectAll() {
	events.clear();
}

void MouseHandler::listenEvents(sf::Event const& e, sf::RenderWindow const& window) {
	if (e.type ==  sf::Event::MouseButtonPressed && e.type == sf::Event::MouseMoved) {
		MouseHandler::getInstance()->callEvent(MouseHandler::EventType::LEFT_PRESSEDMOVE, sf::Mouse::getPosition(window));
	} else if (e.type ==  sf::Event::MouseButtonPressed) {
		if (e.mouseButton.button == sf::Mouse::Left) {
			MouseHandler::getInstance()->callEvent(MouseHandler::EventType::LEFT_PRESSED, sf::Mouse::getPosition(window));
		} else if(e.mouseButton.button == sf::Mouse::Right) {
			MouseHandler::getInstance()->callEvent(MouseHandler::EventType::RIGHT_PRESSED, sf::Mouse::getPosition(window));
		}
	} else if (e.type ==  sf::Event::MouseButtonReleased) {
		if (e.mouseButton.button == sf::Mouse::Left) {
			MouseHandler::getInstance()->callEvent(MouseHandler::EventType::LEFT_RELEASED, sf::Mouse::getPosition(window));
		} else if(e.mouseButton.button == sf::Mouse::Right) {
			MouseHandler::getInstance()->callEvent(MouseHandler::EventType::RIGHT_RELEASED, sf::Mouse::getPosition(window));
		}
	} else if (e.type == sf::Event::MouseWheelMoved) {
		if(e.mouseWheel.delta < 0) {
			MouseHandler::getInstance()->callEvent(MouseHandler::EventType::WHEEL_DOWN, sf::Mouse::getPosition(window));
		} else {
			MouseHandler::getInstance()->callEvent(MouseHandler::EventType::WHEEL_UP, sf::Mouse::getPosition(window));
		}
	}
}


void MouseHandler::callEvent(EventType type, sf::Vector2i const& mouse) {
	auto it = events.find(type);
	if ( it != events.end()) {
		it->second(mouse);
	}
}
