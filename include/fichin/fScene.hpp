#ifndef __FSCENE_HPP__
#define __FSCENE_HPP__

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <fichin/fGroup.hpp>
#include <fichin/fCamera.hpp>

////////////////////////////////////////////////////////////
/// \brief	Representa una escena del juego
///
////////////////////////////////////////////////////////////
class fScene {
public:
	////////////////////////////////////////////////////////////
	/// \brief Construye la escena
	///
	////////////////////////////////////////////////////////////
	fScene();	
	
	////////////////////////////////////////////////////////////
	/// \brief Destructor virtual de la clase fScene
	///
	////////////////////////////////////////////////////////////
	virtual ~fScene();
	
	////////////////////////////////////////////////////////////
	/// \brief Es llamada por el motor en el momento de inicializar la escena
	///
	////////////////////////////////////////////////////////////
	virtual void init();
	
	////////////////////////////////////////////////////////////
	/// \brief Es llamada por el motor en el momento de destruir la escena
	///
	////////////////////////////////////////////////////////////
	virtual void destroy();
	
	////////////////////////////////////////////////////////////
	/// \brief 	Actualiza todos los actores de la escena invocando a
	///			update() para cada uno de ellos.
	///			Es llamada por el motor para actualizar la escena
	///
	/// \param dt Tiempo transcurrido desde la última actualización
	////////////////////////////////////////////////////////////
	virtual void update(float dt);
	
	////////////////////////////////////////////////////////////
	/// \brief 	Dibuja todos los actores de la escena invocanco a
	///			draw() para cada uno de ellos.
	///			Es llamada por el motor para dibujar la escena
	///
	/// \param target La ventana en donde se debe dibujar al actor
	/// \param states Estados para el dibujado del actor en la ventana
	///
	/// \see sf::RenderTarget, sf::RenderStates
	///
	////////////////////////////////////////////////////////////
	virtual void draw(sf::RenderTarget &w, sf::RenderStates s) const;	
	
	////////////////////////////////////////////////////////////
	/// \brief 		Agrega un actor a la escena
	///
	/// \param 	a	Actor que será agregado a la escena
	///
	////////////////////////////////////////////////////////////
	void add(fActor *a);
	
	////////////////////////////////////////////////////////////
	/// \brief 			Cambia el color de fondo de la escena
	///
	/// \param 	color	Nuevo color de fondo para la escena
	///
	////////////////////////////////////////////////////////////
	void setBgColor(const sf::Color &color);
	
	////////////////////////////////////////////////////////////
	/// \brief 		Devuelve el color de fondo utilizado para la escena
	///
	/// \return 	Color de fondo utilizado para la escena
	///
	////////////////////////////////////////////////////////////
	const sf::Color &getBgColor() const;
	
	////////////////////////////////////////////////////////////
	/// \brief 		Devuelve la cámara utilizada por la escena
	///
	/// \return 	Cámara utilizada por la escena
	///
	////////////////////////////////////////////////////////////
	fCamera &getCamera();
	
	
	////////////////////////////////////////////////////////////
	/// \brief 		Pausa la escena
	///
	////////////////////////////////////////////////////////////
	void pause();
	
	////////////////////////////////////////////////////////////
	/// \brief 		Reanuda la escena
	///
	////////////////////////////////////////////////////////////
	void reanude();
	
	////////////////////////////////////////////////////////////
	/// \brief 		Retorna el flag de pausa de la escena
	///
	////////////////////////////////////////////////////////////
	bool isPaused() { return _isPaused; }
	
	
protected:
	fGroup _root;			///< El grupo base que contiene a todos los elementos de la escena
	sf::Color _bgColor;		///< Color de fondo de la escena
	fCamera _camera;
	bool _isPaused;			///< Flag que indica si la escena esta en pausa.
};

////////////////////////////////////////////////////////////
// Inline functions implementation
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
inline void fScene::setBgColor(const sf::Color &color) { _bgColor = color; }

////////////////////////////////////////////////////////////////////////////////
inline const sf::Color &fScene::getBgColor() const { return _bgColor; }



#endif // __FSCENE_HPP__

////////////////////////////////////////////////////////////
/// \class	fScene
///
///	Es la clase base para cualquier escena del juego. Para
/// crear una escena se debe heredar de ésta clase y redefinir
/// los métodos init(), destroy(), update() y draw() siempre que
/// se considere necesario. En caso de no redefinirlos, seguirán
/// con su comportamiento por defecto.
///
/// Cualquier objeto que herede de la clase fActor puede ser agregado
/// a una escena y al hacerlo se invocará automáticamente a los
/// métodos update() y draw() del mismo. Una vez que un actor es
/// agregado a escena, esta última toma control del mismo y se encargará
/// de borrarlo cuando la escena termine, por lo cual no es necesario
/// borrar los actores agregados a una escena.
///
/// Ejemplo de uso:
/// \code
///
/// class MyScene: public fScene
/// {
/// public:
/// 	void init()
/// 	{
/// 		// crea un sprite y lo agrega a escena
/// 		a = new fSprite();
/// 		add(a);
/// 	}
/// 	
/// 	void update(float dt)
/// 	{
/// 		// invocamos a update en la clase padre
/// 		// para que la escena actualice sus actores
/// 		fScene::update(dt);
/// 		
/// 		// agregamos aquí nuestra propia lógica
/// 		if(fKeyboard::pressed(sf::Keyboard::A)
/// 		{
/// 			...
/// 		}
/// 	}
/// 
/// private:
/// 	fSprite a;
/// };
///
/// \endcode
///
////////////////////////////////////////////////////////////
