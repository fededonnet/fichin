#ifndef __FACTOR_HPP__
#define __FACTOR_HPP__

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics/Drawable.hpp>

////////////////////////////////////////////////////////////
/// \brief 	Clase base de cualquier actor o elemento que
/// 		puede ser agregado a una escena del juego
///
////////////////////////////////////////////////////////////
class fActor: public sf::Drawable
{
public:
	enum class CollidableObjectType {
		NONE,
		SPRITE,
		GROUP
	};
	
	////////////////////////////////////////////////////////////
	/// \brief Constructor por defecto
	///
	/// Construye e inicializa un actor.
	///
	////////////////////////////////////////////////////////////
	fActor();
	
	////////////////////////////////////////////////////////////
	/// \brief Actualiza el actor
	///
	/// Es llamada automáticamente por la escena para actualizar
	/// al actor.
	///
	/// \param dt Tiempo transcurrido desde la última actualización
	///
	////////////////////////////////////////////////////////////
	virtual void update(float dt);
	
	////////////////////////////////////////////////////////////
	/// \brief Dibuja el actor
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
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const = 0;
	
	////////////////////////////////////////////////////////////
	/// \brief Permite conocer si el actor es visible
	///
	/// \return Valor de verdad indicando si el actor es visible
	///
	/// \see setVisible
	///
	////////////////////////////////////////////////////////////
	bool isVisible() const;
	
	////////////////////////////////////////////////////////////
	/// \brief Permite cambiar la visibilidad del actor
	///
	/// \brief visible	nuevo estado de visibilidad del actor
	///
	/// \see isVisible
	///
	////////////////////////////////////////////////////////////
	void setVisible(bool visible);
	
	////////////////////////////////////////////////////////////
	/// \brief Permite conocer si el actor está vivo y debe actualizarse
	///
	/// \return Valor de verdad indicando si el actor está vivo
	///
	/// \see kill, revive
	///
	////////////////////////////////////////////////////////////
	bool isAlive() const;
	
	////////////////////////////////////////////////////////////
	/// \brief Mata al actor
	///
	/// Indica a la escena que el actor murió, por lo cual ya
	/// no será actualizado ni dibujado.
	///
	/// La escena dispondrá si el actor muerto será eliminado
	/// de la memoria o reutilizado.
	///
	/// \see isAlive, revive
	///
	////////////////////////////////////////////////////////////
	void kill();
	
	////////////////////////////////////////////////////////////
	/// \brief Revive al actor
	///
	/// Reinicia el estado interno del actor. Resulta útil para
	/// poder reciclarlo o reutilizarlo.
	///
	/// \see isAlive, kill
	///
	////////////////////////////////////////////////////////////
	void revive();
	
	////////////////////////////////////////////////////////////
	/// \brief Retorna el tipo de colision del fActor
	///
	/// 	Se usa para verificar si el fActor puede colisionar con otro actor
	///		Si el type es NONE, el fActor no va a ser considerado para las colisiones.
	/// \see fBoxCollider2D, fPhysicsWorld
	///
	////////////////////////////////////////////////////////////
	CollidableObjectType const& getCollidableObjectType();
	
protected:	
	void setCollidableObjectType(CollidableObjectType type);
	
private:
	bool _alive;	///< si el actor éstá vivo (debe actualizarse)
	bool _visible;	///< si el actor es visible (debe dibujarse)
	CollidableObjectType _collidableType = CollidableObjectType::NONE; ///< tipo de colision que identifica al objeto fActor (NONE por defecto)
};


////////////////////////////////////////////////////////////
// Inline functions implementation
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
inline fActor::fActor(){_visible = _alive = true; }

////////////////////////////////////////////////////////////////////////////////
inline void fActor::update(float dt){}

////////////////////////////////////////////////////////////////////////////////
inline bool fActor::isAlive() const { return _alive;}

////////////////////////////////////////////////////////////////////////////////
inline bool fActor::isVisible() const { return _visible;}

////////////////////////////////////////////////////////////////////////////////
inline void fActor::kill() { _alive = false; _visible = false; }

////////////////////////////////////////////////////////////////////////////////
inline void fActor::setVisible(bool visible) { _visible = visible; }

////////////////////////////////////////////////////////////////////////////////
inline void fActor::revive() { _alive = _visible = true;  }

////////////////////////////////////////////////////////////////////////////////
inline void fActor::setCollidableObjectType(CollidableObjectType collidableType) { _collidableType = collidableType;};

////////////////////////////////////////////////////////////////////////////////
inline fActor::CollidableObjectType const& fActor::getCollidableObjectType() { return _collidableType;};

#endif // __FACTOR_HPP__


////////////////////////////////////////////////////////////
/// \class fActor
///
/// fActor es la clase base de cualquier actor o elemento que
/// puede ser agregado a una escena del juego.
///
/// Ésta clase no puede utilizarse directamente, ya que se
/// trata de una clase abstracta. En cambio, es posible
/// generar una clase heredada y definir los métodos
/// update() y draw() que serán invocados automáticamente
/// para actualizar y dibujar en escena al actor.
///
/// También pueden utilizarse algunas de las subclases
/// ya definidas, como fSprite.
///
/// \see fGroup, fTypedGroup, fSprite
///
////////////////////////////////////////////////////////////

