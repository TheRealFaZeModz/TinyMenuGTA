#pragma region New Shit
//option function Money array

int
MapHandle,
SelectedMapObject,
SpawnedMapObjects,
SpawnedMapObject[25],
Object_Handle;

bool
AttachVehicle = false,
AttachVehicleObject = false,
FreezePos = false,
Collis = true,
MoveMapObject = true,
MoveObject = true,
MoveVehicle = true,
LoadingMapObject;

float
Pos_X,
Pos_Y,
Pos_Z,
PosX_1,
PosY_1,
PosZ_1;

float
Pitch = ENTITY::GET_ENTITY_PITCH(Object_Handle),
Roll = ENTITY::GET_ENTITY_ROLL(Object_Handle);

float
Yaw = ENTITY::GET_ENTITY_HEADING(Object_Handle);

float
MapPitch = ENTITY::GET_ENTITY_PITCH(MapHandle),
MapRoll = ENTITY::GET_ENTITY_ROLL(MapHandle),
MapYaw = ENTITY::GET_ENTITY_HEADING(MapHandle),
MoveSize = 0.1f;

char* ObjectMapString;
char* MapObjectNameArray[25];
char* ObjectNameArray[20];
bool bool_object[50];

void addCharBOOLSwap(char *optionON, char *optionOFF, char **From, int*var, int min, int max, bool B, char *info = "")
{
	if (B)
	{
		char on[30];
		char buf[50];
		snprintf(buf, sizeof(buf), "%s    ~w~%s", optionON, (From[*var]));
		snprintf(on, sizeof(on), "ON");
		drawTextRightJustify(on, 4, textXCoord + .215, (optionCount * 0.035f + 0.163f), .57, .52, 0, 255, 0, 255);
		addOption(buf, info);
		if (currentOption == optionCount)
		{
			lrInstruction = true;
			if (rightPress)
			{
				playSound("NAV_UP_DOWN");
				if (*var >= max)
					*var = min;
				else
					*var = *var + 1;
			}
			else if (leftPress)
			{
				playSound("NAV_UP_DOWN");
				if (*var <= min)
					*var = max;
				else
					*var = *var - 1;
			}
		}
	}
	else
	{
		char buf[30];
		char off[30];
		snprintf(buf, sizeof(buf), "%s: ", optionOFF);//~r~Off"
		addOption(buf, info);
		snprintf(buf, sizeof(buf), "%s ", optionOFF);
		snprintf(off, sizeof(off), "O F F", optionOFF);
		drawTextRightJustify(off, 4, textXCoord + .215, (optionCount * 0.035f + 0.163f), .57, .52, 255, 0, 0, 255);
		addOption(buf, info);
	}

}

#pragma endregion

#pragma region Shit I really have to do this again.....

