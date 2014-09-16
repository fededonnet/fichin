#ifndef __FSPRITERENDERER_HPP__
#define __FSPRITERENDERER_HPP__

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics/BlendMode.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

/////////////////////////////////////////////////
/// \brief 	Permite dibujar una textura o porción de ella
///			en pantalla, en la posición dada por un sf::Transformable
/////////////////////////////////////////////////
class fSpriteRenderer{
public:
	////////////////////////////////////////////////////////////
	/// \brief	Constructor
	///
	///	\param 	t	Transformación asociada, indica en qué lugar
	///				se dibujará la textura
	///
	////////////////////////////////////////////////////////////
	fSpriteRenderer(sf::Transformable &t);
	
	////////////////////////////////////////////////////////////
	/// \brief			Indica si la textura debe dibujarse
	///					invertida horizontalmente
	///
	///	\param 	flip	Verdadero si la textura debe dibujarse
	///					horizontalmente invertida, falso de lo contrario
	///
	////////////////////////////////////////////////////////////
	void flipX(bool flip = true);
	
	////////////////////////////////////////////////////////////
	/// \brief			Indica si la textura debe dibujarse
	///					invertida verticalmente
	///
	///	\param 	flip	Verdadero si la textura debe dibujarse
	///					verticalmente invertida, falso de lo contrario
	///
	////////////////////////////////////////////////////////////
	void flipY(bool flip = true);
	
	////////////////////////////////////////////////////////////
	/// \brief			Cambia el color del sprite. Sólo tiene
	///					efecto con algunos modos de blending
	///
	///	\param 	color	Nuevo color utilizado para dibujar el sprite
	///
	////////////////////////////////////////////////////////////
	void setColor(const sf::Color &color);
	
	////////////////////////////////////////////////////////////
	/// \brief			Obtiene el color usado para dibujar el sprite
	///
	///	\return color	Color utilizado para dibujar el sprite
	///
	////////////////////////////////////////////////////////////
	const sf::Color &getColor();
	
	////////////////////////////////////////////////////////////
	/// \brief			Cambia la transparencia con la que se dibuja el sprite
	///
	///	\param	alpha 	Transparencia con la que se dibuja el sprite
	///
	////////////////////////////////////////////////////////////
	void setAlpha(sf::Uint8 alpha);
	
	////////////////////////////////////////////////////////////
	/// \brief		Obtiene la transparencia con la que se dibuja el sprite
	///
	///	\return 	Transparencia con la que se dibuja el sprite
	///
	////////////////////////////////////////////////////////////
	sf::Uint8 getAlpha();
	
	////////////////////////////////////////////////////////////
	/// \brief			Cambia el modo de blending con el que se dibuja el sprite
	///
	///	\param	blend 	Nuevo modo de blending con el que se dibujará el sprite
	///
	////////////////////////////////////////////////////////////
	void setBlendMode(sf::BlendMode blend);
	
	////////////////////////////////////////////////////////////
	/// \brief		Obtiene el modo de blending con el que se dibuja el sprite
	///
	///	\return 	Modo de blending con el que se dibuja el sprite
	///
	////////////////////////////////////////////////////////////
	sf::BlendMode getBlendMode();
	
	////////////////////////////////////////////////////////////
	/// \brief				Cambia la textura con la que se dibuja el sprite
	///						Utiliza la clase fResourceManager para obtener la
	///						textura correspondiente al archivo dado
	///
	///	\param 	textureName	Nombre del archivo que contiene la textura
	///
	////////////////////////////////////////////////////////////
	void setTexture(const std::string &textureName);
	
	////////////////////////////////////////////////////////////
	/// \brief				Cambia la textura con la que se dibuja el sprite
	///
	///	\param 	texture		Nueva textura con la que se dibujará el sprite
	///
	////////////////////////////////////////////////////////////
	void setTexture(const sf::Texture &texture);
	
	////////////////////////////////////////////////////////////
	/// \brief				Cambia la textura con la que se dibuja el sprite
	///
	///	\param 	texture		Nueva textura con la que se dibujará el sprite
	///	\param 	rect		Región de la textura que se dibujará
	///
	////////////////////////////////////////////////////////////
	void setTexture(const sf::Texture *texture, const sf::IntRect *rect = NULL);
	
	////////////////////////////////////////////////////////////
	/// \brief				Cambia la región de textura que será dibujada en pantalla.
	///						En caso de especificar NULL, se dibujará la textura completa
	///
	///	\param 	rect		Región de la textura que se dibujará
	///
	////////////////////////////////////////////////////////////
	void setTextureRect(const sf::IntRect *rect = NULL);
	
	////////////////////////////////////////////////////////////
	/// \brief		Obtiene la región de textura que es dibujada en pantalla
	///
	///	\return 	Región de textura que es dibujada en pantalla
	///
	////////////////////////////////////////////////////////////
	const sf::IntRect &getTextureRect();
	
	
	////////////////////////////////////////////////////////////
	/// \brief		Permite conocer si el sprite se encuentra dentro
	///				de la región visible por la cámara
	///
	////////////////////////////////////////////////////////////
	bool isOnScreen();
	
	////////////////////////////////////////////////////////////
	/// \brief Dibuja al sprite en pantalla 
	///
	/// \param target La ventana en donde se debe dibujar al actor
	/// \param states Estados para el dibujado del actor en la ventana
	///
	/// \see sf::RenderTarget, sf::RenderStates
	///
	////////////////////////////////////////////////////////////
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	
	////////////////////////////////////////////////////////////
	/// \brief Posiciona el centro de rotación del sprite en el centro
	///
	////////////////////////////////////////////////////////////
	void centerOrigin();
	
protected:
	void updatePositions();					///< Actualiza las coordenadas de los vértices del sprite
	void updateTexCoords();					///< Actualiza las coordenadas de textura de los vértices del sprite
	
private:
	sf::Transformable *_transform;	///< Transformada utilizada para posicionar el sprite
	sf::Vertex _vertices[4];				///< Vértices del sprite
	sf::BlendMode _blendMode;				///< Modo de blending
	const sf::Texture *_texture;			///< Textura utilizada para dibujar el sprite
	const sf::IntRect *_textureRect;		///< Subrectángulo de textura utilizado
	bool _flipX, _flipY;					///< Si debe invertirse el dibujado horizontal o verticalemente
};


////////////////////////////////////////////////////////////
// Inline functions implementation
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
inline void fSpriteRenderer::setBlendMode(sf::BlendMode blend) {_blendMode = blend;}

////////////////////////////////////////////////////////////////////////////////
inline sf::BlendMode fSpriteRenderer::getBlendMode(){return _blendMode;}

////////////////////////////////////////////////////////////////////////////////
inline const sf::IntRect &fSpriteRenderer::getTextureRect() {return *_textureRect; }

#endif	// __FSPRITERENDERER_HPP__
