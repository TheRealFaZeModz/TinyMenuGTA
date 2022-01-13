//Yea Nigga Other Loop Functions
#pragma region Modded Vehicles
bool doModdedT20;
bool spawnModdedT20()
{
	uint Handle = PLAYER::PLAYER_PED_ID();
	Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	//hash2_EMP
	Vector3 null; null.x = 0.0, null.y = 0.0; null.z = 0.0;
	Vector3 a; a.x = 0.0, a.y = 1.61, a.z = -0.12;//X Coord - Y Coord - Z Coord
	Vector3 b; b.x = -12.0, b.y = 0.0, b.z = 0.0;//Pitch - Roll - Yaw
												 
	Vector3 null1; null1.x = 0.0, null1.y = 0.0; null1.z = 0.0;
	Vector3 a1; a1.x = -0.60, a1.y = 1.60, a1.z = 0.20;
	Vector3 b1; b1.x = 0.0, b1.y = 0.0, b1.z = 88.0;
	//hash3_MiniGun2
	Vector3 null0; null0.x = 0.0, null0.y = 0.0; null0.z = 0.0;
	Vector3 a0; a0.x = 0.60, a0.y = 1.60, a0.z = 0.20;
	Vector3 b0; b0.x = 0.0, b0.y = 0.0, b0.z = 88.0;
	//hash4_FLWheel1
	Vector3 null2; null2.x = 0.0, null2.y = 0.0; null2.z = 0.0;
	Vector3 a2; a2.x = -0.94, a2.y = 1.32, a2.z = -0.25;
	Vector3 b2; b2.x = 9.0, b2.y = -28.0, b2.z = 87.0;
	//hash4_RLWheel1
	Vector3 null3; null3.x = 0.0, null3.y = 0.0; null3.z = 0.0;
	Vector3 a3; a3.x = -0.95, a3.y = -1.34, a3.z = -0.25f;
	Vector3 b3; b3.x = 9.0, b3.y = 38.0, b3.z = 87.0;
	//hash4_RFWheel1
	Vector3 null4; null4.x = 0.0, null4.y = 0.0; null4.z = 0.0;
	Vector3 a4; a4.x = 0.95, a4.y = 1.33, a4.z = -0.23;
	Vector3 b4; b4.x = 11.0, b4.y = 26.0, b4.z = -89.0;
	//hash4_RRWheel1
	Vector3 null5; null5.x = 0.0, null5.y = 0.0; null5.z = 0.0;
	Vector3 a5; a5.x = 0.96, a5.y = -1.31, a5.z = -0.23;
	Vector3 b5; b5.x = 10.0, b5.y = 20.0, b5.z = -92.0;

	int hash_T20 = GAMEPLAY::GET_HASH_KEY("t20");
	int hash2_EMP = GAMEPLAY::GET_HASH_KEY("hei_prop_heist_emp");
	int hash3_MiniGun = GAMEPLAY::GET_HASH_KEY("prop_minigun_01");
	int hash4_Wheel = GAMEPLAY::GET_HASH_KEY("prop_wheel_01");

	STREAMING::REQUEST_MODEL(hash_T20);
	STREAMING::REQUEST_MODEL(hash2_EMP);
	STREAMING::REQUEST_MODEL(hash3_MiniGun);
	STREAMING::REQUEST_MODEL(hash4_Wheel);

	if (STREAMING::HAS_MODEL_LOADED(hash_T20) && STREAMING::HAS_MODEL_LOADED(hash2_EMP) && STREAMING::HAS_MODEL_LOADED(hash3_MiniGun) && STREAMING::HAS_MODEL_LOADED(hash4_Wheel))
	{
		int EMP = OBJECT::CREATE_OBJECT(hash2_EMP, null.x, null.y, null.z, 1, 0, 1);
		int MiniGun = OBJECT::CREATE_OBJECT(hash3_MiniGun, null1.x, null1.y, null1.z, 1, 0, 1);
		int MiniGun2 = OBJECT::CREATE_OBJECT(hash3_MiniGun, null0.x, null0.y, null0.z, 1, 0, 1);
		int FLWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null2.x, null2.y, null2.z, 1, 0, 1);
		int RLWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null3.x, null3.y, null3.z, 1, 0, 1);
		int RFWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null4.x, null4.y, null4.z, 1, 0, 1);
		int RRWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null5.x, null5.y, null5.z, 1, 0, 1);

		if (ENTITY::DOES_ENTITY_EXIST(EMP) && ENTITY::DOES_ENTITY_EXIST(MiniGun) && ENTITY::DOES_ENTITY_EXIST(MiniGun2) && ENTITY::DOES_ENTITY_EXIST(FLWheel1) && ENTITY::DOES_ENTITY_EXIST(RLWheel1) && ENTITY::DOES_ENTITY_EXIST(RFWheel1) && ENTITY::DOES_ENTITY_EXIST(RRWheel1))
		{
			int Vehicle = VEHICLE::CREATE_VEHICLE(hash_T20, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);

			if (ENTITY::DOES_ENTITY_EXIST(Vehicle))
			{
				PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash_T20);
				ENTITY::SET_ENTITY_VISIBLE(Vehicle, true);
				ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), true);

				ENTITY::ATTACH_ENTITY_TO_ENTITY(EMP, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(MiniGun, Vehicle, 0, a1.x, a1.y, a1.z, b1.x, b1.y, b1.z, 0, 1, 0, 0, 2, 1);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(MiniGun2, Vehicle, 0, a0.x, a0.y, a0.z, b0.x, b0.y, b0.z, 0, 1, 0, 0, 2, 1);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(FLWheel1, Vehicle, 0, a2.x, a2.y, a2.z, b2.x, b2.y, b2.z, 0, 1, 0, 0, 2, 1);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(RLWheel1, Vehicle, 0, a3.x, a3.y, a3.z, b3.x, b3.y, b3.z, 0, 1, 0, 0, 2, 1);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(RFWheel1, Vehicle, 0, a4.x, a4.y, a4.z, b4.x, b4.y, b4.z, 0, 1, 0, 0, 2, 1);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(RRWheel1, Vehicle, 0, a5.x, a5.y, a5.z, b5.x, b5.y, b5.z, 0, 1, 0, 0, 2, 1);
				return true;
			}
			return false;
		}
		return false;
	}
	return false;
}


