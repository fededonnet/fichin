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
/// \brief 	Objeto que sirve para dibujar una animaci�n sobre un fSpriteRenderer
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
	/// \param renderer 	Objeto fSpriteRenderer sobre el cual se dibujar�n los cuadros de la animaci�n
	///
	////////////////////////////////////////////////////////////
	fAnimationController(fSpriteRenderer &renderer);
	
	////////////////////////////////////////////////////////////
	/// \brief Agrega una nueva animaci�n al manejador de recursos, la misma estar� disponible para cualquier objeto que la solicite
	///
	/// \param name 	Nombre de la animaci�n
	/// \param frames	Indices de los cuadros del fSpritesheet que componene la animaci�n
	/// \param fps		Velocidad de la animaci�n en cuadros por segundo
	/// \param loop		Si la animaci�n debe reiniciar autom�ticamente al finalizar
	///
	/// \see playAnimation
	////////////////////////////////////////////////////////////
	static void addAnimation(const std::string &name, std::initializer_list<int> frames, float fps = 5, bool loop = true);
	
	////////////////////////////////////////////////////////////
	/// \brief Reproduce una animaci�n
	///
	/// \param name 	Nombre de la animaci�n que se desea reproducir, debe haber sido cargada previamente mediante addAnimation()
	/// \param restart	En caso de que la animaci�n ya se est� reproduciendo si �sta debe reiniciarse
	///
	/// \see addAnimation
	////////////////////////////////////////////////////////////
	void playAnimation(const std::string &name, bool restart = false);
	
	////////////////////////////////////////////////////////////
	/// \brief 	Asigna al fSpriteRenderer asociado un cuadro del fSpritesheet.
	///
	/// \param frame 	Indice del cuadro del fSpritesheet que se dibujar� sobre el fSpriteRenderer asociado
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
	/// \param texture 		Nombre con el cual se identifica al recurso de textura que utilizar� el fSpritesheet
	/// \param frameWidth	Ancho de cada cuadro (todos los cuadros deben tener el mismo tama�o)
	/// \param frameHeight	Alto de cada cuadro (todos los cuadros deben tener el mismo tama�o). En caso de que no se especifique se tomar� el alto de la textura
	///	\param name			Nombre con el cual se identificar� al fSpritesheet creado para que pueda ser accedido desde otros objetos
	///
	/// \see fSpritesheet
	////////////////////////////////////////////////////////////
	void setSpritesheet(const std::string &texture, int frameWidth, int frameHeight = -1, const std::string &name = "");
	
	////////////////////////////////////////////////////////////
	/// \brief	Actualiza la animaci�n e indica al fSpriteRenderer asociado cu�l cuadro mostrar
	///
	/// \param dt Tiempo transcurrido desde la �ltima actualizaci�n
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
	/// \brief Reproduce una animaci�n
	///
	/// \param anim 	Animaci�n que se desea reproducir
	/// \param restart	En caso de que la animaci�n ya se est� reproduciendo si �sta debe reiniciarse
	///
	/// \see addAnimation
	////////////////////////////////////////////////////////////
	void playAnimation(const fAnimation &anim, bool restart = false);
	
	////////////////////////////////////////////////////////////
	/// \brief 	Asocia un fSpritesheet al fAnimationController. Es necesario que el fSpritesheet
	///			haya sido cargado previamente en el manejador de recursos.
	///
	/// \param spritesheet	Objeto fSpritesheet que se asociar� a la animaci�n
	///
	////////////////////////////////////////////////////////////
	void setSpritesheet(const fSpritesheet &spritesheet);
	
	///////////////////////////////////////////////////////////
	/// \brief	Asocia un fSpritesheet al fAnimationController,
	/// 		creandolo y cargandolo en caso de que haya sido
	/// 		cargado previamente en el manejador de recursos.
	///
	/// \param texture 		Textura que utilizar� el fSpritesheet
	/// \param frameWidth	Ancho de cada cuadro (todos los cuadros deben tener el mismo tama�o)
	/// \param frameHeight	Alto de cada cuadro (todos los cuadros deben tener el mismo tama�o). En caso de que no se especifique se tomar� el alto de la textura
	///	\param name			Nombre con el cual se identificar� al fSpritesheet creado para que pueda ser accedido desde otros objetos
	///
	/// \see fSpritesheet
	////////////////////////////////////////////////////////////
	void setSpritesheet(const sf::Texture &texture, int frameWidth, int frameHeight = -1, const std::string &name = "");
	
	////////////////////////////////////////////////////////////
	/// \brief	Retorna el nombre (asignado por el usuario) de la animaci�n actual
	////////////////////////////////////////////////////////////
	std::string const& getCurrentAnimationName();
	
	
	////////////////////////////////////////////////////////////
	/// \brief	Asigna un callback que va a ser llamado cada vez que termina una animaci�n
	/// \param callback 	std::function que recibe la referencia constante de un std::string
	////////////////////////////////////////////////////////////
	void setAnimationEndCallback(std::function<void(std::string const&)> callback);
	
private:
	const fAnimation *_animation;		///<	Objeto fAnimation asociado
	int _currentFrame;					///<	Numero de cuadro que se est� mostrando de la animaci�n 
	float _frameElapsed;				///<	Tiempo transcurrido en el cuadro actual de la animaci�n
	bool _isPlaying;					///<	Si la animaci�n est� o no reproduciendose
	fSpriteRenderer *_spriteRenderer;	///<	El objeto fSpriteRenderer al cual se dibujan los cuadros
	const fSpritesheet *_spritesheet;	///<	Objeto fSpritesheet asociado
	std::function<void(std::string const&)> animationEndCallback; ///<	Objeto std::function que sirve de callback al finalizar una animaci�n.
};
	

#endif // __FANIMATIONCONTROLLER_HPP__

////////////////////////////////////////////////////////////
/// \class fAnimationController
///
/// Asocia objetos de tipos fSpritesheet y fAnimation
/// con un fSpriteRenderer. Puede dibujar cuadros de un fSpritesheet
/// o reproducir una animaci�n sobre un fSpriteRenderer.
/// Tambi�n tiene funciones para crear o cargar objetos de tipo
/// fSpritesheet y fAnimation.
///
/// Es utilizada por la clase fSprite.
///
/// \see fSpriteRenderer, fAnimation, fSpritesheet, fSprite 
///
////////////////////////////////////////////////////////////
