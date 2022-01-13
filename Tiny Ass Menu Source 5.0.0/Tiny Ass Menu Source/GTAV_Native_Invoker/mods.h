void HookNative(int native, int dest) {
	//if (auth_hook)
	
		int FuncBytes[1];
		FuncBytes[0] = *(int*)dest;
		memcpy((void*)native, FuncBytes, 4);
	
}

int selectedPlayer;
#pragma region Cars Array
char* g_pcMainMenu[20] = { "Super Cars", "Sports Cars", "Sports Classic Cars", "Muscle Cars", "Sedans", "Coupes", "Compacts", "SUVs and Trucks", "Offroad Vehicles", "Vans", "Emergency Vehicles", "Service Vehicles", "Military Vehicles", "Motorcycles", "Bicycles", "Commercial Vehicles", "Helicopters", "Planes", "Boats", "Trailers" };


char* g_pcSuperCars[11] = { "Truffade Adder", "Overflod Entity XF", "Grotti Cheetah", "Pegassi Infernus", "Pegassi Vacca", "Vapid Bullet", "Coil Voltic", "Pegassi Zentorno", "Grotti Turismo R", "Pegassi Osiris", "Progen T20" };


char* g_pcSportsCars[21] = { "Annis Elegy RH8", "Hijak Khamelion", "Grotti Carbonizzare", "Benefactor Feltzer 1", "Benefactor Feltzer 2", "Dewbauchee Rapid GT 1", "Inverto Coquette 1", "Dewbauchee Rapid GT 2", "Obey 9F Cabrio", "Obey 9F", "Benefactor Surano", "Bravado Banshee", "Pfister Comet", "Benefactor Schwartzer", "Schyster Fusilade", "Bravado Buffalo", "Bravado Buffalo 2", "Maibatsu Penumbra", "Karin Sultan", "Karin Futo", "Lampadati Furore GT"};


char* g_pcSportsClassicCars[20] = { "Inverto Coquette 2", "Inverto Coquette 3", "Truffade Z-Type", "Grotti Stinger GT", "Grotti Stinger", "Pegassi Monroe", "Dewbauchee JB 700", "Declasse Tornado 1", "Declasse Tornado 2", "Declasse Tornado 3", "Declasse Tornado 4", "Vapid Peyote", "Albany Manana", "Albany Virgo", "Albany Roosevelt", "Vapid Blade", "Benefactor Glendale", "Lampadati Pigalle", "Lampadati Casco", "Vapid Chino" };


char* g_pcMuscleCars[12] = { "Vapid Hotknife", "Bravado Gauntlet", "Declasse Vigero", "Vapid Dominator", "Albany Buccaneer", "Imponte Phoenix", "Declasse Sabre Turbo", "Imponte Ruiner", "Declasse Voodoo", "Cheval Picador", "Rat Loader 1", "Rat Loader 2" };


char* g_pcSedans[21] = { "Enus Super Diamond", "Ubermacht Oracle 1", "Ubermacht Oracle 2", "Dundreary Stretch", "Cheval Fugitive", "Cheval Surge", "Benefactor Schafter", "Karin Asterope", "Karin Intruder", "Albany Washington", "Vapid Stanier", "Vulcan Ingot", "Albany Emperor 1", "Albany Emperor 2", "Albany Emperor 3", "Albany Primo", "Dundreary Regina", "Chariot Romero Hearse", "Obey Tailgater", "Declasse Premier", "Zirconium Stratum" };


char* g_pcCoupes[10] = { "Dewbauchee Exemplar", "Enus Cognoscenti Cabrio", "Lampadati Felon GT", "Lampadati Felon", "Ubermacht Zion Cabrio", "Ubermacht Zion", "Ubermacht Sentinel XS", "Ubermacht Sentinel", "Ocelot F620", "Ocelot Jackal" };


char* g_pcCompacts[8] = { "Karin Dilettante 1", "Karin Dilettante 2", "Weeny Issi", "Bollokan Prairie", "Dinka Blista", "Declasse Rhapsody", "Vulcar Warrener", "Benefactor Panto" };


char* g_pcSUVnTrucks[21] = { "Gallivanter Baller 1", "Gallivanter Baller 2", "Obey Rocoto", "Albany Cavalcade 1", "Albany Cavalcade 2", "Benefactor Dubsta 1", "Benefactor Dubsta 2", "Benefactor Dubsta 3", "Benefactor Serrano", "Dundreary Landstalker", "Fathom FQ 2", "Mammoth Patriot", "Emperor Habanero", "Vapid Radius", "Declasse Granger", "Canis Mesa 1", "Canis Mesa 2", "Canis Seminole", "Canis Kalahari", "Bravado Gresley", "Karin BeeJay XL" };


char* g_pcOffRoads[19] = { "Monster Truck", "Vapid Sandking XL", "BF Dune Buggy", "BF Dune 2 (Space Docker)", "BF Injection", "BF Bifta", "Nagasaki Blazer 1", "Nagasaki Blazer 2 (Trevors)", "Canis Mesa (Merryweather)", "Vapid Sandking SWB", "Bravado Duneloader", "Canis Bodhi", "Declasse Rancher XL 1", "Declasse Rancher XL 2", "Karin Rebel 1", "Karin Rebel 2", "Nagasaki Blazer Lifeguard", "Coil Brawler", "Dinka Enduro" };


char* g_pcVans[14] = { "Bravado Bison 1", "Bravado Bison 2", "Bravado Bison 3", "Bravado Paradise", "Zirconium Journey", "Vapid Minivan", "Vapid Bobcat XL", "Bravado Rumpo 1", "Bravado Rumpo 2", "Brute Pony 1", "Brute Pony 2", "Declasse Burrito 1", "Declasse Burrito 2", "Declasse Burrito 3" };


char* g_pcEmergencyCars[18] = { "FIB", "FIB SUV", "Firetruck", "Ambulance", "Police 1", "Police 2", "Police 3", "Police 4", "Police Bike", "Police Old 1", "Police Old 2", "Police Van", "Swat Truck", "Sheriff 1", "Sheriff 2", "Prison Bus", "Park Ranger", "Life Guard SUV" };


char* g_pcServicVehicles[6] = { "Airport Bus", "Dashhound", "Bus", "Rental Shuttle Bus", "Tour Bus", "Taxi" };


char* g_pcMilitary[7] = { "Rhino Tank", "Barracks 1", "Barracks 2", "Barracks 3", "Canis Crusader", "Tanker 1", "Tanker 2" };


char* g_pcMotorcycles[21] = { "Nagasaki Carbon RS", "Pegassi Bati 801RR", "Pegassi Bati 801", "LCC Hexer", "LCC Innovation", "Dinka Double-T", "Dinka Thrust", "Dinka Vindicator", "Pegassi Ruffian", "Shitzu Vader", "Shitzu PCJ 600", "Shitzu Hakuchou", "Dinka Akuma", "Maibatsu Sanchez (Decal)", "Maibatsu Sanchez", "Pegassi ***gio", "Western Daemon", "Western Bagger", "Principe Nemesis", "Sovereign", "Principe Lectro" };


char* g_pcBicycles[7] = { "Whippet Race Bike", "Tri-Cycles Race Bike", "Scorcher", "Endurex Race Bike", "Cruiser", "BMX", "Fixter" };


char* g_pcCommercialVehicles[21] = { "Maibatsu Mule 1", "Maibatsu Mule 2", "Maibatsu Mule 3", "JoBuilt Phantom", "Vapid Benson", "MTL Packer", "MTL Pounder", "JoBuilt Hauler", "Brute Stockade 1", "Brute Stockade 2", "HVY Biff", "HVY Dump", "HVY Dozer", "HVY Forklift", "HVY Handler", "HVY Cutter", "Utility Truck 1", "Utility Truck 2", "Utility Truck 3", "Trashmaster 1", "Trashmaster 2" };


char* g_pcHelicopters[14] = { "Annihilator", "Buzzard Attack Chopper 1", "Buzzard Attack Chopper 2", "Frogger 1", "Frogger 2", "Maverick", "Cargobob 1", "Cargobob 2", "Cargobob 3", "Police Maverick", "Swift 1", "Swift 2", "Buckingham Valkyrie", "Savage" };


char* g_pcPlanes[19] = { "Titan", "Buckingham Luxor 1", "Buckingham Luxor 2", "Buckingham Shamal", "Buckingham Vestra", "Buckingham Miljet", "Velum 1", "Velum 2", "Mammatus", "Duster", "Mallard", "Cuban 800", "Cargo Plane", "Blimp", "P-996 Lazer", "Skylift", "Jet", "Bersa", "Mammoth Hydra" };


char* g_pcBoats[14] = { "Dinka Marquis", "Shitzu Jetmax", "Shitzu Squalo", "Shitzu Suntrap", "Shitzu Tropic", "Speedophile Seashark 1", "Speedophile Seashark 2", "Police Predator", "Submarine", "Pegassi Speeder", "Nagasaki Dinghy 1", "Nagasaki Dinghy 2", "Nagasaki Dinghy 3", "Lampadati Toro" };


char* g_pcTrailers[21] = { "Army Tanker", "Army Trailer 1", "Army Trailer 2", "Bale Trailer", "Boat Trailer", "Cablecar", "Dock Trailer", "Freight Car 1", "Freight Car 2", "Freight Container 1", "Freight Container 2", "Freight Train Boxcar", "Grain Trailer", "Metro Train", "Mobile Home Trailer", "Rake Trailer", "Train Fuel Tank Car", "Car Carrier Trailer", "Marquis Trailer", "Super Car Carrier Trailer", "Trailer Logs" };


unsigned int cars[20][39] = {
	//super 
	{ 0xB779A091, 0xB2FE5CF9, 0xB1D95DA0, 0x18F25AC7, 0x142E0DC3, 0x9AE6DDA1, 0x9F4B77BE, 0xAC5DF515, 0x185484E1, 0x767164D6, 0x6322B39A },//Super

	//sport
	{ 0xDE3D9D22, 0x206D1B68, 0x7B8AB45F, 0x8911B9F5, 0xA29D6D10, 0x8CB29A14, 0x067BC037, 0x679450AF, 0x3D8FA25C, 0xA8E38B01, 0x16E478C1, 0xC1E908D2, 0xC1AE4D16, 0xD37B7976, 0x1DC0BA53, 0xEDD516C6, 0x2BEC3CBE, 0xE9805550, 0x39DA2754, 0x7836CE2F, 0xBF1691E0 },//29 - 8 = 21

	//sport classic
	{ 0x3C4E2113, 0x2EC385FE, 0x2D3BD401, 0x82E499FA, 0x5C23AF9B, 0xE62B361B, 0x3EAB5555, 0x1BB290BC, 0x5B42A5C4, 0x690A4153, 0x86CF7CDD, 0x6D19CCBC, 0x81634188, 0xE2504942, 0x06FF6914, 0xB820ED5E, 0x047A6BC1, 0x404B6381, 0x3822BDFE, 0x14D69010 },//20

	//muscle
	{ 0x0239E390, 0x94B395C5, 0xCEC6B9B7, 0x04CE68AC, 0xD756460C, 0x831A21D5, 0x9B909C94, 0xF26CEFF9, 0x1F3766E3, 0x59E0FBF3, 0xD83C13CE, 0xDCE1D9F7 },

	//sedans
	{ 0x42F2ED16, 0x506434F6, 0xE18195B2, 0x8B13F083, 0x71CB2FFB, 0x8F0E3594, 0xB52B5113, 0x8E9254FB, 0x34DD8AA1, 0x69F06B57, 0xA7EDE74D, 0xB3206692, 0xD7278283, 0x8FC3AADC, 0xB5FCF74E, 0xBB6B404F, 0xFF22D208, 0x2560B2FC, 0xC3DDFDCE, 0x8FB66F9B, 0x66B4FC45 }, //sedans! 23 - 2 = 21 Maximum options allowed on the menu!

	//Coupes
	{ 0xFFB15B5E, 0x13B57D8A, 0xFAAD85EE, 0xE8A8BDA8, 0xBD1B39C3, 0xB8E2AE18, 0x50732C82, 0x3412AE2D, 0xDCBCBE48, 0xDAC67112 }, 

	//Compacts
	{ 0xBC993509, 0x64430650, 0xB9CB3B69, 0xA988D3A2, 0xEB70965F, 0x322CF98F, 0x51D83328, 0xE644E480 },

	//SUV / Trucks
	{ 0xCFCA3668, 0x08852855, 0x7F5C91F1, 0x779F23AA, 0xD0EB2BE5, 0x462FE277, 0xE882E5F6, 0xB6410173, 0x4FB1A214, 0x4BA4E8DC, 0xBC32A33B, 0xCFCFEB3B, 0x34B7390F, 0x9D96B45B, 0x9628879C, 0x36848602, 0xD36A4B44, 0x48CECED3, 0x05852838, 0xA3FC0F4D, 0x32B29A4B },//SUV / Trucks = 28 - 7 = 21

	// off roads
	{ 0xCD93A7DB, 0xB9210FD0, 0x9CF21E0F, 0x1FD824AF, 0x432AA566, 0xEB298297, 0x8125BCF9, 0xB44F0582, 0x84F42E51, 0x3AF8C345, 0x698521E3, 0xAA699BB6, 0x6210CBB0, 0x7341576B, 0xB802DD46, 0x8612B64B, 0xFD231729, 0xA7CE1BC5, 0x6882FA73 },

	/*vans*/
	{ 0xFEFD644F, 0x7B8297C5, 0x67B3F020, 0x58B3979C, 0xF8D48E7A, 0xED7EADA4, 0x3FC5D440, 0x4543B74D, 0x961AFEF7, 0xF8DE29A8, 0x38408341, 0xAFBB2CA4, 0xC9E8FF76, 0x98171BD3 },//vans = 14

	// Emergency
	{ 0x432EA949, 0x9DC66994, 0x73920F8E, 0x45D56ADA, 0x79FBB0C5, 0x9F05F101, 0x71FA16EA, 0x8A63C7B9, 0xFDEFAEC3, 0xA46462F7, 0x95F4C618, 0x1B38E955, 0xB822A1AA, 0x9BAA707C, 0x72935408, 0x885F3671, 0x2C33B46E, 0x1BF8D381 },

	//service vehicles
	{ 0x4C80EB0E, 0x84718D34, 0xD577C962, 0xBE819C63, 0x73B1C3CB, 0xC703DB5F },

	// military
	{ 0x2EA68690, 0xCEEA3F4B, 0x4008EABB, 0x2592B5CF, 0x132D5A1A, 0xD46F4737, 0x74998082 },

	// motorcycles
	{ 0x00ABB0C0, 0xCADD5D2D, 0xF9300CC5, 0x11F76C14, 0xF683EACA, 0x9C669788, 0x6D6F8F43, 0xAF599F01, 0xCABD11E8, 0xF79A00F7, 0xC9CEAF06, 0x4B6C568A, 0x63ABADE7, 0x2EF89E46, 0xA960B13E, 0x0350D1AB, 0x77934CEE, 0x806B9CC3, 0xDA288376, 0x2C509634, 0x26321E67 },

	// bicycles
	{ 0x4339CD69, 0xE823FB48, 0xF4E1AA15, 0xB67597EC, 0x1ABA13B5, 0x43779C54, 0xCE23D3BF },

	// commercial 
	{ 0x35ED670B, 0xC1632BEB, 0x85A5B471, 0x809AA4CB, 0x7A61B330, 0x21EEE87D, 0x7DE35E7D, 0x5A82F9AE, 0x6827CF72, 0xF337AB36, 0x32B91AE8, 0x810369E2, 0x7074F39D, 0x58E49664, 0x1A7FCEFA, 0xC3FBA120, 0x1ED0A534, 0x34E6BF6B, 0x7F2153DF, 0x72435A19, 0xB527915C },//21

	// helicopters
	{ 0x31F0B376, 0x2F03547B, 0x2C75F0DD, 0x2C634FBD, 0x742E9AC0, 0x9D0450CA, 0xFCFCB68B, 0x60A7EA10, 0x53174EEF, 0x1517D4D9, 0xEBC24DF2, 0x4019CB4C, 0xA09E15FD, 0xFB133A17 },

	// planes
	{ 0x761E2AD3, 0x250B0C5E, 0xB79F589E, 0xB79C1BF5, 0x4FF77E37, 0x09D80F93, 0x9C429B6A, 0x403820E8, 0x97E55D11, 0x39D6779E, 0x81794C70, 0xD9927FE3, 0x15F27762, 0xF7004C86, 0xB39B0AE6, 0x3E48BF23, 0x3F119114, 0x6CBD1D6D, 0x39D6E83F },

	// boats
	{ 0xC1CE1183, 0x33581161, 0x17DF5EC2, 0xEF2295C9, 0x1149422F, 0xC2974024, 0xDB4388E4, 0xE2E7D4AB, 0x2DFF622F, 0x0DC60D2B, 0x3D961290, 0x107F392C, 0x107F392C/*copy of other diunghy*//*0x1****4EA*/, 0x3FD5AA2F },

	//trailers
	{ 0xB8081009, 0xA7FF33F5, 0x9E6B14D6, 0xE82AE656, 0x1F3D44B5, 0xC6C3242D, 0x806EFBEE, 0x3D6AAA9B, 0x0AFD22A6, 0x36DCFF98, 0x0E512E79, 0x264D9262, 0x3CC7F596, 0x33C9E158, 0x153E1B0A, 0x174CB172, 0x22EDDC30, 0x7BE032C6, 0x6A59902D, 0x7CAB34D0, 0x782A236D }, };//21 Trailers

#pragma endregion

