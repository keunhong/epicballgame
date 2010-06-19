/*
 *  app.h
 *  epicgame
 *
 *  Created by Keunhong Park on 2/9/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include <SFML/Graphics.hpp>

class App{
private:
	static float			elapsed_time;
	
public:
	static const int		HEIGHT	= 640;
	static const int		WIDTH	= 1024;
	static sf::RenderWindow window;
	static sf::Clock		timer;
	
	static float			get_elapsed_time();
	static void				update_timer();
	static void				init();
};