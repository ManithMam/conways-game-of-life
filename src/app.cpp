#include "app.hpp"

namespace app_constants {
	const unsigned int window_size_x = 1000;
	const unsigned int window_size_y = 800;
}

app::App::App() : window(sf::VideoMode(app_constants::window_size_x, app_constants::window_size_y), "Conway's Game of Life", sf::Style::Close), set_start(false) {}


void app::App::window_close(sf::Event event, sf::RenderWindow& window) {

	if (event.type == sf::Event::Closed) {
		window.close();
	}

}

void app::App::mouse_click(sf::Event event, cell_ctr::Cell_Controller& cell_ctr, tmap::Tilemap& map) {

	if (event.type == sf::Event::MouseButtonPressed) {
		if (event.mouseButton.button == sf::Mouse::Left) {

			int x = event.mouseButton.x;
			int y = event.mouseButton.y;

			cell_ctr.cell_click(map.get_vector_map(), x, y);
		}
	}
}

void app::App::key_press(sf::Event event, game_ctr::Game_Controller& game_ctr, cell_ctr::Cell_Controller& cell_ctr, tmap::Tilemap& map) {

	if (event.type == sf::Event::KeyReleased) {
		if (event.key.scancode == sf::Keyboard::Scan::Q) {
			std::cout << "Start simulation!" << '\n';
			this->set_start = true;			
		}
	}

	if (event.type == sf::Event::KeyReleased) {
		if (event.key.scancode == sf::Keyboard::Scan::W) {
			std::cout << "Stop simulation!" << '\n';
			this->set_start = false;
			game_ctr.reset_cycle();
		}
	}

}

void app::App::poll_events(game_ctr::Game_Controller& game_ctr, cell_ctr::Cell_Controller& cell_ctr, tmap::Tilemap& map) {

	sf::Event event;

	while (window.pollEvent(event)) {

		key_press(event, game_ctr, cell_ctr, map);

		window_close(event, window);

		mouse_click(event, cell_ctr, map);

	}

}

void app::App::game_loop(game_ctr::Game_Controller& game_ctr, cell_ctr::Cell_Controller& cell_ctr, tmap::Tilemap& map) {
	if (this->set_start) {
		game_ctr.start_game(map.get_vector_map(), cell_ctr);
	}
}

void app::App::display_screen(tmap::Tilemap& map) {
	map.draw_map(window);
	window.display();
}

void app::App::print_controls() {
	std::cout << "Controls" << '\n';
	std::cout << "------------------" << '\n';
	std::cout << "Use your mouse to populate the cells by clicking on empty cells." << '\n';
	std::cout << "Start simulation: Q" << '\n';
	std::cout << "Stop simulation: W" << '\n';
}
