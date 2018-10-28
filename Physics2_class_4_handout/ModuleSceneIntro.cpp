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
	circle = box = rick = NULL;
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

void ModuleSceneIntro::Multiball() {
	int x; int y;
	App->colliders->multiball->GetPosition(x, y);
	for (int i = App->player->current_balls; i <= 3; ++i) {
		
		AddBall(x + 80 + i * 5, y + 70 + i * 10);
		circles.getLast()->data->body->ApplyForceToCenter(b2Vec2(SDL_GetTicks() % 40, SDL_GetTicks() % 10),true);
	}
	App->colliders->spawn_multiball = false;
}

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

	//AddBall(595,910,this);
	
	return ret;
}


// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

void ModuleSceneIntro::AddBall(int x, int y){
	circles.add(App->physics->CreateCircle(x, y, 12));
	circles.getLast()->data->listener = this;
	circles.getLast()->data->body->GetFixtureList()->SetRestitution(0.85f);
	App->player->current_balls++;
}
// Update: draw background
update_status ModuleSceneIntro::Update()
{


	if (App->colliders->spawn_multiball && App->player->current_balls <=4) Multiball();

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

	if (last_collided == bodyB) return;

	if (bodyB == App->colliders->ground) {
		p2List_item<PhysBody*>* c = circles.getFirst();
		while (c != NULL) {
			if (bodyA == c->data) {
				LOG("GROUNDTODELETE");
				//App->player->current_balls--;
				//c->data->body->DestroyFixture(c->data->body->GetFixtureList());
				break;
			}
			c = c->next;
		}
	}
	last_collided = bodyB;
		
	//App->audio->PlayFx(bonus_fx);
}
