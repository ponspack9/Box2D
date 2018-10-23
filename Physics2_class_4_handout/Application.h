#pragma once

#include "p2List.h"
#include "Globals.h"

class Module;
class ModuleRender;
class ModuleWindow;
class ModuleTextures;
class ModuleInput;
class ModuleAudio;
class ModulePlayer;
class ModuleSceneIntro;
class ModulePhysics;
class Pinball;
class ModuleFadeToBlack;
class Colliders;


class Application
{
public:
	ModuleRender*		renderer;
	ModuleWindow*		window;
	ModuleTextures*		textures;
	ModuleInput*		input;
	ModuleAudio*		audio;
	ModulePlayer*		player;
	ModuleSceneIntro*	scene_intro;
	ModulePhysics*		physics;
	Pinball*			pinball;
	ModuleFadeToBlack*  fade;
	Colliders*			colliders;

private:

	p2List<Module*> list_modules;

public:

	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();

private:

	void AddModule(Module* mod);
};