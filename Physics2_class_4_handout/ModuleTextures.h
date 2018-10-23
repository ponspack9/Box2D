#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2List.h"
#include "p2Point.h"
#include "SDL\include\SDL.h"

struct Sprite {

	SDL_Texture* texture = nullptr;
	SDL_Rect rect;
	iPoint Position;
};

class ModuleTextures : public Module
{
public:
	ModuleTextures(Application* app, bool start_enabled = true);
	~ModuleTextures();

	bool Init();
	bool CleanUp();

	SDL_Texture* const Load(const char* path);
	void Unload(SDL_Texture* texture);

public:
	p2List<SDL_Texture*> textures;
};