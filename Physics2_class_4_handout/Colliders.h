#pragma once
#include "Module.h"
#include "p2List.h"
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
	void OnCollision(PhysBody* bodyA, PhysBody* bodyB);


	update_status Update();
public:

	uint Flipper_FX;

	PhysBody* Spring;
	b2RevoluteJoint* flipper_joint; 

	void CreateFlipper(Flipper &flipers, int x, int y, int width, int height, int radius, int angle,int low_Angle, int max_Angle);

	bool Right_flippers_Active;
	bool Left_flippers_Active;

	Flipper Left_Flipper;
	Flipper Right_Flipper;
	Flipper MidLeft_Flipper;
	Flipper MidRight_Flipper;
	Flipper TopLeft_Flipper;
	Flipper TopRight_Flipper;

	float flipper_speed = 3.0f * b2_pi; //2PI radians/s
	float flipper_Speed_Right = -3.0f * b2_pi; //2PI radians/s
	float flipper_speed_back = -5.0f;
	float flipper_speed_back_right = 5.0f;

	PhysBody* orange;
	PhysBody* blue;
	PhysBody* green;
	PhysBody* yellow;
	PhysBody* pink;
	PhysBody* red;
	PhysBody* boy;
	PhysBody* girl;
	PhysBody* green_square_mid;
	PhysBody* green_square_top;
	PhysBody* multiball;

	PhysBody* left;
	PhysBody* right;

	p2List<PhysBody*> circles;

	PhysBody* last_collidedA;
	PhysBody* last_collidedB;

	PhysBody* ground;
	bool spawn_multiball;
	//Debug purposes mouse position
	int x;
	int y;

};

