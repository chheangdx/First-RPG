#pragma once
class CSprite
{
private:
	SDL_Texture* image;
	SDL_Rect rect;
	SDL_Renderer* renderer;

	float X_pos;
	float Y_pos;

	float Origin_X;
	float Origin_Y;
public:
	CSprite(SDL_Renderer* renderer, std::string FilePath, int x, int y, int w, int h);
	~CSprite(void);

	void Draw(void);

	void SetX(float x);
	void SetY(float y);
	void SetPosition(float x, float y);

	float GetX(void);
	float GetY(void);

	void SetOrigin(float x, float y);

	int GetWidth(void);
	void SetWidth(int w);
	int GetHeight(void);
	void SetHeight(int h);
};

