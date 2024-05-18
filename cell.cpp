#include <SFML/Graphics.hpp>
#include "cell.hpp"

const sf::Color white = sf::Color(255, 255, 255);
const sf::Color black = sf::Color(0, 0, 0);
const cell::x_y_position default_constructor_position = { 0, 0 };

cell::Cell::Cell(x_y_position cell_position_, int window_x_pos, int window_y_pos) : populated(false), unpopulated_color(white), populated_color(black), cell_position(cell_position_), screen_x_boundary({window_x_pos, window_x_pos+25}), screen_y_boundary({window_y_pos, window_y_pos+25}) {
		
	this->setFillColor(unpopulated_color);
	this->setOutlineThickness(2.f);
	this->setOutlineColor(black);
	this->setPosition(window_x_pos, window_y_pos);	
	this->setSize(sf::Vector2f(25.f, 25.f));
	
}

cell::Cell::Cell() : populated(false), unpopulated_color(white), populated_color(black), cell_position(default_constructor_position), screen_x_boundary({0, 0}), screen_y_boundary({0, 0}) {};

void cell::Cell::set_populated() {
	this->populated = true;	
	this->setFillColor(populated_color);
}

void cell::Cell::set_unpopulated() {
	this->populated = false;
	this->setFillColor(unpopulated_color);
}

void cell::Cell::set_state() {	

	switch (populated) {
		case true:
			this->set_unpopulated();
			break;
		case false:
			this->set_populated();
			break;
	}	
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




