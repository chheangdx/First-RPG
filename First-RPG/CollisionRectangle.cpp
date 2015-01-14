#include "CollisionRectangle.h"


CCollisionRectangle::CCollisionRectangle(void)
{
	OffsetX = 0;
	OffsetY = 0;
}


CCollisionRectangle::~CCollisionRectangle(void)
{
}

CCollisionRectangle::CCollisionRectangle(int x, int y, int w, int h)
{
	OffsetX = x;
	OffsetY = y;
	SetRectangle(0,0,w,h);
}

void CCollisionRectangle::SetRectangle(int x, int y, int w, int h)
{
	CollisionRect.x = x + OffsetX;
	CollisionRect.y = y + OffsetY;
	CollisionRect.w = w;
	CollisionRect.h = h;
}
SDL_Rect CCollisionRectangle::GetRectangle()
{
	return CollisionRect;
}
void CCollisionRectangle::SetX(int offset)
{
	CollisionRect.x = offset + OffsetX;
}
void CCollisionRectangle::SetY(int offset)
{
	CollisionRect.y = offset + OffsetY;
}