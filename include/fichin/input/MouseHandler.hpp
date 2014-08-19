#ifndef __MOUSEHANDLER_HPP__
#define __MOUSEHANDLER_HPP__
#include "fichin/utils/Singleton.hpp"
#include <functional>
#include <SFML/System/Vector2.hpp>
#include <map>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class MouseHandler : public Singleton<MouseHandler> {
public:	
	enum EventType {
		LEFT_PRESSED,
		LEFT_RELEASED,		
		RIGHT_PRESSED,
		RIGHT_RELEASED,
		MOVE,
		LEFT_PRESSEDMOVE,
		WHEEL_UP,
		WHEEL_DOWN
	};
	
	MouseHandler();
	~MouseHandler();
	
	void connect(EventType type, std::function<void(sf::Vector2i const&)> callback);
	void disconnect(EventType type);
	void disconnectAll();
	
	void listenEvents(sf::Event const& e, sf::RenderWindow const& window);
	
private:
	void callEvent(EventType type, sf::Vector2i const& mouse);
	
	std::map<EventType, std::function<void(sf::Vector2i const&)>> events;	
	
};

#endif

