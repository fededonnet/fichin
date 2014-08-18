#ifndef __KINEMATICS_HPP__
#define __KINEMATICS_HPP__
#include <SFML/Graphics/Transformable.hpp>

class KinematicsController{
public:
	KinematicsController();
	inline void setTransformable(sf::Transformable &t){_transform = &t; };

	inline void setVelocity(sf::Vector2f newVel) { _velocity = newVel; };
	inline void setVelocity(float velx, float vely) { _velocity.x = velx; _velocity.y = vely; };
	inline void setVelocityX(float velx) { _velocity.x = velx; };
	inline void setVelocityY(float vely) { _velocity.y = vely; };
	
	inline void setAcceleration(sf::Vector2f newAcc) { _acceleration = newAcc; };
	inline void setAcceleration(float accx, float accy) { _acceleration.x = accx; _acceleration.y = accy; };
	
	inline void setDrag(sf::Vector2f newDrag) { _drag = newDrag; };
	inline void setDrag(float dragx, float dragy) { _drag.x = dragx; _drag.y = dragy; };

	inline void setMaxVelocity(sf::Vector2f newMaxVel) { _velocity = newMaxVel; };
	inline void setMaxVelocity(float maxvelx, float maxvely) { _maxVelocity.x = maxvelx; _maxVelocity.y = maxvely; };

	inline void setAngularVelocity(float angularVel) { _angularVelocity = angularVel; };
	inline void setAngularAcceleration(float angularAcc) { _angularAcceleration = angularAcc; };
	
	inline void setAngularDrag(float angularDrag) { _angularDrag = angularDrag; };
	inline void setMaxAngularVelocity(float maxAngular) {_maxAngularVelocity = maxAngular; };

	inline const sf::Vector2f &getVelocity() const { return _velocity; };
	inline const sf::Vector2f &getAcceleration() const { return _acceleration; };
	inline const sf::Vector2f &getDrag() const { return _drag; };
	inline const sf::Vector2f &getMaxVelocity() const { return _maxVelocity; };
	inline const float getAngularVelocity() const { return _angularVelocity; };
	inline const float getMaxAngularVelocity() const { return _maxAngularVelocity; };
	
	void update(float dt);
	
private:
	sf::Transformable *_transform;
	sf::Vector2f _velocity;
	sf::Vector2f _maxVelocity;
	sf::Vector2f _acceleration;
	sf::Vector2f _drag;
	float _angularVelocity;
	float _angularAcceleration;
	float _maxAngularVelocity;
	float _angularDrag;

	float computeVelocity(float velocity, float acceleration, float drag, float maxVelocity, float dt);
	void updateVelocities(float dt);
};

#endif // __KINEMATICS_HPP__
