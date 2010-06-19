#include <SFML/Graphics.hpp>
#include "app.h"
#include "world.h"
#include "entity.h"
#include "ball.h"

#include <string>
#include <sstream>

int main(int argc, char *argv[])
{
	App::init();
	
	Ball ball(1, 1, 1, 0.3);
	
	// Start game loop

	//////DBG
	std::stringstream ss;
	std::string s;
	sf::Clock clk;
	App::window.Clear();
	//////DBG
	
	while (App::window.IsOpened())
	{		
		// Process events
		sf::Event Event;
		while (App::window.GetEvent(Event))
		{
			// Close App::window : exit
			if (Event.Type == sf::Event::Closed)
				App::window.Close();
		}
		
		App::update_timer();
		
		ball.tick();

		// Clear screen
		App::window.Clear();
		
		// Draw apredefined shape
		App::window.Draw(sf::Shape::Circle(ball.get_position().x, ball.get_position().y, ball.get_radius(), sf::Color::Green));
		
		//////////DBG
		ss.clear();
		ss << ball.get_position().y + ball.get_radius();
		ss >> s;
		sf::String text("Velocity: " + s);
		App::window.Draw(text);
		//////////DBG
		
		// Display rendered frame
		App::window.Display();
	}
	return EXIT_SUCCESS;
}