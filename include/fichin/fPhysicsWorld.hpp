#ifndef FPHYSICSWORLD_HPP
#define FPHYSICSWORLD_HPP
#include <vector>
#include <functional>
#include <SFML/Graphics/Rect.hpp>
#include <fichin/fTypedGroup.hpp>
#include <fichin/fSprite.hpp>
#include <fichin/components/fBoxCollider2D.hpp>

#include <type_traits> /// para el std::is_base_of!
class fActor;

class fPhysicsWorld {
public:	
		
	////////////////////////////////////////////////////////////
	/// \brief Chequea si la caja de colision del fSprite colisiona con un sf::Rect<int>:
	///
	/// \return Flag que indica si hay colision.
	////////////////////////////////////////////////////////////
	static bool spriteVSrect (fSprite* sprite, sf::Rect<int> const& rect);
		
	////////////////////////////////////////////////////////////
	/// \brief Chequea si el actor se encuentra  dentro de un sf::Rect<int>
	/// 		Si esto es asi, llama un callback asignado por el usuario.
	///
	////////////////////////////////////////////////////////////
	template<class A>
	inline static void overlapRect(A* a, sf::Rect<int> const& rect, std::function<void(A*)> callback) {
		//---*Si el tipo del objeto no es de una clase derivada de fSprite, no hay chequeos por hacer:
		if(!std::is_base_of<fSprite, A>::value) {
			return;
		}
		actorVSrect(static_cast<fActor*>(a), rect, callback);		 
	};
	
	
	////////////////////////////////////////////////////////////
	/// \brief  Sobrecarga de overlapRect. Chequea si el grupo se encuentra  dentro de un sf::Rect<int>
	/// 		Recorre sus elementos y realiza el chequeo uno por uno.
	/// 		Si esto es asi, llama un callback asignado por el usuario.
	///
	////////////////////////////////////////////////////////////
	template<class A>
	inline static void overlapRect(fTypedGroup<A>* a, sf::Rect<int> const& rect, std::function<void(A*)> callback) {
		//---*Si el tipo del grupo no es de una clase derivada de fSprite, no hay chequeos por hacer:
		if(!std::is_base_of<fSprite, A>::value) {
			return;
		}
		actorVSrect(static_cast<fActor*>(a), rect, callback);		 
	};	
	
	////////////////////////////////////////////////////////////
	/// \brief Setea el worldLimits
	/// \param sf::Rect<int>: Rect que va a representar los limites del mundo.
	////////////////////////////////////////////////////////////
	static void setWorldLimits(sf::Rect<int> const& rect);
	////////////////////////////////////////////////////////////
	/// \brief Setea los limites del worldLimits
	///
	/// \param x: Left del rect
	/// \param y: Top del rect
	/// \param w: Width del rect
	/// \param h: Height del rect
	////////////////////////////////////////////////////////////
	static void setWorldLimits(int x, int y, int w, int h);		
		
	////////////////////////////////////////////////////////////
	/// \brief Funcion auxiliar que chequea si ambos actores son el mismo.
	///			util cuando necesitamos chequear colisiones que implican grupos de actores.
	///
	/// \param fActor*: Puntero del primer fActor a chequear
	/// \param fActor*: Puntero del segundo fActor a chequear
	/// \return Flag que indica si son el mismo fActor.
	////////////////////////////////////////////////////////////
	static bool isSameActor(fActor*, fActor*);
	
	////////////////////////////////////////////////////////////
	/// \brief Chequea si un sprite se encuentra fuera de los limites del mundo
	///
	/// \param fSprite*: Puntero del sprite a chequear
	/// \param std::function<void(fActor*)>: function que retorna un puntero de fActor
	////////////////////////////////////////////////////////////
	static void spriteOutsideWorldLimits(fSprite* sprite, std::function<void(fActor*)> callback);
	
