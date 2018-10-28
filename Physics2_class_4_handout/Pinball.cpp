
#include "Globals.h"
#include "Application.h"
#include "ModuleWindow.h"
#include "Pinball.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneIntro.h"
#include "ModulePhysics.h"
#include "ModuleAudio.h"
#include "Colliders.h"
#include "ModulePlayer.h"
#include "ModuleFonts.h"


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
	Angle_Right = 0;
	Angle_Left = 0;
}


Pinball::~Pinball()
{

}

bool Pinball::CleanUp() {

	App->textures->Unload(Background.texture);
	App->textures->Unload(Top_Score_Bar.texture);
	App->textures->Unload(Black_Part_Top_Score.texture);
	App->textures->Unload(Bonus_Girl_Boy_Message.texture);
	App->textures->Unload(Bonus_AllBoxes_Message.texture);
	App->textures->Unload(Bonus_Loop_Message.texture);
	App->textures->Unload(Game_Over_Message.texture);
	App->textures->Unload(Multiball_Message.texture);
	App->textures->Unload(Top_Left_Bonus_Machine.texture);
	App->textures->Unload(Orange_Active.texture);
	App->textures->Unload(Green_Active.texture);
	App->textures->Unload(Blue_Active.texture);
	App->textures->Unload(Red_Active.texture);
	App->textures->Unload(Pink_Active.texture);
	App->textures->Unload(Yellow_Active.texture);

	App->textures->Unload(Boy_Active.texture);
	App->textures->Unload(Girl_Active.texture);
	App->textures->Unload(Green_Box_Active.texture);
	App->textures->Unload(Spring.texture);
	App->textures->Unload(Initial_Tube.texture);
	App->textures->Unload(KickerActive.texture);
	App->textures->Unload(Flipper_MidLeft.texture);
	App->textures->Unload(Flipper_MidRight.texture);
	App->textures->Unload(Flipper_Left.texture);
	App->textures->Unload(Flipper_Right.texture);
	App->textures->Unload(Flipper_TopLeft.texture);
	App->textures->Unload(Flipper_TopRight.texture);
	App->textures->Unload(Ball.texture);
	Balls.del(Balls.getFirst());
		App->colliders->Disable();
		App->physics->Disable();
		
		return true;
}

bool Pinball::Start() {

	LOG("Starting pinball");

	font_score = App->fonts->Load("Sprites/fonts3.png", "0123456789", 1);
	
	//Music
	Launcher_Down = App->audio->LoadFx("Audio/Launcher_Charge.wav");


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

	Bonus_Girl_Boy_Message.Position.x = 490;
	Bonus_AllBoxes_Message.Position.x = 490;

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
	//App->audio->PlayMusic("Audio/InGame_Music.wav", 0.0f);
	ResetBall();

	if (App->colliders->IsEnabled() == false) {
		App->physics->Enable();
		App->colliders->Enable();
	}

	Yellow_Activated = false;
	 Pink_Activated = false;
	 Red_Activated = false;
	 Blue_Activated = false;
	 Green_Activated = false;
	 Orange_Activated = false;
	 Girl_Activated = false;
	 Boy_Activated = false;
	 Green_Box1_Activated = false;
	 Green_Box2_Activated = false;
	 left_activated = false;
	 right_activated = false;
	 bonusAllBoxes = false;
	 allBoxesPass = false;
	 sumedPoints = false;
	 BonusMeowMeow = false;


	AddBall(Ball.Position.x, Ball.Position.y);
	//Balls.add(App->physics->CreateCircle(Ball.Position.x, Ball.Position.y, 12));
	//Balls.getLast()->data->listener = this;
	score = 0;
	lifes = 3;
	died = false;



	return true;

}
void Pinball::Multiball() {
	int x; int y;
	App->colliders->multiball->GetPosition(x, y);
	for (int i = App->player->current_balls; i <= 3; ++i) {

		AddBall(x + 80, y + 70 );
		Balls.getLast()->data->body->ApplyForceToCenter(b2Vec2(SDL_GetTicks() % 20, SDL_GetTicks() % 5), true);
	}
	App->colliders->spawn_multiball = false;
}
void Pinball::AddBall(int x, int y) {
	Balls.add(App->physics->CreateCircle(x, y, 12));
	Balls.getLast()->data->listener = this;
	Balls.getLast()->data->body->GetFixtureList()->SetRestitution(0.5f);
	App->player->current_balls++;
}

