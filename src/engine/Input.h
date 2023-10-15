// ▼
#ifndef INPUT_H
#define INPUT_H
#include "System.h"

typedef sf::Keyboard::Key Key;

class Input
{
public:

	static bool IsKeyPressed(const Key key);
	static bool IsKeyReleased(const Key key);
	static bool IsMousePressed(const sf::Mouse::Button code);
	static bool IsMouseReleased(const sf::Mouse::Button code);

	Input() = default;
	~Input() = delete;
};

#endif