void addMapFloatOption(char *option, float *var, float min, float max, bool holdPress, char *info = "") {
	char buf[100];
	char buf1[100];
	snprintf(buf, sizeof(buf), "%s:", option);
	snprintf(buf1, sizeof(buf1), "%s", FtoS(*var));
	addOption(buf, info);
	addOptionRightJustify(buf1);
	if (currentOption == optionCount) {
		lrInstruction = true;
		if (holdPress) {
			if (fastRightPress) {
				playSound("NAV_UP_DOWN");
				if (*var >= max)
					*var = min;
				else
					*var = *var + MoveSize;
				optionPress = true;
				AttachVehicle = true;
				MoveObject = true;
				MoveMapObject = true;
				MoveVehicle = true;
				AttachVehicleObject = true;
			}
			else if (fastLeftPress) {
				playSound("NAV_UP_DOWN");
				if (*var <= min)
					*var = max;
				else
					*var = *var - MoveSize;
				optionPress = true;
				AttachVehicle = true;
				MoveObject = true;
				MoveMapObject = true;
				MoveVehicle = true;
				AttachVehicleObject = true;
			}
		}
		else {
			if (rightPress) {
				playSound("NAV_UP_DOWN");
				if (*var >= max)
					*var = min;
				else
					*var = *var + MoveSize;
				optionPress = true;
				AttachVehicle = true;
				MoveObject = true;
				MoveMapObject = true;
				MoveVehicle = true;
				AttachVehicleObject = true;
			}
			else if (leftPress) {
				playSound("NAV_UP_DOWN");
				if (*var <= min)
					*var = max;
				else
					*var = *var - MoveSize;
				optionPress = true;
				AttachVehicle = true;
				MoveObject = true;
				MoveMapObject = true;
				MoveVehicle = true;
				AttachVehicleObject = true;
			}
		}
	}
}
void MoveCoordsOption(char *option, int Object, bool X_Coords = false, bool Y_Coords = false, bool Z_Coords = false, char *info = "") {
	Vector3 Coords = ENTITY::GET_ENTITY_COORDS(Object, 1);
	char buf[100];
	char buf1[100];
	if (X_Coords)
		__snprintf(buf, 100, "%s:", option, Coords.x);
	__snprintf(buf1, 100, "%.2f", option, Coords.x);
	if (Y_Coords)
		__snprintf(buf, 100, "%s:", option, Coords.y);
	__snprintf(buf1, 100, "%.2f", option, Coords.y);
	if (Z_Coords)
		__snprintf(buf, 100, "%s:", option);
	__snprintf(buf1, 100, "%.2f", Coords.z);
	addOption(buf, info);
	addOptionRightJustify(buf1);
	if (currentOption == optionCount) {
		lrInstruction = true;
		if (fastRightPress) {
			playSound("NAV_UP_DOWN");
			if (X_Coords) {
				Coords.x = Coords.x + MoveSize;
				SET_ENTITY_COORDS1(Object, Coords.x, Coords.y, Coords.z, 0, 0, 0, 1);
			}
			else if (Y_Coords) {
				Coords.y = Coords.y + MoveSize;
				SET_ENTITY_COORDS1(Object, Coords.x, Coords.y, Coords.z, 0, 0, 0, 1);
			}
			else if (Z_Coords) {
				Coords.z = Coords.z + MoveSize;
				SET_ENTITY_COORDS1(Object, Coords.x, Coords.y, Coords.z, 0, 0, 0, 1);
			}
		}
		else if (fastLeftPress) {
			playSound("NAV_UP_DOWN");
			if (X_Coords) {
				Coords.x = Coords.x - MoveSize;
				SET_ENTITY_COORDS1(Object, Coords.x, Coords.y, Coords.z, 0, 0, 0, 1);
			}
			else if (Y_Coords) {
				Coords.y = Coords.y - MoveSize;
				SET_ENTITY_COORDS1(Object, Coords.x, Coords.y, Coords.z, 0, 0, 0, 1);
			}
			else if (Z_Coords) {
				Coords.z = Coords.z - MoveSize;
				SET_ENTITY_COORDS1(Object, Coords.x, Coords.y, Coords.z, 0, 0, 0, 1);
			}
		}
	}
}
void addFloatOption1(char *option, float *var, float min, float max, bool holdPress, float Value = 0.01f, char *info = "") {
	char buf[100];
	char buf1[100];
	snprintf(buf, sizeof(buf), "%s:", option);
	addOption(buf, info);
	snprintf(buf1, sizeof(buf1), "%s", FtoS(*var));
	addOptionRightJustify(buf1);
	if (currentOption == optionCount) {
		lrInstruction = true;
		if (holdPress) {
			if (fastRightPress) {
				playSound("NAV_UP_DOWN");
				if (*var >= max)
					*var = min;
				else
					*var = *var + Value;
			}
			else if (fastLeftPress) {
				playSound("NAV_UP_DOWN");
				if (*var <= min)
					*var = max;
				else
					*var = *var - Value;
			}
		}
		else {
			if (rightPress) {
				playSound("NAV_UP_DOWN");
				if (*var >= max)
					*var = min;
				else
					*var = *var + Value;
			}
			else if (leftPress) {
				playSound("NAV_UP_DOWN");
				if (*var <= min)
					*var = max;
				else
					*var = *var - Value;
			}
		}
	}
}
// From Joren <3
void DeleteVehicle(int Player)
{
	int pedID = PLAYER::GET_PLAYER_PED(Player);
	if (PED::IS_PED_IN_ANY_VEHICLE(pedID, false))
	{
		int Vehicle = PED::GET_VEHICLE_PED_IS_IN(pedID, 1/*yes get last veh*/);

		if (!NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(Vehicle))
		{
			ENTITY::SET_ENTITY_AS_MISSION_ENTITY(Vehicle, 1, 1);

			VEHICLE::DELETE_VEHICLE(&Vehicle);
		}
	}
}
#pragma endregion

#pragma region object spawner
//////////////////////////////

