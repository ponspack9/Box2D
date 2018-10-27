#pragma once
#include "Module.h"
#include "ModulePhysics.h"


class Colliders :	public Module
{
public:


	Colliders(Application* app, bool start_enabled=true);
	~Colliders();
	bool Start();

	update_status Update();
public:
	PhysBody* Spring;
	b2RevoluteJoint* flipper_joint;
	float flipper_speed = 3.0f * b2_pi; //2PI radians/s


};

