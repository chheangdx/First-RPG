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

	void SetX(int x);
	void SetY(int y);
	void SetPosition(int x, int y);

	int GetX(void);
	int GetY(void);
};