update_status Pinball::Update()
{
	if (died == true) {
		AddBall(Ball.Position.x, Ball.Position.y);
		died = false;
	}

	if (Green_Activated&&Yellow_Activated&&Pink_Activated&&Red_Activated&&Blue_Activated&&Orange_Activated) {
		bonusAllBoxes = true;
	}
	if (bonusAllBoxes && !sumedPoints) {
		score += 15000;
		sumedPoints = true;
	}

	if (bonusAllBoxes&&!allBoxesPass) {
		Bonus_AllBoxes_Message.Position.x-=3;
	}
	if (bonusAllBoxes && Boy_Activated && Girl_Activated) {
		BonusMeowMeow = true;
	}

	if (BonusMeowMeow && !sumedPoints) {
		score += 20000;
		sumedPoints2 = true;
	}

	if (BonusMeowMeow) {
		Bonus_Girl_Boy_Message.Position.x -= 3;
	}

	if (App->colliders->spawn_multiball && App->player->current_balls <= 4) Multiball();

	//Spring Llogic
	if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT) {
		App->audio->PlayFx(Launcher_Down);
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
	if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_UP) {
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

	 iPoint mouse;
	 mouse.x = App->input->GetMouseX();
	 mouse.y = App->input->GetMouseY();

	 Draw();

	 // All draw functions ------------------------------------------------------
	 p2List_item<PhysBody*>* c = Balls.getFirst();

	 while (c != NULL)
	 {
		 int x, y;
		 c->data->GetPosition(x, y);
		 App->renderer->Blit(Ball.texture, x, y, NULL, 1.0f);

		 App->renderer->camera.y = -y + 300;
		 if (App->renderer->camera.y <= -670) {
			 App->renderer->camera.y= -669;
		 }
		 else if (App->renderer->camera.y >= 10) {
			 App->renderer->camera.y = 10;
		 }
		
		 c = c->next;
	 }

	
	
	return UPDATE_CONTINUE;
}

