// ▼
#ifndef SYSTEM_H
#define SYSTEM_H
#include "Resources.h"

class System
{
private:

	static void Initialization();
	static void Update();
	friend int main();

	System() = delete;
	~System() = delete;

public:

	static unique_ptr<Resources> resources;
	static unique_ptr<sf::RenderWindow> window;
	static unique_ptr<sf::View> camera;
	static unique_ptr<sf::Clock> clock;
	static unique_ptr<sf::Event> event;	
	static v2i resolution;
	static v2f camera_position;
	static float time_elapsed;
	static v2f cursor_world;
	static v2f cursor_window;
	static entt::registry registry;
};

#endif