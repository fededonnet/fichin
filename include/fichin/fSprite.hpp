#ifndef __FSPRITE_HPP__
#define __FSPRITE_HPP__

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <fichin/fActor.hpp>
#include <fichin/components/fSpriteRenderer.hpp>
#include <fichin/components/fKinematicController.hpp>
#include <fichin/components/fAnimationController.hpp>

/////////////////////////////////////////////////
/// \brief Un actor con métodos para dibujarse, moverse y desplegar animaciones
/////////////////////////////////////////////////
class fSprite: public fActor, public sf::Transformable, public fSpriteRenderer, public fKinematicController, public fAnimationController{
public:
	
	////////////////////////////////////////////////////////////
	/// \brief Constructor por defecto
	///
	/// Construye e inicializa al sprite
	///
	////////////////////////////////////////////////////////////
	fSprite();
	
	////////////////////////////////////////////////////////////
	/// \brief Actualiza el actor
	///
	/// Es llamada automáticamente por la escena para actualizar
	/// al actor.
	///
	/// \param dt Tiempo transcurrido desde la última actualización
	///
	////////////////////////////////////////////////////////////
	void update(float dt);
	
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
	void draw(sf::RenderTarget &w, sf::RenderStates s) const;
};

#endif // __FSPRITE_HPP__

////////////////////////////////////////////////////////////
/// \class fSprite
///
/// Es un actor con funcionalidades para dibujarse en pantalla,
/// moverse y desplegar animaciones entre otras.
/// 
/// Hereda y toma las funcionalidades de las siguientes clases:
/// sf::Transformable
/// fSpriteRenderer
/// fKinematicController
/// fAnimationController
///
/// Ésta clase será generalmente la elección para crear un elemento
/// del juego.
///
/// Ejemplo de uso:
/// \code
///
/// class MyScene: public fScene
/// {
/// public:
/// 	void init()
/// 	{
/// 		// crea un sprite
/// 		fSprite *a = new fSprite();
///			// modifica su posición
///			a->setPosition(100, 100);
///			// modifica su velocidad
///			a->setVelocity(50, 20);
///			// asigna una textura al sprite
///			a->setTexture("assets/img/miImagen.png");
///			// agrega el sprite a la escena
/// 		add(a);
/// 	}
/// };
///
/// \endcode
///
////////////////////////////////////////////////////////////
