#ifndef __FTYPEDGROUP_HPP__
#define __FTYPEDGROUP_HPP__
#include <fichin/fActor.hpp>
#include <fichin/fSprite.hpp>
#include <vector>
#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////
/// \brief 	Un actor especial que puede contener a otros
///			actores del mismo tipo. Una vez que un actor es
///			agregado al grupo, el mismo se encargará de actualizalo,
///			dibujarlo y destruirlo cuando llegue el momento.
///			Un grupo puede ser agregado a una escena (o a otro
///			grupo) como si se tratase de un actor más
/// 		
/// \see fActor, fScene
///
////////////////////////////////////////////////////////////
template<class T>
class fTypedGroup: public fActor
{
public:
	////////////////////////////////////////////////////////////
	/// \brief Constructor del grupo de T
	///
	/// Construye e inicializa un fTypedGroup.
	///
	////////////////////////////////////////////////////////////
	fTypedGroup() {
		fActor::CollidableObjectType type = fActor::CollidableObjectType::GROUP;
		//---*Si el T es una clase que no deriva de fSprite, el tipo de colision del grupo es NONE
		if(!std::is_base_of<fSprite, T>::value) {
			type = fActor::CollidableObjectType::NONE;			
		}	
		setCollidableObjectType(type);		
	}
	
	
	////////////////////////////////////////////////////////////
	/// \brief Destructor. Libera los elementos contenidos en el grupo
	///
	////////////////////////////////////////////////////////////
	virtual ~fTypedGroup();
	
	////////////////////////////////////////////////////////////
	/// \brief 			Agrega un nuevo actor al grupo
	///
	/// \param newActor Actor que será agregado al grupo
	///
	////////////////////////////////////////////////////////////
	void add(T *newActor);
		
	////////////////////////////////////////////////////////////
	/// \brief 	Devuelve la cantidad de actores vivos que hay en el grupo
	///
	////////////////////////////////////////////////////////////
	unsigned countAlive() const;
	
	////////////////////////////////////////////////////////////
	/// \brief 	Devuelve la cantidad de actores muertos que hay en el grupo
	///
	////////////////////////////////////////////////////////////
	unsigned countDead() const;
	
	////////////////////////////////////////////////////////////
	/// \brief 	Devuelve la cantidad total de actores (vivos y muertos) que hay en el grupo
	///
	////////////////////////////////////////////////////////////
	unsigned size() const;
	
	////////////////////////////////////////////////////////////
	/// \brief 	Recorre el grupo y devuelve el primer actor vivo que encuentre
	///
	////////////////////////////////////////////////////////////
	T *getFirstAlive();
	
	////////////////////////////////////////////////////////////
	/// \brief 	Recorre el grupo y devuelve el primer actor muerto que encuentre.
	///			Resulta útil para reutilizar actores
	///
	////////////////////////////////////////////////////////////
	T *getFirstDead();
	
	////////////////////////////////////////////////////////////
	/// \brief 	Recorre el grupo y devuelve el primer actor muerto que encuentre.
	///			Si no encuentra ningún elemento que cumpla con éstas características,
	///			crea uno nuevo y lo agrega al grupo
	///
	///	\return	Un actor muerto que puede reutilizarse
	///
	////////////////////////////////////////////////////////////
	T *recycle();
	
	////////////////////////////////////////////////////////////
	/// \brief 	Permite acceder al i-ésimo elemento del grupo
	///
	////////////////////////////////////////////////////////////
	T *operator[](int i);
	
	////////////////////////////////////////////////////////////
	/// \brief 	Actualiza todos los miembros contenidos en el grupo
	///
	///	\param	Tiempo (en segundos) transcurrido desde la última actualización
	///
	////////////////////////////////////////////////////////////
	virtual void update(float dt);
	
