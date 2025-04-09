#include <SFML/Graphics.hpp>
#include "Player.h"
int main() {
	Player player = Player();
	sf::RenderWindow window(sf::VideoMode({ 200, 200 }), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	player.score = BigInteger(1000000);
	player.score = player.score * BigInteger(1000000) * BigInteger(1000000) * BigInteger(1000000) * BigInteger(1000000);

	std::cout << "Player Score: " << player.score.getString() << std::endl;
	for (auto card : player.deck) {
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
				case sf::Keyboard::Scancode::S:
					player.logScore();
					break;
				case sf::Keyboard::Scancode::J:
					std::cout << "\nJokers\n---------\n";
					for (auto joker : player.jokers) {
						std::cout << (std::string)joker << std::endl;;
					}
					break;
				case sf::Keyboard::Scancode::Num1:
					player.selectCard(0);
					break;
				case sf::Keyboard::Scancode::Num2:
					player.selectCard(1);
					break;
				case sf::Keyboard::Scancode::Num3:
					player.selectCard(2);
					break;
				case sf::Keyboard::Scancode::Num4:
					player.selectCard(3);
					break;
				case sf::Keyboard::Scancode::Num5:
					player.selectCard(4);
					break;
				case sf::Keyboard::Scancode::Num6:
					player.selectCard(5);
					break;
				case sf::Keyboard::Scancode::Num7:
					player.selectCard(6);
					break;
				case sf::Keyboard::Scancode::Num8:
					player.selectCard(7);
					break;
				case sf::Keyboard::Scancode::Num9:
					player.selectCard(8);
					break;
				case sf::Keyboard::Scancode::Num0:
					player.selectCard(9);
					break;
				}
			}
		}

		window.clear();
		window.draw(shape);
		window.display();
	}
}