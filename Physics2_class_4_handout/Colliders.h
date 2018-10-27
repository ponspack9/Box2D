#pragma once
#include "Module.h"
#include "ModulePhysics.h"


struct Flipper{

	b2Body* Placement;
	b2Body* ForceShape;
	b2RevoluteJoint* Flipper_joint;
};

class Colliders :	public Module
{
public:

	
	Colliders(Application* app, bool start_enabled=true);
	~Colliders();
	bool Start();

	update_status Update();
public:

	b2Body* Attach;
	b2Body* flipper;
	PhysBody* Spring;
	b2RevoluteJoint* flipper_joint;

	void Colliders::CreateFlipper(Flipper &flipers, int x, int y, int width, int height, int radius,int low_Angle, int max_Angle);

	Flipper Left_Flipper;
	Flipper Right_Flipper;

	float flipper_speed = 3.0f * b2_pi; //2PI radians/s


};

