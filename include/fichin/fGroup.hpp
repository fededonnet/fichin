#ifndef __FGROUP_HPP__
#define __FGROUP_HPP__
#include "fichin/fActor.hpp"
#include <vector>

class fGroup: public fActor{
public:
	virtual void update(float dt);
	virtual void draw(sf::RenderTarget &w, sf::RenderStates s) const;
	
	void add(fActor *actor);
	
private:
	std::vector<fActor *> _members;
};
#endif // __FGROUP_HPP__