#pragma region Weapon Array
Hash WepPickupArray[49] = { 0x6E4E65C2, 0x741C684A, 0x6C5B941A, 0xF33C83B0, 0xDF711959, 0xB2B5325E, 0x85CAA9B1, 0xB2930A14, 0xFE2A352C, 0x693583AD, 0x1D9588D3, 0x3A4C2AD2, 0x4D36C349, 0x2F36B434, 0xA9355DCD, 0x96B412A3, 0x9299C95B, 0x5E0683A1, 0x2DD30479, 0x1CD604C7, 0x7C119D58, 0xF9AFB48F, 0x8967B4F3, 0x3B662889, 0x2E764125, 0xFD16169E, 0xCB13D282, 0xC69DE3FF, 0x278D8734, 0x5EA16D74, 0x295691A9, 0x81EE601E, 0x88EAACA7, 0x872DC888, 0x815D66E8, 0xFA51ABF5, 0xC5B72713, 0x5307A4EC, 0x9CF13918, 0x0968339D, 0xBFEE6C3B, 0xEBF89D5F, 0x22B15640, 0x763F7121, 0xBED46EC5, 0x079284A9, 0x624F7213, 0xC01EB678, 0xBD4DE242 };
#pragma endregion 
#pragma region Teleport & Notification Definitions
float menuXCord1 = 0.85f;
void drawNotification(char* msg)//Rockstar social
{
	if (menuXCord1 == 0.85f)
	{
		UI::BEGIN_TEXT_COMMAND_THEFEED_POST("STRING");
		_ADD_TEXT_COMPONENT_STRING(msg);
		_SET_NOTIFICATION_MESSAGE("CHAR_SOCIAL_CLUB", "CHAR_SOCIAL_CLUB", true, 1, "~HUD_COLOUR_BLUE~Tiny Menu", "");//dank hax
		UI::_DRAW_NOTIFICATION(false, true);
	}
	else
	{
		UI::_0xF42C43C7("STRING");
		_ADD_TEXT_COMPONENT_STRING(msg);
		UI::_0x38F82261(3000, 1);
	}
}
#pragma endregion
#pragma region teleport func
void TPtoWaypoint() {
	int WaypointHandle = UI::GET_FIRST_BLIP_INFO_ID(8);
	if (UI::DOES_BLIP_EXIST(WaypointHandle)) {
		Vector3 WaypointPos = UI::GET_BLIP_COORDS(WaypointHandle);
		WaypointPos.z += 30.0f;
		int Handle = PLAYER::PLAYER_PED_ID();
		if (PED::IS_PED_IN_ANY_VEHICLE(Handle, 0))
			Handle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		ENTITY::SET_ENTITY_COORDS(Handle, WaypointPos.x, WaypointPos.y, WaypointPos.z, 0, 0, 0, 1);
	}
	else drawNotification("~HUD_COLOUR_PINK~Please set a Waypoint!");
}
void toNearestCar() {
	Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	int VehID = VEHICLE::GET_CLOSEST_VEHICLE(coords.x, coords.y, coords.z, 10000.0f, 0, 71);
	PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), VehID, -1);
}
//try that i guess you got soo manu locations for soo much shit I know lol #freemenu true lmao lots of erro
void TeleportToLoc(float x, float y, float z)
{

	if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0))
	{
		int vehid = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		ENTITY::SET_ENTITY_COORDS(vehid, x, y, z, 1, 0, 0, 1);
	}
	else
	{
		ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), x, y, z, 1, 0, 0, 1);
	}
}
void teleport(Vector3 c) {
	//int Handle 
	Ped pp = PLAYER::PLAYER_PED_ID();
	if (PED::IS_PED_IN_ANY_VEHICLE(pp, 0)) {
		ENTITY::SET_ENTITY_COORDS(PED::GET_VEHICLE_PED_IS_IN(pp, 0), c.x, c.y, c.z, 0, 0, 0, 1);
	}
	else
		ENTITY::SET_ENTITY_COORDS(pp, c.x, c.y, c.z, 0, 0, 0, 1);
}

int teletypes = 0;
char *teleloctypes[] = { "Main Airport","Mount Chiliad", "Maze Bank", "Trevor's Airfield", "Fort Zancudo", "LSC", "Mask Shop", "Cloth Shop", "Amunation", "Pier", "ttrailer", "crane" };


void mair() { Vector3 Coords; Coords.x = -1208.71f; Coords.y = -3026.39f; Coords.z = 13.94f; teleport(Coords); }//main airport
void mchil() { Vector3 Coords; Coords.x = 496.75f; Coords.y = 5591.17f; Coords.z = 795.03f; teleport(Coords); }//mount chiliad
void mbank() { Vector3 c; c.x = -74.94243f; c.y = -818.63446f; c.z = 326.174347f; teleport(c); }//maze bank
void tafield() { Vector3 Coords; Coords.x = 1741.4960f; Coords.y = 3269.2570f; Coords.z = 41.6014f; teleport(Coords); }//trevors airfield
void fzan() { Vector3 Coords; Coords.x = -2012.8470f; Coords.y = 2956.5270f; Coords.z = 32.8101f; teleport(Coords); }//fort zancudo
void lsc() { Vector3 Coords; Coords.x = -373.01; Coords.y = -124.91; Coords.z = 38.31; teleport(Coords); }//ls customs
void mshop() { Vector3 Coords; Coords.x = -1338.16; Coords.y = -1278.11; Coords.z = 4.87; teleport(Coords); }//mask shop
void cshop() { Vector3 Coords; Coords.x = -718.91; Coords.y = -158.16; Coords.z = 37.00; teleport(Coords); }//cloths shop
void ashop() { Vector3 Coords; Coords.x = 247.3652; Coords.y = -45.8777; Coords.z = 69.9411; teleport(Coords); }//amunation 
void hstand() { Vector3 Coords; Coords.x = -1835.696; Coords.y = -1231.947; Coords.z = 13.0174; teleport(Coords); }//hot dog stand
void ttrailer() { Vector3 Coords; Coords.x = 1976.2773; Coords.y = 3820.3276; Coords.z = 33.4501; teleport(Coords); }//trevors trailer
void crane() { Vector3 Coords; Coords.x = -119.7866; Coords.y = -976.2401; Coords.z = 306.3311; teleport(Coords); }//crane

int Steletypes = 0;
char *Steleloctypes[] = { "Inside FIB","Roof FIB", "Ferris Wheel", "Ballance Beam", "Colorful Tower", "Micheal's House", "Franklin's New House", "Franklin's Old House", "Warden's Office" };

void ifib() { Vector3 Coords; Coords.x = 135.5220f; Coords.y = -749.0003f; Coords.z = 260.0000f; teleport(Coords); }//inside fib
void rfib() { Vector3 Coords; Coords.x = 135.5220f; Coords.y = -749.0003f; Coords.z = 265.0000f; teleport(Coords); }//roof fib
void fwheel() { Vector3 Coords; Coords.x = -1664.047; Coords.y = -1128.774; Coords.z = 50.5396; teleport(Coords); }//ferris wheel
void bbeam() { Vector3 Coords; Coords.x = -128.3792; Coords.y = -972.6886; Coords.z = 268.9791; teleport(Coords); }//ballance beam
void ctower() { Vector3 Coords; Coords.x = -11.9003; Coords.y = -588.6138; Coords.z = 116.3994; teleport(Coords); }//colorful tower
void mhouse() { Vector3 Coords; Coords.x = -814.4539; Coords.y = 179.5925; Coords.z = 72.1592; teleport(Coords); }//micheals house
void fnhouse() { Vector3 Coords; Coords.x = 6.4210; Coords.y = 524.9965; Coords.z = 174.6283; teleport(Coords); }//franklins new house house
void fohouse() { Vector3 Coords; Coords.x = -18.4873; Coords.y = -1438.829; Coords.z = 31.1015; teleport(Coords); }//franklins old house house
void woffice() { Vector3 Coords; Coords.x = 1690.8326; Coords.y = 2654.3022; Coords.z = 57.0972; teleport(Coords); }//wardens office
#pragma endregion
#pragma region Auth
bool auth_Drawtext = false;
bool auth_menubase = false;
bool auth_menucoords = false;
bool auth_submenuswitch = false;
bool auth_hook = false;
bool CompareStrings(char* One, char* Two)
{
	if (strncmp(One, Two, 25) == 0)
		return true;
	else
		return false;
}
void HookDISABLECONTROL(struct NativeArg_s* a_pArgs)
{
	int funcadd = DISABLE_CONTROL_ACTION_RPC;
	if (!CompareStrings("am_mp_property_int", SCRIPT::GET_THIS_SCRIPT_NAME()))
		((int(*)(int a, int b))&funcadd)(a_pArgs->ArgValues[0], a_pArgs->ArgValues[1]);
}
void HookCURRENTPEDWEAPONRPC(struct NativeArg_s* a_pArgs)
{
	int funcadd = SET_CURRENT_PED_WEAPON_RPC;
	if (!CompareStrings("am_mp_property_int", SCRIPT::GET_THIS_SCRIPT_NAME()))
	{
	((void(*)(Ped a, Hash b, BOOL c))&funcadd)(a_pArgs->ArgValues[0], a_pArgs->ArgValues[1], a_pArgs->ArgValues[2]);
	}
}
int newmenusize = 0;
int customrpfsize = 0;
int currentmenusize = 0;//check current size on console
int menutype = 0;
int Time_Check = 0;
int scriptsize;
char* currentmenuversion;
char* Thismenuversion = "5.0.1";//4.0.0
#pragma endregion
#pragma region Page 2 Player Options
 //These might need to be looped... 
void godmode(bool toggle)
{
	
	if (toggle == true)
	{
		PLAYER::GET_PLAYER_INVINCIBLE(PLAYER::PLAYER_ID());
		PLAYER::SET_PLAYER_INVINCIBLE(PLAYER::PLAYER_ID(), true);
	}
	else if (toggle == false)
	{
		!PLAYER::GET_PLAYER_INVINCIBLE(PLAYER::PLAYER_ID());
		PLAYER::SET_PLAYER_INVINCIBLE(PLAYER::PLAYER_ID(), false);
	}
}
bool clonefreeze = false;
int ClonePed(int PedHandle)
	{
		return PED::CLONE_PED(PedHandle, ENTITY::GET_ENTITY_HEADING(PedHandle), 1, 1);
	}
bool Shotsling = false;
void slingshot(int selectedPlayer)
	{
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED(selectedPlayer), true));
		if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED(selectedPlayer), true)));
	{
		ENTITY::APPLY_FORCE_TO_ENTITY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED(selectedPlayer), true), 65.0/*1*/, 65.0/*0*/, 65.0/*0*/, 20, 0, 0, 0, 1, false, true, true, true, true);
	}
}



bool doUndriveableCar;
bool undriveablePlayersCar(int Client)
{
	int PedHandle = PLAYER::GET_PLAYER_PED(Client);
	if (PED::IS_PED_IN_ANY_VEHICLE(PedHandle, 0))
	{
		int VehHandle = PED::GET_VEHICLE_PED_IS_IN(PedHandle, 0);
		if (NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(VehHandle))
		{
			VEHICLE::SET_VEHICLE_UNDRIVEABLE(VehHandle, true);
			return true;
		}
		else return false;
	}
	else
	{
		doUndriveableCar = false;
		return false;
	}
}
bool Radioing = false;
bool garage = false;
bool DoorsOpen = false;
void OpenDoors(int VehicleHandle)
{
	for (int DoorIndex = 0; DoorIndex <= 6; DoorIndex++)
		VEHICLE::SET_VEHICLE_DOOR_OPEN(VehicleHandle, DoorIndex, false, false);//1= constant?? if not 0
}
#pragma endregion
#pragma region Random Definitions
bool bool_player[50];
int FreezePedID = 0;
bool Dev_access[50];
bool prologueBypassWebCheck[1];
bool GameSizeWebCheck[1];
int MenuColour_R = 0,
MenuColour_G = 0,
MenuColour_B = 0;
int DeleteSpawnedPedFreezeDelay = 0;
bool isFirstPersonEnabled = false; // 0 = false by default
bool godmodeveh = false;
Object floatation;
int driveonwater = 0;
int invprop;
bool Radaroff = false;
bool RevealAll = false;
bool donwater = false;
bool invwater;
int MoneyRange_ = 0;
bool forcefeld = false;
bool DisableAcc = false;
//bool moneyrain = false;
bool rapidfire = false;
bool GODMODE_NEW = false;
bool rainmoney;//original bool rainmoney;
bool ocean_intensity_toggle = false;
int rainmoneycooldown = 0;
int rainweaponscooldown = 0;
bool clientwanted = false;
bool rainweapons;
bool selfoffradar = false;
//unsigned int TunablePointer = 0x1E70374; //already Defined
bool NoCops = false;
bool TimeStopped = true;//Remove True & or False if this Option fails
int time1;//Advanced Time Def
bool neededbool;
char *char_PlayerOption[50];
bool bool_PlayerOption[50];
bool HasNeons = false;
bool NonHostKickProtect = false;
bool Godmodplveh = false;
bool fakeloop40 = false;
bool RPfix = false;
bool specPlayer = false;
bool hasLoopNeon;
bool BigPunch = false;
bool oneshot = false;
bool hasLinkedNeon;
bool Tunable_Valentines;
bool resetviewfix = false;
bool Tunable_Independance;
bool teleprotect = false;
bool BankFix = false;
bool Tunable_NY;
bool fakeleavefix = false;
bool Tunable_XMas;
bool Tunable_Snow;
int currentOption;
bool ghostrider1 = false;
bool ghostrider2 = false;
bool bool_lobby[50];
bool loop40K_ = false;
bool Minigame = false;
bool FXPro = false;
bool ControlPro = false;
bool SpamPro = false;
bool TimePro = false;
bool weatherpro = false;
bool auto_pilot = 0;
bool bool_eventp[50];
Entity JetpackID = 0;
bool leftfix;
bool downscorch;
bool BossMode = false;
Vehicle car, plane;
Ped pilot;
bool adminkickprotect = false;
bool dropkickpro = false;
bool jaro666 = false;
bool wanted = false;
bool Resetviewlp = false;
int MaxRadius = 8;
int fastScrollSpeed = 1;
void WriteInt32(int Address, int Input) { *(int*)Address = Input; }
char RLL[100];
bool Neontoggle = false;
int NeonR = 0, NeonG = 0, NeonB = 0;//add this to Vehicle Mods
int TunablesPtr1 = 0x1E70374;
//Tow Truck Shit Start
bool isrc = false;
int Savedvehicle[2];// {attached handle, your cars handle}
bool detachTowTruckCar = false;
int detachTowTruckIndex = 0;
int detachTowTruckTimeout = 10000;
int detachTowTruckTimeoutCounter = 0;
int TeleportVehicle = 0;
bool TeleportToMe = false;
bool IPinfo = false;
bool ghostrider11 = false;
bool Give_RP = false;
bool Take_RP = false;
//Tow Truck Shit End
bool FX_PlayFX = true;
char* FX_FXType;
char* FX_FXName;

void PRINT(const char* Text, int MillisecondsToDisplay = 4000)
{
	__PRINT_TEXT_TYPE("STRING");
	__PRINT_TEXT_TEXT(Text); __PRINT_TEXT_TIME(MillisecondsToDisplay);
}
void PlayFX(char* FXType, char* FXName)
{
	FX_PlayFX = true;
	FX_FXType = FXType;
	FX_FXName = FXName;
}
void SetTunable1(int index, int value)
{
	int TunablesAddress = (*(int*)TunablesPtr1) + 4;
	{
		if (TunablesAddress != 0)
		{
			int temp = TunablesAddress;
			temp += (index * 4);
			*(int*)temp = value;
		}
	}
}

/*
bool ParticleFX(char* FXType, char* FXName, int Entity = PLAYER::PLAYER_PED_ID(), float X = 0, float Y = 0, float Z = 0, float Pitch = 0, float Roll = 0, float Yaw = 0)
{
	STREAMING::_REQUEST_DLC_PTFX_ASSET(FXType);
	GRAPHICS::_0x9C720B61(FXType);
	if (STREAMING::_HAS_DLC_PTFX_LOADED(FXType))
	{
		GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY(FXName, Entity, X, Y, Z, Pitch, Roll, Yaw, 1, false, false, false);
		return true;
	}
	else
		return false;
}*/
void DrawNeons(int R, int G, int B)
{
	int VehicleID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
	Vector3 Coords = ENTITY::GET_ENTITY_COORDS(VehicleID, true);
	DRAW_LIGHT_WITH_RANGE(&Coords, R, G, B, 4.0f, 2.0f);
}
bool Write_Global(int a_uiGlobalID, int a_uiValue) {
	int Ptr = *(int*)((TunablePointer - 0x04) + (((a_uiGlobalID / 0x40000) & 0x3F) * 4));
	if (Ptr != 0) {
		*(int*)(Ptr + ((a_uiGlobalID % 0x40000) * 4)) = a_uiValue; return true; //nah nvm I think its good now that we fixed addOption 
	}
	return false;
}
void drawText(char * text, int font, float x, float y, float scalex, float scaley, int r, int g, int b, int a, bool center)
{
	//if (auth_Drawtext) 
	{
		UI::SET_TEXT_FONT(font);
		UI::SET_TEXT_SCALE(scalex, scaley);
		UI::SET_TEXT_COLOUR(r, g, b, a);
		UI::SET_TEXT_WRAP(0.0f, 1.0f);
		UI::SET_TEXT_CENTRE(center);
		UI::SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
		UI::SET_TEXT_OUTLINE();
		UI::_SET_TEXT_ENTRY("STRING");
		UI::_ADD_TEXT_COMPONENT_STRING(text);
		UI::_DRAW_TEXT(x, y);
	}

}
void drawInfoText(char * text, int font, float x, float y, float scalex, float scaley, int r, int b, int g, int a, bool center, int dec = 0, bool outline = false) {
	if (strcmp(GET_THIS_SCRIPT_NAME(), "ingamehud") == 0) {
		UI::SET_TEXT_FONT(font);
		UI::SET_TEXT_SCALE(scalex, scaley);
		UI::SET_TEXT_COLOUR(r, g, b, a);
		if (dec == 0) {
			UI::SET_TEXT_WRAP(0.0f, 1.0f);
		}
		else {
			UI::SET_TEXT_WRAP(0.0f, .665);
			SET_TEXT_RIGHT_JUSTIFY(true);
		}
		UI::SET_TEXT_CENTRE(center);
		UI::SET_TEXT_COLOUR(r, g, b, a);
		if (outline)UI::SET_TEXT_OUTLINE();
		UI::_SET_TEXT_ENTRY("STRING");
		_ADD_TEXT_COMPONENT_STRING(text);;
		UI::_DRAW_TEXT(x, y);
	}
}
void DisableIdleKick() {
	SetTunable1(73, 0x3B9ACA00);
	SetTunable1(74, 0x3B9ACA00);
	SetTunable1(75, 0x3B9ACA00);
	SetTunable1(76, 0x3B9ACA00);
	Write_Global(1325828, 0);//disable timeout (for being idle)
}
int GET_FREE_SEAT(int veh)
{
	int numSeats = VEHICLE::GET_VEHICLE_MAX_NUMBER_OF_PASSENGERS(veh);
	int seat = -1;
	while (seat < numSeats)
	{
		if (VEHICLE::IS_VEHICLE_SEAT_FREE(veh, seat))
		{
			return seat;
		}
		seat++;
	}
	return -2;
}
#pragma endregion
#pragma region Money Stuff & First Person
bool DROP40(Vector3 Inp)
{
	STREAMING::REQUEST_MODEL(0x113FD533);
	if (STREAMING::HAS_MODEL_LOADED(0x113FD533))
	{
		OBJECT::CREATE_AMBIENT_PICKUP(0xCE6FDD6B, Inp.x, Inp.y, Inp.z, 0, 40000, 0x113FD533, 0, 1);
		return true;
	}
	else
		return false;
}
Vector3 get_coords_from_cam(float distance) {
	Vector3 Rot = CAM::GET_GAMEPLAY_CAM_ROT(2);
	Vector3 Coord = CAM::GET_GAMEPLAY_CAM_COORD();
	Rot.y = distance * SYSTEM::COS(Rot.x);
	Coord.x = Coord.x + Rot.y * SYSTEM::SIN(Rot.z * -1.0f);
	Coord.y = Coord.y + Rot.y * SYSTEM::COS(Rot.z * -1.0f);
	Coord.z = Coord.z + distance * SYSTEM::SIN(Rot.x);
	return Coord;
}

