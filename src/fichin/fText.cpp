#include <fichin/fText.hpp>
#include <fichin/fResourceManager.hpp>
#include <cstdarg>

/////////////////////////////////////////////////
fText::fText(const char* text) {
	setString(text);

}

/////////////////////////////////////////////////
void fText::setFont(const std::string &fontFile) {
	sf::Text::setFont(fResourceManager::loadFromFile<sf::Font>(fontFile));
}

/////////////////////////////////////////////////
void fText::draw(sf::RenderTarget &w, sf::RenderStates s) const {
	w.draw(static_cast<sf::Text>(*this), s);
}

/////////////////////////////////////////////////
void fText::setString(const char* text) {
	Text::setString(text);
	//---*Actualizamos el centro del fText:
	center();
}

/////////////////////////////////////////////////
void fText::printf(const char *fmt, ...){
	char buffer[256];
 	va_list args;
	va_start (args, fmt);
	vsprintf (buffer,fmt, args);
	setString(buffer);
	va_end (args);
}

void fText::center() {
	//---*Actualiza el centro del Text en base al tamaño de fuente, tamaño de letras, al ancho y largo del texto:
	sf::FloatRect bounds = getLocalBounds();
	setOrigin(static_cast<int>(bounds.left+bounds.width/2), static_cast<int>(bounds.top+bounds.height/2));
}

sf::Vector2f fText::getSize() {
	sf::Vector2f size;
	sf::FloatRect bounds = getLocalBounds();
	size.x = bounds.left+bounds.width;
	size.y = bounds.top+bounds.height;
	return size;
}
