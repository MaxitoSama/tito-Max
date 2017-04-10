#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleFirstScene.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleAudio.h"
#include "ModuleInit.h"


// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleInit::ModuleInit()
{}

ModuleInit::~ModuleInit()
{}

// Load assets
bool ModuleInit::Start()
{
	LOG("Loading space scene");
	background = App->textures->Load("rtype/First_Scene.png");
	LOG("Loading audio scene");
	music = App->music->LoadChunk("rtype/Commando_01_Credit.wav");

	return true;
}

// UnLoad assets
bool ModuleInit::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(background);
	
	return true;
}

// Update: draw background
update_status ModuleInit::Update()
{
	// Move camera forward -----------------------------


	// Draw everything --------------------------------------
	App->render->Blit(background, 0, 0, NULL);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1 && fading==false)
	{
		Mix_PlayChannel(-1,music,0);
		App->fade->FadeToBlack(this, App->scene_space, 2.0f);
		fading = true;
	}

	return UPDATE_CONTINUE;
}