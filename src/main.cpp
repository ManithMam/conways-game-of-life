#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<iostream>

#include "model/cell.hpp"
#include "model/tilemap.hpp"
#include "controller/cell_controller.hpp"
#include "controller/game_controller.hpp"
#include "app.hpp"


int main() {	

	app::App app;

	tmap::Tilemap map(app.window);

	cell_ctr::Cell_Controller cell_controller;

	game_ctr::Game_Controller game_controller;

	app.print_controls();

	while (app.window.isOpen()) {

		app.poll_events(game_controller, cell_controller, map);

		app.game_loop(game_controller, cell_controller, map);

		app.display_screen(map);

	}

	return 0;
}