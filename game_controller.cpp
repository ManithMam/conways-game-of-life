#include "game_controller.hpp"

game_ctr::Game_Controller::Game_Controller() : cycle(0) {}

bool alive_and_2_or_3_neighbours(cell::Cell& cell, int neighbour_amount) {
	if (cell.get_populated() == true) {
		if (neighbour_amount == 2 || neighbour_amount == 3) {			
			return true;
		}		
	}
	return false;
}

void game_ctr::Game_Controller::game_of_life_algo(cell::Cell& cell) {

	int neighbour_amount = cell.get_num_of_neighbours();	

	if (cell.get_populated() == true && neighbour_amount < 2) {		
		cell.set_unpopulated();				
	}

	if (alive_and_2_or_3_neighbours(cell, neighbour_amount)) {		
		return;
	}

	if (cell.get_populated() == true && neighbour_amount > 3) {		
		cell.set_unpopulated();	}

	if (cell.get_populated() == false && neighbour_amount == 3) {		
		cell.set_populated();
	}

}


void game_ctr::Game_Controller::one_cycle(std::vector<std::vector<cell::Cell>>& cell_vec_2d) {

	for (int i = 0; i < cell_vec_2d.size(); i++) {
		for (int t = 0; t < cell_vec_2d[i].size(); t++) {
			game_of_life_algo(cell_vec_2d[i][t]);
		}
	}

	cycle++;
	std::cout << "Cycle: " << this->cycle << '\n';	
}


void game_ctr::Game_Controller::game_cycle(std::vector<std::vector<cell::Cell>>& cell_vec_2d, cell_ctr::Cell_Controller& cell_controller) {

	cell_controller.check_neighbours(cell_vec_2d);

	one_cycle(cell_vec_2d);
	
	
}

void game_ctr::Game_Controller::start_game(std::vector<std::vector<cell::Cell>>& cell_vec_2d, cell_ctr::Cell_Controller& cell_controller) {

	game_cycle(cell_vec_2d, cell_controller);

}