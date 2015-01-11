#pragma once
class CSprite
{
private:
	SDL_Texture* image;
	
	SDL_Rect rect;
	SDL_Rect crop;

	SDL_Renderer* renderer;

	int img_width;
	int img_height;

	float X_pos;
	float Y_pos;

	float Origin_X;
	float Origin_Y;

	int frames_x;
	int frames_y;

	int CurrentFrame;
	int animationDelay;
public:
	CSprite(SDL_Renderer* renderer, std::string FilePath, int x, int y, int w, int h, int rows, int columns);
	~CSprite(void);

	void Draw(void);
	void PlayAnimation(int BeginFrame, int EndFrame, int Row, int Speed);

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

