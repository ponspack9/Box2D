
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
	Bonus_AllBoxes_Message.rect = {0,0,573,34};
	Bonus_Loop_Message.rect = {0,0,410,34};
	Game_Over_Message.rect = {0,0,219,31};
	Multiball_Message.rect = { 0,0,222,32 };


	Top_Left_Bonus_Machine.rect = { 0,0,97,109 };
	
	Orange_Active.rect=Green_Active.rect=Blue_Active.rect=Red_Active.rect=Pink_Active.rect=Yellow_Active.rect = { 0,0,79,66 };
	Spring.rect = { 0,0,24,151 };
	Initial_Tube.rect = { 0,0,124,450 };
	KickerActive.rect = { 0,0,85,85 };
	Girl_Active.rect = { 0,0,70,83 };
	Boy_Active.rect = { 0,0,73,78 };
	Green_Box_Active.rect = { 0,0,64,57 };

	Flipper_TopRight.rect=Flipper_TopLeft.rect = { 0,0,54,49 };
	Flipper_MidRight.rect=Flipper_MidLeft.rect = { 0,0,37,61 };
	Flipper_Left.rect=Flipper_Right.rect = { 0,0,71,64 };
	Ball.rect = { 0,0,32,32 };

}


Pinball::~Pinball()
{

}

bool Pinball::Start() {

	LOG("Starting pinball");

	Background.texture = App->textures->Load("Sprites/Background.png");
	Top_Score_Bar.texture = App->textures->Load("Sprites/Top_Score_bar.png");
	Black_Part_Top_Score.texture = App->textures->Load("Sprites/Black_Part_Top_Score.png");

	//Messages
	Bonus_Girl_Boy_Message.texture = App->textures->Load("Sprites/Bonus_Girl_Boy_Message.png");
	Bonus_AllBoxes_Message.texture = App->textures->Load("Sprites/Bonus_AllBoxes_Message.png");
	Bonus_Loop_Message.texture = App->textures->Load("Sprites/Bonus_Loop_Message.png");
	Game_Over_Message.texture = App->textures->Load("Sprites/Game_Over_Message.png");
	Multiball_Message.texture = App->textures->Load("Sprites/Multiball_Message.png");


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
	
	Flipper_MidLeft.texture = App->textures->Load("Sprites/Flipper_MidLeft.png");
	Flipper_MidRight.texture = App->textures->Load("Sprites/Flipper_MidRight.png");
	Flipper_Left.texture=App->textures->Load("Sprites/Flipper_Left.png");
	Flipper_Right.texture = App->textures->Load("Sprites/Flipper_Right.png");
	Flipper_TopLeft.texture = App->textures->Load("Sprites/Flipper_TopLeft.png");
	Flipper_TopRight.texture = App->textures->Load("Sprites/Flipper_TopRight.png");


	Ball.texture = App->textures->Load("Sprites/Ball.png");

	Flipper_MidRight.Position.x = 544;
	Flipper_MidRight.Position.y = 672;
	
	Flipper_MidLeft.Position.x = 120;
	Flipper_MidLeft.Position.y = 536;

	Flipper_TopLeft.Position.x = 402;
	Flipper_TopLeft.Position.y = 239;

	Flipper_TopRight.Position.x = 506;
	Flipper_TopRight.Position.y = 239;
	
	Spring.Position.x = 584;
	Spring.Position.y = 1022;
	Flipper_Right.Position.x = 334;
	Flipper_Right.Position.y = 1088;
	Flipper_Left.Position.x = 205;
	Flipper_Left.Position.y = 1088;


	Velocity_Spring = 0;

	ResetBall();
	return true;
}

update_status Pinball::Update()
{
	//Spring Llogic
	if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_REPEAT) {
		Spring_Activated = true;
		if (Spring.Position.y <= 1140) {
			Velocity_Spring = 4;
			Spring.Position.y += Velocity_Spring;
			Spring_Stop = false;
		}
		else {
			Velocity_Spring = 0;
		}
	}
	if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_UP) {
		Spring_Activated = false;

	}
	 if (!Spring_Activated){
		if (Spring.Position.y >= 1022) {
			Velocity_Spring = -15;
			Spring.Position.y += Velocity_Spring;
		}
		if (Spring.Position.y < 1022) {
			Spring.Position.y = 1022;
			Velocity_Spring = 0;
			Spring_Stop = true;
		}
		
	}


	Draw();
	return UPDATE_CONTINUE;
}

bool Pinball::Draw() {

	bool ret = true;

	App->renderer->Blit(Background.texture, 0, 0, &Background.rect);
	

	

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


	//Flippers
	App->renderer->Blit(Flipper_Left.texture, Flipper_Left.Position.x, Flipper_Left.Position.y, &Flipper_Left.rect);
	App->renderer->Blit(Flipper_Right.texture, Flipper_Right.Position.x, Flipper_Right.Position.y, &Flipper_Right.rect);

	App->renderer->Blit(Flipper_MidLeft.texture, Flipper_MidLeft.Position.x, Flipper_MidLeft.Position.y, &Flipper_MidLeft.rect);
	App->renderer->Blit(Flipper_MidRight.texture, Flipper_MidRight.Position.x, Flipper_MidRight.Position.y, &Flipper_MidRight.rect);

	App->renderer->Blit(Flipper_TopLeft.texture, Flipper_TopLeft.Position.x, Flipper_TopLeft.Position.y, &Flipper_TopLeft.rect);
	App->renderer->Blit(Flipper_TopRight.texture, Flipper_TopRight.Position.x, Flipper_TopRight.Position.y, &Flipper_TopRight.rect);
	
	//Ball
	App->renderer->Blit(Ball.texture, Ball.Position.x, Ball.Position.y, &Ball.rect);

	//Spring
	App->renderer->Blit(Spring.texture,Spring.Position.x, Spring.Position.y, &Spring.rect);

	//Initial_Tube
	App->renderer->Blit(Initial_Tube.texture, 505, 724, &Initial_Tube.rect);

	//Top Score Bar
	App->renderer->Blit(Black_Part_Top_Score.texture, 0, -App->renderer->camera.y, &Black_Part_Top_Score.rect);
	App->renderer->Blit(Bonus_Girl_Boy_Message.texture, 0, (-App->renderer->camera.y)+9, &Bonus_Girl_Boy_Message.rect);
	App->renderer->Blit(Top_Score_Bar.texture, 0, -App->renderer->camera.y, &Top_Score_Bar.rect);
	

	return ret;
}