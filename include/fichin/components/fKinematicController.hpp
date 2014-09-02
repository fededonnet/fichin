#ifndef __FKINEMATICCONTROLLER_HPP__
#define __FKINEMATICCONTROLLER_HPP__

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics/Transformable.hpp>

////////////////////////////////////////////////////////////
/// \brief	Agrega movimiento (velocidad, aceleraci�n, velocidad
///			angular, etc.) a un objeto de tipo sf::Transformable.
///			Es utilizada por la clase fSprite
///
/// \see fSprite
///
////////////////////////////////////////////////////////////
class fKinematicController{
public:
	////////////////////////////////////////////////////////////
	/// \brief Construye el objeto a partir del sf::Transformable asociado
	///
	/// \param t Objeto de tipo sf::Transformable cuya posici�n se actualizar�
	///
	////////////////////////////////////////////////////////////
	fKinematicController(sf::Transformable &t);

	////////////////////////////////////////////////////////////
	/// \brief Cambia la velocidad del objeto
	///
	/// \param newVel Nueva velocidad del objeto
	///
	////////////////////////////////////////////////////////////
	void setVelocity(sf::Vector2f newVel);
	
	////////////////////////////////////////////////////////////
	/// \brief Cambia la velocidad del objeto
	///
	/// \param velx Nueva velocidad en X del objeto
	/// \param vely Nueva velocidad en Y del objeto
	///
	////////////////////////////////////////////////////////////
	void setVelocity(float velx, float vely);
	
	////////////////////////////////////////////////////////////
	/// \brief Cambia la velocidad en X del objeto
	///
	/// \param velx Nueva velocidad en X del objeto
	///
	////////////////////////////////////////////////////////////
	void setVelocityX(float velx);
	
	////////////////////////////////////////////////////////////
	/// \brief Cambia la velocidad en Y del objeto
	///
	/// \param vely Nueva velocidad en Y del objeto
	///
	////////////////////////////////////////////////////////////
	void setVelocityY(float vely);
	
	////////////////////////////////////////////////////////////
	/// \brief Cambia la aceleraci�n del objeto
	///
	/// \param newAcc Nueva aceleraci�n del objeto
	///
	////////////////////////////////////////////////////////////
	void setAcceleration(sf::Vector2f newAcc);
	
	////////////////////////////////////////////////////////////
	/// \brief Cambia la aceleraci�n del objeto
	///
	/// \param accx Nueva aceleraci�n en X del objeto
	/// \param accy Nueva aceleraci�n en Y del objeto
	///
	////////////////////////////////////////////////////////////
	void setAcceleration(float accx, float accy);
	
	////////////////////////////////////////////////////////////
	/// \brief Cambia la aceleraci�n en X del objeto
	///
	/// \param accx Nueva aceleraci�n en X del objeto
	///
	////////////////////////////////////////////////////////////
	void setAccelerationX(float accx);
	
	////////////////////////////////////////////////////////////
	/// \brief Cambia la aceleraci�n en Y del objeto
	///
	/// \param accy Nueva aceleraci�n en Y del objeto
	///
	////////////////////////////////////////////////////////////
	void setAccelerationY(float accy);
	
	////////////////////////////////////////////////////////////
	/// \brief 	Cambia el drag del objeto. �ste valor consiste en
	/// 		una desaceleraci�n que es aplicada �nicamente cuando
	///			la aceleraci�n es 0
	///
	/// \param newDrag Nuevo valor de drag para el objeto
	///
	////////////////////////////////////////////////////////////
	void setDrag(sf::Vector2f newDrag);
	
	////////////////////////////////////////////////////////////
	/// \brief 	Cambia el drag del objeto. �ste valor consiste en
	/// 		una desaceleraci�n que es aplicada �nicamente cuando
	///			la aceleraci�n es 0
	///
	/// \param dragx Nuevo valor de drag en X para el objeto
	/// \param dragy Nuevo valor de drag en Y para el objeto
	///
	////////////////////////////////////////////////////////////
	void setDrag(float dragx, float dragy);
	
