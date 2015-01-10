#pragma once
class CSprite
{
private:
	SDL_Texture* image;
	SDL_Rect rect;
	SDL_Renderer* renderer;
public:
	CSprite(SDL_Renderer* renderer, std::string FilePath, int x, int y, int w, int h);
	~CSprite(void);

	void Draw(void);
};

