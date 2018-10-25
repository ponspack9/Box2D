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

	bool Start();

	update_status Update();

	bool Draw();


private :

	bool StartState = true;
	bool Spring_Activated = false;

	int Spring_Position;
	int Initial_Spring_Position;
	int Velocity_Spring;


	Sprite Background;
	Sprite Top_Score_Bar;
	Sprite Black_Part_Top_Score;

	Sprite Bonus_Girl_Boy_Message;

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
	 


};



#endif // ! _Pinball