bool doBoatNTrailer;
bool spawnBoatNTrailer()
{
	uint Me = PLAYER::PLAYER_PED_ID();
	Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	Vector3 null; null.x = 0, null.y = 0; null.z = 0;
	Vector3 a; a.x = 0, a.y = -0.61, a.z = 0.28;
	Vector3 b; b.x = 0, b.y = 0, b.z = 0;
	int hash = GAMEPLAY::GET_HASH_KEY("boattrailer");
	int hash2 = GAMEPLAY::GET_HASH_KEY("suntrap");
	STREAMING::REQUEST_MODEL(hash);
	STREAMING::REQUEST_MODEL(hash2);
	if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
	{
		int Vehicle = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
		int Object = VEHICLE::CREATE_VEHICLE(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
		if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
		{
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
			ENTITY::SET_ENTITY_VISIBLE(Vehicle, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);
			ENTITY::SET_ENTITY_COLLISION(Object, 1, 0);
			return true;
		}
		return false;
	}
	return false;
}

bool doFlatBed;
bool spawnFlatBed()
{
	uint Me = PLAYER::PLAYER_PED_ID();
	Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	Vector3 null; null.x = 0, null.y = 0; null.z = 0;
	Vector3 a; a.x = 0, a.y = -2.0, a.z = 1.1;
	Vector3 b; b.x = 0, b.y = 0, b.z = 0;
	Vector3 null1; null1.x = 0, null1.y = 0; null1.z = 0;
	Vector3 a1; a1.x = -1.06, a1.y = -0.1, a1.z = 0.46;
	Vector3 b1; b1.x = 91.0, b1.y = 0, b1.z = 0;
	Vector3 null2; null2.x = 0, null2.y = 0; null2.z = 0;
	Vector3 a2; a2.x = -0.9, a2.y = 0.61, a2.z = 0.62;
	Vector3 b2; b2.x = 0.0, b2.y = 100.0, b2.z = 0;
	Vector3 null3; null3.x = 0, null3.y = 0; null3.z = 0;
	Vector3 a3; a3.x = 0.9, a3.y = 0.8, a3.z = 0.41;
	Vector3 b3; b3.x = -25.0, b3.y = 0, b3.z = 0;
	int hash = GAMEPLAY::GET_HASH_KEY("flatbed");
	int hash2 = GAMEPLAY::GET_HASH_KEY("t20");
	int hash3 = GAMEPLAY::GET_HASH_KEY("prop_tool_broom");
	int hash4 = GAMEPLAY::GET_HASH_KEY("prop_roadcone01a");
	int hash5 = GAMEPLAY::GET_HASH_KEY("prop_tool_box_02");
	STREAMING::REQUEST_MODEL(hash);
	STREAMING::REQUEST_MODEL(hash2);
	STREAMING::REQUEST_MODEL(hash3);
	STREAMING::REQUEST_MODEL(hash4);
	STREAMING::REQUEST_MODEL(hash5);
	if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2) && STREAMING::HAS_MODEL_LOADED(hash3) && STREAMING::HAS_MODEL_LOADED(hash4) && STREAMING::HAS_MODEL_LOADED(hash5))
	{
		int Vehicle = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
		int Object = VEHICLE::CREATE_VEHICLE(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
		int Broom = OBJECT::CREATE_OBJECT(hash3, null1.x, null1.y, null1.z, 1, 0, 1);
		int Cone = OBJECT::CREATE_OBJECT(hash4, null2.x, null2.y, null2.z, 1, 0, 1);
		int Tool = OBJECT::CREATE_OBJECT(hash5, null3.x, null3.y, null3.z, 1, 0, 1);
		if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object) && ENTITY::DOES_ENTITY_EXIST(Broom) && ENTITY::DOES_ENTITY_EXIST(Cone) && ENTITY::DOES_ENTITY_EXIST(Tool))
		{
			PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
			VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
			VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(Object, "tinymenu");
			VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
			ENTITY::SET_ENTITY_VISIBLE(Vehicle, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(Broom, Vehicle, 0, a1.x, a1.y, a1.z, b1.x, b1.y, b1.z, 0, false, 0, 0, 2, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(Cone, Vehicle, 0, a2.x, a2.y, a2.z, b2.x, b2.y, b2.z, 0, false, 0, 0, 2, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(Tool, Vehicle, 0, a3.x, a3.y, a3.z, b3.x, b3.y, b3.z, 0, false, 0, 0, 2, true);
			ENTITY::SET_ENTITY_COLLISION(Object, 1, 0);
			return true;
		}
		return false;
	}
	return false;
}
bool doTruck;
bool spawn_Truck()
{
	uint Me = PLAYER::PLAYER_PED_ID();
	Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	Vector3 null; null.x = 0, null.y = 0; null.z = 0;
	Vector3 a; a.x = 0, a.y = -2.0, a.z = 0.6;
	Vector3 b; b.x = 0, b.y = 0, b.z = 0;
	int hash = GAMEPLAY::GET_HASH_KEY("guardian");
	int hash2 = GAMEPLAY::GET_HASH_KEY("blazer");
	STREAMING::REQUEST_MODEL(hash);
	STREAMING::REQUEST_MODEL(hash2);
	if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
	{
		int Vehicle = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
		int Object = VEHICLE::CREATE_VEHICLE(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
		if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
		{
			PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
			ENTITY::SET_ENTITY_VISIBLE(Vehicle, true);
			ENTITY::SET_ENTITY_PROOFS(Vehicle, 1, 1, 1, 1, 1, 1, 1, 1);
			VEHICLE::SET_VEHICLE_CAN_BE_VISIBLY_DAMAGED(Vehicle, false);
			VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(Vehicle, false);
			VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(Vehicle, "GAMING");
			VEHICLE::SET_VEHICLE_MOD_KIT(Vehicle, 0);
			VEHICLE::TOGGLE_VEHICLE_MOD(Vehicle, 18, 1);
			VEHICLE::TOGGLE_VEHICLE_MOD(Vehicle, 22, 1);
			VEHICLE::SET_VEHICLE_MOD(Vehicle, 16, 5, 0);
			VEHICLE::SET_VEHICLE_MOD(Vehicle, 12, 2, 0);
			VEHICLE::SET_VEHICLE_MOD(Vehicle, 11, 3, 0);
			VEHICLE::SET_VEHICLE_MOD(Vehicle, 14, 14, 0);
			VEHICLE::SET_VEHICLE_MOD(Vehicle, 15, 3, 0);
			VEHICLE::SET_VEHICLE_MOD(Vehicle, 13, 2, 0);
			VEHICLE::SET_VEHICLE_WHEEL_TYPE(Vehicle, 6);
			VEHICLE::SET_VEHICLE_WINDOW_TINT(Vehicle, 5);
			VEHICLE::SET_VEHICLE_MOD(Vehicle, 23, 19, 1);
			VEHICLE::SET_VEHICLE_MOD(Vehicle, 0, 1, 0);
			VEHICLE::SET_VEHICLE_MOD(Vehicle, 1, 1, 0);
			VEHICLE::SET_VEHICLE_MOD(Vehicle, 2, 1, 0);
			VEHICLE::SET_VEHICLE_MOD(Vehicle, 3, 1, 0);
			VEHICLE::SET_VEHICLE_MOD(Vehicle, 4, 1, 0);
			VEHICLE::SET_VEHICLE_MOD(Vehicle, 5, 1, 0);
			VEHICLE::SET_VEHICLE_MOD(Vehicle, 6, 1, 0);
			VEHICLE::SET_VEHICLE_MOD(Vehicle, 7, 1, 0);
			VEHICLE::SET_VEHICLE_MOD(Vehicle, 8, 1, 0);
			VEHICLE::SET_VEHICLE_MOD(Vehicle, 9, 1, 0);
			VEHICLE::SET_VEHICLE_MOD(Vehicle, 10, 1, 0);
			VEHICLE::TOGGLE_VEHICLE_MOD(Vehicle, 20, 1);
			VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(Object, "tinymenu");
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 0, 0, 0);
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 0, 0);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);
			ENTITY::SET_ENTITY_COLLISION(Object, 1, 0);
			return true;
		}
		return false;
	}
	return false;
}

