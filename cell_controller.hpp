#ifndef CELL_CONTROLLER_H
#define CELL_CONTROLLER_H

#include "tilemap.hpp"
#include "cell.hpp"

namespace cell_ctr {

	class Cell_Controller {

	private:

	public:
		void cell_click(std::vector<std::vector<cell::Cell>>& cells, int mouse_pos_x, int mouse_pos_y);

	};
}



#endif 
