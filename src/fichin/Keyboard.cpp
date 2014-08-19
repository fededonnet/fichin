#include "fichin/input/Keyboard.hpp"
#include <cstring>
using namespace std;

int Keyboard::formerKeyStatus[4], Keyboard::currentKeyStatus[4];



void Keyboard::init(){
	for (int i = 0; i<4; i++){
		formerKeyStatus[i] = currentKeyStatus[i] = 0;	
	}
}

bool Keyboard::pressed(const sf::Keyboard::Key &key){
	return sf::Keyboard::isKeyPressed(key);
}

bool Keyboard::released(const sf::Keyboard::Key &key){
	return !pressed(key);
}

bool Keyboard::justPressed(const sf::Keyboard::Key &key){
	unsigned bucket = key / (sizeof(int)*8);
	unsigned bit = key % (sizeof(int)*8);
	sf::Keyboard::isKeyPressed(key)?currentKeyStatus[bucket] |= 1<<bit : currentKeyStatus[bucket] &= (0xffffffff ^ (1<<bit));
	return (currentKeyStatus[bucket] & (1<<bit)) != 0 && (formerKeyStatus[bucket] & (1<<bit)) == 0;
}

bool Keyboard::justReleased(const sf::Keyboard::Key &key){
	unsigned bucket = key / (sizeof(int)*8);
	unsigned bit = key % (sizeof(int)*8);
	sf::Keyboard::isKeyPressed(key)?currentKeyStatus[bucket] |= 1<<bit : currentKeyStatus[bucket] &= (0xffffffff ^ (1<<bit));
	return ((currentKeyStatus[bucket] & (1<<bit)) == 0) && ((formerKeyStatus[bucket] & (1<<bit)) != 0);
}

void Keyboard::update() {
	memcpy(formerKeyStatus, currentKeyStatus, sizeof(int)*4);
}
