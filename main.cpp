#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<iostream>

#include "cell.hpp"
#include "tilemap.hpp"
#include "cell_controller.hpp"
#include "game_controller.hpp"
#include "app.hpp"


int main() {

	app::App app;

	tmap::Tilemap map(app.window);
	
	cell_ctr::Cell_Controller cell_controller;	

	game_ctr::Game_Controller game_ctr;		

	while (app.window.isOpen())	{			

		app.poll_events(game_ctr, cell_controller, map);		

		app.game_loop(game_ctr, cell_controller, map);

		app.display_screen(map);			
		
	}

	return 0;
}