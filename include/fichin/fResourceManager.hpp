#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H
#include <map>
#include <string>

template<typename T>
class fResourceManager{
public:
	static const T &get(const std::string &resource){
		return _resources.find(resource)->second;
	};
	
	static const T &add(const std::string &resource){
		T &r = (_resources[resource] = T());
		r.loadFromFile(resource);
		return r; 
	};
	
	/*
	template<typename... _Args>
	static const T &add(const std::string &resource, _Args... args){
		return *_resources.emplace(resource, args...).first;
	};
	*/
private:
	static std::map<std::string, T> _resources;
};

template<class T>
std::map<std::string, T>fResourceManager<T>::_resources;

#endif
