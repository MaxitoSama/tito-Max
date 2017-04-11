#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleFirstScene.h"
#include "ModuleInit.h"
#include "ModuleEndScene.h"
#include "ModuleSecondScene.h"
#include "ModuleAudio.h"


// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleEndScene::ModuleEndScene()
{}

ModuleEndScene::~ModuleEndScene()
{}

// Load assets
bool ModuleEndScene::Start()
{
	LOG("Loading space scene");

	background = App->textures->Load("rtype/Last_Scene.png");
	music = App->music->Load("rtype/Commando_08_Name_Entry.ogg");
	Mix_PlayMusic(music, -1);

	return true;
}

// UnLoad assets
bool ModuleEndScene::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(background);
	App->player->Disable();

	return true;
}

// Update: draw background
update_status ModuleEndScene::Update()
{

	// Draw everything --------------------------------------
	App->render->Blit(background, 0, 0, NULL);

	if (App->input->keyboard[SDL_SCANCODE_C] == 1 && fading == false)
	{
		App->fade->FadeToBlack(this, App->scene_start, 2.0f);
		fading = true;
	}

	return UPDATE_CONTINUE;
}




