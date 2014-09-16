#ifndef __FICHINUTILS_HPP__
#define __FICHINUTILS_HPP__

#include <string>       // std::string
#include <sstream> 		// std::stringstream, std::stringbuf

using namespace std;

namespace utils {

template<class T>
inline std::string to_string(T i) {
	std::stringstream ss;
	std::string s;
	ss << i;
	s = ss.str();	
	return s;
}

//---*Retorna la magnitud del sf::Vector2<T>:
template<class T>
float length(sf::Vector2<T> const& vector2) {
	return sqrt(vector2.x * vector2.x + vector2.y * vector2.y);
}
//---*Retorna un sf::Vector2<T> normalizado:
template<class T>
sf::Vector2<T> normalize(sf::Vector2<T> const& vector2) {
	sf::Vector2<T> vector = vector2;
	float length = utils::length(vector2);
	
	if (length != 0){
		vector.x = vector2.x/length;
		vector.y = vector2.y/length;
	}	
	return vector;
}

};

#endif
