#ifndef __FTILEMAP_HPP_
#define __FTILEMAP_HPP_

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <fichin/fActor.hpp>
#include <vector>


////////////////////////////////////////////////////////////
/// \brief Actor que representa un tilemap
///
////////////////////////////////////////////////////////////
class fTilemap: public sf::Transformable, public fActor{
public:
	////////////////////////////////////////////////////////////
	/// \brief 	Construye un objeto de tipo tilemap vac�o. Es necesario
	///			invocar luego a loadFromFile() o loadFromMemory() para
	///			cargar el tilemap.
	///
	///	\see 	loadFromFile loadFromMemory
	///
	////////////////////////////////////////////////////////////
	fTilemap();
	
	////////////////////////////////////////////////////////////
	/// \brief 	Carga los datos de un tilemap desde un archivo de texto
	///			con valores separados por coma
	///
	///	\param	filaname		Nombre del archivo de texto que contiene los datos del tilemap
	///	\param	heightInTiles	Alto del tilemap (en tiles)
	///	\param	widthInTiles	Ancho del tilemap (en tiles)
	///	\param	tileset			Nombre del archivo de textura con el tileset a utilizar
	///	\param	tileWidth		Ancho del los patrones del tileset
	///	\param	tileHeight		Alto del los patrones del tileset
	///
	///	\see loadFromMemory
	///
	////////////////////////////////////////////////////////////
	void loadFromCSVFile(const std::string &filaname, int heightInTiles, int widthInTiles, const std::string &tileset, int tileWidth, int tileHeight);
	
	////////////////////////////////////////////////////////////
	/// \brief 	Carga los datos de un tilemap desde memoria
	///
	///	\param	data			Puntero a la memoria que contiene los datos del tilemap
	///	\param	heightInTiles	Alto del tilemap (en tiles)
	///	\param	widthInTiles	Ancho del tilemap (en tiles)
	///	\param	tileset			Nombre del archivo de textura con el tileset a utilizar
	///	\param	tileWidth		Ancho del los patrones del tileset
	///	\param	tileHeight		Alto del los patrones del tileset
	///
	///	\see loadFromCSVFile
	///
	////////////////////////////////////////////////////////////
	void loadFromMemory(int *data, int heightInTiles, int widthInTiles, const std::string &tileset, int tileWidth, int tileHeight);
	
	////////////////////////////////////////////////////////////
	/// \brief Dibuja el tilemap. Es llamada autom�ticamente por la escena. 
	///
	/// \param target La ventana en donde se debe dibujar al actor
	/// \param states Estados para el dibujado del actor en la ventana
	///
	/// \see sf::RenderTarget, sf::RenderStates
	///
	////////////////////////////////////////////////////////////
	void draw(sf::RenderTarget &t, sf::RenderStates s) const;
	
	////////////////////////////////////////////////////////////
	/// \brief 			Obtiene un arreglo con los tiles de un determinado
	///					tipo dentro del mapa
	///
	/// \param 		t 	Tipo de tile que se desea buscar en el mapa
	///
	/// \return			Vector con los �ndices de los tiles del tipo t
	///
	////////////////////////////////////////////////////////////
	std::vector<int> getTileInstances(int t);
	
	////////////////////////////////////////////////////////////
	/// \brief 		Obtiene las coordenadas de la esquina superior de un
	///				tile a partir de su indice
	///
	/// \param i 	�ndice del tile cuya posici�n se desea obtener
	///
	/// \return		Coordenadas del tile con el �ndice especificado
	///
	////////////////////////////////////////////////////////////
	sf::Vector2f getTileCoords(int i);
	
	////////////////////////////////////////////////////////////
	/// \brief 		Devuelve la porci�n rectangular del espacio que ocupa el tilemap
	///
	/// \return		Rect�ngulo que indica la regi�n que ocupa el tilemap
	///
	////////////////////////////////////////////////////////////
	sf::FloatRect getBounds();
	
private:
	std::vector<int> _tiles;		/// numeros de los patrones del tilemap
	int _width;						/// ancho del tilemap en tiles
	int _height;					/// alto del tilemap en tiles
	int _tileWidth;					/// ancho de los patrones
	int _tileHeight;				/// alto de los patrones
	const sf::Texture *_texture;	/// textura del tileset utilizado
	
	////////////////////////////////////////////////////////////
	/// \brief 		Funci�n auxiliar para el dibujado del tilemap. Agrega los
	///				v�rtices de un tile a un VertexArray
	///
	/// \param 		tileIndex 	�ndice del tile que se quiere dibujar
	/// \param 		vertices 	VertexArray al cual se agregar�n los v�rtices del tile
	///
	////////////////////////////////////////////////////////////
	void drawTile(int tileIndex, sf::VertexArray &vertices) const;
	
	////////////////////////////////////////////////////////////
	/// \brief 		Funci�n auxiliar para redimensionar el arreglo que contiene
	///				los datos del tilemap
	///
	/// \param 		newWidth 	Nuevo ancho del tilemap
	/// \param 		newHeight 	Nuevo alto del tilemap
	///
	////////////////////////////////////////////////////////////
	void resizeTilemap(int newWidth, int newHeight);
};

#endif // __FTILEMAP_HPP_