	////////////////////////////////////////////////////////////
	/// \brief 	Cambia el drag en X del objeto. �ste valor consiste en
	/// 		una desaceleraci�n que es aplicada �nicamente cuando
	///			la aceleraci�n es 0
	///
	/// \param dragx Nuevo valor de drag en X para el objeto
	///
	////////////////////////////////////////////////////////////
	void setDragX(float dragx);
	
	////////////////////////////////////////////////////////////
	/// \brief 	Cambia el drag en Y del objeto. �ste valor consiste en
	/// 		una desaceleraci�n que es aplicada �nicamente cuando
	///			la aceleraci�n es 0
	///
	/// \param dragy Nuevo valor de drag en Y para el objeto
	///
	////////////////////////////////////////////////////////////
	void setDragY(float dragy);

	////////////////////////////////////////////////////////////
	/// \brief 	Cambia la velocidad m�xima del objeto. Si la velocidad
	/// 		del mismo supera este valor ser� recortada autom�ticamente.
	///
	/// \param newMaxVel Nuevo valor para la velocidad m�xima del objeto
	///
	////////////////////////////////////////////////////////////
	void setMaxVelocity(sf::Vector2f newMaxVel);
	
	////////////////////////////////////////////////////////////
	/// \brief 	Cambia la velocidad m�xima del objeto. Si la velocidad
	/// 		del mismo supera este valor ser� recortada autom�ticamente.
	///
	/// \param maxvelx Nuevo valor para la velocidad m�xima en X del objeto
	/// \param maxvely Nuevo valor para la velocidad m�xima en Y del objeto
	///
	////////////////////////////////////////////////////////////
	void setMaxVelocity(float maxvelx, float maxvely);
	
	////////////////////////////////////////////////////////////
	/// \brief 	Cambia la velocidad m�xima en X del objeto. Si la velocidad
	/// 		del mismo supera este valor ser� recortada autom�ticamente.
	///
	/// \param maxvelx Nuevo valor para la velocidad m�xima en X del objeto
	///
	////////////////////////////////////////////////////////////
	void setMaxVelocityX(float maxvelx);
	
	////////////////////////////////////////////////////////////
	/// \brief 	Cambia la velocidad m�xima en Y del objeto. Si la velocidad
	/// 		del mismo supera este valor ser� recortada autom�ticamente.
	///
	/// \param maxvely Nuevo valor para la velocidad m�xima en Y del objeto
	///
	////////////////////////////////////////////////////////////
	void setMaxVelocityY(float maxvely);

	////////////////////////////////////////////////////////////
	/// \brief 	Cambia la velocidad angular o de rotaci�n del objeto.
	///
	/// \param angularVel Nuevo valor para la velocidad angular del objeto
	///
	////////////////////////////////////////////////////////////
	void setAngularVelocity(float angularVel);
	
	////////////////////////////////////////////////////////////
	/// \brief 	Cambia la aceleraci�n angular del objeto.
	///
	/// \param angularAcc Nuevo valor para la aceleraci�n angular del objeto
	///
	////////////////////////////////////////////////////////////
	void setAngularAcceleration(float angularAcc);
	
	////////////////////////////////////////////////////////////
	/// \brief 	Cambia el drag angular del objeto. �ste valor
	/// consiste en una desaceleraci�n que es aplicada �nicamente
	/// cuando la aceleraci�n angular es 0
	///
	/// \param angularDrag Nuevo valor para el drag angular del objeto
	///
	////////////////////////////////////////////////////////////
	void setAngularDrag(float angularDrag);
	
	////////////////////////////////////////////////////////////
	/// \brief 	Cambia la velocidad angular m�xima del objeto.
	///			Si la velocidad angular del mismo supera este
	///			valor ser� recortada autom�ticamente.
	///
	/// \param maxAngular Nuevo valor para la velocidad angular m�xima del objeto
	///
	////////////////////////////////////////////////////////////
	void setMaxAngularVelocity(float maxAngular);