bool doJetSki;
bool spawnJetSki()
{
	uint Me = PLAYER::PLAYER_PED_ID();
	Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	Vector3 null; null.x = 0, null.y = 0; null.z = 0.;
	Vector3 a; a.x = -0.625, a.y = -1.9, a.z = -0.09;
	Vector3 b; b.x = 0, b.y = 0, b.z = 0;
	Vector3 a1; a1.x = 0.625, a1.y = -1.9, a1.z = -0.09;
	Vector3 b1; b1.x = 0, b1.y = 0, b1.z = 0;

	Vector3 a2; a2.x = 0.0, a2.y = 0.9, a2.z = -0.45;
	Vector3 b2; b2.x = 0, b2.y = 0, b2.z = 180.0;

	int hash = GAMEPLAY::GET_HASH_KEY("boattrailer");
	int hash2 = GAMEPLAY::GET_HASH_KEY("seashark");
	int hash3 = GAMEPLAY::GET_HASH_KEY("prop_tool_box_05");
	STREAMING::REQUEST_MODEL(hash);
	STREAMING::REQUEST_MODEL(hash2);
	STREAMING::REQUEST_MODEL(hash3);

	if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2) && STREAMING::HAS_MODEL_LOADED(hash3))
	{
		int Vehicle = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
		int Object = VEHICLE::CREATE_VEHICLE(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
		int Object1 = VEHICLE::CREATE_VEHICLE(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
		int Object2 = OBJECT::CREATE_OBJECT(hash3, null.x, null.y, null.z, 1, 0, 1);
		if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object) && ENTITY::DOES_ENTITY_EXIST(Object1) && ENTITY::DOES_ENTITY_EXIST(Object2))
		{
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
			ENTITY::SET_ENTITY_VISIBLE(Vehicle, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(Object1, Vehicle, 0, a1.x, a1.y, a1.z, b1.x, b1.y, b1.z, 0, false, 0, 0, 2, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(Object2, Vehicle, 0, a2.x, a2.y, a2.z, b2.x, b2.y, b2.z, 0, false, 0, 0, 2, true);
			ENTITY::SET_ENTITY_COLLISION(Object, 1, 0);
			ENTITY::SET_ENTITY_COLLISION(Object1, 1, 0);
			return true;
		}
		return false;
	}
	return false;
}

bool doCustom01;
bool spawnCustom01()
{
	uint Me = PLAYER::PLAYER_PED_ID();
	Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	Vector3 null; null.x = 0, null.y = 0; null.z = 0;
	Vector3 a; a.x = 0, a.y = -0.61, a.z = 0.28;
	Vector3 b; b.x = 0, b.y = 0, b.z = 0;
	int hash = GAMEPLAY::GET_HASH_KEY("boattrailer");
	int hash2 = GAMEPLAY::GET_HASH_KEY("suntrap");
	STREAMING::REQUEST_MODEL(hash);
	STREAMING::REQUEST_MODEL(hash2);
	if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
	{
		int Vehicle = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
		int Object = VEHICLE::CREATE_VEHICLE(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
		if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
		{
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
			ENTITY::SET_ENTITY_VISIBLE(Vehicle, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);
			return true;
		}
		return false;
	}
	return false;
}

bool doRampTruck;
bool RampTruck()
{
	uint Me = PLAYER::PLAYER_PED_ID();
	Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	Vector3 null; null.x = 0, null.y = 0; null.z = 0;
	Vector3 a; a.x = 0, a.y = 10.0, a.z = -0.3;
	Vector3 b; b.x = 0, b.y = -147.0, b.z = 90.0;
	int hash = GAMEPLAY::GET_HASH_KEY("phantom");
	int hash2 = GAMEPLAY::GET_HASH_KEY("prop_lev_des_barge_01");
	STREAMING::REQUEST_MODEL(hash);
	STREAMING::REQUEST_MODEL(hash2);
	if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
	{
		int Vehicle = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
		int Object = OBJECT::CREATE_OBJECT(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
		if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
		{
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
			PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
			ENTITY::SET_ENTITY_VISIBLE(Vehicle, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);
			ENTITY::SET_ENTITY_COLLISION(Object, 1, 0);
			return true;
		}
		return false;
	}
	return false;
}

bool doBusTruck;
bool BusTruck()
{
	uint Me = PLAYER::PLAYER_PED_ID();
	Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	Vector3 null; null.x = 0, null.y = 0; null.z = 0;
	Vector3 a; a.x = 0, a.y = 0, a.z = 0;
	Vector3 b; b.x = 0, b.y = 0, b.z = 0;
	int hash = GAMEPLAY::GET_HASH_KEY("monster");
	int hash2 = GAMEPLAY::GET_HASH_KEY("riot");
	STREAMING::REQUEST_MODEL(hash);
	STREAMING::REQUEST_MODEL(hash2);
	if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
	{
		int Vehicle = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
		int Object = VEHICLE::CREATE_VEHICLE(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
		if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
		{
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
			PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
			ENTITY::SET_ENTITY_VISIBLE(Vehicle, true);
			VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
			VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);
			return true;
		}
		return false;
	}
	return false;
}

bool doBufCustom;
bool BufCustom()
{
	uint Me = PLAYER::PLAYER_PED_ID();
	Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	Vector3 null; null.x = 0, null.y = 0; null.z = 0;
	Vector3 a; a.x = 0, a.y = 0, a.z = 0;
	Vector3 b; b.x = 0, b.y = 0, b.z = 0;
	int hash = GAMEPLAY::GET_HASH_KEY("police2");
	int hash2 = GAMEPLAY::GET_HASH_KEY("buffalo2");
	STREAMING::REQUEST_MODEL(hash);
	STREAMING::REQUEST_MODEL(hash2);
	if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
	{
		int Vehicle = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
		int Object = VEHICLE::CREATE_VEHICLE(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
		if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
		{
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
			PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
			ENTITY::SET_ENTITY_VISIBLE(Vehicle, true);
			VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
			VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
			VEHICLE::SET_VEHICLE_WINDOW_TINT(Vehicle, 5);
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 0, 0, 0);
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 0, 0);
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 0, 0, 0);
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 0, 0, 0);
			VEHICLE::SET_VEHICLE_EXTRA_COLOURS(Object, 0, 0);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);
			return true;
		}
		return false;
	}
	return false;
}

bool doInsurg;
bool Insurg()
{
	uint Me = PLAYER::PLAYER_PED_ID();
	Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	Vector3 null; null.x = 0, null.y = 0; null.z = 0;
	Vector3 a; a.x = 0, a.y = 0, a.z = 0;
	Vector3 b; b.x = 0, b.y = 0, b.z = 0;
	int hash = GAMEPLAY::GET_HASH_KEY("insurgent");
	int hash2 = GAMEPLAY::GET_HASH_KEY("insurgent2");
	STREAMING::REQUEST_MODEL(hash);
	STREAMING::REQUEST_MODEL(hash2);
	if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
	{
		int Vehicle = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
		int Object = VEHICLE::CREATE_VEHICLE(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
		if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
		{
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
			PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
			ENTITY::SET_ENTITY_VISIBLE(Vehicle, true);
			VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
			VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 0, 0, 0);
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 0, 0);
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 0, 0, 0);
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 0, 0, 0);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);
			return true;
		}
		return false;
	}
	return false;
}

bool doSuper1;
bool Super1()
{
	uint Me = PLAYER::PLAYER_PED_ID();
	Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	Vector3 null; null.x = 0, null.y = 0; null.z = 0;
	Vector3 a; a.x = 0, a.y = 0, a.z = -0.25;
	Vector3 b; b.x = 0, b.y = 0, b.z = 0;
	int hash = GAMEPLAY::GET_HASH_KEY("t20");
	int hash2 = GAMEPLAY::GET_HASH_KEY("cheetah");
	STREAMING::REQUEST_MODEL(hash);
	STREAMING::REQUEST_MODEL(hash2);
	if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
	{
		int Vehicle = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
		int Object = VEHICLE::CREATE_VEHICLE(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
		if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
		{
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
			PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
			ENTITY::SET_ENTITY_VISIBLE(Vehicle, true);
			VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
			VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 0, 0, 0);
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 0, 0);
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 0, 0, 0);
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 0, 0, 0);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);
			return true;
		}
		return false;
	}
	return false;
}

bool doSuper2;
bool Super2()
{
	uint Me = PLAYER::PLAYER_PED_ID();
	Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	Vector3 null; null.x = 0, null.y = 0; null.z = 0;
	Vector3 a; a.x = 0, a.y = 0, a.z = 0;
	Vector3 b; b.x = 0, b.y = 0, b.z = 0;
	int hash = GAMEPLAY::GET_HASH_KEY("feltzer2");
	int hash2 = GAMEPLAY::GET_HASH_KEY("rapidgt");
	STREAMING::REQUEST_MODEL(hash);
	STREAMING::REQUEST_MODEL(hash2);
	if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
	{
		int Vehicle = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
		int Object = VEHICLE::CREATE_VEHICLE(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
		if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
		{
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
			PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
			ENTITY::SET_ENTITY_VISIBLE(Vehicle, true);
			VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
			VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 0, 0, 0);
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 0, 0);
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 0, 0, 0);
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 0, 0, 0);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);
			return true;
		}
		return false;
	}
	return false;
}

bool doMuscle1;
bool Muscle1()
{
	uint Me = PLAYER::PLAYER_PED_ID();
	Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	Vector3 null; null.x = 0, null.y = 0; null.z = 0;
	Vector3 a; a.x = 0, a.y = 0, a.z = -0.2;
	Vector3 b; b.x = 0, b.y = 0, b.z = 0;
	int hash = GAMEPLAY::GET_HASH_KEY("hotknife");
	int hash2 = GAMEPLAY::GET_HASH_KEY("jb700");
	STREAMING::REQUEST_MODEL(hash);
	STREAMING::REQUEST_MODEL(hash2);
	if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
	{
		int Vehicle = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
		int Object = VEHICLE::CREATE_VEHICLE(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
		if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
		{
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
			PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
			ENTITY::SET_ENTITY_VISIBLE(Vehicle, true);
			VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
			VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 0, 0, 0);
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 0, 0);
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 0, 0, 0);
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 0, 0, 0);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);
			return true;
		}
		return false;
	}
	return false;
}

