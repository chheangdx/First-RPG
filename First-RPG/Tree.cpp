#include "StdAfx.h"
#include "Tree.h"


Tree::Tree(CSDL_Setup* csdl_setup, float *CameraX, float *CameraY, int x, int y)
{
	this->CameraX = CameraX;
	this->CameraY = CameraY;

	Trunk = new CSprite(csdl_setup->GetRenderer(), "data/environment/Trunk.png", x, y, 43, 145, 1, 1, CameraX, CameraY, CCollisionRectangle(0,110,43,36));
	Crown = new CSprite(csdl_setup->GetRenderer(), "data/environment/Crown.png", x-72, y - 115, 183, 165, 1, 1, CameraX, CameraY, CCollisionRectangle());

	this->x = x;
	this->y = y;
}


Tree::~Tree(void)
{
	delete Trunk;
	delete Crown;
}

void Tree::DrawCrown()
{
	if(97 < *CameraY + Trunk->GetPositionRect().y) Trunk->Draw();
	Crown->Draw();
}
void Tree::DrawTrunk()
{
	if(103 >= *CameraY + Trunk->GetPositionRect().y)
	Trunk->Draw();
}
int Tree::GetX()
{
	return x;
}
int Tree::GetY()
{
	return y;
}
CSprite* Tree::GetCrown()
{
	return Crown;
}
CSprite* Tree::GetTrunk()
{
	return Trunk;
}