#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <cmath>
#include <chrono>
#include <iostream>
#include <trail.hpp>

float a1 = 150;
float a2 = 200;

float w1 = 0.08;
float w2 = 0.16;

float f1 = 0;
float f2 = 0.3;

//  clock.getElapsedTime().asMilliseconds();

Drawer D;
Trail T;

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");

    sf::Clock clock;

    window.clear(sf::Color::Black);    

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }        
        
        window.clear(sf::Color::Black);

        D.update(a1, w1, f1, a2, w2, f2, clock.getElapsedTime().asMilliseconds());
        T.update_vertex(D);
        T.draw(window);
        T.update_trail(clock.getElapsedTime().asMilliseconds());

        window.display();                
    }

    
    return 0;
}