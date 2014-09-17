#include "fichin/fPhysicsWorld.hpp"
#include "fichin/fActor.hpp"
#include "fichin/fSprite.hpp"

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