	////////////////////////////////////////////////////////////
	/// \brief Chequea si un actor se encuentra fuera de los limites del mundo
	///
	/// \param fActor*: Puntero del fActor a chequear
	/// \param std::function<void(fActor*)>: function que retorna un puntero de fActor
	////////////////////////////////////////////////////////////
	static void actorOutsideWorldLimits(fActor* actor, std::function<void(fActor*)> callback);
	
	////////////////////////////////////////////////////////////
	/// \brief Chequea si un fSprite colisiona con otro fSprite
	///
	/// \param fSprite*: Puntero del fSprite A
	/// \param fSprite*: Puntero del fSprite B
	/// \return Flag que indica si hay colision entre ambos fSprites
	////////////////////////////////////////////////////////////
	static bool spriteVSsprite(fSprite*,fSprite*);
	
	
	////////////////////////////////////////////////////////////
	/// \brief Funcion overlap. Chequea si 2 entidades colisionan
	///				Sirve para chequear si un actor colisiona con otro.
	/// \param fTypedGroup<A>* : fTypedGroup de tipo A
	/// \param fTypedGroup<B>* : fTypedGroup de tipo B
	/// \param std::function<void(A*,B*)>: function que retorna los punteros implicados
	/// 		en la colision. Son punteros especificados por el usuario.
	////////////////////////////////////////////////////////////
	template<class A, class B>
	inline static void overlap(A* a, B* b, std::function<void(A*, B*)> callback) {
		actorVSactor(static_cast<fActor*>(a),static_cast<fActor*>(b),callback);
	};
	
	////////////////////////////////////////////////////////////
	/// \brief Funcion overlap. Solo se llama si ambos actores son fTypedGroup<> 
	///				Sirve para chequear si un actor colisiona con otro.
	///				Si ambos actores son fTypedGroup, previamente hace estos chequeos.
	/// \param fTypedGroup<A>* : fTypedGroup de tipo A
	/// \param fTypedGroup<B>* : fTypedGroup de tipo B
	/// \param std::function<void(C*,D*)>: function que retorna los punteros implicados
	/// 		en la colision. Son punteros especificados por el usuario.
	///
	////////////////////////////////////////////////////////////
	template<class A, class B>
	inline static void overlap(fTypedGroup<A>* a, fTypedGroup<B>* b, std::function<void(A*, B*)> callback) {
		actorVSactor(static_cast<fActor*>(a),static_cast<fActor*>(b),callback);
	};
	
	////////////////////////////////////////////////////////////
	/// \brief Sobrecarga auxiliar de overlap. Solo se llama si el primer actor es un typedGroup:
	////////////////////////////////////////////////////////////
	template<class A, class B>
	inline static void overlap(fTypedGroup<A>* a, B* b, std::function<void(A*, B*)> callback) {
		actorVSactor(static_cast<fActor*>(a),static_cast<fActor*>(b),callback);		 
	};	
	
	////////////////////////////////////////////////////////////
	/// \brief Sobrecarga auxiliar de overlap. Solo se llama si el segundo actor es un typedGroup:
	////////////////////////////////////////////////////////////
	template<class A, class B>
	inline static void overlap(A* a,fTypedGroup<B>* b, std::function<void(A*, B*)> callback) {
		actorVSactor(static_cast<fActor*>(a),static_cast<fActor*>(b),callback);		 
	};	
	
private:
	static sf::Rect<int> _worldLimits;	
	
	////////////////////////////////////////////////////////////
	/// \brief Chequea si el actor se encuentra  dentro de un sf::Rect<int>
	/// 		Si el actor es un group o typedGroup, recorre sus elementos y realiza el chequeo uno por uno.
	/// 		Si esto es asi, llama un callback asignado por el usuario.
	///
	////////////////////////////////////////////////////////////
	template <class T>
	inline static void actorVSrect (fActor* actor, sf::Rect<int> const& rect, std::function<void(T*)> callback) {
		//---*Si el actor no esta vivo, no hay nada que chequear:
		if(!actor->isAlive()) {
			return;
		}		
		//---*Vemos de que tipo es el fActor:
		switch(actor->getCollidableObjectType()) {
		case fActor::CollidableObjectType::NONE:
			//---*Nada por hacer aca!
			break;
		case fActor::CollidableObjectType::SPRITE:
			{
				T* sprite = static_cast<T*>(actor);
				if(fPhysicsWorld::spriteVSrect(sprite, rect)) {
					callback(sprite);
				}
			}	
			break;
		case fActor::CollidableObjectType::GROUP:
			{			
				fTypedGroup<T>* group = static_cast<fTypedGroup<T>*>(actor);
				groupVSrect(group, rect, callback);						
			}	
			break;
		}	
	};
	
