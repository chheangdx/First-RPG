#include "StdAfx.h"
#include "MainCharacter.h"


#define StartX 300
#define StartY 250

MainCharacter::MainCharacter(CSDL_Setup* csdl_setup, int *MouseX, int *MouseY, float *CameraX, float *CameraY, CEnvironment* environment)
{
	this->environment = environment;
	this->csdl_setup = csdl_setup;
	this->MouseX = MouseX;
	this->MouseY = MouseY;
	this->CameraX = CameraX;
	this->CameraY = CameraY;

	bob = new CSprite(csdl_setup->GetRenderer(), "data/tom.png", StartX, StartY, 100, 120, 4, 4, CameraX, CameraY, CCollisionRectangle(0,0, 100, 120));
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
	bob->DrawSteady();
}

void MainCharacter::UpdateAnimation()
{
	if((int)distance > 0){
		angle = atan2(Follow_point_y - *CameraY, Follow_point_x - *CameraX);
		angle = angle * (180 / 3.14f) + 180;
	}

	if(angle > 45 && angle <= 135)
	{
		//down
		if(follow)bob->PlayAnimation(0, 3, 0, 200);
		else bob->PlayAnimation(1, 1, 0, 200);
	}
	else if(angle > 125 && angle <= 225)
	{
		//left
		if(follow)bob->PlayAnimation(0, 3, 1, 200);
		else bob->PlayAnimation(1, 1, 1, 200);
	}
	else if(angle > 225 && angle <= 315)
	{
		//up
		if(follow) bob->PlayAnimation(0, 3, 3, 200);
		else bob->PlayAnimation(1, 1, 3, 200);
	}
	else if((angle > 315 && angle <= 360) || (angle >= -45 && angle <=45))
	{
		//right
		if(follow)bob->PlayAnimation(0 , 3, 2, 200);
		else bob->PlayAnimation(1, 1, 2, 200);
	}
}
//
void MainCharacter::UpdateControls()
{
	distance = GetDistance(*CameraX, *CameraY, (float) Follow_point_x, (float) Follow_point_y);

	if(csdl_setup->GetMainEvent()->type == SDL_MOUSEBUTTONDOWN
		|| csdl_setup->GetMainEvent()->type == SDL_MOUSEMOTION)
	{
		if(csdl_setup->GetMainEvent()->button.button == SDL_BUTTON_LEFT)
		{
			Follow_point_x = (int) *CameraX - *MouseX + StartX;
			Follow_point_y = (int) *CameraY - *MouseY + StartY;
			follow = true;
		}
	}

	if(timeCheck+10 < SDL_GetTicks() && follow) //update every 500 ms
	{
		if((int)distance > 0){
			bool colliding = false;
			for(int i=0; i<environment->GetTrees().size(); i++){
				if(bob->isColliding(environment->GetTrees()[i]->GetTrunk()->GetCollisionRect()))
				{
					if(*CameraX > Follow_point_x) *CameraX = *CameraX + 5;
					if(*CameraX < Follow_point_x) *CameraX = *CameraX - 5;
					if(*CameraY > Follow_point_y) *CameraY = *CameraY + 5;
					if(*CameraY < Follow_point_y) *CameraY = *CameraY - 5;
					Follow_point_x = *CameraX;
					Follow_point_y = *CameraY;
					distance = 0;
					follow = false;
					colliding = true;
				}
			}
			if(!colliding){
				if(*CameraX != Follow_point_x){
					*CameraX = *CameraX - ((*CameraX-Follow_point_x)/distance) * 2.5f;
				}
				if(*CameraY != Follow_point_y){
					*CameraY = *CameraY - ((*CameraY-Follow_point_y)/distance) * 2.5f;
				}
			}
		}else follow = false;

		timeCheck = SDL_GetTicks();
	}
}


void MainCharacter::Update()
{			
	UpdateAnimation();
	UpdateControls();
}