#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"
#include "SDL_mixer\include\SDL_mixer.h"
#pragma comment( lib, "SDL_mixer/libx86/SDL2_mixer.lib" )

struct SDL_Texture;

class ModulePlayer : public Module
{
public:
	ModulePlayer();
	~ModulePlayer();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	Mix_Chunk* music = NULL;
	Animation* current_animation = nullptr;
	Animation idle;
	Animation idle2;
	Animation up;
	Animation down;
	Animation left;
	Animation right;
	Animation idleUP;
	Animation idleDown;
	Animation idleRight;
	Animation idleLeft;
	Animation rightUP;
	Animation leftUP;
	Animation rightDOWN;
	Animation leftDOWN;
	Collider* playercoll;
	enum LastDirection { UP, DOWN, LEFT, RIGHT };
	LastDirection player_last_direction;
	iPoint position;
};

#endif