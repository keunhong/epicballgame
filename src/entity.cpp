/*
 *  entity.cpp
 *  epicgame
 *
 *  Created by Keunhong Park on 2/8/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "app.h"
#include "entity.h"
#include "world.h"

Entity::Entity(){
	position.x = 1 * World::SCALE;
	position.y = 1 * World::SCALE;
	velocity.x = 0;
	velocity.y = 0;
	acceleration.x = 0;
	acceleration.y = World::G * World::SCALE;
	mass = 1;
}

Point Entity::get_position(){
	return position;
}

Point Entity::get_velocity(){
	return velocity;
}

Point Entity::get_acceleration(){
	return acceleration;
}

float Entity::get_mass(){
	return mass;
}

void Entity::accelerate(float x, float y){
	velocity.x += x;
	velocity.y += y;
}