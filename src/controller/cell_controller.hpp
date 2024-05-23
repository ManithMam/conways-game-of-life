#pragma once

#include "../model/tilemap.hpp"
#include "../model/cell.hpp"
#include <unordered_map>
#include <map>

namespace cell_ctr {

	class Cell_Controller {

	private:
		bool mouse_on_cell(cell::screen_boundary boundary_x, cell::screen_boundary boundary_y, int mouse_pos_x, int mouse_pos_y);
		void calculate_neighbour_count(int& neigbours, const cell::neigbouring_positions& pos, std::map<cell::x_y_position, cell::Cell, cell::x_y_comp>& populated_cells);
		std::map<cell::x_y_position, cell::Cell, cell::x_y_comp> get_populated_cells(std::vector<std::vector<cell::Cell>>& cells);
		void set_cell_neighbourcount(cell::Cell& cell, std::vector<std::vector<cell::Cell>>& cells, const cell::neigbouring_positions& neighbour_pos, std::map<cell::x_y_position, cell::Cell, cell::x_y_comp>& populated_cells);

	public:
		void cell_click(std::vector<std::vector<cell::Cell>>& cells, int mouse_pos_x, int mouse_pos_y);
		void check_neighbours(std::vector<std::vector<cell::Cell>>& cells);
	};
}
