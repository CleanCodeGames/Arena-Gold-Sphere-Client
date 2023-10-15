#include "engine/System.h"
#include "engine/Input.h"

int main()
{
	System::Initialization();
	while (System::window->isOpen())
	{
		System::Update();
		while (System::window->pollEvent(*System::event)) 
		{
			if (Input::KeyPressed(Key::Escape))
				System::window->close();
		}

		System::window->clear();

		System::window->display();
	}
	return 0;
}