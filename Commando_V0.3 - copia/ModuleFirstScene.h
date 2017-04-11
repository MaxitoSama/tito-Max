#ifndef __MODULEFIRSTSCENE_H__
#define __MODULEFIRSTSCENE_H__

#include "Module.h"
#include "Animation.h"
#include "SDL_mixer\include\SDL_mixer.h"
#pragma comment( lib, "SDL_mixer/libx86/SDL2_mixer.lib" )

struct SDL_Texture;

class ModuleFirstScene : public Module
{
public:
	ModuleFirstScene();
	~ModuleFirstScene();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	
	SDL_Texture* background = nullptr;
	SDL_Texture* stars = nullptr;
	SDL_Texture* palm_trees_texture = nullptr;
	Mix_Music* music = NULL;
	Animation palm_trees;
	Collider* mur1=nullptr;
	Collider* murpro = nullptr;
	bool fading = false;
};

#endif // __MODULEFIRSTSCENE_H__