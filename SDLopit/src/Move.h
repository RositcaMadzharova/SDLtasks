/*
 * Move.h
 *
 *  Created on: Jun 22, 2017
 *      Author: Rossy
 */

#ifndef MOVE_H_
#define MOVE_H_
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <time.h>
using namespace std;

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;
const int IMAGE_WIDTH = 200;
const int IMAGE_HEIGHT = 200;

class Move {
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	void Init();
	void LoadMedia();
	void Close();

public:
	Move();
	virtual ~Move();
	void MoveRect( SDL_Event*, SDL_Rect* );
	bool IsInsideImage( SDL_Event*, SDL_Rect* );
	void SetPosition( int, int, SDL_Rect* );
	void SetImageSize( int, int, SDL_Rect* );
	bool IsLeft( SDL_Rect* );
	bool IsRight( SDL_Rect* );
	bool IsUp( SDL_Rect* );
	bool IsDown( SDL_Rect* );
	SDL_Texture* firstPic;
	SDL_Texture* secondPic;
	SDL_Texture* background;
	SDL_Renderer* getRenderer();
};

#endif /* MOVE_H_ */
