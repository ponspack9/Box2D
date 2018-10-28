#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleSceneIntro.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModulePhysics.h"
#include "ModuleFadeToBlack.h"
#include "Pinball.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	circle = box = rick = NULL;
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	Background.rect = { 0,0,629,500 };
	Background.texture = App->textures->Load("Sprites/Main_Menu.png");
	Play.rect = { 0,0,629,500 };
	Play.texture = App->textures->Load("Sprites/Play_Active.png");


	circle = App->textures->Load("pinball/wheel.png"); 
	box = App->textures->Load("pinball/crate.png");
	rick = App->textures->Load("pinball/rick_head.png");
	bonus_fx = App->audio->LoadFx("pinball/bonus.wav");

	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update: draw background
update_status ModuleSceneIntro::Update()
{

	iPoint mouse;
	mouse.x = App->input->GetMouseX();
	mouse.y = App->input->GetMouseY();

	App->renderer->Blit(Background.texture, 0, 0, &Background.rect);

	if ((mouse.x >= 240 && mouse.x <= 240 + 157) && (mouse.y >= 295 && mouse.y <= 295 + 58)) {
		App->renderer->Blit(Play.texture, 0, 0, &Play.rect);
		if (App->input->GetMouseButton(SDL_BUTTON_LEFT) == KEY_DOWN) {
			App->fade->FadeToBlack(this, App->pinball, 2.0f);
		}
	}
	//if(App->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN)
	//{
	//	circles.add(App->physics->CreateCircle(App->input->GetMouseX(), App->input->GetMouseY(), 12));
	//	circles.getLast()->data->listener = this;
	//}


	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody* bodyA, PhysBody* bodyB)
{
	
	//App->audio->PlayFx(bonus_fx);
	
}
