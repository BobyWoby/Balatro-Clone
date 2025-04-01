#include <SFML/Graphics.hpp>
#include "Player.h"
int main(){   
    Player player = Player();
    sf::RenderWindow window(sf::VideoMode({ 200, 200 }), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    player.score = BigInteger(1000000);
    player.score = player.score * BigInteger(1000000) * BigInteger(1000000);

    std::cout << "Player Score: " << player.score.getString() << std::endl;
    for(auto card : player.deck){
        std::cout << "Rank: " << card.rank << ", Suit: " << card.suit << std::endl;
    }
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