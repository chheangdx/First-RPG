#pragma once
class CSDL_Setup
{
private:
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Event *mainEvent;

public:
	CSDL_Setup(bool *quit, int screen_width, int screen_height);
	~CSDL_Setup(void);

	//getters
	SDL_Renderer* GetRenderer(void);
	SDL_Event* GetMainEvent(void);

	void Begin(void);
	void End(void);
};