int Buildingsvar;
char *Buildings[] = { "Maze Bank","Map 1","Map 2","Map 3","Map 4","Map 5","Map 6","Map 7","Map 8","Map 9","Map 10","Map 11","Map 12","Map 13","Map 14","Map 15","Map 16","Map 17","Map 18","Map 19","Building 1","Building 2","Apartment 1", "Apartment 2","Apartmaent 3","Apartment 4","Apartment 5","Apartment 6", "Apartment 7","Apartment 8","Apartment 9","Apartment 10","Apartment 11","Apartment 12","1","2","3","4","5","6","7","8","9","10","11","12","13","14" };
char *Buildingshash[] = { "DT1_11_DT1_TOWER", "dt1_lod_slod3","id1_lod_slod4","id2_lod_slod4","hw1_lod_slod4","po1_lod_slod4","sc1_lod_slod4","ss1_lod_slod3","ap1_lod_slod4","kt1_lod_slod4","bh1_lod_slod3","sp1_lod_slod4","sm_lod_slod4","vb_lod_slod4","ch1_lod_slod3a","ch2_lod_slod3","hei_ch1_yacht_slod3","hei_ch1_yacht_slod2","hei_dt1_carrmp_slod3","hei_dt1_carrmp_slod2","DT1_01_BUILD","DT1_05_BUILD1_H","db_apart_01d_","db_apart_01_","db_apart_02_","db_apart_03_","db_apart_05_","db_apart_06_","db_apart_07_","db_apart_08_","db_apart_05d","db_apart_06d_","db_apart_07d_","db_apart_08d_","SS1_PROPS_BUG1480687_SLOD","SS1_PROPS_BUG1513403_SLOD","SS1_08_APART","SS1_08_BUILD6","SS1_08_CORNER","SS1_08_CORNER_EM","SS1_08_DTL01","SS1_08_DTL02","SS1_08_GROUND_H","SS1_07_HOTELRAILING4","SS1_07_HOTELRAILING3","SS1_07_HOTELRAILING2","SS1_07_HOTELRAILING1","SS1_06_MONKEY" };
int MapPropsvar;
char *MapProps[] = { "Sand Block","Weed Plant","Ferris Wheel","Hotdog","Atm","prop_sculpt_fix" ,"Barge","Safe","Roof Vent","Heist Emp","Alien Egg","Shutter","Airhockey","Air Propeller","Amp", "UFO","Arcade","Asteroid","Vault Door","Barrel","Bball Arcade","Biotech_store","Boogieboad","Boombox","Xmas Tree","Xmas","Windmill","MP Ramp 1","MP Ramp 2","MP Ramp 3","Beachball","Speaker 1","Speaker 2","Boulder_01","Inflategate","Time Capsule","Fridge","Jet","Pickaxe","Pyramid","Whalebones","Rocket","Monkey","Dino","Guard Tower" };
char *MapPropshash[] = { "prop_mb_sandblock_01","prop_weed_01","prop_ld_ferris_wheel","prop_cs_hotdog_01","prop_atm_01","prop_sculpt_fix" ,"prop_lev_des_barge_01","p_v_43_safe_s","prop_roofvent_06a","hei_prop_heist_emp","prop_alien_egg_01","v_ilev_bl_shutter1","prop_airhockey_01","prop_air_propeller01","prop_amp_01", "UFO","prop_arcade_01","prop_asteroid_01","prop_bank_vaultdoor","prop_barrel_01a","prop_bball_arcade_01","prop_biotech_store","prop_boogieboad_01","prop_boombox_01","prop_xmas_tree_int","prop_xmas_ext","prop_windmill_01","prop_mp_ramp_01","prop_mp_ramp_02","prop_mp_ramp_03","prop_beachball_02","prop_speaker_07","prop_out_door_speaker","prop_test_boulder_01","Prop_inflategate_01","prop_time_capsule_01","prop_fridge_01","p_cs_mp_jet_01_s","prop_tool_pickaxe","v_res_fa_pyramid","p_seabed_whalebones","cs1_09_diner_rocket","ss1_06_monkey","ch3_01_dino","v_71_guardtower" };
int Rampvar;
char *RampProps[] = { "Water Ramp 1", "Water Ramp 2", "Water Ramp 3","Jetski Ramp","MP Ramp 1", "MP Ramp 2", "MP Ramp 3","Container", "Barge" ,"Skate Flat Ramp", "Skate Fun Box", "Skate Half Pipe", "Skate Kickers", "Skate Quarter Pipe", "Skate Rail", "Skate Spiner" };
char *RampPropshash[] = { "prop_water_ramp_01", "prop_water_ramp_02", "prop_water_ramp_03","prop_jetski_ramp_01","prop_mp_ramp_01", "prop_mp_ramp_02", "prop_mp_ramp_03","prop_container_01a", "prop_lev_des_barge_01" ,"prop_skate_flatramp", "prop_skate_funbox", "prop_skate_halfpipe", "prop_skate_kickers", "prop_skate_quartpipe", "prop_skate_rail", "prop_skate_spiner" };
bool Create_Map(char* MapObjectName, char* ObName, Vector3 Pos, bool custom = false, int hash = 0) {
	if (STREAMING::IS_MODEL_IN_CDIMAGE(GAMEPLAY::GET_HASH_KEY(MapObjectName))) {
		if (STREAMING::IS_MODEL_VALID(GAMEPLAY::GET_HASH_KEY(MapObjectName))) {
			STREAMING::REQUEST_MODEL(GAMEPLAY::GET_HASH_KEY(MapObjectName));
			Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
			if (STREAMING::HAS_MODEL_LOADED(GAMEPLAY::GET_HASH_KEY(MapObjectName))) {
				SpawnedMapObject[SpawnedMapObjects] = OBJECT::CREATE_OBJECT(GAMEPLAY::GET_HASH_KEY(MapObjectName), coords.x, coords.y, coords.z, 1, 1, 1);
				MapObjectNameArray[SpawnedMapObjects] = MapObjectName;
				if (ENTITY::DOES_ENTITY_EXIST(SpawnedMapObject[SpawnedMapObjects])) {
					ENTITY::FREEZE_ENTITY_POSITION(SpawnedMapObject[SpawnedMapObjects], true);
					SpawnedMapObjects++;
					char buf[100];
					snprintf(buf, sizeof(buf), "Spawned: ~b~%s~HUD_COLOUR_WHITE~!", MapObjectName);
					PRINT(buf);
					if (SpawnedMapObjects >= 25)
						SpawnedMapObjects = 0;
					return true;
				}
				else return false;
				//PRINT("~r~Object not Exist!");
			}
			//else return false;
			//PRINT("~r~Object not Loaded!");
		}
	}
}

