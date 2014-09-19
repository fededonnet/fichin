#ifndef __FANIMATIONCONTROLLER_HPP__
#define __FANIMATIONCONTROLLER_HPP__

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <string>
#include <initializer_list>
#include <fichin/fAnimation.hpp>
#include <fichin/components/fSpriteRenderer.hpp>
#include <fichin/fSpritesheet.hpp>

////////////////////////////////////////////////////////////
/// \brief 	Objeto que sirve para dibujar una animación sobre un fSpriteRenderer
///
/// \see fSpriteRenderer, fAnimation, fSpritesheet, fSprite
///
////////////////////////////////////////////////////////////
class fAnimationController
{
public:
	////////////////////////////////////////////////////////////
	/// \brief Construye el objeto
	///
	/// \param renderer 	Objeto fSpriteRenderer sobre el cual se dibujarán los cuadros de la animación
	///
	////////////////////////////////////////////////////////////
	fAnimationController(fSpriteRenderer &renderer);
	
	////////////////////////////////////////////////////////////
	/// \brief Agrega una nueva animación al manejador de recursos, la misma estará disponible para cualquier objeto que la solicite
	///
	/// \param name 	Nombre de la animación
	/// \param frames	Indices de los cuadros del fSpritesheet que componene la animación
	/// \param fps		Velocidad de la animación en cuadros por segundo
	/// \param loop		Si la animación debe reiniciar automáticamente al finalizar
	///
	/// \see playAnimation
	////////////////////////////////////////////////////////////
	static void addAnimation(const std::string &name, std::initializer_list<int> frames, float fps = 5, bool loop = true);
	
	////////////////////////////////////////////////////////////
	/// \brief Reproduce una animación
	///
	/// \param name 	Nombre de la animación que se desea reproducir, debe haber sido cargada previamente mediante addAnimation()
	/// \param restart	En caso de que la animación ya se esté reproduciendo si ésta debe reiniciarse
	///
	/// \see addAnimation
	////////////////////////////////////////////////////////////
	void playAnimation(const std::string &name, bool restart = false);
	
	////////////////////////////////////////////////////////////
	/// \brief 	Asigna al fSpriteRenderer asociado un cuadro del fSpritesheet.
	///
	/// \param frame 	Indice del cuadro del fSpritesheet que se dibujará sobre el fSpriteRenderer asociado
	///
	/// \see setSpritesheet
	////////////////////////////////////////////////////////////
	void setFrame(int frame);
	
	////////////////////////////////////////////////////////////
	/// \brief 	Asocia un fSpritesheet al fAnimationController. Es necesario que el fSpritesheet
	///			haya sido cargado previamente en el manejador de recursos.
	///
	/// \param name	Nombre con el cual se identifica al fSpritesheet
	///
	////////////////////////////////////////////////////////////
	void setSpritesheet(const std::string &name);
	
	////////////////////////////////////////////////////////////
	/// \brief	Asocia un fSpritesheet al fAnimationController,
	/// 		creandolo y cargandolo en caso de que haya sido
	/// 		cargado previamente en el manejador de recursos.
	///
	/// \param texture 		Nombre con el cual se identifica al recurso de textura que utilizará el fSpritesheet
	/// \param frameWidth	Ancho de cada cuadro (todos los cuadros deben tener el mismo tamaño)
	/// \param frameHeight	Alto de cada cuadro (todos los cuadros deben tener el mismo tamaño). En caso de que no se especifique se tomará el alto de la textura
	///	\param name			Nombre con el cual se identificará al fSpritesheet creado para que pueda ser accedido desde otros objetos
	///
	/// \see fSpritesheet
	////////////////////////////////////////////////////////////
	void setSpritesheet(const std::string &texture, int frameWidth, int frameHeight = -1, const std::string &name = "");
	
	////////////////////////////////////////////////////////////
	/// \brief	Actualiza la animación e indica al fSpriteRenderer asociado cuál cuadro mostrar
	///
	/// \param dt Tiempo transcurrido desde la última actualización
	///
	////////////////////////////////////////////////////////////
	void updateAnimation(float dt);
	
