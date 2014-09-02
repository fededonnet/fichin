#include <fichin/input/fKeyboard.hpp>
#include <cstring>	//memcpy
using namespace std;

int fKeyboard::formerKeyStatus[4], fKeyboard::currentKeyStatus[4];

////////////////////////////////////////////////////////////

void fKeyboard::init(){
	for (int i = 0; i<4; i++){
		formerKeyStatus[i] = currentKeyStatus[i] = 0;	
	}
}

////////////////////////////////////////////////////////////

bool fKeyboard::pressed(const sf::Keyboard::Key &key){
	return sf::Keyboard::isKeyPressed(key);
}

////////////////////////////////////////////////////////////

bool fKeyboard::released(const sf::Keyboard::Key &key){
	return !pressed(key);
}

////////////////////////////////////////////////////////////

bool fKeyboard::justPressed(const sf::Keyboard::Key &key){
	unsigned bucket = key / (sizeof(int)*8);
	unsigned bit = key % (sizeof(int)*8);
	sf::Keyboard::isKeyPressed(key)?currentKeyStatus[bucket] |= 1<<bit : currentKeyStatus[bucket] &= (0xffffffff ^ (1<<bit));
	return (currentKeyStatus[bucket] & (1<<bit)) != 0 && (formerKeyStatus[bucket] & (1<<bit)) == 0;
}

////////////////////////////////////////////////////////////

bool fKeyboard::justReleased(const sf::Keyboard::Key &key){
	unsigned bucket = key / (sizeof(int)*8);
	unsigned bit = key % (sizeof(int)*8);
	sf::Keyboard::isKeyPressed(key)?currentKeyStatus[bucket] |= 1<<bit : currentKeyStatus[bucket] &= (0xffffffff ^ (1<<bit));
	return ((currentKeyStatus[bucket] & (1<<bit)) == 0) && ((formerKeyStatus[bucket] & (1<<bit)) != 0);
}

////////////////////////////////////////////////////////////

void fKeyboard::update() {
	memcpy(formerKeyStatus, currentKeyStatus, sizeof(int)*4);
}
