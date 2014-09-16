#include "fichin/fPhysicsWorld.hpp"
#include "fichin/fActor.hpp"
#include "fichin/fSprite.hpp"

////////////////////////////////////////////////////////////
sf::Rect<int> fPhysicsWorld::_worldLimits = sf::Rect<int>(0,0,0,0);
void fPhysicsWorld::setWorldLimits(sf::Rect<int> const& worldLimits) {
	_worldLimits = worldLimits;
}

////////////////////////////////////////////////////////////
void fPhysicsWorld::setWorldLimits(int x, int y, int w, int h) {
	_worldLimits.left = x;
	_worldLimits.top = y;
	_worldLimits.width = w;
	_worldLimits.height = h;
}

////////////////////////////////////////////////////////////
bool fPhysicsWorld::isSameActor(fActor* a, fActor* b) {
	if(a == b) {
		return true;
	}
	return false;
}

////////////////////////////////////////////////////////////
bool fPhysicsWorld::spriteVSsprite(fSprite* a,fSprite* b) {
	if(!a->isAlive() || !b->isAlive()) {
		return false;
	}
	fBoxCollider2D* ba = static_cast<fBoxCollider2D*> (a);
	fBoxCollider2D* bb = static_cast<fBoxCollider2D*> (b);
	
	if(ba->overlaps(bb)) {
		return true;
	}	
	return false;
}

////////////////////////////////////////////////////////////
bool fPhysicsWorld::spriteVSrect (fSprite* sprite, sf::Rect<int> const& rect) {
	fBoxCollider2D* boxCollider2D = static_cast<fBoxCollider2D*>(sprite);
	if(boxCollider2D->overlaps(rect)) {
		return true;
	}	
	return false;
}


////////////////////////////////////////////////////////////
void fPhysicsWorld::spriteOutsideWorldLimits(fSprite* sprite, std::function<void(fActor*)> callback) {
	//---*Si el sprite no esta vivo, no hay nada que chequear:
	if(!sprite->isAlive()) {
		return;
	}		
	fBoxCollider2D* boxCollider2D = static_cast<fBoxCollider2D*>(sprite);
	if(!boxCollider2D->overlaps(_worldLimits)) {
		callback(sprite);
	}
}

////////////////////////////////////////////////////////////
void fPhysicsWorld::actorOutsideWorldLimits (fActor* actor, std::function<void(fActor*)> callback) {
	//---*Si el actor no esta vivo, no hay nada que chequear:
	if(!actor->isAlive()) {
		return;
	}	
	
	switch(actor->getCollidableObjectType()) {
		case fActor::CollidableObjectType::NONE:
			//---*Nada por hacer aca!
			break;
		case fActor::CollidableObjectType::SPRITE:
			{
				fSprite* sprite = static_cast<fSprite*>(actor);
				spriteOutsideWorldLimits(sprite, callback);
			}	
			break;
		case fActor::CollidableObjectType::GROUP:
			{				
				//---*Si el type es GROP es porque T es derivada de fSprite.
				fTypedGroup<fSprite>* group = static_cast<fTypedGroup<fSprite>*>(actor);
				std::vector<fSprite*> members = group->getMembers();				
				for(size_t n =0; n<members.size(); n++) {
					spriteOutsideWorldLimits(members[n], callback);
				}				
				
			}	
			break;
	}	
}