bool Pinball::Draw() {

	bool ret = true;

	
	App->renderer->Blit(Background.texture, 0, 0, &Background.rect);
	

	

	//Box Points activated
	if(Boy_Activated)
		App->renderer->Blit(Boy_Active.texture,54,882,&Boy_Active.rect);
	if (Girl_Activated)
		App->renderer->Blit(Girl_Active.texture, 486,881, &Girl_Active.rect);
	if (Yellow_Activated)
		App->renderer->Blit(Yellow_Active.texture, 143, 693, &Yellow_Active.rect);
	if (Red_Activated)
		App->renderer->Blit(Red_Active.texture, 426, 699, &Red_Active.rect);
	if (Pink_Activated)
		App->renderer->Blit(Pink_Active.texture, 281, 664, &Pink_Active.rect);
	if (Orange_Activated)
		App->renderer->Blit(Orange_Active.texture, 272, 1004, &Orange_Active.rect);
	if (Green_Activated)
		App->renderer->Blit(Green_Active.texture, 338, 879, &Green_Active.rect);
	if (Blue_Activated)
		App->renderer->Blit(Blue_Active.texture, 204, 881, &Blue_Active.rect);

	//Middle Box Bonus
	if (Green_Box1_Activated)
		App->renderer->Blit(Green_Box_Active.texture, 312, 342, &Green_Box_Active.rect);
	//Top Box Bonus
	if (Green_Box2_Activated)
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
	if (App->colliders->Right_flippers_Active == true) {
		App->renderer->Blit(Flipper_Right.texture, Flipper_Right.Position.x, Flipper_Right.Position.y, &Flipper_Right.rect,1,Angle_Right,Flipper_Right.rect.w,0 );
		App->renderer->Blit(Flipper_MidRight.texture, Flipper_MidRight.Position.x, Flipper_MidRight.Position.y, &Flipper_MidRight.rect, 1, Angle_Right, Flipper_MidRight.rect.w,0);
		App->renderer->Blit(Flipper_TopRight.texture, Flipper_TopRight.Position.x, Flipper_TopRight.Position.y, &Flipper_TopRight.rect, 1, Angle_Right, Flipper_TopRight.rect.w,0);
		Angle_Right += 6;
	}
	else if (App->colliders->Right_flippers_Active == false && Angle_Right >=0) {
		App->renderer->Blit(Flipper_Right.texture, Flipper_Right.Position.x, Flipper_Right.Position.y, &Flipper_Right.rect, 1, Angle_Right, Flipper_Right.rect.w, 0);
		App->renderer->Blit(Flipper_MidRight.texture, Flipper_MidRight.Position.x, Flipper_MidRight.Position.y, &Flipper_MidRight.rect, 1, Angle_Right, Flipper_MidRight.rect.w,0);
		App->renderer->Blit(Flipper_TopRight.texture, Flipper_TopRight.Position.x, Flipper_TopRight.Position.y, &Flipper_TopRight.rect, 1, Angle_Right, Flipper_TopRight.rect.w,0);
		Angle_Right -= 6;
	}
	else {
		App->renderer->Blit(Flipper_Right.texture, Flipper_Right.Position.x, Flipper_Right.Position.y, &Flipper_Right.rect);
		App->renderer->Blit(Flipper_MidRight.texture, Flipper_MidRight.Position.x, Flipper_MidRight.Position.y, &Flipper_MidRight.rect);
		App->renderer->Blit(Flipper_TopRight.texture, Flipper_TopRight.Position.x, Flipper_TopRight.Position.y, &Flipper_TopRight.rect);

	}


	if (App->colliders->Left_flippers_Active == true) {
		App->renderer->Blit(Flipper_Left.texture, Flipper_Left.Position.x, Flipper_Left.Position.y, &Flipper_Left.rect, 1, Angle_Left, 0, 0);
		App->renderer->Blit(Flipper_MidLeft.texture, Flipper_MidLeft.Position.x, Flipper_MidLeft.Position.y, &Flipper_MidLeft.rect, 1, Angle_Left, 0, 0);
		App->renderer->Blit(Flipper_TopLeft.texture, Flipper_TopLeft.Position.x, Flipper_TopLeft.Position.y, &Flipper_TopLeft.rect, 1, Angle_Left, 0, 0);
			Angle_Left -= 6;
	}
	else if (App->colliders->Left_flippers_Active == false && Angle_Left <=-25) {
		App->renderer->Blit(Flipper_Left.texture, Flipper_Left.Position.x, Flipper_Left.Position.y, &Flipper_Left.rect, 1, Angle_Left,0, 0);
		App->renderer->Blit(Flipper_MidLeft.texture, Flipper_MidLeft.Position.x, Flipper_MidLeft.Position.y, &Flipper_MidLeft.rect, 1, Angle_Left, 0, 0);
		App->renderer->Blit(Flipper_TopLeft.texture, Flipper_TopLeft.Position.x, Flipper_TopLeft.Position.y, &Flipper_TopLeft.rect, 1, Angle_Left, 0, 0);
		Angle_Left += 6;
	}
	else {
		App->renderer->Blit(Flipper_Left.texture, Flipper_Left.Position.x, Flipper_Left.Position.y, &Flipper_Left.rect);
		App->renderer->Blit(Flipper_MidLeft.texture, Flipper_MidLeft.Position.x, Flipper_MidLeft.Position.y, &Flipper_MidLeft.rect);
		App->renderer->Blit(Flipper_TopLeft.texture, Flipper_TopLeft.Position.x, Flipper_TopLeft.Position.y, &Flipper_TopLeft.rect);

	}
	



	//Spring
	App->renderer->Blit(Spring.texture,Spring.Position.x, Spring.Position.y, &Spring.rect);

	//Initial_Tube
	App->renderer->Blit(Initial_Tube.texture, 505, 724, &Initial_Tube.rect);

	//Top Score Bar
	App->renderer->Blit(Black_Part_Top_Score.texture, 0, -App->renderer->camera.y, &Black_Part_Top_Score.rect);
	App->renderer->Blit(Bonus_AllBoxes_Message.texture, Bonus_AllBoxes_Message.Position.x, (-App->renderer->camera.y) + 9, &Bonus_Girl_Boy_Message.rect);
	App->renderer->Blit(Bonus_Girl_Boy_Message.texture, Bonus_Girl_Boy_Message.Position.x, (-App->renderer->camera.y)+9, &Bonus_Girl_Boy_Message.rect);
	App->renderer->Blit(Top_Score_Bar.texture, 0, -App->renderer->camera.y, &Top_Score_Bar.rect);
	
	//Printing score
	sprintf_s(score_text, 10, "%7d", score);
	App->fonts->BlitText(0, -App->renderer->camera.y + 25, font_score, score_text);
	sprintf_s(score_text, 10, "%7d", lifes);
	App->fonts->BlitText(470, -App->renderer->camera.y + 25,font_score, score_text);

	if (lifes < 0) {
		App->fade->FadeToBlack(this, App->scene_intro,2.0f);
	}
	return ret;
}

void Pinball::OnCollision(PhysBody* bodyA, PhysBody* bodyB)
{
	if (bodyB == App->colliders->ground){
		
		if (last_collided == bodyA) 
			return;
		Balls.del(Balls.getFirst());
		--lifes;
		died = true;
		last_collided = bodyA;
	}


}
