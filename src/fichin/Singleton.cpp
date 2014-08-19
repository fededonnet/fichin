#include "Singleton.h"

template class <T>
T* Singleton::instance = nullptr;
T* Singleton::getInstance() {
	if(!instance) {
		instance = new T();
	}
	return instance;
}