bool doMuscle2;
bool Muscle2()
{
	uint Me = PLAYER::PLAYER_PED_ID();
	Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	Vector3 null; null.x = 0, null.y = 0; null.z = 0;
	Vector3 a; a.x = 0, a.y = 0, a.z = 2.0;
	Vector3 b; b.x = 0, b.y = 0, b.z = 0;
	int hash = GAMEPLAY::GET_HASH_KEY("coquette2");
	int hash2 = GAMEPLAY::GET_HASH_KEY("hotknife");
	STREAMING::REQUEST_MODEL(hash);
	STREAMING::REQUEST_MODEL(hash2);
	if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
	{
		int Vehicle = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
		int Object = VEHICLE::CREATE_VEHICLE(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
		if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
		{
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
			PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
			ENTITY::SET_ENTITY_VISIBLE(Vehicle, true);
			VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
			VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 0, 0, 0);
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 0, 0);
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 0, 0, 0);
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 0, 0, 0);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);
			return true;
		}
		return false;
	}
	return false;
}

bool doSpecial1;
bool Special1()
{
	uint Me = PLAYER::PLAYER_PED_ID();
	Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	Vector3 null; null.x = 0, null.y = 0; null.z = 0;
	Vector3 a; a.x = 0, a.y = 0, a.z = 0;
	Vector3 b; b.x = 0, b.y = 0, b.z = 0;
	int hash = GAMEPLAY::GET_HASH_KEY("zentorno");
	int hash2 = GAMEPLAY::GET_HASH_KEY("kuruma2");
	STREAMING::REQUEST_MODEL(hash);
	STREAMING::REQUEST_MODEL(hash2);
	if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
	{
		int Vehicle = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
		int Object = VEHICLE::CREATE_VEHICLE(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
		if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
		{
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
			PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
			ENTITY::SET_ENTITY_VISIBLE(Vehicle, true);
			VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
			VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 0, 0, 0);
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 0, 0);
			VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(Object, "tinymenu");
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 0, 0, 0);
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 0, 0, 0);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);
			return true;
		}
		return false;
	}
	return false;
}

bool doSpecial2;
bool Special2()
{
	uint Me = PLAYER::PLAYER_PED_ID();
	Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	Vector3 null; null.x = 0, null.y = 0; null.z = 0;
	Vector3 a; a.x = 0, a.y = 1, a.z = 0.8;
	Vector3 b; b.x = 0, b.y = 0, b.z = 0;
	int hash = GAMEPLAY::GET_HASH_KEY("buzzard");
	int hash2 = GAMEPLAY::GET_HASH_KEY("submersible");
	STREAMING::REQUEST_MODEL(hash);
	STREAMING::REQUEST_MODEL(hash2);
	if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
	{
		int Vehicle = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
		int Object = VEHICLE::CREATE_VEHICLE(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
		if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
		{
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
			PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
			ENTITY::SET_ENTITY_VISIBLE(Vehicle, true);
			VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
			VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 0, 0, 0);
			// VEHICLE::SET_VEHICLE_COLOURS(Vehicle, 42, 0);
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 0, 0);
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 255, 149, 0);
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 0, 0, 0);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);
			return true;
		}
		return false;
	}
	return false;
}

bool doSpecial3;
bool Special3()
{
	uint Me = PLAYER::PLAYER_PED_ID();
	Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	Vector3 null; null.x = 0, null.y = 0; null.z = 0;
	Vector3 a; a.x = 0, a.y = -2.0, a.z = 1.1;
	Vector3 b; b.x = 0, b.y = 0, b.z = 0;
	Vector3 null1; null1.x = 0, null1.y = 0; null1.z = 0;
	Vector3 a1; a1.x = -1.06, a1.y = -0.1, a1.z = 0.46;
	Vector3 b1; b1.x = 91.0, b1.y = 0, b1.z = 0;
	Vector3 null2; null2.x = 0, null2.y = 0; null2.z = 0;
	Vector3 a2; a2.x = -0.9, a2.y = 0.61, a2.z = 0.62;
	Vector3 b2; b2.x = 0.0, b2.y = 100.0, b2.z = 0;
	Vector3 null3; null3.x = 0, null3.y = 0; null3.z = 0;
	Vector3 a3; a3.x = 0.9, a3.y = 0.8, a3.z = 0.41;
	Vector3 b3; b3.x = -25.0, b3.y = 0, b3.z = 0;
	int hash = GAMEPLAY::GET_HASH_KEY("flatbed");
	int hash2 = GAMEPLAY::GET_HASH_KEY("slamvan2");
	int hash3 = GAMEPLAY::GET_HASH_KEY("prop_tool_broom");
	int hash4 = GAMEPLAY::GET_HASH_KEY("prop_roadcone01a");
	int hash5 = GAMEPLAY::GET_HASH_KEY("prop_tool_box_02");
	STREAMING::REQUEST_MODEL(hash);
	STREAMING::REQUEST_MODEL(hash2);
	STREAMING::REQUEST_MODEL(hash3);
	STREAMING::REQUEST_MODEL(hash4);
	STREAMING::REQUEST_MODEL(hash5);
	if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2) && STREAMING::HAS_MODEL_LOADED(hash3) && STREAMING::HAS_MODEL_LOADED(hash4) && STREAMING::HAS_MODEL_LOADED(hash5))
	{
		int Vehicle = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
		int Object = VEHICLE::CREATE_VEHICLE(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
		int Broom = OBJECT::CREATE_OBJECT(hash3, null1.x, null1.y, null1.z, 1, 0, 1);
		int Cone = OBJECT::CREATE_OBJECT(hash4, null2.x, null2.y, null2.z, 1, 0, 1);
		int Tool = OBJECT::CREATE_OBJECT(hash5, null3.x, null3.y, null3.z, 1, 0, 1);
		if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object) && ENTITY::DOES_ENTITY_EXIST(Broom) && ENTITY::DOES_ENTITY_EXIST(Cone) && ENTITY::DOES_ENTITY_EXIST(Tool))
		{
			PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
			VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 8, 17, 30);
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 30, 1);
			VEHICLE::SET_VEHICLE_EXTRA_COLOURS(Object, 92, 0);
			VEHICLE::SET_VEHICLE_COLOURS(Object, 12, 53);
			VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(Object, "tinymenu");
			VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(Object, 1);
			VEHICLE::TOGGLE_VEHICLE_MOD(Object, 18, 1);
			VEHICLE::TOGGLE_VEHICLE_MOD(Object, 22, 1);
			VEHICLE::SET_VEHICLE_MOD(Object, 11, 3, 0);
			VEHICLE::SET_VEHICLE_MOD(Object, 14, 14, 0);
			VEHICLE::SET_VEHICLE_MOD(Object, 15, 3, 0);
			VEHICLE::SET_VEHICLE_MOD(Object, 13, 2, 0);
			VEHICLE::SET_VEHICLE_WHEEL_TYPE(Object, 6);
			VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
			VEHICLE::SET_VEHICLE_MOD(Object, 23, 18, 1);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
			ENTITY::SET_ENTITY_VISIBLE(Vehicle, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(Broom, Vehicle, 0, a1.x, a1.y, a1.z, b1.x, b1.y, b1.z, 0, false, 0, 0, 2, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(Cone, Vehicle, 0, a2.x, a2.y, a2.z, b2.x, b2.y, b2.z, 0, false, 0, 0, 2, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(Tool, Vehicle, 0, a3.x, a3.y, a3.z, b3.x, b3.y, b3.z, 0, false, 0, 0, 2, true);
			return true;
		}
		return false;
	}
	return false;
}

