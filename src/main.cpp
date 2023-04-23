#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <cmath>
#include <chrono>
#include <iostream>

int cur_time(std::chrono::time_point<std::chrono::steady_clock> start)
{
    auto end = std::chrono::steady_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(start-end).count();
}

// sf::Vector2f sincurve(float x, float w, int t)
// {
//     return sf::Vector2f(i, 200+70*sin((float)i/50 -w*t));
// } 

// sf::Vector2f invsincurve(float x, float w, int t)
// {
//     return sf::Vector2f(i, 200+70*sin((float)i/50 -w*t));
// } 

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
    
    window.clear(sf::Color::Black);
    
    sf::Vertex sine[1000];

    int t;
    float w;
    w = 0.08;

    sf::Clock clock;

    t = 0;

    while(t <= 5000)
    {
        sf::sleep(sf::milliseconds(70));
        t = clock.getElapsedTime().asMilliseconds();
        for (int i = 0; i < 500; i++)
        {
            sine[i] = sf::Vertex(sf::Vector2f(i, 200+70*sin((float)i/50 -w*t)), sf::Color(250 - (float)i/2, 0, (float)i/2));
        }
        window.clear(sf::Color::Black);
        window.draw(sine, 500, sf::Lines);
        window.display();        
    }


    window.clear(sf::Color::Black);
    window.draw(sine, 500, sf::Lines);

    window.display();

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


        
    }

    
    return 0;
}