#include "Colliders.h"
#include "ModulePhysics.h"
#include "Globals.h"
#include "ModuleInput.h"
#include "Application.h"



Colliders::Colliders(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	
}


Colliders::~Colliders()
{
}

bool Colliders::Start()
{
	int Initial_Tube[46] = {
		610, 1173,
		608, 857,
		590, 806,
		560, 767,
		543, 755,
		548, 739,
		583, 760,
		620, 827,
		626, 869,
		628, 1183,
		397, 1183,
		423, 1156,
		563, 1080,
		565, 867,
		551, 828,
		525, 795,
		533, 781,
		554, 802,
		570, 831,
		578, 860,
		580, 881,
		580, 1177,
		610, 1179
	};
	int Background[116] = {
		640, 767,
		558, 732,
		583, 684,
		567, 668,
		611, 589,
		603, 588,
		602, 549,
		609, 549,
		611, 352,
		605, 353,
		603, 314,
		611, 313,
		609, 83,
		602, 86,
		590, 74,
		583, 80,
		555, 56,
		558, 47,
		550, 40,
		555, 29,
		423, 30,
		410, 42,
		414, 52,
		384, 78,
		374, 73,
		355, 90,
		349, 177,
		336, 186,
		315, 153,
		273, 132,
		263, 126,
		259, 98,
		246, 75,
		224, 52,
		183, 33,
		144, 28,
		110, 35,
		86, 50,
		69, 69,
		55, 95,
		49, 121,
		48, 155,
		50, 653,
		55, 676,
		63, 695,
		74, 709,
		82, 723,
		82, 742,
		82, 833,
		75, 836,
		67, 828,
		43, 831,
		39, 1076,
		190, 1157,
		205, 1172,
		205, 1179,
		645, 1181,
		643, 795
	};
	int UpLeftCurve[82] = {
		213, 131,
		208, 109,
		189, 79,
		162, 61,
		130, 64,
		108, 78,
		90, 100,
		84, 121,
		89, 659,
		102, 680,
		119, 705,
		120, 832,
		125, 838,
		130, 835,
		128, 711,
		123, 698,
		104, 671,
		100, 658,
		100, 646,
		136, 591,
		114, 548,
		133, 532,
		107, 470,
		107, 428,
		100, 428,
		100, 412,
		108, 412,
		108, 372,
		98, 372,
		96, 307,
		96, 293,
		102, 295,
		108, 288,
		120, 291,
		133, 253,
		123, 247,
		127, 227,
		121, 203,
		182, 170,
		184, 162,
		201, 133
	};
	int RightDown[12] = {
		407, 979,
		419, 987,
		475, 959,
		482, 884,
		464, 879,
		410, 975
	};
	int LeftDown[10] = {
		146, 878,
		128, 885,
		135, 960,
		192, 988,
		204, 978
	};
	int RightBottom[14] = {
		508, 1019,
		521, 990,
		526, 988,
		528, 1024,
		515, 1050,
		411, 1109,
		397, 1082
	};
	int LeftBottom[14] = {
		89, 989,
		80, 992,
		83, 1029,
		97, 1051,
		195, 1105,
		208, 1082,
		97, 1016
	};


	App->physics->CreateChain(0, 0, Initial_Tube, 46);
	App->physics->CreateChain(0, 0, Background, 116);
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
	App->physics->CreateCircle(305, 165,  15, b2_staticBody);
	App->physics->CreateCircle(544, 866, 15, b2_staticBody);
	App->physics->CreateCircle(150, 340, 15, b2_staticBody);

	return true;
}

update_status Colliders::Update() {
	int x = App->input->GetMouseX();
	int y = App->input->GetMouseY();
	LOG("Mouse [%d,%d]", x, y);
	return UPDATE_CONTINUE;
}
