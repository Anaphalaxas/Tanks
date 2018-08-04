#pragma once
#include <allegro5/allegro.h>
class Display
{
private:
	static Display *instance;
	ALLEGRO_DISPLAY *display;

public:
	Display();
	~Display();
	static Display* get_instance();
	static void destroy();
	ALLEGRO_DISPLAY *get_display();
	void initialize_display();
	void update_display();
	static const int SCREEN_WIDTH = 640;
	static const int SCREEN_HEIGHT = 520;
	static const int PLAYABLE_WIDTH = 640;
	static const int PLAYABLE_HEIGHT = 480;
	static const int FPS = 60;
};
