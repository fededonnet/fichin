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
	/// \brief 			Indica a la cámara que debe actualizar automáticamente
	///					su posición de manera que una determinada entidad quede
	///					siempre en el centro de la misma
	///
	/// \param 	target	Entidad a la que la cámara debe seguir
	///
	///	\see	setBounds
	///
	////////////////////////////////////////////////////////////
	void follow(const sf::Transformable *target);
	
	////////////////////////////////////////////////////////////
	/// \brief 			Limita el movimiento de la camara de manera
	///					que la porción visible nunca abandone un
	///					area rectangular dada
	///
	/// \param 	bounds	Area reactangular que indica los límites de movimiento de la cámara
	///
	///	\see	follow
	///
	////////////////////////////////////////////////////////////
	void setBounds(const sf::FloatRect &bounds);
	
	////////////////////////////////////////////////////////////
	/// \brief 	Obtiene el los límites de movimiento de la cámara
	///
	/// \return	Area reactangular que indica los límites de movimiento de la cámara
	///
	///	\see	setBounds
	///
	////////////////////////////////////////////////////////////
	sf::FloatRect getBounds() const;
	
private:
	sf::FloatRect 				_bounds;		///< limites del movimiento de la cámara
	bool 						_useBounds;		///< Si se debe o no usar el atributo _bounds para limitar el movimiento de la camara
	const sf::Transformable *	_target;		///< Objeto al cual la cámara debe seguir
	
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
