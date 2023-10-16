// ▼
#include "System.h"

unique_ptr<Resources>		 System::resources;
unique_ptr<sf::RenderWindow> System::window;
unique_ptr<sf::Event>		 System::event;
unique_ptr<sf::View>		 System::camera;
unique_ptr<sf::Clock>		 System::clock;
sf::Vector2i				 System::resolution;
sf::Vector2f				 System::camera_position;
sf::Vector2f				 System::cursor_world;
sf::Vector2f				 System::cursor_window;
float						 System::time_elapsed;
entt::registry				 System::registry;


void System::Initialization()
{
	resources = make_unique<Resources>();
	window = make_unique<sf::RenderWindow>();
	event = make_unique<sf::Event>();
	camera = make_unique<sf::View>();
	clock = make_unique<sf::Clock>();
	resolution.x = sf::VideoMode::getDesktopMode().width;
	resolution.y = sf::VideoMode::getDesktopMode().height;
	window->create(sf::VideoMode(resolution.x, resolution.y), L"Арена золотой сферы", sf::Style::Close, sf::ContextSettings(4, 4, 8));
	camera->reset(sf::FloatRect(0, 0, static_cast<float>(resolution.x), static_cast<float>(resolution.y)));
	camera->setCenter(0, 0);
	camera_position = camera->getCenter();
	window->setView(*camera);
	window->setMouseCursorVisible(true);
	//window->setFramerateLimit(60);
	srand(static_cast<uint>(::time(0)));
	clock->restart();
}

void System::Update()
{
	time_elapsed = clock->getElapsedTime().asSeconds();
	clock->restart();
	camera_position = camera->getCenter();
	cursor_world = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
	cursor_window = v2f(sf::Mouse::getPosition(*window));
	
}