bool doSpecial4;
bool Special4()
{
	uint Me = PLAYER::PLAYER_PED_ID();
	Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	Vector3 null; null.x = 0, null.y = 0; null.z = 0.;

	Vector3 a; a.x = 0.0, a.y = 0.0, a.z = 0.6;		// seashark 1 - 0.7 worked just hard to get on .. infront and behind wings only way to get on the sharks ...
	Vector3 b; b.x = 0, b.y = 0, b.z = 0;

	Vector3 a1; a1.x = 0.0, a1.y = -4.0, a1.z = 0.6;  // seashark 2
	Vector3 b1; b1.x = 0, b1.y = 0, b1.z = 0;


	Vector3 a2; a2.x = 0.0, a2.y = 0.9, a2.z = -0.45;
	Vector3 b2; b2.x = 0, b2.y = 0, b2.z = 180.0;

	int hash = GAMEPLAY::GET_HASH_KEY("hydra");
	int hash2 = GAMEPLAY::GET_HASH_KEY("seashark");
	int hash3 = GAMEPLAY::GET_HASH_KEY("prop_tool_box_05"); // turn this into something usefull maybe another sea shark ...
	STREAMING::REQUEST_MODEL(hash);
	STREAMING::REQUEST_MODEL(hash2);
	STREAMING::REQUEST_MODEL(hash3);

	if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2) && STREAMING::HAS_MODEL_LOADED(hash3))
	{
		int Vehicle = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
		int Object = VEHICLE::CREATE_VEHICLE(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
		int Object1 = VEHICLE::CREATE_VEHICLE(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
		int Object2 = OBJECT::CREATE_OBJECT(hash3, null.x, null.y, null.z, 1, 0, 1);
		if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object) && ENTITY::DOES_ENTITY_EXIST(Object1) && ENTITY::DOES_ENTITY_EXIST(Object2))
		{
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
			ENTITY::SET_ENTITY_VISIBLE(Vehicle, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(Object1, Vehicle, 0, a1.x, a1.y, a1.z, b1.x, b1.y, b1.z, 0, false, 0, 0, 2, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(Object2, Vehicle, 0, a2.x, a2.y, a2.z, b2.x, b2.y, b2.z, 0, false, 0, 0, 2, true);
			ENTITY::SET_ENTITY_COLLISION(Object, 1, 0);
			ENTITY::SET_ENTITY_COLLISION(Object1, 1, 0);
			return true;
		}
		return false;
	}
	return false;
}
bool doSpecial5;
bool Special5()
{
	uint Handle = PLAYER::PLAYER_PED_ID();
	Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	//hash2_PANTO
	Vector3 null; null.x = 0.0, null.y = 0.0; null.z = 0.0;
	Vector3 a; a.x = 0.0, a.y = 0.0, a.z = -0.2;//X Coord - Y Coord - Z Coord
	Vector3 b; b.x = 0.0, b.y = 0.0, b.z = 0.0;//Pitch - Roll - Yaw
											   //hash3_MiniGun
	Vector3 null1; null1.x = 0.0, null1.y = 0.0; null1.z = 0.0;
	Vector3 a1; a1.x = -0.60, a1.y = 1.60, a1.z = 0.20;
	Vector3 b1; b1.x = 0.0, b1.y = 0.0, b1.z = 88.0;
	//hash3_MiniGun2
	Vector3 null0; null0.x = 0.0, null0.y = 0.0; null0.z = 0.0;
	Vector3 a0; a0.x = 0.60, a0.y = 1.60, a0.z = 0.20;
	Vector3 b0; b0.x = 0.0, b0.y = 0.0, b0.z = 88.0;
	//hash4_WindScreen _ VANISHED NEEDS FIXING
	Vector3 null2; null2.x = 0.0, null2.y = 0.0; null2.z = 0.0;
	Vector3 a2; a2.x = 0.3, a2.y = 0.41, a2.z = 0.50;
	Vector3 b2; b2.x = -45.3, b2.y = 0.0, b2.z = -179.0;//87
														//hash4_RLWheel1
	Vector3 null3; null3.x = 0.0, null3.y = 0.0; null3.z = 0.0;
	Vector3 a3; a3.x = -0.90, a3.y = -1.2, a3.z = 0.0; // -0.23
	Vector3 b3; b3.x = 0.0, b3.y = 0.0, b3.z = 86.0;
	//hash4_RFWindScreen 
	Vector3 null4; null4.x = 0.0, null4.y = 0.0; null4.z = 0.0;
	Vector3 a4; a4.x = -0.3, a4.y = 0.41, a4.z = 0.5;
	Vector3 b4; b4.x = -45.3, b4.y = 0.0, b4.z = -179.0;
	//hash4_RRWheel1
	Vector3 null5; null5.x = 0.0, null5.y = 0.0; null5.z = 0.0;
	Vector3 a5; a5.x = 0.92, a5.y = -1.2, a5.z = 0.01;
	Vector3 b5; b5.x = 0.0, b5.y = 0.0, b5.z = -92.0;
	//PUNTO -- FUCK UP NEEDS FIXING 
	Vector3 null6; null6.x = 0, null6.y = 0; null6.z = 0;
	Vector3 a6; a6.x = 0.0, a6.y = 0.0, a6.z = -0.2;
	Vector3 b6; b6.x = 0.0, b6.y = 0.0, b6.z = 0.0;
	//SIDES LEFT
	Vector3 null7; null7.x = 0, null7.y = 0; null7.z = 0;
	Vector3 a7; a7.x = -0.75, a7.y = 0.7, a7.z = -0.3;
	Vector3 b7; b7.x = 90.0, b7.y = 0.0, b7.z = 0.0;
	//SIDES RIGHT
	Vector3 null8; null8.x = 0, null8.y = 0; null8.z = 0;
	Vector3 a8; a8.x = 0.75, a8.y = 0.7, a8.z = -0.3;
	Vector3 b8; b8.x = 90.0, b8.y = 0.0, b8.z = 0.0;

	int hash = GAMEPLAY::GET_HASH_KEY("hotknife");
	int hash2_EMP = GAMEPLAY::GET_HASH_KEY("hei_prop_heist_emp");
	int hash3_MiniGun = GAMEPLAY::GET_HASH_KEY("prop_minigun_01");
	int hash4_Wheel = GAMEPLAY::GET_HASH_KEY("prop_wheel_01");
	int hash2 = GAMEPLAY::GET_HASH_KEY("panto");
	int hashWindow = GAMEPLAY::GET_HASH_KEY("prop_ballistic_shield");
	int hashSides = GAMEPLAY::GET_HASH_KEY("prop_cons_plank");




	STREAMING::REQUEST_MODEL(hashWindow);// WINDOW
	STREAMING::REQUEST_MODEL(hash2_EMP); // PANTO
	STREAMING::REQUEST_MODEL(hash3_MiniGun); // GUNS
	STREAMING::REQUEST_MODEL(hash4_Wheel); // back wheels
	STREAMING::REQUEST_MODEL(hash);
	STREAMING::REQUEST_MODEL(hash2);
	STREAMING::REQUEST_MODEL(hashSides); // SIDE SKIRTS

	if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hashSides) && STREAMING::HAS_MODEL_LOADED(hashWindow) && STREAMING::HAS_MODEL_LOADED(hash2_EMP) && STREAMING::HAS_MODEL_LOADED(hash3_MiniGun) && STREAMING::HAS_MODEL_LOADED(hash2) && STREAMING::HAS_MODEL_LOADED(hash4_Wheel))
	{
		int EMP = OBJECT::CREATE_OBJECT(hash2_EMP, null.x, null.y, null.z, 1, 0, 1);
		int MiniGun = OBJECT::CREATE_OBJECT(hash3_MiniGun, null1.x, null1.y, null1.z, 1, 0, 1);
		int MiniGun2 = OBJECT::CREATE_OBJECT(hash3_MiniGun, null0.x, null0.y, null0.z, 1, 0, 1);
		int WINDOW_1 = OBJECT::CREATE_OBJECT(hashWindow, null2.x, null2.y, null2.z, 1, 0, 1);
		int RLWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null3.x, null3.y, null3.z, 1, 0, 1);
		int WINDOW_2 = OBJECT::CREATE_OBJECT(hashWindow, null4.x, null4.y, null4.z, 1, 0, 1);
		int RRWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null5.x, null5.y, null5.z, 1, 0, 1);
		int Object = VEHICLE::CREATE_VEHICLE(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
		int LeftSide = OBJECT::CREATE_OBJECT(hashSides, null7.x, null7.y, null7.z, 1, 0, 1);
		int RightSide = OBJECT::CREATE_OBJECT(hashSides, null8.x, null8.y, null8.z, 1, 0, 1);


		if (ENTITY::DOES_ENTITY_EXIST(EMP) && ENTITY::DOES_ENTITY_EXIST(LeftSide) && ENTITY::DOES_ENTITY_EXIST(RightSide) && ENTITY::DOES_ENTITY_EXIST(MiniGun) && ENTITY::DOES_ENTITY_EXIST(MiniGun2) && ENTITY::DOES_ENTITY_EXIST(WINDOW_1) && ENTITY::DOES_ENTITY_EXIST(RLWheel1) && ENTITY::DOES_ENTITY_EXIST(WINDOW_2) && ENTITY::DOES_ENTITY_EXIST(RRWheel1))
		{
			int Vehicle = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);

			if (ENTITY::DOES_ENTITY_EXIST(Vehicle))
			{
				PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
				ENTITY::SET_ENTITY_VISIBLE(Vehicle, true);
				ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), true);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
				PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
				ENTITY::SET_ENTITY_VISIBLE(Vehicle, true);
				VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
				VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
				VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 0, 0, 0);
				VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 0, 0);
				VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 0, 0, 0);
				VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 0, 0, 0);
				VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(Vehicle, "tinymenu");
				VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(Object, "tinymenu");
				VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(Vehicle, 1);
				VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(Object, 1);

				ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(EMP, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(MiniGun, Vehicle, 0, a1.x, a1.y, a1.z, b1.x, b1.y, b1.z, 0, 1, 0, 0, 2, 1);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(MiniGun2, Vehicle, 0, a0.x, a0.y, a0.z, b0.x, b0.y, b0.z, 0, 1, 0, 0, 2, 1);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(WINDOW_1, Vehicle, 0, a2.x, a2.y, a2.z, b2.x, b2.y, b2.z, 0, 1, 0, 0, 2, 1);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(RLWheel1, Vehicle, 0, a3.x, a3.y, a3.z, b3.x, b3.y, b3.z, 0, 1, 0, 0, 2, 1);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(WINDOW_2, Vehicle, 0, a4.x, a4.y, a4.z, b4.x, b4.y, b4.z, 0, 1, 0, 0, 2, 1);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(RRWheel1, Vehicle, 0, a5.x, a5.y, a5.z, b5.x, b5.y, b5.z, 0, 1, 0, 0, 2, 1);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(LeftSide, Vehicle, 0, a7.x, a7.y, a7.z, b7.x, b7.y, b7.z, 0, 1, 0, 0, 2, 1);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(RightSide, Vehicle, 0, a8.x, a8.y, a8.z, b8.x, b8.y, b8.z, 0, 1, 0, 0, 2, 1);

				return true;
			}
			return false;
		}
		return false;
	}
	return false;
}

