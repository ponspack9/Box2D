#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleSceneIntro.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModulePhysics.h"
#include "ModuleFadeToBlack.h"
#include "Colliders.h"
#include "Pinball.h"
#include "ModulePlayer.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}


// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;
	App->renderer->camera.y = 0;
	Background.rect = { 0,0,629,500 };
	Background.texture = App->textures->Load("Sprites/Main_Menu.png");
	Play.rect = { 0,0,629,500 };
	Play.texture = App->textures->Load("Sprites/Play_Active.png");


	//AddBall(595,910,this);
	
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



	//if(App->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN)
	//{
	//	AddBall(App->input->GetMouseX(), App->input->GetMouseY());
	//}

	// Prepare for raycast ------------------------------------------------------
	
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

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody* bodyA, PhysBody* bodyB)
{

}
