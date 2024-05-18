#include "cell_controller.hpp"

bool mouse_on_cell(cell::screen_boundary boundary_x, cell::screen_boundary boundary_y, int mouse_pos_x, int mouse_pos_y) {

	bool between_x = false;
	bool between_y = false;

	if (boundary_x.lower <= mouse_pos_x && mouse_pos_x <= boundary_x.upper) {
		between_x = true;
	}

	if (boundary_y.lower <= mouse_pos_y && mouse_pos_y <= boundary_y.upper) {
		between_y = true;
	}

	if (between_x == true && between_y == true) {
		return true;
	}
	else {
		return false;
	}	
}

void cell_ctr::Cell_Controller::cell_click(std::vector<std::vector<cell::Cell>>& cells, int mouse_pos_x, int mouse_pos_y) {

	for (int i = 0; i < cells.size(); i++) {
		for (int t = 0; t < cells[i].size(); t++) {

			cell::screen_boundary boundary_x = cells[i][t].get_screen_boundary_x();
			cell::screen_boundary boundary_y = cells[i][t].get_screen_boundary_y();		

			if (mouse_on_cell(boundary_x, boundary_y, mouse_pos_x, mouse_pos_y)) {
				cells[i][t].set_state();
				std::cout << "Populated: " << cells[i][t].get_populated() << '\n';
			}
		}
	}

}

void calculate_neighbour_count(int& neigbours, std::vector<std::vector<cell::Cell>>& cells, const cell::neigbouring_positions& pos) {	

	if (cells[pos.upper_left.x_position][pos.upper_left.y_position].get_populated() == true) {
		neigbours++;
	}

	if (cells[pos.above.x_position][pos.above.y_position].get_populated() == true) {
		neigbours++;
	}

	if (cells[pos.upper_right.x_position][pos.upper_right.y_position].get_populated() == true) {
		neigbours++;
	}

	if (cells[pos.left.x_position][pos.left.y_position].get_populated() == true) {
		neigbours++;
	}

	if (cells[pos.right.x_position][pos.right.y_position].get_populated() == true) {
		neigbours++;
	}

	if (cells[pos.lower_left.x_position][pos.lower_left.y_position].get_populated() == true) {
		neigbours++;
	}

	if (cells[pos.below.x_position][pos.below.y_position].get_populated() == true) {
		neigbours++;
	}

	if (cells[pos.lower_right.x_position][pos.lower_right.y_position].get_populated() == true) {
		neigbours++;
	}

}


void set_cell_neighbourcount(cell::Cell& cell, std::vector<std::vector<cell::Cell>>& cells, const cell::neigbouring_positions& neighbour_pos) {

	int neighbours_amount = 0;

	if (cell.get_populated() == true) {
		
		calculate_neighbour_count(neighbours_amount, cells, neighbour_pos);

	}

	cell.set_num_of_neighbours(neighbours_amount);

}

void cell_ctr::Cell_Controller::check_neighbours(std::vector<std::vector<cell::Cell>>& cells) {

	for (int i = 0; i < cells.size(); i++) {
		for (int t = 0; t < cells[i].size(); t++) {
			cell::Cell cell = cells[i][t];
			cell::neigbouring_positions neighbour_pos = cell.get_neighbour_pos();	

			set_cell_neighbourcount(cell, cells, neighbour_pos);
		}
	}

}