bool Ttrap(char* ObjectName, char* ObjectName2, char* ObjectName3, bool freeze = false) {
	if (STREAMING::IS_MODEL_IN_CDIMAGE(GAMEPLAY::GET_HASH_KEY(ObjectName))) {
		if (STREAMING::IS_MODEL_VALID(GAMEPLAY::GET_HASH_KEY(ObjectName))) {
			STREAMING::REQUEST_MODEL(GAMEPLAY::GET_HASH_KEY(ObjectName));
			Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
			if (STREAMING::HAS_MODEL_LOADED(GAMEPLAY::GET_HASH_KEY(ObjectName))) {
				int Object = OBJECT::CREATE_OBJECT(GAMEPLAY::GET_HASH_KEY(ObjectName), -796.61, 305.37, 84.42, 1, 1, 1);//garage
				int Object2 = OBJECT::CREATE_OBJECT(GAMEPLAY::GET_HASH_KEY(ObjectName2), -773.39, 305.27, 84.41, 1, 1, 1);//apartment
				int Object3 = OBJECT::CREATE_OBJECT(GAMEPLAY::GET_HASH_KEY(ObjectName3), -774.31, 326.81, 208.80, 1, 1, 1);//apartment
				ENTITY::FREEZE_ENTITY_POSITION(Object, 1);
				ENTITY::SET_ENTITY_COLLISION(Object, 1, 0);
				ENTITY::FREEZE_ENTITY_POSITION(Object2, 1);
				ENTITY::SET_ENTITY_COLLISION(Object2, 1, 0);
				ENTITY::FREEZE_ENTITY_POSITION(Object3, 1);
				ENTITY::SET_ENTITY_COLLISION(Object3, 1, 0);
				return true;
			}
		}
	}
}

void freezeEntity(uint Handle) {
	if (ENTITY::DOES_ENTITY_EXIST(Handle)) {
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(Handle);
		ENTITY::FREEZE_ENTITY_POSITION(Handle, true);
	}
}
void unfreezeEntity(uint Handle) {
	if (ENTITY::DOES_ENTITY_EXIST(Handle)) {
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(Handle);
		ENTITY::FREEZE_ENTITY_POSITION(Handle, false);
	}
}

void FrezzeandUnfrezze(uint ha) {
	if (bool_object[7] == false) {
		freezeEntity(ha);
		PRINT("Objected Frozen");
		bool_object[7] = true;
	}
	else if (bool_object[7] == true) {
		unfreezeEntity(ha);
		PRINT("Objected UnFrozen");
		bool_object[7] = false;
	}
}

void DeleteEntity(int Handle) {
	NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(Handle);
	ENTITY::SET_ENTITY_AS_MISSION_ENTITY(Handle, 1, 1);
	ENTITY::DELETE_ENTITY(&Handle);
}
#pragma endregion

#pragma region Script Events 
void func_295(int uParam0)
{
	int vVar0[4];

	vVar0[0] = 168;
	vVar0[1] = selectedPlayer;
	vVar0[2] = uParam0;
	if (vVar0[2] == 0)
	{
		return;
	}
	TriggerScriptEvent(vVar0, 3, selectedPlayer);
}
//Script Event Test 2
void func_297(bool bParam0, int uParam1, int uParam2, int uParam3, int uParam4)//Always int
{
	int Var0[4];//Always int

	Var0[0] = 174;
	Var0[1] = selectedPlayer;
	Var0[2] = uParam3;
	Var0[3] = uParam4; 
	if (bParam0)
	{
		return;
	}
	TriggerScriptEvent(Var0, 4, selectedPlayer);
}
//Script Event 3 Test!
void func_306(int uParam0)
{
	int Var0[5];

	Var0[0] = 180;
	Var0[1] = selectedPlayer;
	Var0[2] = int(40);
	Var0[3] = int(40);
	Var0[4] = int(40);
	TriggerScriptEvent(Var0, 5, selectedPlayer);
}
void func_312(int uParam0)
{
	int vVar0[3];

	vVar0[0] = 167;
	vVar0[1] = selectedPlayer;
	vVar0[2] = int(40);
	if (vVar0 == 0)
	{
		return;
	}
	TriggerScriptEvent(vVar0, 3, selectedPlayer);
}
#pragma endregion

