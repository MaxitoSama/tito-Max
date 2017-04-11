#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 14

class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleRender;
class ModuleParticles;
class ModuleFirstScene;
class ModuleSecondScene;
class ModuleEndScene;
class ModulePlayer;
class ModuleFadeToBlack;
class ModuleInit;
class ModuleAudio;
class ModuleCollision;
class ModuleEnemies;
class Module;

// TODO 1: Create an intro scene with rtype/intro.png that then fades to ModuleSpaceScene

class Application
{
public:

	Module* modules[NUM_MODULES];
	ModuleWindow* window;
	ModuleRender* render;
	ModuleInput* input;
	ModuleTextures* textures;
	ModuleFirstScene* scene_space;
	ModuleSecondScene* scene_map2;
	ModuleEndScene* end_scene;
	ModuleCollision* collision;
	ModulePlayer* player;
	ModuleFadeToBlack* fade;
	ModuleParticles* particles;
	ModuleInit* scene_start;
	ModuleAudio* music;
	ModuleEnemies* enemies;

public:

	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();

};

// Global var made extern for Application ---
extern Application* App;

#endif // __APPLICATION_H__