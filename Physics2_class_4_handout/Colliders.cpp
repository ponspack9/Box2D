#include "Colliders.h"
#include "Globals.h"
#include "ModuleInput.h"
#include "ModuleInput.h"
#include "Application.h"
#include "Pinball.h"



Colliders::Colliders(Application* app, bool start_enabled) : Module(app, start_enabled)
{

}


Colliders::~Colliders()
{
}

bool Colliders::Start()
{
	//Create Background colliders

	int Initial_Tube[96] = {78, 505,77, 448,78, 146,77, 133,75, 122,71, 110,66, 99,	60, 88,	54, 80,	45, 70,	37, 62,	29, 56,	8, 42,	-1, 62,	0, 67,	18, 76,	27, 83,	44, 104,56, 134,58, 183,57, 534,
		123, 535,122, 147,122, 133,114, 76,79, 27,49, 10,42, 3,28, 0,24, 3,20, 14,37, 25,45, 32,56, 41,	62, 47,	69, 55,	76, 64,	83, 74,	91, 87,	96, 98,	100, 110,103, 122,105, 133,	106, 148,107, 203, 107, 450,106, 514,78, 514};
	int Background[147] = {	640, 767,559, 739,	556, 733,558, 727,581, 686,566, 676,564, 672,565, 667,606, 592,602, 590,601, 549,612, 549,611, 358,603, 357,603, 314,611, 313,611, 81,605, 88,592, 78,585, 84,
		552, 56,555, 48,546, 39,555, 29,426, 31,412, 45,418, 56,385, 84,374, 73,355, 90,352, 178,342, 190,331, 186,316, 156,274, 136,263, 126,259, 98,246, 75,224, 52,183, 33,164, 29,146, 28,126, 31,110, 37,
		95, 45,	83, 54,	69, 69,	55, 95,	50, 122,50, 157,50, 653,55, 679,62, 694,74, 709,82, 722,82, 742,82, 833,75, 836,61, 833,42, 834,41, 1079,48, 1078,58, 1083,194, 1157,211, 1173,205, 1361,380, 1357,400, 1173,
		421, 1155,562, 1078,563, 1176,633, 1173,640, 773};
	int UpLeftCurve[82] = { 213, 131, 208, 109,	189, 79,162, 61,130, 64,108, 78,90, 100,84, 121,89, 659,102, 680,119, 705,120, 832,125, 838,130, 835,128, 711,123, 698,	104, 671,
		100, 658,100, 646,	136, 591,114, 548,133, 532,107, 470,107, 428,100, 428,100, 412,108, 412,108, 372,98, 372,96, 307,96, 293,102, 295,108, 288,120, 291,133, 253,123, 247,127, 227,
		121, 203,182, 170,184, 162,	201, 133 };
	int RightDown[12] = {	407, 979,	419, 987,	475, 959,	482, 884,	464, 879,	410, 975};
	int LeftDown[10] = { 146, 878,	128, 885,	135, 960,	192, 988,	204, 978};
	int RightBottom[14] = {	508, 1019,	521, 990,	526, 988,	528, 1024,	515, 1050,	411, 1109,	397, 1082};
	int LeftBottom[14] = {	89, 989, 80, 992,	83, 1029,	97, 1051,	195, 1105,	208, 1082,	97, 1016};
	int Flipper_Left[22] = { 14, 0,	24, 1, 71, 47,	71, 58,	66, 63,	58, 63,	5, 34,	0, 26,	0, 15,	3, 5,	10, 0};
	int Flipper_Right[22] = { 55, -1,	47, 0,	0, 45,	0, 56,	4, 62,	9, 63,	64, 33,	70, 23,	70, 11,	64, 3,	57, -1};
	int Flipper_MidLeft[22] = {	0, 7, 7, 0,	16, 0,	21, 2,	25, 6,	37, 48,	37, 54,	32, 61,	24, 61,	0, 20,	0, 9};
	int Flipper_MidRight[22] = { 29, 1,	37, 9,	38, 18,	15, 58,	11, 61,	4, 60,	0, 56,	0, 47,	11, 7,	18, 0,	26, 0};
	int Flipper_TopLeft[20] = {	0, 6, 6, 0, 16, 0, 54, 36,	54, 46,	48, 49,	42, 47,	5, 26,	0, 19,	0, 9};
	int Flipper_TopRight[22] = { 52, 5,	53, 10,	53, 19,	50, 25,	8, 49,	4, 49,	0, 44,	0, 36,	36, 1,	43, -1,	49, 2 };

	App->physics->CreateChain(505, 724, Initial_Tube, 96);
	App->physics->CreateChain(0, 0, Background, 147);
	App->physics->CreateChain(0, 0, UpLeftCurve, 82);
	App->physics->CreateChain(0, 0, RightDown, 12);
	App->physics->CreateChain(0, 0, LeftDown, 10);
	App->physics->CreateChain(0, 0, RightBottom, 14);
	App->physics->CreateChain(0, 0, LeftBottom, 14);

	App->physics->CreateCircle(372, 569, 40, b2_staticBody);
	App->physics->CreateCircle(535, 427, 40, b2_staticBody);
	App->physics->CreateCircle(590, 280, 15, b2_staticBody);
	App->physics->CreateCircle(550, 161, 15, b2_staticBody);
	App->physics->CreateCircle(398, 161, 15, b2_staticBody);
	App->physics->CreateCircle(305, 165, 15, b2_staticBody);
	App->physics->CreateCircle(544, 866, 15, b2_staticBody);
	App->physics->CreateCircle(150, 340, 15, b2_staticBody);
	
	//Create Flippers

	CreateFlipper(Left_Flipper, 205, 1095, 60, 20, 10, 0, -40, 45);
	CreateFlipper(Right_Flipper, 400, 1095, 60, 20, 10,170,-220,-145);

	CreateFlipper(MidLeft_Flipper, 125, 538, 47, 15, 10, 0, -80, 40);
	CreateFlipper(MidRight_Flipper, 570, 670, 45, 15, 10, 170, -190, -115);

	CreateFlipper(TopLeft_Flipper, 400, 240, 50, 15, 10, 0, -40, 45);
	CreateFlipper(TopRight_Flipper, 565, 240, 50, 15, 10, 170, -220, -145);

	//Spring

	Spring = App->physics->CreateRectangle(App->pinball->GetSpringPosition().x + 13, App->pinball->GetSpringPosition().y + 16, 27, 30,0, b2_kinematicBody);
	test = App->physics->CreateRectangleSensor(500, 500, 50, 50, this);
	orange = App->physics->CreateRectangleSensor(310, 1035, 60, 60, this);

	return true;
}

