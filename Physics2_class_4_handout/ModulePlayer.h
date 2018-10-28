#pragma once

#include "Module.h"
#include "Globals.h"
#include "p2Point.h"



class ModulePlayer : public Module
{
public:
	ModulePlayer(Application* app, bool start_enabled = true);
	virtual ~ModulePlayer();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	uint score;
	uint lifes;
	int current_balls;

	bool game_over;

};