	////////////////////////////////////////////////////////////
	/// \brief 	Obtiene la velocidad del objeto
	///
	/// \return Velocidad del objeto
	///
	////////////////////////////////////////////////////////////
	const sf::Vector2f &getVelocity() const;
	
	////////////////////////////////////////////////////////////
	/// \brief 	Obtiene la acceleraci�n del objeto
	///
	/// \return	Aceleraci�n del objeto 
	///
	////////////////////////////////////////////////////////////
	const sf::Vector2f &getAcceleration() const;
	
	////////////////////////////////////////////////////////////
	/// \brief 	Obtiene el drag del objeto. �ste valor
	/// consiste en una desaceleraci�n que es aplicada �nicamente
	/// cuando la aceleraci�n es 0
	///
	/// \return Valor del drag del objeto
	///
	////////////////////////////////////////////////////////////
	const sf::Vector2f &getDrag() const;
	
	////////////////////////////////////////////////////////////
	/// \brief 	Obtiene la velocidad m�xima del objeto. Si la
	///			velocidad del mismo supera este valor ser�
	///			recortada autom�ticamente.
	///
	/// \return Velocidad m�xima del objeto
	///
	////////////////////////////////////////////////////////////
	const sf::Vector2f &getMaxVelocity() const;
	
	////////////////////////////////////////////////////////////
	/// \brief 	Obtiene la velocidad angular o de rotaci�n del objeto
	///
	/// \return Velocidad angular del objeto
	///
	////////////////////////////////////////////////////////////
	float getAngularVelocity() const;
	
	////////////////////////////////////////////////////////////
	/// \brief 	Obtiene la velocidad angular m�xima del objeto.
	///			Si la velocidad angular del mismo supera este
	///			valor ser� recortada autom�ticamente.
	///
	/// \return Velocidad angular m�xima del objeto
	///
	////////////////////////////////////////////////////////////
	float getMaxAngularVelocity() const;
	
	////////////////////////////////////////////////////////////
	/// \brief 	Actualiza la velocidad y posici�n del objeto
	///
	/// \param dt Tiempo transcurrido desde la �ltima actualizaci�n
	///
	////////////////////////////////////////////////////////////
	void updateKinematics(float dt);
	
private:
	sf::Transformable *_transform;	///< El objeto transformable cuya posici�n se actualizar�
	sf::Vector2f _velocity;			///< Velocidad del objeto
	sf::Vector2f _maxVelocity;		///< M�xima velocidad del objeto
	sf::Vector2f _acceleration;		///< Aceleraci�n del objeto
	sf::Vector2f _drag;				///< Drag del objeto
	float _angularVelocity;			///< Velocidad angular del objeto
	float _angularAcceleration;		///< Aceleraci�n angular del objeto
	float _maxAngularVelocity;		///< M�xima velocidad angular del objeto
	float _angularDrag;				///< Drag angular del objeto

	////////////////////////////////////////////////////////////
	/// \brief 	Funci�n de ayuda para calcular la velocidad en una dimensi�n.
	///
	/// \param velocity 	Velocidad actual
	/// \param aceleration 	Aceleraci�n
	/// \param drag			Valor de drag
	/// \param maxVelocity	Velocidad m�xima
	/// \param dt			Tiempo transcurrido desde la �ltima actualizaci�n
	///
	/// \return Velocidad resultante
	///
	////////////////////////////////////////////////////////////
	float computeVelocity(float velocity, float acceleration, float drag, float maxVelocity, float dt);
	
	////////////////////////////////////////////////////////////
	/// \brief 	Funci�n de ayuda para actualizar las velocidades
	///			linear y angular del objeto
	///
	/// \param dt Tiempo transcurrido desde la �ltima actualizaci�n
	///
	////////////////////////////////////////////////////////////
	void updateVelocities(float dt);
};


////////////////////////////////////////////////////////////
// Inline functions implementation
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
inline void fKinematicController::setVelocity(sf::Vector2f newVel) { _velocity = newVel; };