#pragma endregion
#pragma region Veh Stuff & More money Shit
//does this one work?
void ToNearestCar()
{
	Vector3 Coords16 = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	int VehID = VEHICLE::GET_CLOSEST_VEHICLE(Coords16.x,Coords16.y,Coords16.z, 150.0, 0, 71);
	PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), VehID, -1);
}
void drawCount(char *text, int font, float scaleX, float scaleY, int r, int g, int b, int a, float start, float end, float x, float y, bool otherside)
{
	UI::_SET_TEXT_ENTRY("STRING");
	UI::SET_TEXT_RIGHT_JUSTIFY(otherside);
	UI::SET_TEXT_FONT(font);
	UI::SET_TEXT_SCALE(scaleX, scaleY);
	UI::SET_TEXT_WRAP(start, end);
	UI::SET_TEXT_COLOUR(r, g, b, a);
	UI::_ADD_TEXT_COMPONENT_STRING(text);
	UI::_DRAW_TEXT(x, y);
}

void rain_money()
{
	float angle = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, MoneyRange_) * 3.14159265359;
	float radius = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, MoneyRange_) * 5.0f;
	float x = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true).x + radius * SYSTEM::COS(angle);
	float y = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true).y + radius * SYSTEM::SIN(angle);
	STREAMING::REQUEST_MODEL(0x113FD533);
	if (STREAMING::HAS_MODEL_LOADED(0x113FD533))
	{
		OBJECT::CREATE_AMBIENT_PICKUP(0xCE6FDD6B, x, y, ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true).z + 75.0f, 0, 40000, 0x113FD533, 0, 1); //0xCE6FDD6B = Money bag 40K prop
	}
}

#pragma endregion
#pragma region Troll Defs
void ATTACH_ENTITY_TO_ENTITY1(Entity Ent1, Entity Ent2, float X = 0, float Y = 0, float Z = 0, float Pitch = 0, float Roll = 0, float Yaw = 0, bool HasPhysics = false) {
	ENTITY::ATTACH_ENTITY_TO_ENTITY(Ent1, Ent2, 0, X, Y, Z, Pitch, Roll, Yaw, 1, 0, 0, 1, 2, 1);
	if (HasPhysics) {
		ENTITY::SET_ENTITY_INVINCIBLE(Ent1, true);
		ENTITY::SET_ENTITY_COLLISION(Ent1, true, false);
	}
}
#pragma endregion
#pragma region Self

bool neverwanted = false;

float TrainSpeed;

bool drivetrain  = false; 

int TrainID;

char *weps[] = { "WEAPON_UNARMED","WEAPON_KNIFE","WEAPON_NIGHTSTICK","WEAPON_HAMMER","WEAPON_BAT","WEAPON_GOLFCLUB","WEAPON_CROWBAR","WEAPON_PISTOL","WEAPON_COMBATPISTOL","WEAPON_APPISTOL","WEAPON_PISTOL50","WEAPON_MICROSMG","WEAPON_SMG","WEAPON_ASSAULTSMG","WEAPON_ASSAULTRIFLE","WEAPON_ADVANCEDRIFLE","WEAPON_MG","WEAPON_COMBATMG","WEAPON_PUMPSHOTGUN","WEAPON_SAWNOFFSHOTGUN","WEAPON_ASSAULTSHOTGUN","WEAPON_BULLPUPSHOTGUN","WEAPON_STUNGUN","WEAPON_SNIPERRIFLE","WEAPON_HEAVYSNIPER","WEAPON_REMOTESNIPER","WEAPON_GRENADELAUNCHER","WEAPON_GRENADELAUNCHER_SMOKE","WEAPON_RPG","WEAPON_STINGER","WEAPON_MINIGUN","WEAPON_GRENADE","WEAPON_STICKYBOMB","WEAPON_SMOKEGRENADE","WEAPON_BZGAS","WEAPON_MOLOTOV","WEAPON_FIREEXTINGUISHER","WEAPON_PETROLCAN","WEAPON_BALL","WEAPON_FLARE","WEAPON_BOTTLE","WEAPON_GUSENBERG","WEAPON_SPECIALCARBINE","WEAPON_HEAVYPISTOL","WEAPON_SNSPISTOL","WEAPON_BULLPUPRIFLE","WEAPON_DAGGER","WEAPON_VINTAGEPISTOL","WEAPON_FIREWORK","WEAPON_MUSKET","WEAPON_HEAVYSHOTGUN","WEAPON_MARKSMANRIFLE","WEAPON_HOMINGLAUNCHER","WEAPON_PROXMINE","WEAPON_SNOWBALL","WEAPON_FLAREGUN","WEAPON_GARBAGEBAG","WEAPON_COMBATPDW","WEAPON_MARKSMANPISTOL","WEAPON_KNUCKLE","WEAPON_CARBINERIFLE" };


int cloneself(int PedHandle) 
{
	return PED::CLONE_PED(PedHandle, ENTITY::GET_ENTITY_HEADING(PedHandle), true, true);
}

bool unlimitedammo = false;

void unlimitedclip() {
	unlimitedammo = !unlimitedammo;
	WEAPON::SET_PED_INFINITE_AMMO_CLIP(PLAYER::PLAYER_PED_ID(), unlimitedammo); //Always on when true
}

bool noragdoll = false;

bool superRun = false;

bool ClearPlayrTaskLoop = false;

void endTask(int Client)
{
	AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::GET_PLAYER_PED(Client));
}
#pragma endregion
#pragma region debug Freeze
char byteArray3[144];
char *ReadBytes3(int address, int length)
{
	for (int i = 0; i < length; i++)
	{
		byteArray3[i] = *(char*)(address + (i));
	}
	return byteArray3;
}
bool doClown = false;
bool spawnClown()
{
	if (doClown)
	{
		STREAMING::REQUEST_MODEL(GAMEPLAY::GET_HASH_KEY("s_m_y_clown_01"));
		Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), 1);
		if (STREAMING::HAS_MODEL_LOADED(GAMEPLAY::GET_HASH_KEY("s_m_y_clown_01")))
		{
			int Ped = (PED::CREATE_PED(21, 0x3F039CBA, coords.x, coords.y, coords.z, 0, 1, 0));
			if (ENTITY::DOES_ENTITY_EXIST(Ped))
			{
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(GAMEPLAY::GET_HASH_KEY("s_m_y_clown_01"));
				ENTITY::ATTACH_ENTITY_TO_ENTITY(Ped, selectedPlayer, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1);
				return true;
			}
			return false;
		}
		return false;
	}
}
/*
bool taxif = false;//bool taxiif;
bool Taxif() {
	if (PLAYER::GET_PLAYER_MAX_ARMOUR(PLAYER::GET_PLAYER_PED(selectedPlayer)) != 170 && PLAYER::IS_PLAYER_PLAYING(selectedPlayer) && (selectedPlayer)) {
		char *FuncByteslaserB = ReadBytes3(0x402D9A10, 0x90); //laser
		WriteBytes((int)0x402CF6C0, FuncByteslaserB, 0x90);//TAXI = 0x402CF6C0 
		char cmd1B[] = { 0x47, 0xF0, 0x4F, 0x80 };
		char cmd2B[0x10] = {};
		WriteBytes((int)0x4120CC28, cmd1B, 4);
		WriteBytes((int)0x4120CD00, cmd2B, 0x10);
		uint Handle = PLAYER::GET_PLAYER_PED(selectedPlayer);
		Vector3 c = ENTITY::GET_ENTITY_COORDS(Handle, 1);
		int hash = GAMEPLAY::GET_HASH_KEY("taxi");
		STREAMING::REQUEST_MODEL(hash);
		if (STREAMING::HAS_MODEL_LOADED(hash)) {
			int Vehicle = VEHICLE::CREATE_VEHICLE(hash, c.x, c.y, c.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
			if (ENTITY::DOES_ENTITY_EXIST(Vehicle)) {
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
				SYSTEM::WAIT(50);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(Vehicle, Handle, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0, 1, 0, 0, 2, 1);
				ENTITY::SET_ENTITY_VISIBLE(Vehicle, 0);
				SYSTEM::WAIT(4050);
				PRINT("~w~FREEZING ~w~%s ~b~NOW!!!");
				return true;
			}
			return false;
		}
		return false;
	}
}*/
#pragma endregion
#pragma region Fun Mods



#pragma endregion
#pragma region Weapons Self
void giveAll(int id) {
	for (int i = 0; i < 61; i++) { // Ped ped, Hash weaponHash, int ammoCount, BOOL equipNow
		WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(id), GAMEPLAY::GET_HASH_KEY(weps[i]), 9999, 1);//-1 is infinite ammo, example (GAMEPLAY::GET_HASH_KEY(weps[i]), -1, 1))
	}
}
#pragma endregion


#pragma region Vehicle Mods
void BoostVehicleForward() 
{
	VEHICLE::SET_VEHICLE_FORWARD_SPEED(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false), 100.0f);
}

void FixVehicle() {
	VEHICLE::SET_VEHICLE_FIXED(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false));
	VEHICLE::SET_VEHICLE_DEFORMATION_FIXED(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false));
	VEHICLE::SET_VEHICLE_DIRT_LEVEL(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false), 0.0f); // Dirt LVL 0 = clean, 10 = Dirty
}

void BoostVehicleBackward() {
	VEHICLE::SET_VEHICLE_FORWARD_SPEED(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false), -100.0f);
}

void FlipVehicle() {
	VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false));
}

void RainbowCar()
{
	int Red = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255),
		Green = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255),
		Blue = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255);
	VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false), Red, Green, Blue);
	VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false), Red, Green, Blue);
}

void maxupgrades(Vehicle VehicleHandle) {
	VEHICLE::SET_VEHICLE_MOD_KIT(VehicleHandle, 0);
	VEHICLE::SET_VEHICLE_COLOURS(VehicleHandle, 120, 120);
	VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(VehicleHandle, "TinyMenu");
	VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(VehicleHandle, 5);
	VEHICLE::TOGGLE_VEHICLE_MOD(VehicleHandle, 18, 1);
	VEHICLE::TOGGLE_VEHICLE_MOD(VehicleHandle, 22, 1);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 16, 5, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 12, 2, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 11, 3, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 14, 14, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 15, 3, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 13, 2, 0);
	VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehicleHandle, 6);
	VEHICLE::SET_VEHICLE_WINDOW_TINT(VehicleHandle, 5);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 23, 19, 1);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 0, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 1, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 2, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 3, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 4, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 5, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 6, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 7, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 8, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 9, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 10, 1, 0);
	VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(VehicleHandle, false);
}

void godmodecar(bool toggleOn) {
	if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), true)); 
	{
		Entity self = PLAYER::PLAYER_PED_ID();
		Vehicle playerVeh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED(self), 0);
		ENTITY::SET_ENTITY_INVINCIBLE(playerVeh, toggleOn);
		ENTITY::SET_ENTITY_CAN_BE_DAMAGED(playerVeh, false);
		ENTITY::SET_ENTITY_PROOFS(playerVeh, toggleOn, toggleOn, toggleOn, toggleOn, toggleOn, toggleOn, toggleOn, toggleOn);
		VEHICLE::SET_VEHICLE_CAN_BREAK(playerVeh, 0);
		VEHICLE::SET_VEHICLE_CAN_BE_VISIBLY_DAMAGED(playerVeh, false);
		VEHICLE::SET_VEHICLE_STRONG(playerVeh, toggleOn);
		VEHICLE::SET_VEHICLE_DIRT_LEVEL(playerVeh, 0.0f);
		VEHICLE::SET_VEHICLE_DEFORMATION_FIXED(playerVeh);
		VEHICLE::SET_VEHICLE_ENGINE_CAN_DEGRADE(playerVeh, false);
		VEHICLE::SET_VEHICLE_EXPLODES_ON_HIGH_EXPLOSION_DAMAGE(playerVeh, false);
		VEHICLE::SET_VEHICLE_IS_WANTED(playerVeh, false);
		if (VEHICLE::GET_VEHICLE_BODY_HEALTH(playerVeh) < 1000.0f)
		{
			VEHICLE::SET_VEHICLE_BODY_HEALTH(playerVeh, 1000.0f);
		}
		VEHICLE::SET_VEHICLE_CAN_BE_USED_BY_FLEEING_PEDS(playerVeh, false);
		 //FLAG_NO_RESPRAY needs to be removed from vehicles.meta for unrestricted access to LSC for any vehicle. spawned or not.
	}
 
}

int driveontype = 1;

bool driftmod = false;

bool VehicleNOS = false;

bool pushvehicle = false;

int vehiclecatagories = 0;

bool creatvehiclenow = false;

int vehcounter = 0;

int veh[50];

bool fcar = false;

bool fcar2 = false;

int PersonalOrLast = 0;

bool create_vehicle(int vehiclehash)
{
	STREAMING::REQUEST_MODEL(vehiclehash);
	if (STREAMING::HAS_MODEL_LOADED(vehiclehash))
	{
		Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
		 veh[vehcounter] = VEHICLE::CREATE_VEHICLE(vehiclehash, pos.x, pos.y, pos.z, 90.0, true, false);
		 PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), veh[vehcounter], -1);
		 if (ENTITY::DOES_ENTITY_EXIST(veh[vehcounter]))
		 {
			 ++vehcounter;
			 return true;
		} 
	}
	return false;
}

bool clearArea = false;

//void ejectorseat() {
	//int veh = _0xFDA7B6CA;
	//VEHICLE::_0xFDA7B6CA(uParam2, 0f, -9f, 10f);
//}


