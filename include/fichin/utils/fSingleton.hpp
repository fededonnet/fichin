#ifndef __FSINGLETON_HPP__
#define __FSINGLETON_HPP__

template <class T>
class fSingleton {	
public:
	static T* getInstance() {
		if(!instance) {
			instance = new T();
		}
		return instance;
	}	
	virtual ~fSingleton() {}
	
private:
	static T* instance;	
	
protected:
	fSingleton() {}	
};

template <class T> 
T* fSingleton<T>::instance = nullptr;

#endif

