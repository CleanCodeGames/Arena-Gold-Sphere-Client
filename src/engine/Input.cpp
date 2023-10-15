// ▼
#include "Input.h"

bool Input::IsKeyPressed(const Key key)
{
	if (System::event->type == sf::Event::KeyPressed)
		if (System::event->key.code == key) return true;
	return false;
}

bool Input::IsKeyReleased(const Key key)
{
	if (System::event->type == sf::Event::KeyReleased)
		if (System::event->key.code == key) return true;
	return false;
}

bool Input::IsMousePressed(const sf::Mouse::Button code)
{
	if (System::event->type == sf::Event::MouseButtonPressed)
		if (System::event->key.code == code) return true;
	return false;
}

bool Input::IsMouseReleased(const sf::Mouse::Button code)
{
	if (System::event->type == sf::Event::MouseButtonReleased)
		if (System::event->key.code == code) return true;
	return false;
}