void FlyingCar()
{
	PRINT("~HUD_COLOUR_GREEN~Rudder = L1 Or R1", 2000);
	int VehicleHandle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
	float Speed = ENTITY::GET_ENTITY_SPEED(VehicleHandle);
	Speed += 2;
	Vector3 rot = ENTITY::GET_ENTITY_ROTATION(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), true), 2);
	if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0))
	{
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED(PLAYER::PLAYER_PED_ID()), true));
		if (VEHICLE::IS_VEHICLE_ON_ALL_WHEELS(VehicleHandle))
		{
			if (CONTROLS::IS_CONTROL_PRESSED(0, Button_R2))
			{
				ENTITY::APPLY_FORCE_TO_ENTITY(VehicleHandle, 1, 0, 0, 0.02555, 0, 2.955, 0, 1, 1, 1, 1, 0, 1);
				VEHICLE::SET_VEHICLE_FORWARD_SPEED(VehicleHandle, Speed);
			}
			if (CONTROLS::IS_CONTROL_PRESSED(0, Button_L2))
			{
				ENTITY::APPLY_FORCE_TO_ENTITY(VehicleHandle, 1, 0, 0, 0.02555, 0, -2.955, 0, 1, 1, 1, 1, 0, 1);
				VEHICLE::SET_VEHICLE_FORWARD_SPEED(VehicleHandle, -Speed);
			}
		}
		else
		{
			if (CONTROLS::IS_CONTROL_PRESSED(0, Button_R2))
				VEHICLE::SET_VEHICLE_FORWARD_SPEED(VehicleHandle, 65);

			if (CONTROLS::IS_CONTROL_PRESSED(0, Button_L2))
				VEHICLE::SET_VEHICLE_FORWARD_SPEED(VehicleHandle, -20); //-65 was previous number

			CONTROLS::SET_INPUT_EXCLUSIVE(2, 196);
			if (CONTROLS::IS_CONTROL_PRESSED(0, Button_L1))
				ENTITY::SET_ENTITY_ROTATION(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), true), rot.x, rot.y, rot.z += 1.5, 2, 1);
			if (CONTROLS::IS_CONTROL_PRESSED(0, Button_R1))
				ENTITY::SET_ENTITY_ROTATION(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), true), rot.x, rot.y, rot.z -= 1.5, 2, 1);
			if (CONTROLS::IS_CONTROL_PRESSED(0, Button_L2) && CONTROLS::IS_CONTROL_PRESSED(0, Button_R2))
				VEHICLE::SET_VEHICLE_FORWARD_SPEED(VehicleHandle, 0);
		}
	}
}
void flatocean() 
{	
	float height = 0;
	//Vector3				Fix Code Later
	WATER::GET_WATER_HEIGHT_NO_WAVES(0, 0, 0, 0);
	WATER::GET_WATER_HEIGHT(0, 0, 0, 0);
}
void LoopingNeons() {
	DrawNeons(NeonR, NeonG, NeonB);
}
void VehicleMaxUpgrades(int VehicleHandle)//PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(),0)
{
	NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(VehicleHandle);
	if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(VehicleHandle))
	{
		VEHICLE::SET_VEHICLE_MOD_KIT(VehicleHandle, 0);
		VEHICLE::SET_VEHICLE_COLOURS(VehicleHandle, 120, 120);
		VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(VehicleHandle, "TinyMenu");
		VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(VehicleHandle, 1);
		VEHICLE::TOGGLE_VEHICLE_MOD(VehicleHandle, 18, 1);
		VEHICLE::TOGGLE_VEHICLE_MOD(VehicleHandle, 22, 1);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 16, 5, 0);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 12, 2, 0);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 11, 3, 0);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 14, 14, 0);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 15, 3, 0);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 13, 2, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehicleHandle, 6);
		VEHICLE::SET_VEHICLE_WINDOW_TINT(VehicleHandle, 5);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 23, 19, 1);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 0, 1, 0);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 1, 1, 0);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 2, 1, 0);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 3, 1, 0);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 4, 1, 0);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 5, 1, 0);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 6, 1, 0);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 7, 1, 0);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 8, 1, 0);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 9, 1, 0);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 10, 1, 0);
	}
}
bool dorollercoaster;
bool spawnrollercoaster()
{
	uint Handle = PLAYER::PLAYER_PED_ID();
	Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(Handle, 1);
	int hash = GAMEPLAY::GET_HASH_KEY("blazer");
	int hash2 = GAMEPLAY::GET_HASH_KEY("prop_roller_car_01");
	STREAMING::REQUEST_MODEL(hash);
	STREAMING::REQUEST_MODEL(hash2);
	if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2)) {
		int Object = OBJECT::CREATE_OBJECT(hash2, 0, 0, 0, 1, 0, 1),
			Object2 = OBJECT::CREATE_OBJECT(hash2, 0, 0, 0, 1, 0, 1),
			Object3 = OBJECT::CREATE_OBJECT(hash2, 0, 0, 0, 1, 0, 1),
			Object4 = OBJECT::CREATE_OBJECT(hash2, 0, 0, 0, 1, 0, 1),
			Object5 = OBJECT::CREATE_OBJECT(hash2, 0, 0, 0, 1, 0, 1);
		if (ENTITY::DOES_ENTITY_EXIST(Object) && ENTITY::DOES_ENTITY_EXIST(Object2) && ENTITY::DOES_ENTITY_EXIST(Object3) && ENTITY::DOES_ENTITY_EXIST(Object4) && ENTITY::DOES_ENTITY_EXIST(Object5)) {
			int Vehicle = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
			if (ENTITY::DOES_ENTITY_EXIST(Vehicle)) {
				PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
				ENTITY::SET_ENTITY_VISIBLE(Vehicle, 0);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, -0.34, -0.08, -0.6, 0, 0, 180, 0, 1, 0, 0, 2, 1);
				ATTACH_ENTITY_TO_ENTITY_PHYSICALLY(Object2, Object, 0, 0, 0.0, 3.2, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0f, 1, 1, 0, 0, 2);
				ATTACH_ENTITY_TO_ENTITY_PHYSICALLY(Object3, Object2, 0, 0, 0.0, 3.2, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0f, 1, 1, 0, 0, 2);
				ATTACH_ENTITY_TO_ENTITY_PHYSICALLY(Object4, Object3, 0, 0, 0.0, 3.2, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0f, 1, 1, 0, 0, 2);
				ATTACH_ENTITY_TO_ENTITY_PHYSICALLY(Object5, Object4, 0, 0, 0.0, 3.2, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0f, 1, 1, 0, 0, 2);
				ENTITY::SET_ENTITY_VISIBLE(Handle, 0);
				return true;
			}
			return false;
		}
		return false;
	}
	return false;
}
bool boostHorn = false;

void playrhornboost(int selectedplayer)
{
	if (boostHorn)
	{
		bool isHornPressed = PLAYER::IS_PLAYER_PRESSING_HORN(selectedplayer);//<TYPE> <VALUE> Created our own variable
		if (isHornPressed)
		{
			int vehicle = PED::GET_VEHICLE_PED_IS_IN(selectedplayer, 0);
			NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(vehicle);
			VEHICLE::SET_VEHICLE_FORWARD_SPEED(vehicle, 100.0f);
		}
	}
}
#pragma endregion

#pragma region New Money Drop

bool moneyrain;
int rainm;
char *rainnames[] = { "Money Bag","Baggage", "Air Hockey", "Beer Bottle", "Armour", "Sheild", "Barbell",  "BBQ", "Bowling Ball", "Bowling Pin", "Kayak 1", "Kayak 2" };
Hash rainHashes[] = { 0x113FD533, 0x8DE4F79E, 0x9BE9742E, 0x28BE7556, 0x29CB0F3C, 0x44083A8F, 0xE2FBA8D8, 0x1EFB7B6C, 0xDE6C3FFE, 0xA67C935F, 0xE1C17F6F, 0x9C5D94D2 };
void Dropmoney(int Player)
{
	{
		STREAMING::REQUEST_MODEL(rainHashes[rainm]);
		if (STREAMING::HAS_MODEL_LOADED(rainHashes[rainm]))
		STREAMING::REQUEST_MODEL(0x113FD533);
		Vector3 Player = GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS2(PLAYER::PLAYER_PED_ID(), 0.0, 0.0, 0);
		int offsetX = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(-MaxRadius, MaxRadius);
		int offsetyY = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(-MaxRadius, MaxRadius);
		int offsetX1 = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(-MaxRadius, MaxRadius);
		int offsetyY1 = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(-MaxRadius, MaxRadius);
		int offsetZ = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(8, 60);

		if (STREAMING::HAS_MODEL_LOADED(0x113FD533))
		{
			int PICKUP_MONEY_CASE = GAMEPLAY::GET_HASH_KEY("PICKUP_MONEY_CASE");
			int AMOUNT = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(20000, 90000);
			Vector3 Cord1 = { Player.x + offsetX, Player.y + offsetyY, Player.z + offsetZ };
			Vector3 Cord2 = { Player.x + offsetX1, Player.y + offsetyY1, Player.z + offsetZ };
			__CREATE_AMBIENT_PICKUP(PICKUP_MONEY_CASE, Cord1, 0, AMOUNT, rainHashes[rainm], 0, 1);
			__CREATE_AMBIENT_PICKUP(PICKUP_MONEY_CASE, Cord2, 0, AMOUNT, rainHashes[rainm], 0, 1);



		}
	}
}
void MoneyLoop()
{
	if (!loop40K_)
	{
		loop40K_ = true;
	}
	else
	{
		loop40K_ = false;
	}
}
/*

bool Dropmoney(int Player)
{
	STREAMING::REQUEST_MODEL(rainHashes[rainm]);
	if (STREAMING::HAS_MODEL_LOADED(rainHashes[rainm]))
	{
		Vector3 Player = GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS2(PLAYER::GET_PLAYER_PED(selectedPlayer), 0.0, 0.0, 0);
		int offsetX = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(-MaxRadius, MaxRadius);
		int offsetyY = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(-MaxRadius, MaxRadius);
		int offsetX1 = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(-MaxRadius, MaxRadius);
		int offsetyY1 = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(-MaxRadius, MaxRadius);
		int offsetZ = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(8, 60);
		OBJECT::CREATE_AMBIENT_PICKUP(0xCE6FDD6B, MyCoords.x, MyCoords.y, MyCoords.z, 0, 40000, rainHashes[rainm], 0, 1);
		return true;
	}
	else
		return false;
}
*/
#pragma endregion
#pragma region protection func
bool bool_protection[50];

#pragma endregion
#pragma region ghost rider
int ParticleManBones[] = { 31086,18905,57005,14201,52301 };
int int_PlayerOption[20];
#pragma endregion
//MODDER PROTECTION STARTS HERE U BLIND BAT!!!
#pragma region Modder Protections

union ScriptArg {
	unsigned int ui; float f; int i; char *str;
};
static void TRIGGER_SCRIPT_EVENT(Any p0, int* p1, Any p2, int p3) { invoke<Void>(0x54763B35, p0, p1, p2, p3); } // 0x54763B35
static void TRIGGER_SCRIPT_EVENT(int always1, ScriptArg *argsStruct, int argsStructCount, int playerbitset) { invoke<Void>(0x54763B35, always1, argsStruct, argsStructCount, playerbitset); } // 0x54763B35
static void TriggerScriptEvent(int* Args, int ArgCount, Player BitsetPlayer) { int Bitset = 0; SET_BIT(&Bitset, BitsetPlayer); if (Bitset != 0) { TRIGGER_SCRIPT_EVENT(1, Args, ArgCount, Bitset); } }
namespace PlayerMods {
	namespace eventCreator {
		void callScriptEvent(ScriptArg *args, int argsCount, unsigned int playerBits) {
			TRIGGER_SCRIPT_EVENT(1, args, argsCount, playerBits);
		}
	};
};
#pragma endregion
#pragma region Non host kick 
void kickPlayerNonHost(int player) {
	unsigned int playerBit = (1 << player);
	ScriptArg args[3] = {
		0x2,player,0x35 };//0x35 is the speccial one I guess
	TRIGGER_SCRIPT_EVENT(1, args, 3, playerBit);
}
#pragma endregion
#pragma region Protections
void setupDefaultStatEvent(int player, ScriptArg *args) {
	args[0].i = 150;
	args[1].i = player;
	args[2].i = player;//unknown value
	args[3].i = 88;//int
	args[4].i = 34;//bool
	args[5].i = 1;//float
	args[6].i = 2949;//int
	args[7].i = 228;//bool
	args[8].i = 228;//float
	args[9].i = 0;//value to set for the int ones. This is added on to the previous value set for the stat
	args[10].i = 0;//value to set for the float ones. This is added on to the previous value set for the stat
	args[11].i = 0;//value to set for the bool ones
}
bool globalStatVersionType = 1;
void setPlayerStatInt(int player, int statIndex, int statValue, bool type = globalStatVersionType) {
	statValue = 0xFFFFFFFF - statValue + 1;
	ScriptArg args[12];
	setupDefaultStatEvent(player, args);
	//printf("%i\n", args[6].i);
	args[EVENT_STAT_VALUE_INT].ui = *(unsigned int*)(&statValue);
	args[EVENT_STAT_VALUE_BOOL].i = statValue;
	args[EVENT_STAT_VALUE_FLOAT].f = statValue;
	if (type == 0)
		args[EVENT_STAT_INT_0].i = statIndex;
	else
		args[EVENT_STAT_INT_1].i = statIndex;
	unsigned int bits = (1 << player);
	PlayerMods::eventCreator::callScriptEvent(args, 12, bits);
}
void setPlayerStatBool(int player, int statIndex, bool statValue, bool type = globalStatVersionType) {
	ScriptArg args[12];
	setupDefaultStatEvent(player, args);
	args[EVENT_STAT_VALUE_INT].i = *(unsigned int*)(&statValue);
	args[EVENT_STAT_VALUE_BOOL].i = statValue;
	args[EVENT_STAT_VALUE_FLOAT].f = statValue;
	if (type == 0)
		args[EVENT_STAT_BOOL_0].i = statIndex;
	else
		args[EVENT_STAT_BOOL_1].i = statIndex;
	unsigned int bits = (1 << player);
	PlayerMods::eventCreator::callScriptEvent(args, 12, bits);
}
opd_s _0x012C8D60_t = { 0x0012C8D60,TOC };
unsigned int(*_0x0012C8D60)(unsigned int r3, unsigned int senderData, unsigned int recieverData, unsigned int r6, unsigned int r7, unsigned int r8, unsigned int r9) = (unsigned int(*)(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int))&_0x012C8D60_t;
char scriptEventDialogText[100];
unsigned int scriptEventDetour(unsigned int r3, unsigned int senderData, unsigned int recieverData, unsigned int r6, unsigned int r7, unsigned int r8, unsigned int r9) {
	int addressOfArgs = r3 + 10 * 0x4;
	char *senderName = (char*)(*(int*)(senderData + 0x78) + 0x10);
	if (NonHostKickProtect)
	{
		if (*(int*)addressOfArgs == 0x2 && *(int*)(addressOfArgs + 0x8) == 0x35) {
			snprintf(scriptEventDialogText, sizeof(scriptEventDialogText), "~b~NOTICE!!!  ~b~%s  ~w~Tried To Non Host Kick You!", senderName);
			PRINT(scriptEventDialogText, 5000);
			*(int*)addressOfArgs = 0;
		}
	}
	if (fakeleavefix)
	{
		if (*(int*)addressOfArgs == 0x2 && *(int*)(addressOfArgs + 0x8) == 0x34) {
			snprintf(scriptEventDialogText, sizeof(scriptEventDialogText), "~b~NOTICE!!!  ~b~%s  ~w~Tried Fake leave On You!", senderName);
			PRINT(scriptEventDialogText, 5000);
			*(int*)addressOfArgs = 0;
		}
	}
	if (resetviewfix)
	{
		if (*(int*)addressOfArgs == 0x2 && *(int*)(addressOfArgs + 0x8) == 0x2e) {
			snprintf(scriptEventDialogText, sizeof(scriptEventDialogText), "~b~NOTICE!!!  ~b~%s  ~w~Tried To Reset Your View!", senderName);
			PRINT(scriptEventDialogText, 4000);
			*(int*)addressOfArgs = 0;
		}
	}
	if (RPfix)
	{
		if (*(int*)addressOfArgs == 0xD8) {
			snprintf(scriptEventDialogText, sizeof(scriptEventDialogText), "~b~NOTICE!!!  ~b~%s  ~w~Tried To Give You %i RP!", senderName, *(int*)(addressOfArgs + 0x8));
			PRINT(scriptEventDialogText, 5000);
			*(int*)addressOfArgs = 0;
		}
	}
	if (BankFix)
	{
		if (*(int*)addressOfArgs == 0xDA && *(int*)addressOfArgs == 0xDB) {
			if (bool_protection[16]) {
				snprintf(scriptEventDialogText, sizeof(scriptEventDialogText), "~b~NOTICE!!!  ~b~%s  ~w~Tried Adding Money To Your Bank!", senderName);
				PRINT(scriptEventDialogText, 5000);
			}
		}
	}
	if (teleprotect)
	{
		if (*(int*)addressOfArgs == 0x16C) {
			snprintf(scriptEventDialogText, sizeof(scriptEventDialogText), "~b~NOTICE!!!  ~b~%s  ~w~Tried Forcing You To Apartment!", senderName);
			PRINT(scriptEventDialogText, 5000);
			*(int*)addressOfArgs = 0;
		}
	}
	if (Minigame)
	{
		if (*(int*)addressOfArgs == 0x3) {
			if (*(int*)(addressOfArgs + 0x8) == 0x37 || *(int*)(addressOfArgs + 0x8) == 0x36 || *(int*)(addressOfArgs + 0x8) == 0x35) {
				snprintf(scriptEventDialogText, sizeof(scriptEventDialogText), "~b~NOTICE!!!  ~b~%s  ~w~Tried Teleporting To Game!", senderName);
				PRINT(scriptEventDialogText, 5000);
				*(int*)addressOfArgs = 0;
			}
		}
		return _0x0012C8D60(r3, senderData, recieverData, r6, r7, r8, r9);
	}
}
void setupScriptEventDetour() {//call this on game start to set it up aka put in Hook()
	*(int*)(0x1C6BD80) = *(int*)( /*this returns the opd struct address Function*/(int)&scriptEventDetour);//same
	*(int*)((0x1C6BD80 + 0x4)) = *(int*)( /*this returns the opd struct address TOC*/(int)&scriptEventDetour + 0x4);
}

opd_s _0x12F7188_t = { 0x12F7188,TOC };
opd_s _0x13398D4_t = { 0x13398D4,TOC };
opd_s _0x133D6EC_t = { 0x133D6EC,TOC };
uint32_t(*getCNetGamePlayer)(uint32_t playerId) = (uint32_t(*)(uint32_t))&_0x12F7188_t;
uint32_t(*getSyncTreePool)(uint32_t cNetworkObjectMgr, uint32_t syncTreetype) = (uint32_t(*)(uint32_t, uint32_t))&_0x13398D4_t; // 0x13398D4
uint32_t(*sub_133D6EC)(uint32_t CNetworkObjectMgr, uint32_t CNetGamePlayer_client, uint32_t CNetGamePlayer_self, uint32_t syncTreetype, uint32_t r7, uint32_t r8, uint32_t r9, uint32_t r10) = (uint32_t(*)(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t))&_0x133D6EC_t; // 0x133D6EC
void kickLocal(int playerID)
{
	uint64_t* hostUUID = (uint64_t*)(*(unsigned int*)(*(unsigned int*)(0x1CF72C4) + 0x40) + 0x1EB8);
	uint64_t realHostUUID = *hostUUID;

	uint32_t address = getCNetGamePlayer(playerID);
	uint32_t cplayerinfo = *(uint32_t*)(address + 0x78);
	uint64_t uuid = *(uint32_t*)(address + 0x40);

	*hostUUID = uuid;
	NETWORK::NETWORK_SESSION_KICK_PLAYER(playerID);
	*hostUUID = realHostUUID;
}

