#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <cmath>
#include <chrono>
#include <iostream>
#include <drawer.hpp>

class Trail
{
public:
    sf::Vertex operator[](int i) { return V[i]; }
    
    void update_vertex(Drawer D)
    {
        V[index].position = D.get_pos();
        V[index].color = D.get_color();
        index = (index + 1) % N;
    }

    void update_trail(int t)
    {
        if (t%8 == 0)
        for (int i = 0; i < N; i++)
        {
            if (V[i].color.a - 0.5 < 0) V[i].color.a = 0;
            else V[i].color.a -= 0.5;
        }        
    }

    void draw(sf::RenderWindow &window) { window.draw(V, N, sf::Points); } 

    Trail()
    {
        index = 0;
        
        for (int i = 0; i < N; i++)
        {
            V[i].position = sf::Vector2f(i , 250);
            V[i].color = sf::Color(0, 255, 0, 0);
        }
    }

private:

    sf::Vertex V[10000];
    int index;
    int N = 10000;

};
