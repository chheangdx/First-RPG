#include "Sprite.h"


CSprite::CSprite(SDL_Renderer* renderer, std::string FilePath, int x, int y, int w, int h, int rows, int columns, float *CameraX, float *CameraY, CCollisionRectangle collision_rect)
{
	this->renderer = renderer;
	this->CameraX = CameraX;
	this->CameraY = CameraY;

	image = NULL;
	image = IMG_LoadTexture(this->renderer, FilePath.c_str());
	if(image == NULL)
	{
		std::cout << "Texture not created from " << FilePath.c_str() << "!" << std::endl;
	}

	//location to start drawing
	rect.x = x;
	rect.y = y;
	//width and height to draw
	rect.w = w;
	rect.h = h;

	SDL_QueryTexture(image, NULL, NULL, &img_width, &img_height);

	frames_x = columns;
	frames_y = rows;

	camera.x = rect.x + (int)*CameraX;
	camera.y = rect.y + (int)*CameraY;
	camera.w = rect.w;
	camera.h = rect.h;

	crop.x = 0;
	crop.y = 0;
	crop.w = img_width/frames_x;
	crop.h = img_height/frames_y;

	X_pos = (float) x;
	Y_pos = (float) y;

	Origin_X = 0;
	Origin_Y = 0;

	CurrentFrame = 0;
	animationDelay = 0;

	this->collision_rect = collision_rect;
}


CSprite::~CSprite(void)
{
	SDL_DestroyTexture(image);

}

void CSprite::Draw(void)
{
	camera.x = rect.x + (int) *CameraX;
	camera.y = rect.y + (int) *CameraY;

	collision_rect.SetX(camera.x);
	collision_rect.SetY(camera.y);

	SDL_RenderCopy(renderer, image, &crop, &camera);
}

void CSprite::DrawSteady()
{
	SDL_RenderCopy(renderer, image, &crop, &rect);
}

void CSprite::SetX(float x)
{
	X_pos = x;
	rect.x = int(X_pos - Origin_X);
}
void CSprite::SetY(float y)
{
	Y_pos = y;
	rect.y = int(Y_pos - Origin_Y);
}
void CSprite::SetPosition(float x, float y)
{
	X_pos = x;
	Y_pos = y;

	rect.x = int(X_pos - Origin_X);
	rect.y = int(Y_pos - Origin_Y);
}

float CSprite::GetX(void)
{
	return X_pos;
}
float CSprite::GetY(void)
{
	return Y_pos;
}

void CSprite::SetOrigin(float x, float y)
{
	Origin_X = x;
	Origin_Y = y;

	SetPosition(GetX(), GetY());
}

int CSprite::GetHeight()
{
	return rect.h;
}

int CSprite::GetWidth()
{
	return rect.w;
}
void CSprite::SetHeight(int h)
{
	rect.h = h;
}

void CSprite::SetWidth(int w)
{
	rect.w = w;
}

void CSprite::PlayAnimation(int BeginFrame, int EndFrame, int Row, int Speed)
{
	if(animationDelay + Speed < SDL_GetTicks()){
		if(BeginFrame != EndFrame){
			if(EndFrame <= CurrentFrame) CurrentFrame = BeginFrame;
			else CurrentFrame++;
		}else CurrentFrame = BeginFrame;

		crop.x = CurrentFrame * img_width/frames_x;
		crop.y = Row * (img_height/frames_y);
		crop.w = img_width/frames_x;
		crop.h = img_height/frames_y;

		animationDelay = SDL_GetTicks();
	}
}
bool CSprite::isColliding(CCollisionRectangle theCollider)
{
	return !(collision_rect.GetRectangle().x + collision_rect.GetRectangle().w < theCollider.GetRectangle().x
				|| collision_rect.GetRectangle().y + collision_rect.GetRectangle().h < theCollider.GetRectangle().y
				|| collision_rect.GetRectangle().x > theCollider.GetRectangle().x + theCollider.GetRectangle().w
				|| collision_rect.GetRectangle().y > theCollider.GetRectangle().y + theCollider.GetRectangle().h);
}
CCollisionRectangle CSprite::GetCollisionRect()
{
	return collision_rect;
}