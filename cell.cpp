#include <SFML/Graphics.hpp>
#include "cell.hpp"

const sf::Color white = sf::Color(255, 255, 255);
const sf::Color black = sf::Color(0, 0, 0);
const cell::x_y_position default_constructor_position = { 0, 0 };

cell::neigbouring_positions calculate_neighbours(cell::x_y_position cell_pos) {

	cell::x_y_position upper_left = { cell_pos.x_position - 1, cell_pos.y_position - 1 };
	cell::x_y_position upper = { cell_pos.x_position, cell_pos.y_position - 1 };
	cell::x_y_position upper_right = { cell_pos.x_position + 1, cell_pos.y_position - 1 };
	cell::x_y_position left = { cell_pos.x_position - 1, cell_pos.y_position };
	cell::x_y_position right = { cell_pos.x_position + 1, cell_pos.y_position };
	cell::x_y_position lower_left = { cell_pos.x_position - 1, cell_pos.y_position + 1 };
	cell::x_y_position below = { cell_pos.x_position, cell_pos.y_position + 1 };
	cell::x_y_position lower_right = { cell_pos.x_position + 1, cell_pos.y_position + 1 };

	cell::neigbouring_positions neighbours_positions = { upper_left, upper, upper_right, left, right, lower_left, below, lower_right };

	return neighbours_positions;
}

cell::Cell::Cell(x_y_position cell_position_, int window_x_pos, int window_y_pos) : num_of_neigbours(0), populated(false), unpopulated_color(white), populated_color(black), cell_position(cell_position_), screen_x_boundary({window_x_pos, window_x_pos+25}), screen_y_boundary({window_y_pos, window_y_pos+25}), neighbour_positions(calculate_neighbours(cell_position_)) {
			
	this->setFillColor(unpopulated_color);
	this->setOutlineThickness(2.f);
	this->setOutlineColor(black);
	this->setPosition(window_x_pos, window_y_pos);	
	this->setSize(sf::Vector2f(25.f, 25.f));
	
}

cell::Cell::Cell() : num_of_neigbours(0), populated(false), unpopulated_color(white), populated_color(black), cell_position(default_constructor_position), screen_x_boundary({0, 0}), screen_y_boundary({0, 0}),  neighbour_positions(calculate_neighbours(default_constructor_position)) {};

void cell::Cell::set_populated() {
	this->populated = true;	
	this->setFillColor(populated_color);
}

void cell::Cell::set_unpopulated() {
	this->populated = false;
	this->setFillColor(unpopulated_color);
}

void cell::Cell::switch_state() {

	switch (populated) {
		case true:
			this->set_unpopulated();
			break;
		case false:
			this->set_populated();
			break;
	}	
}

void cell::Cell::set_num_of_neighbours(int neigbours) {
	this->num_of_neigbours = neigbours;
}

cell::x_y_position cell::Cell::get_position() {
	return this->cell_position;
}

bool cell::Cell::get_populated() {
	return this->populated;
}

cell::screen_boundary cell::Cell::get_screen_boundary_x() {
	return this->screen_x_boundary;
}

cell::screen_boundary cell::Cell::get_screen_boundary_y() {
	return this->screen_y_boundary;
}

cell::neigbouring_positions cell::Cell::get_neighbour_pos() const{
	return this->neighbour_positions;
}

int cell::Cell::get_num_of_neighbours() {
	return this->num_of_neigbours;
}




