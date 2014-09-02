#ifndef __FTYPEDGROUP_HPP__
#define __FTYPEDGROUP_HPP__
#include "fichin/fActor.hpp"
#include <vector>

template<class T>
class fTypedGroup: public fActor{
	T *add();
	T *recycle();
	virtual void update(float dt);
	virtual void draw(sf::RenderTarget &w, sf::RenderStates s) const;
	
private:
	std::vector<T> _members;	///< Los miembros del grupo
};


////////////////////////////////////////////////////////////
// Inline functions implementation
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
template <class T>
inline void fTypedGroup<T>::update(float dt){
	for(int i = 0; i<_members.size(); i++){
		_members[i].update(dt);
	}
}

////////////////////////////////////////////////////////////////////////////////
template <class T>
inline void fTypedGroup<T>::draw(sf::RenderTarget &w, sf::RenderStates s) const{
	for(int i = 0; i<_members.size(); i++){
		_members[i].draw(w, s);
	}
}

////////////////////////////////////////////////////////////////////////////////
template <class T>
inline T *fTypedGroup<T>::add(){
	_members.emplace_back();
	return _members[_members.size()-1];
}

////////////////////////////////////////////////////////////////////////////////
template <class T>
inline T *fTypedGroup<T>::recycle(){
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

#endif // __TYPEDGROUP_HPP__
