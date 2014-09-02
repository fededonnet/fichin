#ifndef __FANIMATION_HPP__
#define __FANIMATION_HPP__

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <initializer_list>
#include <vector>
#include <string>

////////////////////////////////////////////////////////////
/// \brief 	Clase para represenar la animación de un sprite.
///			Ésta clase está pensada para uso interno y es
///			empleada por fAnimationController en conjunto
///			con un objeto de tipo fSpritesheet.
///
///	\see fAnimationController fSpritesheet
///
////////////////////////////////////////////////////////////
class fAnimation
{
public:
	////////////////////////////////////////////////////////////
	/// \brief Construye una animación
	///
	/// \param name 	Nombre de la animación
	/// \param frames	Indices de los cuadros del fSpritesheet que conforman la animación
	/// \param fps 		Velocidad de la animación en cantidad de cuadros por segundo
	/// \param loop		Indica si la animación debe reiniciar automáticamente al finalizar
	////////////////////////////////////////////////////////////
	fAnimation(const std::string &name, const std::initializer_list<int> &frames, float fps = 10, bool loop = true);
	
	///////////////////////////////////////////////////////////
	/// \brief 	Devuelve la duración de un cuadro de la animación.
	///			Todos los cuadros tienen la misma duración
	///
	/// \return Duración (en segundos) de un cuadro de la animación
	////////////////////////////////////////////////////////////
	float getFrameDuration() const;
	
	///////////////////////////////////////////////////////////
	/// \brief Devuelve la cantidad de cuadros que componen la animación
	///
	/// \return Cantidad de cuadros que componen la animación
	////////////////////////////////////////////////////////////
	int getFrameCount() const;
	
	///////////////////////////////////////////////////////////
	/// \brief 	Devuelve el número de cuadro dentro del fSpritesheet
	///			para un determinado cuadro de la animación
	/// 
	/// \param 	i	Ordinal del cuadro la animación cuyo cuadro dentro del fSpritesheet se desea conocer
	///
	/// \return Número de cuadro, dentro del fSpritesheet, del i-ésimo cuadro de la animación
	////////////////////////////////////////////////////////////
	int getFrame(int i) const;
	
	///////////////////////////////////////////////////////////
	/// \brief Devuelve el nombre de la animación
	///
	/// \return Nombre de la animación
	////////////////////////////////////////////////////////////
	const std::string &getName() const;
	
	///////////////////////////////////////////////////////////
	/// \brief Devuelve si la animación se ejecuta en un bucle, es decir, vuelve a comenzar al terminar
	///
	/// \return Si la animación debe o no volver a comenzar cuando haya terminado
	////////////////////////////////////////////////////////////
	bool loops() const;
	
private:
	////////////////////////////////////////////////////////////
	// Member data
	////////////////////////////////////////////////////////////
	float _frameDuration;		///< Duración de un cuadro de animación
	std::vector<int> _frames;	///< Indices de los cuadros que componen la animación
	std::string _name;			///< Nombre de la animación
	bool _loop;					///< Debe la animacion comenzar de nuevo automáticamente al finalizar?
};


////////////////////////////////////////////////////////////
// Inline functions implementation
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
inline float fAnimation::getFrameDuration() const { return _frameDuration; }

////////////////////////////////////////////////////////////////////////////////
inline int fAnimation::getFrameCount() const { return _frames.size(); }

////////////////////////////////////////////////////////////////////////////////
inline int fAnimation::getFrame(int i) const{ return _frames[i]; }

////////////////////////////////////////////////////////////////////////////////
inline bool fAnimation::loops() const{ return _loop; }

////////////////////////////////////////////////////////////////////////////////
inline const std::string &fAnimation::getName() const{ return _name; }


#endif // __FANIMATION_HPP__
