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
    if (player.deck.empty()) {
        std::cout << "No Cards in Deck!" << std::endl;
    }
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
            if (auto keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                switch (keyPressed->scancode) {
                case sf::Keyboard::Scancode::Escape:
                    window.close();
                    break;
                case sf::Keyboard::Scancode::D:
                    player.drawHand();
                    std::cout << "\nCurrent Hand\n-----------------" << std::endl;
                    for (auto card : player.currentHand) {
                        std::cout << (std::string)card << std::endl;
                    }
                    if (player.currentHand.empty()) {
                        std::cout << "No Cards in Hand" << std::endl;
                    }
                    break;

                }
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}