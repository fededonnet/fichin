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
	/// \param mode Tamaño y propiedades de la ventana de video
	///
	////////////////////////////////////////////////////////////
	void init(const sf::VideoMode &mode);
	
	////////////////////////////////////////////////////////////
	/// \brief 	Permite obtener el tamaño de la ventana de juego
	///
	/// \return El tamaño de la ventana de juego
	///
	////////////////////////////////////////////////////////////
	static fGame &getGame();
	
	////////////////////////////////////////////////////////////
	/// \brief Inicia el juego con la escena especificada
	///
	/// \param scene Escena inicial del juego
	///
	////////////////////////////////////////////////////////////
	int run(fScene *scene);
	
	////////////////////////////////////////////////////////////
	/// \brief Termina con la ejecución de la escena actual y
	/// comienza a ejecutar una nueva escena
	///
	/// \param nextScene La siguiente escena que se ejecutará
	///
	////////////////////////////////////////////////////////////
	void switchScene(fScene *nextScene);
	
	
	////////////////////////////////////////////////////////////
	/// \brief 	Devuelve la escena del juego que está ejecutándose
	///
	/// \return Escena actual
	///
	////////////////////////////////////////////////////////////
	fScene *getCurrentScene();
	
	
	////////////////////////////////////////////////////////////
	/// \brief 	Permite obtener el tamaño de la ventana de juego
	///
	/// \return El tamaño de la ventana de juego
	///
	////////////////////////////////////////////////////////////
	sf::Vector2u getWindowSize() const;
	
private:
	fGame();							///< Constructor
	static fGame *_singletonInst;		///< Instancia singleton de la clase
	
	fScene *_currentScene;				///< La escena actual
	fScene *_nextScene;					///< La próxima escena, en caso de que se haya pedido un cambio de escena
	bool _sceneSwitchRequested;			///< Indica si el usuario ha solicitado un cambio de escena
	sf::RenderWindow _window;			///< La ventana de juego
};

#endif // __FGAME_HPP__

////////////////////////////////////////////////////////////
/// \class fGame
///
/// Representa a un juego. Lleva el control de la ventana de video
/// y el bucle de juego. Una vez creado el objeto se debe especificar
/// la escena inicial invocando al método run() para comenzar el juego.
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
