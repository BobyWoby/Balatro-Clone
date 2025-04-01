#include <SFML/Graphics.hpp>
#include "Player.h"
int main(){   
    Player player = Player();
    sf::RenderWindow window(sf::VideoMode({ 200, 200 }), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    player.score = BigInteger(100000);
    player.score = player.score * BigInteger(5);
    std::cout << "Player Score: " << player.score.getString();

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}