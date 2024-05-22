#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "controller/game_controller.hpp"

namespace app {
	class App {

	private:

		bool set_start;

		void window_close(sf::Event event, sf::RenderWindow& window);
		void mouse_click(sf::Event event, cell_ctr::Cell_Controller& cell_ctr, tmap::Tilemap& map);
		void key_press(sf::Event event, game_ctr::Game_Controller& game_ctr, cell_ctr::Cell_Controller& cell_ctr, tmap::Tilemap& map);

	public:

		sf::RenderWindow window;
		void poll_events(game_ctr::Game_Controller& game_ctr, cell_ctr::Cell_Controller& cell_ctr, tmap::Tilemap& map);
		void game_loop(game_ctr::Game_Controller& game_ctr, cell_ctr::Cell_Controller& cell_ctr, tmap::Tilemap& map);
		void display_screen(tmap::Tilemap& map);

		App();
	};
}