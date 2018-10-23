#include "Colliders.h"
#include "ModulePhysics.h"
#include "Globals.h"
#include "ModuleInput.h"
#include "Application.h"



Colliders::Colliders(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	
}


Colliders::~Colliders()
{
}

bool Colliders::Start()
{
	int Initial_Tube[38] = {
		104, 447,
		102, 140,
		93, 102,
		78, 72,
		60, 51,
		39, 32,
		45, 12,
		96, 65,
		120, 131,
		121, 448,
		77, 448,
		74, 138,
		54, 91,
		35, 68,
		24, 59,
		19, 70,
		49, 109,
		62, 140,
		60, 447
	};
	App->physics->CreateChain(507, 720, Initial_Tube, 38);
	return true;
}

update_status Colliders::Update() {
	int x = App->input->GetMouseX();
	int y = App->input->GetMouseY();
	LOG("Mouse [%d,%d]", x, y);
	return UPDATE_CONTINUE;
}
