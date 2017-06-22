//============================================================================
// Name        : SDLopit.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Move.h"
using namespace std;

int main(int args, char* argc[]) {


	Move move;
	SDL_Rect rect = { 200, 200, IMAGE_WIDTH, IMAGE_HEIGHT };

	bool quit = false;
		bool click = false;
		SDL_Event e;

		while (!quit)
		{
			while (SDL_PollEvent(&e) != 0)
			{
				switch (e.type)
				{
				case SDL_QUIT:
					quit = true;
					break;
				case SDL_MOUSEBUTTONDOWN:
				{
					if (move.IsInsideImage(&e, &rect))
					{
						click = true;
					}
					case SDL_KEYDOWN:
					if (click)
					{
						move.MoveRect(&e, &rect);
					}
					break;
				}
				}

			}

			SDL_RenderClear(move.getRenderer());
			SDL_RenderCopy(move.getRenderer(), move.background, NULL, NULL);

			if (move.IsLeft(&rect) == true){

			} else if (move.IsRight(&rect) == true) {
				SDL_RenderCopy(move.getRenderer(), move.secondPic, 0, &rect);
			}
			else if (move.IsUp(&rect) == true)
			{
				SDL_RenderCopyEx(move.getRenderer(), move.firstPic, 0, &rect,
						0, NULL, SDL_FLIP_HORIZONTAL);
			}
			else if (move.IsDown(&rect) == true)
			{
				SDL_RenderCopyEx(move.getRenderer(), move.firstPic, 0, &rect,
						30.00, NULL, SDL_FLIP_NONE);
			}
			else
			{
				SDL_RenderCopy(move.getRenderer(), move.firstPic, 0, &rect);
			}
			SDL_RenderPresent(move.getRenderer());
		}




	return 0;
}
