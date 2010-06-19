/*
 *  ball.h
 *  epicgame
 *
 *  Created by Keunhong Park on 2/9/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _H_BALL
#define _H_BALL

class Ball : public Entity{
private:
	float radius;
	
public:
	Ball();
	Ball(float sx, float sy, float m, float r);
	int get_radius();
	void tick();
};

#endif