
#include "Globals.h"
#include "Application.h"
#include "ModuleWindow.h"
#include "Pinball.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModulePhysics.h"


Pinball::Pinball(Application* app, bool start_enabled) : Module(app, start_enabled){

	Background.rect = { 0,0,630,1173};
	Black_Part_Top_Score.rect = Top_Score_Bar.rect = { 0,0,630,50 };

	//Messages 
	Bonus_Girl_Boy_Message.rect = { 0,0,844,34 };

	Top_Left_Bonus_Machine.rect = { 0,0,97,109 };
	
	Orange_Active.rect=Green_Active.rect=Blue_Active.rect=Red_Active.rect=Pink_Active.rect=Yellow_Active.rect = { 0,0,79,66 };
	Spring.rect = { 0,0,24,151 };
	Initial_Tube.rect = { 0,0,124,450 };
	KickerActive.rect = { 0,0,85,85 };
	Girl_Active.rect = { 0,0,70,83 };
	Boy_Active.rect = { 0,0,73,78 };
	Green_Box_Active.rect = { 0,0,64,57 };


}


Pinball::~Pinball()
{
}

bool Pinball::Start() {
	LOG("Starting pinball");
	Background.texture = App->textures->Load("Sprites/Background.png");
	Top_Score_Bar.texture = App->textures->Load("Sprites/Top_Score_bar.png");
	Black_Part_Top_Score.texture = App->textures->Load("Sprites/Black_Part_Top_Score.png");

	Bonus_Girl_Boy_Message.texture = App->textures->Load("Sprites/Bonus_Girl_Boy_Message.png");


	Top_Left_Bonus_Machine.texture = App->textures->Load("Sprites/Top_Left_Bonus_Machine.png");

	Orange_Active.texture = App->textures->Load("Sprites/Orange_Active.png");
	Green_Active.texture = App->textures->Load("Sprites/Green_Active.png");
	Blue_Active.texture = App->textures->Load("Sprites/Blue_Active.png");
	Red_Active.texture = App->textures->Load("Sprites/Red_Active.png");
	Pink_Active.texture = App->textures->Load("Sprites/Pink_Active.png");
	Yellow_Active.texture = App->textures->Load("Sprites/Yellow_Active.png");
	Boy_Active.texture = App->textures->Load("Sprites/Boy_Active.png");
	Girl_Active.texture = App->textures->Load("Sprites/Girl_Active.png");
	Green_Box_Active.texture = App->textures->Load("Sprites/Green_Box_Active.png");
	
	Spring.texture = App->textures->Load("Sprites/Spring.png");


	Initial_Tube.texture = App->textures->Load("Sprites/Initial_Tube.png");
	KickerActive.texture = App->textures->Load("Sprites/Kicker_Active.png");



	Spring.Position.y = 1022;

	Velocity_Spring = 4;

	return true;
}

update_status Pinball::Update()
{
	//Spring Llogic
	if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_REPEAT) {
		
		if (Spring.Position.y <= 1140) {
			Spring_Activated = true;
			Spring.Position.y += 3;
			Velocity_Spring = 4;
		}
	}
	if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_UP) {
		Spring_Activated = false;

	}
	 if (!Spring_Activated){
		if (Spring.Position.y >= 1022) {
			Spring.Position.y -= Velocity_Spring;
			Velocity_Spring += 2;
		}
		if (Spring.Position.y < 1022) {
			Spring.Position.y = 1022;
		}
	}


	Draw();
	return UPDATE_CONTINUE;
}

bool Pinball::Draw() {

	bool ret = true;

	App->renderer->Blit(Background.texture, 0, 0, &Background.rect);
	

	//Spring
	App->renderer->Blit(Spring.texture, 584, Spring.Position.y, &Spring.rect);

	//Box Points activated
	App->renderer->Blit(Boy_Active.texture,54,882,&Boy_Active.rect);
	App->renderer->Blit(Girl_Active.texture, 486,881, &Girl_Active.rect);
	App->renderer->Blit(Yellow_Active.texture, 143, 693, &Yellow_Active.rect);
	App->renderer->Blit(Red_Active.texture, 426, 699, &Red_Active.rect);
	App->renderer->Blit(Pink_Active.texture, 281, 664, &Pink_Active.rect);
	App->renderer->Blit(Orange_Active.texture, 272, 1004, &Orange_Active.rect);
	App->renderer->Blit(Green_Active.texture, 338, 879, &Green_Active.rect);
	App->renderer->Blit(Blue_Active.texture, 204, 881, &Blue_Active.rect);

	//Middle Box Bonus
	App->renderer->Blit(Green_Box_Active.texture, 312, 342, &Green_Box_Active.rect);
	//Top Box Bonus
	App->renderer->Blit(Green_Box_Active.texture, 455, 130, &Green_Box_Active.rect);

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



	//Top Score Bar
	App->renderer->Blit(Black_Part_Top_Score.texture, 0, -App->renderer->camera.y, &Black_Part_Top_Score.rect);
	App->renderer->Blit(Bonus_Girl_Boy_Message.texture, 0, (-App->renderer->camera.y)+9, &Bonus_Girl_Boy_Message.rect);
	App->renderer->Blit(Top_Score_Bar.texture, 0, -App->renderer->camera.y, &Top_Score_Bar.rect);
	

	return ret;
}