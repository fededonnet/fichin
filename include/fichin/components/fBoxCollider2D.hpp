#ifndef FBOXCOLLIDER2D_HPP
#define FBOXCOLLIDER2D_HPP
#include <SFML/Graphics/RectangleShape.hpp>

class fBoxCollider2D {
public:
	////////////////////////////////////////////////////////////
	/// \brief 	Tipos de Mascara de collision del fBoxCollider2D, sirve
	/// para identificar el "tipo" de colision de este componente.
	///
	///
	///
	////////////////////////////////////////////////////////////
	enum class CollideMask {
		SOLID,
		SENSOR
	};
	
	////////////////////////////////////////////////////////////
	/// \brief 	Constructor del componente fBoxCollider2D
	///
	/// \param puntero a objeto sf::Transformable en el cual se va a 
	/// desarollar la "caja" de colision de este fBoxCollider2D
	///
	///
	////////////////////////////////////////////////////////////
	fBoxCollider2D(sf::Transformable *t);
	
	////////////////////////////////////////////////////////////
	/// \brief 	Destructor del componente fBoxCollider2D
	///
	///
	///
	////////////////////////////////////////////////////////////
	~fBoxCollider2D();
	
	////////////////////////////////////////////////////////////
	/// \brief 	Setea la "caja de colision" del componente fBoxCollider2D, dandole
	/// los atributos necesarios para que detecte colisiones con otro fBoxCollider2D
	///
	/// \param width: Ancho de la caja de colision.
	/// \param height: Alto de la caja de colision.
	/// \param draw: Flag que indica si se va a dibujar la caja de colision (por defecto es false).
	/// \param mask: Mascara de colision que va a tener este fBoxCollider2D (por defecto es SENSOR).
	////////////////////////////////////////////////////////////
	void setBox(int width, int height, bool draw = false, CollideMask mask = CollideMask::SENSOR);
	
	////////////////////////////////////////////////////////////
	/// \brief  Actualiza el componente fBoxCollider2D
	///
	/// \param dt: Delta Time del loop del juego.
	///
	////////////////////////////////////////////////////////////
	void update(float dt);
	
	////////////////////////////////////////////////////////////
	/// \brief Dibuja un sf::RectangleShape que representa a este fBoxCollider2D
	///
	/// Dibuja al shape en la ventana target con los estados states.
	/// Es llamada automáticamente por la escena. 
	///
	/// \param target La ventana en donde se debe dibujar al actor
	/// \param states Estados para el dibujado del actor en la ventana
	///
	/// \see sf::RenderTarget, sf::RenderStates
	///
	////////////////////////////////////////////////////////////
	void draw(sf::RenderTarget &w, sf::RenderStates s) const;
	
	////////////////////////////////////////////////////////////
	/// \brief  Retorna el rect que representa a este fBoxCollider2D
	///
	/// \return sf::Rect<int>: Referencia constante del Rect que representa la caja de colision.
	////////////////////////////////////////////////////////////
	inline sf::Rect<int> const& getBoxCollider2DRect() { return _rect;}
	
	////////////////////////////////////////////////////////////
	/// \brief  Retorna el tamaño en pixeles de la caja de colision
	///
	/// \return sf::Vector2f: Referencia constante del vector que representa el tamaño en pixeles de la caja de colision.
	////////////////////////////////////////////////////////////
	inline sf::Vector2f const& getBoxCollider2DSize() { return _size;}	
	
	////////////////////////////////////////////////////////////
	/// \brief  Chequea si un punto se encuentra dentro de la caja de colision
	///
	/// \param  pointX: Posicion del punto en eje X.
	/// \param  pointY: Posicion del punto en eje Y.
	/// \return bool: Flag que indica si hay colision.
	////////////////////////////////////////////////////////////
	bool contains(float pointX, float pointY);
	
	////////////////////////////////////////////////////////////
	/// \brief  Chequea si un punto se encuentra dentro de la caja de colision
	///
	/// \param  point: Referencia constante del sf::Vector2 a chequear.
	/// \return bool: Flag que indica si hay colision.
	////////////////////////////////////////////////////////////
	bool contains(sf::Vector2f const& point);	
	
	////////////////////////////////////////////////////////////
	/// \brief  Chequea si un Rect se encuentra colisionando con la caja de colision
	///
	/// \param  otherRect: Referencia constante del sf::Rect<int> a chequear.
	/// \return bool: Flag que indica si hay colision.
	////////////////////////////////////////////////////////////
	bool overlaps(sf::Rect<int> const& otherRect);
	
	////////////////////////////////////////////////////////////
	/// \brief  Chequea si un fBoxCollider2D se encuentra colisionado con la caja de colision
	///
	/// \param other: Puntero a objeto fBoxCollider2D a chequear.
	/// \return bool: Flag que indica si hay colision.
	////////////////////////////////////////////////////////////
	bool overlaps(fBoxCollider2D* other);
	
	////////////////////////////////////////////////////////////
	/// \brief  Setea un tipo de mascara de colision 
	///
	/// \param mask: Tipo de mascara de colision.
	////////////////////////////////////////////////////////////
	void setCollideMask(CollideMask mask);

private: 
	////////////////////////////////////////////////////////////
	/// \brief Funcion de uso interno para actualizar al _rect 
	///
	////////////////////////////////////////////////////////////
	void updateRect();
	
	sf::Transformable* _transform;		///< El objeto transformable que cuya posicion se va a formar y actualizar al _rect
	sf::Rect<int> _rect;  				///< Rect que representa las dimenciones de la "caja de colision" de este fBoxCollider2D.
	sf::Vector2f _size; 				///< Tamaño (ancho y alto) de la caja de colision.
	sf::RectangleShape _renderShape; 	///< Shape grafico para dibujar y representar a este fBoxCollider2D.
	CollideMask _collideMask; 			///< Mascara que sirve para identificar el tipo de colision con este fBoxCollider2D.
	bool _draw; 						///< Flag que indica si se debe dibujar el rectangleShape que representa al fBoxCollider2D.
};

#endif