	////////////////////////////////////////////////////////////
	/// \brief Dibuja todos los miembros contenidos en el grupo
	///
	/// Dibuja al actor en la ventana target con los estados states.
	/// Es llamada automáticamente por la escena. 
	///
	/// \param target La ventana en donde se debe dibujar al actor
	/// \param states Estados para el dibujado del actor en la ventana
	///
	/// \see sf::RenderTarget, sf::RenderStates
	///
	////////////////////////////////////////////////////////////
	virtual void draw(sf::RenderTarget &w, sf::RenderStates s) const;
			
	////////////////////////////////////////////////////////////
	/// \brief Retorna la referencia constante del vector de miembros de este grupo
	///
	////////////////////////////////////////////////////////////
	std::vector<T*> const& getMembers();	
	
private:
	
	std::vector<T *> _members;	///< Los miembros del grupo
};


////////////////////////////////////////////////////////////
// Inline functions implementation
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
template <class T>
inline void fTypedGroup<T>::update(float dt)
{
	for(size_t i = 0; i<_members.size(); i++)
	{
		if(_members[i]->isAlive())
			_members[i]->update(dt);
	}
}

////////////////////////////////////////////////////////////////////////////////
template <class T>
inline void fTypedGroup<T>::draw(sf::RenderTarget &w, sf::RenderStates s) const
{
	for(size_t i = 0; i<_members.size(); i++)
	{
		if(_members[i]->isVisible())
			_members[i]->draw(w, s);
	}
}

////////////////////////////////////////////////////////////////////////////////
template <class T>
inline void fTypedGroup<T>::add(T *newActor)
{
	_members.push_back(newActor);
}

////////////////////////////////////////////////////////////////////////////////
template <class T>
inline unsigned fTypedGroup<T>::countAlive() const
{
	unsigned alive = 0;
	for(size_t i = 0; i<_members.size(); i++)
	{
		if(_members[i]->isAlive())
		{
			++alive;
		}
	}
	return alive;
}

////////////////////////////////////////////////////////////////////////////////
template <class T>
inline unsigned fTypedGroup<T>::countDead() const
	{
		unsigned dead = 0;
		for(size_t i = 0; i<_members.size(); i++)
		{
			if(!_members[i]->isAlive())
			{
				++dead;
			}
		}
		return dead;
	}

////////////////////////////////////////////////////////////////////////////////
template <class T>
inline T *fTypedGroup<T>::getFirstAlive()
{
	// busca el primer actor vivo y lo devuelve
	for(size_t i = 0; i<_members.size(); i++)
	{
		if(_members[i]->isAlive())
		{
			return _members[i];
		}
	}
	// si no encontro un actor que pueda reciclarse, crea uno nuevo
	return nullptr;
}

////////////////////////////////////////////////////////////////////////////////
template <class T>
inline T *fTypedGroup<T>::getFirstDead()
{
	// busca el primer actor no vivo y lo devuelve
	for(size_t i = 0; i<_members.size(); i++)
	{
		if(!_members[i]->isAlive())
		{
			return _members[i];
		}
	}
	return nullptr;
}

////////////////////////////////////////////////////////////////////////////////
template <class T>
inline T *fTypedGroup<T>::recycle()
{
	T *newActor = getFirstDead();
	if(newActor == nullptr)
	{
		newActor = new T;
		add(newActor);
	}
	return newActor;
}

////////////////////////////////////////////////////////////////////////////////
template <class T>
inline unsigned fTypedGroup<T>::size() const
{
	return _members.size();
}

////////////////////////////////////////////////////////////////////////////////
template <class T>
inline fTypedGroup<T>::~fTypedGroup()
{	
	for(size_t i = 0; i<_members.size(); i++) {		
		delete _members[i];		
	}
	_members.clear();
}

////////////////////////////////////////////////////////////////////////////////
template <class T>
T *fTypedGroup<T>::operator[](int i)
{
	return _members[i];
}

////////////////////////////////////////////////////////////////////////////////
template <class T>
inline std::vector<T*> const& fTypedGroup<T>::getMembers() {
	return _members;
}

#endif // __TYPEDGROUP_HPP__
