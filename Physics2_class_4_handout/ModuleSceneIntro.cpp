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

	App->renderer->camera.x = 0;
	App->renderer->camera.y = -100;

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

	if(App->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN)
	{
		AddBall(App->input->GetMouseX(), App->input->GetMouseY());
	}

	if(App->input->GetKey(SDL_SCANCODE_2) == KEY_DOWN)
	{
		boxes.add(App->physics->CreateRectangle(App->input->GetMouseX(), App->input->GetMouseY(), 100, 50));
	}
	if (App->input->GetKey(SDL_SCANCODE_F3) == KEY_DOWN)
	{
		App->fade->FadeToBlack(this, App->pinball);
	}
	

	if(App->input->GetKey(SDL_SCANCODE_3) == KEY_DOWN)
	{
		// Pivot 0, 0
		int rick_head[64] = {
			14, 36,
			42, 40,
			40, 0,
			75, 30,
			88, 4,
			94, 39,
			111, 36,
			104, 58,
			107, 62,
			117, 67,
			109, 73,
			110, 85,
			106, 91,
			109, 99,
			103, 104,
			100, 115,
			106, 121,
			103, 125,
			98, 126,
			95, 137,
			83, 147,
			67, 147,
			53, 140,
			46, 132,
			34, 136,
			38, 126,
			23, 123,
			30, 114,
			10, 102,
			29, 90,
			0, 75,
			30, 62
		};

		ricks.add(App->physics->CreateChain(App->input->GetMouseX(), App->input->GetMouseY(), rick_head, 64));
	}
	
	// Prepare for raycast ------------------------------------------------------
	
	iPoint mouse;
	mouse.x = App->input->GetMouseX();
	mouse.y = App->input->GetMouseY();

	// All draw functions ------------------------------------------------------
	p2List_item<PhysBody*>* c = circles.getFirst();

	while(c != NULL)
	{
		int x, y;
		c->data->GetPosition(x, y);
		App->renderer->Blit(App->pinball->Ball.texture, x, y, NULL, 1.0f);
		c = c->next;
	}

	c = boxes.getFirst();

	while(c != NULL)
	{
		int x, y;
		c->data->GetPosition(x, y);
		App->renderer->Blit(box, x, y, NULL, 1.0f, c->data->GetRotation());
		c = c->next;
	}

	c = ricks.getFirst();

	while(c != NULL)
	{
		int x, y;
		c->data->GetPosition(x, y);
		App->renderer->Blit(rick, x, y, NULL, 1.0f, c->data->GetRotation());
		c = c->next;
	}
	
	/*App->pinball->Draw();*/

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
