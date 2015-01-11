#include "StdAfx.h"
#include "Main.h"


CMain::CMain(int screen_width,int screen_height)
{
	quit = false;

	csdl_setup = new CSDL_Setup(&quit, screen_width, screen_height);
	grass = new CSprite(csdl_setup->GetRenderer(), "data/grass.bmp", 0, 0, 600, 500, 1, 1);
	bob = new CSprite(csdl_setup->GetRenderer(), "data/tom.png", 300, 250, 100, 120, 4, 4);
	bob->SetOrigin(bob->GetWidth()/2.0f, (float) bob->GetHeight());

	timeCheck = SDL_GetTicks();
	MouseX = 0;
	MouseY = 0;

	follow = false;
	distance = 0;
}


CMain::~CMain(void)
{
	delete csdl_setup;
	delete grass;
	delete bob;
}

void CMain::GameLoop(void)
{
	while(!quit && csdl_setup->GetMainEvent()->type != SDL_QUIT){
		csdl_setup->Begin();
		SDL_GetMouseState(&MouseX, &MouseY);

		grass->Draw();
		bob->Draw();

		float angle = atan2(Follow_point_y - bob->GetY(), Follow_point_x - bob->GetX());
		angle = angle * (180 / 3.14) + 180;

		distance = GetDistance(bob->GetX(), bob->GetY(), (float) Follow_point_x, (float) Follow_point_y);

		if((int)distance != 0){
		if(angle > 45 && angle <= 135)
		{
			//up
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
		}
		if(csdl_setup->GetMainEvent()->type == SDL_MOUSEBUTTONDOWN
			|| csdl_setup->GetMainEvent()->type == SDL_MOUSEMOTION)
		{
			if(csdl_setup->GetMainEvent()->button.button == SDL_BUTTON_LEFT)
			{
				Follow_point_x = MouseX;
				Follow_point_y = MouseY;
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
		csdl_setup->End();
	}
}

float CMain::GetDistance(float x1, float y1, float x2, float y2)
{
	float DifferenceX = x1 - x2;
	float DifferenceY = y1 - y2;
	float distance = sqrt(DifferenceX * DifferenceX + DifferenceY * DifferenceY);
	return distance;
}