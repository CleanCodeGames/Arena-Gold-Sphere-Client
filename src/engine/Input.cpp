// ▼
#include "Input.h"

bool Input::KeyPressed(const Key key)
{
	if (System::event->type == sf::Event::KeyPressed)
		if (System::event->key.code == key) return true;
	return false;
}

bool Input::KeyReleased(const Key key)
{
	if (System::event->type == sf::Event::KeyReleased)
		if (System::event->key.code == key) return true;
	return false;
}

bool Input::MousePressed(const sf::Mouse::Button code)
{
	if (System::event->type == sf::Event::MouseButtonPressed)
		if (System::event->key.code == code) return true;
	return false;
}

bool Input::MouseReleased(const sf::Mouse::Button code)
{
	if (System::event->type == sf::Event::MouseButtonReleased)
		if (System::event->key.code == code) return true;
	return false;
}