void Colliders::OnCollision(PhysBody * bodyA, PhysBody * bodyB)
{
	//Spawn a ball that collides with orange bonus to trigger it
	if (bodyA == orange) {
		LOG("ORANGE")

	}

}

update_status Colliders::Update() {
	x = App->input->GetMouseX();
	y = App->input->GetMouseY();



	if (App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT)
	{
		//flipper_joint->
		//Left_Flipper.Flipper_joint->EnableMotor (true);
		//MidLeft_Flipper.Flipper_joint->EnableMotor(true);
		Left_Flipper.Flipper_joint->SetMotorSpeed(flipper_speed);
		TopLeft_Flipper.Flipper_joint->SetMotorSpeed (flipper_speed);
		MidLeft_Flipper.Flipper_joint->SetMotorSpeed(flipper_speed);
	
		LOG("A");
	}

	if (App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT)
	{
		//flipper_joint->
		//Right_Flipper.Flipper_joint->EnableMotor(true);
		//MidRight_Flipper.Flipper_joint->EnableMotor(true);
		Right_Flipper.Flipper_joint->SetMotorSpeed(-flipper_speed);
		TopRight_Flipper.Flipper_joint->SetMotorSpeed(-flipper_speed);
		MidRight_Flipper.Flipper_joint->SetMotorSpeed(-flipper_speed);
		LOG("D");
	}
	if (Left_Flipper.Flipper_joint->GetJointAngle() >= Left_Flipper.Flipper_joint->GetUpperLimit()) {
		LOG("TOPEEE");
		Left_Flipper.Flipper_joint->SetMotorSpeed(flipper_speed_back);
		TopLeft_Flipper.Flipper_joint->SetMotorSpeed(flipper_speed_back);
		MidLeft_Flipper.Flipper_joint->SetMotorSpeed(flipper_speed_back);

	}

	if (Right_Flipper.Flipper_joint->GetJointAngle() <= Right_Flipper.Flipper_joint->GetLowerLimit()) {
		LOG("TOPEEE %f , %f",Right_Flipper.Flipper_joint->GetJointAngle(), MidRight_Flipper.Flipper_joint->GetJointAngle());
		Right_Flipper.Flipper_joint->SetMotorSpeed(flipper_speed_back_right);
		TopRight_Flipper.Flipper_joint->SetMotorSpeed(flipper_speed_back_right);
		//MidRight_Flipper.Flipper_joint->SetMotorSpeed(flipper_speed_back_right);

	}
	// Can't get it work in the same if,, to check, AND some kind of delay 
	if (MidRight_Flipper.Flipper_joint->GetJointAngle() <= MidRight_Flipper.Flipper_joint->GetLowerLimit()) {
		LOG("TOPEEE %f , %f", Right_Flipper.Flipper_joint->GetJointAngle(), MidRight_Flipper.Flipper_joint->GetJointAngle());
		MidRight_Flipper.Flipper_joint->SetMotorSpeed(flipper_speed_back_right);

	}


	Spring->body->SetLinearVelocity(b2Vec2(0, App->pinball->Velocity_Spring));

	//correcting Movement
	if (METERS_TO_PIXELS(Spring->body->GetPosition().y) >= 1037 && App->pinball->Spring_Stop == true) {
		Spring->body->SetLinearVelocity(b2Vec2(0, -2));
	}
	//LOG("SPring_Position:%d", METERS_TO_PIXELS(Spring->body->GetPosition().y));
	//LOG("Mouse [%d,%d]", x, y);
	return UPDATE_CONTINUE;
}