////////////////////////////////////////////////////////////////////////////////
inline void fKinematicController::setVelocity(float velx, float vely) { _velocity.x = velx; _velocity.y = vely; };

////////////////////////////////////////////////////////////////////////////////
inline void fKinematicController::setVelocityX(float velx) { _velocity.x = velx; };

////////////////////////////////////////////////////////////////////////////////
inline void fKinematicController::setVelocityY(float vely) { _velocity.y = vely; };

////////////////////////////////////////////////////////////////////////////////
inline void fKinematicController::setAcceleration(sf::Vector2f newAcc) { _acceleration = newAcc; };

////////////////////////////////////////////////////////////////////////////////
inline void fKinematicController::setAcceleration(float accx, float accy) { _acceleration.x = accx; _acceleration.y = accy; };

////////////////////////////////////////////////////////////////////////////////
inline void fKinematicController::setAccelerationX(float accx) { _acceleration.x = accx; };

////////////////////////////////////////////////////////////////////////////////
inline void fKinematicController::setAccelerationY(float accy) { _acceleration.y = accy; };

////////////////////////////////////////////////////////////////////////////////
inline void fKinematicController::setDrag(sf::Vector2f newDrag) { _drag = newDrag; };

////////////////////////////////////////////////////////////////////////////////
inline void fKinematicController::setDrag(float dragx, float dragy) { _drag.x = dragx; _drag.y = dragy; };

////////////////////////////////////////////////////////////////////////////////
inline void fKinematicController::setDragX(float dragx) { _drag.x = dragx; };

////////////////////////////////////////////////////////////////////////////////
inline void fKinematicController::setDragY(float dragy) { _drag.y = dragy; };

////////////////////////////////////////////////////////////////////////////////
inline void fKinematicController::setMaxVelocity(sf::Vector2f newMaxVel) { _velocity = newMaxVel; };

////////////////////////////////////////////////////////////////////////////////
inline void fKinematicController::setMaxVelocity(float maxvelx, float maxvely) { _maxVelocity.x = maxvelx; _maxVelocity.y = maxvely; };

////////////////////////////////////////////////////////////////////////////////
inline void fKinematicController::setMaxVelocityX(float maxvelx) { _maxVelocity.x = maxvelx; };

////////////////////////////////////////////////////////////////////////////////
inline void fKinematicController::setMaxVelocityY(float maxvely) { _maxVelocity.y = maxvely; };

////////////////////////////////////////////////////////////////////////////////
inline void fKinematicController::setAngularVelocity(float angularVel) { _angularVelocity = angularVel; };

////////////////////////////////////////////////////////////////////////////////
inline void fKinematicController::setAngularAcceleration(float angularAcc) { _angularAcceleration = angularAcc; };

////////////////////////////////////////////////////////////////////////////////
inline void fKinematicController::setAngularDrag(float angularDrag) { _angularDrag = angularDrag; };

////////////////////////////////////////////////////////////////////////////////
inline void fKinematicController::setMaxAngularVelocity(float maxAngular) {_maxAngularVelocity = maxAngular; };

////////////////////////////////////////////////////////////////////////////////
inline const sf::Vector2f &fKinematicController::getVelocity() const { return _velocity; };

////////////////////////////////////////////////////////////////////////////////
inline const sf::Vector2f &fKinematicController::getAcceleration() const { return _acceleration; };

////////////////////////////////////////////////////////////////////////////////
inline const sf::Vector2f &fKinematicController::getDrag() const { return _drag; };

////////////////////////////////////////////////////////////////////////////////
inline const sf::Vector2f &fKinematicController::getMaxVelocity() const { return _maxVelocity; };

////////////////////////////////////////////////////////////////////////////////
inline float fKinematicController::getAngularVelocity() const { return _angularVelocity; };

////////////////////////////////////////////////////////////////////////////////
inline float fKinematicController::getMaxAngularVelocity() const { return _maxAngularVelocity; };

#endif // __FKINEMATICCONTROLLER_HPP__