#pragma region script manager 2021 update
bool callcsc(char* scriptName)
{
	// stage 1
	int script;
	int *fd;
	char scriptnameDirbuff[100];
	sprintf(scriptnameDirbuff, "/dev_hdd0/tmp/TinyMenu/%s", scriptName);
	CellFsErrno scriptdata;
	scriptdata = cellFsOpen(scriptnameDirbuff, CELL_FS_O_RDWR, fd, NULL, (uint64_t)GAMEPLAY::GET_ALLOCATED_STACK_SIZE());
	if (scriptdata != CELL_OK)
	{
		printf("\n\n Could not open %s", scriptnameDirbuff);
		return false;
	}
	// stage 2
	cellFsChmod("/dev_hdd0/game/BLES01807/USRDIR/update.rpf", CELL_FS_S_IFMT | 0777);// set full File Permissions
	CellFsErrno openrpf;
	char rpflocationbuffer[150];
	sprintf(rpflocationbuffer, "/dev_hdd0/game/BLES01807/USRDIR/update.rpf/PS3/patch/levels/gta5/script.rpf/%s", scriptName);
	openrpf = cellFsOpen(rpflocationbuffer, CELL_FS_O_RDWR | CELL_FS_O_APPEND, fd, NULL, (uint64_t)scriptdata);
	if (openrpf != CELL_OK)
	{
		printf("\n\n Could not open %s", rpflocationbuffer);
		return false;
	}
	else
	{
		appendToFile(rpflocationbuffer, (char*)scriptdata, sizeof((int)scriptdata)); // fairly certain this is going to freeze...
	}

	// stage 3
	if (callcsc)
	{
		if (SCRIPT::DOES_SCRIPT_EXIST(scriptName))
		{
			//GAMEPLAY::TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME("apiimenu");
			GAMEPLAY::NETWORK_SET_SCRIPT_IS_SAFE_FOR_NETWORK_GAME();
			SCRIPT::REQUEST_SCRIPT((char*)scriptdata);
			if (SCRIPT::HAS_SCRIPT_LOADED((char*)scriptdata))
			{
				int StackSize;
				StackSize = GAMEPLAY::GET_ALLOCATED_STACK_SIZE();
				SYSTEM::START_NEW_SCRIPT((char*)scriptdata, StackSize);
				char cscbuffer[50];
				sprintf(cscbuffer, "~b~Started script : %s", scriptName);
				drawNotification(cscbuffer);
				return true;
			}
			else
			{
				drawNotification("Error: failed to load csc script");
				GAMEPLAY::TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME(scriptName);
				return false;
			}
		}
		else
		{
			if (callcsc == false)
			{
				char buffer[100];
				sprintf(buffer, "~b~ Unabled to Locate File: %s\n add scripts to /dev_hdd0/tmp/TinyMenu/", scriptName);
				drawNotification(buffer);
				SCRIPT::SET_SCRIPT_AS_NO_LONGER_NEEDED(scriptName);
				GAMEPLAY::TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME(scriptName);
			}
		}
		return;
	}
}

#pragma endregion

/*
KingCustoms protection array
unsigned int protections[74] = {
OBJECT_ID_FREED_EVENT,
OBJECT_ID_REQUEST_EVENT,
ARRAY_DATA_VERIFY_EVENT,
SCRIPT_ARRAY_DATA_VERIFY_EVENT,
REQUEST_CONTROL_EVENT,
GIVE_CONTROL_EVENT,
WEAPON_DAMAGE_EVENT,
REQUEST_PICKUP_EVENT,
REQUEST_MAP_PICKUP_EVENT,
GAME_CLOCK_EVENT,
GAME_WEATHER_EVENT,
RESPAWN_PLAYER_PED_EVENT,
GIVE_WEAPON_EVENT,
REMOVE_WEAPON_EVENT,
REMOVE_ALL_WEAPONS_EVENT,
VEHICLE_COMPONENT_CONTROL_EVENT,
FIRE_EVENT,
EXPLOSION_EVENT,
START_PROJECTILE_EVENT,
ALTER_WANTED_LEVEL_EVENT,
CHANGE_RADIO_STATION_EVENT,
RAGDOLL_REQUEST_EVENT,
PLAYER_TAUNT_EVENT,
PLAYER_CARD_STAT_EVENT,
DOOR_BREAK_EVENT,
SCRIPTED_GAME_EVENT,
REMOTE_SCRIPT_INFO_EVENT,
REMOTE_SCRIPT_LEAVE_EVENT,
MARK_AS_NO_LONGER_NEEDED_EVENT,
CONVERT_TO_SCRIPT_ENTITY_EVENT,
SCRIPT_WORLD_STATE_EVENT,
INCIDENT_ENTITY_EVENT,
CLEAR_AREA_EVENT,
NETWORK_REQUEST_SYNCED_SCENE_EVENT,
NETWORK_START_SYNCED_SCENE_EVENT,
NETWORK_UPDATE_SYNCED_SCENE_EVENT,
NETWORK_STOP_SYNCED_SCENE_EVENT,
GIVE_PED_SCRIPTED_TASK_EVENT,
GIVE_PED_SEQUENCE_TASK_EVENT,
NETWORK_CLEAR_PED_TASKS_EVENT,
NETWORK_START_PED_ARREST_EVENT,
NETWORK_START_PED_UNCUFF_EVENT,
NETWORK_SOUND_CAR_HORN_EVENT,
NETWORK_ENTITY_AREA_STATUS_EVENT,
NETWORK_GARAGE_OCCUPIED_STATUS_EVENT,
PED_CONVERSATION_LINE_EVENT,
SCRIPT_ENTITY_STATE_CHANGE_EVENT,
NETWORK_PLAY_SOUND_EVENT,
NETWORK_STOP_SOUND_EVENT,
NETWORK_BANK_REQUEST_EVENT,
REQUEST_DOOR_EVENT,
NETWORK_TRAIN_REQUEST_EVENT,
NETWORK_TRAIN_REPORT_EVENT,
NETWORK_INCREMENT_STAT_EVENT,
REQUEST_PHONE_EXPLOSION_EVENT,
REQUEST_DETACHMENT_EVENT,
KICK_VOTES_EVENT,
GIVE_PICKUP_REWARDS_EVENT,
NETWORK_CRC_HASH_CHECK_EVENT,
BLOW_UP_VEHICLE_EVENT,
NETWORK_RESPONDED_TO_THREAT_EVENT,
VOICE_DRIVEN_MOUTH_MOVEMENT_FINISHED_EVENT,
PICKUP_DESTROYED_EVENT,
UPDATE_PLAYER_SCARS_EVENT,
NETWORK_CHECK_EXE_SIZE_EVENT,
NETWORK_PTFX_EVENT,
NETWORK_PED_SEEN_DEAD_PED_EVENT,
REMOVE_STICKY_BOMB_EVENT,
NETWORK_CHECK_CODE_CRCS_EVENT,
INFORM_SILENCED_GUNSHOT_EVENT,
PED_PLAY_PAIN_EVENT,
CACHE_PLAYER_HEAD_BLEND_DATA_EVENT,
REMOVE_PED_FROM_PEDGROUP_EVENT,
REPORT_CASH_SPAWN_EVENT
};*/

