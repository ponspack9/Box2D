#pragma once
#include "Module.h"
class Colliders :	public Module
{
public:


	Colliders(Application* app, bool start_enabled=true);
	~Colliders();
	bool Start();

	update_status Update();
public:
	PhysBody* Spring;
	b2Body* A;

};

