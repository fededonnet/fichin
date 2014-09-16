#include <fichin/fCamera.hpp>
#include <fichin/fGame.hpp>

//////////////////////////////////////////////

fCamera::fCamera()
{
	// por las dudas no asignemos un tamaño a la cámara, toma por defecto el tamaño de la ventana
	const sf::Vector2u &size = fGame::getGame().getWindowSize();
	setSize(size.x, size.y);
	setCenter(size.x/2.0, size.y/2.0);
}

//////////////////////////////////////////////

void fCamera::update(float td)
{
	if(_target != nullptr)
	{
		setCenter(_target->getPosition());
	}
	
	if(_useBounds)
	{
		// corregir la posición de la cámara si sale fuera de los límites
		sf::Vector2f newCenter = getCenter();
		const sf::Vector2f &size = getSize();
		
		const float leftBound = _bounds.left + size.x/2.0;
		const float topBound = _bounds.top + size.y/2.0;
		const float rightBound = _bounds.left + _bounds.width - size.x/2.0;
		const float bottomBound = _bounds.top + _bounds.height - size.y/2.0;
		
		if(newCenter.x > rightBound) 	newCenter.x = rightBound;
		else if(newCenter.x < leftBound)	newCenter.x = leftBound;
		if(newCenter.y < topBound)		newCenter.y = topBound;
		else if(newCenter.y > bottomBound)	newCenter.y = bottomBound;
		
		setCenter(newCenter);
	}
}

//////////////////////////////////////////////

sf::FloatRect fCamera::getBounds() const {
	return sf::FloatRect(getCenter().x - getSize().x/2.0, getCenter().y - getSize().y/2.0, getSize().x, getSize().y);
}
