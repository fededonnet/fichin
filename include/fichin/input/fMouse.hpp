#ifndef __FMOUSE_HPP__
#define __FMOUSE_HPP__
#include <SFML/Window/Mouse.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Window.hpp>

class fMouse{
public:
	static bool pressed(sf::Mouse::Button button = sf::Mouse::Left);
	static bool justPressed(sf::Mouse::Button button = sf::Mouse::Left);
	static bool justReleased(sf::Mouse::Button button = sf::Mouse::Left);
	static const sf::Vector2i &getPosition();
	static void setPosition(const sf::Vector2i &pos);
	static void setPosition(const sf::Vector2i& position, const sf::Window& relativeTo);
	static void show(bool show = true);
	static void hide();

	
	
private:
	
	static void init(sf::Window &w);
	static void update();
	
	struct fMouseStatus{
		sf::Vector2i pos;
		char buttonStatus;
	};
	
	static fMouseStatus _currentStatus, _formerStatus;
	static sf::Window *_window;
		
	friend class fGame;
};

#endif // __FMOUSE_HPP__
