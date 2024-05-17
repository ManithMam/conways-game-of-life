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