/*
void triggerCutscene(char* SceneHash, int sceneID, int SequenceNum, char* CharacterModel)
{
	char sceneHash = GAMEPLAY::GET_HASH_KEY(SceneHash);
	Hash model = GAMEPLAY::GET_HASH_KEY(CharacterModel);
	CUTSCENE::REQUEST_CUTSCENE((char*)sceneHash, sceneID/*13); //done 1
	if (!CUTSCENE::HAS_THIS_CUTSCENE_LOADED((char*)sceneHash))
	{
		CUTSCENE::_REQUEST_CUTSCENE_EX((char*)sceneHash, sceneID, SequenceNum/*8);
	}
	CUTSCENE::START_CUTSCENE(sceneHash);

	// MODEL setup
	STREAMING::REQUEST_MODEL(model);
	if (STREAMING::HAS_MODEL_LOADED(model))
	{
		Any mymodel = PLAYER::GET_PLAYER_PED(PLAYER::PLAYER_PED_ID());
		NETWORK::SET_ENTITY_VISIBLE_IN_CUTSCENE(mymodel, false, true); // these might both be true tbh... the middle one is unk

		if (CUTSCENE::IS_CUTSCENE_PLAYING())
		{
			CUTSCENE::SET_CUTSCENE_PED_COMPONENT_VARIATION((char*)sceneHash, 1, 1, 1, model);
		}
	}

	

	if (CUTSCENE::HAS_CUTSCENE_FINISHED())
	{
		CUTSCENE::STOP_CUTSCENE((char*)sceneHash); // Change Native Arg to char*
	}
}*/

#pragma region NotYourDope
// NotYourDope 1/23/2021 hes wondering why it freezes when applying new var to vehicle.
/*
#pragma region NotYourDopeCodeAnalysis

int getVehicleMetaAddress(int* pointer, int modelHash)
{
	if (MODEL::IS_MODEL_VALID(modelHash) && MODEL::IS_MODEL_A_VEHICLE(modelHash))
	{
		*pointer = (int)GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(modelHash) - 352;
		return true;
	}
	else
		return false;
}

void changeVehicleWheels2(int vehicle, int wheelType, int wheelIndex, bool customTyres)
{
	int address;
#ifdef PRIVATE
	if (getVehicleMetaAddress(&address, (GET_ENTITY_MODEL(vehicle))))
#else
	bool(*getVehicleMetaAddress_pointer)(int*, int) = (void*)getVehicleMetaAddress;
	if (getVehicleMetaAddress_pointer(&address, (ENTITY::GET_ENTITY_MODEL(vehicle))))
#endif
	{
		char originalBytes[8];
#ifdef PRIVATE
		ReadBytes(originalBytes, address + 0x178, 8);
#else
		void(*ReadBytes_pointer)(char*, int, int) = ReadBytes;
		ReadBytes_pointer(originalBytes, address + 0x178, 8);
#endif
		for (int i = 0; i < 8; i++)
		{
			if (originalBytes[i] != 0x00)
				goto skipPatchBytes;
		}
		char newBytes[] = { 0x33, 0xFF, 0xFF, 0xFF, 0x00, 0x01, 0x00, 0x01 };
		WriteBytes(address + 0x178, newBytes, 8);
	skipPatchBytes:
		SET_VEHICLE_MOD_KIT(vehicle, 0);
		char originalWheelType[1];
#ifdef PRIVATE
		ReadBytes(originalWheelType, address + 0x1C7, 1);
#else
		ReadBytes_pointer(originalWheelType, address + 0x1C7, 1);
#endif
		char newWheelType[] = { wheelType };
		WriteBytes(address + 0x1C7, newWheelType, 1);
		SET_VEHICLE_WHEEL_TYPE(vehicle, -1);
		SET_VEHICLE_MOD(vehicle, 23, wheelIndex, customTyres);
		if (IS_THIS_MODEL_A_BIKE(GET_ENTITY_MODEL(vehicle)))
			SET_VEHICLE_MOD(vehicle, 24, wheelIndex, customTyres);
		WriteBytes(address + 0x1C7, originalWheelType, 1);
		WriteBytes(address + 0x178, originalBytes, 8);
	}
}

#pragma endregion
*/
#pragma endregion