	////////////////////////////////////////////////////////////
	/// \brief Chequea si los elementos del typedGroup estan en colision con un sf::Rect<int>:
	/// 		
	/// \return T
	////////////////////////////////////////////////////////////
	template <class T>
	inline static void groupVSrect(fTypedGroup<T>* group, sf::Rect<int> const& rect, std::function<void(T*)> callback) {
		//---*Si el actor no esta vivo, no hay nada que chequear:
		if(!group->isAlive()) {
			return;
		}	
		std::vector<T*> members = group->getMembers();
		for(size_t n = 0; n<members.size(); n++) {
			if(members[n]->isAlive()) {	
				actorVSrect(members[n], rect, callback);
			}
		}	
		
	};
	
	////////////////////////////////////////////////////////////
	/// \brief Chequea si un actor colisiona con otro
	///			Esta funcion puede recibir cualquier tipo de clase derivada de fActor.
	/// \param A*: Actor A
	/// \param B*: Actor B
	/// \param std::function<void(A*,B*)>: function que retorna los punteros implicados
	/// 		en la colision. Son punteros especificados por el usuario.
	////////////////////////////////////////////////////////////
	template<class A, class B>
	inline static void actorVSactor(fActor* a, fActor* b, std::function<void(A*, B*)> callback) {
		//---*Si uno de los 2 actores no es derivado de fSprite no es necesario hacer ningun chequeo:
		if(!std::is_base_of<fSprite, A>::value || !std::is_base_of<fSprite, B>::value) {
			return;			
		}
		//---*Si alguno de los actores esta "muerto" no es necesario hacer ningun chequeo:
		if(!a->isAlive() || !b->isAlive()) {
			return;
		}
		
		switch(a->getCollidableObjectType()) {
		case fActor::CollidableObjectType::NONE:
			//---*Nothing to do here!
			break;
		case fActor::CollidableObjectType::SPRITE:
			{
				A* sa = static_cast<A*>(a);
				//---*Vemos el collisionType del fActor b:
				switch(b->getCollidableObjectType()) {
				case fActor::CollidableObjectType::NONE:
					//---*Nothing to do here!
					break;
				case fActor::CollidableObjectType::SPRITE:
				{
					//---*Sprite vs Sprite:						
					B* sb = static_cast<B*>(b);
					if(fPhysicsWorld::spriteVSsprite(sa,sb)) {
						callback(sa,sb);
					}
					break;
				}
				case fActor::CollidableObjectType::GROUP:
				{					
					//---*Sprite vs Group:
					fTypedGroup<B>* group = static_cast<fTypedGroup<B>*>(b);
					B* sb = spriteVSgroup(sa,group);
					if(sb != nullptr) {
						callback(sa,sb);
					}
					break;	
				}
					
				}			
				break;	
			}
		case fActor::CollidableObjectType::GROUP: 
			{				
				//---*El Actor a es un grupo de actores:
				fTypedGroup<A>* groupA =  static_cast<fTypedGroup<A>*>(a);
				std::vector<A*> members = groupA->getMembers();
				
				//---*Vemos el collisionType del fActor b:
				switch(b->getCollidableObjectType()) {
				case fActor::CollidableObjectType::NONE:
					//---*Nothing to do here!
					break;
				case fActor::CollidableObjectType::SPRITE:
				{
					//---*Group vs Sprite:
					B* unit = static_cast<B*>(b);
					A* groupMember = spriteVSgroup(unit,groupA);
					if(groupMember != nullptr) {
						callback(groupMember,unit);
					}			
					break;	
				}
				case fActor::CollidableObjectType::GROUP:
				{						
					fTypedGroup<B>* groupB =  static_cast<fTypedGroup<B>*>(b);
					//---*fGrup vs fGroup:
					std::pair<A*,B*> pair = groupVSgroup(groupA,groupB);
					if(pair.first != nullptr && pair.second != nullptr) {
						callback(pair.first, pair.second);
					}
					break;				
				}
				}				
				break;
			}
		}
		
	};
	
	
	////////////////////////////////////////////////////////////
	/// \brief Chequea si un elemento del grupo colisiona con otro elemento de un grupo.
	/// 		Si alguno de los grupos no posee actores que puedan colisionar, esta funcion no hace nada.
	///
	/// \param fSprite*: Puntero del fSprite A
	/// \param fTypedGroup<fSprite>*: Puntero del typedGroup
	/// \return Retorna el puntero al elemento si hay colision, de lo contrario retorna nullptr
	////////////////////////////////////////////////////////////
	template<class A, class B>
	inline static std::pair<A*,B*> groupVSgroup(fTypedGroup<A>* groupA, fTypedGroup<B>* groupB) {
		//---*Par de punteros que vamos a retornar:
		std::pair<A*,B*> pair = std::make_pair(nullptr, nullptr);
		//---*Si alguno de los actores esta "muerto" no es necesario hacer ningun chequeo y retornamos el pair con punteros nulos:
		if(!groupA->isAlive() || !groupB->isAlive()) {
			return pair;
		}		
		//---*Si alguno de los grupos no son de tipo "colisionables" retornamos el pair con punteros nulos:
		if(groupA->getCollidableObjectType() != fActor::CollidableObjectType::GROUP 
		|| groupB->getCollidableObjectType() != fActor::CollidableObjectType::GROUP) {
			return pair;
		}	
		//---*Obtenemos las referencias constantes de los miembos de ambos grupos para poder recorrerlos:
		std::vector<A*> membersA = groupA->getMembers();
		std::vector<B*> membersB = groupB->getMembers();
		for(size_t n = 0; n< membersA.size(); n++) {	
			if(membersA[n]->isAlive()) {
				for(size_t i = 0; i< membersB.size(); i++) {								
					if(!fPhysicsWorld::isSameActor(membersA[n],membersB[i]) && membersB[i]->isAlive()) {
						fBoxCollider2D* boxCollider2D = static_cast<fBoxCollider2D*>(membersA[n]);
						if(boxCollider2D->overlaps(membersB[i])) {
							pair.first = membersA[n];
							pair.second = membersB[i];							
						}
					}
				}
			}
		}		
		return pair;
	};	
	
	///////////////////////////////////////////////////////////
	/// \brief Chequea si un fSprite colisiona con el elemento de un grupo.
	/// 		Si el grupo no posee actores que puedan colisionar, esta funcion no hace nada.
	///
	/// \param fSprite*: Puntero del fSprite A
	/// \param fTypedGroup<fSprite>*: Puntero del typedGroup
	/// \return Retorna el puntero al elemento si hay colision, de lo contrario retorna nullptr
	////////////////////////////////////////////////////////////
	template<class T>
	inline static T* spriteVSgroup(fSprite* sprite, fTypedGroup<T>* group) {
		if(!sprite->isAlive() || !group->isAlive()) {
			return  nullptr;
		}		
		fBoxCollider2D* boxCollider2D = static_cast<fBoxCollider2D*>(sprite);
		std::vector<T*> members = group->getMembers();
		for(size_t n = 0; n< members.size(); n++) {
			if(!fPhysicsWorld::isSameActor(sprite,members[n]) && members[n]->isAlive()) {
				if(boxCollider2D->overlaps(members[n])) {
					return members[n];
				}
			}
		}	
		return nullptr;
	};
	
};



#endif

