#include <fichin/components/fKinematicController.hpp>

////////////////////////////////////////////////////////////

fKinematicController::fKinematicController(sf::Transformable &t):
_transform(&t),
_velocity(0, 0),
_maxVelocity(0, 0),
_acceleration(0, 0),
_drag(0, 0),
_angularVelocity(0),
_angularAcceleration(0),
_maxAngularVelocity(0),
_angularDrag(0)
{
	
}

////////////////////////////////////////////////////////////

void fKinematicController::updateKinematics(float dt){
	updateVelocities(dt);
	_transform->move(_velocity.x * dt, _velocity.y * dt);
	_transform->rotate(_angularVelocity * dt);
}

////////////////////////////////////////////////////////////

void fKinematicController::updateVelocities(float dt){
	_velocity.x = computeVelocity(_velocity.x, _acceleration.x, _drag.x, _maxVelocity.x, dt);
	_velocity.y = computeVelocity(_velocity.y, _acceleration.y, _drag.y, _maxVelocity.y, dt);
	_angularVelocity = computeVelocity(_angularVelocity, _angularAcceleration, _angularDrag, _maxAngularVelocity, dt);
}

////////////////////////////////////////////////////////////

float fKinematicController::computeVelocity(float velocity, float acceleration, float drag, float maxVelocity, float dt){
	// apply acceleration/drag
	if(acceleration != 0){
		velocity += acceleration * dt;
	}else if (drag != 0){
		float deltadrag = drag *dt;
		if(velocity - deltadrag > 0){
			velocity -= deltadrag;
		}else if (_velocity.x + deltadrag < 0){
			velocity += deltadrag;
		}else{
			velocity = 0;
		}
	}

	// apply max velocity
	if(velocity != 0 && maxVelocity != 0){
		if (velocity > maxVelocity){
			velocity = maxVelocity;
		}else if(velocity < -maxVelocity){
			velocity = -maxVelocity;
		}
	}
	return velocity;
}	