uint32_t sub_133D6EC_hooked(uint32_t CNetworkObjectMgr, uint32_t CNetGamePlayer_client, uint32_t CNetGamePlayer_self, uint32_t syncTreetype, uint32_t r7, uint32_t r8, uint32_t r9, uint32_t r10)
{
	uint32_t sync_pool = getSyncTreePool(CNetworkObjectMgr, syncTreetype);
	if (sync_pool == 0)
	{
		uint32_t cPlayerInfo = *(uint32_t*)(CNetGamePlayer_client + 0x78);
		char* name = (char*)(cPlayerInfo + 0x10);

		char buff[100];
		sprintf(buff, "%s tried to freeze lobby! Kicked him from game\n", name);
		drawNotification(buff);

		kickLocal(selectedPlayer);

		return 6;
	}


	return sub_133D6EC(CNetworkObjectMgr, CNetGamePlayer_client, CNetGamePlayer_self, syncTreetype, r7, r8, r9, r10);
}
void SessionFreezeProtection() {//call this on game start to set it up aka put in Hook()
	*(int*)(0x1C707F0) = *(int*)( /*this returns the opd struct address Function*/(int)&sub_133D6EC_hooked);
}
opd_s sub_A5660C_opd[2] = { 0xA5660C, TOC };
typedef int(*pUnknownFn)(int r3);
pUnknownFn sub_A5660C = (pUnknownFn)sub_A5660C_opd;
int32_t send_global_to_host()
{
	int32_t var_prt = *(int32_t *)(0x1C97580);
	if (var_prt == 0)
	{
		return 0;
	}

	int32_t prt = *(int32_t *)(var_prt);
	uint32_t count = *(int32_t *)(var_prt + 0x8);
	if (count < 1)
	{
		return 0;
	}

	for (int i = 0; i < count; i++) // i >= count
	{
		int32_t value = i * *(int32_t *)(var_prt + 0xC);
		int32_t unk = *(int32_t *)(prt + 0x4 + value);
		if (unk != 0)
		{
			if (*(int32_t *)(unk + 0x3C) == 0xC875557D)
			{
				if (*(int32_t *)(unk) == 0x18B9440)
				{
					sub_A5660C(prt);
					int ret = (value + prt);
					return ret;
				}
			}
		}
	}
	return 0;
}

#pragma endregion
#pragma region GIVE RP
static void TriggerScriptEvent1(int* Args, int ArgCount, Player BitsetPlayer)
{
	int Bitset = 0;
	GAMEPLAY::SET_BIT(&Bitset, BitsetPlayer);
	if (Bitset != 0) {
		SCRIPT::TRIGGER_SCRIPT_EVENT2(1, Args, ArgCount, Bitset);
	}
}
#pragma endregion 
#pragma region autopilot
Vector3 GetWaypoint()
{
	int WaypointHandle = UI::GET_FIRST_BLIP_INFO_ID(8);
	return UI::GET_BLIP_COORDS(WaypointHandle);
}
#pragma endregion
#pragma region Recovery
//Definitions
opd_s STAT_SET_INT1_t = { 0x42BE0C, TOC };
void(*STAT_SET_INT1)(int hash, int stat) = (void(*)(int, int))&STAT_SET_INT1_t;
bool cstrcmp(const char* s1, const char* s2)
{
	while (*s1 && (*s1 == *s2))
		s1++, s2++;
	if (*(const unsigned char*)s1 - *(const unsigned char*)s2 == 0)
		return true;
	else
		return false;
}
opd_s STAT_SET_INT_t = { 0x42BE0C, TOC };//1.26 Address But I think its the same as 1.27
void(*STAT_SET_INT)(int Hash, int Value, int Number) = (void(*)(int, int, int))&STAT_SET_INT_t;
void SET_STAT_INT(int Hash, int Value)
{
	STAT_SET_INT(Hash, Value, 1);
}
//Functions
void MaxSkills()
{
	drawNotification("~HUD_COLOUR_GREEN~Max Skills ~g~Given!");
	STATS::STAT_SET_INT(get_hash_key("MP0_SCRIPT_INCREASE_STAM"), 100, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_SCRIPT_INCREASE_STRN"), 100, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_SCRIPT_INCREASE_LUNG"), 100, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_SCRIPT_INCREASE_DRIV"), 100, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_SCRIPT_INCREASE_FLY"), 100, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_SCRIPT_INCREASE_SHO"), 100, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_SCRIPT_INCREASE_STL"), 100, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_RACES_WON"), 100, 0);
}
void UnlockAllLSC()
{
	drawNotification("~HUD_COLOUR_PINK~Dont Spam or Freeze");//Text Message notification Tested Works Great!
	STATS::STAT_SET_BOOL(get_hash_key("MP0_AWD_FMRACEWORLDRECHOLDER"), 1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_AWD_ENEMYDRIVEBYKILLS"), 600, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_USJS_COMPLETED"), 50, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_USJS_FOUND"), 50, 0);
	STATS::STAT_SET_BOOL(get_hash_key("MP0_AWD_FMWINALLRACEMODES"), 1, 0);
	STATS::STAT_SET_BOOL(get_hash_key("MP0_AWD_FMWINEVERYGAMEMODE"), 1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_DB_PLAYER_KILLS"), 1000, 0); // drive by kills
	STATS::STAT_SET_INT(get_hash_key("MP0_KILLS_PLAYERS"), 1000, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_AWD_FMHORDWAVESSURVIVE"), 21, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_AWD_CAR_BOMBS_ENEMY_KILLS"), 25, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_AWD_FM_TDM_MVP"), 60, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_AWD_HOLD_UP_SHOPS"), 20, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_AWD_RACES_WON"), 101, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_AWD_NO_ARMWRESTLING_WINS"), 21, 0);
	STATS::STAT_SET_BOOL(get_hash_key("MP0_AWD_FMATTGANGHQ"), 1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_AWD_FMBBETWIN"), 50000, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_AWD_FM_DM_WINS"), 51, 0);
	STATS::STAT_SET_BOOL(get_hash_key("MP0_AWD_FMFULLYMODDEDCAR"), 1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_AWD_FM_DM_TOTALKILLS"), 500, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_MPPLY_DM_TOTAL_DEATHS"), 412, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_MPPLY_TIMES_FINISH_DM_TOP_3"), 36, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_PLAYER_HEADSHOTS"), 623, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_AWD_FM_DM_WINS"), 63, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_AWD_FM_TDM_WINS"), 13, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_AWD_FM_GTA_RACES_WON"), 12, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_AWD_FM_GOLF_WON"), 2, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_AWD_FM_SHOOTRANG_TG_WON"), 2, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_AWD_FM_SHOOTRANG_RT_WON"), 2, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_AWD_FM_SHOOTRANG_CT_WON"), 2, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_AWD_FM_SHOOTRANG_GRAN_WON"), 2, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_AWD_FM_TENNIS_WON"), 2, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_MPPLY_TENNIS_MATCHES_WON"), 2, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_MPPLY_TOTAL_TDEATHMATCH_WON"), 63, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_MPPLY_TOTAL_RACES_WON"), 101, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_MPPLY_TOTAL_DEATHMATCH_LOST"), 23, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_MPPLY_TOTAL_RACES_LOST"), 36, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_AWD_25_KILLS_STICKYBOMBS"), 50, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_AWD_50_KILLS_GRENADES"), 50, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_GRENADE_ENEMY_KILLS"), 50, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_AWD_20_KILLS_MELEE"), 50, 0);
}
void UnlockHeist()
{
	drawNotification("~HUD_COLOUR_PINK~Heist Gear ~g~Given!");
	STATS::STAT_SET_INT(get_hash_key("MP0_CHAR_KIT_FM_PURCHASE"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_CHAR_KIT_FM_PURCHASE2"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_CHAR_KIT_FM_PURCHASE3"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_CHAR_KIT_FM_PURCHASE4"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_CHAR_KIT_FM_PURCHASE5"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_CHAR_KIT_FM_PURCHASE6"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_CHAR_KIT_FM_PURCHASE7"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_CHAR_KIT_FM_PURCHASE8"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_CHAR_KIT_FM_PURCHASE9"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_CHAR_KIT_FM_PURCHASE10"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_CHAR_KIT_FM_PURCHASE11"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_CHAR_KIT_FM_PURCHASE12"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_CHAR_KIT_1_FM_UNLCK"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_CHAR_KIT_2_FM_UNLCK"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_CHAR_KIT_3_FM_UNLCK"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_CHAR_KIT_4_FM_UNLCK"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_CHAR_KIT_5_FM_UNLCK"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_CHAR_KIT_6_FM_UNLCK"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_CHAR_KIT_7_FM_UNLCK"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_CHAR_KIT_8_FM_UNLCK"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_CHAR_KIT_9_FM_UNLCK"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_CHAR_KIT_10_FM_UNLCK"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_CHAR_KIT_11_FM_UNLCK"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_CHAR_KIT_12_FM_UNLCK"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_races_won"), 100, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_number_turbo_starts_in_race"), 100, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_usjs_found"), 50, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_usjs_completed"), 50, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_awd_fmwinairrace"), 50, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_awd_fmwinsearace"), 50, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_awd_fmrallywonnav"), 50, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_awd_fmrallywondrive"), 500, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_awd_fm_races_fastest_lap"), 500, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_char_fm_carmod_0_unlck"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_char_fm_carmod_1_unlck"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_char_fm_carmod_2_unlck"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_char_fm_carmod_3_unlck"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_char_fm_carmod_4_unlck"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_char_fm_carmod_5_unlck"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_char_fm_carmod_6_unlck"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_char_fm_carmod_7_unlck"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_CHAR_FM_VEHICLE_1_UNLCK"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_CHAR_FM_VEHICLE_2_UNLCK"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_CHAR_FM_ABILITY_1_UNLCK"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_CHAR_FM_ABILITY_2_UNLCK"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_CHAR_FM_ABILITY_3_UNLCK"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_CHAR_FM_PACKAGE_1_COLLECT"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_CHAR_FM_PACKAGE_2_COLLECT"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_CHAR_FM_PACKAGE_3_COLLECT"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_CHAR_FM_PACKAGE_4_COLLECT"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_CHAR_FM_PACKAGE_5_COLLECT"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_CHAR_FM_PACKAGE_6_COLLECT"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_CHAR_FM_PACKAGE_7_COLLECT"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_CHAR_FM_PACKAGE_8_COLLECT"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_CHAR_FM_PACKAGE_9_COLLECT"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_CHAR_FM_HEALTH_1_UNLCK"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_CHAR_FM_HEALTH_2_UNLCK"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("HOLDUPS_BITSET"), -1, 0);
}
void UnlockAllWeaponCamos()
{
	drawNotification("~HUD_COLOUR_PINK~Weapon Camos ~g~Given!");
	STATS::STAT_SET_INT(get_hash_key("MP0_PISTOL_KILLS"), 600, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_CMBTPISTOL_KILLS"), 600, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_APPISTOL_KILLS"), 600, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_MICROSMG_KILLS"), 600, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_SMG_KILLS"), 600, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_ASLTSMG_KILLS"), 600, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_ASLTRIFLE_KILLS"), 600, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_CRBNRIFLE_KILLS"), 600, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_ADVRIFLE_KILLS"), 600, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_HVYSNIPER_KILLS"), 600, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_SNIPERRFL_KILLS"), 600, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_ASLTSHTGN_KILLS"), 600, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_PUMP_KILLS"), 600, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_GRNLAUNCH_KILLS"), 600, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_RPG_KILLS"), 600, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_MINIGUNS_KILLS"), 600, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_ASLTSMG_KILLS"), 600, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_ASLTRIFLE_KILLS"), 600, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_CRBNRIFLE_KILLS"), 600, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_ADVRIFLE_KILLS"), 600, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_HVYSNIPER_KILLS"), 600, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_SNIPERRFL_KILLS"), 600, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_MG_KILLS"), 600, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_CMBTMG_KILLS"), 600, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_PISTOL_ENEMY_KILLS"), 600, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_CMBTPISTOL_ENEMY_KILLS"), 600, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_APPISTOL_ENEMY_KILLS"), 600, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_MICROSMG_ENEMY_KILLS"), 600, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_SMG_ENEMY_KILLS"), 600, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_ASLTSMG_ENEMY_KILLS"), 600, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_ASLTRIFLE_ENEMY_KILLS"), 600, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_CRBNRIFLE_ENEMY_KILLS"), 600, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_ADVRIFLE_ENEMY_KILLS"), 600, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_HVYSNIPER_ENEMY_KILLS"), 600, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_SNIPERRFL_ENEMY_KILLS"), 600, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_ASLTSHTGN_ENEMY_KILLS"), 600, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_PUMP_ENEMY_KILLS"), 600, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_GRNLAUNCH_ENEMY_KILLS"), 600, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_RPG_ENEMY_KILLS"), 600, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_MINIGUNS_ENEMY_KILLS"), 600, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_ASLTSMG_ENEMY_KILLS"), 600, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_ASLTRIFLE_ENEMY_KILLS"), 600, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_CRBNRIFLE_ENEMY_KILLS"), 600, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_ADVRIFLE_ENEMY_KILLS"), 600, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_HVYSNIPER_ENEMY_KILLS"), 600, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_SNIPERRFL_ENEMY_KILLS"), 600, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_MG_ENEMY_KILLS"), 600, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_CMBTMG_ENEMY_KILLS"), 600, 0);
}
void BuyAllGuns()
{
	drawNotification("~HUD_COLOUR_PINK~All Weapons ~g~Given");
	STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_WEAPON_GV_BS_1"), -1, 1);
	STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_WEAPON_GV_BS_2"), -1, 1);
	STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_WEAPON_GV_BS_3"), -1, 1);
	STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_BOTTLE_IN_POSSESSION"), -1, 1);
	STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_UNLOCKED"), -1, 1);
	STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_UNLOCKED2"), -1, 1);
	STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_WEAP_FM_PURCHASE"), -1, 1);
	STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_WEAP_FM_PURCHASE2"), -1, 1);
	STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_ADDON_1_UNLCK"), -1, 1);
	STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_ADDON_2_UNLCK"), -1, 1);
	STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_ADDON_3_UNLCK"), -1, 1);
	STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_ADDON_4_UNLCK"), -1, 1);
	STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_ADDON_5_UNLCK"), -1, 1);
	STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_WEAP_FM_ADDON_PURCH"), -1, 1);
	STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_WEAP_FM_ADDON_PURCH2"), -1, 1);
	STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_WEAP_FM_ADDON_PURCH3"), -1, 1);
	STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_WEAP_FM_ADDON_PURCH4"), -1, 1);
	STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_WEAP_FM_ADDON_PURCH5"), -1, 1);
	STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_1_FM_UNLCK"), -1, 1);
	STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_2_FM_UNLCK"), -1, 1);
	STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_3_FM_UNLCK"), -1, 1);
	STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_4_FM_UNLCK"), -1, 1);
	STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_5_FM_UNLCK"), -1, 1);
	STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_6_FM_UNLCK"), -1, 1);
	STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_7_FM_UNLCK"), -1, 1);
	STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_8_FM_UNLCK"), -1, 1);
	STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_9_FM_UNLCK"), -1, 1);
	STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_10_FM_UNLCK"), -1, 1);
	STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_11_FM_UNLCK"), -1, 1);
	STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_12_FM_UNLCK"), -1, 1);
	STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE"), -1, 1);
	STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE2"), -1, 1);
	STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE3"), -1, 1);
	STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE4"), -1, 1);
	STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE5"), -1, 1);
	STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE6"), -1, 1);
	STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE7"), -1, 1);
	STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE8"), -1, 1);
	STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE9"), -1, 1);
	STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE10"), -1, 1);
	STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE11"), -1, 1);
	STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE12"), -1, 1);
}
void UnlimitedAmmo2()
{
	drawNotification("~HUD_COLOUR_PINK~Unlimited Ammo ~g~Given!");
	STATS::STAT_SET_INT(get_hash_key("MP1_GRNLAUNCH_FM_AMMO_BOUGHT"), 1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_GRNLAUNCH_FM_AMMO_CURRENT"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_RPG_FM_AMMO_BOUGHT"), 1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_RPG_FM_AMMO_CURRENT"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_MINIGUNS_FM_AMMO_BOUGHT"), 1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_MINIGUNS_FM_AMMO_CURRENT"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_STKYBMB_FM_AMMO_BOUGHT"), 1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_STKYBMB_FM_AMMO_CURRENT"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_SMKGRENADE_FM_AMMO_BOUGHT"), 1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_SMKGRENADE_FM_AMMO_CURRENT"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_GRENADE_FM_AMMO_BOUGHT"), 1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_GRENADE_FM_AMMO_CURRENT"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_PRXMINE_FM_AMMO_BOUGHT"), 1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_PRXMINE_FM_AMMO_CURRENT"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_HOMLNCH_FM_AMMO_BOUGHT"), 1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_HOMLNCH_FM_AMMO_CURRENT"), -1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_FLAREGUN_FM_AMMO_BOUGHT"), 1, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_FLAREGUN_FM_AMMO_CURRENT"), -1, 0);
}
void alltrophies()
{
	drawNotification("~HUD_COLOUR_PINK~Unlocking All Trophies ~g~Given!");
	SET_STAT_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_REPORT_STRENGTH"), 128);
	SET_STAT_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_COMMEND_STRENGTH"), 128);
	SET_STAT_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_FRIENDLY"), 128);
	SET_STAT_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_HELPFUL"), 128);
	SET_STAT_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_GRIEFING"), 0);
	SET_STAT_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_VC_ANNOYINGME"), 0);
	SET_STAT_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_VC_HATE"), 0);
	SET_STAT_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_OFFENSIVE_LANGUAGE"), 0);
	SET_STAT_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_OFFENSIVE_TAGPLATE"), 0);
	SET_STAT_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_OFFENSIVE_UGC"), 0);
	SET_STAT_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_BAD_CREW_NAME"), 0);
	SET_STAT_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_BAD_CREW_MOTTO"), 0);
	SET_STAT_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_BAD_CREW_STATUS"), 0);
	SET_STAT_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_BAD_CREW_EMBLEM"), 0);
	SET_STAT_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_GAME_EXPLOITS"), 0);
	SET_STAT_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_EXPLOITS"), 0);
	SET_STAT_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_ISPUNISHED"), 0);
}
//Money Menu
int deductAmount = 1;
void deductMoney() {
	NETWORKCASH::NETWORK_BUY_AIRSTRIKE(deductAmount, 0, 1);
}
int moneyAmount = 100;

