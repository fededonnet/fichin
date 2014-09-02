#ifndef __FKEYBOARD_HPP__
#define __FKEYBOARD_HPP__

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Window/Keyboard.hpp>

////////////////////////////////////////////////////////////
/// \brief Permite tener acceso al estado del teclado
///
////////////////////////////////////////////////////////////
class fKeyboard{
public:
	////////////////////////////////////////////////////////////
	/// \brief Permite saber si una tecla está siendo presionada
	///
	/// \param key Tecla cuyo estado se desea conocer
	///
	/// \return Verdadero si la tecla está presionada, falso de lo contrario
	///
	////////////////////////////////////////////////////////////
	static bool pressed(const sf::Keyboard::Key &key);
	
	////////////////////////////////////////////////////////////
	/// \brief 	Permite saber si una tecla acaba de ser presionada, 
	///			es decir, que está presionada en la iteración actual
	///			del bucle de juego pero que no lo estaba en la anterior
	///
	/// \param key Tecla cuyo estado se desea conocer
	///
	/// \return Verdadero si la tecla acaba de ser presionada, falso de lo contrario
	///
	////////////////////////////////////////////////////////////
	static bool justPressed(const sf::Keyboard::Key &key);
	
	////////////////////////////////////////////////////////////
	/// \brief Permite saber si una tecla no está siendo presionada
	///
	/// \param key Tecla cuyo estado se desea conocer
	///
	/// \return Verdadero si la tecla no está presionada, falso de lo contrario
	///
	////////////////////////////////////////////////////////////
	static bool released(const sf::Keyboard::Key &key);
	
	////////////////////////////////////////////////////////////
	/// \brief 	Permite saber si una tecla acaba de ser soltada, 
	///			es decir, que no está presionada en la iteración actual
	///			del bucle de juego pero que lo estaba en la anterior
	///
	/// \param key Tecla cuyo estado se desea conocer
	///
	/// \return Verdadero si la tecla acaba de ser soltada, falso de lo contrario
	///
	////////////////////////////////////////////////////////////
	static bool justReleased(const sf::Keyboard::Key &key);

private:
	static void init();									///< Inicializa variables internas
	static void update();								///< Actualiza el estado interno de las teclas
	
	static int formerKeyStatus[4], currentKeyStatus[4];	///< Estados de las teclas para el frame anterior y el actual
	
	friend class fGame;		///< Sólo la clase fGame puede acceder a los métodos init() y update()
};

#endif // __FKEYBOARD_HPP__

////////////////////////////////////////////////////////////
/// \class fKeyboard
///
/// Permite conocer el estado del teclado. Posee métodos
/// estáticos para conocer si una determinada tecla
/// está presionada o acaba de ser presionada.
///
/// Ejemplo de uso:
///
/// class MyScene: public fScene
/// {
/// 	void update(float dt)
///		{
///			if(Keyboard::pressed(sf::Key::A)
///			{
///				...acciones si la tecla A está presionada
///			}
///		}
/// };
////////////////////////////////////////////////////////////
