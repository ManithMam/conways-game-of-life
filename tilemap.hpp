#ifndef TILEMAP_H
#define TILEMAP_H

#include <vector>
#include "cell.hpp"
#include <SFML/Graphics.hpp>
#include "cell.hpp"
#include <iostream>

class Tilemap {

	private:		
		
		std::vector<std::vector<cell::Cell>> map;		

		void load_map_vector(int window_size_x, int window_size_y);		

	public:		

		void draw_map(sf::RenderTarget& window);	

		Tilemap(sf::RenderTarget& window);
};

#endif