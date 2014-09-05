#include <fichin/fText.hpp>
#include <fichin/fResourceManager.hpp>
#include <cstdarg>

/////////////////////////////////////////////////
fText::fText() {

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
void fText::printf(const char *fmt, ...){
	char buffer[256];
 	va_list args;
	va_start (args, fmt);
	vsprintf (buffer,fmt, args);
	setString(buffer);
	va_end (args);
}
