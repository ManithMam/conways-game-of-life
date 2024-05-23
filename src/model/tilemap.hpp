#ifndef TILEMAP_H
#define TILEMAP_H

#include <vector>
#include "cell.hpp"
#include <SFML/Graphics.hpp>
#include "cell.hpp"
#include <iostream>

namespace tmap {

	class Tilemap {

	private:

		std::vector<std::vector<cell::Cell>> map;

		void load_map_vector(int window_size_x, int window_size_y);

	public:

		void draw_map(sf::RenderTarget& window);
		std::vector<std::vector<cell::Cell>>& get_vector_map();

		Tilemap(sf::RenderTarget& window);
	};

}
#endif