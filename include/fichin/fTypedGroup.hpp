#ifndef __FTYPEDGROUP_HPP__
#define __FTYPEDGROUP_HPP__
#include "fichin/fActor.hpp"
#include <vector>

template<class T>
class fTypedGroup: public fActor{
	T *recycle(){
		// busca el primer actor no vivo y lo devuelve
		for(int i = 0; i<_members.size(); i++){
			if(!_members[i].isAlive()){
				return &_members[i];
			}
		}
		// si no encontro un actor que pueda reciclarse, crea uno nuevo
		_members.emplace_back();
		return _members[_members.size()-1];
	}
	
	T *create(){
		_members.emplace_back();
		return _members[_members.size()-1];
	}
	
	
	virtual void update(float dt){
		for(int i = 0; i<_members.size(); i++){
			_members[i].update(dt);
		}
	}
	
	virtual draw(sf::RenderTarget &w, sf::RenderStates s) const{
		for(int i = 0; i<_members.size(); i++){
			_members[i].draw(w, s);
		}
	}
	
	virtual void update(float dt);
	virtual void draw(sf::RenderTarget &w, sf::RenderStates s) const;
	
private:
	std::vector<T> _members;
};

#endif // __TYPEDGROUP_HPP__
