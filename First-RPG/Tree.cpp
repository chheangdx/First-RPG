#include "StdAfx.h"
#include "Tree.h"


Tree::Tree(CSDL_Setup* csdl_setup, float *CameraX, float *CameraY, int x, int y)
{
Trunk = new CSprite(csdl_setup->GetRenderer(), "data/environment/Trunk.png", x, y, 43, 145, 1, 1, CameraX, CameraY);
Crown = new CSprite(csdl_setup->GetRenderer(), "data/environment/Crown.png", x-72, y - 115, 183, 165, 1, 1, CameraX, CameraY);

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
	Crown->Draw();
}
void Tree::DrawTrunk()
{
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