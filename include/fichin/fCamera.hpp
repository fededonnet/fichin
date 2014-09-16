#ifndef __FCAMERA_HPP__
#define __FCAMERA_HPP__

#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Transformable.hpp>

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////


class fCamera: public sf::View
{
public:
	////////////////////////////////////////////////////////////
	/// \brief 	Constructor
	////////////////////////////////////////////////////////////
	fCamera();
	
	////////////////////////////////////////////////////////////
	/// \brief 			Indica a la c�mara que debe actualizar autom�ticamente
	///					su posici�n de manera que una determinada entidad quede
	///					siempre en el centro de la misma
	///
	/// \param 	target	Entidad a la que la c�mara debe seguir
	///
	///	\see	setBounds
	///
	////////////////////////////////////////////////////////////
	void follow(const sf::Transformable *target);
	
	////////////////////////////////////////////////////////////
	/// \brief 			Limita el movimiento de la camara de manera
	///					que la porci�n visible nunca abandone un
	///					area rectangular dada
	///
	/// \param 	bounds	Area reactangular que indica los l�mites de movimiento de la c�mara
	///
	///	\see	follow
	///
	////////////////////////////////////////////////////////////
	void setBounds(const sf::FloatRect &bounds);
	
	////////////////////////////////////////////////////////////
	/// \brief 	Obtiene el los l�mites de movimiento de la c�mara
	///
	/// \return	Area reactangular que indica los l�mites de movimiento de la c�mara
	///
	///	\see	setBounds
	///
	////////////////////////////////////////////////////////////
	sf::FloatRect getBounds() const;
	
private:
	sf::FloatRect 				_bounds;		///< limites del movimiento de la c�mara
	bool 						_useBounds;		///< Si se debe o no usar el atributo _bounds para limitar el movimiento de la camara
	const sf::Transformable *	_target;		///< Objeto al cual la c�mara debe seguir
	
	void update(float dt);
	friend class fGame;
};

////////////////////////////////////////////////////////////
// Inline functions implementation
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
inline void fCamera::setBounds(const sf::FloatRect &bounds) { _bounds = bounds; _useBounds = true; }

////////////////////////////////////////////////////////////////////////////////
inline void fCamera::follow(const sf::Transformable *target){_target = target;}
#endif