bool doSpecial6;
bool Special6()
{
	uint Handle = PLAYER::PLAYER_PED_ID();
	Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	//hash2_Dozer
	Vector3 null; null.x = 0.0, null.y = 0.0; null.z = 0.0;
	Vector3 a; a.x = 0.0, a.y = 0.0, a.z = -0.4;   //X Coord - Y Coord - Z Coord
	Vector3 b; b.x = 0.0, b.y = 0.0, b.z = 0.0;   //Pitch - Roll - Yaw
												  //hash3_MiniGun LEFT
	Vector3 null1; null1.x = 0.0, null1.y = 0.0; null1.z = 0.0;
	Vector3 a1; a1.x = -0.70, a1.y = 1.80, a1.z = 0.98;
	Vector3 b1; b1.x = 0.0, b1.y = 0.0, b1.z = 88.0;
	//hash3_MiniGun2 RIGHT
	Vector3 null0; null0.x = 0.0, null0.y = 0.0; null0.z = 0.0;
	Vector3 a0; a0.x = 0.70, a0.y = 1.80, a0.z = 0.98;
	Vector3 b0; b0.x = 0.0, b0.y = 0.0, b0.z = 88.0;
	//hash4_Left BLUE left
	Vector3 null2; null2.x = 0.0, null2.y = 0.0; null2.z = 0.0;
	Vector3 a2; a2.x = -0.31, a2.y = 2.51, a2.z = 0.55;
	Vector3 b2; b2.x = 0.0, b2.y = 0.0, b2.z = -175.0;//87 - 179
													  //hash4_NIONS LEFT/back
	Vector3 null3; null3.x = 0.0, null3.y = 0.0; null3.z = 0.0;
	Vector3 a3; a3.x = 0.5, a3.y = -3.0, a3.z = -0.36; // -0.23
	Vector3 b3; b3.x = 0.0, b3.y = 0.0, b3.z = 86.0;
	//hash4_Right BLUE LIGHT
	Vector3 null4; null4.x = 0.0, null4.y = 0.0; null4.z = 0.0;
	Vector3 a4; a4.x = 0.31, a4.y = 2.51, a4.z = 0.55;
	Vector3 b4; b4.x = 0.0, b4.y = 0.0, b4.z = -175.0;
	//hash4_NIONS RIGHT
	Vector3 null5; null5.x = 0.0, null5.y = 0.0; null5.z = 0.0;
	Vector3 a5; a5.x = 0.92, a5.y = -2.0, a5.z = 0.01;
	Vector3 b5; b5.x = 0.0, b5.y = 0.0, b5.z = 89.0;
	//ENGINE
	Vector3 null6; null6.x = 0, null6.y = 0; null6.z = 0;
	Vector3 a6; a6.x = 0.0, a6.y = 1.76, a6.z = 0.99;
	Vector3 b6; b6.x = -0.0, b6.y = 0.0, b6.z = 0.0;
	//SIDES LEFT EMP
	Vector3 null7; null7.x = 0, null7.y = 0; null7.z = 0;
	Vector3 a7; a7.x = -0.88, a7.y = -1.8, a7.z = 1.0;
	Vector3 b7; b7.x = 0.0, b7.y = -51.9, b7.z = 0.0;
	//SIDES RIGHT EMP
	Vector3 null8; null8.x = 0, null8.y = 0; null8.z = 0;
	Vector3 a8; a8.x = 0.88, a8.y = -1.8, a8.z = 1.0;
	Vector3 b8; b8.x = 0.0, b8.y = 51.9, b8.z = 0.0;
	//BEAR
	Vector3 null9; null9.x = 0, null9.y = 0; null9.z = 0;
	Vector3 a9; a9.x = -1.0, a9.y = 2.7, a9.z = -0.4;
	Vector3 b9; b9.x = 0.0, b9.y = 0.0, b9.z = 156.5;
	//SPIKES
	Vector3 null10; null10.x = 0, null10.y = 0; null10.z = 0;
	Vector3 a10; a10.x = -0.12, a10.y = 0.59, a10.z = 1.9;
	Vector3 b10; b10.x = 0.0, b10.y = 0.0, b10.z = 0.0;

	int hash = GAMEPLAY::GET_HASH_KEY("monster");				// Monster Truck
	int hash1 = GAMEPLAY::GET_HASH_KEY("prop_car_engine_01");	// Car Engine
	int hash2 = GAMEPLAY::GET_HASH_KEY("bulldozer");			// Dozer
	int hash3 = GAMEPLAY::GET_HASH_KEY("prop_minigun_01");		// Mini GUn 
	int hash4 = GAMEPLAY::GET_HASH_KEY("v_ilev_uvcheetah");		// Nion Lights <-- needs changing
	int hash5 = GAMEPLAY::GET_HASH_KEY("prop_air_lights_05a");	// Blue Lights	
	int hash6 = GAMEPLAY::GET_HASH_KEY("hei_prop_heist_emp");	// Emp Lights	
	int hash7 = GAMEPLAY::GET_HASH_KEY("prop_mem_teddy_02");	// Large Teddy	
	int hash8 = GAMEPLAY::GET_HASH_KEY("p_stinger_04");			// Stinger Spikes

	STREAMING::REQUEST_MODEL(hash); 	// MONSTER
	STREAMING::REQUEST_MODEL(hash1); 	// Car Engine
	STREAMING::REQUEST_MODEL(hash2); 	// DOZER
	STREAMING::REQUEST_MODEL(hash3); 	// GUNS
	STREAMING::REQUEST_MODEL(hash4); 	// Nion Lights
	STREAMING::REQUEST_MODEL(hash5);	// Blue Lights
	STREAMING::REQUEST_MODEL(hash6); 	// Emp Lights
	STREAMING::REQUEST_MODEL(hash7); 	// Large Teddy
	STREAMING::REQUEST_MODEL(hash8); 	// SPIKES

	if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash1) && STREAMING::HAS_MODEL_LOADED(hash2) && STREAMING::HAS_MODEL_LOADED(hash3) && STREAMING::HAS_MODEL_LOADED(hash4) && STREAMING::HAS_MODEL_LOADED(hash5) && STREAMING::HAS_MODEL_LOADED(hash6) && STREAMING::HAS_MODEL_LOADED(hash7) && STREAMING::HAS_MODEL_LOADED(hash8))
	{
		int Object = VEHICLE::CREATE_VEHICLE(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
		int Ebox = OBJECT::CREATE_OBJECT(hash1, null.x, null.y, null.z, 1, 0, 1);
		int GunL = OBJECT::CREATE_OBJECT(hash3, null1.x, null1.y, null1.z, 1, 0, 1);
		int GunR = OBJECT::CREATE_OBJECT(hash3, null0.x, null0.y, null0.z, 1, 0, 1);
		int LSign = OBJECT::CREATE_OBJECT(hash4, null3.x, null3.y, null3.z, 1, 0, 1);
		int RSign = OBJECT::CREATE_OBJECT(hash4, null5.x, null5.y, null5.z, 1, 0, 1);
		int LBlight = OBJECT::CREATE_OBJECT(hash5, null2.x, null2.y, null2.z, 1, 0, 1);
		int RBlight = OBJECT::CREATE_OBJECT(hash5, null4.x, null4.y, null4.z, 1, 0, 1);
		int LeftEmp = OBJECT::CREATE_OBJECT(hash6, null7.x, null7.y, null7.z, 1, 0, 1);
		int RightEmp = OBJECT::CREATE_OBJECT(hash6, null8.x, null8.y, null8.z, 1, 0, 1);
		int Teddy = OBJECT::CREATE_OBJECT(hash7, null9.x, null9.y, null9.z, 1, 0, 1);
		int Spikes = OBJECT::CREATE_OBJECT(hash8, null10.x, null10.y, null10.z, 1, 0, 1);

		if (ENTITY::DOES_ENTITY_EXIST(Ebox) && ENTITY::DOES_ENTITY_EXIST(GunL) && ENTITY::DOES_ENTITY_EXIST(GunR) && ENTITY::DOES_ENTITY_EXIST(LSign) && ENTITY::DOES_ENTITY_EXIST(RSign) && ENTITY::DOES_ENTITY_EXIST(LBlight) && ENTITY::DOES_ENTITY_EXIST(RBlight) && ENTITY::DOES_ENTITY_EXIST(LeftEmp) && ENTITY::DOES_ENTITY_EXIST(RightEmp) && ENTITY::DOES_ENTITY_EXIST(Teddy) && ENTITY::DOES_ENTITY_EXIST(Spikes))
		{
			int Vehicle = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);

			if (ENTITY::DOES_ENTITY_EXIST(Vehicle))
			{
				PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
				ENTITY::SET_ENTITY_VISIBLE(Vehicle, true);
				ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), true);
				VEHICLE::SET_VEHICLE_MOD_KIT(Vehicle, 5);
				VEHICLE::SET_VEHICLE_WINDOW_TINT(Vehicle, 5);
				VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 0, 0, 0);
				VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 0, 0, 0);
				VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 0, 0, 0);
				VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 0, 0);

				ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(Ebox, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(GunL, Vehicle, 0, a1.x, a1.y, a1.z, b1.x, b1.y, b1.z, 0, 1, 0, 0, 2, 1);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(GunR, Vehicle, 0, a0.x, a0.y, a0.z, b0.x, b0.y, b0.z, 0, 1, 0, 0, 2, 1);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(LBlight, Vehicle, 0, a2.x, a2.y, a2.z, b2.x, b2.y, b2.z, 0, 1, 0, 0, 2, 1);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(RBlight, Vehicle, 0, a4.x, a4.y, a4.z, b4.x, b4.y, b4.z, 0, 1, 0, 0, 2, 1);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(LSign, Vehicle, 0, a3.x, a3.y, a3.z, b3.x, b3.y, b3.z, 0, 1, 0, 0, 2, 1);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(RSign, Vehicle, 0, a5.x, a5.y, a5.z, b5.x, b5.y, b5.z, 0, 1, 0, 0, 2, 1);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(LeftEmp, Vehicle, 0, a7.x, a7.y, a7.z, b7.x, b7.y, b7.z, 0, 1, 0, 0, 2, 1);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(RightEmp, Vehicle, 0, a8.x, a8.y, a8.z, b8.x, b8.y, b8.z, 0, 1, 0, 0, 2, 1);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(Teddy, Vehicle, 0, a9.x, a9.y, a9.z, b9.x, b9.y, b9.z, 0, 1, 0, 0, 2, 1);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(Spikes, Vehicle, 0, a10.x, a10.y, a10.z, b10.x, b10.y, b10.z, 0, 1, 0, 0, 2, 1);

				return true;
			}
			return false;
		}
		return false;
	}
	return false;
}

