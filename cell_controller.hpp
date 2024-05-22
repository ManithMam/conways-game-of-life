#pragma once

#include "tilemap.hpp"
#include "cell.hpp"
#include <unordered_map>
#include <map>

namespace cell_ctr {

	class Cell_Controller {

	private:

	public:
		void cell_click(std::vector<std::vector<cell::Cell>>& cells, int mouse_pos_x, int mouse_pos_y);
		void check_neighbours(std::vector<std::vector<cell::Cell>>& cells);
	};
}

