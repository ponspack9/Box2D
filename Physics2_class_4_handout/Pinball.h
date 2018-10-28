#ifndef  _Pinball_
#define _Pinball_

#include "Module.h"
#include "SDL/include/SDL.h"
#include "ModuleTextures.h"

struct Sprite;

class Pinball: public Module
{
public:
	Pinball(Application* app, bool start_enabled=true);
	~Pinball();

	void OnCollision(PhysBody* bodyA, PhysBody* bodyB);

	bool Start();
	bool CleanUp();

	void Multiball();

	void AddBall(int x, int y);

	update_status Update();

	bool Draw();

	void ResetBall() {
		Ball.Position = { 583,993 };
	}

	Sprite Ball;

	iPoint GetSpringPosition() const {
		return Spring.Position;
	};


	uint score;
	int lifes;
	int current_balls;

	bool game_over;

	int Angle_Right;
	int Angle_Left;
	int Velocity_Spring;
	bool Spring_Activated = false;
	bool Spring_Stop = true;
	bool died = false;

	Sprite Background;


	PhysBody* last_collided=nullptr;
	p2List<PhysBody*> Balls;
	
	uint Launcher_Down;
	uint InGame_Music;
	uint Flipper_FX;

	bool Yellow_Activated;
	bool Pink_Activated;
	bool Red_Activated;
	bool Blue_Activated;
	bool Green_Activated;
	bool Orange_Activated;
	bool Girl_Activated;
	bool Boy_Activated;
	bool Green_Box1_Activated;
	bool Green_Box2_Activated;
	bool left_activated;
	bool right_activated;
	bool bonusAllBoxes;
		bool allBoxesPass;
		bool sumedPoints;
	int font_score;
	char score_text[10];

private :

	bool StartState = true;

	int Spring_Position;
	int Initial_Spring_Position;
	
	


	Sprite Top_Score_Bar;
	Sprite Black_Part_Top_Score;

	Sprite Bonus_Girl_Boy_Message;
	Sprite Bonus_AllBoxes_Message;
	Sprite Bonus_Loop_Message;
	Sprite Game_Over_Message;
	Sprite Multiball_Message;

	Sprite Yellow_Active;
	Sprite Pink_Active;
	Sprite Red_Active;
	Sprite Blue_Active;
	Sprite Green_Active;
	Sprite Orange_Active;
	Sprite Girl_Active;
	Sprite Boy_Active;
	Sprite Green_Box_Active;

	Sprite Top_Left_Bonus_Machine;
	
	Sprite Spring;

	Sprite Initial_Tube;
	Sprite KickerActive;

	Sprite Flipper_TopLeft;
	Sprite Flipper_TopRight;
	Sprite Flipper_MidLeft;
	Sprite Flipper_MidRight;
	Sprite Flipper_Left;
	Sprite Flipper_Right;


};



#endif // ! _Pinball