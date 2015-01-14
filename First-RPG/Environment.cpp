#include "StdAfx.h"
#include "Environment.h"


CEnvironment::CEnvironment(CSDL_Setup* csdl_setup, int screen_width,int screen_height, float *CameraX, float *CameraY)
{
	this->CameraX = CameraX;
	this->CameraY = CameraY;

	for(int i=0; i<4; i++){
		for(int j=0; j<7; j++){
			grass[i][j] = new CSprite(csdl_setup->GetRenderer(), "data/environment/grass.bmp", screen_width*i, screen_height*j, 600, 500, 1, 1, CameraX, CameraY, CCollisionRectangle());
		}
	}

	Mode = GamePlay;

	this->csdl_setup = csdl_setup;
	OnePressed = false;
	
	LoadFromFile();
}


CEnvironment::~CEnvironment(void)
{
	for(int i=0; i<4; i++){
		for(int j=0; j<7; j++){
			delete grass[i][j];
		}
	}
	for(std::vector<Tree*>::iterator i=trees.begin(); i != trees.end(); ++i){
		delete (*i);
	}
	trees.clear();
}

void CEnvironment::DrawBack()
{
	for(int i=0; i<4; i++){
		for(int j=0; j<7; j++){
			grass[i][j]->Draw();
		}
	}
	for(std::vector<Tree*>::iterator i=trees.begin(); i != trees.end(); ++i){
		(*i)->DrawTrunk();
	}
}
void CEnvironment::DrawFront()
{
	for(std::vector<Tree*>::iterator i=trees.begin(); i != trees.end(); ++i){
		(*i)->DrawCrown();
	}
}

void CEnvironment::Update()
{	
	if(csdl_setup->GetMainEvent()->type == SDL_KEYDOWN){
		if(!OnePressed && csdl_setup->GetMainEvent()->key.keysym.sym == SDLK_F12)
		{
			if(Mode == LevelCreation) Mode = GamePlay;
			else if(Mode == GamePlay) Mode = LevelCreation;
			OnePressed = true;
		}
	}
	if(csdl_setup->GetMainEvent()->type == SDL_KEYUP){
		if(OnePressed && csdl_setup->GetMainEvent()->key.keysym.sym == SDLK_F12)
		{
			OnePressed = false;
		}
	}

	if(Mode == LevelCreation){
		if(csdl_setup->GetMainEvent()->type == SDL_KEYDOWN)
		{
			if(!OnePressed && csdl_setup->GetMainEvent()->key.keysym.sym == SDLK_F11)
				{
					SaveToFile();
					OnePressed = true;
				}
			if(!OnePressed && csdl_setup->GetMainEvent()->key.keysym.sym == SDLK_F1)
				{
					trees.push_back(new Tree(csdl_setup, CameraX, CameraY,  - (int) *CameraX + 275, - (int) *CameraY + 90));
					OnePressed = true;
				}
			if(!OnePressed && csdl_setup->GetMainEvent()->key.keysym.sym == SDLK_F2)
			{
				{
					if(trees.size() > 0) 
					{
						int count = 0;
						for(std::vector<Tree*>::iterator i = trees.begin(); i!=trees.end(); ++i)
						{
							if(count == trees.size()) delete (*i);
							count++;
						}
						trees.pop_back();
					}
					OnePressed = true;
				}
			}
		}
		if(csdl_setup->GetMainEvent()->type == SDL_KEYUP)
		{
			if(OnePressed && csdl_setup->GetMainEvent()->key.keysym.sym == SDLK_F1 )
			{
				OnePressed = false;
			}
			if(OnePressed && csdl_setup->GetMainEvent()->key.keysym.sym == SDLK_F2 )
			{
				OnePressed = false;
			}
			if(OnePressed && csdl_setup->GetMainEvent()->key.keysym.sym == SDLK_F11 )
			{
				OnePressed = false;
			}
		} 
	}
}

void CEnvironment::SaveToFile()
{
	std::ofstream LoadedFile;
	LoadedFile.open("data/LevelLayout.txt");
	LoadedFile << "---====BEGIN_TREE====---\n";
	for(std::vector<Tree*>::iterator i=trees.begin(); i != trees.end(); ++i){
		LoadedFile << "x: " << (*i)->GetX() << "\ty: " << (*i)->GetY() << std::endl;
	}	
	LoadedFile << "---====END_TREE====---\n";
	std::cout << "SAVED!\n";
	LoadedFile.close();
}

void CEnvironment::LoadFromFile()
{
	std::ifstream LoadedFile("data/LevelLayout.txt");

	std::string line;

	enum ObjectType{
		TypeNone,
		TypeTree
	};

	int CurrentType = TypeNone;

	if(LoadedFile.is_open())
	{
		while(LoadedFile.good()){
		std::getline(LoadedFile, line);
			if(line == "---====BEGIN_TREE====---")
			{
				CurrentType = TypeTree;
			}
			else if(line == "---====END_TREE====---")
			{
				CurrentType = TypeNone;
			}else
			{
				if(CurrentType == TypeTree)
				{
					std::istringstream iss(line);

					int TempX = 0;
					int TempY = 0;
					std::string PrevWord;

					while(iss)
					{
						std::string word;
						iss >>word;
						if(PrevWord == "x:")
						{
							TempX = atoi(word.c_str());
						}
						else if(PrevWord == "y:")
						{
							TempY = atoi(word.c_str());
							trees.push_back(new Tree(csdl_setup, CameraX, CameraY, TempX, TempY));
						}
						PrevWord = word;
					}
				}
			}
		}
		LoadedFile.close();
		std::cout << "Level Loaded! \n";
	}else std::cout << "File could not be Open: data/LevelLayout.txt \n";
}
std::vector<Tree*> CEnvironment::GetTrees()
{
	return trees;
}