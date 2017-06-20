//============================================================================
// Name        : SDLchess.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include "Texture.h"
using namespace std;


const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;

const int RECT_WIDTH = 100;
const int RECT_HEIGHT = 100;

bool init();
bool loadMedia();
void close();

SDL_Window* gWindow = NULL;
SDL_Texture* gTexture = NULL;
SDL_Renderer* gRenderer = NULL;

SDL_Rect gSpriteClips[12];
Texture gSpriteSheetTexture;


int main( int argc, char* args[] ) {

	if (!init()) {
		printf("Failed to initialize!\n");
	} else {
		if (!loadMedia()) {
			printf("Failed to load media!\n");
		} else {
			bool quit = false;

			SDL_Event e;

			while (!quit) {

				while (SDL_PollEvent(&e) != 0) {

					if (e.type == SDL_QUIT) {
						quit = true;
					}

				}

				SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 0);
				SDL_RenderClear(gRenderer);


				SDL_Rect fillRect = { 0, 0, 100, 100 };
				SDL_SetRenderDrawColor(gRenderer, 0, 0, 200, 0);
				SDL_RenderFillRect(gRenderer, &fillRect);

				int row = 0, column = 0, x = 0;
				SDL_Rect rect, darea;


				SDL_RenderGetViewport(gRenderer, &darea);

				for (; row < 8; row++) {
					column = row % 2;
					x = column;
					for (; column < 4 + (row % 2); column++) {
						SDL_SetRenderDrawColor(gRenderer, 0, 0, 150, 0xFF);

						rect.w = darea.w / 8;
						rect.h = darea.h / 8;
						rect.x = x * rect.w;
						rect.y = row * rect.h;
						x = x + 2;
						SDL_RenderFillRect(gRenderer, &rect);
					}
					int offsetX = 100;
							for (int i = 0; i < 8; i++) {
								gSpriteSheetTexture.Render(i * offsetX, 100, &gSpriteClips[5]);
								gSpriteSheetTexture.Render(i * offsetX, 600, &gSpriteClips[11]);
							}
							gSpriteSheetTexture.Render(0, 0, &gSpriteClips[4]);
							gSpriteSheetTexture.Render(700, 0, &gSpriteClips[4]);
							gSpriteSheetTexture.Render(0, 700, &gSpriteClips[10]);
							gSpriteSheetTexture.Render(700, 700, &gSpriteClips[10]);

							gSpriteSheetTexture.Render(100, 0, &gSpriteClips[3]);
							gSpriteSheetTexture.Render(600, 0, &gSpriteClips[3]);
							gSpriteSheetTexture.Render(100, 700, &gSpriteClips[9]);
							gSpriteSheetTexture.Render(600, 700, &gSpriteClips[9]);

							gSpriteSheetTexture.Render(200, 0, &gSpriteClips[2]);
							gSpriteSheetTexture.Render(500, 0, &gSpriteClips[2]);
							gSpriteSheetTexture.Render(200, 700, &gSpriteClips[8]);
							gSpriteSheetTexture.Render(500, 700, &gSpriteClips[8]);

							gSpriteSheetTexture.Render(300, 0, &gSpriteClips[1]);
							gSpriteSheetTexture.Render(400, 0, &gSpriteClips[0]);
							gSpriteSheetTexture.Render(300, 700, &gSpriteClips[7]);
							gSpriteSheetTexture.Render(400, 700, &gSpriteClips[6]);

				}
				SDL_RenderPresent(gRenderer);
			}
		}
	}

	close();

	return 0;
}

bool init() {

	bool success = true;

	if (SDL_Init( SDL_INIT_VIDEO) < 0) {
		cout << "SDL could not initialize! SDL Error: %s\n" << SDL_GetError()
				<< endl;
		success = false;
	} else {

		if (!SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
			cout << "Warning: Linear texture filtering not enabled!" << endl;
		}

		gWindow = SDL_CreateWindow("Chess", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL) {
			cerr << "Window could not be created! SDL Error: %s"
					<< SDL_GetError() << endl;
			success = false;
		} else {

			gRenderer = SDL_CreateRenderer(gWindow, -1,
					SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL) {
				cerr << "Renderer could not be created! SDL Error: %s"
						<< SDL_GetError() << endl;
				success = false;
			} else {

				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags)) {
					cerr
							<< "SDL_image could not initialize! SDL_image Error: %s"
							<<
							IMG_GetError() << endl;
					success = false;

				}
			}
		}
	}

	return success;
}


bool loadMedia() {

	bool success = true;

	gSpriteSheetTexture.gRenderer = gRenderer;
	if (!gSpriteSheetTexture.LoadFromFile("Chess_Pieces_Sprite02.png")) {
		cout << "Failed to load sprite sheet texture!\n";
		success = false;
	} else {
		int offsetX = 100;
		for (int i = 0; i < 6; i++) {
			gSpriteClips[i].x = i * offsetX;
			gSpriteClips[i].y = 0;
			gSpriteClips[i].w = 100;
			gSpriteClips[i].h = 100;
		}

		for (int i = 0; i < 6; i++) {
			gSpriteClips[i + 6].x = i * offsetX;
			gSpriteClips[i + 6].y = 100;
			gSpriteClips[i + 6].w = 100;
			gSpriteClips[i + 6].h = 100;
		}

	}

	return success;
}


void close() {

	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	IMG_Quit();
	SDL_Quit();
}
