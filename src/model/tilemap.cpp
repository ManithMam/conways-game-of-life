#include "tilemap.hpp"
#include <iostream>

void tmap::Tilemap::load_map_vector(int window_size_x, int window_size_y) {
	
	cell::x_y_position cell_position;	

	int cell_pos_x = 0;	

	for (int x = 0; x < window_size_x; x += 25) {	

		int cell_pos_y = 0;
		cell_position.x_position = cell_pos_x;
		
		cell_pos_x++;

		std::vector<cell::Cell> cell_vector;
		this->map.push_back(cell_vector);

		for (int y = 0; y < window_size_y; y += 25) {
			
			cell_position.y_position = cell_pos_y;
			cell::Cell cell_(cell_position, x, y);
			
			this->map[cell_position.x_position].push_back(cell_);
			
			cell_pos_y++;		
			
		}
	}
}

tmap::Tilemap::Tilemap(sf::RenderTarget& window) :  map() {

	load_map_vector(window.getSize().x, window.getSize().y);
}

void tmap::Tilemap::draw_map(sf::RenderTarget& window) {

	for(int x = 0; x < this->map.size(); x++) {
		for (int y = 0; y < this->map[x].size(); y++) {
			window.draw(this->map[x][y]);
		}
	} 
}

std::vector<std::vector<cell::Cell>>& tmap::Tilemap::get_vector_map() {
	return this->map;
}
