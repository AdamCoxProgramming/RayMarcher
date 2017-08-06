
#include<SDL.h>
#include <SDL_opengl.h>

struct Time
{
	static float GetDeltaTime()
	{
		return deltaTime;
	}

	static void Update()
	{
		long now = SDL_GetTicks();
		//deltatime is in seconds
		if (now > last) {
			deltaTime = ((float)(now - last)) / 1000;
			last = now;
		}
	}

	static float time()
	{
		return SDL_GetTicks();
	}

private:

	static float last;
	static float deltaTime;
	
};