	////////////////////////////////////////////////////////////
	/// \brief	Detiene la animacion actual
	///
	////////////////////////////////////////////////////////////
	void pause();
	
	////////////////////////////////////////////////////////////
	/// \brief	Reanuda la animacion actual
	///
	////////////////////////////////////////////////////////////
	void reanude();
	
protected:
	////////////////////////////////////////////////////////////
	/// \brief Reproduce una animación
	///
	/// \param anim 	Animación que se desea reproducir
	/// \param restart	En caso de que la animación ya se esté reproduciendo si ésta debe reiniciarse
	///
	/// \see addAnimation
	////////////////////////////////////////////////////////////
	void playAnimation(const fAnimation &anim, bool restart = false);
	
	////////////////////////////////////////////////////////////
	/// \brief 	Asocia un fSpritesheet al fAnimationController. Es necesario que el fSpritesheet
	///			haya sido cargado previamente en el manejador de recursos.
	///
	/// \param spritesheet	Objeto fSpritesheet que se asociará a la animación
	///
	////////////////////////////////////////////////////////////
	void setSpritesheet(const fSpritesheet &spritesheet);
	
	///////////////////////////////////////////////////////////
	/// \brief	Asocia un fSpritesheet al fAnimationController,
	/// 		creandolo y cargandolo en caso de que haya sido
	/// 		cargado previamente en el manejador de recursos.
	///
	/// \param texture 		Textura que utilizará el fSpritesheet
	/// \param frameWidth	Ancho de cada cuadro (todos los cuadros deben tener el mismo tamaño)
	/// \param frameHeight	Alto de cada cuadro (todos los cuadros deben tener el mismo tamaño). En caso de que no se especifique se tomará el alto de la textura
	///	\param name			Nombre con el cual se identificará al fSpritesheet creado para que pueda ser accedido desde otros objetos
	///
	/// \see fSpritesheet
	////////////////////////////////////////////////////////////
	void setSpritesheet(const sf::Texture &texture, int frameWidth, int frameHeight = -1, const std::string &name = "");
	
	////////////////////////////////////////////////////////////
	/// \brief	Retorna el nombre (asignado por el usuario) de la animación actual
	////////////////////////////////////////////////////////////
	std::string const& getCurrentAnimationName();
	
	
	////////////////////////////////////////////////////////////
	/// \brief	Asigna un callback que va a ser llamado cada vez que termina una animación
	/// \param callback 	std::function que recibe la referencia constante de un std::string
	////////////////////////////////////////////////////////////
	void setAnimationEndCallback(std::function<void(std::string const&)> callback);
	
private:
	const fAnimation *_animation;		///<	Objeto fAnimation asociado
	int _currentFrame;					///<	Numero de cuadro que se está mostrando de la animación 
	float _frameElapsed;				///<	Tiempo transcurrido en el cuadro actual de la animación
	bool _isPlaying;					///<	Si la animación está o no reproduciendose
	fSpriteRenderer *_spriteRenderer;	///<	El objeto fSpriteRenderer al cual se dibujan los cuadros
	const fSpritesheet *_spritesheet;	///<	Objeto fSpritesheet asociado
	std::function<void(std::string const&)> animationEndCallback; ///<	Objeto std::function que sirve de callback al finalizar una animación.
};
	

#endif // __FANIMATIONCONTROLLER_HPP__

////////////////////////////////////////////////////////////
/// \class fAnimationController
///
/// Asocia objetos de tipos fSpritesheet y fAnimation
/// con un fSpriteRenderer. Puede dibujar cuadros de un fSpritesheet
/// o reproducir una animación sobre un fSpriteRenderer.
/// También tiene funciones para crear o cargar objetos de tipo
/// fSpritesheet y fAnimation.
///
/// Es utilizada por la clase fSprite.
///
/// \see fSpriteRenderer, fAnimation, fSpritesheet, fSprite 
///
////////////////////////////////////////////////////////////
