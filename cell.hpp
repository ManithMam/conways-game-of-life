#ifndef CELL_H
#define CELL_H

#include <SFML/Graphics.hpp>
#include <vector>

namespace cell {

	struct x_y_position {
		int x_position;
		int y_position;
	};

	class Cell : public sf::RectangleShape {

	private:

		bool populated;
		sf::Color color;
		sf::Color populated_color;
		x_y_position cell_position;

		void set_populated();
		void set_unpopulated();

	public:

		x_y_position get_position();
		bool get_populated();

		Cell(x_y_position cell_position_, int window_x_pos, int window_y_pos);
		Cell();

	};
}

#endif

