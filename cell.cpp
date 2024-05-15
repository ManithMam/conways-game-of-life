#include <SFML/Graphics.hpp>
#include "cell.hpp"

const sf::Color white = sf::Color(255, 255, 255);
const sf::Color black = sf::Color(0, 0, 0);
const sf::Color red = sf::Color(255, 0, 0);
const sf::Color yellow = sf::Color(255, 255, 0);
const cell::x_y_position default_constructor_position = { 0, 0 };

cell::Cell::Cell(x_y_position cell_position_, int window_x_pos, int window_y_pos) : populated(false), color(white), populated_color(yellow), cell_position(cell_position_) {
		
	this->setFillColor(color);
	this->setOutlineThickness(2.f);
	this->setOutlineColor(red);
	this->setPosition(window_x_pos, window_y_pos);	
	this->setSize(sf::Vector2f(25.f, 25.f));
	
}

cell::Cell::Cell() : populated(false), color(white), populated_color(yellow), cell_position(default_constructor_position) {};

void cell::Cell::set_populated() {
	this->populated = true;
	this->color = yellow;
}

void cell::Cell::set_unpopulated() {
	this->populated = false;
	this->color = white;	
}

cell::x_y_position cell::Cell::get_position() {
	return this->cell_position;
}

bool cell::Cell::get_populated() {
	return this->populated;
}


