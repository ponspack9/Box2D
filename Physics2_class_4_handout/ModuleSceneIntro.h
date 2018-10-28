#pragma once
#include "Module.h"
#include "p2List.h"
#include "p2Point.h"
#include "Globals.h"

class PhysBody;

class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro(Application* app, bool start_enabled = true);
	~ModuleSceneIntro();

	void Multiball();

	bool Start();
	update_status Update();
	bool CleanUp();
	void AddBall(int x, int y, Module* callback = nullptr);
	void OnCollision(PhysBody* bodyA, PhysBody* bodyB);

public:
	p2List<PhysBody*> circles;
	p2List<PhysBody*> boxes;
	p2List<PhysBody*> ricks;

	SDL_Texture* circle;
	SDL_Texture* box;
	SDL_Texture* rick;
	uint bonus_fx;

	PhysBody* last_collided;
};