void giveMoney(int amount) {
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(amount);
}
void Cash1Million()
{
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(1000000);
}
void Cash5Million()
{
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(5000000);
}
void Cash10Million()
{
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
}
void Cash30Million()
{
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(30000000);
}
void Cash60Million()
{
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(60000000);
}
void Cash90Million()
{
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(90000000);
}
void Cash100Million()
{
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(100000000);
}
void Cash1Million1()
{
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(1000000);
}
void Cash5Million1()
{
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(5000000);
}
//Rank menu??
void Rank8000()
{
	drawNotification("~HUD_COLOUR_PINK~Rank 8000 ~g~Given!");
	STAT_SET_INT1(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_XP_FM"), 1787576850);
}
void Rank999()
{
	drawNotification("~HUD_COLOUR_PINK~Rank 999 ~g~Given!");
	STAT_SET_INT1(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_XP_FM"), 47478300);
}
void Rank400()
{
	drawNotification("~HUD_COLOUR_PINK~Rank 400 ~g~Given!");
	STAT_SET_INT1(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_XP_FM"), 12406850);
}
void Rank1337()
{
	drawNotification("~HUD_COLOUR_PINK~Rank 1337 ~g~Given!");
	STAT_SET_INT1(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_XP_FM"), 75185850);
}
void Rank900()
{
	drawNotification("~HUD_COLOUR_PINK~Rank 900 ~g~Given!");
	STAT_SET_INT1(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_XP_FM"), 40444350);
}
void Rank1()
{
	drawNotification("~HUD_COLOUR_PINK~Rank 1 ~g~Given!");
	STAT_SET_INT1(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_XP_FM"), 0);
}
void Rank120()
{
	drawNotification("~HUD_COLOUR_PINK~Rank 120 ~g~Given!");
	STAT_SET_INT1(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_XP_FM"), 2165850);
}
void Rank1202()
{
	drawNotification("~HUD_COLOUR_PINK~Rank 1202 ~g~Given!");
	STAT_SET_INT1(GAMEPLAY::GET_HASH_KEY("MP1_CHAR_XP_FM"), 2165850);//Custom Native STAT_SET_INT1 Definition is above
}
//Misc Menu
void Snacks2()
{
	drawNotification("~HUD_COLOUR_PINK~Max Snacks ~g~Given!");
	STATS::STAT_SET_INT(get_hash_key("MP1_NO_BOUGHT_YUM_SNACKS"), 99999999, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_NO_BOUGHT_HEALTH_SNACKS"), 99999999, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_NO_BOUGHT_EPIC_SNACKS"), 99999999, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_CIGARETTES_BOUGHT"), 99999999, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_NUMBER_OF_ORANGE_BOUGHT"), 99999999, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_NUMBER_OF_BOURGE_BOUGHT"), 99999999, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_FIREWORK_TYPE_1_WHITE"), 999999, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_FIREWORK_TYPE_2_WHITE"), 999999, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_FIREWORK_TYPE_3_WHITE"), 999999, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_FIREWORK_TYPE_4_WHITE"), 999999, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_FIREWORK_TYPE_1_RED"), 999999, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_FIREWORK_TYPE_2_RED"), 999999, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_FIREWORK_TYPE_3_RED"), 999999, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_FIREWORK_TYPE_4_RED"), 999999, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_FIREWORK_TYPE_1_BLUE"), 999999, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_FIREWORK_TYPE_2_BLUE"), 999999, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_FIREWORK_TYPE_3_BLUE"), 999999, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_FIREWORK_TYPE_4_BLUE"), 999999, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_MP_CHAR_ARMOUR_1_COUNT"), 9999, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_MP_CHAR_ARMOUR_1_COUNT"), 9999, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_MP_CHAR_ARMOUR_1_COUNT"), 9999, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_MP_CHAR_ARMOUR_1_COUNT"), 9999, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_MP_CHAR_ARMOUR_1_COUNT"), 9999, 0);
	drawNotification("~HUD_COLOUR_PINK~Snacks Given ~r~Finished");
}
void ClearReports2()
{
	drawNotification("~HUD_COLOUR_PINK~Clear Reports ~g~Given!");
	STATS::STAT_SET_INT(get_hash_key("MP1_TIMES_CHEATED"), 0, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_MPPLY_EXPLOITS"), 0, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_MPPLY_GAME_EXPLOITS"), 0, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_MPPLY_COMMEND_STRENGTH"), 100, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_MPPLY_FRIENDLY"), 100, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_MPPLY_HELPFUL"), 100, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_MPPLY_OFFENSIVE_LANGUAGE"), 0, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_MPPLY_VC_HATE"), 0, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_MPPLY_VC_ANNOYINGME"), 0, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_MPPLY_RACE_CHEAT_TALLY"), 0, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_MPPLY_GRIEFING"), 0, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_MPPLY_LTS_CHEAT_TALLY"), 0, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_MPPLY_SUR_CHEAT_TALLY"), 0, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_MPPLY_CAP_CHEAT_TALLY"), 0, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_SCADMIN_IS_CHEATER"), 0, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_MPPLY_MC_CHEAT_TALLY"), 0, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_MPPLY_RACE_CHEAT_TALLY"), 0, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_MPPLY_DM_CHEAT_TALLY"), 0, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_MPPLY_BECAME_CHEATER_NUM"), 0, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_MPPLY_OVERALL_CHEAT"), 0, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_MPPLY_WAS_I_CHEATER"), 0, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_CHEAT_BITSET"), 0, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_BAD_SPORT_BITSET"), 0, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_MPPLY_WAS_I_BAD_SPORT"), 0, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_MPPLY_OVERALL_BADSPORT"), 0, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_MPPLY_CHAR_IS_BADSPORT"), 0, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_MPPLY_BECAME_BADSPORT_NUM"), 0, 0);
	STATS::STAT_SET_INT(get_hash_key("MP1_MPPLY_DESTROYED_PVEHICLES"), 0, 0);
}
void HeistTrophies()
{
	drawNotification("~HUD_COLOUR_PINK~Unlocking Heist Trophies ~g~Given!");
	STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_HEIST _ACH_TRACKER"), -1, 0);
}
void RemoveBS()
{
	drawNotification("~HUD_COLOUR_PINK~Remove Bad Sport ~g~Given!");
	STATS::STAT_SET_INT(get_hash_key("MP0_BAD_SPORT_BITSET"), 0, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_MPPLY_WAS_I_BAD_SPORT"), 0, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_MPPLY_OVERALL_BADSPORT"), 0, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_MPPLY_CHAR_IS_BADSPORT"), 0, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_MPPLY_BECAME_BADSPORT_NUM"), 0, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_MPPLY_DESTROYED_PVEHICLES"), 0, 0);
}
void Fireworks()
{
	drawNotification("~HUD_COLOUR_PINK~Fireworks ~g~Given!");
	STATS::STAT_SET_INT(get_hash_key("MP0_FIREWORK_TYPE_1_WHITE"), 999999, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_FIREWORK_TYPE_2_WHITE"), 999999, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_FIREWORK_TYPE_3_WHITE"), 999999, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_FIREWORK_TYPE_4_WHITE"), 999999, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_FIREWORK_TYPE_1_RED"), 999999, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_FIREWORK_TYPE_2_RED"), 999999, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_FIREWORK_TYPE_3_RED"), 999999, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_FIREWORK_TYPE_4_RED"), 999999, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_FIREWORK_TYPE_1_BLUE"), 999999, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_FIREWORK_TYPE_2_BLUE"), 999999, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_FIREWORK_TYPE_3_BLUE"), 999999, 0);
	STATS::STAT_SET_INT(get_hash_key("MP0_FIREWORK_TYPE_4_BLUE"), 999999, 0);
}
//Change Appearance Code
int fam;
void changeAppearance(char* family, int model, int texture)
{
	if (cstrcmp(family, "HATS") || cstrcmp(family, "GLASSES") || cstrcmp(family, "EARS"))
	{
		if (cstrcmp(family, "HATS"))
			fam = 0;
		else if (cstrcmp(family, "GLASSES"))
			fam = 1;
		else if (cstrcmp(family, "EARS"))
			fam = 2;
		PED::SET_PED_PROP_INDEX1(PLAYER::PLAYER_PED_ID(), fam, model - 1, texture);
	}
	else
	{
		if (cstrcmp(family, "FACE"))
			fam = 0;
		else if (cstrcmp(family, "MASK"))
			fam = 1;
		else if (cstrcmp(family, "HAIR"))
			fam = 2;
		else if (cstrcmp(family, "TORSO"))
			fam = 3;
		else if (cstrcmp(family, "LEGS"))
			fam = 4;
		else if (cstrcmp(family, "HANDS"))
			fam = 5;
		else if (cstrcmp(family, "SHOES"))
			fam = 6;
		else if (cstrcmp(family, "SPECIAL1"))
			fam = 7;
		else if (cstrcmp(family, "SPECIAL2"))
			fam = 8;
		else if (cstrcmp(family, "SPECIAL3"))
			fam = 9;
		else if (cstrcmp(family, "TEXTURE"))
			fam = 10;
		else if (cstrcmp(family, "TORSO2"))
			fam = 11;
		PED::SET_PED_COMPONENT_VARIATION1(PLAYER::PLAYER_PED_ID(), fam, model, texture);
	}
}



void ResetAppearance()
{
	PED::CLEAR_ALL_PED_PROPS(PLAYER::PLAYER_PED_ID());
	PED::CLEAR_PED_DECORATIONS(PLAYER::PLAYER_PED_ID());
	PED::SET_PED_COMPONENT_VARIATION1(PLAYER::PLAYER_PED_ID(), 1, 0, 0);
	PED::SET_PED_COMPONENT_VARIATION1(PLAYER::PLAYER_PED_ID(), 5, 0, 0);
	PED::SET_PED_COMPONENT_VARIATION1(PLAYER::PLAYER_PED_ID(), 9, 0, 0);
}
#pragma endregion
#pragma region Player Stats
opd_s NETWORK_HANDLE_FROM_PLAYER_FUNC_t = { 0x47E00C, TOC };
static char* _GET_TEXT_SUBSTRING(char *text, int position, int length) { return invoke<char*>(0x34A396EE, text, position, length); } // 0x34A396EE
unsigned int(*NETWORK_HANDLE_FROM_PLAYER_FUNC)(unsigned int a_uiRecevPlayerIndex, int valuePointer) = (unsigned int(*)(unsigned int, int))&NETWORK_HANDLE_FROM_PLAYER_FUNC_t;

opd_s NETWORK_INCREMENT_STATS_t = { 0x12D141C, TOC };
void(*NETWORK_INCREMENT_STATS)(int stats, int value, unsigned int a_uiRecevPlayerIndex) = (void(*)(int, int, unsigned int))&NETWORK_INCREMENT_STATS_t;

unsigned int NETWORK_HANDLE_FROM_PLAYER(unsigned int PlayerIndex)
{
	return NETWORK_HANDLE_FROM_PLAYER_FUNC(PlayerIndex, 1);
}
void SetPlayerStats(unsigned int a_uiRecevPlayerIndex, char *Stat_Index, float Value_Index)
{
	if (strcmp(_GET_TEXT_SUBSTRING(Stat_Index, 0, 5), "MPPLY") == 0)
	{
		NETWORK_INCREMENT_STATS(GAMEPLAY::GET_HASH_KEY(Stat_Index), Value_Index, NETWORK_HANDLE_FROM_PLAYER(a_uiRecevPlayerIndex));
	}
	else
	{
		char debug[500];
		snprintf(debug, sizeof(debug), "MP%i%s", 0, Stat_Index);
		snprintf(debug, sizeof(debug), "MP%i%s", 1, Stat_Index);
		NETWORK_INCREMENT_STATS(GAMEPLAY::GET_HASH_KEY(debug), Value_Index, NETWORK_HANDLE_FROM_PLAYER(a_uiRecevPlayerIndex));
	}

}
#pragma endregion
#pragma region Deposit 
bool deposit = false;
void direct_deposit() {
	int Args6[5];
	Args6[0] = 219;//0xDB  
	Args6[1] = 40;
	Args6[2] = 100000000000;
	Args6[3] = -1;
	Args6[4] = 1;
	TriggerScriptEvent(Args6, 5, selectedPlayer);
}
//Direct Deposit Freeze Thanks to Pro(::
bool depositfreeze = false;
void givePlayerMoney(int player, int amount) {//refunds to themself. max 20k
	for (int i = 16; i < amount / 20000 + 16; i++) {
		ScriptArg args[4];
		args[0].i = 219;//0xDA = 218;
		args[1].i = i;//player;//cash giver (them cuz they refund themself)
		args[2].i = 20000;//46
		args[3].i = 1;
		unsigned int bits = (1 << player);//0xFFFFFFFF;
		PlayerMods::eventCreator::callScriptEvent(args, 4, bits);
	}
}

#pragma endregion
#pragma region IP Stuff
opd_s GET_TIME_SINCE_LAST_ARREST_t = { 0x424DCC, TOC };
int GlobalToAddress(int Global, int imm) {
	return (int)(GLOBALPTR + ((Global & 0xFFFFFF) >> 16 & 0xFFFC) + (imm * 4));
}
void WriteGlobal(int Global, int imm, int Value) {
	*(int*)(GlobalToAddress(Global, imm)) = Value;
}
int ReadGlobal(int Global, int imm) {
	return *(int*)(GlobalToAddress(Global, imm));
}
int Read_Global(int a_uiGlobalID) {
	int Ptr = *(int*)((TunablePointer - 0x04) + (((a_uiGlobalID / 0x40000) & 0x3F) * 4));
	if (Ptr != 0)return *(int*)(Ptr + ((a_uiGlobalID % 0x40000) * 4)); return 0;
}
int getPlayerStat(int player, int stat) {
	return Read_Global(1581767 + (player * 306) + stat);
}
int getPlayerRank(int player) {
	return getPlayerStat(player, 185);
}
int getPlayerCash(int player) {
	return getPlayerStat(player, 182);
}
void playerstuff(bool isSelected) {
	if (strcmp(GET_THIS_SCRIPT_NAME(), "ingamehud") == 0) {
		for (int i = 1; i < 17; i++) {
			if (i % 2) {
			}
			else {
			}
		}
	}
	Player ui_slectedPlayer = selectedPlayer;
	Player ui_currentPlayer = currentOption - 1;
	Player OnlinePlayer = PLAYER::GET_PLAYER_PED(isSelected ? ui_slectedPlayer : ui_currentPlayer);
	Vector3 Coords = ENTITY::GET_ENTITY_COORDS(OnlinePlayer, 1);
	char Cash[50], Rank[50], IPADDR[50];
	sprintf(Cash, "~HUD_COLOUR_GREEN~$ ~HUD_COLOUR_GREEN~%i", getPlayerCash(isSelected ? ui_slectedPlayer : ui_currentPlayer));
	sprintf(Rank, "Lvl ~HUD_COLOUR_GREEN~%i", getPlayerRank(isSelected ? ui_slectedPlayer : ui_currentPlayer));

	drawText("Wallet", 4, 0.225f, 0.6f, 0, .52, MenuColour_R, MenuColour_G, MenuColour_B, 255, 0);
	drawText(Cash, 4, 0.225f, .63, 0, .52, 255, 255, 255, 255, .0);

	drawText("Rank", 4, 0.225f, .66, 0, .52, MenuColour_R, MenuColour_G, MenuColour_B, 255, .0);
	drawText(Rank, 4, 0.225f, .69, 0, .52, 255, 255, 255, 255, .0);

	drawText("IP Address", 4, 0.225f, .72, 0, .52, MenuColour_R, MenuColour_G, MenuColour_B, 255, 0);
	drawText("Internal IP", 4, 0.225f, .78, 0, .52, MenuColour_R, MenuColour_G, MenuColour_B, 255, 0);
	drawText("Port", 4, 0.225f, .84, .84, .52, MenuColour_R, MenuColour_G, MenuColour_B, 255, 0);

	char IPADDR1[4][50];
	char RegionBuffer[2][10];
	for (int i = 0; i < 34; i++) {
		int Handle[13];
		NETWORK_HANDLE_FROM_PLAYER2(isSelected ? ui_slectedPlayer : ui_currentPlayer, &Handle[0], 13);
		char *RealName = NETWORK_GET_GAMERTAG_FROM_HANDLE(&Handle[0]);
		char *ipName = ReadBytes(0x40025C80 + (i * 136), 100);
		if (!strcmp(RealName, ipName)) {
			int ip = *(int *)(0x40025CC8 + (i * 0x88));
			int p1 = (ip & 0xff000000) >> 24;
			int p2 = (ip & 0x00ff0000) >> 16;
			int p3 = (ip & 0x0000ff00) >> 8;
			int p4 = (ip & 0x000000ff) >> 0;

			int internal_ip = *(int *)(0x40025CA8 + (i * 0x88));
			int p5 = (internal_ip & 0xff000000) >> 24;
			int p6 = (internal_ip & 0x00ff0000) >> 16;
			int p7 = (internal_ip & 0x0000ff00) >> 8;
			int p8 = (internal_ip & 0x000000ff) >> 0;

			char *Region = ReadBytes(0x40025c96 + (i * 0x88), 100);

			int port = *(int*)(0x40025ccd + (i * 0x88));
			int p9 = (port & 0xff000000) >> 24;
			int p10 = (port & 0x00ff0000) >> 16;
			int portToShow = (p9 << 8) | p10;

			sprintf(IPADDR1[0], "~HUD_COLOUR_GREEN~%i.%i.%i.%i", p1, p2, p3, p4);
			sprintf(IPADDR1[1], "~HUD_COLOUR_GREEN~%i.%i.%i.%i", p5, p6, p7, p8);
			sprintf(IPADDR1[2], "~HUD_COLOUR_GREEN~%s", Region);
			sprintf(IPADDR1[3], "~HUD_COLOUR_GREEN~%i", portToShow);

			if (strstr(IPADDR1[0], "255.255.255.255") == NULL && strstr(IPADDR1[0], "0.0.0.0") == NULL) {
				strcpy(RegionBuffer[0], IPADDR1[2]);
				memcpy(RegionBuffer[1], RegionBuffer[0], strlen(RegionBuffer[0]) - 3);

				drawText(IPADDR1[0], 4, 0.225f, .75, 0, .52, 255, 255, 255, 255, .0);//ip
				drawText(IPADDR1[1], 4, 0.225f, .81, 0, .52, 255, 255, 255, 255, .0);//internal ip
				drawText(IPADDR1[3], 4, 0.225f, .87, 0, .52, 255, 255, 255, 255, .0);//port
			}
			else {
				drawText(IPADDR1[0], 4, 0.225f, .75, 0, .52, 255, 255, 255, 255, .0);//ip
				drawText(IPADDR1[1], 4, 0.225f, .81, 0, .52, 255, 255, 255, 255, .0);//internal ip
				drawText(IPADDR1[3], 4, 0.225f, .87, 0, .52, 255, 255, 255, 255, .0);//port
			}
		}
	}
}
#pragma endregion
#pragma region text message
void sendText1(int player, char *text, int font) {
	if (player == PLAYER::PLAYER_ID()) {
		UI::SET_TEXT_FONT(font);
		UI::BEGIN_TEXT_COMMAND_THEFEED_POST("STRING");
		_ADD_TEXT_COMPONENT_STRING(text);
		UI::_SET_NOTIFICATION_MESSAGE_1("~CHAR_AMANDA~", "CHAR_AMANDA", true, 4, "", "");
	}
	else {
		int NetHandleBuffer = 0x10070200;
		NETWORK_HANDLE_FROM_PLAYER(player, NetHandleBuffer, 13);
		NETWORK_SEND_TEXT_MESSAGE(text, NetHandleBuffer);
	}
}
void sendText(int player, char *text, int font) {
	if (player == PLAYER::PLAYER_ID()) {
		UI::SET_TEXT_FONT(font);
		UI::BEGIN_TEXT_COMMAND_THEFEED_POST("STRING");
		_ADD_TEXT_COMPONENT_STRING(text);
		UI::_DRAW_NOTIFICATION(false, true);
	}
	else {
		int NetHandleBuffer = 0x10070200;
		NETWORK_HANDLE_FROM_PLAYER(player, NetHandleBuffer, 13);
		NETWORK_SEND_TEXT_MESSAGE(text, NetHandleBuffer);
	}
}
#pragma endregion
#pragma region model menu 
char* ModelString;
bool bool_outfit[50];
int 
PedVar,
ScenariosVar, 
AnimalVar,
Ped2Var;

