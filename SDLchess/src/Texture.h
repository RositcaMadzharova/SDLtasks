#ifndef SRC_TEXTURE_H_
#define SRC_TEXTURE_H_

#include <iostream>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <string>
using namespace std;

class Texture
{
public:
	//The window renderer
	static SDL_Renderer* gRenderer;

	Texture();
	virtual ~Texture();

	int GetWidth() const;
	int GetHeight() const;

	bool LoadFromFile(string path);
	void Render(int x, int y, SDL_Rect* clip = NULL);
	void SetColor(Uint8 red, Uint8 green, Uint8 blue);
	void Free();
private:
	SDL_Texture* m_texture;
	int m_iWidth;
	int m_iHeight;

};

#endif /* SRC_TEXTURE_H_ */
