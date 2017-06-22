/*
 * Move.cpp
 *
 *  Created on: Jun 22, 2017
 *      Author: Rossy
 */

#include "Move.h"

Move::Move() {
	Init();
	LoadMedia();
}

void Move::Init() {
	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_JPG);
	window = SDL_CreateWindow("Move picture",
	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH,
			WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}

void Move::LoadMedia() {
	SDL_Surface* firstPicS = IMG_Load("firstPic.jpg");
	if (firstPic == NULL) {
		std::cerr << "Unable to load image " << "firstPic.jpg"
				<< "! SDL_image Error: " << IMG_GetError();
	} else firstPic = SDL_CreateTextureFromSurface(renderer, firstPicS);
	SDL_Surface* secondPicS = IMG_Load("secondPic.jpg");
	if (secondPic == NULL) {
		std::cerr << "Unable to load image " << "secondPic.jpg"
				<< "! SDL_image Error: " << IMG_GetError();
	} else 	secondPic = SDL_CreateTextureFromSurface(renderer, secondPicS);
	SDL_Surface* backgroundS = IMG_Load("background.jpg");
	if (background == NULL) {
		std::cerr << "Unable to load image " << "background.jpg"
				<< "! SDL_image Error: " << IMG_GetError();
	} else 	background = SDL_CreateTextureFromSurface(renderer, backgroundS);
}

void Move::Close() {
	SDL_DestroyTexture(firstPic);
	SDL_DestroyTexture(secondPic);
	SDL_DestroyTexture(background);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

Move::~Move() {
	Close();
}

void Move::MoveRect(SDL_Event* e, SDL_Rect* rect) {
	int step = 5;
	switch (e->key.keysym.sym) {
	case SDLK_UP:
		if (rect->y != 0)
			rect->y -= step;
		break;
	case SDLK_DOWN:
		if (rect->y != WINDOW_HEIGHT - IMAGE_HEIGHT)
			rect->y += step;
		break;
	case SDLK_LEFT:
		if (rect->x != 0)
			rect->x -= step;
		break;
	case SDLK_RIGHT:
		if (rect->x != WINDOW_WIDTH - IMAGE_WIDTH)
			rect->x += step;
		break;
	}
}

bool Move::IsInsideImage(SDL_Event* e, SDL_Rect* rect) {
	if (e->type == SDL_MOUSEBUTTONDOWN) {
		int x;
		int y;
		SDL_GetMouseState(&x, &y);
		if ((x >= rect->x && x <= rect->x + rect->w)
				&& (y >= rect->y && y <= rect->y + rect->h)) {
			return true;
		}
	}
	return false;
}

void Move::SetPosition(int x, int y, SDL_Rect* rect) {
	rect->x = x;
	rect->y = y;
}

void Move::SetImageSize(int w, int h, SDL_Rect* rect) {
	if (w <= WINDOW_WIDTH && h <= WINDOW_HEIGHT) {
		rect->w = w;
		rect->h = h;
	}
}

bool Move::IsLeft(SDL_Rect* rect) {
	if (rect->x == WINDOW_WIDTH - IMAGE_WIDTH) {
		return true;
	}
	return false;
}

bool Move::IsRight(SDL_Rect* rect) {
	if (rect->y == WINDOW_HEIGHT - IMAGE_HEIGHT) {
		return true;
	}
	return false;
}

bool Move::IsUp(SDL_Rect* rect) {
	if (rect->x == 0) {
		return true;
	}
	return false;
}

bool Move::IsDown(SDL_Rect* rect) {
	if (rect->y == 0) {
		return true;
	}
	return false;
}

SDL_Renderer* Move::getRenderer() {
	return renderer;
}
