#include "KeyboardPlayer.h"
#include "math.h"
//#include <SFML/Keyboard.hpp>
#include <SFML/Graphics.hpp>

KeyboardPlayer::KeyboardPlayer(void)
{

}

void KeyboardPlayer::Play(double time, TankControl* control) {
	double forward = 0, sideways = 0, turn = 0, lift = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::RControl)) control->ShootGun();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) control->ShootCannon();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) turn -= 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) turn += 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) forward += 25;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) forward -= 25;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) sideways += 25;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) sideways -= 25;
	control->SetEngines(forward+sideways, forward-sideways, turn, lift);
}

KeyboardPlayer::~KeyboardPlayer(void)
{

}
