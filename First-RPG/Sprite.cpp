#include "StdAfx.h"
#include "Sprite.h"


CSprite::CSprite(SDL_Renderer* renderer, std::string FilePath, int x, int y, int w, int h)
{
	this->renderer = renderer;

	image = NULL;
	image = IMG_LoadTexture(this->renderer, FilePath.c_str());
	if(image == NULL)
	{
		std::cout << "Texture not created from " << FilePath.c_str() << "!" << std::endl;
	}

	//location to start drawing
	rect.x = x;
	rect.y = y;
	//width and height to draw
	rect.w = w;
	rect.h = h;
}


CSprite::~CSprite(void)
{
	SDL_DestroyTexture(image);

}

void CSprite::Draw(void)
{
	SDL_RenderCopy(renderer, image, NULL, &rect); //put image with parameters rect onto renderer
}