char *PedsChar[] = { "Cop 1","Pogo","Alien","Zombie","Topless Chick","Body Builder","Impotant Rage","Paparazzi","Hiker","Breakdancer","Cletus","OG","Mayweather","Prologue Driver","Mexican Gangster","Chris","Clay","Officer","Mechanic","Security Officer","Detective","FBI Agent","Pilot","Scientist","Blackops","Fireman","Highway Cop","Marine","Inmate","Swat","Secret Service","Jewel Thief","Party Target","Clown","Tattoo Artist","Player 0","Player 2","Lester", "Agent","Old Man 1","Old Man 2", "Nude","Nude 2","Nude 3" };
char *PedsCharhash[] = { "s_m_y_cop_01","u_m_y_pogo_01","s_m_m_movalien_01","u_m_y_zombie_01","a_f_y_topless_01","u_m_y_babyd","u_m_y_imporage","a_m_m_paparazzi_01","a_m_y_beach_02","a_m_y_breakdance_01","csb_cletus","csb_g","csb_mweather","csb_prologuedriver","g_m_y_mexgoon_03","ig_chrisformage","ig_claypain","s_m_m_armoured_01","s_m_m_autoshop_01","s_m_m_chemsec_01","s_m_m_ciasec_01","s_m_m_fiboffice_01","s_m_m_pilot_01","s_m_m_scientist_01","s_m_y_blackops_01","s_m_y_fireman_01","s_m_y_hwaycop_01","s_m_y_marine_01","s_m_y_prismuscl_01","s_m_y_swat_01","u_m_m_jewelsec_01","u_m_m_jewelthief","u_m_m_partytarget","S_M_Y_Clown_01","u_m_y_tattoo_01","player_zero","player_two","ig_lestercrest","ig_agent","ig_old_man1a","ig_old_man2", "a_m_y_acult_01","a_m_y_acult_02","a_m_y_acult_02_p" };
char *ScenariosMenu[] = { "Play Music","Take Photos","Use Binoculars","Drink Coffee","Play Golf","Lift Weights","Bench Press","Chin Ups","Smoke Weed","Be Handyman","Do Yoga","Flex Muscles","Clipboard","BBQ","Fishing","Security","Leaf Blower","Idle Cop","Welding","Jack Hammering" };
char *ScenariosChar[20] = { "WORLD_HUMAN_MUSICIAN","WORLD_HUMAN_PAPARAZZI","WORLD_HUMAN_BINOCULARS","WORLD_HUMAN_DRINKING","WORLD_HUMAN_GOLF_PLAYER","WORLD_HUMAN_MUSCLE_FREE_WEIGHTS","PROP_HUMAN_SEAT_MUSCLE_BENCH_PRESS","PROP_HUMAN_MUSCLE_CHIN_UPS","WORLD_HUMAN_SMOKING_POT","WORLD_HUMAN_HAMMERING","WORLD_HUMAN_YOGA", "WORLD_HUMAN_MUSCLE_FLEX","WORLD_HUMAN_CLIPBOARD","PROP_HUMAN_BBQ","WORLD_HUMAN_STAND_FISHING","WORLD_HUMAN_SECURITY_SHINE_TORCH","WORLD_HUMAN_GARDENER_LEAF_BLOWER","WORLD_HUMAN_COP_IDLES","WORLD_HUMAN_WELDING","WORLD_HUMAN_HAMMERING" };
char *ScenarioDict = "amb@lo_res_idles";
#pragma endregion
#pragma region more_boringness
void ResetPlayerView(int player) {
	ScriptArg args[3];
	args[0].i = 0x2;
	args[1].i = selectedPlayer;
	args[2].i = 0x2e;//46
	unsigned int bits = (1 << selectedPlayer);
	PlayerMods::eventCreator::callScriptEvent(args, 3, bits);
}
void TeleportToClient(int Client) {
	Vector3 Coords = ENTITY::GET_ENTITY_COORDS(Client, 1);
	if (PED::IS_PED_SITTING_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID()))
		ENTITY::SET_ENTITY_COORDS(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), Coords.x, Coords.y, Coords.z, 1, 0, 0, 1);
	else ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), Coords.x, Coords.y, Coords.z, 1, 0, 0, 1);
}
void teleportplayerfoot(int playerid, char* anim, char* animid, float X, float Y, float Z) {
	AI::CLEAR_PED_TASKS_IMMEDIATELY(playerid);
	Vector3 pedpos = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(playerid, 0.0f, 0.0f, 0.0f);
	int scene2 = NETWORK_CREATE_SYNCHRONISED_SCENE_3(X, Y, Z, 0.0, 0.0, 0.0, 2, 0, 0, 0, 0, 0);
	NETWORK_ADD_PED_TO_SYNCHRONISED_SCENE_3(playerid, scene2, anim, animid, 8.0f, -8.0, 5, 0, 30, 0);
	NETWORK::NETWORK_START_SYNCHRONISED_SCENE(scene2);
}

#pragma endregion
#pragma region Special Creative shit
#pragma region boat ride
Object AddRope(Vector3 pos, Vector3 rot, int type, float length, bool breakable)
{
	return ROPE::ADD_ROPE(pos.x, pos.y, pos.z, rot.x, rot.y, rot.z, length, type, length, 0.5f, 0.5f, false, false, true, 1.0f, breakable, 0);
}
void AttacRopehEntities(int rope, int ent1, int ent2, Vector3 pos1, Vector3 pos2, float length)
{
	ROPE::ATTACH_ENTITIES_TO_ROPE(rope, ent1, ent2, pos1.x, pos1.y, pos1.z, pos2.x, pos2.y, pos2.z, length, 0, 0, 0, 0);
}
void DrawLine(Vector3 start, Vector3 end, int R, int G, int B, int A)
{
	GRAPHICS::DRAW_LINE(start.x, start.y, start.z, end.x, end.y, end.z, R, G, B, A);
}

//Tropic Speed boat with a tow rope and a floating inner tube , that we can later place a player on.. Zombie mod comes later (;
Vehicle trop_boat;
Object inner_tube;
bool create_boat = 0, toggle_boat_ride = 0;
int players_list_index = 0;

