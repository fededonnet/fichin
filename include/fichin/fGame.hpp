#ifndef __FGAME_HPP__
#define __FGAME_HPP__

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics/RenderWindow.hpp>
#include <fichin/fScene.hpp>

////////////////////////////////////////////////////////////
/// \brief 	Objeto que controla la ventana de video y el bucle de juego
/// 		
/// \see fScene
///
////////////////////////////////////////////////////////////
class fGame
{ 
public:
	////////////////////////////////////////////////////////////
	/// \brief Construye e inicializa el juego
	///
	/// \param mode Tama�o y propiedades de la ventana de video
	///
	////////////////////////////////////////////////////////////
	fGame(sf::VideoMode mode);
	
	////////////////////////////////////////////////////////////
	/// \brief Inicia el juego con la escena especificada
	///
	/// \param scene Escena inicial del juego
	///
	////////////////////////////////////////////////////////////
	int run(fScene *scene);
	
	////////////////////////////////////////////////////////////
	/// \brief Termina con la ejecuci�n de la escena actual y
	/// comienza a ejecutar una nueva escena
	///
	/// \param nextScene La siguiente escena que se ejecutar�
	///
	////////////////////////////////////////////////////////////
	void switchScene(fScene *nextScene);
	
	
private:
	fScene *_currentScene;		///< La escena actual
	fScene *_nextScene;			///< La pr�xima escena, en caso de que se haya pedido un cambio de escena
	bool _sceneSwitchRequested;	///< Indica si el usuario ha solicitado un cambio de escena
	sf::RenderWindow _window;	///< La ventana de juego
};

#endif // __FGAME_HPP__

////////////////////////////////////////////////////////////
/// \class fGame
///
/// Representa a un juego. Lleva el control de la ventana de video
/// y el bucle de juego. Una vez creado el objeto se debe especificar
/// la escena inicial invocando al m�todo run() para comenzar el juego.
///
/// Ejemplo de uso:
/// \code
/// 
/// int main(int argc, char *argv[])
/// {
/// 	fGame g(sf::VideoMode(800, 600));
/// 	g.run(new PlayScene());
/// }
/// 
/// \endcode
///
/// \see fScene
///
////////////////////////////////////////////////////////////
