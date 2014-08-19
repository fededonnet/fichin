#ifndef __KEYBOARD_HPP__
#define __KEYBOARD_HPP__
#include <SFML/Window/Event.hpp>

class Keyboard{
public:
	static bool pressed(const sf::Keyboard::Key &key);
	static bool justPressed(const sf::Keyboard::Key &key);
	static bool released(const sf::Keyboard::Key &key);
	static bool justReleased(const sf::Keyboard::Key &key);

private:
	static int formerKeyStatus[4], currentKeyStatus[4];
	static void init();
	static void update();
	static void keyPressedHandler(const sf::Event &e);
	static void keyReleasedHandler(const sf::Event &e);

	friend class Game;
};

#endif // __KEYBOARD_HPP__
