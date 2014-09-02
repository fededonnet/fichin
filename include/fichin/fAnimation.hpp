#ifndef __FANIMATION_HPP__
#define __FANIMATION_HPP__

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <initializer_list>
#include <vector>
#include <string>

////////////////////////////////////////////////////////////
/// \brief 	Clase para represenar la animaci�n de un sprite.
///			�sta clase est� pensada para uso interno y es
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
	/// \brief Construye una animaci�n
	///
	/// \param name 	Nombre de la animaci�n
	/// \param frames	Indices de los cuadros del fSpritesheet que conforman la animaci�n
	/// \param fps 		Velocidad de la animaci�n en cantidad de cuadros por segundo
	/// \param loop		Indica si la animaci�n debe reiniciar autom�ticamente al finalizar
	////////////////////////////////////////////////////////////
	fAnimation(const std::string &name, const std::initializer_list<int> &frames, float fps = 10, bool loop = true);
	
	///////////////////////////////////////////////////////////
	/// \brief 	Devuelve la duraci�n de un cuadro de la animaci�n.
	///			Todos los cuadros tienen la misma duraci�n
	///
	/// \return Duraci�n (en segundos) de un cuadro de la animaci�n
	////////////////////////////////////////////////////////////
	float getFrameDuration() const;
	
	///////////////////////////////////////////////////////////
	/// \brief Devuelve la cantidad de cuadros que componen la animaci�n
	///
	/// \return Cantidad de cuadros que componen la animaci�n
	////////////////////////////////////////////////////////////
	int getFrameCount() const;
	
	///////////////////////////////////////////////////////////
	/// \brief 	Devuelve el n�mero de cuadro dentro del fSpritesheet
	///			para un determinado cuadro de la animaci�n
	/// 
	/// \param 	i	Ordinal del cuadro la animaci�n cuyo cuadro dentro del fSpritesheet se desea conocer
	///
	/// \return N�mero de cuadro, dentro del fSpritesheet, del i-�simo cuadro de la animaci�n
	////////////////////////////////////////////////////////////
	int getFrame(int i) const;
	
	///////////////////////////////////////////////////////////
	/// \brief Devuelve el nombre de la animaci�n
	///
	/// \return Nombre de la animaci�n
	////////////////////////////////////////////////////////////
	const std::string &getName() const;
	
	///////////////////////////////////////////////////////////
	/// \brief Devuelve si la animaci�n se ejecuta en un bucle, es decir, vuelve a comenzar al terminar
	///
	/// \return Si la animaci�n debe o no volver a comenzar cuando haya terminado
	////////////////////////////////////////////////////////////
	bool loops() const;
	
private:
	////////////////////////////////////////////////////////////
	// Member data
	////////////////////////////////////////////////////////////
	float _frameDuration;		///< Duraci�n de un cuadro de animaci�n
	std::vector<int> _frames;	///< Indices de los cuadros que componen la animaci�n
	std::string _name;			///< Nombre de la animaci�n
	bool _loop;					///< Debe la animacion comenzar de nuevo autom�ticamente al finalizar?
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
