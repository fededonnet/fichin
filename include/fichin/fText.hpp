#ifndef __FTEXT_HPP__
#define __FTEXT_HPP__

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <fichin/fActor.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

////////////////////////////////////////////////////////////
/// \brief 	Un actor que sirve para dibujar texto en pantalla.
/// 		Hereda todas las funcionalidades de sf::Text y agrega algunas más.
///
////////////////////////////////////////////////////////////
class fText : public fActor, public sf::Text {
public:
	////////////////////////////////////////////////////////////
	/// \brief Constructor por defecto
	///
	/// Construye e inicializa un actor.
	///
	////////////////////////////////////////////////////////////
	fText();
	
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
	void setFont(const std::string &fontFile);

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

	////////////////////////////////////////////////////////////
	/// \brief Asigna una cadena de texto al actor
	///
	/// Es util para asignar cadenas que incorporan valores
	/// numéricos de manera sencilla. Funciona de manera similar
	/// a la función con el mismo nombre de la biblioteca <cstddio>
	/// (ver http://www.cplusplus.com/reference/cstdio/printf/)
	///
	////////////////////////////////////////////////////////////
	void printf(const char *fmt, ...);
};

#endif // __FTEXT_HPP__