bool doSpecial7;
bool Special7()
{
	uint Handle = PLAYER::PLAYER_PED_ID();
	Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	//hash2_Dozer
	Vector3 null; null.x = 0.0, null.y = 0.0; null.z = 0.0;
	Vector3 a; a.x = 0.0, a.y = 0.0, a.z = -0.4;   //X Coord - Y Coord - Z Coord
	Vector3 b; b.x = 0.0, b.y = 0.0, b.z = 0.0;   //Pitch - Roll - Yaw
												  //hash3_MiniGun LEFT
	Vector3 null1; null1.x = 0.0, null1.y = 0.0; null1.z = 0.0;
	Vector3 a1; a1.x = -0.70, a1.y = 1.80, a1.z = 0.98;
	Vector3 b1; b1.x = 0.0, b1.y = 0.0, b1.z = 88.0;
	//hash3_MiniGun2 RIGHT
	Vector3 null0; null0.x = 0.0, null0.y = 0.0; null0.z = 0.0;
	Vector3 a0; a0.x = 0.70, a0.y = 1.80, a0.z = 0.98;
	Vector3 b0; b0.x = 0.0, b0.y = 0.0, b0.z = 88.0;
	//hash4_Left BLUE left
	Vector3 null2; null2.x = 0.0, null2.y = 0.0; null2.z = 0.0;
	Vector3 a2; a2.x = -0.31, a2.y = 2.51, a2.z = 0.55;
	Vector3 b2; b2.x = 0.0, b2.y = 0.0, b2.z = -175.0;//87 - 179
													  //hash4_NIONS LEFT/back
	Vector3 null3; null3.x = 0.0, null3.y = 0.0; null3.z = 0.0;
	Vector3 a3; a3.x = 0.5, a3.y = -3.0, a3.z = -0.36; // -0.23
	Vector3 b3; b3.x = 0.0, b3.y = 0.0, b3.z = 86.0;
	//hash4_Right BLUE LIGHT
	Vector3 null4; null4.x = 0.0, null4.y = 0.0; null4.z = 0.0;
	Vector3 a4; a4.x = 0.31, a4.y = 2.51, a4.z = 0.55;
	Vector3 b4; b4.x = 0.0, b4.y = 0.0, b4.z = -175.0;
	//hash4_NIONS RIGHT
	Vector3 null5; null5.x = 0.0, null5.y = 0.0; null5.z = 0.0;
	Vector3 a5; a5.x = 0.92, a5.y = -2.0, a5.z = 0.01;
	Vector3 b5; b5.x = 0.0, b5.y = 0.0, b5.z = 89.0;
	//ENGINE
	Vector3 null6; null6.x = 0, null6.y = 0; null6.z = 0;
	Vector3 a6; a6.x = 0.0, a6.y = 1.76, a6.z = 0.86;
	Vector3 b6; b6.x = -0.0, b6.y = 0.0, b6.z = 0.0;
	//SIDES LEFT EMP
	Vector3 null7; null7.x = 0, null7.y = 0; null7.z = 0;
	Vector3 a7; a7.x = -0.88, a7.y = -1.8, a7.z = 1.0;
	Vector3 b7; b7.x = 0.0, b7.y = -51.9, b7.z = 0.0;
	//SIDES RIGHT EMP
	Vector3 null8; null8.x = 0, null8.y = 0; null8.z = 0;
	Vector3 a8; a8.x = 0.88, a8.y = -1.8, a8.z = 1.0;
	Vector3 b8; b8.x = 0.0, b8.y = 51.9, b8.z = 0.0;
	//BEAR
	Vector3 null9; null9.x = 0, null9.y = 0; null9.z = 0;
	Vector3 a9; a9.x = -1.0, a9.y = 2.7, a9.z = -0.4;
	Vector3 b9; b9.x = 0.0, b9.y = 0.0, b9.z = 156.5;
	//SPIKES
	Vector3 null10; null10.x = 0, null10.y = 0; null10.z = 0;
	Vector3 a10; a10.x = -0.12, a10.y = 0.59, a10.z = 1.9;
	Vector3 b10; b10.x = 0.0, b10.y = 0.0, b10.z = 0.0;

	int hash = GAMEPLAY::GET_HASH_KEY("monster");				// Monster Truck
	int hash1 = GAMEPLAY::GET_HASH_KEY("prop_car_engine_01");	// Car Engine
	int hash2 = GAMEPLAY::GET_HASH_KEY("bulldozer");			// Dozer
	int hash3 = GAMEPLAY::GET_HASH_KEY("prop_minigun_01");		// Mini GUn 
	int hash4 = GAMEPLAY::GET_HASH_KEY("v_ilev_uvcheetah");		// Nion Lights <-- needs changing
	int hash5 = GAMEPLAY::GET_HASH_KEY("prop_air_lights_05a");	// Blue Lights	
	int hash6 = GAMEPLAY::GET_HASH_KEY("hei_prop_heist_emp");	// Emp Lights	
	int hash7 = GAMEPLAY::GET_HASH_KEY("prop_mem_teddy_02");	// Large Teddy	
	int hash8 = GAMEPLAY::GET_HASH_KEY("p_stinger_04");			// Stinger Spikes

	STREAMING::REQUEST_MODEL(hash); 	// MONSTER
	STREAMING::REQUEST_MODEL(hash1); 	// Car Engine
	STREAMING::REQUEST_MODEL(hash2); 	// DOZER
	STREAMING::REQUEST_MODEL(hash3); 	// GUNS
	STREAMING::REQUEST_MODEL(hash4); 	// Nion Lights
	STREAMING::REQUEST_MODEL(hash5);	// Blue Lights
	STREAMING::REQUEST_MODEL(hash6); 	// Emp Lights
	STREAMING::REQUEST_MODEL(hash7); 	// Large Teddy
	STREAMING::REQUEST_MODEL(hash8); 	// SPIKES

	if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash1) && STREAMING::HAS_MODEL_LOADED(hash2) && STREAMING::HAS_MODEL_LOADED(hash3) && STREAMING::HAS_MODEL_LOADED(hash4) && STREAMING::HAS_MODEL_LOADED(hash5) && STREAMING::HAS_MODEL_LOADED(hash6) && STREAMING::HAS_MODEL_LOADED(hash7) && STREAMING::HAS_MODEL_LOADED(hash8))
	{
		int Object = VEHICLE::CREATE_VEHICLE(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
		int Ebox = OBJECT::CREATE_OBJECT(hash1, null.x, null.y, null.z, 1, 0, 1);
		int GunL = OBJECT::CREATE_OBJECT(hash3, null1.x, null1.y, null1.z, 1, 0, 1);
		int GunR = OBJECT::CREATE_OBJECT(hash3, null0.x, null0.y, null0.z, 1, 0, 1);
		int LSign = OBJECT::CREATE_OBJECT(hash4, null3.x, null3.y, null3.z, 1, 0, 1);
		int RSign = OBJECT::CREATE_OBJECT(hash4, null5.x, null5.y, null5.z, 1, 0, 1);
		int LBlight = OBJECT::CREATE_OBJECT(hash5, null2.x, null2.y, null2.z, 1, 0, 1);
		int RBlight = OBJECT::CREATE_OBJECT(hash5, null4.x, null4.y, null4.z, 1, 0, 1);
		int LeftEmp = OBJECT::CREATE_OBJECT(hash6, null7.x, null7.y, null7.z, 1, 0, 1);
		int RightEmp = OBJECT::CREATE_OBJECT(hash6, null8.x, null8.y, null8.z, 1, 0, 1);
		int Teddy = OBJECT::CREATE_OBJECT(hash7, null9.x, null9.y, null9.z, 1, 0, 1);
		int Spikes = OBJECT::CREATE_OBJECT(hash8, null10.x, null10.y, null10.z, 1, 0, 1);

		if (ENTITY::DOES_ENTITY_EXIST(Ebox) && ENTITY::DOES_ENTITY_EXIST(GunL) && ENTITY::DOES_ENTITY_EXIST(GunR) && ENTITY::DOES_ENTITY_EXIST(LSign) && ENTITY::DOES_ENTITY_EXIST(RSign) && ENTITY::DOES_ENTITY_EXIST(LBlight) && ENTITY::DOES_ENTITY_EXIST(RBlight) && ENTITY::DOES_ENTITY_EXIST(LeftEmp) && ENTITY::DOES_ENTITY_EXIST(RightEmp) && ENTITY::DOES_ENTITY_EXIST(Teddy) && ENTITY::DOES_ENTITY_EXIST(Spikes))
		{
			int Vehicle = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);

			if (ENTITY::DOES_ENTITY_EXIST(Vehicle))
			{
				PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
				ENTITY::SET_ENTITY_VISIBLE(Vehicle, true);
				ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), true);
				VEHICLE::SET_VEHICLE_MOD_KIT(Vehicle, 5);
				VEHICLE::SET_VEHICLE_WINDOW_TINT(Vehicle, 5);
				VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 0, 0, 0);
				VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 0, 0, 0);
				VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 0, 0, 0);
				VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 0, 0);

				ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(Ebox, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(GunL, Vehicle, 0, a1.x, a1.y, a1.z, b1.x, b1.y, b1.z, 0, 1, 0, 0, 2, 1);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(GunR, Vehicle, 0, a0.x, a0.y, a0.z, b0.x, b0.y, b0.z, 0, 1, 0, 0, 2, 1);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(LBlight, Vehicle, 0, a2.x, a2.y, a2.z, b2.x, b2.y, b2.z, 0, 1, 0, 0, 2, 1);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(RBlight, Vehicle, 0, a4.x, a4.y, a4.z, b4.x, b4.y, b4.z, 0, 1, 0, 0, 2, 1);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(LSign, Vehicle, 0, a3.x, a3.y, a3.z, b3.x, b3.y, b3.z, 0, 1, 0, 0, 2, 1);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(RSign, Vehicle, 0, a5.x, a5.y, a5.z, b5.x, b5.y, b5.z, 0, 1, 0, 0, 2, 1);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(LeftEmp, Vehicle, 0, a7.x, a7.y, a7.z, b7.x, b7.y, b7.z, 0, 1, 0, 0, 2, 1);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(RightEmp, Vehicle, 0, a8.x, a8.y, a8.z, b8.x, b8.y, b8.z, 0, 1, 0, 0, 2, 1);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(Teddy, Vehicle, 0, a9.x, a9.y, a9.z, b9.x, b9.y, b9.z, 0, 1, 0, 0, 2, 1);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(Spikes, Vehicle, 0, a10.x, a10.y, a10.z, b10.x, b10.y, b10.z, 0, 1, 0, 0, 2, 1);

				return true;
			}
			return false;
		}
		return false;
	}
	return false;
}