void Colliders::CreateFlipper(Flipper &flipers, int x,int y, int width,int height,int radius,int angle ,int low_Angle, int max_Angle) {

	flipers.Placement = App->physics->CreateCircle(x, y, radius, b2_staticBody)->body;
	flipers.ForceShape = App->physics->CreateRectangle(x, y, width, height, angle)->body;

	//flipers.Placement = App->physics->CreateCircle(205, 1095, 20, b2_staticBody)->body;
	//flipers.Flipper = App->physics->CreateRectangle(205, 1095, 80, 30, 0.14)->body;

	b2RevoluteJointDef revoluteJointDef;
	revoluteJointDef.bodyA = flipers.ForceShape;
	revoluteJointDef.bodyB = flipers.Placement;
	//b2Vec2 v = { PIXEL_TO_METERS(-40), PIXEL_TO_METERS(0) };
	//revoluteJointDef.Initialize(m_bodyA, m_bodyB, v);
	revoluteJointDef.collideConnected = false;
	revoluteJointDef.localAnchorA.Set(PIXEL_TO_METERS(-width/1.3), PIXEL_TO_METERS(0));//the top right corner of the box
	revoluteJointDef.localAnchorB.Set(PIXEL_TO_METERS(0), PIXEL_TO_METERS(0));//center of the circle
	revoluteJointDef.lowerAngle = low_Angle*DEGTORAD;
	revoluteJointDef.upperAngle = max_Angle*DEGTORAD;
	revoluteJointDef.enableLimit = true;
	revoluteJointDef.motorSpeed = flipper_speed;
	revoluteJointDef.maxMotorTorque = 1000.0f;
	revoluteJointDef.enableMotor = true;
	flipers.Flipper_joint = (b2RevoluteJoint*)App->physics->world->CreateJoint(&revoluteJointDef);
}