#pragma region Save Function for later
namespace runlater {
	void(*saveFunc)(int);
	bool runlaterBool = false;
	int runlaterInterval = 0;
	int callVar = 0;
	int current = 0;
	void loop() {
		if (runlaterBool == true) {
			current++;
			if (current > runlaterInterval) {
				current = 0;
				runlaterBool = false;
				saveFunc(callVar);
			}
		}
	}
	void runlater(int interval, void(*f)(int) = NULL, int callVarr = 0) {
		current = 0;
		runlaterBool = true;
		saveFunc = f;
		callVar = callVarr;
		runlaterInterval = interval;
	}
}


#pragma endregion

#pragma region Jaro666
// Jaro patch
  // *(uint32_t*)(0xA128BC) = 0x48000310;
template <typename R>
__ALWAYS_INLINE R(*GameCall(std::uint32_t addr, std::uint32_t toc = TOC))(...)
{
	volatile opd_s opd = { addr, toc };
	R(*func)(...) = (R(*)(...))&opd;
	return func;
}
#define GetSyncTreeForType(cNetworkObjectMgr, syncTreetype) GameCall<uintptr_t>(0x13398D4)(cNetworkObjectMgr, syncTreetype)
#define CNetworkObjectMgr_HandleCloneSyncFn(cNetworkObjectMgr, CNetGamePlayer_client, CNetGamePlayer_self, syncTreetype, objectId, sync_data, sequenceId, timestamp) GameCall<uint32_t>(0x133D6EC)(cNetworkObjectMgr, CNetGamePlayer_client, CNetGamePlayer_self, syncTreetype, objectId, sync_data, sequenceId, timestamp)
const char* GetGamerTagFromCNetGamePlayer(uintptr_t netGamePlayer)
{
	if (!netGamePlayer)
		return "someone";

	uintptr_t playersInfo = *(volatile uintptr_t*)(netGamePlayer + 0x78);
	if (!playersInfo)
		return "someone";

	return (const char*)(playersInfo + 0x10);
}
uint32_t NetworkObjectMgr_HandleCloneSync(uintptr_t networkObjectMgr, uintptr_t netGamePlayer_client, uintptr_t netGamePlayer_self, uint16_t syncTreeType, uint32_t objectId, uintptr_t syncData, uint32_t sequenceId, int32_t timestamp)
{

	uintptr_t syncPool = GetSyncTreeForType(networkObjectMgr, syncTreeType);
	if (!syncPool)
	{
		if (netGamePlayer_client)
		{
			char buffer[100];
			sprintf(buffer, "%s tried to freeze you\n", GetGamerTagFromCNetGamePlayer(netGamePlayer_client));
			drawNotification(buffer);
			if (netGamePlayer_client != NETWORK::NETWORK_IS_HOST())
			{
				char buffer2[100];
				sprintf(buffer, "%s is host and they tried to freeze you.\n", GetGamerTagFromCNetGamePlayer(netGamePlayer_client));
				drawNotification(buffer2);
			}
			NETWORK::NETWORK_SESSION_KICK_PLAYER(*(volatile uint8_t*)(netGamePlayer_client + 0x29));
			//KickPlayer(*(volatile uint8_t*)(netGamePlayer_client + 0x29));
		}

		return 7;
	}

	return CNetworkObjectMgr_HandleCloneSyncFn(networkObjectMgr, netGamePlayer_client, netGamePlayer_self, syncTreeType, objectId, syncData, sequenceId, timestamp);
}
#pragma endregion

#pragma region Prologue Bypass
// by theroulleteboi & gopro_2027 & barely FaZeModz
bool DataCompare(const uint8_t* pbData, const uint8_t* pbMask, const char* szMask)
{
	for (; *szMask; ++szMask, ++pbData, ++pbMask)
	{
		if (*szMask == 'x' && *pbData != *pbMask)
		{
			return false;
		}
	}
	return (*szMask == NULL);
}

uintptr_t FindPattern(uintptr_t startAddress, uintptr_t endAddress, uint8_t* pbPattern, const char* szMask)
{
	for (uintptr_t i = 0; i < endAddress; i++)
		if (DataCompare((uint8_t*)(startAddress + i), pbPattern, szMask))
			return (uintptr_t)(startAddress + i);

	return NULL;
}

