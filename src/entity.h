/*
 *  entity.h
 *  epicgame
 *
 *  Created by Keunhong Park on 2/8/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _H_ENTITY
#define _H_ENTITY

struct Point {
	float x;
	float y;
};

class Entity{
protected:
	Point position;
	Point velocity;
	Point acceleration;
	float mass;
	
public:
	Entity();
	Point get_position();
	Point get_velocity();
	Point get_acceleration();
	float get_mass();
	
	void accelerate(float x, float y);
	virtual void tick() = 0;
};

#endif