bool doSpecial8;
bool Special8()
{
	uint Me = PLAYER::PLAYER_PED_ID();
	Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	Vector3 null; null.x = 0, null.y = 0; null.z = 0;
	Vector3 a; a.x = 0, a.y = 0, a.z = 0;
	Vector3 b; b.x = 0, b.y = 0, b.z = 0;
	int hash = GAMEPLAY::GET_HASH_KEY("massacro2");
	int hash2 = GAMEPLAY::GET_HASH_KEY("freight");
	STREAMING::REQUEST_MODEL(hash);
	STREAMING::REQUEST_MODEL(hash2);
	if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
	{
		int Vehicle = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
		int Object = VEHICLE::CREATE_VEHICLE(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
		if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
		{
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
			PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
			ENTITY::SET_ENTITY_VISIBLE(Object, true);
			VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
			VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 0, 0, 0);
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 0, 0);
			VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(Object, "tinymenu");
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 0, 0, 0);
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 0, 0, 0);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);
			return true;
		}
		return false;
	}
	return false;
}
float featurePrecisionlvl = 1.0;
bool doSpecial9;
bool Special9()
{
	uint Me = PLAYER::PLAYER_PED_ID();
	Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	Vector3 null; null.x = 0, null.y = 0; null.z = 0;
	Vector3 a; a.x = 0, a.y = 0, a.z = 0;
	Vector3 b; b.x = 0, b.y = 0, b.z = 0;
	int hash = GAMEPLAY::GET_HASH_KEY("ztype");
	int hash2 = GAMEPLAY::GET_HASH_KEY("btype");
	STREAMING::REQUEST_MODEL(hash);
	STREAMING::REQUEST_MODEL(hash2);
	if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
	{
		int Vehicle = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
		int Object = VEHICLE::CREATE_VEHICLE(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
		if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
		{
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
			PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
			ENTITY::SET_ENTITY_VISIBLE(Vehicle, true);
			VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
			VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 0, 0, 0);
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 0, 0);
			VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(Vehicle, "tinymenu");
			VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(Object, "tinymenu");
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 0, 0, 0);
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 0, 0, 0);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);
			return true;
		}
		return false;
	}
	return false;
}

#pragma endregion