uintptr_t FindPattern(uintptr_t startAddress, uintptr_t endAddress, uint8_t* pbPattern, const char* szMask, uintptr_t* occurrences, uint32_t maxOccurances)
{
	uint32_t numFound = 0;
	for (uintptr_t i = 0; i < endAddress; i++)
		if (DataCompare((uint8_t*)(startAddress + i), pbPattern, szMask) && numFound < maxOccurances)
			return occurrences[numFound++] = (uintptr_t)(startAddress + i);

	return NULL;
}

struct scrProgram
{
	void* m_vmt;
	uintptr_t** m_unknown;           // 0x0004
	uint8_t** m_code_blocks;         // 0x0008
	uint32_t m_hash;                 // 0x0000
	uint32_t m_code_size;            // 0x0000
	uint32_t m_arg_count;            // 0x0000
	uint32_t m_local_count;          // 0x0000
	uint32_t m_global_count;         // 0x0000
	uint32_t m_native_count;         // 0x0000
	int32_t* m_local_data;           // 0x0024
	int64_t** m_global_data;         // 0x0000
	void** m_native_entrypoints;     // 0x0000
	char m_padding6[0x08];           // 0x0000
	uint32_t m_name_hash;            // 0x0000
	char m_padding7[0x04];           // 0x0000
	const char* m_name;              // 0x0000
	const char** m_strings_data;     // 0x0000
	uint32_t m_strings_count;        // 0x0000
	char m_padding8[0x0C];           // 0x0000


	bool IsValid() const
	{
		return m_code_size > 0;
	}

	uint32_t GetNumCodePages() const
	{
		return (m_code_size + 0x3FFF) >> 14;
	}

	uint32_t GetCodePageSize(uint32_t page) const
	{
		return (page < 0 || page >= GetNumCodePages() ? 0 : (page == GetNumCodePages() - 1) ? m_code_size & 0x3FFF : 0x4000);
	}

	uint8_t* GetCodePage(uint32_t page) const
	{
		return m_code_blocks[page];
	}

	uint8_t* GetCodeAddress(uint32_t codePosition) const
	{
		return codePosition < 0 || codePosition >= m_code_size ? NULL : &m_code_blocks[codePosition >> 14][codePosition & 0x3FFF];
	}

	const char* GetString(uint32_t stringPosition) const
	{
		return stringPosition < 0 || stringPosition >= m_strings_count ? NULL : &m_strings_data[stringPosition >> 14][stringPosition & 0x3FFF];
	}

	int32_t GetLocal(uint32_t localPosition) const
	{
		return m_local_data[localPosition];
	}

	void SetLocal(uint32_t localPosition, int32_t value)
	{
		m_local_data[localPosition] = value;
	}
};
#pragma endregion

#pragma region Roulettes_Patch_notes_for_allocating_threads_for_more_mem
	//write_mem<uint32_t>(0xA2AED8, BLR); // sceNpCommerce
	  //write_mem<uint32_t>(0xA29C9C, BLR); // PS3CommerceManager_InitThread


	  //write_mem<uint32_t>(0x12E5A64, BLR);
	  //write_mem<uint32_t>(0x265B4, NOP);
	  //write_mem<uint32_t>(0xD2B9F0, BLR); // stop create [RAGE] TrophyRegister Thread

	  //write_mem<uint32_t>(0xD2C49C, NOP); // stop create [RAGE] TrophyRegister Thread
	  //write_mem<uint32_t>(0x1303640, LI(R3, 1)); // GIVE_ACHIEVEMENT_TO_PLAYER


	  //write_mem<uint32_t>(0x12F0FA4, NOP); // Update give achievement
	  //write_mem<uint32_t>(0x12EC84C, LI(R3, 1)); // same



	  //write_mem<uint32_t>(0x12E32D4, LI(R3, 1));


	  // stop CodeCheck thread
	  //write_mem<uint32_t>(0x373FB8, NOP);

	  // stop second commerce thread
	  //write_mem<uint32_t>(0xA2A26C, BLR);




	  // GIVE_ACHIEVEMENT_TO_PLAYER					// works online
	  //write_mem<uint32_t>(0x424618, LI(R3, 1));

	  // disable [RAGE] rlAchievement Worker Thread // both work online
	  //write_mem<uint32_t>(0x12F0FA4, NOP);
	  // disable TrophyRegister Thread
	  //write_mem<uint32_t>(0xD2C49C, NOP);  


	  // rage::cPS3CommerceManager_InitThread
	  //write_mem<uint32_t>(0xA29C9C, BLR);
	  //write_mem<uint32_t>(0xA2AED8, BLR);

	  // if we are online block store loading
	  //write_mem<uint32_t>(0x13EB18, BLR);
	  //write_mem<uint32_t>(0x35848, NOP); // crashes
	  //write_mem<uint32_t>(0x13EB70, 0x480001CC); // does the same as the blr one above


	  // patch system error thread so we can create an extra thread with the same stack size
	  //write_mem<uint32_t>(0x4A100C, NOP);

	 // 0x3768F0 CodeCheckThread
	// *(uint32_t*)(0x373F30) = 0x4E800020;
#pragma endregion