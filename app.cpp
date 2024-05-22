#include "app.hpp"

const unsigned int window_size_x = 1000;
const unsigned int window_size_y = 800;

App::App() : window(sf::VideoMode(window_size_x, window_size_y), "Conway's Game of Life", sf::Style::Close), set_start(false) {}


void App::window_close(sf::Event event, sf::RenderWindow& window) {

	if (event.type == sf::Event::Closed) {
		window.close();
	}

}

void App::mouse_click(sf::Event event, cell_ctr::Cell_Controller& cell_ctr, tmap::Tilemap& map) {

	if (event.type == sf::Event::MouseButtonPressed) {
		if (event.mouseButton.button == sf::Mouse::Left) {

			int x = event.mouseButton.x;
			int y = event.mouseButton.y;

			cell_ctr.cell_click(map.get_vector_map(), x, y);
		}
	}
}

void App::key_press(sf::Event event, Game_Controller& game_ctr, cell_ctr::Cell_Controller& cell_ctr, tmap::Tilemap& map) {	

	if (event.type == sf::Event::KeyReleased) {
		if (event.key.scancode == sf::Keyboard::Scan::Q) {
			std::cout << "Q!" << '\n';
			this->set_start = true;
		}
	}

	if (event.type == sf::Event::KeyReleased) {
		if (event.key.scancode == sf::Keyboard::Scan::W) {
			std::cout << "W!" << '\n';
			this->set_start = false;
			
		}
	}
		
}

void App::poll_events(Game_Controller& game_ctr, cell_ctr::Cell_Controller& cell_ctr, tmap::Tilemap& map) {	

	sf::Event event;

	while (window.pollEvent(event)) {

		key_press(event, game_ctr, cell_ctr, map);

		window_close(event, window);

		mouse_click(event, cell_ctr, map);
				
	}

}

void App::game_loop(Game_Controller& game_ctr, cell_ctr::Cell_Controller& cell_ctr, tmap::Tilemap& map) {
	if (this->set_start) {
		game_ctr.start_game(map.get_vector_map(), cell_ctr);
	}
}

void App::display_screen(tmap::Tilemap& map) {
	map.draw_map(window);
	window.display();
}