bool TropicBoat()//RouletteBoi's doing
{
	//Player rider = something(PLAYER::GET_PLAYER_PED(players_list_index));
	if (create_boat)
	{
		Hash hash = 0x1149422F;
		Hash pool_inner = 0x63F9CEA3;
		if (!STREAMING::HAS_MODEL_LOADED(hash))
		{
			STREAMING::REQUEST_MODEL(hash);
		}
		else
		{
			Vector3 coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0f, 0.0f, 0.0f);
			trop_boat = VEHICLE::CREATE_VEHICLE(hash, coords.x, coords.y, coords.z, 0.0f, 1, 0);
			if (ENTITY::DOES_ENTITY_EXIST(trop_boat))
			{
				PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), trop_boat, -1);
				coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0f, -5.0f, 0.0f);
				inner_tube = OBJECT::CREATE_OBJECT(pool_inner, coords.x, coords.y, coords.z, 1, 1, 1);
				Vector3 boat_pos = ENTITY::GET_ENTITY_COORDS(trop_boat, 1);
				Vector3 inner_pos = ENTITY::GET_ENTITY_COORDS(inner_tube, 1);
				float dist = GetVectorDistance(inner_pos, boat_pos);
				Object rope = AddRope(boat_pos, new_Vector3(0.0f, 0.0f, 0.0f), 4, dist, 0);

				//if (ENTITY::DOES_ENTITY_EXIST(inner_tube))
				//{
					//ATTACH_ENTITY_TO_ENTITY_PHYSICALLY(trop_boat, inner_tube, 0, 0, 0.0, 15, 0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0f, true, true, true, false, 2);
					//std::debug_log("tube exist\n");
				//}


				if (ROPE::DOES_ROPE_EXIST(&rope))
				{
					ROPE::ROPE_LOAD_TEXTURES();
					ROPE::ACTIVATE_PHYSICS(rope);
					AttacRopehEntities(rope, trop_boat, inner_tube, inner_pos, boat_pos, dist);
					ROPE::PIN_ROPE_VERTEX(rope, 0, inner_pos.x, inner_pos.y, inner_pos.z);
					ROPE::PIN_ROPE_VERTEX(rope, ROPE::GET_ROPE_VERTEX_COUNT(rope) - 1, boat_pos.x, boat_pos.y, boat_pos.z);
				}
				//attach player code here:
				create_boat = 0;
			}
		}
	}

	if (ENTITY::DOES_ENTITY_EXIST(trop_boat) && !create_boat)
	{
		//attach player code here:
	}


}
bool tube;
bool Tube()
{
	uint Handle = PLAYER::PLAYER_PED_ID();
	Vector3 c = ENTITY::GET_ENTITY_COORDS(Handle, 1);
	int hash = 0x1149422F;
	int hash2 = 0x63F9CEA3;
	STREAMING::REQUEST_MODEL(hash);
	STREAMING::REQUEST_MODEL(hash2);
	if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
	{
		int Object = OBJECT::CREATE_OBJECT(hash2, 0, 0, 0, 1, 1, 1);
		if (ENTITY::DOES_ENTITY_EXIST(Object))
		{
			int Vehicle = VEHICLE::CREATE_VEHICLE(hash, c.x, c.y, c.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
			if (ENTITY::DOES_ENTITY_EXIST(Vehicle))
			{
				PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
				ATTACH_ENTITY_TO_ENTITY_PHYSICALLY(Object, Vehicle, 0, 0, 0.0, -15.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0f, 0, 1, 0, 0, 2);
				ENTITY::SET_ENTITY_VISIBLE(Handle, 1);
				return true;
			}
			return false;
		}
		return false;
	}
	return false;
}
#pragma endregion
#pragma region RealCarMod


bool RealCarModBool = false; 

float gasx = 0.18; //set to 0 if safezone is at 100 %
float gasy = 0.91;

//refuel key(for jerry can)
int refuelKey = 24; //key.L

int GUI_time = 0;
Vector3 gasStations[] = {
	{ -724, -935, 30 },
	{ -71, -1762, 30 },
	{ 265, -1261, 30 },
	{ 819, -1027, 30 },
	{ -2097, -320, 30 },
	{ 1212, 2657, 30 },
	{ 2683, 3264, 30 },
	{ -2555, 2334, 30 },
	{ 180, 6603, 30 },
	{ 2581, 362, 30 },
	{ 1702, 6418, 30 },
	{ -1799, 803, 30 },
	{ -90, 6415, 30 },
	{ 264, 2609, 30 },
	{ 50, 2776, 30 },
	{ 2537, 2593, 30 },
	{ 1182, -330, 30 },
	{ -526, -1212, 30 },
	{ 1209, -1402, 30 },
	{ 2005, 3775, 30 },
	{ 621, 269, 30 },
	{ -1434, -274, 30 },
	{ 1687, 4929, 30 }
};


float gasw = 0.3;
float gash = 0.009;
bool refillCar = false;
bool lowFuel = false;
bool drawHint = false;
bool drawHintB = false;
bool hasfuel = false;
int gradientRed = 0;
int gradientGreen = 255;
int gradientBlue = 255;
int gradientOpacity = 180;
//Full Fuel Bar Color
int FuelFullBarRed = 246;
int FuelFullBarGreen = 154;
int FuelFullBarBlue = 80;
int FuelFullBarOpacity = 255;
//Emptying Bar Second Layer
int FuelseclayerR = 255;
int FuelseclayerG = 0;
int FuelseclayerB = 0;


int blip[100];

struct fuel_mod
{
	int pointer;
	float fuel;
};

int cars_count = 0;
fuel_mod cars2[11]; // 11

				   //char *dict = "misscarsteal2peeing";
				   //char *anim = "peeing_loop";

void GUI_drawText()
{
	if (hasfuel)
	{
		if (drawHint)
		{
			UI::SET_TEXT_FONT(0);
			UI::SET_TEXT_PROPORTIONAL(1);
			UI::SET_TEXT_SCALE(0.0, 0.35);
			UI::SET_TEXT_COLOUR(255, 255, 255, 255);
			UI::SET_TEXT_DROPSHADOW(0, 0, 0, 0, 255);
			UI::SET_TEXT_EDGE(1, 0, 0, 0, 255);
			UI::SET_TEXT_DROP_SHADOW();
			UI::SET_TEXT_OUTLINE();
			UI::_SET_TEXT_ENTRY("STRING");
			_ADD_TEXT_COMPONENT_STRING("HOLD RIGHT TO REFILL VEHICLE WITH JERRY CAN!");
			UI::_DRAW_TEXT(0.015, 0.015);
			GRAPHICS::DRAW_RECT(gasx + 0.07, gasy, 0.14, gash, 0, 0, 0, 60);
			GRAPHICS::DRAW_RECT(gasx + (cars2[1].fuel / 2), gasy, cars2[1].fuel, gash, 156, 181, 42, 255);
		}
		else if (drawHintB)
		{
			UI::SET_TEXT_FONT(0);
			UI::SET_TEXT_PROPORTIONAL(1);
			UI::SET_TEXT_SCALE(0.0, 0.35);
			UI::SET_TEXT_COLOUR(255, 255, 255, 255);
			UI::SET_TEXT_DROPSHADOW(0, 0, 0, 0, 255);
			UI::SET_TEXT_EDGE(1, 0, 0, 0, 255);
			UI::SET_TEXT_DROP_SHADOW();
			UI::SET_TEXT_OUTLINE();
			UI::_SET_TEXT_ENTRY("STRING");
			UI::_ADD_TEXT_COMPONENT_STRING("PRESS L3 TO BEGIN REFUELING!");
			UI::_DRAW_TEXT(0.015, 0.015);
		}
	}
}
void GUI_renderGUI()
{
	GRAPHICS::DRAW_RECT(gasx + 0.07, gasy, 0.14, gash + 0.01, 0, 0, 0, 255);//--bar bg 1
	GRAPHICS::DRAW_RECT(gasx + 0.07, gasy, 0.14, gash, FuelseclayerR, FuelseclayerG, FuelseclayerB, 195);//second Bar

	if (cars2[1].fuel == 0)
	{
		UI::SET_TEXT_FONT(0);
		UI::SET_TEXT_PROPORTIONAL(1);
		UI::SET_TEXT_SCALE(0.0, 0.32);
		UI::SET_TEXT_COLOUR(255, 0, 0, 255);//~R~
		UI::SET_TEXT_DROP_SHADOW();
		UI::_SET_TEXT_ENTRY("STRING");
		UI::_ADD_TEXT_COMPONENT_STRING("OUT OF FUEL");
		UI::_DRAW_TEXT(gasx + 0.028, gasy - 0.03);
	}
	else if (cars2[1].fuel <= 25)
	{
		UI::SET_TEXT_FONT(0);
		UI::SET_TEXT_PROPORTIONAL(1);
		UI::SET_TEXT_SCALE(0.0, 0.32);
		UI::SET_TEXT_COLOUR(255, 255, 0, 255);//~y~
		UI::SET_TEXT_DROP_SHADOW();
		UI::_SET_TEXT_ENTRY("STRING");
		UI::_ADD_TEXT_COMPONENT_STRING("REFILL FUEL SOON");
		UI::_DRAW_TEXT(gasx + 0.028, gasy - 0.03);
	}
	else
	{
		UI::SET_TEXT_FONT(0);
		UI::SET_TEXT_PROPORTIONAL(1);
		UI::SET_TEXT_SCALE(0.0, 0.32);
		UI::SET_TEXT_COLOUR(0, 255, 0, 255);//~g~
		UI::SET_TEXT_DROP_SHADOW();
		UI::_SET_TEXT_ENTRY("STRING");
		UI::_ADD_TEXT_COMPONENT_STRING("FUEL LEVEL GOOD");
		UI::_DRAW_TEXT(gasx + 0.028, gasy - 0.03);
	}

	if (cars2[1].fuel < 0.026)
	{
		GRAPHICS::DRAW_RECT(gasx + (cars2[1].fuel / 2), gasy, cars2[1].fuel, gash, 230, 0, 0, 255);
		lowFuel = true;
	}
	else
	{
		//--GRAPHICS.DRAW_RECT(gasx + (cars[1].fuel / 2), gasy, cars[1].fuel, gash, 156, 181, 42, 255)
		GRAPHICS::DRAW_RECT(gasx + (cars2[1].fuel / 2), gasy, cars2[1].fuel, gash, FuelFullBarRed, FuelFullBarGreen, FuelFullBarBlue, FuelFullBarOpacity);//Full Bar
		lowFuel = false;
	}

	GRAPHICS::DRAW_RECT(gasx + 0.07, gasy, 0.002, gash, 0, 255, 0, 50);
}
void GUI_unload()
{
	int size = sizeof(gasStations) / sizeof(gasStations[0]);
	for (int i = 0; i < size; i++)
	{
		UI::REMOVE_BLIP(&blip[i]);//&blip[i]
	}
}
void GUI_init()
{
	GUI_time = GAMEPLAY::GET_GAME_TIMER();
	//REQUEST_ANIM_DICT(dict)
	int size = sizeof(gasStations) / sizeof(gasStations[0]);
	for (int i = 0; i < size; i++)
	{
		blip[i] = UI::ADD_BLIP_FOR_COORD(gasStations[i].x, gasStations[i].y, gasStations[i].z);
		UI::SET_BLIP_SPRITE(blip[i], 361);
		UI::SET_BLIP_SCALE(blip[i], 0.8);
		UI::SET_BLIP_AS_SHORT_RANGE(blip[i], true);
	}
}
//loop this GUI_Tick
void GUI_tick()
{
	int playerPed = PLAYER::PLAYER_PED_ID();
	int player = PLAYER::PLAYER_ID();
	int playerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
	Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);

	if (playerExists)
	{
		//--refill with jerry can
		if (hasfuel && (WEAPON::GET_SELECTED_PED_WEAPON(playerPed) == 883325847))  //jerrycan
		{
			
			int size = sizeof(cars2) / sizeof(cars2[0]);
			for (int i = 0; i < size; i++)
			{
				if (ENTITY::DOES_ENTITY_EXIST(cars2[i].pointer) && cars2[i].fuel < 0.14)
				{
					
					Vector3 coords = ENTITY::GET_ENTITY_COORDS(cars2[i].pointer, 0);
					Vector3 coords2 = ENTITY::GET_ENTITY_COORDS(playerPed, 0);

					if (GAMEPLAY::GET_DISTANCE_BETWEEN_COORDS(coords.x, coords.y, coords.z, coords2.x, coords2.y, coords2.z, false) < 3)
					{
					
						int ammo = WEAPON::GET_AMMO_IN_PED_WEAPON(playerPed, WEAPON::GET_SELECTED_PED_WEAPON(playerPed));
						drawHintB = false;
						drawHint = true;
						GUI_drawText();
						GUI_renderGUI();
						if (CONTROLS::IS_CONTROL_PRESSED(2, Dpad_Right) && ammo > 0)
						{
							
							cars2[i].fuel = cars2[i].fuel + 0.0005;
							AI::TASK_TURN_PED_TO_FACE_ENTITY(playerPed, cars2[i].pointer, 100);
							//--AI.TASK_PLAY_ANIM(playerPed, dict, anim, 5, -1, -1, 16, 0, false, 0, false);
							WEAPON::SET_PED_AMMO(playerPed, WEAPON::GET_SELECTED_PED_WEAPON(playerPed), ammo - 9);
						}
						else
						{
							drawHint = false;
						}
					}
				}
			}
		}

		//--ENTERED CAR
		if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, false) && VEHICLE::GET_PED_IN_VEHICLE_SEAT(PED::GET_VEHICLE_PED_IS_IN(playerPed, true), -1) == playerPed)
		{
			//--if (PED.IS_PED_IN_ANY_VEHICLE(playerPed, false)) then
			int veh = PED::GET_VEHICLE_PED_IS_IN(playerPed, true);
			float carspeed = ENTITY::GET_ENTITY_SPEED(veh);

			//not needed for an online menu
			//int model;
			//if (IS_PED_MODEL(playerPed, GET_HASH_KEY("player_zero")))
			//{
			//	model = 0;
			//}
			//else if (IS_PED_MODEL(playerPed, GET_HASH_KEY("player_one")))
			//{
			//	model = 1;
			//}
			//else if (IS_PED_MODEL(playerPed, GET_HASH_KEY("player_two")))
			//{
			//	model = 2;
			//}

			//char *statname = "SP" model "_TOTAL_CASH";
			//int hash = GET_HASH_KEY(statname);
			//bool val = STAT_GET_INT(hash, 0, -1);

			//--If vehicle has changed
			if (cars2[1].pointer != veh)
			{
				bool found = false;
				bool emptyfound = false;

				//--Check if current vehicle is used before
				int size2 = sizeof(cars2) / sizeof(cars2[0]);
				for (int j = 0; j < size2; j++)
				{
					if (cars2[j].pointer == veh)
					{
						//-- Has been in this car before
						found = true;

						//idk???
						cars2[1].pointer = veh;
						cars2[1].fuel = 1.0f;
						break;
					}
					else
					{
						//--Check if vehicle still exists, if not then make a possible value if there is no other one(really sloppy)
						if (!ENTITY::DOES_ENTITY_EXIST(cars2[j].pointer))
						{
							cars2[j].pointer = veh;
							cars2[j].fuel = GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(6, 12) / 100;
							emptyfound = true;
						}
					}
				}

				if (!found)
				{
					//-- There is a possible value from earlier
					int size3 = sizeof(cars2) / sizeof(cars2[0]);
					if (emptyfound)
					{
						for (int k = 0; k < size3; k++)
						{
							if (!ENTITY::DOES_ENTITY_EXIST(cars2[k].pointer))
							{
								cars2[k].pointer = 0;
							}
						}
					}
					else
					{
						//	--Remove cars if we are over the 10 cars limit
						if (size3 > 10)
						{
							cars2[1].pointer = 0;
						}
					}

					//-- Insert current car at pos #1
					cars2[1].pointer = veh;
					cars2[1].fuel = GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(6, 12) / 100;
				}
			}

			//-- Does vehicle use fuel ?
			if (VEHICLE::IS_THIS_MODEL_A_CAR(ENTITY::GET_ENTITY_MODEL(veh)) || VEHICLE::IS_THIS_MODEL_A_BIKE(ENTITY::GET_ENTITY_MODEL(veh)) || VEHICLE::IS_THIS_MODEL_A_QUADBIKE(ENTITY::GET_ENTITY_MODEL(veh)))
			{
				//-- Fuel usage
				if ((GAMEPLAY::GET_GAME_TIMER() - GUI_time) > 200)
				{
					if (cars2[1].fuel > 0 && cars2[1].pointer)
					{
						cars2[1].fuel = cars2[1].fuel - (carspeed / 600000);
						GUI_time = GAMEPLAY::GET_GAME_TIMER();
					}
					else
					{
						cars2[1].fuel = 0.0f;
					}
				}
				GUI_renderGUI();
				/*old speedo
				if (GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("mpmissmarkers256"))
				{
					float mph = (carspeed * 2.236936);
					GRAPHICS::DRAW_SPRITE("mpmissmarkers256", "basejump_icon", 0.5, 0.5, 0.2, 0.3, 0.0, 255, 255, 255, 200);//speedo backround
					GRAPHICS::DRAW_SPRITE("mpmissmarkers256", "arm_wrestling_icon", 0.5, 0.5, 0.2, 0.3, mph, 255, 255, 255, 200);//speedo needle
																																 //Fuel gauge 
					GRAPHICS::DRAW_SPRITE("mpmissmarkers256", "darts_icon", 0.2, 0.5, 0.2, 0.3, 0.0, 255, 255, 255, 200);//speedo backround
					GRAPHICS::DRAW_SPRITE("mpmissmarkers256", "air_race_icon", 0.2, 0.5, 0.2, 0.3, cars2[1].fuel, 255, 255, 255, 200);//speedo needle

				}
				else
				{
					GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("mpmissmarkers256", 0);
				}*/
				//Speedo BETA
				if (RealCarModBool) {
					if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), true))
					{
						Vehicle CurrentVeh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
						float Speed = ENTITY::GET_ENTITY_SPEED(CurrentVeh);
						Speed *= 2.94f;
						if (strcmp(SCRIPT::GET_THIS_SCRIPT_NAME(), "ingamehud") == 0)
						{
							GRAPHICS::DRAW_SPRITE("timerbars", "lhs_bg", .82, .90, .17, .06, 0, gradientRed, gradientGreen, gradientBlue, gradientOpacity);
							char SpeedBuffer[10];
							sprintf(SpeedBuffer, "%i MPH", (int)Speed);
							//drawTextinfo(SpeedBuffer, 4, .81, .88, .50, .70, 0, 0, 0, 255, 0);
							drawText(SpeedBuffer, 4, .81, .88, .50, .70, 0, 0, 0, 255, 0);
						}
					}
				}

				hasfuel = true;
				//--Has used his horn to refuel
				if (refillCar == true)
				{
					if (cars2[1].fuel < 0.14)
					{
						//-- car refuel slower than bike
						if (VEHICLE::IS_THIS_MODEL_A_CAR(ENTITY::GET_ENTITY_MODEL(veh)))
						{
							cars2[1].fuel = cars2[1].fuel + 0.001;
						}
						else
						{
							cars2[1].fuel = cars2[1].fuel + 0.002;
						}

						VEHICLE::SET_VEHICLE_ENGINE_ON(veh, false, true);
						//UI::DISPLAY_CASH(true);
						//STAT_SET_INT(hash, val - 1, true); // not needed for an online menu
					}
					else
					{
						refillCar = false;
						cars2[1].fuel = 0.14;
						VEHICLE::SET_VEHICLE_ENGINE_ON(veh, true, true);
					}
				}

				//-- OUT OF GAS
				if (cars2[1].fuel == 0)
				{
					VEHICLE::SET_VEHICLE_ENGINE_ON(veh, false, true);
				}

				//sound horn to refill gas
				if (carspeed < 1 && refillCar == false)
				{
					Vector3 coords = ENTITY::GET_ENTITY_COORDS(playerPed, 0);
					int gas_size = sizeof(gasStations) / sizeof(gasStations[0]);
					for (int l = 0; l < gas_size; l++)
					{
						if (GAMEPLAY::GET_DISTANCE_BETWEEN_COORDS(coords.x, coords.y, coords.z, gasStations[l].x, gasStations[l].y, coords.z, false) < 12 && drawHintB == false)
						{
							//--you are close show hint
							drawHint = false;
							drawHintB = true;
							GUI_drawText();

							if (cars2[1].fuel < 0.14 && drawHintB == true)
							{
								refillCar = PLAYER::IS_PLAYER_PRESSING_HORN(player);
							}
							else
							{
								if (drawHintB == true)
								{
									drawHintB = false;
								}	
							}
							break;
						}
						else
						{
							//--you are far hide hint
							if (drawHintB == true)
							{
								drawHintB = false;
							}
						}

					}
				}
				else
				{
					hasfuel = false;
				}
			}		
		}
		else
		{
			//--EXIT CAR
			lowFuel = false;
			drawHintB = false;
			refillCar = false;
		}
	}
}
#pragma endregion
#pragma region beta_menu //test code
// beta funcs
void drawBetaNotification(char* msg)//Simeon Message
{
	UI::BEGIN_TEXT_COMMAND_THEFEED_POST("STRING");
	_ADD_TEXT_COMPONENT_STRING(msg);
	_SET_NOTIFICATION_MESSAGE("CHAR_SIMEON", "CHAR_SIMEON", true, 1, "Tiny Menu", "Beta Message");// ref : Pic names: https://pastebin.com/XdpJVbHz
	UI::_DRAW_NOTIFICATION(false, true);
}

bool scenariostesting(char *animation_Dictionary, char *animationName)
{
		if (CONTROLS::IS_CONTROL_JUST_PRESSED(0, Button_X)) {
			AI::CLEAR_PED_TASKS(PLAYER::GET_PLAYER_PED(PLAYER::PLAYER_PED_ID()));
		}
		for (int i = 0; i < sizeof(animationName) / 4; i++)
		{
			AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), (char*)animationName[i], 0, 1);
		}
}

void draw_esp_player(char *texture_dict, char *texture_name)
{
	Vector3 player_coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), true);
	float player_coords_f = ENTITY::GET_ENTITY_COORDS_FLOAT(PLAYER::GET_PLAYER_PED(selectedPlayer), true);
	float my_player_coords = ENTITY::GET_ENTITY_COORDS_FLOAT(PLAYER::GET_PLAYER_PED(PLAYER::PLAYER_PED_ID()), true);
	GRAPHICS::DRAW_MARKER(MarkerTypeQuestionMark, player_coords.x, player_coords.y, player_coords.z + 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, PLAYER::GET_PLAYER_PED(selectedPlayer) + 3.0f, 255, 0, 0, 255, true, true, 2, false, texture_dict, texture_name, PLAYER::GET_PLAYER_PED(selectedPlayer));
	GRAPHICS::DRAW_LINE(my_player_coords, my_player_coords, my_player_coords, player_coords_f, player_coords_f, player_coords_f, 255, 0, 0, 255);
}

bool Loadinterior = true;
bool Load_Interior(int interiorID)
{
	if (Loadinterior)
	{
		if (INTERIOR::IS_VALID_INTERIOR(interiorID))
		{
			INTERIOR::_LOAD_INTERIOR(interiorID);
		}
		PRINT("Interior Loaded", 3000);
		Loadinterior = false;
	}
}

bool ENABLE_IPL_INTERIOR(char *IPLNAME)
{
	STREAMING::REQUEST_IPL(IPLNAME);
	if (!STREAMING::IS_IPL_ACTIVE(IPLNAME))
	{
		// im too tired for this 5/15/2021
	}
}

// defs
bool cruise_control_v1 = false;
bool disable_wind = false;
char cruise_control_Option_Buffer[50];
char* theOptionName = "Cruise Control";
char* optionColor1 = "~HUD_COLOUR_GREEN~";
char* optionColor2 = "~HUD_COLOUR_RED~";
bool code_execute_1;
bool get_interiorID = false;
// looped only with developer access
void betaloop() 
{
	/*if (cruise_control_v1)
	{
		if (CONTROLS::IS_CONTROL_JUST_PRESSED(0, BUTTON_DPAD_DOWN))
		{
			code_execute_1 = false;
			if (!code_execute_1)
			{
				sprintf(cruise_control_Option_Buffer, "%s %s", optionColor1, theOptionName);
				if (PED::IS_PED_SITTING_IN_ANY_VEHICLE(PLAYER::GET_PLAYER_PED(PLAYER::PLAYER_PED_ID())))
				{
					Entity myVeh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_ID(), false);
					NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(myVeh);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(myVeh))
					{
						AI::SET_DRIVE_TASK_CRUISE_SPEED(PLAYER::PLAYER_ID(), myVeh);
					}
				}
				else
				{
					PRINT("~HUD_COLOUR_RED~MUST BE IN A VEHICLE!");
				}
				code_execute_1 = true; // stop running this code looped after first trigger until DPAD_DOWN is pressed again.
			}
		}
		else if (!cruise_control_v1) { sprintf(cruise_control_Option_Buffer, "%s", theOptionName); }
	}*/
	if (disable_wind)
	{
		GAMEPLAY::SET_WIND(0.0f);
		GAMEPLAY::SET_WIND_SPEED(0.0f)
	}
	else if (!disable_wind)
	{
		char naturalwind_buffer[10];
		if (GAMEPLAY::GET_WIND_SPEED() < 1.0f) {
			sprintf(wind_buffer, "%.2f", (GAMEPLAY::GET_WIND_SPEED() += 0.2f));
		}
		GAMEPLAY::SET_WIND(*(float*)wind_buffer);
		GAMEPLAY::SET_WIND_SPEED(*(float*)wind_buffer)
	}
	if (get_interiorID)
	{
		Vector3 me = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
		int InteriorID = INTERIOR::GET_INTERIOR_AT_COORDS(me.x, me.y, me.z);
		int InteriorGroupID = INTERIOR::GET_INTERIOR_GROUP_ID(InteriorID);
		int InteriorRoomKey = INTERIOR::GET_ROOM_KEY_FROM_ENTITY(PLAYER::PLAYER_PED_ID());
		Vector3 loc = INTERIOR::GET_OFFSET_FROM_INTERIOR_IN_WORLD_COORDS(InteriorID, me.x, me.y, me.z);
		char InteriorIDbuf[100];
		char OffsetBuf[100];
		char GroupIDBuf[100];
		char RoomKeyBuf[100];
		sprintf(InteriorIDbuf, "Current Interior ID: %i", InteriorID);
		sprintf(OffsetBuf, "\nCurrent Interior Offset: 0x%02x", loc);
		sprintf(GroupIDBuf, "Current Interior Group ID: %i", InteriorGroupID);
		sprintf(RoomKeyBuf, "Current Interior Room Key: 0x%02x", InteriorRoomKey);
		int hashval = GAMEPLAY::GET_HASH_KEY(OffsetBuf);
		char finaloffsetbuf[150];
		strcpy(finaloffsetbuf, OffsetBuf);
		//drawText(RoomKeyBuf, 0, 0.4f, 0.9332f, 1.5f, 0.5f, 255, 255, 255, 255, false);		// Interior Room Key offset
		//drawText(GroupIDBuf, 0, 0.4f, 0.9332f, 1.0f, 0.5f, 255, 255, 255, 255, false);		// Interior Group ID
		drawText(InteriorIDbuf, 0, 0.4f, 0.9332f, 0.1f, 0.5f, 255, 255, 255, 255, false);			// Interior ID
		drawText(finaloffsetbuf, 0, 0.4f, 0.94f, 2.5f, 0.4, 255, 255, 255, 255, false);		// Interior Offset
	}
}
#pragma endregion

#pragma endregion