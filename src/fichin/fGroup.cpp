#include <fichin/fGroup.hpp>

//////////////////////////////////////////////

void fGroup::update(float dt){
	for(std::vector<fActor *>::iterator i = _members.begin(); i<_members.end(); ++i){
		if((*i)->isAlive()) (*i)->update(dt);
	}
}

//////////////////////////////////////////////

void fGroup::draw(sf::RenderTarget &w, sf::RenderStates s) const{
	for(std::vector<fActor *>::const_iterator i = _members.begin(); i<_members.end(); ++i){
		if((*i)->isVisible()) (*i)->draw(w, s);
	}
}

//////////////////////////////////////////////

void fGroup::add(fActor *actor){
	_members.push_back(actor);
}
	
//////////////////////////////////////////////

fGroup::~fGroup(){
	for(std::vector<fActor *>::iterator i = _members.begin(); i<_members.end(); ++i){
		delete (*i);
	}
}


