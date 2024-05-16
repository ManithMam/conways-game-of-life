#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<iostream>
#include "cell.hpp"
#include "tilemap.hpp"

int main() {

	sf::RenderWindow window(sf::VideoMode(1000, 800), "Conway's Game of Life");
	sf::Vector2u window_size = window.getSize();		

	tmap::Tilemap map(window);

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
		
		map.draw_map(window);		

	}

	return 0;
}