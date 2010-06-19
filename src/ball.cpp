/*
 *  ball.cpp
 *  epicgame
 *
 *  Created by Keunhong Park on 2/9/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "app.h"
#include "world.h"
#include "entity.h"
#include "ball.h"

Ball::Ball():Entity(){
	radius = 0.5 * World::SCALE;
}

Ball::Ball(float sx, float sy, float m, float r){
	position.x = sx * World::SCALE;
	position.y = sy * World::SCALE;
	velocity.x = 0;
	velocity.y = 0;
	mass = m;
	radius = r * World::SCALE;
	
	acceleration.x = 0;
	acceleration.y = World::G * World::SCALE;
}

int Ball::get_radius(){
	return radius;
}

void Ball::tick(){

	// if on ground and can 
	if(App::window.GetInput().IsKeyDown(sf::Key::Up)){
		velocity.y = -10 * World::SCALE;
	}
	
	if(App::window.GetInput().IsKeyDown(sf::Key::Left) && position.y <= App::HEIGHT - radius){
		accelerate(-0.3, 0);
	}else if(App::window.GetInput().IsKeyDown(sf::Key::Right) && position.y <= App::HEIGHT - radius){
		accelerate(0.3, 0);
	}else{
		//velocity.x = 0;
	}
	
	if(
	   position.y <= App::HEIGHT - radius || 
	   App::window.GetInput().IsKeyDown(sf::Key::Up) ||
	   App::window.GetInput().IsKeyDown(sf::Key::Left) ||
	   App::window.GetInput().IsKeyDown(sf::Key::Right)
	)
	{
		/*
		 * x-coordinate stuff 
		 */
		// if hits walls reverse velocity
		if(position.x == 0 + radius || position.x == App::WIDTH - radius){
			velocity.x = -velocity.x;
		}
		
		if(position.x <= App::WIDTH - radius && position.x >= 0 + radius){
			velocity.x += acceleration.x * App::get_elapsed_time();
			position.x += velocity.x * App::get_elapsed_time();
		}
		
		if(position.x >= App::WIDTH - radius){
			position.x = App::WIDTH - radius;
		}else if(position.x <= 0 + radius){
			position.x = 0 + radius;
		}
		
		
		/*
		 * y-coordinate stuff 
		 */
		// if hits walls reverse velocity
		if(position.y == App::HEIGHT - radius || position.y == 0 + radius){
			acceleration.y = 0;
			velocity.y = -velocity.y;
			
			velocity.y *= 0.75;
			if(velocity.y < 5.96E-08 && position.y == 0 + radius) velocity.y = 0;

			// friction
			velocity.x *= 0.999;
		}
		
		if(position.y <= App::HEIGHT - radius){
			velocity.y += acceleration.y * App::get_elapsed_time();
			position.y += velocity.y * App::get_elapsed_time();
		}
		
		// if ball tries to go below boundary then don't let it
		if(position.y > App::HEIGHT - radius){
			position.y = App::HEIGHT - radius;
		}else if(position.y < 0 + radius){
			position.y = 0 + radius;
		}
		
		if(position.y < App::HEIGHT - radius){
			acceleration.y = World::G * World::SCALE;
		}else{
			acceleration.y = 0;
		}
	}
}