#pragma once
#include "StdAfx.h"
#include "CollisionRectangle.h"

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
	unsigned int animationDelay;

	SDL_Rect camera;
	float *CameraX;
	float *CameraY;

	CCollisionRectangle collision_rect;
public:
	CSprite(SDL_Renderer* renderer, std::string FilePath, int x, int y, int w, int h, int rows, int columns, float *CameraX, float *CameraY, CCollisionRectangle collision_rect);
	~CSprite(void);

	void Draw(void);
	void DrawSteady();
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

	bool isColliding(CCollisionRectangle theCollider);
	CCollisionRectangle GetCollisionRect();
};

