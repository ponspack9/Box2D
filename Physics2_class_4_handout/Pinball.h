#ifndef  _Pinball_
#define _Pinball_

#include "Module.h"
#include "SDL/include/SDL.h"
#include "ModuleTextures.h"

struct Sprite;

class Pinball: public Module
{
public:
	Pinball(Application* app, bool start_enabled = true);
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
	Sprite Yellow_Active;
	Sprite Pink_Active;
	Sprite Red_Active;
	Sprite Blue_Active;
	Sprite Green_Active;
	Sprite Orange_Active;
	
	
	Sprite Spring;

	Sprite Initial_Tube;
	Sprite KickerActive;
	 


};



#endif // ! _Pinball