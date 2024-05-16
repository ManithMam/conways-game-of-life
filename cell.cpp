#include <SFML/Graphics.hpp>
#include "cell.hpp"

const sf::Color white = sf::Color(255, 255, 255);
const sf::Color black = sf::Color(0, 0, 0);
const cell::x_y_position default_constructor_position = { 0, 0 };

cell::Cell::Cell(x_y_position cell_position_, int window_x_pos, int window_y_pos) : populated(false), unpopulated_color(white), populated_color(black), cell_position(cell_position_) {
		
	this->setFillColor(unpopulated_color);
	this->setOutlineThickness(2.f);
	this->setOutlineColor(black);
	this->setPosition(window_x_pos, window_y_pos);	
	this->setSize(sf::Vector2f(25.f, 25.f));
	
}

cell::Cell::Cell() : populated(false), unpopulated_color(white), populated_color(black), cell_position(default_constructor_position) {};

void cell::Cell::set_populated() {
	this->populated = true;	
	this->setFillColor(populated_color);
}

void cell::Cell::set_unpopulated() {
	this->populated = false;
	this->setFillColor(unpopulated_color);
}

cell::x_y_position cell::Cell::get_position() {
	return this->cell_position;
}

bool cell::Cell::get_populated() {
	return this->populated;
}


