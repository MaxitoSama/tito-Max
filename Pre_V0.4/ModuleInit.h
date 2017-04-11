#ifndef __MODULEINIT_H__
#define __MODULEINIT_H__

#include "Module.h"
#include "SDL_mixer\include\SDL_mixer.h"
#pragma comment( lib, "SDL_mixer/libx86/SDL2_mixer.lib" )

struct SDL_Texture;

class ModuleInit : public Module
{
public:
	ModuleInit();
	~ModuleInit();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* background = nullptr;
	SDL_Texture* stars = nullptr;
	Mix_Chunk* music = NULL;

	bool fading = false;
};

#endif // __MODULESCENESPACE_H__