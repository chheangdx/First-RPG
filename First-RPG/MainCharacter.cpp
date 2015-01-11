#include "StdAfx.h"
#include "MainCharacter.h"


MainCharacter::MainCharacter(CSDL_Setup* csdl_setup, int *MouseX, int *MouseY)
{
	this->csdl_setup = csdl_setup;
	this->MouseX = MouseX;
	this->MouseY = MouseY;

	bob = new CSprite(csdl_setup->GetRenderer(), "data/tom.png", 300, 250, 100, 120, 4, 4);
	bob->SetOrigin(bob->GetWidth()/2.0f, (float) bob->GetHeight());

	timeCheck = SDL_GetTicks();

	follow = false;
	distance = 0;
	angle = 3 * 3.14f / 2; //initially facing down
}


MainCharacter::~MainCharacter(void)
{
	delete bob;
}

float MainCharacter::GetDistance(float x1, float y1, float x2, float y2)
{
	float DifferenceX = x1 - x2;
	float DifferenceY = y1 - y2;
	float distance = sqrt(DifferenceX * DifferenceX + DifferenceY * DifferenceY);
	return distance;
}

void MainCharacter::Draw()
{
	bob->Draw();
}
void MainCharacter::Update()
{			
	if((int)distance != 0){
		angle = atan2(Follow_point_y - bob->GetY(), Follow_point_x - bob->GetX());
		angle = angle * (180 / 3.14f) + 180;
	}
	distance = GetDistance(bob->GetX(), bob->GetY(), (float) Follow_point_x, (float) Follow_point_y);

	if(angle > 45 && angle <= 135)
	{
		//up h
		if(follow) bob->PlayAnimation(0, 3, 3, 200);
		else bob->PlayAnimation(1, 1, 3, 200);
	}
	else if(angle > 125 && angle <= 225)
	{
		//right
		if(follow)bob->PlayAnimation(0 , 3, 2, 200);
		else bob->PlayAnimation(1, 1, 2, 200);
	}
	else if(angle > 225 && angle <= 315)
	{
		//down
		if(follow)bob->PlayAnimation(0, 3, 0, 200);
		else bob->PlayAnimation(1, 1, 0, 200);
	}
	else if((angle > 315 && angle <= 360) || (angle >= -45 && angle <=45))
	{
		//left
		if(follow)bob->PlayAnimation(0, 3, 1, 200);
		else bob->PlayAnimation(1, 1, 1, 200);
	}

	if(csdl_setup->GetMainEvent()->type == SDL_MOUSEBUTTONDOWN
		|| csdl_setup->GetMainEvent()->type == SDL_MOUSEMOTION)
	{
		if(csdl_setup->GetMainEvent()->button.button == SDL_BUTTON_LEFT)
		{
			Follow_point_x = *MouseX;
			Follow_point_y = *MouseY;
			follow = true;
		}
	}

	if(timeCheck+10 < SDL_GetTicks() && follow) //update every 500 ms
	{
		if((int)distance != 0){
			if(bob->GetX() != Follow_point_x){
				bob->SetX(bob->GetX() - ((bob->GetX()-Follow_point_x)/distance) * 1.5f);
			}
			if(bob->GetY() != Follow_point_y){
				bob->SetY(bob->GetY() - ((bob->GetY()-Follow_point_y)/distance) * 1.5f);
			}
		}else follow = false;

		timeCheck = SDL_GetTicks();
	}
}