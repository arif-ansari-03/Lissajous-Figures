#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <cmath>

class Drawer
{
public:
    sf::Vector2f get_pos() { return pos; }
    sf::Color get_color() { return color; }
    
    void set_pos(sf::Vector2f V) { pos = V; }
    void set_color(sf::Color C) { color = C; }
    
    void update(float a1, float w1, float f1, float a2, float w2, float f2, int t)
    {
        set_pos( sf::Vector2f( (250 + a1 * sin( w1 * t + f1 )) , (250 + a2 * sin( w2 * t + f2 )) ) ) ;
        set_color( sf::Color(c, 0, 255 - c, 255) );

        c = (c+0.005);
        if (c > 255) c = 0;
    }

    Drawer()
    {
        pos = sf::Vector2f();
        color = sf::Color();
        c = 0;
    }

private:
    sf::Vector2f pos;
    sf::Color color;
    float c;
};