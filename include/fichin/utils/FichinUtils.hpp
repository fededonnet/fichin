#ifndef __FICHINUTILS_HPP__
#define __FICHINUTILS_HPP__

#include <string>       // std::string
#include <sstream> 		// std::stringstream, std::stringbuf

using namespace std;

namespace utils {

template<class T>
inline std::string to_string(T i)
{
	std::stringstream ss;
	std::string s;
	ss << i;
	s = ss.str();	
	return s;
}

}

#endif
