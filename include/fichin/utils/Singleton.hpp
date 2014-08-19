#ifndef __SINGLETON_HPP__
#define __SINGLETON_HPP__

template <class T>
class Singleton {
private:
	static T* instance;	
	
protected:
	Singleton() {}
	
public:
	static T* getInstance() {
		if(!instance) {
			instance = new T();
		}
		return instance;
	}
	
	virtual ~Singleton() {}
};

template <class T> 
T* Singleton<T>::instance = nullptr;



#endif

