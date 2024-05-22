#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "game_controller.hpp"

class App {

	private:	

		bool set_start;
		
		void window_close(sf::Event event, sf::RenderWindow& window);
		void mouse_click(sf::Event event, cell_ctr::Cell_Controller& cell_ctr, tmap::Tilemap& map);
		void key_press(sf::Event event, Game_Controller& game_ctr, cell_ctr::Cell_Controller& cell_ctr, tmap::Tilemap& map);

	public:
		
		sf::RenderWindow window;
		void poll_events( Game_Controller& game_ctr, cell_ctr::Cell_Controller& cell_ctr, tmap::Tilemap& map);
		void game_loop(Game_Controller& game_ctr, cell_ctr::Cell_Controller& cell_ctr, tmap::Tilemap& map);	
		void display_screen(tmap::Tilemap& map);

		App();
};
