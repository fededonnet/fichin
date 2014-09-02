#ifndef __FSPRITESHEET_HPP__
#define __FSPRITESHEET_HPP__

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <vector>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <fichin/fResourceManager.hpp>

////////////////////////////////////////////////////////////
/// \brief 	Estructura para almacenar los subrectángulos de
///			textura de un sprite sheet
///
////////////////////////////////////////////////////////////
class fSpritesheet{
public:
	////////////////////////////////////////////////////////////
	/// \brief Constructor
	///
	/// \param texture		Textura del sprite sheet
	/// \param frameWidth	Ancho del cuadro (se asume que todos los cuadros tienen el mismo tamaño)
	/// \param frameHeight	Alto del cuadro (se asume que todos los cuadros tienen el mismo tamaño).
	///						En caso de especificar el valor -1 se toma como alto al alto de la textura
	///
	////////////////////////////////////////////////////////////
	fSpritesheet(const sf::Texture &texture, int frameWidth, int frameHeight = -1);
	
	////////////////////////////////////////////////////////////
	/// \brief 		Obtiene el subrectángulo de textura correspondiente a un cuadro
	///
	/// \param	i	Ordinal del cuadro que se desea obtener
	///
	/// \return		Subrectángulo de textura donde se ubica el cuadro buscado
	///
	////////////////////////////////////////////////////////////
	const sf::IntRect &getRect(int i) const;
	
	////////////////////////////////////////////////////////////
	/// \brief 	Obtiene la textura utilizada por el sprite sheet
	///
	/// \return	Textura utilizada por el sprite sheet 
	///
	////////////////////////////////////////////////////////////
	const sf::Texture &getTexture() const;
	
	////////////////////////////////////////////////////////////
	/// \brief 		Obtiene la cantidad de cuadros que hay en el sprite sheet
	///
	/// \return 	Cantidad de cuadros que hay en el sprite sheet
	///
	////////////////////////////////////////////////////////////
	unsigned int getRectCount() const;
	
private:
	const sf::Texture *_texture;		///< La textura del sprite sheet
	std::vector<sf::IntRect> _rects;	///< Los subrectangulos con las regiones de los cuadros
};


////////////////////////////////////////////////////////////
// Inline functions implementation
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
inline const sf::IntRect &fSpritesheet::getRect(int i) const { return _rects[i]; }

////////////////////////////////////////////////////////////////////////////////
inline const sf::Texture &fSpritesheet::getTexture() const { return *_texture; }

////////////////////////////////////////////////////////////////////////////////
inline unsigned int fSpritesheet::getRectCount() const { return _rects.size(); }

#endif // __FSPRITESHEET_HPP__
