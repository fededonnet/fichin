#include "fichin/fGroup.hpp"


void fGroup::update(float dt){
	fActor *a;
	for(int i = 0; i<_members.size(); i++){
		a = _members[i];
		if(a->isAlive()) a->update(dt);
	}
}


void fGroup::draw(sf::RenderTarget &w, sf::RenderStates s) const{
	fActor *a;
	for(int i = 0; i<_members.size(); i++){
		a = _members[i];
		if(a->isVisible()) a->draw(w, s);
	}
}
	

void fGroup::add(fActor *actor){
	_members.push_back(actor);
}
	


