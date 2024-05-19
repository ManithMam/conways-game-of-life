#ifndef CELL_H
#define CELL_H

#include <SFML/Graphics.hpp>
#include <vector>

namespace cell {

	struct x_y_position {
		int x_position;
		int y_position;		
	};

	struct x_y_comp
	{
		bool operator() (x_y_position a, x_y_position b) const
		{
			return std::make_pair(a.x_position, a.y_position) > std::make_pair(b.x_position, b.y_position);
		}
	};

	struct screen_boundary {
		int lower;
		int upper;
	};

	struct neigbouring_positions {

		cell::x_y_position upper_left;
		cell::x_y_position above;
		cell::x_y_position upper_right;
		cell::x_y_position left;
		cell::x_y_position right;
		cell::x_y_position lower_left;
		cell::x_y_position below;
		cell::x_y_position lower_right;

	};


	class Cell : public sf::RectangleShape {

	private:

		bool populated;
		sf::Color unpopulated_color;
		sf::Color populated_color;
		x_y_position cell_position;
		screen_boundary screen_x_boundary;
		screen_boundary screen_y_boundary;
		int num_of_neigbours;
		neigbouring_positions neighbour_positions;

			

	public:
		
		void set_populated();
		void set_unpopulated();
		void set_num_of_neighbours(int neigbours);
		void switch_state();

		x_y_position get_position();
		bool get_populated();
		
		screen_boundary get_screen_boundary_x();
		screen_boundary get_screen_boundary_y();
		neigbouring_positions get_neighbour_pos() const;
		int get_num_of_neighbours();

		Cell(x_y_position cell_position_, int window_x_pos, int window_y_pos);
		Cell();

	};
}

#endif

