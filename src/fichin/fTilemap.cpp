#include <fichin/fTilemap.hpp>
#include <fichin/fResourceManager.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <sstream>
#include <fstream>

//////////////////////////////////////////////

fTilemap::fTilemap():
_width(0),
_height(0),
_tileWidth(0),
_tileHeight(0),
_texture(nullptr)
{
}

//////////////////////////////////////////////

void fTilemap::loadFromCSVFile(const std::string &filename, int heightInTiles, int widthInTiles, const std::string &tileset, int tileWidth, int tileHeight)
{
	resizeTilemap(heightInTiles, widthInTiles);
	_texture = &fResourceManager::loadFromFile<sf::Texture>(tileset);
	_tileWidth = tileWidth;
	_tileHeight = tileHeight;
	ifstream input(filename.c_str());
	if(!input.is_open())
	{
		cerr<<"ERROR: No se encontró el archivo "+filename<<endl;
		return;
	}
	string line, value;
	int count = 0;
	while(std::getline(input,line)){
		std::stringstream ss(line);
		while(std::getline(ss,value,','))
		{
			_tiles[count++] = atoi(value.c_str());
		}
	}
	
}

//////////////////////////////////////////////

void fTilemap::loadFromMemory(int *data, int heightInTiles, int widthInTiles, const std::string &tileset, int tileWidth, int tileHeight)
{
	resizeTilemap(widthInTiles, heightInTiles);
	_texture = &fResourceManager::loadFromFile<sf::Texture>(tileset);
	_tileWidth = tileWidth;
	_tileHeight = tileHeight;
	for(int i = 0; i<heightInTiles*widthInTiles; i++)
	{
		_tiles[i] = data[i];
	}
}

//////////////////////////////////////////////

void fTilemap::resizeTilemap(int newWidth, int newHeight)
{
	if(newWidth != _width || newHeight != _height )
	{
		_width = newWidth;
		_height = newHeight;
		_tiles.resize(_width * _height);
	}
}

//////////////////////////////////////////////

void fTilemap::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	static sf::VertexArray vertices(sf::Triangles);
	vertices.clear();
	if(_height*_width > 0 && _texture != nullptr){
		for(int i = 0; i<_height*_width; i++)
		{
			if(_tiles[i] != 0)
			{
				// agregamos los vertices del tile al array
				drawTile(i, vertices);
			}
		}
		// dibujamos los vertices del arreglo como triangulos, con la textura y en la posicion indicadas
		states.transform = getTransform();
		states.texture = _texture;
		target.draw(vertices, states);	
	}
}

//////////////////////////////////////////////

void fTilemap::drawTile(int tileIndex, sf::VertexArray &vertices) const 
{	
	// posición en coordenadas globales de la esquina superior izquierda del tile
	sf::Vector2f tilePos = sf::Vector2f((tileIndex%_width)*_tileWidth, (tileIndex/_width)*_tileHeight);

	// coordenadas de textura de la esquina superior izquierda del tile
	sf::Vector2f tileCoords = sf::Vector2f(((_tiles[tileIndex]-1)%(_texture->getSize().x/_tileWidth))*_tileWidth, ((_tiles[tileIndex]-1)/(_texture->getSize().x/_tileWidth))*_tileHeight);
	
	// posición de los vertices del triángulo superior del tile
	vertices.append(sf::Vertex(sf::Vector2f(tilePos.x, tilePos.y+_tileHeight), sf::Color::White, sf::Vector2f(tileCoords.x, tileCoords.y+_tileHeight)));
	vertices.append(sf::Vertex(sf::Vector2f(tilePos.x+_tileWidth, tilePos.y), sf::Color::White, sf::Vector2f(tileCoords.x + _tileWidth, tileCoords.y)));
	vertices.append(sf::Vertex(sf::Vector2f(tilePos.x, tilePos.y), sf::Color::White, sf::Vector2f(tileCoords.x, tileCoords.y)));
	
	// posición de los vertices del triángulo inferior del tile
	vertices.append(sf::Vertex(sf::Vector2f(tilePos.x, tilePos.y+_tileHeight), sf::Color::White, sf::Vector2f(tileCoords.x, tileCoords.y+_tileHeight)));
	vertices.append(sf::Vertex(sf::Vector2f(tilePos.x+_tileWidth, tilePos.y+_tileHeight), sf::Color::White, sf::Vector2f(tileCoords.x+_tileWidth, tileCoords.y+_tileHeight)));
	vertices.append(sf::Vertex(sf::Vector2f(tilePos.x+_tileWidth, tilePos.y), sf::Color::White,  sf::Vector2f(tileCoords.x + _tileWidth, tileCoords.y)));
}

//////////////////////////////////////////////

std::vector<int> fTilemap::getTileInstances(int i)
{
	std::vector<int> tileInstances;
	for(int c = 0; c < _width * _height; c++)
	{
		if(_tiles[c] == i)
		{
			tileInstances.push_back(c);
		}
	}
	return tileInstances;
}

//////////////////////////////////////////////

sf::Vector2f fTilemap::getTileCoords(int i)
{
	return sf::Vector2f((i%_width)*_tileWidth, (i/_width)*_tileHeight);
}


//////////////////////////////////////////////

sf::FloatRect fTilemap::getBounds(){
	sf::Vector2f pos = getPosition();
	return sf::FloatRect(pos.x, pos.y, pos.x+_width*_tileWidth, pos.y + _height*_tileHeight);
}
