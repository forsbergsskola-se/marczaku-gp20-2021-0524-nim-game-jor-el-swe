/*This source code copyrighted by Lazy Foo' Productions (2004-2020)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>

//Screen dimension constants
//const int SCREEN_WIDTH = 640;
//const int SCREEN_HEIGHT = 480;

const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 840;


//Starts up SDL and creates window
bool init();

//loads media
bool loadMedia();

//frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gXOut = NULL;

int main(int argc, char* args[])
{
	//main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;

	if (!init()) {
		printf("Failed to initialize!\n");
		close();
		return 0;
	}


	//Fill the surface green
	SDL_FillRect(gScreenSurface, NULL, SDL_MapRGB(gScreenSurface->format, 0x00, 0xFF, 0x00));

	if (!loadMedia()) {
		printf("Failed to load media!\n");
		close();
		return 0;
	}



	//main loop
	while (!quit) {
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				quit = true;
			}
		
		//Apply the image
		SDL_BlitSurface(gXOut, NULL, gScreenSurface, NULL);
		//Update the surface
		SDL_UpdateWindowSurface(gWindow);
	}

	close();

	return 0;
}

bool init()
{
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}

	return success;
}

bool loadMedia()
{
	bool success = true;

	//load splash image
	gXOut = SDL_LoadBMP("hello_world.bmp");
	if (gXOut == NULL) {
		printf("Unable to load image %s! SDL Error: %s\n", "hello_world.bmp", SDL_GetError());
		success = false;
	}
	return success;
}

void close()
{
	//Deallocate surface
	SDL_FreeSurface(gXOut);
	gXOut = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}





