#pragma once

#include "cell_controller.hpp"

namespace game_ctr {
	class Game_Controller {

	private:

		int cycle;

		void game_of_life_algo(cell::Cell& cell);
		void one_cycle(std::vector<std::vector<cell::Cell>>& cell_vec_2d);
		void game_cycle(std::vector<std::vector<cell::Cell>>& cell_vec_2d, cell_ctr::Cell_Controller& cell_controller);

	public:

		void start_game(std::vector<std::vector<cell::Cell>>& cell_vec_2d, cell_ctr::Cell_Controller& cell_controller);
		void reset_cycle();

		Game_Controller();
	};
}


