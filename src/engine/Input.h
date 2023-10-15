// ▼
#ifndef INPUT_H
#define INPUT_H
#include "System.h"

typedef sf::Keyboard::Key Key;

class Input
{
public:

	static bool KeyPressed(const Key key);
	static bool KeyReleased(const Key key);
	static bool MousePressed(const sf::Mouse::Button code);
	static bool MouseReleased(const sf::Mouse::Button code);

	Input() = default;
	~Input() = delete;
};

#endif
