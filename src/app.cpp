/*
 *  app.cpp
 *  epicgame
 *
 *  Created by Keunhong Park on 2/9/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include <SFML/Graphics.hpp>
#include "app.h"

sf::RenderWindow	App::window;
sf::Clock			App::timer;
float				App::elapsed_time = 0;

float App::get_elapsed_time(){
	return elapsed_time;
}

void App::update_timer(){
	elapsed_time = timer.GetElapsedTime();
	timer.Reset();
}

void App::init(){
	window.Create(sf::VideoMode(WIDTH, HEIGHT, 32), "epicgame", sf::Style::Resize | sf::Style::Close, sf::WindowSettings(24, 8, 2));
	//window.UseVerticalSync(true);
	window.SetFramerateLimit(0);
}