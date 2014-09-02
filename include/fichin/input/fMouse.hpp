#ifndef __FMOUSE_HPP__
#define __FMOUSE_HPP__

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Window/Mouse.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Window.hpp>

////////////////////////////////////////////////////////////
/// \brief Permite tener acceso al estado del mouse
///
////////////////////////////////////////////////////////////
class fMouse{
public:
	////////////////////////////////////////////////////////////
	/// \brief Permite conocer si un bot�n del mouse est� siendo presionada
	///
	/// \param button Bot�n cuyo estado se desea conocer
	///
	/// \return Verdadero si el bot�n est� presionada, falso de lo contrario
	///
	////////////////////////////////////////////////////////////
	static bool pressed(sf::Mouse::Button button = sf::Mouse::Left);
	
	////////////////////////////////////////////////////////////
	/// \brief 	Permite conocer si un bot�n del mouse acaba de ser presionado, 
	///			es decir, que est� presionado en la iteraci�n actual
	///			del bucle de juego pero que no lo estaba en la anterior
	///
	/// \param button Bot�n cuyo estado se desea conocer
	///
	/// \return Verdadero si el bot�n acaba de ser presionado, falso de lo contrario
	///
	////////////////////////////////////////////////////////////
	static bool justPressed(sf::Mouse::Button button = sf::Mouse::Left);
	
	////////////////////////////////////////////////////////////
	/// \brief 	Permite conocer si un bot�n del mouse acaba de ser soltado, 
	///			es decir, que no est� presionado en la iteraci�n actual
	///			del bucle de juego pero que lo estaba en la anterior
	///
	/// \param button Bot�n cuyo estado se desea conocer
	///
	/// \return Verdadero si el bot�n acaba de ser soltado, falso de lo contrario
	///
	////////////////////////////////////////////////////////////
	static bool justReleased(sf::Mouse::Button button = sf::Mouse::Left);
	
	////////////////////////////////////////////////////////////
	/// \brief 	Permite conocer la posici�n del cursor del mouse dentro de la vantana
	///
	/// \return Posici�n del mouse en coordenadas de la ventana
	///
	////////////////////////////////////////////////////////////
	static const sf::Vector2i &getPosition();
	
	////////////////////////////////////////////////////////////
	/// \brief 	Cambia la posici�n del cursor del mouse dentro de la vantana
	///
	/// \param 	Nueva posici�n del mouse en coordenadas de la ventana
	///
	////////////////////////////////////////////////////////////
	static void setPosition(const sf::Vector2i &pos);
	
	////////////////////////////////////////////////////////////
	/// \brief 	Cambia la visibilidad del cursor del rat�n
	///
	/// \param 	Verdadero si el cursor debe mostrarse, falso de lo contrario
	///
	////////////////////////////////////////////////////////////
	static void show(bool show = true);
	
	////////////////////////////////////////////////////////////
	/// \brief 	Oculta el cursor del rat�n
	///
	////////////////////////////////////////////////////////////
	static void hide();
	
private:
	static void init(sf::Window &w);	///< Inicializa variables internas
	static void update();				///< Actualiza el estado interno de las rat�n
	
	////////////////////////////////////////////////////////////
	/// \brief Estructura para almacenar el estado interno del rat�n 
	////////////////////////////////////////////////////////////
	struct fMouseStatus{
		sf::Vector2i pos;
		char buttonStatus;
	};
	
	static fMouseStatus _currentStatus, _formerStatus;	///< Estado actual y anterior del rat�n
	static sf::Window *_window;							///< La ventana de juego
		
	friend class fGame;
};

#endif // __FMOUSE_HPP__
