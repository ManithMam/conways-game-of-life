#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<iostream>
#include "cell.hpp"
#include "tilemap.hpp"
#include "cell_controller.hpp"

int main() {

	sf::RenderWindow window(sf::VideoMode(1000, 800), "Conway's Game of Life");

	window.setSize(sf::Vector2u(1000, 800));			

	tmap::Tilemap map(window);
	
	cell_ctr::Cell_Controller controller;	

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}				
		}		

		window.display();		

		
		if (event.type == sf::Event::MouseButtonPressed) {
			if (event.mouseButton.button == sf::Mouse::Left) {

				int x = event.mouseButton.x;
				int y = event.mouseButton.y;				

				controller.cell_click(map.get_vector_map(), x, y);
			}
		}
		
		map.draw_map(window);		

	}

	return 0;
}