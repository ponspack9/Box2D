#include "Globals.h"
#include "Application.h"
#include "ModulePhysics.h"
#include <cmath>
#include "Box2D/Box2D/Box2D.h"

#ifdef _DEBUG
	#pragma comment (lib,"Box2D/libx86/Debug/Box2D.lib")
#else 
	#pragma comment (lib,"Box2D/libx86/Release/Box2D.lib")
#endif 

#define METERS_TO_PIXELS(meters) {int(meters * 10)}
#define PIXELS_TO_METERS(pixels) {float(pixels * 0.1)}


// TODO DONE 1: Include Box 2 header and library

ModulePhysics::ModulePhysics(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	debug = true;
}

// Destructor
ModulePhysics::~ModulePhysics()
{
}

bool ModulePhysics::Start()
{
	LOG("Creating Physics 2D environment");

	b2Vec2 gravity(0.0f, -10.0f);
	world = new b2World(gravity);

	float32 timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 8;
	int32 positionIterations = 3;
	world->Step(timeStep, velocityIterations, positionIterations);


	// TODO DONE 2: Create a private variable for the world
	// - You need to send it a default gravity
	// - You need init the world in the constructor
	// - Remember to destroy the world after using it

	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(10.0f, 10.0f);
	b2Body* groundBody = world->CreateBody(&groundBodyDef);	b2CircleShape ground;	ground.m_radius = 10;	groundBody->CreateFixture(&ground, 0.0f);	/*b2PolygonShape groundBox;
	groundBox.SetAsBox(50.0f, 10.0f);	*/	//groundBody->CreateFixture(&groundBox, 0.0f);
	// TODO 4: Create a a big static circle as "ground"
	return true;
}

// 
update_status ModulePhysics::PreUpdate()
{
	// TODO 3: Update the simulation ("step" the world)

	return UPDATE_CONTINUE;
}

// 
update_status ModulePhysics::PostUpdate()
{
	// TODO 5: On space bar press, create a circle on mouse position
	// - You need to transform the position / radius

	if(App->input->GetKey(SDL_SCANCODE_F1) == KEY_DOWN)
		debug = !debug;

	if(!debug)
		return UPDATE_CONTINUE;

	// Bonus code: this will iterate all objects in the world and draw the circles
	// You need to provide your own macro to translate meters to pixels
	
	for(b2Body* b = world->GetBodyList(); b; b = b->GetNext())
	{
		for(b2Fixture* f = b->GetFixtureList(); f; f = f->GetNext())
		{
			switch(f->GetType())
			{
				case b2Shape::e_circle:
				{
					b2CircleShape* shape = (b2CircleShape*)f->GetShape();
					b2Vec2 pos = f->GetBody()->GetPosition();
					App->renderer->DrawCircle(METERS_TO_PIXELS(pos.x), METERS_TO_PIXELS(pos.y), METERS_TO_PIXELS(shape->m_radius), 255, 255, 255);
				}
				break;

				// You will have to add more cases to draw boxes, edges, and polygons ...
			}
		}
	}

	return UPDATE_CONTINUE;
}


// Called before quitting
bool ModulePhysics::CleanUp()
{
	LOG("Destroying physics world");

	// Delete the whole physics world!
	delete world;

	return true;
}
