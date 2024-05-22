#include "cell_controller.hpp"

bool cell_ctr::Cell_Controller::mouse_on_cell(cell::screen_boundary boundary_x, cell::screen_boundary boundary_y, int mouse_pos_x, int mouse_pos_y) {

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
				cells[i][t].switch_state();
				std::cout << "Cell: " << cells[i][t].get_position().x_position << "|" << cells[i][t].get_position().y_position << " is populated: " << cells[i][t].get_populated() << '\n';
				
			}
		}
	}

}

void cell_ctr::Cell_Controller::calculate_neighbour_count(int& neigbours, const cell::neigbouring_positions& pos, std::map<cell::x_y_position, cell::Cell, cell::x_y_comp>& populated_cells) {

	//upper_left
	if (populated_cells.find({ pos.upper_left.x_position, pos.upper_left.y_position }) != populated_cells.end()) {		
		neigbours++;
	}

	//above
	if (populated_cells.find({ pos.above.x_position, pos.above.y_position }) != populated_cells.end()) {		
		neigbours++;
	}

	//upper_right
	if (populated_cells.find({ pos.upper_right.x_position, pos.upper_right.y_position }) != populated_cells.end()) {		
		neigbours++;
	}

	//left
	if (populated_cells.find({ pos.left.x_position, pos.left.y_position }) != populated_cells.end()) {		
		neigbours++;
	}

	//right
	if (populated_cells.find({ pos.right.x_position, pos.right.y_position }) != populated_cells.end()) {		
		neigbours++;
	}

	//lower_left
	if (populated_cells.find({ pos.lower_left.x_position, pos.lower_left.y_position }) != populated_cells.end()) {		
		neigbours++;
	}

	//below
	if (populated_cells.find({ pos.below.x_position, pos.below.y_position }) != populated_cells.end()) {		
		neigbours++;
	}

	//lower_right
	if (populated_cells.find({ pos.lower_right.x_position, pos.lower_right.y_position }) != populated_cells.end()) {		
		neigbours++;
	}
}


void cell_ctr::Cell_Controller::set_cell_neighbourcount(cell::Cell& cell, std::vector<std::vector<cell::Cell>>& cells, const cell::neigbouring_positions& neighbour_pos, std::map<cell::x_y_position, cell::Cell, cell::x_y_comp>& populated_cells) {

	int neighbours_amount = 0;	

	calculate_neighbour_count(neighbours_amount, neighbour_pos, populated_cells);
	
	cell.set_num_of_neighbours(neighbours_amount);
	
}

std::map<cell::x_y_position, cell::Cell, cell::x_y_comp> cell_ctr::Cell_Controller::get_populated_cells(std::vector<std::vector<cell::Cell>>& cells) {

	std::map<cell::x_y_position, cell::Cell, cell::x_y_comp> populated_cells;

	for (std::vector<cell::Cell> cell_vector : cells) {
		for (cell::Cell cell : cell_vector) {
			if (cell.get_populated() == true) {
				populated_cells[cell.get_position()] = cell;
			}
		}
	}

	return populated_cells;
}

void cell_ctr::Cell_Controller::check_neighbours(std::vector<std::vector<cell::Cell>>& cells) {

	std::map<cell::x_y_position, cell::Cell, cell::x_y_comp> populated_cells;

	populated_cells = get_populated_cells(cells);

	for (int i = 0; i < cells.size(); i++) {
		for (int t = 0; t < cells[i].size(); t++) {
			cell::Cell& cell = cells[i][t];
			cell::neigbouring_positions neighbour_pos = cell.get_neighbour_pos();	

			set_cell_neighbourcount(cell, cells, neighbour_pos, populated_cells);
		}
	}

}
