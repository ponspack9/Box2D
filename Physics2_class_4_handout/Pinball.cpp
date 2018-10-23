
#include "Globals.h"
#include "Application.h"
#include "ModuleWindow.h"
#include "Pinball.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"


Pinball::Pinball(Application* app, bool start_enabled) : Module(app, start_enabled){

	Background.rect = { 0,0,630,1173};
	Orange_Active.rect=Green_Active.rect=Blue_Active.rect=Red_Active.rect=Pink_Active.rect=Yellow_Active.rect = { 0,0,79,66 };
	Spring.rect = { 0,0,24,151 };
	Initial_Tube.rect = { 0,0,124,450 };
	KickerActive.rect = { 0,0,85,85 };
}


Pinball::~Pinball()
{
}

bool Pinball::Start() {
	LOG("Starting pinball");
	Background.texture = App->textures->Load("Sprites/Background.png");

	Orange_Active.texture = App->textures->Load("Sprites/Orange_Active.png");
	Green_Active.texture = App->textures->Load("Sprites/Green_Active.png");
	Blue_Active.texture = App->textures->Load("Sprites/Blue_Active.png");
	Red_Active.texture = App->textures->Load("Sprites/Red_Active.png");
	Pink_Active.texture = App->textures->Load("Sprites/Pink_Active.png");
	Yellow_Active.texture = App->textures->Load("Sprites/Yellow_Active.png");
	Spring.texture = App->textures->Load("Sprites/Spring.png");
	Initial_Tube.texture = App->textures->Load("Sprites/Initial_Tube.png");
	KickerActive.texture = App->textures->Load("Sprites/Kicker_Active.png");
	return true;
}

update_status Pinball::Update()
{
	//if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT)

	/*
	int speed = 3;

	if(App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT)
	App->renderer->camera.y += speed;

	if(App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT)
	App->renderer->camera.y -= speed;

	if(App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
	App->renderer->camera.x += speed;

	if(App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
	App->renderer->camera.x -= speed;
	*/

	/*if (App->input->GetKey(SDL_SCANCODE_F3) == KEY_DOWN)
	{
		App->fade->FadeToBlack(App->pinball, App->pinball);
	}*/
	Draw();
	return UPDATE_CONTINUE;
}

bool Pinball::Draw() {

	bool ret = true;

	App->renderer->Blit(Background.texture, 0, 0, &Background.rect);

	//Spring
	App->renderer->Blit(Spring.texture, 584, 1022, &Spring.rect);

	//Box Points activated
	App->renderer->Blit(Yellow_Active.texture, 143, 693, &Yellow_Active.rect);
	App->renderer->Blit(Red_Active.texture, 426, 699, &Red_Active.rect);
	App->renderer->Blit(Pink_Active.texture, 281, 664, &Pink_Active.rect);
	App->renderer->Blit(Orange_Active.texture, 272, 1004, &Orange_Active.rect);
	App->renderer->Blit(Green_Active.texture, 338, 879, &Green_Active.rect);
	App->renderer->Blit(Blue_Active.texture, 204, 881, &Blue_Active.rect);

	//Initial_Tube
	App->renderer->Blit(Initial_Tube.texture, 505, 724, &Initial_Tube.rect);
	
	//kikers 
	//9
	App->renderer->Blit(KickerActive.texture, 105, 406, &KickerActive.rect);
	//10
	App->renderer->Blit(KickerActive.texture, 105, 350, &KickerActive.rect);
	//11
	App->renderer->Blit(KickerActive.texture, 121, 244, &KickerActive.rect);
	//12
	App->renderer->Blit(KickerActive.texture, 383, 57, &KickerActive.rect);
	//1
	App->renderer->Blit(KickerActive.texture, 501, 57, &KickerActive.rect);
	//3
	App->renderer->Blit(KickerActive.texture, 521, 294, &KickerActive.rect);
	//5
	App->renderer->Blit(KickerActive.texture, 521, 528, &KickerActive.rect);
	//7
	App->renderer->Blit(KickerActive.texture, 121, 616, &KickerActive.rect);

	return ret;
}