// Tiny Menu 5.0.0 Final Revision By FaZeModz 
#include <sys/dbg.h>

CDECL int _sys_printf(char* format, ...);
#define printf _sys_printf

CDECL int _sys_sprintf(char* buffer, char* format, ...);
#define sprintf _sys_sprintf

CDECL int _sys_snprintf(char* buffer, int size, char* format, ...);
#define snprintf _sys_snprintf


   
#pragma region old Includes for auth
#include <cellstatus.h>
#include <ppu_asm_intrinsics.h>
#include <ppu_intrinsics.h>
#include <sys/prx.h>
#include <sys/ppu_thread.h>
#include <string.h>
#include <sys/memory.h>
#include <sys/timer.h>
#include <sys/process.h>
#include <ppu_intrinsics.h>
#include <stdarg.h>
#include <stdio.h>
#include <cstdlib>
#include <sysutil\sysutil_msgdialog.h>
#include <sysutil\sysutil_oskdialog.h>
#include <sysutil\sysutil_oskdialog_ext.h>
#include <sys/sys_time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/syscall.h>
#include <sys/timer.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netex/net.h>
#include <netex/errno.h>
#include <string.h>
#pragma endregion 
#pragma region Declarations
#include <sys/ppu_thread.h>
#include <string.h>
#include <sys/sys_time.h>
#include <sys/time_util.h>
#include <stdarg.h>
#include <assert.h>
#include <sys/process.h>
#include <sys/memory.h>
#include <sys/timer.h>
#include <sys/return_code.h>
#include <sys/prx.h>
#include <stddef.h>
#include <math.h>
#include <stdarg.h>
#include <cellstatus.h>
#include <typeinfo>
#include <vector>
#include <pthread.h>
#include <locale.h>
#include <cell/error.h>
#include <sys/paths.h>
#include <time.h>
#include <net\if_dl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cell/cell_fs.h>
#include <cell/sysmodule.h>
#include <stdio.h>
#include <string.h>
#include <cell/fs/cell_fs_errno.h>
#include <cell/fs/cell_fs_file_api.h>
#include <ppu_intrinsics.h>
#include <cstdlib>
#include <cell/pad.h>
#include <cell/pad/pad_codes.h>

#include "printf.h"
#include "special_dialog.h"




#include "Enums.h"
#include "Natives.h"
#include "New modz Defs.h" //And Script Events
#include "mods.h"
#include "Socket.h"
#include "MenuUtils.h" //Loop 1
#include "cscinjector.h" // added thanks to gopro in 4.X.X+ 1/23/21
#include "New modz.h" // contains csc loop





SYS_MODULE_INFO("Tiny Ass Menu", 0, 1, 1);
SYS_MODULE_START(PRX_ENTRY);

int _Timer = 0;
#define DEVELOPERMODE true // if false.. no Kick Protection

#pragma region Globals
#define MENUTYPE menutype[0] == 1

#pragma region GAME_ID_detection
#define unk_title_id_var "BLES01807"

bool IsGameGTAV(char *cur_title_id)//CheckGameID
{
	if (!strcmp(cur_title_id, unk_title_id_var))
	{
		return true;
	}

	return false;
}
int32_t sys_get_game_application_title_Id(char *title_id)
{
	system_call_1(986, (uint64_t)title_id);
	return_to_user_prog(int32_t);
}
char *GetCurrentGameID()
{
	char tittle_id[0x40];
	sys_get_game_application_title_Id(tittle_id);
	return tittle_id;
}
void check_game()
{
	char *game_id = GetCurrentGameID();
	//printf("game_id: %s\n", game_id);

	if (IsGameGTAV(game_id))
	{
		printf("GTA Detected!")
	}
}

//dropKickAnti
void hgufaighfuiap() 
{
    int Ptr = *(int*)(0x1E70384);
    if (Ptr != 0) {
        *(int*)(Ptr + 0x1DBC) = 0;
    }
}
// dropKickAnti2
#define hgfusahup() \
{\
    unsigned int Global_2387877_address = (*(int*)0x1E70394+0x1BE94);\
    if (*(int*)Global_2387877_address > 4) {\
        *(int*)Global_2387877_address = 4;\
    }\
}
//antiFakeLeaveV2
#define vnjcbdiwe9() \
{\
    unsigned int Global_1588610_address = (*(int*)0x1E70388+0xF608);\
    unsigned int Global_1572928_address = (*(int*)0x1E70388+0x100);\
    if (*(int*)Global_1588610_address == 0)\
        *(int*)Global_1588610_address = 0x12;\
    if (*(int*)Global_1572928_address == 0)\
        *(int*)Global_1572928_address = 2;\
}
#pragma endregion
#pragma endregion



		/* Thismenuversion = Go to Definition

		Change lOg v4.1.0 
		<label>Added</label>
		<br>
		<li>Activated Lifetime mode</li>
		<br>
		<br>
		<li>Updated</li>
		<br>
		<li>Auto Update Now Fully Functional with Hen!</li>
		<br>
		<br>
		<label>Open a Ticket and report bugs if any are found!</label>


		IMPORTANT NEWS: 
		AS OF NOW 12/4/2020 I am getting a kernal Panick which makes no sense as i Have added nothing since 12/2/2020 and the menu loaded then..
		ALRIGHT>>>> I FUCKING FIXED IT... Garage in apartments uses HookNative... Which causes a freeze... Not sure what im going to do yet...12/5/20


		Updated 4.1.0 Dev Notes: 
		Started Work on Downloading csc scripts from the server. Cant seem to get the menu to properly receive the file size. 
		Probably server related. 
		- Server files added
		- Folder 'CSC' rock_menu2.csc
		- csc.php in www/html
		- added file size check to class.php
		

		Update 4.4.6
		- Fixed freeze in csc injector
		- Need to fix toggle script
		- seems Download script is working fine now. Need to truncate the file so it wipes all current data before writing new data.
		- not really sure what menu its downloading but also need to remove the http header from the file 'FILE_START' to DownloadAnyFile()
		- Over all great update. Got some work to do... 2/16/2021
		
		Update 4.5.0
		- Created Beta menu (Dev Access)
		- Cruise control only seems to work on story. (Beta Menu)
		- Updated protections. (Arabic Guy)
		- Updated Clear Area (Lobby Options)
		- Updated Stability Features (Automatic)
		- Fixed a bug in Auto Update for HEN users.
		- Updated Vehicle Spawner (Stability update)
		- Fixed Freeze Time (Weather Options)
		- Added Prologue Bypass 
		- Added CEX Support
		- Added Game Crash Exit (Select + Start)
		- Refreshed All TinyMenu Keys. (Visit Discord)
		- Updated Protections (Jaro666)

		- Removed Alternative Base Support
		- removed Script manager at least until i can fix the toggle script bug.

		- Moved Scenarios to Beta Menu until i can fix the bug. (Dev Access)

		03/23/2021
		add a new thread next. use syscall for system process exit gta 5 .. use sdk buttons... (Exit Game if crash via buttons)


		05/15/2021 
		STREAMING::_SWITCH_OUT_PLAYER 
		Look into this on Native DB 


		
		*/

void otherLoop();
int Hook() 
{
	if (Dev_access[0]) { startScriptLoop(); betaloop(); }
	monitorButtons();
	otherLoop();
	optionCount = 0;
	PLAYER::SET_PLAYER_MAX_ARMOUR(PLAYER::PLAYER_PED_ID(), 1997);//MENU ID For Others Menus
	setupScriptEventDetour(); //modder protections
	switch (submenu)
	{
#pragma region Main Menu
	case Main_Menu:
		addTitle("Tiny Menu");
		addSubmenuOption("Self", Self_Options);
		addSubmenuOption("Players", Players_List);
		addSubmenuOption("Lobby", Lobby_menu);
		addSubmenuOption("Spawn", Vehicle_spawner);
		addSubmenuOption("Vehicle", Vehicle_Mods);
		addSubmenuOption("Teleport", Teleport_menu);
		addSubmenuOption("Weather", weather);
		addSubmenuOption("Recovery", recovery);
		addSubmenuOption("Protections", mddrprotect); 
		addSubmenuOption("Settings", Settings);
		addSubmenuOption("Credits", Credits);
		if (Dev_access[0]) { 
		addSubmenuOption("Scenarios", Player_scenes);
		//addSubmenuOption("Script Manager", scriptmanager); // needs bugs fixed before giving to the beta testing team.
		//addOption("Download Script [BETA]"); // works great just need to add truncate to function
		addSubmenuOption("Beta Options", beta_menu); // case 13
			switch (getOption())
			{
				case 13: changeSubmenu(beta_menu); break;
				//case 11: changeSubmenu(scriptmanager); break; // moved out of release until i can fix the freezing problem
				//case 14: DownloadAnyFile("/dev_hdd0/tmp/TinyMenu/CSC/script.csc"); break;
			}
		}
		break;
#pragma endregion
#pragma region beta_menu
	case beta_menu:
		char versionbuff[30];
		sprintf(versionbuff, "Beta v%s", Thismenuversion);
		Ped me = PLAYER::PLAYER_PED_ID();
		addTitle(versionbuff);
		addBoolOption("Cruise Control"/*cruise_control_Option_Buffer*/, cruise_control_v1); // commented out looped func for release.
		addBoolOption("Disable Wind", disable_wind);
		addOption("Print Wind Speed");
		addBoolOption("Print Interior ID", get_interiorID);
		addBoolOption("Rockstar Developer", rockstarDeveloper);
		addBoolOption("Spoof to Badsport", badsportlobbyspoof);
		addOption("Tubing Mod Story");
		addOption("Tubing Mod Online");
		//addOption("Prologue Bypass"); // we did it in memory thanks to Luis & Tyler
		switch (getOption())
		{
			case 1: cruise_control_v1 = !cruise_control_v1; break;
			case 2: disable_wind = !disable_wind; if (disable_wind) { drawBetaNotification("Try Flying!"); } break;
			case 3: char naturalwind_buffer[30]; sprintf(naturalwind_buffer, "WIND SPEED : %02x", GAMEPLAY::GET_WIND_SPEED()); PRINT(naturalwind_buffer, 3000); break;
			case 4: get_interiorID = !get_interiorID; break;
			case 5: rockstarDeveloper = !rockstarDeveloper; break;
			case 6: badsportlobbyspoof = !badsportlobbyspoof; break;
			case 7: create_boat = 1; toggle_boat_ride = 1; break; //case 5: drawNotification("~HUD_COLOUR_PINK~Coming in Future Update!"); break;
			case 8: tube = true; break; //case 6: drawNotification("~HUD_COLOUR_PINK~Coming in Future Update!"); break;
			/*case 9: 
					if (check_if_file_exists("/dev_hdd0/tmp/TinyMenu/update.rpf") == false)
					{
						RPFupdate("/dev_hdd0/game/BLES01807/USRDIR/update.rpf", customrpfsize);
					}
					printf("\n\nRPF Size: %i\n\n", customrpfsize); break;*/
		}
		break;
#pragma endregion
#pragma region Self Options
	case Self_Options://18-21 options per page Bc removed Infinite Scroll *Old School Base*(;
		addTitle("Self Options");
		addBoolOption("Godmode", GODMODE_NEW);
		addBoolOption("Godmode V2 [Undetected]", undectedgmode);
		addBoolOption("NoRagDoll", noragdoll);
		addBoolOption("Invisibility", !ENTITY::IS_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID()));
		addBoolOption("Never Wanted", wanted);
		addBoolOption("Off Radar", selfoffradar);
		addBoolOption("Blind Eye", NoCops);
		addOption("Clone Self");
		addOption("Give Weapons");
		addBoolOption("Unlimited Ammo", unlimitedammo);
		addBoolOption("Rapid Fire", rapidfire);
		addBoolOption("1 Shot 1 Kill", oneshot);
		//addBoolOption("No Ragdoll", noragdoll);
		addBoolOption("Tiny Person Glow", ghostrider1);
		addBoolOption("Ghost Rider", ghostrider2);
		//addBoolOption("Drive Train", drivetrain); //Fix Later 
		//addBoolOption("First Person ~w~[BETA]", isFirstPersonEnabled);
		addBoolOption("Sky Run", superRun);//case 14
		addBoolOption("Forcefield", forcefeld);
		addBoolOption("Super Punch", BigPunch);
		addBoolOption("Mobile Radio", Radioing);// added back in 4.0.0
		//addBoolOption("Weapons In Apartment", garage);//added back to 4.0.0
		//addSubmenuOption("Change Model ~w~[BETA]", changemodel);
		//addSubmenuOption("Animations ~w~[BETA]", anims);
		switch (getOption())
		{
		case 1: GODMODE_NEW = !GODMODE_NEW; break;
		case 2: undectedgmode = !undectedgmode; break; //added back for 4.0.0
		case 3: noragdoll = !noragdoll; break;
		case 4: ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), !ENTITY::IS_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID())); break;
		case 5: wanted = !wanted; break;
		case 6: selfoffradar = !selfoffradar; break;
		case 7: NoCops = !NoCops; break; //Blind Eye
		case 8: cloneself(PLAYER::PLAYER_PED_ID()); break;
		case 9: giveAll(PLAYER::PLAYER_ID()); break;
		case 10: unlimitedclip(); break;
		case 11: rapidfire = !rapidfire; break;
		case 12: oneshot = !oneshot; break;
		case 13:ghostrider1 = !ghostrider1; break;
		case 14:ghostrider2 = !ghostrider2; break;
		case 15: drawNotification("~HUD_COLOUR_BLUE~Start From Maze Bank"); superRun = !superRun; break;
		case 16: forcefeld = !forcefeld; break;
		case 17: BigPunch = !BigPunch; break;
		case 18: Radioing = !Radioing; break; // added back in 4.0.0
		//case 19: garage = !garage;     break; 
		}
		break;
#pragma endregion
#pragma region Players List
	case Players_List:
		addTitle("Players List");
		for (int i = 0; i < 18; i++)
		{
			if (i == NETWORK::NETWORK_GET_HOST_OF_SCRIPT("freemode", -1, 0)) 
			{
				char hostbuffer[50];
				char* host = PLAYER::GET_PLAYER_NAME(i);
				sprintf(hostbuffer, "%s [HOST]", PLAYER::GET_PLAYER_NAME(i));
				addOption(hostbuffer);
			}
			else {
				addOption(PLAYER::GET_PLAYER_NAME(i));
			}
		}
		if (optionPress && PLAYER::IS_PLAYER_PLAYING(currentOption - 1))
		{
			selectedPlayer = currentOption - 1;
			changeSubmenu(Player_Options);
		}
		break;
#pragma endregion
#pragma region Player Options 
	case Player_Options:
		playerstuff(true);
		Vehicle VehicleHandle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED(selectedPlayer), true);
		addTitle(PLAYER::GET_PLAYER_NAME(selectedPlayer));//Continues Too use players name instead of menu title
		//addSubmenuOption("CLIENT STATS", Stats);
		//addSubmenuOption("Script Events", Script_Events);
		//addSubmenuOption("Scenarios", Player_scenes);
		addSubmenuOption("Fun Mods", Fun_modz);
		addSubmenuOption("Vehicle Mods", player_veh_mods);
		addSubmenuOption("Trolling Mods", Troll);
		addOption("Teleport To Player");
		addOption("Teleport Player To Me");
		addOption("Teleport Player Into Car");
		addOption("Explode Player");
		addOption("Non Host Kick");//case5
		addOption("Host Kick");
		addOption("Kill Passive");//case 8
		addBoolOption("Direct Deposit Freeze V1", depositfreeze);
		addBoolOption("Direct Deposit", deposit);
		addBoolOption("40K Drop", loop40K_);
		addOption("Say Hello");//Send One Player Text message
		addOption("Make Fake Leave");
		addBoolOption("Reset View Looped", Resetviewlp);
		addOption("Teleport To Golf");
		addOption("Teleport To Darts");
		addBoolOption("Remove Wanted Level", clientwanted);
		addBoolOption("Fake 40K Drop", fakeloop40);
		addBoolOption("Spectate Player", specPlayer);//17
		switch (getOption())
		{
		case 4: TeleportToClient(PLAYER::GET_PLAYER_PED(selectedPlayer)); break;
		case 5: Vector3 tmp = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 1.3, 0.0);
			teleportplayerfoot(PLAYER::GET_PLAYER_PED(selectedPlayer), "missfbi5ig_30monkeys", "monkey_a_freakout_loop", tmp.x, tmp.y, tmp.z); break;
		case 6: Vector3 Coords2 = ENTITY::GET_ENTITY_COORDS(selectedPlayer, 1);
			FIRE::ADD_OWNED_EXPLOSION(selectedPlayer, Coords2.x, Coords2.y, Coords2.z, 7, 15, true, true, true); break;
		case 7: if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::GET_PLAYER_PED(selectedPlayer), 0))
		{
			int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED(selectedPlayer), 0);
			PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), veh, GET_FREE_SEAT(veh));
		}
				break;
		case 8: kickPlayerNonHost(selectedPlayer); break;
		case 9: NETWORK::NETWORK_SESSION_KICK_PLAYER(selectedPlayer); break;
		//case 4: bool_player[5] = !bool_player[5]; break;
		case 10:
			Vector3 Coords = ENTITY::GET_ENTITY_COORDS(selectedPlayer, 1);
			FIRE::ADD_EXPLOSION(Coords.x, Coords.y, Coords.z, 1, 4, 0, 0, 0); break;
		case 11:depositfreeze = !depositfreeze; break;//Try this then rename the void to just deposit1
		case 12: deposit = !deposit; break;
		case 13: loop40K_ = !loop40K_; break;
		case 14: sendText(selectedPlayer, "~b~Hello!", 7); break;//7 is font 4 Is Tiny Menu Font
		case 15: int Args9[3];
			Args9[0] = 0x2;
			Args9[1] = selectedPlayer;
			Args9[2] = 0x34;//46
			TriggerScriptEvent(Args9, 3, selectedPlayer); break;
		case 16: Resetviewlp = !Resetviewlp; break;
		case 17: int Args11[3];
			Args11[0] = 0x3;
			Args11[1] = selectedPlayer;
			Args11[2] = 0x37;
			TriggerScriptEvent(Args11, 3, selectedPlayer);
			drawNotification("~HUD_COLOUR_PINK~Teleported Player to Golf"); break;
		case 18: int Args12[3];
			Args12[0] = 0x3;
			Args12[1] = selectedPlayer;
			Args12[2] = 0x36;
			TriggerScriptEvent(Args12, 3, selectedPlayer);
			drawNotification("~HUD_COLOUR_PINK~Teleported Player to Darts"); break;
		case 19: clientwanted = !clientwanted; break;
		case 20: fakeloop40 = !fakeloop40; break;
		case 21: specPlayer = !specPlayer; break;
		}
		break;
#pragma endregion
#pragma region Fun Mods
	case Fun_modz:
		playerstuff(true);
		addTitle(PLAYER::GET_PLAYER_NAME(selectedPlayer)); //Continues Too use players name instead of menu title
		addBoolOption("Rank Player 10,000 RP", Take_RP);
		addBoolOption("Derank Player", Give_RP);
		addOption("Drive Rollercoaster");
		addBoolOption("PTFX Man", ghostrider11);//case 5
		switch (getOption())
		{
		case 1: Take_RP = !Take_RP; break;
		case 2: Give_RP = !Give_RP; break;
		case 3: dorollercoaster = true;//story only.. Freezes online for the moment*/  
		case 4: char buff[50]; sprintf(buff, "~b~Coming on TinyMenu V%s", Thismenuversion); drawNotification(buff);	break;
		case 5: ghostrider11 = !ghostrider11; break;//case 5 starts here
		}
		break;
#pragma endregion
#pragma region Player Veh Mods
	case player_veh_mods:
		playerstuff(true);
		addTitle(PLAYER::GET_PLAYER_NAME(selectedPlayer));
		addOption("Boost Vehicle Forward");
		addOption("Launch Vehicle");
		addBoolOption("Set Vehicle Godmode", Godmodplveh);
		addOption("MaxOut Players Vehicle");
		addOption("Teleport to Me [Vehicle]");
		addOption("Fix Player Vehicle");
		addBoolOption("Launch Player Vehicle", Shotsling);//Increased Power
		addOption("Kick Player From Vehicle");
		addBoolOption("Disable Player Vehicle", doUndriveableCar);//fixed
		addBoolOption("Horn Boost", boostHorn);
		switch (getOption())
		{
		case 1: NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(PED::GET_VEHICLE_PED_IS_IN(selectedPlayer, false)),
			VEHICLE::SET_VEHICLE_FORWARD_SPEED(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED(selectedPlayer), false), 100.0f); break;//use this to set on network player (PLAYER::GET_PLAYER_PED(selectedPlayer)

		case 2: NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(PED::GET_VEHICLE_PED_IS_IN(selectedPlayer, false)),
			ENTITY::APPLY_FORCE_TO_ENTITY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED(selectedPlayer), false), 1, 0.0, 0.0, 10.0, 0.0, 60.0, 0.0, 1, false, true, true, true, true); break;//1, 0.0, 0.0, 6.0, 0.0, 3.0, 0.0, 1, false, true, true, true, true edit parameters Float Y & Z to fit your needs

		case 3:Godmodplveh = !Godmodplveh; break;
		case 4: NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(VehicleHandle);
			if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(VehicleHandle))
			{
				VehicleMaxUpgrades(selectedPlayer);
			}
			else
				drawNotification("~b~Player is not in a vehicle");
			break;
		case 5: if (PED::IS_PED_IN_ANY_VEHICLE(selectedPlayer, true))
		{
			TeleportToMe = true;
		}
				else
					drawNotification("~b~Player is not in a vehicle"); break;
		case 6: NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(VehicleHandle);
			if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(VehicleHandle))
			{
				VEHICLE::SET_VEHICLE_FIXED(VehicleHandle);
			}
			else
				drawNotification("~b~Player is not in a vehicle");
			break;
		case 7: Shotsling = !Shotsling; break;
		case 8: KickFromCar(selectedPlayer); break;
		case 9: doUndriveableCar = !doUndriveableCar; break;
		case 10: boostHorn = !boostHorn; break;
		}
		break;
#pragma endregion
#pragma region Player Options Page 2 (Troll)
	case Troll: 
		playerstuff(true);
		addTitle(PLAYER::GET_PLAYER_NAME(selectedPlayer));
		addSubmenuOption("Player Stat Menu", PlayerSTATmenu);
		addBoolOption("Clear Task", ClearPlayrTaskLoop);
		addOption("Clone Player");
		addOption("Love Tap Kick [NEW]");
		switch (getOption())
		{
		case 2: ClearPlayrTaskLoop = !ClearPlayrTaskLoop; break;
		case 3: drawNotification("~b~Doesn't effect other modders"); clonefreeze = !clonefreeze; break;
		case 4: Write_Global(0x183D83 + selectedPlayer, 1); break; //added in 4.0.0
		}
		break;
#pragma endregion
#pragma region Player stat menu
	case PlayerSTATmenu:
		playerstuff(true);
		addTitle(PLAYER::GET_PLAYER_NAME(selectedPlayer));
		addOption("Gift Player 2Billion");//NEW
		addOption("Gift Player Max Abilities");//NEW
		addOption("Gift Player Max Ammo");//NEW
		addOption("Gift Unlock All LSC");//NEW
		addOption("Modded Roll");//case 12
		switch (getOption())
		{
		case 1:
			SetPlayerStats(selectedPlayer, "CASH_GIFT", 2000000000);//2B
			sendText(selectedPlayer, "Cash Given    ~b~Change Session to See Effects", 4);
			drawNotification("~b~Sending Cash Gift Stats too Player!");
			break;
		case 2:
			SetPlayerStats(selectedPlayer, "MP0_SCRIPT_INCREASE_STAM", 100);
			SetPlayerStats(selectedPlayer, "MP0_SCRIPT_INCREASE_STRN", 100);
			SetPlayerStats(selectedPlayer, "MP0_SCRIPT_INCREASE_LUNG", 100);
			SetPlayerStats(selectedPlayer, "MP0_SCRIPT_INCREASE_DRIV", 100);
			SetPlayerStats(selectedPlayer, "MP0_SCRIPT_INCREASE_FLY", 100);
			SetPlayerStats(selectedPlayer, "MP0_SCRIPT_INCREASE_SHO", 100);
			SetPlayerStats(selectedPlayer, "MP0_SCRIPT_INCREASE_STL", 100);
			SetPlayerStats(selectedPlayer, "MP0_RACES_WON", 100);
			sendText(selectedPlayer, "~b~MAX STATS GIVEN! \n Dont Leave Lobby For 5 Minutes to save stats!", 7);
			drawNotification("~b~Sending Max Ability Stats too Player!");
			break;
		case 3:
			SetPlayerStats(selectedPlayer, "MP1_GRNLAUNCH_FM_AMMO_BOUGHT", 1);
			SetPlayerStats(selectedPlayer, "MP1_GRNLAUNCH_FM_AMMO_CURRENT", -1);
			SetPlayerStats(selectedPlayer, "MP1_RPG_FM_AMMO_BOUGHT", 1);
			SetPlayerStats(selectedPlayer, "MP1_RPG_FM_AMMO_CURRENT", -1);
			SetPlayerStats(selectedPlayer, "MP1_MINIGUNS_FM_AMMO_BOUGHT", 1);
			SetPlayerStats(selectedPlayer, "MP1_MINIGUNS_FM_AMMO_CURRENT", -1);
			SetPlayerStats(selectedPlayer, "MP1_STKYBMB_FM_AMMO_BOUGHT", 1);
			SetPlayerStats(selectedPlayer, "MP1_STKYBMB_FM_AMMO_CURRENT", -1);
			SetPlayerStats(selectedPlayer, "MP1_SMKGRENADE_FM_AMMO_BOUGHT", 1);
			SetPlayerStats(selectedPlayer, "MP1_SMKGRENADE_FM_AMMO_CURRENT", -1);
			SetPlayerStats(selectedPlayer, "MP1_GRENADE_FM_AMMO_BOUGHT", 1);
			SetPlayerStats(selectedPlayer, "MP1_GRENADE_FM_AMMO_CURRENT", -1);
			SetPlayerStats(selectedPlayer, "MP1_PRXMINE_FM_AMMO_BOUGHT", 1);
			SetPlayerStats(selectedPlayer, "MP1_PRXMINE_FM_AMMO_CURRENT", -1);
			SetPlayerStats(selectedPlayer, "MP1_HOMLNCH_FM_AMMO_BOUGHT", 1);
			SetPlayerStats(selectedPlayer, "MP1_HOMLNCH_FM_AMMO_CURRENT", -1);
			SetPlayerStats(selectedPlayer, "MP1_FLAREGUN_FM_AMMO_BOUGHT", 1);
			SetPlayerStats(selectedPlayer, "MP1_FLAREGUN_FM_AMMO_CURRENT", -1);
			drawNotification("~b~Sending Unlimited Ammo Stats too Player!");
			if (!(cstrcmp(PLAYER::GET_PLAYER_NAME(selectedPlayer), "-")) && selectedPlayer != PLAYER::PLAYER_ID()) {
				sendText(selectedPlayer, "~b~MAX AMMO STATS GIVEN! \n Dont Leave Lobby For 5 Minutes to save stats!", 7);
			}
			break;
		case 4:
			drawNotification("~b~Dont Spam or Freeze");//Text Message notification Tested Works Great!
			SetPlayerStats(selectedPlayer, "MP0_AWD_FMRACEWORLDRECHOLDER", 1);
			SetPlayerStats(selectedPlayer, "MP0_AWD_ENEMYDRIVEBYKILLS", 600);
			SetPlayerStats(selectedPlayer, "MP0_USJS_COMPLETED", 50);
			SetPlayerStats(selectedPlayer, "MP0_USJS_FOUND", 50);
			SetPlayerStats(selectedPlayer, "MP0_AWD_FMWINALLRACEMODES", 1);
			SetPlayerStats(selectedPlayer, "MP0_AWD_FMWINEVERYGAMEMODE", 1);
			SetPlayerStats(selectedPlayer, "MP0_DB_PLAYER_KILLS", 1000); // drive by kills
			SetPlayerStats(selectedPlayer, "MP0_KILLS_PLAYERS", 1000);
			SetPlayerStats(selectedPlayer, "MP0_AWD_FMHORDWAVESSURVIVE", 21);
			SetPlayerStats(selectedPlayer, "MP0_AWD_CAR_BOMBS_ENEMY_KILLS", 25);
			SetPlayerStats(selectedPlayer, "MP0_AWD_FM_TDM_MVP", 60);
			SetPlayerStats(selectedPlayer, "MP0_AWD_HOLD_UP_SHOPS", 20);
			SetPlayerStats(selectedPlayer, "MP0_AWD_RACES_WON", 101);
			SetPlayerStats(selectedPlayer, "MP0_AWD_NO_ARMWRESTLING_WINS", 21);
			SetPlayerStats(selectedPlayer, "MP0_AWD_FMATTGANGHQ", 1);
			SetPlayerStats(selectedPlayer, "MP0_AWD_FMBBETWIN", 50000);
			SetPlayerStats(selectedPlayer, "MP0_AWD_FM_DM_WINS", 51);
			SetPlayerStats(selectedPlayer, "MP0_AWD_FMFULLYMODDEDCAR", 1);
			SetPlayerStats(selectedPlayer, "MP0_AWD_FM_DM_TOTALKILLS", 500);
			SetPlayerStats(selectedPlayer, "MP0_MPPLY_DM_TOTAL_DEATHS", 412);
			SetPlayerStats(selectedPlayer, "MP0_MPPLY_TIMES_FINISH_DM_TOP_3", 36);
			SetPlayerStats(selectedPlayer, "MP0_PLAYER_HEADSHOTS", 623);
			SetPlayerStats(selectedPlayer, "MP0_AWD_FM_DM_WINS", 63);
			SetPlayerStats(selectedPlayer, "MP0_AWD_FM_TDM_WINS", 13);
			SetPlayerStats(selectedPlayer, "MP0_AWD_FM_GTA_RACES_WON", 12);
			SetPlayerStats(selectedPlayer, "MP0_AWD_FM_GOLF_WON", 2);
			SetPlayerStats(selectedPlayer, "MP0_AWD_FM_SHOOTRANG_TG_WON", 2);
			SetPlayerStats(selectedPlayer, "MP0_AWD_FM_SHOOTRANG_RT_WON", 2);
			SetPlayerStats(selectedPlayer, "MP0_AWD_FM_SHOOTRANG_CT_WON", 2);
			SetPlayerStats(selectedPlayer, "MP0_AWD_FM_SHOOTRANG_GRAN_WON", 2);
			SetPlayerStats(selectedPlayer, "MP0_AWD_FM_TENNIS_WON", 2);
			SetPlayerStats(selectedPlayer, "MP0_MPPLY_TENNIS_MATCHES_WON", 2);
			SetPlayerStats(selectedPlayer, "MP0_MPPLY_TOTAL_TDEATHMATCH_WON", 63);
			SetPlayerStats(selectedPlayer, "MP0_MPPLY_TOTAL_RACES_WON", 101);
			SetPlayerStats(selectedPlayer, "MP0_MPPLY_TOTAL_DEATHMATCH_LOST", 23);
			SetPlayerStats(selectedPlayer, "MP0_MPPLY_TOTAL_RACES_LOST", 36);
			SetPlayerStats(selectedPlayer, "MP0_AWD_25_KILLS_STICKYBOMBS", 50);
			SetPlayerStats(selectedPlayer, "MP0_AWD_50_KILLS_GRENADES", 50);
			SetPlayerStats(selectedPlayer, "MP0_GRENADE_ENEMY_KILLS", 50);
			SetPlayerStats(selectedPlayer, "MP0_AWD_20_KILLS_MELEE", 50);
			{
				if (!(cstrcmp(PLAYER::GET_PLAYER_NAME(selectedPlayer), "-")) && selectedPlayer != PLAYER::PLAYER_ID()) {
					sendText(selectedPlayer, "~b~Sending Unlock All LSC", 7);
				}
			}
			break;

		case 5: SetPlayerStats(selectedPlayer, "MP0_SHOOTING_ABILITY", 250); break;//modded roll test
		//case 16: ccapinotify("buzzer.ps3mapi?mode=1"); break; break;
		//case 15: NETWORK::NETWORK_SET_VOICE_ACTIVE(true); break;
		}
		break;
#pragma endregion 
#pragma region Lobby
	case Lobby_menu:
		//char *players_list[] = { PLAYER::GET_PLAYER_NAME(0), PLAYER::GET_PLAYER_NAME(1), PLAYER::GET_PLAYER_NAME(2), PLAYER::GET_PLAYER_NAME(3), PLAYER::GET_PLAYER_NAME(4), PLAYER::GET_PLAYER_NAME(5), PLAYER::GET_PLAYER_NAME(6), PLAYER::GET_PLAYER_NAME(7), PLAYER::GET_PLAYER_NAME(8), PLAYER::GET_PLAYER_NAME(9), PLAYER::GET_PLAYER_NAME(10), PLAYER::GET_PLAYER_NAME(11), PLAYER::GET_PLAYER_NAME(12), PLAYER::GET_PLAYER_NAME(13), PLAYER::GET_PLAYER_NAME(14), PLAYER::GET_PLAYER_NAME(15), PLAYER::GET_PLAYER_NAME(16), PLAYER::GET_PLAYER_NAME(17), PLAYER::GET_PLAYER_NAME(18) };
		addTitle("Lobby");
		addBoolOption("Clear Area", clearArea);
		addBoolOption("Rain Weapons", rainweapons);
		addBoolOption("Rain Money", rainmoney);
		addBoolOption("Talking Players", bool_lobby[1]);
		addBoolOption("Flat Ocean", ocean_intensity_toggle);
		addBoolOption("Disable Mini Map", Radaroff);
		addBoolOption("Reveal All Players", RevealAll);
		addOption("Disable Idle Kick");
		//addOption("Force Host"); //Freezes Hen Users removed from v4.0.0
		addOption("All Player Messages");
		switch (getOption())
		{
		case 1: clearArea = !clearArea; break;
		case 2: rainweapons = !rainweapons; break;
		case 3: rainmoney = !rainmoney; break;
		case 4: bool_lobby[1] = !bool_lobby[1]; break;
		case 5: ocean_intensity_toggle = !ocean_intensity_toggle;
			if (ocean_intensity_toggle) { WATER::WAVE_INTENSITY(1.0f); }
			else { WATER::WAVE_INTENSITY(0.0f); }  break;
		case 6: Radaroff = !Radaroff; break;//For v1.5 update
		case 7: RevealAll = !RevealAll; break; //For v1.5 update
		case 8: PRINT("~r~DISABLED IDLE KICK", 4000); DisableIdleKick(); break;
		//case 9: send_global_to_host(); drawNotification("~y~Warning ~w~: ~HUD_COLOUR_BLUE~Do not Spam!!!"); break;
		case 9: changeSubmenu(texts); break;
		}
		break;
#pragma endregion
#pragma region Texts
	case texts:
		addTitle("Texts");
		addOption("Hey! Im Using Tiny Menu");
		addOption("Buy Tiny Menu! www.fazemodz.win");
		addOption("Hello");
		addOption("I wish I could mod");
		addOption("YouTube FaZeModz");
		addOption("Wassup");
		addOption("Yes!!");
		addOption("No");
		addOption("I can't do that yet Sorry");
		addOption("Come Hangout?");
		addKeyboardOption("Custom Message", keyboardAction, "Input Message", 16, NULL);
		addOption("Car meet?");
		//addOption("Custom Input");
		switch (getOption())
		{
		case 1: for (int i = 0; i < 18; i++) {
			if (!(cstrcmp(PLAYER::GET_PLAYER_NAME(i), "-")) && i != PLAYER::PLAYER_ID()) {
				sendText(i, "Hey! Im Using Tiny Menu", 7);
			}
		}
				break;
		case 2: for (int i = 0; i < 18; i++) {
			if (!(cstrcmp(PLAYER::GET_PLAYER_NAME(i), "-")) && i != PLAYER::PLAYER_ID()) {
				sendText(i, "Buy Tiny Menu! ~b~www.fazemodz.win", 7);
			}
		}
				break;
		case 3: for (int i = 0; i < 18; i++) {
			if (!(cstrcmp(PLAYER::GET_PLAYER_NAME(i), "-")) && i != PLAYER::PLAYER_ID()) {
				sendText(i, "Hello", 7);
			}
		} 
				//drawNotification("~HUD_COLOUR_FACEBOOK_BLUE~FACEBOOK BLUE TEST");//Hud Color Only Renders on Xbox
				break;
		case 4: for (int i = 0; i < 18; i++) {
			if (!(cstrcmp(PLAYER::GET_PLAYER_NAME(i), "-")) && i != PLAYER::PLAYER_ID()) {
				sendText(i, "I wish I could mod", 7);
			}
		}
				break;
		case 5:for (int i = 0; i < 18; i++) {
			if (!(cstrcmp(PLAYER::GET_PLAYER_NAME(i), "-")) && i != PLAYER::PLAYER_ID()) {
				sendText(i, "YouTube FaZe Modz", 7);
			}
		}
			   break;
		case 6:for (int i = 0; i < 18; i++) {
			if (!(cstrcmp(PLAYER::GET_PLAYER_NAME(i), "-")) && i != PLAYER::PLAYER_ID()) {
				sendText(i, "Wassup", 7);
			}
		}
			   break;
		case 7:for (int i = 0; i < 18; i++) {
			if (!(cstrcmp(PLAYER::GET_PLAYER_NAME(i), "-")) && i != PLAYER::PLAYER_ID()) {
				sendText(i, "Yes!!", 7);
			}
		}
			   break;
		case 8:for (int i = 0; i < 18; i++) {
			if (!(cstrcmp(PLAYER::GET_PLAYER_NAME(i), "-")) && i != PLAYER::PLAYER_ID()) {
				sendText(i, "No", 7);
			}
		}
			   break;
		case 9: for (int i = 0; i < 18; i++) {
			if (!(cstrcmp(PLAYER::GET_PLAYER_NAME(i), "-")) && i != PLAYER::PLAYER_ID()) {
				sendText(i, "I can't do that yet, sorry", 7);
			}
		}
				break;
		case 10: 
				for (int i = 0; i < 18; i++) {
					if (!(cstrcmp(PLAYER::GET_PLAYER_NAME(i), "-")) && i != PLAYER::PLAYER_ID()) {
						sendText(i, "Come Hangout?", 7);
					}
				}
				break;
		case 11:
			if (optionPress)
			{
				char buff[16];
				if (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 1)
				{
					char* Result = GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
					sprintf(buff, "%s", Result);
					for (int i = 0; i < 18; i++)
					{
						if (!(cstrcmp(PLAYER::GET_PLAYER_NAME(i), "-")) && i != PLAYER::PLAYER_ID()) {
							sendText(i, buff, 7);
						}
					}
				}
			}
			break;// Custom Input
		case 12: 
			for (int i = 0; i < 18; i++) {
				if (!(cstrcmp(PLAYER::GET_PLAYER_NAME(i), "-")) && i != PLAYER::PLAYER_ID()) {
					sendText(i, "Car meet?", 7);
				}
			}
			break;
		}
		break;
#pragma endregion
#pragma region Weather
	case weather:
		addTitle("Weather");
		addOption("Forward One Hour");
		addBoolOption("Freeze Clock Time", TimeStopped);
		addIntOption("Advanced Time", &time1, 0, 23, true);
		addOption("Real Snow");
		addOption("Snowing");
		addOption("Blizzard");
		addOption("Light Snow");
		addOption("Green Sky");
		addOption("Sunny");
		addOption("Clear");
		addOption("Cloudy");
		addOption("Foggy");
		addOption("Stormy");
		addOption("OverCast");
		switch (getOption())
		{
		case 1:
			int activeLineIndexTime = 0;
			int h = TIME::GET_CLOCK_HOURS();
			if (activeLineIndexTime == 0) h = (h == 23) ? 0 : h + 1;
			int m = TIME::GET_CLOCK_MINUTES();
			TIME::SET_CLOCK_TIME(h, m, 0);
			break;
		case 2:
			TimeStopped = !TimeStopped;
			TIME::PAUSE_CLOCK(TimeStopped);// Fixed in 4.5.0
			break;
		case 3: NETWORK::NETWORK_OVERRIDE_CLOCK_TIME(time1, TIME::GET_CLOCK_MINUTES(), TIME::GET_CLOCK_SECONDS()); break;
		case 4: *(unsigned int*)0x10953F8 = 0x60000000;
			*(unsigned int*)0x10953A4 = 0x60000000;
			*(unsigned int*)0x3D3EB0 = 0x60000000;
			GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("xmas");
			break;
		case 5: *(unsigned int*)0x10953F8 = 0x60000000;
			*(unsigned int*)0x10953A4 = 0x60000000;
			*(unsigned int*)0x3D3EB0 = 0x60000000;
			GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("SNOW");
			break;
		case 6:  *(unsigned int*)0x10953F8 = 0x60000000;
			*(unsigned int*)0x10953A4 = 0x60000000;
			*(unsigned int*)0x3D3EB0 = 0x60000000;
			GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("BLIZZARD");
			break;
		case 7: *(unsigned int*)0x10953F8 = 0x60000000;
			*(unsigned int*)0x10953A4 = 0x60000000;
			*(unsigned int*)0x3D3EB0 = 0x60000000;
			GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("SNOWLIGHT");
			break;
		case 8: *(unsigned int*)0x10953F8 = 0x60000000;
			*(unsigned int*)0x10953A4 = 0x60000000;
			*(unsigned int*)0x3D3EB0 = 0x60000000;
			GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("NEUTRAL");//Black & White Sky
			break;
		case 9: *(unsigned int*)0x10953F8 = 0x60000000;
			*(unsigned int*)0x10953A4 = 0x60000000;
			*(unsigned int*)0x3D3EB0 = 0x60000000;
			GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("EXTRASUNNY");
			break;
		case 10: *(unsigned int*)0x10953F8 = 0x60000000;
			*(unsigned int*)0x10953A4 = 0x60000000;
			*(unsigned int*)0x3D3EB0 = 0x60000000;
			GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("CLEAR");
			break;
		case 11: *(unsigned int*)0x10953F8 = 0x60000000;
			*(unsigned int*)0x10953A4 = 0x60000000;
			*(unsigned int*)0x3D3EB0 = 0x60000000;
			GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("CLOUDS");
			break;
		case 12: *(unsigned int*)0x10953F8 = 0x60000000;
			*(unsigned int*)0x10953A4 = 0x60000000;
			*(unsigned int*)0x3D3EB0 = 0x60000000;
			GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("FOGGY");
			break;
		case 13: *(unsigned int*)0x10953F8 = 0x60000000;
			*(unsigned int*)0x10953A4 = 0x60000000;
			*(unsigned int*)0x3D3EB0 = 0x60000000;
			GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("THUNDER");
			break;
		case 14:
			*(unsigned int*)0x10953F8 = 0x60000000;
			*(unsigned int*)0x10953A4 = 0x60000000;
			*(unsigned int*)0x3D3EB0 = 0x60000000;
			GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("OVERCAST");
			break;
		}
		break;
#pragma endregion
#pragma region Vehicle Spawner
	case Vehicle_spawner:
		addTitle("Vehicle List");
		for (int i = 0; i < sizeof(g_pcMainMenu) / 4; i++)
		{
			addSubmenuOption(g_pcMainMenu[i], Vehicle_spawner + (i + 1));
		}
		//addOption("Spawn adder");
		//addOption("spawn Entity");
		switch (getOption())// How a Vehicle Lists looks without an Array
		{
			//case 1: create_vehicle("adder"); break;
			//case 2: create_vehicle(0x206D1B68, "Entity"); break;//Ask Pb how this works with adding Parameter char Vehicle to Definition
		}
		break;
#pragma endregion	
#pragma region All Vehicles
	case Vehicle_spawner + 1://copy & Paste this 
		addTitle("Super");
		for (int i = 0; i < sizeof(g_pcSuperCars) / 4; i++)
		{
			addOption(g_pcSuperCars[i]);
		}
		if (optionPress)
		{
			vehiclecatagories = 0;
			creatvehiclenow = 1;
			//add If player is in a vehicle statement to this .. dummy
			DeleteVehicle(PLAYER::PLAYER_PED_ID());
		} break;
	case Vehicle_spawner + 2:
		addTitle("Sports");
		for (int i = 0; i < sizeof(g_pcSportsCars) / 4; i++)
		{
			addOption(g_pcSportsCars[i]);
		}
		if (optionPress)
		{
			vehiclecatagories = 1;
			creatvehiclenow = 1;
			DeleteVehicle(PLAYER::PLAYER_PED_ID());
		} break;
#pragma region Sports classic
	case Vehicle_spawner + 3:
		addTitle("Sports Classic");
		for (int i = 0; i < sizeof(g_pcSportsClassicCars) / 4; i++)
		{
			addOption(g_pcSportsClassicCars[i]);
		}
		if (optionPress)
		{
			vehiclecatagories = 2;
			creatvehiclenow = 1;
			DeleteVehicle(PLAYER::PLAYER_PED_ID());
		} break;
#pragma endregion
	case Vehicle_spawner + 4:
		addTitle("Muscle");
		for (int i = 0; i < sizeof(g_pcMuscleCars) / 4; i++)
		{
			addOption(g_pcMuscleCars[i]);
		}
		if (optionPress)
		{
			vehiclecatagories = 3;
			creatvehiclenow = 1;
			DeleteVehicle(PLAYER::PLAYER_PED_ID());
		} break;
	case Vehicle_spawner + 5:
		addTitle("Sedans");
		for (int i = 0; i < sizeof(g_pcSedans) / 4; i++)
		{
			addOption(g_pcSedans[i]);
		}
		if (optionPress)
		{
			vehiclecatagories = 4;
			creatvehiclenow = 1;
			DeleteVehicle(PLAYER::PLAYER_PED_ID());
		} break;
	case Vehicle_spawner + 6:
		addTitle("Sedans");
		for (int i = 0; i < sizeof(g_pcCoupes) / 4; i++)
		{
			addOption(g_pcCoupes[i]);
		}
		if (optionPress)
		{
			vehiclecatagories = 5;
			creatvehiclenow = 1;
			DeleteVehicle(PLAYER::PLAYER_PED_ID());
		} break;
	case Vehicle_spawner + 7:
		addTitle("Compacts");
		for (int i = 0; i < sizeof(g_pcCompacts) / 4; i++)
		{
			addOption(g_pcCompacts[i]);
		}
		if (optionPress)
		{
			vehiclecatagories = 6;
			creatvehiclenow = 1;
			DeleteVehicle(PLAYER::PLAYER_PED_ID());
		} break;
	case Vehicle_spawner + 8:
		addTitle("Trucks");
		for (int i = 0; i < sizeof(g_pcSUVnTrucks) / 4; i++)
		{
			addOption(g_pcSUVnTrucks[i]);
		}
		if (optionPress)
		{
			vehiclecatagories = 7;
			creatvehiclenow = 1;
			DeleteVehicle(PLAYER::PLAYER_PED_ID());
		} break;
	case Vehicle_spawner + 9:
		addTitle("Off Road");
		for (int i = 0; i < sizeof(g_pcOffRoads) / 4; i++)
		{
			addOption(g_pcOffRoads[i]);
		}
		if (optionPress)
		{
			vehiclecatagories = 8;
			creatvehiclenow = 1;
			DeleteVehicle(PLAYER::PLAYER_PED_ID());
		} break;
	case Vehicle_spawner + 10:
		addTitle("Vans");
		for (int i = 0; i < sizeof(g_pcVans) / 4; i++)
		{
			addOption(g_pcVans[i]);
		}
		if (optionPress)
		{
			vehiclecatagories = 9;
			creatvehiclenow = 1;
			DeleteVehicle(PLAYER::PLAYER_PED_ID());
		} break;
	case Vehicle_spawner + 11:
		addTitle("Emergency");
		for (int i = 0; i < sizeof(g_pcEmergencyCars) / 4; i++)
		{
			addOption(g_pcEmergencyCars[i]);
		}
		if (optionPress)
		{
			vehiclecatagories = 10;
			creatvehiclenow = 1;
			DeleteVehicle(PLAYER::PLAYER_PED_ID());
		} break;
	case Vehicle_spawner + 12:
		addTitle("Service");
		for (int i = 0; i < sizeof(g_pcServicVehicles) / 4; i++)
		{
			addOption(g_pcServicVehicles[i]);
		}
		if (optionPress)
		{
			vehiclecatagories = 11;
			creatvehiclenow = 1;
			DeleteVehicle(PLAYER::PLAYER_PED_ID());
		} break;
	case Vehicle_spawner + 13:
		addTitle("Military");
		for (int i = 0; i < sizeof(g_pcMilitary) / 4; i++)
		{
			addOption(g_pcMilitary[i]);
		}
		if (optionPress)
		{
			vehiclecatagories = 12;
			creatvehiclenow = 1;
			DeleteVehicle(PLAYER::PLAYER_PED_ID());
		} break;
	case Vehicle_spawner + 14:
		addTitle("Motorcycle");
		for (int i = 0; i < sizeof(g_pcMotorcycles) / 4; i++)
		{
			addOption(g_pcMotorcycles[i]);
		}
		if (optionPress)
		{
			vehiclecatagories = 13;
			creatvehiclenow = 1;
			DeleteVehicle(PLAYER::PLAYER_PED_ID());
		} break;
	case Vehicle_spawner + 15:
		addTitle("Cycles");
		for (int i = 0; i < sizeof(g_pcBicycles) / 4; i++)
		{
			addOption(g_pcBicycles[i]);
		}
		if (optionPress)
		{
			vehiclecatagories = 14;
			creatvehiclenow = 1;
			DeleteVehicle(PLAYER::PLAYER_PED_ID());
		} break;
	case Vehicle_spawner + 16:
		addTitle("Commercial");
		for (int i = 0; i < sizeof(g_pcCommercialVehicles) / 4; i++)
		{
			addOption(g_pcCommercialVehicles[i]);
		}
		if (optionPress)
		{
			vehiclecatagories = 15;
			creatvehiclenow = 1;
			DeleteVehicle(PLAYER::PLAYER_PED_ID());
		} break;
	case Vehicle_spawner + 17:
		addTitle("Helicopters");
		for (int i = 0; i < sizeof(g_pcHelicopters) / 4; i++)
		{
			addOption(g_pcHelicopters[i]);
		}
		if (optionPress)
		{
			vehiclecatagories = 16;
			creatvehiclenow = 1;
			DeleteVehicle(PLAYER::PLAYER_PED_ID());
		} break;
	case Vehicle_spawner + 18:
		addTitle("Planes");
		for (int i = 0; i < sizeof(g_pcPlanes) / 4; i++)
		{
			addOption(g_pcPlanes[i]);
		}
		if (optionPress)
		{
			vehiclecatagories = 17;
			creatvehiclenow = 1;
			DeleteVehicle(PLAYER::PLAYER_PED_ID());
		} break;
	case Vehicle_spawner + 19:
		addTitle("Boats");
		for (int i = 0; i < sizeof(g_pcBoats) / 4; i++)
		{
			addOption(g_pcBoats[i]);
		}
		if (optionPress)
		{
			vehiclecatagories = 18;
			creatvehiclenow = 1;
			DeleteVehicle(PLAYER::PLAYER_PED_ID());
		} break;
	case Vehicle_spawner + 20:
		addTitle("Trailers");
		for (int i = 0; i < sizeof(g_pcTrailers) / 4; i++)
		{
			addOption(g_pcTrailers[i]);
		}
		if (optionPress)
		{
			vehiclecatagories = 19;
			creatvehiclenow = 1;
			DeleteVehicle(PLAYER::PLAYER_PED_ID());
		} break;
#pragma endregion
#pragma region Vehicle Options
	case Vehicle_Mods:
		addTitle("Vehicle Modz");
		addSubmenuOption("UnderGlow", Neons);
		//addSubmenuOption("Special Cars", Modded_Vehicles);
		addOption("Boost Forwards"); //Fixed Thanks the TheRouletteBoi (:
		addOption("Boost Backwards");
		addOption("Fix Vehicle");
		addOption("Flip Vehicle");
		addOption("Rainbow Car");
		addOption("Max Upgrades");
		addBoolOption("GodMode Car", godmodeveh);
		addBoolOption("Fly Car", fcar); //case 9
		addFunBool("Drive On Water", &driveonwater, 1, donwater);
		//addBoolOption("Horn Boost", VehicleNOS); No Idea why its not working
		addBoolOption("Square To Drift", &driftmod);
		addOption("KickFLip");
		addOption("BackFLip");
		addOption("Open / Close Doors");
		addBoolOption("Fuel Mod", RealCarModBool);
		addOption("Delete Vehicle");
		addSubmenuOption("Fuel Mod options", fuelmodoptions);
		addSubmenuOption("Button Shortcuts", vehiclebinds);
		//addOption("Drive Rollercoaster ~w~[BETA]");
		//addOption("Ejector Seat");
		switch (getOption())
		{
		case 2: BoostVehicleForward(); break; // () is for Functions
		case 3: BoostVehicleBackward(); break;
		case 4: FixVehicle(); break;
		case 5: FlipVehicle(); break;
		case 6: RainbowCar(); break;
		case 7: maxupgrades(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false)); break;
		case 8: godmodeveh = !godmodeveh; break;
		case 9: fcar = !fcar;  break;
		case 10: donwater = !donwater;
			Entity pp = PLAYER::PLAYER_PED_ID();
			if (PED::IS_PED_IN_ANY_VEHICLE(pp, 0)) {
				pp = PED::GET_VEHICLE_PED_IS_USING(pp);
			}
			Vector3 c = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(pp, 0, 7, 0);
			if (!donwater) {
				ENTITY::SET_ENTITY_AS_MISSION_ENTITY(floatation, 1, 1);
				OBJECT::DELETE_OBJECT(&floatation);
			}
			else {
				floatation = OBJECT::CREATE_OBJECT(-1281648158, c.x, c.y, c.z, 1, 0, 0);
				ENTITY::SET_ENTITY_AS_MISSION_ENTITY(floatation, true, true);
				invwater = true;
			}
			break;
		case 11: break;
			//case 11: VehicleNOS = !VehicleNOS; break;
			//case 12: ejectorseat(); break;
		case 12:ENTITY::APPLY_FORCE_TO_ENTITY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), 1, 0.0, 0.0, 10.71, 5.0, 0.0, 0.0, 1, false, true, true, true, true); break;
		case 13:ENTITY::APPLY_FORCE_TO_ENTITY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), 1, 0.0, 0.0, 6.0, 0.0, 3.0, 0.0, 1, false, true, true, true, true); break;
		//case 15: dorollercoaster = true; break;
		case 14: DoorsOpen = !DoorsOpen; break;
		case 15: RealCarModBool = !RealCarModBool;
			if (RealCarModBool)
			{
				GUI_init();
			}
			else
			{
				GUI_unload();
			}
			break;
		case 16: // Code Under review.. Freezes Hen Users.. removed in 4.0.0 
			if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 1) == false)
			{
				ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(PED::GET_VEHICLE_PED_IS_IN1(PLAYER::PLAYER_PED_ID(), 1));
				VEHICLE::DELETE_VEHICLE(PED::GET_VEHICLE_PED_IS_IN1(PLAYER::PLAYER_PED_ID(), 1));
				PRINT("~HUD_COLOUR_GREEN~Vehicle Deleted Successfully!");
			}
			else
			{
				PRINT("~r~MUST BE IN A VEHICLE", 4000);
			}
		}
		break;
#pragma endregion
#pragma region fuelmodoptions
	case fuelmodoptions:
		addTitle("Fuel Mod Menu");
		addIntOption("F_Bar Red", &FuelFullBarRed, 0, 255, true);
		addIntOption("F_Bar Blue", &FuelFullBarGreen, 0, 255, true);
		addIntOption("F_Bar Green", &FuelFullBarBlue, 0, 255, true);
		addIntOption("F_Bar Opacity", &FuelFullBarOpacity, 0, 255, true);
		addIntOption("F_Bar Layer 2 R", &FuelseclayerR, 0, 255, true);
		addIntOption("F_Bar Layer 2 G", &FuelseclayerG, 0, 255, true);
		addIntOption("F_Bar Layer 2 B", &FuelseclayerB, 0, 255, true);
		break;
#pragma endregion
#pragma region VehBinds
	case vehiclebinds: 
		addTitle("Vehicle Binds");
		addBoolOption("Fix Vehicle [D-Pad Left]", leftfix);
		addBoolOption("Scorch Vehicle [D-Pad Down]", downscorch);
		switch (getOption())
		{
		case 1:
			leftfix = !leftfix; break;
		case 2: 
			downscorch = !downscorch; break;
		}
		break;
#pragma endregion
#pragma region Neons
	case Neons:
		addTitle("Neons");
		addBoolOption("Togle", HasNeons);
		addOption("Red");
		addOption("Green");
		addOption("Blue");
		addOption("Orange");
		addOption("White");
		addOption("Yellow");
		addOption("Pink");
		addOption("Purple");
		switch (getOption())
		{
		case 1:
			if (HasNeons)
				HasNeons = false;
			else
				HasNeons = true; break;
		case 2:
			hasLoopNeon = false;
			NeonR = 255;
			NeonG = 0;
			NeonB = 0; break;
		case 3:
			hasLoopNeon = false;
			NeonR = 0;
			NeonG = 255;
			NeonB = 0; break;
		case 4:
			hasLoopNeon = false;
			NeonR = 0;
			NeonG = 0;
			NeonB = 255; break;
		case 5:
			hasLoopNeon = false;///
			NeonR = 255;
			NeonG = 155;
			NeonB = 0; break;
		case 6:
			hasLoopNeon = false;///
			NeonR = 255;
			NeonG = 255;
			NeonB = 255; break;
		case 7:
			hasLoopNeon = false;///
			NeonR = 255;
			NeonG = 255;
			NeonB = 0; break;
		case 8:
			hasLoopNeon = false;///
			NeonR = 255;
			NeonG = 0;
			NeonB = 255; break;
		case 9:
			hasLoopNeon = false;///
			NeonR = 150;
			NeonG = 0;
			NeonB = 255; break;

		}
		break;
#pragma endregion
#pragma region Modded Vehicles
	case Modded_Vehicles:
	addTitle("*Modded Vehicles");
	addOption("Boat And Trailer");
	addOption("FlatBed And Special");
	addOption("Guardian And ATV");
	addOption("JetSki And Trailer");
	addOption("Ramp Truck");
	addOption("Monster Swat");
	addOption("Buffulo Police");
	addOption("Super 1");
	addOption("Super 2");
	addOption("Muscle 1");
	addOption("Muscle 2");
	addOption("Special");
	addOption("Sub Copter");
	addOption("SlamVan");
	addOption("Flying 5 Seater");
	addOption("Panto/HotKnife");
	addOption("Monster Digger");
	addOption("Train");
	addOption("Classic Car Mix");
	addOption("Special Insurgent");
	switch (getOption())
	{
	case 1: doBoatNTrailer = true; break;
	case 2: doFlatBed = true; break;
	case 3: doTruck = true; break;
	case 4: doJetSki = true; break;
	case 5: doRampTruck = true; break;
	case 6: doBusTruck = true; break;
	case 7: doBufCustom = true; break;
	case 8: doSuper1 = true; break;
	case 9: doSuper2 = true; break;
	case 10: doMuscle1 = true; break;
	case 11: doMuscle2 = true; break;
	case 12: doSpecial1 = true; break;
	case 13: doSpecial2 = true; break;
	case 14: doSpecial3 = true; break;
	case 15: doSpecial4 = true; break;
	case 16: doSpecial5 = true; break;
	case 17: doSpecial7 = true; break;
	case 18: doSpecial8 = true; break;
	case 19: doSpecial9 = true; break;
	case 20: doInsurg = true; break;
	}
	break;
#pragma endregion
#pragma region Teleport Menu 
	case Teleport_menu:
		addTitle("Teleport Menu");
		addOption("teleport to Waypoint");
		addOption("teleport to Mors Mutual");
		addTeleportOption("Teleport to Bank Vault", 255.5819, 217.6896, 101.6834);//Different way to do it (::
		addOption("Teleport to  Nearest Car");
		addOption("Teleport 2 Meters Forward");
		addOption("Teleport 2 Meters Up");
		addIntTeleportOption("Generel Locations", teleloctypes, &teletypes, 0, 11);
		addIntTeleportOption("Special Locations", Steleloctypes, &Steletypes, 0, 8);
		switch (getOption())
		{
		case 1: TPtoWaypoint(); break;
		case 2: TeleportToLoc(-240.0677, -1164.9530, 23.0176);  break;
		case 3: break;
		case 4: ToNearestCar(); break;
		case 5: {
			Vector3 Coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS1(PLAYER::PLAYER_PED_ID(), 0.0, 2.0, 0.0);
			int Handle = PLAYER::PLAYER_PED_ID();
			if (PED::IS_PED_IN_ANY_VEHICLE(Handle, 0))Handle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(Handle, Coords.x, Coords.y, Coords.z, 0, 0, 1);
		}
				break;
		case 6: {
			Vector3 Coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS1(PLAYER::PLAYER_PED_ID(), 0.0, 0.0, 2.0);
			int Handle = PLAYER::PLAYER_PED_ID();
			if (PED::IS_PED_IN_ANY_VEHICLE(Handle, 0))Handle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(Handle, Coords.x, Coords.y, Coords.z, 0, 0, 1);
		}
				break;
		case 7:
			switch (teletypes) { 
			case 0: mair(); break;
			case 1: mchil(); break;
			case 2: mbank(); break;
			case 3: tafield(); break;
			case 4: fzan(); break;
			case 5: lsc(); break;
			case 6: mshop(); break;
			case 7: cshop(); break;
			case 8: ashop(); break;
			case 9: hstand(); break;
			case 10: ttrailer(); break;
			case 11: crane(); break;
			}
			break;
		case 8:
			switch (Steletypes) {
			case 0: ifib(); break;
			case 1: rfib(); break;
			case 2: fwheel(); break;
			case 3: bbeam(); break;
			case 4: ctower(); break;
			case 5: mhouse(); break;
			case 6: fnhouse(); break;
			case 7: fohouse(); break;
			case 8: woffice(); break;
			}
			break;

		}
		break;
		
#pragma endregion 
#pragma region Settings
	case Settings:
		addTitle("Settings");
		addSubmenuOption("Menu Customizations", Customizemenu);
		addBoolOption("Sounds", menuSounds);
		//addIntOption("Fast Scroll Speed", &fastScrollSpeed, 1, 8, true);
		//addBoolOption("Instructions", instructions);
		switch (getOption())
		{
		case 2: menuSounds = !menuSounds; break;
		//case 4: break;
		//case 2: instructions = !instructions; break;
		}
		break;
#pragma endregion
#pragma region Customization Menu
	case Customizemenu:
		addTitle("Custom Menu");
		//Base 
		addIntOption("Banner Text Red", &MenuColour_R, 0, 255, true);
		addIntOption("Banner Text Green", &MenuColour_G, 0, 255, true);
		addIntOption("Banner Text Blue", &MenuColour_B, 0, 255, true);
		//addIntOption("Banner Text Opacity", &bannerTextOpacity, 0, 255, true);
		//addIntOption("Banner Text Font", &bannerTextFont, 0, 7, false); //Might Add This Later As An Option
		//Text
		addIntOption("Text Red", &optionsRed, 0, 255, true);
		addIntOption("Text Green", &optionsGreen, 0, 255, true);
		addIntOption("Text Blue", &optionsBlue, 0, 255, true);
		//addIntOption("Text Opacity", &optionsOpacity, 0, 255, true);
		//addIntOption("Text Font", &optionsFont, 0, 7, false); //Might Add This Later As An Option
		addIntOption("Menu Red", &backgroundRed, 0, 255, true);
		addIntOption("Menu Green", &backgroundGreen, 0, 255, true);
		addIntOption("Menu Blue", &backgroundBlue, 0, 255, true);
		addIntOption("Star Red", &spritered, 0, 255, true);
		addIntOption("Star Blue", &spriteblue, 0, 255, true);
		addIntOption("Star Green", &spritegreen, 0, 255, true);
		//addFloatOption1("Adjust Menu Y", &menuYCoord, 0.000f, 1.0f, true, 0.015);
		//addFloatOption1("Adjust Menu X", &menuXCoord, 0.000f, 1.0f, true, 0.015);
		//addIntOption("Star Opacity", &spriteopacity, 0, 255, true);
		//addIntOption("Menu Opacity", &backgroundOpacity, 0, 255, true);
		switch (getOption())
		{
			//addIntOption's dont use cases :p
		}
		break;
#pragma endregion
#pragma region Protection Defintions
		
#pragma endregion
#pragma region Protections
	case mddrprotect:
		addTitle("Protections");
		addBoolOption("Non Host Kick", &bool_eventp[0]);
		addBoolOption("Fake Leave", &bool_eventp[1]);
		addBoolOption("Rank", &bool_eventp[3]);
		addBoolOption("Give Money", &bool_eventp[4]);
		addBoolOption("Apartment Invite", &bool_eventp[5]);
		addBoolOption("Game Invite", &bool_eventp[6]);
		addBoolOption("Job Invite", &bool_eventp[7]);
		addBoolOption("Time", &bool_eventp[16]);
		addBoolOption("Weather", &bool_eventp[17]);
		addBoolOption("Clear Task", &bool_protection[3]);
		addBoolOption("Take / Give Weapons", &bool_protection[4]);
		addBoolOption("Animation / Teleport", &bool_protection[5]);
		addBoolOption("Alter Wanted Lvl", &bool_protection[6]);
		addBoolOption("Particle FX", &bool_protection[7]);
		addBoolOption("Weather Protection", weatherpro);
		addBoolOption("Player Aim Protection", BossMode);
		addBoolOption("Freeze Protection", adminkickprotect); // 	*(unsigned int*)0x9FBBC8 = 0x60000000;  *(unsigned int*)0x9FBBCC = 0x60000000;  *(unsigned int*)0x9FBA00 = 0x60000000;
		addBoolOption("Drop Kick Protection", dropkickpro);
		addBoolOption("Jaro Freeze Protection", jaro666);// 4.5.0 release
		switch (getOption())
		{
		case 1:
			*(int*)0x12D1A50 = bool_eventp[0] ? 0x4E800020 : 0x7C0802A6;//non host kick
			break;
		case 2:
			*(int*)0x12C2988 = bool_eventp[1] ? 0x4E800020 : 0x7C0802A6;//fake leave
			break;
		case 3:
			*(int*)0x12D1E28 = bool_eventp[3] ? 0x4E800020 : 0x7C0802A6;//rank
			break;
		case 4:
			*(int*)0x12CB55C = bool_eventp[4] ? 0x4E800020 : 0x7C0802A6;//money
			break;
		case 5:
			*(int*)0x12C3C74 = bool_eventp[5] ? 0x4E800020 : 0x7C0802A6;//aprtment invites
			*(int*)0x12CB198 = bool_eventp[5] ? 0x4E800020 : 0x7C0802A6;
			*(int*)0x12CB70C = bool_eventp[5] ? 0x4E800020 : 0x7C0802A6;
			*(int*)0x12CB930 = bool_eventp[5] ? 0x4E800020 : 0x7C0802A6;
			break;
		case 6:
			*(int*)0x12C8D60 = bool_eventp[6] ? 0x4E800020 : 0x7C0802A6;//game invites
			break;
		case 7:
			*(int*)0x12C5638 = bool_eventp[7] ? 0x4E800020 : 0x7C0802A6;//job invites
			*(int*)0x12D5098 = bool_eventp[7] ? 0x4E800020 : 0x7C0802A6;
			*(int*)0x12BD36C = bool_eventp[7] ? 0x4E800020 : 0x7C0802A6;
			break;
		case 8:
			*(int*)0x12BDFCC = bool_eventp[16] ? 0x4E800020 : 0x7C0802A6;//time 
			break;
		case 9:
			*(int*)0x12D5098 = bool_eventp[17] ? 0x4E800020 : 0x7C0802A6;//weather
			break;
		case 10:
			*(int*)0x12CC958 = bool_protection[3] ? 0x4E800020 : 0x7C0802A6;//clear task
			break;
		case 11:
			*(int*)0x12D0584 = bool_protection[4] ? 0x4E800020 : 0x7C0802A6;//weapons
			*(int*)0x12C3ACC = bool_protection[4] ? 0x4E800020 : 0x7C0802A6;
			*(int*)0x12C37EC = bool_protection[4] ? 0x4E800020 : 0x7C0802A6;
			break;
		case 12:
			*(int*)0x12C3C74 = bool_protection[5] ? 0x4E800020 : 0x7C0802A6;//animation teleport
			*(int*)0x12CB198 = bool_protection[5] ? 0x4E800020 : 0x7C0802A6;
			*(int*)0x12CB70C = bool_protection[5] ? 0x4E800020 : 0x7C0802A6;
			*(int*)0x12CB930 = bool_protection[5] ? 0x4E800020 : 0x7C0802A6;
			break;
		case 13:
			*(int*)0x12C78DC = bool_protection[6] ? 0x4E800020 : 0x7C0802A6;//wanted lvl
			break;
		case 14:
			*(int*)0x12C5638 = bool_protection[7] ? 0x4E800020 : 0x7C0802A6;//animation
			*(int*)0x12D5098 = bool_protection[7] ? 0x4E800020 : 0x7C0802A6;
			*(int*)0x12BD36C = bool_protection[7] ? 0x4E800020 : 0x7C0802A6;
			break;
		case 15:
			weatherpro = !weatherpro; break;//Game Weather Event Protection
		case 16:
			BossMode = !BossMode; break; //Aim Protections From Players :p UPDATE 1.5.9
		case 17: 
			adminkickprotect = !adminkickprotect; break;
		case 18: 
			dropkickpro = !dropkickpro; break;
		case 19: 
			jaro666 = !jaro666; break;
		}
		break;
#pragma endregion
#pragma region Script Manager
		case scriptmanager:
			{
				char *scriptName = "fm_deathmatch_creator";
				SCRIPT::REQUEST_SCRIPT(scriptName);
				addTitle("Script Manager");
				addOption("Display Instructions");
				//addBoolOption("Toggle Script", isScriptRunning(scriptName));// CSCcallScript
				addOption("Toggle Script");
				addIntOption("Set Stack Size", &stacksize, 0, 32000, true);
				bool direxists = readDir("/dev_hdd0/tmp/TinyMenu/CSC", &callback_read_directories_scripts);
				if (direxists == DIRECTORY_INVALID) {
					addOption("Folder does not exist!");
				}
				if (direxists == 0) {
					addOption("Create Folder /dev_hdd0/tmp/TinyMenu/CSC");
				}
				switch (getOption())
				{
				case 1: TopLeftInstructionBox("Create Directory ~n~/dev_hdd0/tmp/TinyMenu/CSC~n~and add your scripts"); break;
				case 2: ToggleScript(scriptName, (int)stacksize, &lastLoadedScript); break;
				case 3: PRINT("Stack Size set"); break;
				}
				break;
			}
#pragma endregion
#pragma region Scenarios
	case Player_scenes:
		addTitle("Scenarios");
		for (int i = 0; i < sizeof(ScenariosMenu) / 4; i++)
		{
			addOption(ScenariosMenu[i]);
		}
		if (optionPress) {
			for (ScenariosVar = 0; ScenariosVar < sizeof(ScenariosChar) / 4; ScenariosVar++)
			{
				STREAMING::REQUEST_ANIM_DICT(ScenarioDict);
				if (STREAMING::HAS_ANIM_DICT_LOADED(ScenarioDict)) {
					AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), ScenariosChar[ScenariosVar], 0, 1);
				}	
			}
		}
		if (CONTROLS::IS_CONTROL_JUST_PRESSED(0, Button_X)) {
			bool once = true;
			if (once)
			{
				if (AI::IS_PED_ACTIVE_IN_SCENARIO(PLAYER::PLAYER_PED_ID()))
				{
					AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::PLAYER_PED_ID());
				}
				once = false;
			}
		}
		break;
#pragma endregion
#pragma region Recovery
	case recovery:
		addTitle("Recovery");
		addSubmenuOption("Money Menu", money);
		addSubmenuOption("Rank Menu", ranksub);
		addSubmenuOption("Outfits", outfits);
		addSubmenuOption("Misc", Extras);
		addSubmenuOption("Tunables", tunables);
		addOption("MaxSkills");//case 1
		addOption("Unlock All LSC");
		addOption("Unlock All Weapon Camos");
		addOption("Unlock All Weapons");
		addOption("Unlimted Ammo");
		addOption("Unlock All Trophies");//case 6
		switch (getOption())
		{
		case 29: MaxSkills(); break;
		case 30: UnlockAllLSC(); break;
		case 31: UnlockAllWeaponCamos(); break;
		case 32: BuyAllGuns(); break;
		case 33: UnlimitedAmmo2(); break;
		case 34: alltrophies(); break;
		}
		break;
#pragma endregion
#pragma region Recovery Tunables
	case tunables:
		addTitle("Tunables");
		addOption("No IDE Kick");
		addOption("Free Stores");
		addOption("No Betting Limit");
		addOption("No LSC Cap");
		addBoolOption("Valentine DLC", Tunable_Valentines);
		addBoolOption("Independance DLC", Tunable_Independance);
		addBoolOption("New Years DLC", Tunable_NY);
		addBoolOption("Christmas DLC", Tunable_XMas);
		addBoolOption("Christmas Snow", Tunable_Snow);
		switch (getOption())
		{
		case 1:
			Func::SetTunable(71, 0x00000001);
			Func::SetTunable(72, 0x00000001);
			Func::SetTunable(73, 0x00000001);
			break;
		case 2:
			Func::SetTunable(58, 0x00000000);
			Func::SetTunable(60, 0x00000000);
			Func::SetTunable(60, 0x00000000);
			Func::SetTunable(61, 0x00000000);
			Func::SetTunable(63, 0x00000000);
			Func::SetTunable(64, 0x00000000);
			Func::SetTunable(65, 0x00000000);
			Func::SetTunable(66, 0x00000000);
			Func::SetTunable(67, 0x00000000);
			break;
		case 3:
			Func::SetTunable(82, 0x05F5E0FF);
			break;
		case 4:
			Func::SetTunable(142, 0x05F5E0FF);
			break;
		case 5:
			if (Tunable_Valentines == false)
			{
				Tunable_Valentines = true;
				Func::SetTunable(4824, 0x00000000);
			}
			else if (Tunable_Valentines == true)
			{
				Tunable_Valentines = false;
				Func::SetTunable(4824, 0x00000001);
			}
			break;
		case 6:
			if (Tunable_Independance == false)
			{
				Func::SetTunable(6000, 0x00000001);
				Func::SetTunable(6008, 0x00000000);
				Func::SetTunable(6014, 0x00000001);
				Func::SetTunable(6046, 0x00000001);
				Tunable_Independance = true;
			}
			else if (Tunable_Independance == true)
			{
				Func::SetTunable(6000, 0x00000000);
				Func::SetTunable(6008, 0x00000001);
				Func::SetTunable(6014, 0x00000000);
				Func::SetTunable(6046, 0x00000000);
				Tunable_Independance = false;
			}
			break;
		case 7:
			if (Tunable_NY == false)
			{
				Func::SetTunable(6926, 0x00000000);
				Func::SetTunable(6927, 0x00000000);
				Tunable_NY = true;
			}
			else if (Tunable_NY == true)
			{
				Func::SetTunable(6926, 0x00000001);
				Func::SetTunable(6927, 0x00000001);
				Tunable_NY = false;
			}
			break;
		case 8:
			if (Tunable_XMas == false)
			{
				Func::SetTunable(6870, 0x00000000);
				Func::SetTunable(6871, 0x00000000);
				Func::SetTunable(6874, 0x00000000);
				Func::SetTunable(6875, 0x00000000);
				Func::SetTunable(6876, 0x00000000);
				Tunable_XMas = true;
			}
			else if (Tunable_XMas == true)
			{
				Func::SetTunable(6870, 0x00000001);
				Func::SetTunable(6871, 0x00000001);
				Func::SetTunable(6874, 0x00000001);
				Func::SetTunable(6875, 0x00000001);
				Func::SetTunable(6876, 0x00000001);
				Tunable_XMas = false;
			}
			break;
		case 9:
			Tunable_Snow = !Tunable_Snow;
			if (Tunable_Snow == false)
			{
				Func::SetTunable(4715, 0);
			}
			else if (Tunable_Snow == true)
			{
				Func::SetTunable(4715, 1);
			}
			break;
		}
		break;
#pragma endregion
#pragma region Money Menu
	case money:
		addTitle("Money Menu");
		addIntOption("Give Money", &moneyAmount, 1, 10000000, true);
		addIntOption("Remove Money", &deductAmount, 1, 1000000000, true, "Positive Number");
		addOption("Give 1Million");
		addOption("Give 10Million");
		addOption("Give 30Million");
		addOption("Give 60Million");
		addOption("Give 90Million");
		addOption("Give 100Million");
		addOption("Remove 10 Millions");
		addOption("Remove 20 Millions");
		switch (getOption())
		{
		case 1: giveMoney(moneyAmount); break;
		case 2: deductMoney(); break;
		case 3:Cash1Million(); break;
		case 4:Cash10Million(); break;
		case 5:Cash30Million(); break;
		case 6:Cash60Million(); break;
		case 7:Cash90Million(); break;
		case 8:Cash100Million(); break;
		case 9:NETWORKCASH::NETWORK_SPENT_CASH_DROP2(10000000); break;
		case 10:NETWORKCASH::NETWORK_SPENT_CASH_DROP2(20000000); break;
		}
		break;
#pragma endregion
#pragma region Rank Menu
	case ranksub:
		addTitle("Custom Rank");
		addOption("Rank 1");
		addOption("Rank 120");
		addOption("Rank 8000");
		addOption("Rank 999");
		addOption("Rank 400");
		addOption("Rank 1337");
		addOption("Rank 900");
		addOption("Rank 1202");//case 13
		switch (getOption())
		{
		case 11: Rank1(); break;
		case 12: Rank120(); break;
		case 13: Rank8000(); break;
		case 14: Rank999(); break;
		case 15: Rank400(); break;
		case 16: Rank1337(); break;
		case 17: Rank900(); break;
		case 18: Rank1202(); break;
		}
		break;
#pragma endregion
#pragma region outfits
	case outfits:
		addTitle("Outfits");
		addSubmenuOption("Page 2---->", more_outfits);
		addOption("Santa");
		addOption("Elf");
		addOption("Snowman");
		addOption("Police Outfit");
		addOption("R3AP3R");
		addOption("BiG_GHOST_GaMeR");
		addOption("PBMODZ");
		addOption("VampDaily");
		addOption("Penguin Outfit");
		addOption("Splinter Cell");
		addOption("Pilot");
		addOption("Special Ops");
		addOption("Balla's Gang");
		addOption("Elf 2");
		addOption("Thug");
		addOption("Santa 2");
		addOption("Snowman 2");
		addOption("Invisible");//case 18
		switch (getOption())
		{
		case 2:
			changeAppearance("MASK", 8, 0);
			changeAppearance("TORSO", 12, 0);
			changeAppearance("LEGS", 19, 0);
			changeAppearance("SHOES", 4, 4);
			changeAppearance("SPECIAL1", 10, 0);
			changeAppearance("SPECIAL2", 21, 2);
			changeAppearance("TORSO2", 19, 0); break;
		case 3:
			changeAppearance("MASK", 34, 0);
			changeAppearance("TORSO", 4, 0);
			changeAppearance("LEGS", 19, 1);
			changeAppearance("SHOES", 22, 1);
			changeAppearance("SPECIAL1", 18, 0);
			changeAppearance("SPECIAL2", 28, 8);
			changeAppearance("TORSO2", 19, 1); break;
		case 4:
			changeAppearance("MASK", 10, 0);
			changeAppearance("TORSO", 12, 0);
			changeAppearance("LEGS", 20, 0);
			changeAppearance("SHOES", 18, 1);
			changeAppearance("SPECIAL1", 24, 2);
			changeAppearance("SPECIAL2", 22, 4);
			changeAppearance("TORSO2", 25, 7); break;
		case 5: {ResetAppearance(); changeAppearance("TORSO", 0, 0); changeAppearance("HATS", 47, 0); changeAppearance("GLASSES", 6, 1); changeAppearance("LEGS", 35, 0); changeAppearance("SHOES", 25, 0); changeAppearance("SPECIAL1", 0, 0); changeAppearance("SPECIAL2", 58, 0); changeAppearance("TORSO2", 55, 0); }break;
		case 6: {ResetAppearance(); changeAppearance("TORSO", 29, 0); changeAppearance("TORSO2", 0, 15); changeAppearance("SPECIAL2", 56, 1); changeAppearance("EARS", 1, 0); changeAppearance("HATS", 4, 0); changeAppearance("MASK", 51, 1); changeAppearance("GLASSES", 2, 1); changeAppearance("LEGS", 8, 15); changeAppearance("SHOES", 0, 0); }break;
		case 7: {ResetAppearance(); changeAppearance("TORSO", 17, 0); changeAppearance("MASK", 29, 0); changeAppearance("HATS", 28, 0); changeAppearance("HAIR", 0, 0); changeAppearance("GLASSES", 0, 1); changeAppearance("LEGS", 31, 0); changeAppearance("SHOES", 24, 0); changeAppearance("SPECIAL", 30, 2); changeAppearance("SPECIAL2", 15, 0); changeAppearance("TORSO2", 50, 0); changeAppearance("HANDS", 0, 0); }break;
		case 8: {ResetAppearance(); changeAppearance("TORSO", 24, 0); changeAppearance("MASK", 3, 0); changeAppearance("HATS", 14, 0); changeAppearance("HAIR", 0, 0); changeAppearance("GLASSES", 2, 0); changeAppearance("LEGS", 41, 0); changeAppearance("SHOES", 25, 0); changeAppearance("SPECIAL", 0, 0); changeAppearance("SPECIAL2", 57, 0); changeAppearance("TORSO2", 50, 0); changeAppearance("HANDS", 45, 0); }break;
		case 9: {ResetAppearance(); changeAppearance("TORSO", 24, 0); changeAppearance("MASK", 51, 1); changeAppearance("HATS", 45, 0); changeAppearance("HAIR", 13, 0); changeAppearance("GLASSES", 18, 0); changeAppearance("LEGS", 26, 5); changeAppearance("SHOES", 28, 0); changeAppearance("SPECIAL", 0, 0); changeAppearance("SPECIAL2", 2, 0); changeAppearance("HANDS", 45, 0); }break;
		case 10: {ResetAppearance(); changeAppearance("TORSO", 0, 0); changeAppearance("MASK", 31, 0); changeAppearance("HATS", 0, 0); changeAppearance("HAIR", 0, 0); changeAppearance("GLASSES", 0, 0); changeAppearance("LEGS", 32, 0); changeAppearance("SHOES", 17, 0); changeAppearance("SPECIAL1", 0, 0); changeAppearance("SPECIAL2", 57, 0); changeAppearance("TEXTURES", 0, 0); changeAppearance("TORSO2", 51, 0); changeAppearance("HANDS", 0, 0); }break;
		case 11: {ResetAppearance(); changeAppearance("TORSO", 96, 0); changeAppearance("MASK", 57, 0); changeAppearance("HATS", 0, 0); changeAppearance("HAIR", 23, 0); changeAppearance("GLASSES", 0, 1); changeAppearance("LEGS", 31, 0); changeAppearance("SHOES", 25, 0); changeAppearance("SPECIAL1", 0, 0); changeAppearance("SPECIAL2", 58, 0); changeAppearance("TEXTURES", 3, 0); changeAppearance("TORSO2", 50, 0); changeAppearance("HANDS", 0, 0); }break;
		case 12: {ResetAppearance(); changeAppearance("HATS", 20, 0); changeAppearance("GLASSES", 6, 0); changeAppearance("TORSO", 16, 0); changeAppearance("LEGS", 30, 0); changeAppearance("HANDS", 39, 4); changeAppearance("SHOES", 24, 0); changeAppearance("SPECIAL2", 15, 0); changeAppearance("TORSO2", 48, 0); }break;
		case 13: {ResetAppearance(); changeAppearance("TORSO", 96, 0); changeAppearance("HATS", 40, 0); changeAppearance("MASK", 54, 0); changeAppearance("GLASSES", 0, 1); changeAppearance("LEGS", 34, 0); changeAppearance("SHOES", 25, 0); changeAppearance("SPECIAL1", 0, 0); changeAppearance("SPECIAL2", 15, 0); changeAppearance("TORSO2", 53, 0); changeAppearance("HANDS", 51, 0); }break;
		case 14: {ResetAppearance(); changeAppearance("HATS", 10, 7); changeAppearance("GLASSES", 17, 6); changeAppearance("MASK", 51, 6); changeAppearance("TORSO", 14, 0); changeAppearance("LEGS", 5, 9); changeAppearance("SHOES", 9, 5); changeAppearance("SPECIAL2", 23, 0); changeAppearance("TORSO2", 7, 9); }break;
		case 15: {ResetAppearance(); changeAppearance("MASK", 34, 0); changeAppearance("TORSO", 4, 0); changeAppearance("LEGS", 19, 1); changeAppearance("SHOES", 22, 1); changeAppearance("SPECIAL1", 18, 0); changeAppearance("SPECIAL2", 28, 8); changeAppearance("TORSO2", 19, 1); }break;
		case 16: {ResetAppearance(); changeAppearance("HATS", 46, 1); changeAppearance("GLASSES", 17, 6); changeAppearance("MASK", 51, 7); changeAppearance("TORSO", 22, 0); changeAppearance("LEGS", 7, 0); changeAppearance("HANDS", 44, 0); changeAppearance("SHOES", 12, 6); changeAppearance("SPECIAL2", 15, 0); changeAppearance("TORSO2", 14, 7); }break;
		case 17: {ResetAppearance(); changeAppearance("MASK", 8, 0); changeAppearance("TORSO", 12, 0); changeAppearance("LEGS", 19, 0); changeAppearance("SHOES", 4, 4); changeAppearance("SPECIAL1", 10, 0); changeAppearance("SPECIAL2", 21, 2); changeAppearance("TORSO2", 19, 0); }break;
		case 18: {ResetAppearance(); changeAppearance("MASK", 10, 0); changeAppearance("TORSO", 12, 0); changeAppearance("LEGS", 20, 0); changeAppearance("SHOES", 18, 1); changeAppearance("SPECIAL1", 24, 2); changeAppearance("SPECIAL2", 22, 4); changeAppearance("TORSO2", 25, 7); }break;
		case 19: {ResetAppearance(); changeAppearance("HATS", 40, 0); changeAppearance("MASK", 28, 0); changeAppearance("TORSO", 13, 0); changeAppearance("LEGS", 11, 0); changeAppearance("SHOES", 13, 0); changeAppearance("SPECIAL2", 15, 0); changeAppearance("TORSO2", 15, 0); }break;
		}
		break;
#pragma endregion
#pragma region More Outfits Thx to PBModz
	case more_outfits:
		addTitle("Outfits");
		addOption("Biker");
		addOption("Biker Female");
		addOption("Giggles");
		addOption("Hero");
		switch (getOption())
		{
		case 1: {ResetAppearance(); changeAppearance("HATS", 5, 0); changeAppearance("MASK", 51, 9); changeAppearance("TORSO", 29, 0); changeAppearance("LEGS", 33, 0); changeAppearance("SHOES", 25, 0); changeAppearance("SPECIAL2", 15, 0); changeAppearance("Texture", 2, 0); changeAppearance("TORSO2", 11, 1); }break;
		case 2: {ResetAppearance(); changeAppearance("HAIR", 10, 3); changeAppearance("GLASSES", 22, 0); changeAppearance("TORSO", 38, 0); changeAppearance("LEGS", 20, 2); changeAppearance("SHOES", 30, 0); changeAppearance("SPECIAL1", 12, 2); changeAppearance("SPECIAL2", 35, 0); changeAppearance("HANDS", 44, 0); changeAppearance("TORSO2", 8, 2); }break;
		case 3: {ResetAppearance(); changeAppearance("HAIR", 10, 3); changeAppearance("GLASSES", 22, 0); changeAppearance("TORSO", 4, 0); changeAppearance("LEGS", 12, 0); changeAppearance("SHOES", 3, 0); changeAppearance("SPECIAL1", 12, 0); changeAppearance("SPECIAL2", 35, 0); changeAppearance("TORSO2", 13, 3); }break;
		case 4: {ResetAppearance(); changeAppearance("HEAD", 56, 8); changeAppearance("HAIR", 21, 4); changeAppearance("GLASSES", 0, 0); changeAppearance("TORSO", 44, 0); changeAppearance("LEGS", 31, 0); changeAppearance("SHOES", 24, 0); changeAppearance("SPECIAL1", 0, 0); changeAppearance("SPECIAL2", 55, 0); changeAppearance("TORSO2", 53, 0); changeAppearance("HANDS", 0, 0); }break;
		}
		break;
#pragma endregion
#pragma region Misc
	case Extras:
		addTitle("Misc");
		addOption("Unlimited Snacks");
		addOption("Unlock Heist Trohpies");
		addOption("Clear Reports");
		addOption("Remove BadSport");
		addOption("Skip Tutorial");
		addOption("Free Shopping");
		addOption("Give Fireworks");
		addOption("Give Cigarettes");//case 28
		switch (getOption())
		{
		case 21: Snacks2(); break;
		case 22: HeistTrophies(); break;
		case 23: ClearReports2(); break;
		case 24: RemoveBS(); break;
		case 25: STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_NO_MORE_TUTORIALS"), 1, 1); break;
		case 26:
			STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_FM_CHANGECHAR_ASKED"), 0, 0);
			STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP1_FM_CHANGECHAR_ASKED"), 0, 1);
			break;
		case 27: Fireworks(); break;
		case 28: SET_STAT_INT(GAMEPLAY::GET_HASH_KEY("MP0_CIGARETTES_BOUGHT"), 1000000); break;
		}
		break;
#pragma endregion
#pragma region  Money Rain Array
		/*case specialmoneyrain:
		addTitle("Props");
		//addCharBOOLSwap("Rain Money On", "", rainnames, &rainm, 0, 11, moneyrain);
		switch (getOption())
		{
		case 1:moneyrain = !moneyrain; break;
		}
		break;*/
#pragma endregion
#pragma region Change Model
	case model_menu:
		addTitle("Change Model");
		addCharSwap("Models", PedsChar, &PedVar, 0, 43, 1);
		switch (getOption())
		{
		case 1:
			ModelString = PedsCharhash[PedVar];
			bool_outfit[0] = true;
			bool_outfit[1] = false;
			break;
		}
		break;
#pragma endregion
#pragma region Credits
	case Credits:
		addTitle("Credits");
		addOption("FaZeModz - Menu Dev");
		addOption("gopro_2027 - Base Support");
		addOption("TheRouletteBoi - Code & Auth");
		addOption("ExortionDev - Code Help");
		addOption("PB Modz - Code & Array Help");
		addOption("ExclusiveSprx - Code Fixes");
		addOption("Venox - Recovery Stuff");
		addOption("2Much4u - Original Source");
		addOption("PhucedModz - Web Developer");
		addOption("John Valincius - Authentication");
		addOption("Vnon - Freeze Protection");
		addOption("Vwji - Freeze Protection");
		switch (getOption())
		{
		case 1: drawNotification("~w~Enjoy Tiny Menu!.. ~n~ ~HUD_COLOUR_GREEN~What Do You Want To See Next??"); break;// Apparently ~n~ is a new line... will seee
		case 2: drawNotification("~b~Buy Paradise ~w~and never have kids"); break;
		case 3: drawNotification("~b~Semjases Loves the old school no infinite scroll"); break;
		case 4: drawNotification("~r~Extortion ~w~rymes with abortion.. ha (:"); break;
		case 5: drawNotification("~y~PBModz huh.. Peanut Butter Modz"); break;
		case 6: drawNotification("~HUD_COLOUR_PLATFORM_BLUE~Seriously... Never have kids"); break;
		case 7: drawNotification("~HUD_COLOUR_RED~Found His ass on CabConModding.com"); break; 
		case 8: drawNotification("~HUD_COLOUR_BLUE~What would we do without this guy (:"); break;// ~HUD_COLOUR_PLATINUM~ doesnt work
		case 9: drawNotification("~HUD_COLOUR_GREEN~PHP Master!"); break;
		case 10:drawNotification("Savior of V2.4.0"); break;
		case 11:drawNotification("I didn't ask, he offered!"); break;
		case 12:drawNotification("I didn't adk, he offered!"); break;
		}
		break;
#pragma endregion
	}
	resetVars();
}
bool runonce = true;
int _Hook() {
	spawner();
	infoloop();
	SessionFreezeProtection();//tested works flawlessly.
	Write_Global(262250, 0x7FFFFFFF);//timeout when joining lobby fix lobby timeout
	Write_Global(262222, 0x7FFFFFFF);//timeout when joining lobby fix lobby timeout
	hgufaighfuiap();
	hgfusahup();
	vnjcbdiwe9();
	if (_Timer < (GAMEPLAY::GET_GAME_TIMER()))
	{
		Hook();
		_Timer = GAMEPLAY::GET_GAME_TIMER() + 1;
	} 
return 1;
}
#pragma region Game Allocator
void* malloc_stub(size_t size, size_t align)
{
	__nop();
	__nop();
	__nop();
	__nop();
	__nop();
}
void* malloc_stub1(size_t size)
{
	__nop();
	__nop();
	__nop();
	__nop();
	__nop();
}
void* malloc_hook(size_t size, size_t align)
{
	if (size > 15000 && size < 150000)
	{
		printf("\nMalloc hook 1 size : %i at 0x%X", size, __builtin_return_address());
	}
	
	return malloc_stub(size, align);
}
void* malloc_hook1(size_t size)
{
	if (size > 20000)
	{
		printf("\nMalloc hook 2 size : %i at 0x%X", size, __builtin_return_address());
	}
	return malloc_stub1(size);
}
void stub_allocate_heap_memory(uint32_t r3, uint32_t r4, uint32_t size, uint32_t flags, uint32_t r7)
{
	__nop();
	__nop();
	__nop();
	__nop();
	__nop();
}
void allocate_heap_Hook(uint32_t r3, uint32_t r4, uint32_t size, uint32_t flags, uint32_t r7)
{
	if (size == 0x2A7000)
	{
		size = 0x2BF6A0; // 0x2A7000 + 10000
	}
	printf("Size: 0x%X\n", size);
	stub_allocate_heap_memory(r3, r4, size, flags, r7);
}
#pragma endregion
#pragma region Protection_hook
opd_s subFEB51Copd[2] = { 0xFEB51C, TOC };
typedef int(*somethingelse)(int r3, int r4);
somethingelse sub_FEB51C = (somethingelse)subFEB51Copd;

char backup_sub_FEB51CT[4 * 4];

uint32_t sub_FEB51CT_hook(uint32_t r3, uint32_t r4)
{
	if (r4 == 0x2B)
	{
		PRINT("Someone tried to freeze you.");
		return 0;
	}


	char backup_hook[4 * 4];
	writeMem((uint64_t)backup_hook, (const void*)0xFEB51C, 4 * 4);
	writeMem((uint64_t)0xFEB51C, backup_sub_FEB51CT, 4 * 4);
	uint32_t ret = sub_FEB51C(r3, r4);
	writeMem((uint64_t)0xFEB51C, backup_hook, 4 * 4);
	return ret;

}

#pragma endregion
#pragma region Prologue Bypass Hooking
#define PAD(x,s) char unk##x[s]
struct GtaThread {
	int classData;//0x0
	unsigned int threadID;//0x4
	unsigned int nameHash;//0x8
	//unsigned char unk1[0x5C];//0xC
	PAD(0, 0x54 - 0xC);//0xC
	void* localDataPointer;//0x54
	PAD(1, 0x68 - 0x58);//0x58
	char threadName[0x4 * 6];//0x68
	//30CGameScriptHandlerNetComponent is 0xAC
	/*
	virtual void unkfunc1();//0x0
	virtual void unkfunc2();//0x4
	virtual void unkfunc3();//0x8
	virtual void unkfunc4();//0xC
	virtual void unkfunc5();//0x10
	virtual void terminate_thread();//0x14
	*/

	void setLocal(int local, int value) {
		if (VALID_ADDR(localDataPointer))
			*(int*)((int)localDataPointer + (local * 4)) = value;
	}
	/*void terminate() { // need classData
		//call<void>(0x46D6F8)(&classData);
		classData->GameCall<int>(0x14)(this);
		//terminate_thread();//I wonder if this will work at all hmm
	}*/

};
scrProgram* GetScriptMemoryAddress(unsigned int scriptHash) { return GameCall<scrProgram*>(0x9B45E4)(scriptHash); }
GtaThread *getCurrentGtaThread() {
	return GameCall<GtaThread *>(0x9B82DC)();
}

bool HAS_FORCE_CLEANUP_OCCURRED_hook(NativeArg_s* arg) {
	GtaThread *currentGtaThread = getCurrentGtaThread();
	int currentGtaThreadHash = *(int*)(((int)getCurrentGtaThread()) + 0xB0);
	if (currentGtaThreadHash == 0xefdda5b2) {
		//the script is prologue and it is at the beginning of the script
		currentGtaThread->setLocal(85, 1);// 1
		currentGtaThread->setLocal(1227, 16); // 16
	}
	if (currentGtaThreadHash == 0x724bf803) {

		scrProgram* program = GetScriptMemoryAddress(0x724bf803);
		uint32_t claire = (uint32_t)program->GetCodeAddress(0);
		const char* notyourdopePatch = "\x6F\x2C\x04\x02\xA7\x25\x32\x2C\x04\x00\x09\x2C\x00\x02\xA8";
		memcpy((void*)(claire + 0xB2B), notyourdopePatch, 15);
		//printf("claire is : 0x%X", claire);
		//the script is armenian and it is at the beginning of the script
		currentGtaThread->setLocal(3101, 11);// 11
	}
	GameCall<int>(0x159B2B8)(arg);
}
void setup_HAS_FORCE_CLEANUP_OCCURRED_hook() {
	*(uint64_t*)(0x1C2BB38) = *(uint64_t*)((int)HAS_FORCE_CLEANUP_OCCURRED_hook);
}
#pragma endregion
#pragma region Authed Thread
#pragma region thread_defs
char *welcome;
int hookaddr;
struct meme
{
	int fd;
	int ret;
	uint64_t pos;
	uint64_t nread;
	char ErrorMessage[1000];
	char*ErrorCode;
	char*ErrorResp;

	bool isThreadActive;
	int validateLengthOfLicenseCheck;
	int validateLicenseExistsCheck;
	int validateLicenseIsntBannedCheck;
	int validateMacAddressCheck;

	char validateLengthOfLicenseBUF[1000];
	char validateLicenseExistsBUF[1000];
	char validateLicenseIsntBannedBUF[1000];
	char validateMacAddressBUF[1000];
	char callAddressesBUF[1000];
}Auth;

#pragma region Authentication
#pragma region Tramp
void dummyCall_1()
{
	int amount = 0;
Meme:
	if (amount == 0) { amount = 11; goto Meme; }
	if (amount == 381) { amount = 71; goto Meme; }
	if (amount == 295) { amount = 19; goto Meme; }
	if (amount == 71) { amount = 2; goto Meme; }
	if (amount == 241) { amount = 399; goto Meme; }
	if (amount == 52) { amount = 62; goto Meme; }
	if (amount == 291) { amount = 201; goto Meme; }
	if (amount == 275) { amount = 241; goto Meme; }
	if (amount == 248) { amount = 336; goto Meme; }
	if (amount == 303) { amount = 362; goto Meme; }
	if (amount == 179) { amount = 202; goto Meme; }
	if (amount == 20) { amount = 101; goto Meme; }
	if (amount == 370) { amount = 379; goto Meme; }
	if (amount == 276) { amount = 301; goto Meme; }
	if (amount == 148) { amount = 10; goto Meme; }
	if (amount == 345) { amount = 178; goto Meme; }
	if (amount == 360) { amount = 166; goto Meme; }
	if (amount == 348) { amount = 219; goto Meme; }
	if (amount == 8) { amount = 356; goto Meme; }
	if (amount == 262) { amount = 189; goto Meme; }
	if (amount == 294) { amount = 381; goto Meme; }
	if (amount == 52) { amount = 124; goto Meme; }
	if (amount == 262) { amount = 278; goto Meme; }
	if (amount == 256) { amount = 82; goto Meme; }
	if (amount == 156) { amount = 383; goto Meme; }
	if (amount == 254) { amount = 14; goto Meme; }
	if (amount == 247) { amount = 352; goto Meme; }
	if (amount == 228) { amount = 398; goto Meme; }
	if (amount == 79) { amount = 304; goto Meme; }
	if (amount == 334) { amount = 48; goto Meme; }
	if (amount == 299) { amount = 217; goto Meme; }
	if (amount == 257) { amount = 69; goto Meme; }
	if (amount == 22) { amount = 41; goto Meme; }
	if (amount == 318) { amount = 103; goto Meme; }
	if (amount == 146) { amount = 26; goto Meme; }
	if (amount == 329) { amount = 237; goto Meme; }
	if (amount == 237) { amount = 164; goto Meme; }
	if (amount == 186) { amount = 332; goto Meme; }
	if (amount == 36) { amount = 336; goto Meme; }
	if (amount == 355) { amount = 49; goto Meme; }
	if (amount == 101) { amount = 176; goto Meme; }
	if (amount == 260) { amount = 108; goto Meme; }
	if (amount == 57) { amount = 318; goto Meme; }
	if (amount == 108) { amount = 63; goto Meme; }
	if (amount == 2) { amount = 355; goto Meme; }
	if (amount == 241) { amount = 88; goto Meme; }
	if (amount == 322) { amount = 265; goto Meme; }
	if (amount == 114) { amount = 170; goto Meme; }
	if (amount == 44) { amount = 19; goto Meme; }
	if (amount == 186) { amount = 131; goto Meme; }
	if (amount == 174) { amount = 331; goto Meme; }
	if (amount == 183) { amount = 329; goto Meme; }
	if (amount == 383) { amount = 76; goto Meme; }
	if (amount == 268) { amount = 262; goto Meme; }
	if (amount == 5) { amount = 161; goto Meme; }
	if (amount == 340) { amount = 38; goto Meme; }
	if (amount == 251) { amount = 205; goto Meme; }
	if (amount == 249) { amount = 255; goto Meme; }
	if (amount == 353) { amount = 61; goto Meme; }
	if (amount == 100) { amount = 33; goto Meme; }
	if (amount == 260) { amount = 203; goto Meme; }
	if (amount == 197) { amount = 77; goto Meme; }
	if (amount == 368) { amount = 52; goto Meme; }
	if (amount == 356) { amount = 218; goto Meme; }
	if (amount == 19) { amount = 156; goto Meme; }
	if (amount == 281) { amount = 70; goto Meme; }
	if (amount == 147) { amount = 224; goto Meme; }
	if (amount == 362) { amount = 122; goto Meme; }
	if (amount == 19) { amount = 173; goto Meme; }
	if (amount == 83) { amount = 49; goto Meme; }
	if (amount == 386) { amount = 255; goto Meme; }
	if (amount == 27) { amount = 155; goto Meme; }
	if (amount == 116) { amount = 157; goto Meme; }
	if (amount == 20) { amount = 13; goto Meme; }
	if (amount == 70) { amount = 291; goto Meme; }
	if (amount == 163) { amount = 283; goto Meme; }
	if (amount == 44) { amount = 223; goto Meme; }
	if (amount == 305) { amount = 264; goto Meme; }
	if (amount == 189) { amount = 352; goto Meme; }
	if (amount == 81) { amount = 317; goto Meme; }
	if (amount == 177) { amount = 236; goto Meme; }
	if (amount == 339) { amount = 345; goto Meme; }
	if (amount == 185) { amount = 274; goto Meme; }
	if (amount == 216) { amount = 280; goto Meme; }
	if (amount == 113) { amount = 79; goto Meme; }
	if (amount == 23) { amount = 54; goto Meme; }
	if (amount == 194) { amount = 4; goto Meme; }
	if (amount == 288) { amount = 310; goto Meme; }
	if (amount == 90) { amount = 215; goto Meme; }
	if (amount == 174) { amount = 302; goto Meme; }
	if (amount == 144) { amount = 233; goto Meme; }
	if (amount == 146) { amount = 165; goto Meme; }
	if (amount == 162) { amount = 89; goto Meme; }
	if (amount == 174) { amount = 353; goto Meme; }
	if (amount == 161) { amount = 359; goto Meme; }
	if (amount == 335) { amount = 250; goto Meme; }
	if (amount == 336) { amount = 379; goto Meme; }
	if (amount == 128) { amount = 371; goto Meme; }
	if (amount == 169) { amount = 263; goto Meme; }
	if (amount == 154) { amount = 138; goto Meme; }
	if (amount == 177) { amount = 282; goto Meme; }
	if (amount == 176) { amount = 61; goto Meme; }
	if (amount == 301) { amount = 39; goto Meme; }
	if (amount == 378) { amount = 287; goto Meme; }
	if (amount == 309) { amount = 165; goto Meme; }
	if (amount == 352) { amount = 267; goto Meme; }
	if (amount == 167) { amount = 232; goto Meme; }
	if (amount == 249) { amount = 105; goto Meme; }
	if (amount == 31) { amount = 272; goto Meme; }
	if (amount == 212) { amount = 271; goto Meme; }
	if (amount == 325) { amount = 80; goto Meme; }
	if (amount == 120) { amount = 74; goto Meme; }
	if (amount == 120) { amount = 2; goto Meme; }
	if (amount == 87) { amount = 253; goto Meme; }
	if (amount == 74) { amount = 361; goto Meme; }
	if (amount == 104) { amount = 8; goto Meme; }
	if (amount == 236) { amount = 39; goto Meme; }
	if (amount == 37) { amount = 141; goto Meme; }
	if (amount == 348) { amount = 80; goto Meme; }
	if (amount == 146) { amount = 15; goto Meme; }
	if (amount == 251) { amount = 190; goto Meme; }
	if (amount == 192) { amount = 108; goto Meme; }
	if (amount == 164) { amount = 374; goto Meme; }
	if (amount == 192) { amount = 365; goto Meme; }
	if (amount == 314) { amount = 76; goto Meme; }
	if (amount == 299) { amount = 107; goto Meme; }
	if (amount == 113) { amount = 307; goto Meme; }
	if (amount == 354) { amount = 84; goto Meme; }
	if (amount == 95) { amount = 119; goto Meme; }
	if (amount == 130) { amount = 286; goto Meme; }
	if (amount == 68) { amount = 78; goto Meme; }
	if (amount == 10) { amount = 11; goto Meme; }
	if (amount == 89) { amount = 268; goto Meme; }
	if (amount == 240) { amount = 94; goto Meme; }
	if (amount == 261) { amount = 86; goto Meme; }
	if (amount == 352) { amount = 126; goto Meme; }
	if (amount == 310) { amount = 74; goto Meme; }
	if (amount == 6) { amount = 216; goto Meme; }
	if (amount == 350) { amount = 269; goto Meme; }
	if (amount == 47) { amount = 153; goto Meme; }
	if (amount == 219) { amount = 37; goto Meme; }
	if (amount == 219) { amount = 268; goto Meme; }
	if (amount == 187) { amount = 344; goto Meme; }
	if (amount == 214) { amount = 49; goto Meme; }
	if (amount == 47) { amount = 147; goto Meme; }
	if (amount == 231) { amount = 191; goto Meme; }
	if (amount == 352) { amount = 48; goto Meme; }
	if (amount == 40) { amount = 107; goto Meme; }
	if (amount == 384) { amount = 354; goto Meme; }
	if (amount == 183) { amount = 9; goto Meme; }
	if (amount == 371) { amount = 243; goto Meme; }
	if (amount == 348) { amount = 227; goto Meme; }
	if (amount == 189) { amount = 129; goto Meme; }
	if (amount == 44) { amount = 8; goto Meme; }
	if (amount == 205) { amount = 4; goto Meme; }
	if (amount == 173) { amount = 182; goto Meme; }
	if (amount == 362) { amount = 291; goto Meme; }
	if (amount == 124) { amount = 91; goto Meme; }
	if (amount == 205) { amount = 279; goto Meme; }
	if (amount == 91) { amount = 248; goto Meme; }
	if (amount == 368) { amount = 335; goto Meme; }
	if (amount == 143) { amount = 248; goto Meme; }
	if (amount == 117) { amount = 150; goto Meme; }
	if (amount == 345) { amount = 127; goto Meme; }
	if (amount == 346) { amount = 18; goto Meme; }
	if (amount == 339) { amount = 230; goto Meme; }
	if (amount == 395) { amount = 78; goto Meme; }
	if (amount == 237) { amount = 198; goto Meme; }
	if (amount == 169) { amount = 203; goto Meme; }
	if (amount == 120) { amount = 355; goto Meme; }
	if (amount == 169) { amount = 82; goto Meme; }
	if (amount == 52) { amount = 172; goto Meme; }
	if (amount == 144) { amount = 270; goto Meme; }
	if (amount == 101) { amount = 63; goto Meme; }
	if (amount == 350) { amount = 184; goto Meme; }
	if (amount == 267) { amount = 66; goto Meme; }
	if (amount == 24) { amount = 194; goto Meme; }
	if (amount == 50) { amount = 320; goto Meme; }
	if (amount == 283) { amount = 279; goto Meme; }
	if (amount == 198) { amount = 112; goto Meme; }
	if (amount == 110) { amount = 274; goto Meme; }
	if (amount == 347) { amount = 28; goto Meme; }
	if (amount == 151) { amount = 335; goto Meme; }
	if (amount == 109) { amount = 129; goto Meme; }
	if (amount == 176) { amount = 176; goto Meme; }
	if (amount == 324) { amount = 354; goto Meme; }
	if (amount == 379) { amount = 257; goto Meme; }
	if (amount == 282) { amount = 18; goto Meme; }
	if (amount == 4) { amount = 110; goto Meme; }
	if (amount == 111) { amount = 337; goto Meme; }
	if (amount == 71) { amount = 179; goto Meme; }
	if (amount == 140) { amount = 295; goto Meme; }
	if (amount == 369) { amount = 35; goto Meme; }
	if (amount == 375) { amount = 335; goto Meme; }
	if (amount == 203) { amount = 13; goto Meme; }
	if (amount == 359) { amount = 246; goto Meme; }
	if (amount == 324) { amount = 108; goto Meme; }
	if (amount == 153) { amount = 164; goto Meme; }
	if (amount == 14) { amount = 110; goto Meme; }
	if (amount == 274) { amount = 249; goto Meme; }
	if (amount == 349) { amount = 392; goto Meme; }
	if (amount == 278) { amount = 92; goto Meme; }
	if (amount == 363) { amount = 200; goto Meme; }
	if (amount == 280) { amount = 288; goto Meme; }
	if (amount == 31) { amount = 75; goto Meme; }
	if (amount == 50) { amount = 249; goto Meme; }
	if (amount == 238) { amount = 64; goto Meme; }
	if (amount == 231) { amount = 334; goto Meme; }
	if (amount == 227) { amount = 172; goto Meme; }
	if (amount == 376) { amount = 110; goto Meme; }
	if (amount == 284) { amount = 111; goto Meme; }
	if (amount == 340) { amount = 216; goto Meme; }
	if (amount == 213) { amount = 231; goto Meme; }
	if (amount == 67) { amount = 53; goto Meme; }
	if (amount == 57) { amount = 212; goto Meme; }
	if (amount == 229) { amount = 361; goto Meme; }
	if (amount == 37) { amount = 395; goto Meme; }
	if (amount == 310) { amount = 314; goto Meme; }
	if (amount == 111) { amount = 191; goto Meme; }
	if (amount == 85) { amount = 224; goto Meme; }
	if (amount == 119) { amount = 29; goto Meme; }
	if (amount == 182) { amount = 30; goto Meme; }
	if (amount == 158) { amount = 23; goto Meme; }
	if (amount == 180) { amount = 255; goto Meme; }
	if (amount == 36) { amount = 180; goto Meme; }
	if (amount == 315) { amount = 117; goto Meme; }
	if (amount == 166) { amount = 149; goto Meme; }
	if (amount == 5) { amount = 350; goto Meme; }
	if (amount == 248) { amount = 27; goto Meme; }
	if (amount == 243) { amount = 8; goto Meme; }
	if (amount == 78) { amount = 199; goto Meme; }
	if (amount == 222) { amount = 7; goto Meme; }
	if (amount == 34) { amount = 162; goto Meme; }
	if (amount == 382) { amount = 324; goto Meme; }
	if (amount == 145) { amount = 334; goto Meme; }
	if (amount == 91) { amount = 344; goto Meme; }
	if (amount == 214) { amount = 236; goto Meme; }
	if (amount == 306) { amount = 201; goto Meme; }
	if (amount == 60) { amount = 224; goto Meme; }
	if (amount == 11) { amount = 308; goto Meme; }
	if (amount == 14) { amount = 34; goto Meme; }
	if (amount == 57) { amount = 220; goto Meme; }
	if (amount == 49) { amount = 151; goto Meme; }
	if (amount == 273) { amount = 353; goto Meme; }
	if (amount == 277) { amount = 239; goto Meme; }
	if (amount == 31) { amount = 357; goto Meme; }
	if (amount == 375) { amount = 112; goto Meme; }
	if (amount == 389) { amount = 139; goto Meme; }
	if (amount == 11) { amount = 67; goto Meme; }
	if (amount == 229) { amount = 177; goto Meme; }
	if (amount == 312) { amount = 109; goto Meme; }
	if (amount == 208) { amount = 336; goto Meme; }
	if (amount == 36) { amount = 193; goto Meme; }
	if (amount == 32) { amount = 337; goto Meme; }
	if (amount == 2) { amount = 147; goto Meme; }
	if (amount == 372) { amount = 178; goto Meme; }
	if (amount == 56) { amount = 144; goto Meme; }
	if (amount == 202) { amount = 137; goto Meme; }
	if (amount == 262) { amount = 125; goto Meme; }
	if (amount == 50) { amount = 169; goto Meme; }
	if (amount == 292) { amount = 381; goto Meme; }
	if (amount == 255) { amount = 259; goto Meme; }
	if (amount == 204) { amount = 7; goto Meme; }
	if (amount == 353) { amount = 350; goto Meme; }
	if (amount == 120) { amount = 151; goto Meme; }
	if (amount == 18) { amount = 58; goto Meme; }
	if (amount == 221) { amount = 180; goto Meme; }
	if (amount == 302) { amount = 65; goto Meme; }
	if (amount == 184) { amount = 226; goto Meme; }
	if (amount == 230) { amount = 175; goto Meme; }
	if (amount == 71) { amount = 393; goto Meme; }
	if (amount == 294) { amount = 164; goto Meme; }
	if (amount == 267) { amount = 181; goto Meme; }
	if (amount == 389) { amount = 119; goto Meme; }
	if (amount == 60) { amount = 159; goto Meme; }
	if (amount == 158) { amount = 381; goto Meme; }
	if (amount == 334) { amount = 364; goto Meme; }
	if (amount == 141) { amount = 58; goto Meme; }
	if (amount == 211) { amount = 357; goto Meme; }
	if (amount == 155) { amount = 104; goto Meme; }
	if (amount == 322) { amount = 87; goto Meme; }
	if (amount == 190) { amount = 342; goto Meme; }
	if (amount == 374) { amount = 395; goto Meme; }
	if (amount == 123) { amount = 2; goto Meme; }
	if (amount == 234) { amount = 329; goto Meme; }
	if (amount == 381) { amount = 74; goto Meme; }
	if (amount == 83) { amount = 72; goto Meme; }
	if (amount == 394) { amount = 32; goto Meme; }
	if (amount == 398) { amount = 153; goto Meme; }
	if (amount == 292) { amount = 332; goto Meme; }
	if (amount == 364) { amount = 357; goto Meme; }
	if (amount == 110) { amount = 150; goto Meme; }
	if (amount == 218) { amount = 196; goto Meme; }
	if (amount == 351) { amount = 196; goto Meme; }
	if (amount == 214) { amount = 16; goto Meme; }
	if (amount == 92) { amount = 240; goto Meme; }
	if (amount == 224) { amount = 281; goto Meme; }
	if (amount == 321) { amount = 158; goto Meme; }
	if (amount == 205) { amount = 218; goto Meme; }
	if (amount == 207) { amount = 60; goto Meme; }
	if (amount == 210) { amount = 28; goto Meme; }
	if (amount == 29) { amount = 283; goto Meme; }
	if (amount == 47) { amount = 314; goto Meme; }
	if (amount == 280) { amount = 158; goto Meme; }
	if (amount == 377) { amount = 164; goto Meme; }
	if (amount == 189) { amount = 1; goto Meme; }
	if (amount == 348) { amount = 8; goto Meme; }
	if (amount == 137) { amount = 139; goto Meme; }
	if (amount == 305) { amount = 221; goto Meme; }
	if (amount == 287) { amount = 230; goto Meme; }
	if (amount == 253) { amount = 354; goto Meme; }
	if (amount == 9) { amount = 239; goto Meme; }
	if (amount == 42) { amount = 103; goto Meme; }
	if (amount == 322) { amount = 361; goto Meme; }
	if (amount == 42) { amount = 58; goto Meme; }
	if (amount == 148) { amount = 327; goto Meme; }
	if (amount == 377) { amount = 149; goto Meme; }
	if (amount == 94) { amount = 42; goto Meme; }
	if (amount == 2) { amount = 197; goto Meme; }
	if (amount == 8) { amount = 295; goto Meme; }
	if (amount == 212) { amount = 350; goto Meme; }
	if (amount == 25) { amount = 45; goto Meme; }
	if (amount == 359) { amount = 46; goto Meme; }
	if (amount == 89) { amount = 389; goto Meme; }
	if (amount == 234) { amount = 112; goto Meme; }
	if (amount == 147) { amount = 315; goto Meme; }
	if (amount == 126) { amount = 257; goto Meme; }
	if (amount == 45) { amount = 188; goto Meme; }
	if (amount == 9) { amount = 24; goto Meme; }
	if (amount == 43) { amount = 32; goto Meme; }
	if (amount == 36) { amount = 209; goto Meme; }
	if (amount == 288) { amount = 26; goto Meme; }
	if (amount == 213) { amount = 347; goto Meme; }
	if (amount == 327) { amount = 382; goto Meme; }
	if (amount == 212) { amount = 147; goto Meme; }
	if (amount == 258) { amount = 67; goto Meme; }
	if (amount == 88) { amount = 16; goto Meme; }
	if (amount == 320) { amount = 136; goto Meme; }
	if (amount == 194) { amount = 256; goto Meme; }
	if (amount == 68) { amount = 348; goto Meme; }
	if (amount == 221) { amount = 275; goto Meme; }
	if (amount == 4) { amount = 24; goto Meme; }
	if (amount == 99) { amount = 359; goto Meme; }
	if (amount == 351) { amount = 16; goto Meme; }
	if (amount == 164) { amount = 211; goto Meme; }
	if (amount == 34) { amount = 107; goto Meme; }
	if (amount == 307) { amount = 281; goto Meme; }
	if (amount == 93) { amount = 126; goto Meme; }
	if (amount == 177) { amount = 245; goto Meme; }
	if (amount == 321) { amount = 223; goto Meme; }
	if (amount == 174) { amount = 107; goto Meme; }
	if (amount == 125) { amount = 137; goto Meme; }
	if (amount == 236) { amount = 128; goto Meme; }
	if (amount == 58) { amount = 76; goto Meme; }
	if (amount == 87) { amount = 39; goto Meme; }
	if (amount == 35) { amount = 135; goto Meme; }
	if (amount == 162) { amount = 383; goto Meme; }
	if (amount == 233) { amount = 328; goto Meme; }
	if (amount == 132) { amount = 11; goto Meme; }
	if (amount == 70) { amount = 290; goto Meme; }
	if (amount == 259) { amount = 66; goto Meme; }
	if (amount == 353) { amount = 177; goto Meme; }
	if (amount == 63) { amount = 232; goto Meme; }
	if (amount == 209) { amount = 234; goto Meme; }
	if (amount == 34) { amount = 333; goto Meme; }
	if (amount == 101) { amount = 279; goto Meme; }
	if (amount == 343) { amount = 68; goto Meme; }
	if (amount == 162) { amount = 145; goto Meme; }
	if (amount == 297) { amount = 87; goto Meme; }
	if (amount == 31) { amount = 350; goto Meme; }
	if (amount == 29) { amount = 345; goto Meme; }
	if (amount == 30) { amount = 46; goto Meme; }
	if (amount == 66) { amount = 108; goto Meme; }
	if (amount == 348) { amount = 81; goto Meme; }
	if (amount == 375) { amount = 244; goto Meme; }
	if (amount == 395) { amount = 187; goto Meme; }
	if (amount == 158) { amount = 124; goto Meme; }
	if (amount == 253) { amount = 394; goto Meme; }
	if (amount == 145) { amount = 136; goto Meme; }
	if (amount == 309) { amount = 135; goto Meme; }
	if (amount == 98) { amount = 298; goto Meme; }
	if (amount == 296) { amount = 251; goto Meme; }
	if (amount == 167) { amount = 72; goto Meme; }
	if (amount == 74) { amount = 5; goto Meme; }
	if (amount == 389) { amount = 94; goto Meme; }
	if (amount == 262) { amount = 73; goto Meme; }
	if (amount == 204) { amount = 272; goto Meme; }
	if (amount == 317) { amount = 218; goto Meme; }
	if (amount == 148) { amount = 387; goto Meme; }
	if (amount == 259) { amount = 299; goto Meme; }
	if (amount == 278) { amount = 140; goto Meme; }
	if (amount == 374) { amount = 291; goto Meme; }
	if (amount == 238) { amount = 281; goto Meme; }
	if (amount == 1) { amount = 399; goto Meme; }
	if (amount == 288) { amount = 15; goto Meme; }
	if (amount == 48) { amount = 349; goto Meme; }
	if (amount == 392) { amount = 292; goto Meme; }
	if (amount == 373) { amount = 102; goto Meme; }
	if (amount == 326) { amount = 206; goto Meme; }
	if (amount == 314) { amount = 234; goto Meme; }
	if (amount == 346) { amount = 379; goto Meme; }
}
void dummyCall_2()
{
	int amount = 0;
Meme:
	if (amount == 0) { amount = 11; goto Meme; }
	if (amount == 9) { amount = 288; goto Meme; }
	if (amount == 5) { amount = 217; goto Meme; }
	if (amount == 192) { amount = 115; goto Meme; }
	if (amount == 356) { amount = 142; goto Meme; }
	if (amount == 382) { amount = 297; goto Meme; }
	if (amount == 115) { amount = 372; goto Meme; }
	if (amount == 84) { amount = 322; goto Meme; }
	if (amount == 269) { amount = 266; goto Meme; }
	if (amount == 84) { amount = 35; goto Meme; }
	if (amount == 227) { amount = 142; goto Meme; }
	if (amount == 123) { amount = 88; goto Meme; }
	if (amount == 32) { amount = 187; goto Meme; }
	if (amount == 322) { amount = 10; goto Meme; }
	if (amount == 287) { amount = 37; goto Meme; }
	if (amount == 303) { amount = 45; goto Meme; }
	if (amount == 268) { amount = 199; goto Meme; }
	if (amount == 305) { amount = 318; goto Meme; }
	if (amount == 120) { amount = 299; goto Meme; }
	if (amount == 221) { amount = 187; goto Meme; }
	if (amount == 321) { amount = 106; goto Meme; }
	if (amount == 114) { amount = 83; goto Meme; }
	if (amount == 353) { amount = 388; goto Meme; }
	if (amount == 100) { amount = 96; goto Meme; }
	if (amount == 310) { amount = 2; goto Meme; }
	if (amount == 55) { amount = 2; goto Meme; }
	if (amount == 210) { amount = 377; goto Meme; }
	if (amount == 233) { amount = 14; goto Meme; }
	if (amount == 356) { amount = 178; goto Meme; }
	if (amount == 357) { amount = 70; goto Meme; }
	if (amount == 55) { amount = 137; goto Meme; }
	if (amount == 149) { amount = 395; goto Meme; }
	if (amount == 329) { amount = 242; goto Meme; }
	if (amount == 88) { amount = 256; goto Meme; }
	if (amount == 318) { amount = 307; goto Meme; }
	if (amount == 357) { amount = 97; goto Meme; }
	if (amount == 230) { amount = 206; goto Meme; }
	if (amount == 143) { amount = 51; goto Meme; }
	if (amount == 301) { amount = 317; goto Meme; }
	if (amount == 265) { amount = 190; goto Meme; }
	if (amount == 161) { amount = 195; goto Meme; }
	if (amount == 284) { amount = 9; goto Meme; }
	if (amount == 345) { amount = 384; goto Meme; }
	if (amount == 118) { amount = 149; goto Meme; }
	if (amount == 340) { amount = 5; goto Meme; }
	if (amount == 149) { amount = 172; goto Meme; }
	if (amount == 48) { amount = 281; goto Meme; }
	if (amount == 245) { amount = 11; goto Meme; }
	if (amount == 220) { amount = 363; goto Meme; }
	if (amount == 326) { amount = 350; goto Meme; }
	if (amount == 80) { amount = 138; goto Meme; }
	if (amount == 145) { amount = 267; goto Meme; }
	if (amount == 267) { amount = 177; goto Meme; }
	if (amount == 76) { amount = 34; goto Meme; }
	if (amount == 253) { amount = 358; goto Meme; }
	if (amount == 76) { amount = 339; goto Meme; }
	if (amount == 342) { amount = 118; goto Meme; }
	if (amount == 43) { amount = 225; goto Meme; }
	if (amount == 143) { amount = 89; goto Meme; }
	if (amount == 187) { amount = 229; goto Meme; }
	if (amount == 392) { amount = 364; goto Meme; }
	if (amount == 329) { amount = 21; goto Meme; }
	if (amount == 177) { amount = 222; goto Meme; }
	if (amount == 261) { amount = 263; goto Meme; }
	if (amount == 333) { amount = 346; goto Meme; }
	if (amount == 162) { amount = 129; goto Meme; }
	if (amount == 244) { amount = 119; goto Meme; }
	if (amount == 121) { amount = 19; goto Meme; }
	if (amount == 200) { amount = 13; goto Meme; }
	if (amount == 98) { amount = 39; goto Meme; }
	if (amount == 106) { amount = 313; goto Meme; }
	if (amount == 85) { amount = 375; goto Meme; }
	if (amount == 350) { amount = 130; goto Meme; }
	if (amount == 13) { amount = 368; goto Meme; }
	if (amount == 12) { amount = 157; goto Meme; }
	if (amount == 335) { amount = 390; goto Meme; }
	if (amount == 136) { amount = 174; goto Meme; }
	if (amount == 235) { amount = 265; goto Meme; }
	if (amount == 356) { amount = 144; goto Meme; }
	if (amount == 0) { amount = 342; goto Meme; }
	if (amount == 309) { amount = 327; goto Meme; }
	if (amount == 148) { amount = 64; goto Meme; }
	if (amount == 387) { amount = 52; goto Meme; }
	if (amount == 276) { amount = 32; goto Meme; }
	if (amount == 277) { amount = 392; goto Meme; }
	if (amount == 232) { amount = 155; goto Meme; }
	if (amount == 125) { amount = 221; goto Meme; }
	if (amount == 171) { amount = 323; goto Meme; }
	if (amount == 335) { amount = 145; goto Meme; }
	if (amount == 282) { amount = 1; goto Meme; }
	if (amount == 360) { amount = 324; goto Meme; }
	if (amount == 219) { amount = 161; goto Meme; }
	if (amount == 380) { amount = 340; goto Meme; }
	if (amount == 240) { amount = 30; goto Meme; }
	if (amount == 32) { amount = 39; goto Meme; }
	if (amount == 252) { amount = 272; goto Meme; }
	if (amount == 138) { amount = 362; goto Meme; }
	if (amount == 309) { amount = 371; goto Meme; }
	if (amount == 118) { amount = 71; goto Meme; }
	if (amount == 26) { amount = 251; goto Meme; }
	if (amount == 330) { amount = 11; goto Meme; }
	if (amount == 375) { amount = 212; goto Meme; }
	if (amount == 236) { amount = 153; goto Meme; }
	if (amount == 167) { amount = 302; goto Meme; }
	if (amount == 226) { amount = 393; goto Meme; }
	if (amount == 346) { amount = 361; goto Meme; }
	if (amount == 27) { amount = 326; goto Meme; }
	if (amount == 151) { amount = 397; goto Meme; }
	if (amount == 380) { amount = 87; goto Meme; }
	if (amount == 98) { amount = 286; goto Meme; }
	if (amount == 13) { amount = 331; goto Meme; }
	if (amount == 194) { amount = 206; goto Meme; }
	if (amount == 357) { amount = 90; goto Meme; }
	if (amount == 45) { amount = 115; goto Meme; }
	if (amount == 307) { amount = 217; goto Meme; }
	if (amount == 181) { amount = 10; goto Meme; }
	if (amount == 271) { amount = 190; goto Meme; }
	if (amount == 199) { amount = 124; goto Meme; }
	if (amount == 0) { amount = 390; goto Meme; }
	if (amount == 0) { amount = 129; goto Meme; }
	if (amount == 240) { amount = 228; goto Meme; }
	if (amount == 339) { amount = 66; goto Meme; }
	if (amount == 285) { amount = 138; goto Meme; }
	if (amount == 330) { amount = 83; goto Meme; }
	if (amount == 272) { amount = 92; goto Meme; }
	if (amount == 201) { amount = 352; goto Meme; }
	if (amount == 243) { amount = 83; goto Meme; }
	if (amount == 233) { amount = 55; goto Meme; }
	if (amount == 223) { amount = 176; goto Meme; }
	if (amount == 227) { amount = 199; goto Meme; }
	if (amount == 196) { amount = 66; goto Meme; }
	if (amount == 202) { amount = 311; goto Meme; }
	if (amount == 365) { amount = 265; goto Meme; }
	if (amount == 15) { amount = 11; goto Meme; }
	if (amount == 242) { amount = 44; goto Meme; }
	if (amount == 287) { amount = 178; goto Meme; }
	if (amount == 335) { amount = 120; goto Meme; }
	if (amount == 240) { amount = 179; goto Meme; }
	if (amount == 6) { amount = 137; goto Meme; }
	if (amount == 284) { amount = 297; goto Meme; }
	if (amount == 113) { amount = 286; goto Meme; }
	if (amount == 381) { amount = 221; goto Meme; }
	if (amount == 298) { amount = 328; goto Meme; }
	if (amount == 329) { amount = 259; goto Meme; }
	if (amount == 270) { amount = 100; goto Meme; }
	if (amount == 368) { amount = 343; goto Meme; }
	if (amount == 287) { amount = 330; goto Meme; }
	if (amount == 180) { amount = 378; goto Meme; }
	if (amount == 186) { amount = 228; goto Meme; }
	if (amount == 311) { amount = 7; goto Meme; }
	if (amount == 89) { amount = 98; goto Meme; }
	if (amount == 300) { amount = 123; goto Meme; }
	if (amount == 393) { amount = 61; goto Meme; }
	if (amount == 263) { amount = 373; goto Meme; }
	if (amount == 94) { amount = 204; goto Meme; }
	if (amount == 198) { amount = 250; goto Meme; }
	if (amount == 101) { amount = 388; goto Meme; }
	if (amount == 276) { amount = 331; goto Meme; }
	if (amount == 218) { amount = 2; goto Meme; }
	if (amount == 268) { amount = 187; goto Meme; }
	if (amount == 220) { amount = 398; goto Meme; }
	if (amount == 123) { amount = 44; goto Meme; }
	if (amount == 350) { amount = 56; goto Meme; }
	if (amount == 393) { amount = 234; goto Meme; }
	if (amount == 31) { amount = 54; goto Meme; }
	if (amount == 313) { amount = 122; goto Meme; }
	if (amount == 28) { amount = 210; goto Meme; }
	if (amount == 270) { amount = 227; goto Meme; }
	if (amount == 36) { amount = 365; goto Meme; }
	if (amount == 368) { amount = 366; goto Meme; }
	if (amount == 285) { amount = 88; goto Meme; }
	if (amount == 112) { amount = 107; goto Meme; }
	if (amount == 357) { amount = 165; goto Meme; }
	if (amount == 169) { amount = 69; goto Meme; }
	if (amount == 44) { amount = 41; goto Meme; }
	if (amount == 360) { amount = 70; goto Meme; }
	if (amount == 272) { amount = 389; goto Meme; }
	if (amount == 221) { amount = 141; goto Meme; }
	if (amount == 88) { amount = 165; goto Meme; }
	if (amount == 209) { amount = 95; goto Meme; }
	if (amount == 277) { amount = 9; goto Meme; }
	if (amount == 154) { amount = 347; goto Meme; }
	if (amount == 85) { amount = 98; goto Meme; }
	if (amount == 286) { amount = 355; goto Meme; }
	if (amount == 378) { amount = 159; goto Meme; }
	if (amount == 53) { amount = 56; goto Meme; }
	if (amount == 347) { amount = 312; goto Meme; }
	if (amount == 289) { amount = 134; goto Meme; }
	if (amount == 282) { amount = 378; goto Meme; }
	if (amount == 146) { amount = 160; goto Meme; }
	if (amount == 214) { amount = 389; goto Meme; }
	if (amount == 37) { amount = 332; goto Meme; }
	if (amount == 177) { amount = 50; goto Meme; }
	if (amount == 29) { amount = 386; goto Meme; }
	if (amount == 68) { amount = 378; goto Meme; }
	if (amount == 389) { amount = 337; goto Meme; }
	if (amount == 178) { amount = 275; goto Meme; }
	if (amount == 277) { amount = 51; goto Meme; }
	if (amount == 347) { amount = 59; goto Meme; }
	if (amount == 291) { amount = 226; goto Meme; }
	if (amount == 274) { amount = 362; goto Meme; }
	if (amount == 155) { amount = 251; goto Meme; }
	if (amount == 49) { amount = 163; goto Meme; }
	if (amount == 354) { amount = 322; goto Meme; }
	if (amount == 90) { amount = 267; goto Meme; }
	if (amount == 104) { amount = 246; goto Meme; }
	if (amount == 33) { amount = 190; goto Meme; }
	if (amount == 124) { amount = 294; goto Meme; }
	if (amount == 233) { amount = 142; goto Meme; }
	if (amount == 324) { amount = 212; goto Meme; }
	if (amount == 124) { amount = 285; goto Meme; }
	if (amount == 253) { amount = 169; goto Meme; }
	if (amount == 112) { amount = 221; goto Meme; }
	if (amount == 96) { amount = 377; goto Meme; }
	if (amount == 102) { amount = 21; goto Meme; }
	if (amount == 390) { amount = 24; goto Meme; }
	if (amount == 164) { amount = 279; goto Meme; }
	if (amount == 157) { amount = 270; goto Meme; }
	if (amount == 53) { amount = 368; goto Meme; }
	if (amount == 187) { amount = 391; goto Meme; }
	if (amount == 15) { amount = 96; goto Meme; }
	if (amount == 242) { amount = 46; goto Meme; }
	if (amount == 38) { amount = 91; goto Meme; }
	if (amount == 69) { amount = 235; goto Meme; }
	if (amount == 191) { amount = 143; goto Meme; }
	if (amount == 122) { amount = 26; goto Meme; }
	if (amount == 55) { amount = 214; goto Meme; }
	if (amount == 272) { amount = 190; goto Meme; }
	if (amount == 133) { amount = 206; goto Meme; }
	if (amount == 99) { amount = 117; goto Meme; }
	if (amount == 334) { amount = 152; goto Meme; }
	if (amount == 142) { amount = 30; goto Meme; }
	if (amount == 72) { amount = 334; goto Meme; }
	if (amount == 176) { amount = 345; goto Meme; }
	if (amount == 128) { amount = 56; goto Meme; }
	if (amount == 355) { amount = 190; goto Meme; }
	if (amount == 336) { amount = 49; goto Meme; }
	if (amount == 104) { amount = 288; goto Meme; }
	if (amount == 363) { amount = 277; goto Meme; }
	if (amount == 343) { amount = 99; goto Meme; }
	if (amount == 379) { amount = 253; goto Meme; }
	if (amount == 214) { amount = 348; goto Meme; }
	if (amount == 93) { amount = 63; goto Meme; }
	if (amount == 247) { amount = 296; goto Meme; }
	if (amount == 347) { amount = 272; goto Meme; }
	if (amount == 119) { amount = 208; goto Meme; }
	if (amount == 331) { amount = 219; goto Meme; }
	if (amount == 164) { amount = 315; goto Meme; }
	if (amount == 69) { amount = 135; goto Meme; }
	if (amount == 143) { amount = 116; goto Meme; }
	if (amount == 171) { amount = 195; goto Meme; }
	if (amount == 386) { amount = 93; goto Meme; }
	if (amount == 116) { amount = 261; goto Meme; }
	if (amount == 276) { amount = 181; goto Meme; }
	if (amount == 346) { amount = 36; goto Meme; }
	if (amount == 74) { amount = 390; goto Meme; }
	if (amount == 309) { amount = 130; goto Meme; }
	if (amount == 64) { amount = 210; goto Meme; }
	if (amount == 166) { amount = 334; goto Meme; }
	if (amount == 233) { amount = 143; goto Meme; }
	if (amount == 41) { amount = 313; goto Meme; }
	if (amount == 292) { amount = 128; goto Meme; }
	if (amount == 309) { amount = 328; goto Meme; }
	if (amount == 31) { amount = 247; goto Meme; }
	if (amount == 309) { amount = 281; goto Meme; }
	if (amount == 256) { amount = 40; goto Meme; }
	if (amount == 44) { amount = 185; goto Meme; }
	if (amount == 65) { amount = 175; goto Meme; }
	if (amount == 101) { amount = 21; goto Meme; }
	if (amount == 12) { amount = 212; goto Meme; }
	if (amount == 217) { amount = 192; goto Meme; }
	if (amount == 120) { amount = 141; goto Meme; }
	if (amount == 213) { amount = 276; goto Meme; }
	if (amount == 178) { amount = 389; goto Meme; }
	if (amount == 106) { amount = 397; goto Meme; }
	if (amount == 111) { amount = 284; goto Meme; }
	if (amount == 150) { amount = 146; goto Meme; }
	if (amount == 161) { amount = 336; goto Meme; }
	if (amount == 84) { amount = 389; goto Meme; }
	if (amount == 8) { amount = 90; goto Meme; }
	if (amount == 64) { amount = 253; goto Meme; }
	if (amount == 91) { amount = 347; goto Meme; }
	if (amount == 109) { amount = 66; goto Meme; }
	if (amount == 136) { amount = 297; goto Meme; }
	if (amount == 186) { amount = 73; goto Meme; }
	if (amount == 312) { amount = 309; goto Meme; }
	if (amount == 146) { amount = 272; goto Meme; }
	if (amount == 86) { amount = 111; goto Meme; }
	if (amount == 131) { amount = 221; goto Meme; }
	if (amount == 33) { amount = 172; goto Meme; }
	if (amount == 273) { amount = 226; goto Meme; }
	if (amount == 384) { amount = 199; goto Meme; }
	if (amount == 396) { amount = 275; goto Meme; }
	if (amount == 278) { amount = 69; goto Meme; }
	if (amount == 240) { amount = 347; goto Meme; }
	if (amount == 151) { amount = 269; goto Meme; }
	if (amount == 348) { amount = 124; goto Meme; }
	if (amount == 265) { amount = 216; goto Meme; }
	if (amount == 229) { amount = 245; goto Meme; }
	if (amount == 62) { amount = 357; goto Meme; }
	if (amount == 379) { amount = 345; goto Meme; }
	if (amount == 81) { amount = 17; goto Meme; }
	if (amount == 27) { amount = 206; goto Meme; }
	if (amount == 143) { amount = 389; goto Meme; }
	if (amount == 391) { amount = 275; goto Meme; }
	if (amount == 184) { amount = 192; goto Meme; }
	if (amount == 228) { amount = 261; goto Meme; }
	if (amount == 213) { amount = 294; goto Meme; }
	if (amount == 146) { amount = 20; goto Meme; }
	if (amount == 237) { amount = 9; goto Meme; }
	if (amount == 257) { amount = 50; goto Meme; }
	if (amount == 371) { amount = 103; goto Meme; }
	if (amount == 130) { amount = 347; goto Meme; }
	if (amount == 2) { amount = 132; goto Meme; }
	if (amount == 27) { amount = 203; goto Meme; }
	if (amount == 268) { amount = 42; goto Meme; }
	if (amount == 240) { amount = 317; goto Meme; }
	if (amount == 398) { amount = 254; goto Meme; }
	if (amount == 126) { amount = 160; goto Meme; }
	if (amount == 249) { amount = 357; goto Meme; }
	if (amount == 201) { amount = 239; goto Meme; }
	if (amount == 157) { amount = 391; goto Meme; }
	if (amount == 297) { amount = 320; goto Meme; }
	if (amount == 118) { amount = 307; goto Meme; }
	if (amount == 48) { amount = 156; goto Meme; }
	if (amount == 235) { amount = 147; goto Meme; }
	if (amount == 15) { amount = 49; goto Meme; }
	if (amount == 309) { amount = 305; goto Meme; }
	if (amount == 394) { amount = 165; goto Meme; }
	if (amount == 397) { amount = 265; goto Meme; }
	if (amount == 233) { amount = 252; goto Meme; }
	if (amount == 201) { amount = 369; goto Meme; }
	if (amount == 177) { amount = 60; goto Meme; }
	if (amount == 217) { amount = 87; goto Meme; }
	if (amount == 274) { amount = 271; goto Meme; }
	if (amount == 284) { amount = 330; goto Meme; }
	if (amount == 353) { amount = 296; goto Meme; }
	if (amount == 120) { amount = 395; goto Meme; }
	if (amount == 105) { amount = 218; goto Meme; }
	if (amount == 74) { amount = 69; goto Meme; }
	if (amount == 334) { amount = 213; goto Meme; }
	if (amount == 283) { amount = 187; goto Meme; }
	if (amount == 195) { amount = 34; goto Meme; }
	if (amount == 356) { amount = 49; goto Meme; }
	if (amount == 204) { amount = 177; goto Meme; }
	if (amount == 291) { amount = 158; goto Meme; }
	if (amount == 102) { amount = 112; goto Meme; }
	if (amount == 398) { amount = 49; goto Meme; }
	if (amount == 278) { amount = 127; goto Meme; }
	if (amount == 231) { amount = 225; goto Meme; }
	if (amount == 63) { amount = 179; goto Meme; }
	if (amount == 257) { amount = 9; goto Meme; }
	if (amount == 120) { amount = 24; goto Meme; }
	if (amount == 82) { amount = 68; goto Meme; }
	if (amount == 109) { amount = 74; goto Meme; }
	if (amount == 314) { amount = 5; goto Meme; }
	if (amount == 388) { amount = 37; goto Meme; }
	if (amount == 259) { amount = 314; goto Meme; }
	if (amount == 371) { amount = 395; goto Meme; }
	if (amount == 297) { amount = 209; goto Meme; }
	if (amount == 209) { amount = 294; goto Meme; }
	if (amount == 59) { amount = 268; goto Meme; }
	if (amount == 58) { amount = 271; goto Meme; }
	if (amount == 354) { amount = 322; goto Meme; }
	if (amount == 151) { amount = 127; goto Meme; }
	if (amount == 242) { amount = 390; goto Meme; }
	if (amount == 157) { amount = 291; goto Meme; }
	if (amount == 64) { amount = 300; goto Meme; }
	if (amount == 356) { amount = 309; goto Meme; }
	if (amount == 291) { amount = 56; goto Meme; }
	if (amount == 299) { amount = 9; goto Meme; }
	if (amount == 61) { amount = 201; goto Meme; }
	if (amount == 138) { amount = 197; goto Meme; }
	if (amount == 283) { amount = 119; goto Meme; }
	if (amount == 89) { amount = 325; goto Meme; }
	if (amount == 43) { amount = 281; goto Meme; }
	if (amount == 239) { amount = 253; goto Meme; }
	if (amount == 190) { amount = 394; goto Meme; }
	if (amount == 157) { amount = 384; goto Meme; }
	if (amount == 222) { amount = 156; goto Meme; }
	if (amount == 284) { amount = 353; goto Meme; }
	if (amount == 258) { amount = 349; goto Meme; }
	if (amount == 180) { amount = 57; goto Meme; }
	if (amount == 192) { amount = 362; goto Meme; }
	if (amount == 335) { amount = 200; goto Meme; }
	if (amount == 2) { amount = 17; goto Meme; }
	if (amount == 365) { amount = 319; goto Meme; }
	if (amount == 396) { amount = 75; goto Meme; }
	if (amount == 265) { amount = 13; goto Meme; }
	if (amount == 188) { amount = 42; goto Meme; }
	if (amount == 91) { amount = 56; goto Meme; }
	if (amount == 259) { amount = 191; goto Meme; }
	if (amount == 272) { amount = 142; goto Meme; }
	if (amount == 276) { amount = 48; goto Meme; }
	if (amount == 87) { amount = 349; goto Meme; }
	if (amount == 346) { amount = 248; goto Meme; }
	if (amount == 45) { amount = 288; goto Meme; }
	if (amount == 95) { amount = 111; goto Meme; }
	if (amount == 124) { amount = 123; goto Meme; }
	if (amount == 154) { amount = 187; goto Meme; }
	if (amount == 239) { amount = 393; goto Meme; }
}
void dummyCall_3()
{
	int amount = 0;
Meme:
	if (amount == 0) { amount = 11; goto Meme; }
	if (amount == 117) { amount = 137; goto Meme; }
	if (amount == 99) { amount = 275; goto Meme; }
	if (amount == 93) { amount = 226; goto Meme; }
	if (amount == 363) { amount = 245; goto Meme; }
	if (amount == 209) { amount = 19; goto Meme; }
	if (amount == 34) { amount = 225; goto Meme; }
	if (amount == 203) { amount = 94; goto Meme; }
	if (amount == 146) { amount = 167; goto Meme; }
	if (amount == 342) { amount = 243; goto Meme; }
	if (amount == 305) { amount = 24; goto Meme; }
	if (amount == 387) { amount = 239; goto Meme; }
	if (amount == 2) { amount = 293; goto Meme; }
	if (amount == 300) { amount = 101; goto Meme; }
	if (amount == 173) { amount = 279; goto Meme; }
	if (amount == 391) { amount = 193; goto Meme; }
	if (amount == 195) { amount = 384; goto Meme; }
	if (amount == 78) { amount = 280; goto Meme; }
	if (amount == 189) { amount = 161; goto Meme; }
	if (amount == 124) { amount = 115; goto Meme; }
	if (amount == 389) { amount = 286; goto Meme; }
	if (amount == 314) { amount = 206; goto Meme; }
	if (amount == 343) { amount = 351; goto Meme; }
	if (amount == 172) { amount = 220; goto Meme; }
	if (amount == 281) { amount = 232; goto Meme; }
	if (amount == 149) { amount = 317; goto Meme; }
	if (amount == 89) { amount = 236; goto Meme; }
	if (amount == 354) { amount = 323; goto Meme; }
	if (amount == 246) { amount = 141; goto Meme; }
	if (amount == 85) { amount = 1; goto Meme; }
	if (amount == 385) { amount = 311; goto Meme; }
	if (amount == 65) { amount = 69; goto Meme; }
	if (amount == 213) { amount = 286; goto Meme; }
	if (amount == 6) { amount = 327; goto Meme; }
	if (amount == 213) { amount = 340; goto Meme; }
	if (amount == 189) { amount = 338; goto Meme; }
	if (amount == 389) { amount = 80; goto Meme; }
	if (amount == 326) { amount = 180; goto Meme; }
	if (amount == 45) { amount = 348; goto Meme; }
	if (amount == 399) { amount = 65; goto Meme; }
	if (amount == 233) { amount = 301; goto Meme; }
	if (amount == 329) { amount = 76; goto Meme; }
	if (amount == 275) { amount = 297; goto Meme; }
	if (amount == 166) { amount = 200; goto Meme; }
	if (amount == 165) { amount = 243; goto Meme; }
	if (amount == 53) { amount = 187; goto Meme; }
	if (amount == 266) { amount = 346; goto Meme; }
	if (amount == 145) { amount = 84; goto Meme; }
	if (amount == 37) { amount = 228; goto Meme; }
	if (amount == 150) { amount = 159; goto Meme; }
	if (amount == 20) { amount = 325; goto Meme; }
	if (amount == 278) { amount = 279; goto Meme; }
	if (amount == 70) { amount = 340; goto Meme; }
	if (amount == 91) { amount = 220; goto Meme; }
	if (amount == 58) { amount = 304; goto Meme; }
	if (amount == 206) { amount = 293; goto Meme; }
	if (amount == 42) { amount = 382; goto Meme; }
	if (amount == 56) { amount = 55; goto Meme; }
	if (amount == 120) { amount = 167; goto Meme; }
	if (amount == 198) { amount = 166; goto Meme; }
	if (amount == 24) { amount = 256; goto Meme; }
	if (amount == 162) { amount = 12; goto Meme; }
	if (amount == 158) { amount = 41; goto Meme; }
	if (amount == 320) { amount = 264; goto Meme; }
	if (amount == 185) { amount = 138; goto Meme; }
	if (amount == 278) { amount = 264; goto Meme; }
	if (amount == 305) { amount = 90; goto Meme; }
	if (amount == 384) { amount = 314; goto Meme; }
	if (amount == 93) { amount = 99; goto Meme; }
	if (amount == 115) { amount = 111; goto Meme; }
	if (amount == 88) { amount = 243; goto Meme; }
	if (amount == 384) { amount = 289; goto Meme; }
	if (amount == 244) { amount = 196; goto Meme; }
	if (amount == 59) { amount = 295; goto Meme; }
	if (amount == 255) { amount = 206; goto Meme; }
	if (amount == 364) { amount = 278; goto Meme; }
	if (amount == 54) { amount = 282; goto Meme; }
	if (amount == 389) { amount = 395; goto Meme; }
	if (amount == 87) { amount = 282; goto Meme; }
	if (amount == 150) { amount = 22; goto Meme; }
	if (amount == 75) { amount = 264; goto Meme; }
	if (amount == 110) { amount = 137; goto Meme; }
	if (amount == 4) { amount = 13; goto Meme; }
	if (amount == 339) { amount = 274; goto Meme; }
	if (amount == 20) { amount = 67; goto Meme; }
	if (amount == 116) { amount = 212; goto Meme; }
	if (amount == 110) { amount = 253; goto Meme; }
	if (amount == 124) { amount = 29; goto Meme; }
	if (amount == 336) { amount = 277; goto Meme; }
	if (amount == 249) { amount = 211; goto Meme; }
	if (amount == 161) { amount = 374; goto Meme; }
	if (amount == 78) { amount = 112; goto Meme; }
	if (amount == 343) { amount = 43; goto Meme; }
	if (amount == 102) { amount = 0; goto Meme; }
	if (amount == 221) { amount = 359; goto Meme; }
	if (amount == 363) { amount = 297; goto Meme; }
	if (amount == 83) { amount = 167; goto Meme; }
	if (amount == 22) { amount = 315; goto Meme; }
	if (amount == 38) { amount = 101; goto Meme; }
	if (amount == 311) { amount = 183; goto Meme; }
	if (amount == 306) { amount = 238; goto Meme; }
	if (amount == 70) { amount = 292; goto Meme; }
	if (amount == 85) { amount = 54; goto Meme; }
	if (amount == 27) { amount = 80; goto Meme; }
	if (amount == 5) { amount = 314; goto Meme; }
	if (amount == 364) { amount = 196; goto Meme; }
	if (amount == 389) { amount = 327; goto Meme; }
	if (amount == 293) { amount = 203; goto Meme; }
	if (amount == 180) { amount = 105; goto Meme; }
	if (amount == 317) { amount = 133; goto Meme; }
	if (amount == 70) { amount = 391; goto Meme; }
	if (amount == 390) { amount = 183; goto Meme; }
	if (amount == 248) { amount = 157; goto Meme; }
	if (amount == 5) { amount = 373; goto Meme; }
	if (amount == 398) { amount = 393; goto Meme; }
	if (amount == 35) { amount = 258; goto Meme; }
	if (amount == 31) { amount = 90; goto Meme; }
	if (amount == 339) { amount = 391; goto Meme; }
	if (amount == 211) { amount = 166; goto Meme; }
	if (amount == 325) { amount = 35; goto Meme; }
	if (amount == 107) { amount = 108; goto Meme; }
	if (amount == 122) { amount = 210; goto Meme; }
	if (amount == 243) { amount = 89; goto Meme; }
	if (amount == 297) { amount = 112; goto Meme; }
	if (amount == 276) { amount = 222; goto Meme; }
	if (amount == 338) { amount = 304; goto Meme; }
	if (amount == 396) { amount = 97; goto Meme; }
	if (amount == 368) { amount = 168; goto Meme; }
	if (amount == 34) { amount = 259; goto Meme; }
	if (amount == 340) { amount = 63; goto Meme; }
	if (amount == 324) { amount = 99; goto Meme; }
	if (amount == 352) { amount = 267; goto Meme; }
	if (amount == 275) { amount = 49; goto Meme; }
	if (amount == 337) { amount = 324; goto Meme; }
	if (amount == 370) { amount = 5; goto Meme; }
	if (amount == 354) { amount = 173; goto Meme; }
	if (amount == 187) { amount = 241; goto Meme; }
	if (amount == 396) { amount = 260; goto Meme; }
	if (amount == 99) { amount = 116; goto Meme; }
	if (amount == 82) { amount = 23; goto Meme; }
	if (amount == 239) { amount = 193; goto Meme; }
	if (amount == 124) { amount = 265; goto Meme; }
	if (amount == 199) { amount = 95; goto Meme; }
	if (amount == 2) { amount = 229; goto Meme; }
	if (amount == 137) { amount = 18; goto Meme; }
	if (amount == 363) { amount = 211; goto Meme; }
	if (amount == 337) { amount = 154; goto Meme; }
	if (amount == 38) { amount = 73; goto Meme; }
	if (amount == 343) { amount = 122; goto Meme; }
	if (amount == 234) { amount = 148; goto Meme; }
	if (amount == 122) { amount = 60; goto Meme; }
	if (amount == 121) { amount = 167; goto Meme; }
	if (amount == 188) { amount = 115; goto Meme; }
	if (amount == 282) { amount = 322; goto Meme; }
	if (amount == 350) { amount = 129; goto Meme; }
	if (amount == 375) { amount = 7; goto Meme; }
	if (amount == 206) { amount = 202; goto Meme; }
	if (amount == 52) { amount = 377; goto Meme; }
	if (amount == 125) { amount = 168; goto Meme; }
	if (amount == 66) { amount = 166; goto Meme; }
	if (amount == 214) { amount = 320; goto Meme; }
	if (amount == 258) { amount = 279; goto Meme; }
	if (amount == 396) { amount = 198; goto Meme; }
	if (amount == 141) { amount = 229; goto Meme; }
	if (amount == 371) { amount = 301; goto Meme; }
	if (amount == 212) { amount = 190; goto Meme; }
	if (amount == 65) { amount = 241; goto Meme; }
	if (amount == 4) { amount = 312; goto Meme; }
	if (amount == 246) { amount = 376; goto Meme; }
	if (amount == 124) { amount = 117; goto Meme; }
	if (amount == 363) { amount = 246; goto Meme; }
	if (amount == 210) { amount = 264; goto Meme; }
	if (amount == 375) { amount = 144; goto Meme; }
	if (amount == 386) { amount = 104; goto Meme; }
	if (amount == 168) { amount = 132; goto Meme; }
	if (amount == 104) { amount = 370; goto Meme; }
	if (amount == 80) { amount = 375; goto Meme; }
	if (amount == 33) { amount = 275; goto Meme; }
	if (amount == 109) { amount = 31; goto Meme; }
	if (amount == 77) { amount = 278; goto Meme; }
	if (amount == 349) { amount = 322; goto Meme; }
	if (amount == 216) { amount = 155; goto Meme; }
	if (amount == 385) { amount = 301; goto Meme; }
	if (amount == 313) { amount = 297; goto Meme; }
	if (amount == 226) { amount = 122; goto Meme; }
	if (amount == 90) { amount = 37; goto Meme; }
	if (amount == 50) { amount = 156; goto Meme; }
	if (amount == 153) { amount = 115; goto Meme; }
	if (amount == 373) { amount = 269; goto Meme; }
	if (amount == 110) { amount = 221; goto Meme; }
	if (amount == 31) { amount = 235; goto Meme; }
	if (amount == 366) { amount = 290; goto Meme; }
	if (amount == 15) { amount = 270; goto Meme; }
	if (amount == 79) { amount = 112; goto Meme; }
	if (amount == 28) { amount = 157; goto Meme; }
	if (amount == 30) { amount = 53; goto Meme; }
	if (amount == 239) { amount = 177; goto Meme; }
	if (amount == 205) { amount = 354; goto Meme; }
	if (amount == 306) { amount = 185; goto Meme; }
	if (amount == 65) { amount = 98; goto Meme; }
	if (amount == 55) { amount = 368; goto Meme; }
	if (amount == 331) { amount = 281; goto Meme; }
	if (amount == 204) { amount = 76; goto Meme; }
	if (amount == 341) { amount = 208; goto Meme; }
	if (amount == 285) { amount = 72; goto Meme; }
	if (amount == 127) { amount = 208; goto Meme; }
	if (amount == 395) { amount = 357; goto Meme; }
	if (amount == 266) { amount = 365; goto Meme; }
	if (amount == 59) { amount = 108; goto Meme; }
	if (amount == 278) { amount = 278; goto Meme; }
	if (amount == 386) { amount = 376; goto Meme; }
	if (amount == 23) { amount = 281; goto Meme; }
	if (amount == 256) { amount = 34; goto Meme; }
	if (amount == 125) { amount = 172; goto Meme; }
	if (amount == 330) { amount = 76; goto Meme; }
	if (amount == 212) { amount = 250; goto Meme; }
	if (amount == 285) { amount = 273; goto Meme; }
	if (amount == 88) { amount = 26; goto Meme; }
	if (amount == 128) { amount = 188; goto Meme; }
	if (amount == 13) { amount = 310; goto Meme; }
	if (amount == 329) { amount = 265; goto Meme; }
	if (amount == 127) { amount = 123; goto Meme; }
	if (amount == 386) { amount = 10; goto Meme; }
	if (amount == 294) { amount = 60; goto Meme; }
	if (amount == 349) { amount = 11; goto Meme; }
	if (amount == 60) { amount = 364; goto Meme; }
	if (amount == 22) { amount = 56; goto Meme; }
	if (amount == 81) { amount = 75; goto Meme; }
	if (amount == 281) { amount = 13; goto Meme; }
	if (amount == 110) { amount = 1; goto Meme; }
	if (amount == 275) { amount = 381; goto Meme; }
	if (amount == 377) { amount = 377; goto Meme; }
	if (amount == 301) { amount = 151; goto Meme; }
	if (amount == 185) { amount = 384; goto Meme; }
	if (amount == 134) { amount = 310; goto Meme; }
	if (amount == 251) { amount = 382; goto Meme; }
	if (amount == 80) { amount = 8; goto Meme; }
	if (amount == 20) { amount = 291; goto Meme; }
	if (amount == 111) { amount = 274; goto Meme; }
	if (amount == 72) { amount = 294; goto Meme; }
	if (amount == 13) { amount = 146; goto Meme; }
	if (amount == 378) { amount = 42; goto Meme; }
	if (amount == 257) { amount = 293; goto Meme; }
	if (amount == 68) { amount = 275; goto Meme; }
	if (amount == 320) { amount = 250; goto Meme; }
	if (amount == 345) { amount = 72; goto Meme; }
	if (amount == 101) { amount = 182; goto Meme; }
	if (amount == 186) { amount = 264; goto Meme; }
	if (amount == 78) { amount = 393; goto Meme; }
	if (amount == 134) { amount = 178; goto Meme; }
	if (amount == 215) { amount = 257; goto Meme; }
	if (amount == 165) { amount = 143; goto Meme; }
	if (amount == 379) { amount = 78; goto Meme; }
	if (amount == 103) { amount = 387; goto Meme; }
	if (amount == 215) { amount = 325; goto Meme; }
	if (amount == 360) { amount = 212; goto Meme; }
	if (amount == 241) { amount = 265; goto Meme; }
	if (amount == 103) { amount = 154; goto Meme; }
	if (amount == 121) { amount = 87; goto Meme; }
	if (amount == 216) { amount = 376; goto Meme; }
	if (amount == 112) { amount = 161; goto Meme; }
	if (amount == 38) { amount = 393; goto Meme; }
	if (amount == 310) { amount = 222; goto Meme; }
	if (amount == 365) { amount = 383; goto Meme; }
	if (amount == 24) { amount = 207; goto Meme; }
	if (amount == 103) { amount = 104; goto Meme; }
	if (amount == 42) { amount = 341; goto Meme; }
	if (amount == 5) { amount = 34; goto Meme; }
	if (amount == 288) { amount = 1; goto Meme; }
	if (amount == 224) { amount = 49; goto Meme; }
	if (amount == 196) { amount = 140; goto Meme; }
	if (amount == 256) { amount = 350; goto Meme; }
	if (amount == 355) { amount = 168; goto Meme; }
	if (amount == 61) { amount = 114; goto Meme; }
	if (amount == 392) { amount = 166; goto Meme; }
	if (amount == 356) { amount = 67; goto Meme; }
	if (amount == 318) { amount = 314; goto Meme; }
	if (amount == 381) { amount = 46; goto Meme; }
	if (amount == 256) { amount = 140; goto Meme; }
	if (amount == 379) { amount = 198; goto Meme; }
	if (amount == 3) { amount = 353; goto Meme; }
	if (amount == 307) { amount = 331; goto Meme; }
	if (amount == 263) { amount = 9; goto Meme; }
	if (amount == 193) { amount = 255; goto Meme; }
	if (amount == 73) { amount = 282; goto Meme; }
	if (amount == 119) { amount = 165; goto Meme; }
	if (amount == 157) { amount = 125; goto Meme; }
	if (amount == 327) { amount = 299; goto Meme; }
	if (amount == 202) { amount = 103; goto Meme; }
	if (amount == 98) { amount = 314; goto Meme; }
	if (amount == 390) { amount = 363; goto Meme; }
	if (amount == 130) { amount = 91; goto Meme; }
	if (amount == 132) { amount = 189; goto Meme; }
	if (amount == 54) { amount = 316; goto Meme; }
	if (amount == 298) { amount = 314; goto Meme; }
	if (amount == 332) { amount = 195; goto Meme; }
	if (amount == 280) { amount = 103; goto Meme; }
	if (amount == 20) { amount = 339; goto Meme; }
	if (amount == 38) { amount = 375; goto Meme; }
	if (amount == 81) { amount = 93; goto Meme; }
	if (amount == 190) { amount = 145; goto Meme; }
	if (amount == 211) { amount = 24; goto Meme; }
	if (amount == 250) { amount = 257; goto Meme; }
	if (amount == 340) { amount = 276; goto Meme; }
	if (amount == 191) { amount = 302; goto Meme; }
	if (amount == 112) { amount = 251; goto Meme; }
	if (amount == 346) { amount = 268; goto Meme; }
	if (amount == 344) { amount = 249; goto Meme; }
	if (amount == 73) { amount = 387; goto Meme; }
	if (amount == 152) { amount = 302; goto Meme; }
	if (amount == 77) { amount = 15; goto Meme; }
	if (amount == 359) { amount = 289; goto Meme; }
	if (amount == 142) { amount = 281; goto Meme; }
	if (amount == 32) { amount = 343; goto Meme; }
	if (amount == 240) { amount = 246; goto Meme; }
	if (amount == 367) { amount = 196; goto Meme; }
	if (amount == 53) { amount = 31; goto Meme; }
	if (amount == 141) { amount = 162; goto Meme; }
	if (amount == 36) { amount = 241; goto Meme; }
	if (amount == 336) { amount = 288; goto Meme; }
	if (amount == 24) { amount = 277; goto Meme; }
	if (amount == 285) { amount = 396; goto Meme; }
	if (amount == 140) { amount = 211; goto Meme; }
	if (amount == 143) { amount = 68; goto Meme; }
	if (amount == 389) { amount = 50; goto Meme; }
	if (amount == 364) { amount = 202; goto Meme; }
	if (amount == 208) { amount = 51; goto Meme; }
	if (amount == 70) { amount = 246; goto Meme; }
	if (amount == 174) { amount = 223; goto Meme; }
	if (amount == 320) { amount = 336; goto Meme; }
	if (amount == 316) { amount = 334; goto Meme; }
	if (amount == 209) { amount = 238; goto Meme; }
	if (amount == 344) { amount = 58; goto Meme; }
	if (amount == 238) { amount = 314; goto Meme; }
	if (amount == 322) { amount = 115; goto Meme; }
	if (amount == 323) { amount = 200; goto Meme; }
	if (amount == 335) { amount = 292; goto Meme; }
	if (amount == 289) { amount = 230; goto Meme; }
	if (amount == 324) { amount = 182; goto Meme; }
	if (amount == 207) { amount = 197; goto Meme; }
	if (amount == 225) { amount = 212; goto Meme; }
	if (amount == 394) { amount = 296; goto Meme; }
	if (amount == 155) { amount = 126; goto Meme; }
	if (amount == 207) { amount = 395; goto Meme; }
	if (amount == 222) { amount = 50; goto Meme; }
	if (amount == 315) { amount = 149; goto Meme; }
	if (amount == 195) { amount = 215; goto Meme; }
	if (amount == 209) { amount = 176; goto Meme; }
	if (amount == 271) { amount = 332; goto Meme; }
	if (amount == 251) { amount = 297; goto Meme; }
	if (amount == 92) { amount = 385; goto Meme; }
	if (amount == 148) { amount = 99; goto Meme; }
	if (amount == 284) { amount = 260; goto Meme; }
	if (amount == 150) { amount = 337; goto Meme; }
	if (amount == 267) { amount = 175; goto Meme; }
	if (amount == 320) { amount = 244; goto Meme; }
	if (amount == 52) { amount = 79; goto Meme; }
	if (amount == 234) { amount = 65; goto Meme; }
	if (amount == 358) { amount = 344; goto Meme; }
	if (amount == 283) { amount = 151; goto Meme; }
	if (amount == 297) { amount = 232; goto Meme; }
	if (amount == 203) { amount = 191; goto Meme; }
	if (amount == 316) { amount = 362; goto Meme; }
	if (amount == 101) { amount = 165; goto Meme; }
	if (amount == 32) { amount = 235; goto Meme; }
	if (amount == 47) { amount = 262; goto Meme; }
	if (amount == 43) { amount = 354; goto Meme; }
	if (amount == 125) { amount = 266; goto Meme; }
	if (amount == 326) { amount = 171; goto Meme; }
	if (amount == 242) { amount = 244; goto Meme; }
	if (amount == 279) { amount = 213; goto Meme; }
	if (amount == 169) { amount = 104; goto Meme; }
	if (amount == 134) { amount = 381; goto Meme; }
	if (amount == 228) { amount = 237; goto Meme; }
	if (amount == 202) { amount = 74; goto Meme; }
	if (amount == 18) { amount = 322; goto Meme; }
	if (amount == 228) { amount = 218; goto Meme; }
	if (amount == 86) { amount = 342; goto Meme; }
	if (amount == 95) { amount = 381; goto Meme; }
	if (amount == 358) { amount = 178; goto Meme; }
	if (amount == 261) { amount = 273; goto Meme; }
	if (amount == 49) { amount = 106; goto Meme; }
	if (amount == 182) { amount = 221; goto Meme; }
	if (amount == 340) { amount = 69; goto Meme; }
	if (amount == 309) { amount = 3; goto Meme; }
	if (amount == 399) { amount = 120; goto Meme; }
	if (amount == 19) { amount = 351; goto Meme; }
	if (amount == 211) { amount = 233; goto Meme; }
	if (amount == 368) { amount = 293; goto Meme; }
	if (amount == 207) { amount = 307; goto Meme; }
	if (amount == 350) { amount = 250; goto Meme; }
	if (amount == 364) { amount = 6; goto Meme; }
	if (amount == 185) { amount = 113; goto Meme; }
	if (amount == 389) { amount = 321; goto Meme; }
	if (amount == 196) { amount = 313; goto Meme; }
	if (amount == 219) { amount = 386; goto Meme; }
	if (amount == 182) { amount = 293; goto Meme; }
	if (amount == 328) { amount = 364; goto Meme; }
	if (amount == 261) { amount = 92; goto Meme; }
	if (amount == 83) { amount = 235; goto Meme; }
	if (amount == 113) { amount = 114; goto Meme; }
}
void dummyCall_4()
{
	int amount = 0;
Meme:
	if (amount == 0) { amount = 11; goto Meme; }
	if (amount == 182) { amount = 129; goto Meme; }
	if (amount == 134) { amount = 389; goto Meme; }
	if (amount == 208) { amount = 24; goto Meme; }
	if (amount == 276) { amount = 36; goto Meme; }
	if (amount == 360) { amount = 129; goto Meme; }
	if (amount == 276) { amount = 306; goto Meme; }
	if (amount == 196) { amount = 141; goto Meme; }
	if (amount == 6) { amount = 81; goto Meme; }
	if (amount == 46) { amount = 332; goto Meme; }
	if (amount == 151) { amount = 165; goto Meme; }
	if (amount == 121) { amount = 178; goto Meme; }
	if (amount == 218) { amount = 313; goto Meme; }
	if (amount == 247) { amount = 301; goto Meme; }
	if (amount == 360) { amount = 112; goto Meme; }
	if (amount == 42) { amount = 278; goto Meme; }
	if (amount == 246) { amount = 335; goto Meme; }
	if (amount == 154) { amount = 374; goto Meme; }
	if (amount == 343) { amount = 41; goto Meme; }
	if (amount == 71) { amount = 395; goto Meme; }
	if (amount == 65) { amount = 186; goto Meme; }
	if (amount == 128) { amount = 380; goto Meme; }
	if (amount == 4) { amount = 313; goto Meme; }
	if (amount == 211) { amount = 297; goto Meme; }
	if (amount == 136) { amount = 183; goto Meme; }
	if (amount == 53) { amount = 166; goto Meme; }
	if (amount == 6) { amount = 205; goto Meme; }
	if (amount == 4) { amount = 137; goto Meme; }
	if (amount == 330) { amount = 374; goto Meme; }
	if (amount == 315) { amount = 178; goto Meme; }
	if (amount == 23) { amount = 232; goto Meme; }
	if (amount == 294) { amount = 251; goto Meme; }
	if (amount == 156) { amount = 281; goto Meme; }
	if (amount == 311) { amount = 384; goto Meme; }
	if (amount == 390) { amount = 79; goto Meme; }
	if (amount == 168) { amount = 225; goto Meme; }
	if (amount == 22) { amount = 104; goto Meme; }
	if (amount == 290) { amount = 70; goto Meme; }
	if (amount == 52) { amount = 107; goto Meme; }
	if (amount == 237) { amount = 242; goto Meme; }
	if (amount == 180) { amount = 95; goto Meme; }
	if (amount == 313) { amount = 90; goto Meme; }
	if (amount == 232) { amount = 27; goto Meme; }
	if (amount == 45) { amount = 248; goto Meme; }
	if (amount == 278) { amount = 190; goto Meme; }
	if (amount == 398) { amount = 331; goto Meme; }
	if (amount == 12) { amount = 288; goto Meme; }
	if (amount == 34) { amount = 257; goto Meme; }
	if (amount == 337) { amount = 328; goto Meme; }
	if (amount == 324) { amount = 8; goto Meme; }
	if (amount == 317) { amount = 207; goto Meme; }
	if (amount == 43) { amount = 242; goto Meme; }
	if (amount == 155) { amount = 84; goto Meme; }
	if (amount == 311) { amount = 391; goto Meme; }
	if (amount == 30) { amount = 322; goto Meme; }
	if (amount == 348) { amount = 127; goto Meme; }
	if (amount == 179) { amount = 351; goto Meme; }
	if (amount == 82) { amount = 368; goto Meme; }
	if (amount == 70) { amount = 343; goto Meme; }
	if (amount == 331) { amount = 340; goto Meme; }
	if (amount == 263) { amount = 121; goto Meme; }
	if (amount == 327) { amount = 47; goto Meme; }
	if (amount == 349) { amount = 399; goto Meme; }
	if (amount == 21) { amount = 64; goto Meme; }
	if (amount == 235) { amount = 228; goto Meme; }
	if (amount == 331) { amount = 22; goto Meme; }
	if (amount == 291) { amount = 145; goto Meme; }
	if (amount == 327) { amount = 213; goto Meme; }
	if (amount == 153) { amount = 392; goto Meme; }
	if (amount == 327) { amount = 232; goto Meme; }
	if (amount == 377) { amount = 133; goto Meme; }
	if (amount == 262) { amount = 377; goto Meme; }
	if (amount == 284) { amount = 385; goto Meme; }
	if (amount == 216) { amount = 319; goto Meme; }
	if (amount == 182) { amount = 281; goto Meme; }
	if (amount == 136) { amount = 120; goto Meme; }
	if (amount == 291) { amount = 31; goto Meme; }
	if (amount == 175) { amount = 7; goto Meme; }
	if (amount == 356) { amount = 303; goto Meme; }
	if (amount == 40) { amount = 383; goto Meme; }
	if (amount == 309) { amount = 165; goto Meme; }
	if (amount == 242) { amount = 257; goto Meme; }
	if (amount == 177) { amount = 397; goto Meme; }
	if (amount == 70) { amount = 114; goto Meme; }
	if (amount == 247) { amount = 122; goto Meme; }
	if (amount == 377) { amount = 33; goto Meme; }
	if (amount == 158) { amount = 236; goto Meme; }
	if (amount == 356) { amount = 55; goto Meme; }
	if (amount == 295) { amount = 364; goto Meme; }
	if (amount == 274) { amount = 320; goto Meme; }
	if (amount == 99) { amount = 153; goto Meme; }
	if (amount == 218) { amount = 297; goto Meme; }
	if (amount == 21) { amount = 216; goto Meme; }
	if (amount == 382) { amount = 283; goto Meme; }
	if (amount == 344) { amount = 151; goto Meme; }
	if (amount == 227) { amount = 199; goto Meme; }
	if (amount == 260) { amount = 19; goto Meme; }
	if (amount == 34) { amount = 1; goto Meme; }
	if (amount == 29) { amount = 379; goto Meme; }
	if (amount == 174) { amount = 194; goto Meme; }
	if (amount == 13) { amount = 36; goto Meme; }
	if (amount == 71) { amount = 393; goto Meme; }
	if (amount == 132) { amount = 206; goto Meme; }
	if (amount == 126) { amount = 34; goto Meme; }
	if (amount == 253) { amount = 151; goto Meme; }
	if (amount == 90) { amount = 106; goto Meme; }
	if (amount == 338) { amount = 383; goto Meme; }
	if (amount == 26) { amount = 162; goto Meme; }
	if (amount == 82) { amount = 268; goto Meme; }
	if (amount == 124) { amount = 2; goto Meme; }
	if (amount == 322) { amount = 111; goto Meme; }
	if (amount == 270) { amount = 271; goto Meme; }
	if (amount == 306) { amount = 6; goto Meme; }
	if (amount == 291) { amount = 335; goto Meme; }
	if (amount == 337) { amount = 195; goto Meme; }
	if (amount == 328) { amount = 109; goto Meme; }
	if (amount == 308) { amount = 61; goto Meme; }
	if (amount == 151) { amount = 201; goto Meme; }
	if (amount == 323) { amount = 37; goto Meme; }
	if (amount == 220) { amount = 194; goto Meme; }
	if (amount == 244) { amount = 44; goto Meme; }
	if (amount == 294) { amount = 134; goto Meme; }
	if (amount == 285) { amount = 115; goto Meme; }
	if (amount == 224) { amount = 105; goto Meme; }
	if (amount == 20) { amount = 147; goto Meme; }
	if (amount == 49) { amount = 148; goto Meme; }
	if (amount == 25) { amount = 367; goto Meme; }
	if (amount == 176) { amount = 0; goto Meme; }
	if (amount == 38) { amount = 374; goto Meme; }
	if (amount == 28) { amount = 131; goto Meme; }
	if (amount == 213) { amount = 93; goto Meme; }
	if (amount == 76) { amount = 58; goto Meme; }
	if (amount == 163) { amount = 221; goto Meme; }
	if (amount == 34) { amount = 72; goto Meme; }
	if (amount == 148) { amount = 136; goto Meme; }
	if (amount == 373) { amount = 254; goto Meme; }
	if (amount == 135) { amount = 274; goto Meme; }
	if (amount == 223) { amount = 188; goto Meme; }
	if (amount == 219) { amount = 206; goto Meme; }
	if (amount == 164) { amount = 262; goto Meme; }
	if (amount == 290) { amount = 246; goto Meme; }
	if (amount == 372) { amount = 298; goto Meme; }
	if (amount == 117) { amount = 383; goto Meme; }
	if (amount == 275) { amount = 225; goto Meme; }
	if (amount == 360) { amount = 300; goto Meme; }
	if (amount == 103) { amount = 180; goto Meme; }
	if (amount == 32) { amount = 306; goto Meme; }
	if (amount == 113) { amount = 178; goto Meme; }
	if (amount == 258) { amount = 140; goto Meme; }
	if (amount == 272) { amount = 111; goto Meme; }
	if (amount == 317) { amount = 159; goto Meme; }
	if (amount == 306) { amount = 175; goto Meme; }
	if (amount == 235) { amount = 33; goto Meme; }
	if (amount == 285) { amount = 307; goto Meme; }
	if (amount == 276) { amount = 262; goto Meme; }
	if (amount == 253) { amount = 274; goto Meme; }
	if (amount == 292) { amount = 187; goto Meme; }
	if (amount == 14) { amount = 284; goto Meme; }
	if (amount == 158) { amount = 375; goto Meme; }
	if (amount == 381) { amount = 27; goto Meme; }
	if (amount == 321) { amount = 94; goto Meme; }
	if (amount == 138) { amount = 235; goto Meme; }
	if (amount == 298) { amount = 280; goto Meme; }
	if (amount == 321) { amount = 380; goto Meme; }
	if (amount == 313) { amount = 178; goto Meme; }
	if (amount == 185) { amount = 246; goto Meme; }
	if (amount == 104) { amount = 147; goto Meme; }
	if (amount == 395) { amount = 124; goto Meme; }
	if (amount == 266) { amount = 385; goto Meme; }
	if (amount == 119) { amount = 19; goto Meme; }
	if (amount == 161) { amount = 372; goto Meme; }
	if (amount == 116) { amount = 325; goto Meme; }
	if (amount == 371) { amount = 28; goto Meme; }
	if (amount == 264) { amount = 65; goto Meme; }
	if (amount == 269) { amount = 239; goto Meme; }
	if (amount == 295) { amount = 262; goto Meme; }
	if (amount == 248) { amount = 70; goto Meme; }
	if (amount == 30) { amount = 240; goto Meme; }
	if (amount == 43) { amount = 312; goto Meme; }
	if (amount == 2) { amount = 385; goto Meme; }
	if (amount == 65) { amount = 55; goto Meme; }
	if (amount == 228) { amount = 196; goto Meme; }
	if (amount == 45) { amount = 186; goto Meme; }
	if (amount == 168) { amount = 110; goto Meme; }
	if (amount == 27) { amount = 122; goto Meme; }
	if (amount == 343) { amount = 149; goto Meme; }
	if (amount == 201) { amount = 241; goto Meme; }
	if (amount == 66) { amount = 134; goto Meme; }
	if (amount == 118) { amount = 223; goto Meme; }
	if (amount == 279) { amount = 354; goto Meme; }
	if (amount == 265) { amount = 255; goto Meme; }
	if (amount == 73) { amount = 89; goto Meme; }
	if (amount == 181) { amount = 234; goto Meme; }
	if (amount == 107) { amount = 58; goto Meme; }
	if (amount == 28) { amount = 315; goto Meme; }
	if (amount == 45) { amount = 184; goto Meme; }
	if (amount == 225) { amount = 227; goto Meme; }
	if (amount == 266) { amount = 369; goto Meme; }
	if (amount == 67) { amount = 13; goto Meme; }
	if (amount == 337) { amount = 316; goto Meme; }
	if (amount == 263) { amount = 68; goto Meme; }
	if (amount == 67) { amount = 273; goto Meme; }
	if (amount == 52) { amount = 387; goto Meme; }
	if (amount == 364) { amount = 302; goto Meme; }
	if (amount == 133) { amount = 94; goto Meme; }
	if (amount == 390) { amount = 22; goto Meme; }
	if (amount == 155) { amount = 352; goto Meme; }
	if (amount == 186) { amount = 348; goto Meme; }
	if (amount == 369) { amount = 196; goto Meme; }
	if (amount == 137) { amount = 81; goto Meme; }
	if (amount == 372) { amount = 183; goto Meme; }
	if (amount == 58) { amount = 346; goto Meme; }
	if (amount == 18) { amount = 46; goto Meme; }
	if (amount == 228) { amount = 134; goto Meme; }
	if (amount == 162) { amount = 148; goto Meme; }
	if (amount == 238) { amount = 31; goto Meme; }
	if (amount == 229) { amount = 183; goto Meme; }
	if (amount == 180) { amount = 126; goto Meme; }
	if (amount == 203) { amount = 148; goto Meme; }
	if (amount == 333) { amount = 196; goto Meme; }
	if (amount == 329) { amount = 127; goto Meme; }
	if (amount == 396) { amount = 134; goto Meme; }
	if (amount == 345) { amount = 104; goto Meme; }
	if (amount == 164) { amount = 312; goto Meme; }
	if (amount == 307) { amount = 363; goto Meme; }
	if (amount == 223) { amount = 190; goto Meme; }
	if (amount == 91) { amount = 326; goto Meme; }
	if (amount == 368) { amount = 79; goto Meme; }
	if (amount == 11) { amount = 0; goto Meme; }
	if (amount == 279) { amount = 347; goto Meme; }
	if (amount == 82) { amount = 392; goto Meme; }
	if (amount == 390) { amount = 286; goto Meme; }
	if (amount == 93) { amount = 187; goto Meme; }
	if (amount == 370) { amount = 101; goto Meme; }
	if (amount == 197) { amount = 75; goto Meme; }
	if (amount == 108) { amount = 129; goto Meme; }
	if (amount == 265) { amount = 108; goto Meme; }
	if (amount == 64) { amount = 106; goto Meme; }
	if (amount == 333) { amount = 272; goto Meme; }
	if (amount == 253) { amount = 69; goto Meme; }
	if (amount == 67) { amount = 6; goto Meme; }
	if (amount == 374) { amount = 89; goto Meme; }
	if (amount == 298) { amount = 271; goto Meme; }
	if (amount == 25) { amount = 62; goto Meme; }
	if (amount == 84) { amount = 305; goto Meme; }
	if (amount == 126) { amount = 391; goto Meme; }
	if (amount == 108) { amount = 63; goto Meme; }
	if (amount == 34) { amount = 18; goto Meme; }
	if (amount == 199) { amount = 73; goto Meme; }
	if (amount == 229) { amount = 350; goto Meme; }
	if (amount == 378) { amount = 399; goto Meme; }
	if (amount == 80) { amount = 220; goto Meme; }
	if (amount == 109) { amount = 188; goto Meme; }
	if (amount == 299) { amount = 217; goto Meme; }
	if (amount == 351) { amount = 65; goto Meme; }
	if (amount == 318) { amount = 75; goto Meme; }
	if (amount == 202) { amount = 31; goto Meme; }
	if (amount == 198) { amount = 105; goto Meme; }
	if (amount == 263) { amount = 57; goto Meme; }
	if (amount == 27) { amount = 320; goto Meme; }
	if (amount == 261) { amount = 282; goto Meme; }
	if (amount == 272) { amount = 339; goto Meme; }
	if (amount == 247) { amount = 227; goto Meme; }
	if (amount == 362) { amount = 307; goto Meme; }
	if (amount == 172) { amount = 359; goto Meme; }
	if (amount == 148) { amount = 144; goto Meme; }
	if (amount == 115) { amount = 138; goto Meme; }
	if (amount == 162) { amount = 62; goto Meme; }
	if (amount == 173) { amount = 151; goto Meme; }
	if (amount == 277) { amount = 267; goto Meme; }
	if (amount == 149) { amount = 305; goto Meme; }
	if (amount == 383) { amount = 160; goto Meme; }
	if (amount == 206) { amount = 77; goto Meme; }
	if (amount == 375) { amount = 295; goto Meme; }
	if (amount == 189) { amount = 110; goto Meme; }
	if (amount == 63) { amount = 348; goto Meme; }
	if (amount == 215) { amount = 177; goto Meme; }
	if (amount == 228) { amount = 150; goto Meme; }
	if (amount == 203) { amount = 298; goto Meme; }
	if (amount == 390) { amount = 136; goto Meme; }
	if (amount == 179) { amount = 366; goto Meme; }
	if (amount == 297) { amount = 115; goto Meme; }
	if (amount == 39) { amount = 291; goto Meme; }
	if (amount == 282) { amount = 255; goto Meme; }
	if (amount == 354) { amount = 277; goto Meme; }
	if (amount == 342) { amount = 250; goto Meme; }
	if (amount == 281) { amount = 266; goto Meme; }
	if (amount == 184) { amount = 367; goto Meme; }
	if (amount == 122) { amount = 312; goto Meme; }
	if (amount == 289) { amount = 298; goto Meme; }
	if (amount == 337) { amount = 101; goto Meme; }
	if (amount == 173) { amount = 283; goto Meme; }
	if (amount == 257) { amount = 207; goto Meme; }
	if (amount == 307) { amount = 281; goto Meme; }
	if (amount == 209) { amount = 142; goto Meme; }
	if (amount == 381) { amount = 266; goto Meme; }
	if (amount == 100) { amount = 247; goto Meme; }
	if (amount == 74) { amount = 352; goto Meme; }
	if (amount == 142) { amount = 370; goto Meme; }
	if (amount == 192) { amount = 70; goto Meme; }
	if (amount == 84) { amount = 350; goto Meme; }
	if (amount == 341) { amount = 43; goto Meme; }
	if (amount == 227) { amount = 371; goto Meme; }
	if (amount == 48) { amount = 206; goto Meme; }
	if (amount == 67) { amount = 104; goto Meme; }
	if (amount == 124) { amount = 283; goto Meme; }
	if (amount == 29) { amount = 86; goto Meme; }
	if (amount == 285) { amount = 68; goto Meme; }
	if (amount == 315) { amount = 253; goto Meme; }
	if (amount == 325) { amount = 276; goto Meme; }
	if (amount == 256) { amount = 70; goto Meme; }
	if (amount == 25) { amount = 96; goto Meme; }
	if (amount == 328) { amount = 120; goto Meme; }
	if (amount == 384) { amount = 335; goto Meme; }
	if (amount == 80) { amount = 239; goto Meme; }
	if (amount == 28) { amount = 92; goto Meme; }
	if (amount == 313) { amount = 282; goto Meme; }
	if (amount == 60) { amount = 89; goto Meme; }
	if (amount == 25) { amount = 323; goto Meme; }
	if (amount == 288) { amount = 165; goto Meme; }
	if (amount == 371) { amount = 21; goto Meme; }
	if (amount == 303) { amount = 241; goto Meme; }
	if (amount == 184) { amount = 201; goto Meme; }
	if (amount == 278) { amount = 224; goto Meme; }
	if (amount == 158) { amount = 193; goto Meme; }
	if (amount == 34) { amount = 334; goto Meme; }
	if (amount == 0) { amount = 9; goto Meme; }
	if (amount == 256) { amount = 3; goto Meme; }
	if (amount == 230) { amount = 235; goto Meme; }
	if (amount == 66) { amount = 167; goto Meme; }
	if (amount == 166) { amount = 242; goto Meme; }
	if (amount == 213) { amount = 72; goto Meme; }
	if (amount == 235) { amount = 353; goto Meme; }
	if (amount == 17) { amount = 217; goto Meme; }
	if (amount == 245) { amount = 308; goto Meme; }
	if (amount == 305) { amount = 174; goto Meme; }
	if (amount == 177) { amount = 231; goto Meme; }
	if (amount == 19) { amount = 21; goto Meme; }
	if (amount == 315) { amount = 166; goto Meme; }
	if (amount == 386) { amount = 7; goto Meme; }
	if (amount == 369) { amount = 309; goto Meme; }
	if (amount == 322) { amount = 48; goto Meme; }
	if (amount == 121) { amount = 241; goto Meme; }
	if (amount == 171) { amount = 298; goto Meme; }
	if (amount == 54) { amount = 6; goto Meme; }
	if (amount == 266) { amount = 273; goto Meme; }
	if (amount == 279) { amount = 339; goto Meme; }
	if (amount == 324) { amount = 243; goto Meme; }
	if (amount == 353) { amount = 107; goto Meme; }
	if (amount == 237) { amount = 182; goto Meme; }
	if (amount == 14) { amount = 61; goto Meme; }
	if (amount == 249) { amount = 30; goto Meme; }
	if (amount == 38) { amount = 230; goto Meme; }
	if (amount == 0) { amount = 95; goto Meme; }
	if (amount == 397) { amount = 117; goto Meme; }
	if (amount == 327) { amount = 352; goto Meme; }
	if (amount == 108) { amount = 208; goto Meme; }
	if (amount == 316) { amount = 1; goto Meme; }
	if (amount == 132) { amount = 357; goto Meme; }
	if (amount == 114) { amount = 238; goto Meme; }
	if (amount == 161) { amount = 19; goto Meme; }
	if (amount == 30) { amount = 340; goto Meme; }
	if (amount == 92) { amount = 74; goto Meme; }
	if (amount == 257) { amount = 340; goto Meme; }
	if (amount == 115) { amount = 256; goto Meme; }
	if (amount == 280) { amount = 294; goto Meme; }
	if (amount == 61) { amount = 102; goto Meme; }
	if (amount == 224) { amount = 47; goto Meme; }
	if (amount == 184) { amount = 218; goto Meme; }
	if (amount == 78) { amount = 326; goto Meme; }
	if (amount == 166) { amount = 238; goto Meme; }
	if (amount == 110) { amount = 164; goto Meme; }
	if (amount == 280) { amount = 169; goto Meme; }
	if (amount == 9) { amount = 266; goto Meme; }
	if (amount == 137) { amount = 333; goto Meme; }
	if (amount == 349) { amount = 87; goto Meme; }
	if (amount == 286) { amount = 185; goto Meme; }
	if (amount == 8) { amount = 9; goto Meme; }
	if (amount == 267) { amount = 239; goto Meme; }
	if (amount == 196) { amount = 372; goto Meme; }
	if (amount == 186) { amount = 8; goto Meme; }
	if (amount == 10) { amount = 321; goto Meme; }
	if (amount == 169) { amount = 295; goto Meme; }
	if (amount == 192) { amount = 105; goto Meme; }
	if (amount == 225) { amount = 92; goto Meme; }
	if (amount == 20) { amount = 67; goto Meme; }
	if (amount == 350) { amount = 394; goto Meme; }
	if (amount == 190) { amount = 90; goto Meme; }
	if (amount == 268) { amount = 234; goto Meme; }
	if (amount == 1) { amount = 306; goto Meme; }
	if (amount == 270) { amount = 225; goto Meme; }
	if (amount == 227) { amount = 380; goto Meme; }
	if (amount == 277) { amount = 384; goto Meme; }
	if (amount == 286) { amount = 312; goto Meme; }
	if (amount == 303) { amount = 43; goto Meme; }
	if (amount == 309) { amount = 58; goto Meme; }
	if (amount == 301) { amount = 140; goto Meme; }
	if (amount == 58) { amount = 257; goto Meme; }
	if (amount == 186) { amount = 24; goto Meme; }
	if (amount == 127) { amount = 196; goto Meme; }
	if (amount == 217) { amount = 146; goto Meme; }
}
#pragma endregion
int dieloading(char* msg, char* secMSG, int time_millisecs)
{
	Dialog::msgdialog_mode = Dialog::MODE_CHECK_PROGRESSBAR_1;
	Dialog::Showprogress(msg, secMSG, 120);
}
int* die(char* msg)
{
	Dialog::msgdialog_mode = Dialog::MODE_STRING_OK;
	Dialog::Show(msg);
}
int* dieTrampoline(int*(*fnptr)(char*), char*msg, bool ping = false)
{
	dummyCall_2();
	if (ping)
	{
		return fnptr(msg);
	}
	else
	{
		dieTrampoline(fnptr, msg, true);
	}
	return fnptr(msg);
}
#pragma endregion
#pragma endregion

void Thread(uint64_t nothing)
{
#if DEVELOPERMODE == 1
		//block eboot detection
		char patch12E3AC8data[] = { 0x3C, 0x60, 0x00, 0xEB, 0x38, 0x63, 0x3A, 0x30, 0x3C, 0x80, 0x01, 0xCF, 0xF8, 0x64, 0x74, 0xE0, 0x4E, 0x80, 0x00, 0x20 };
		memcpy((void*)0x12E3AC8, patch12E3AC8data, sizeof(patch12E3AC8data));
		*(ui64*)0x1CF74E0 = 0xEB3A30;

		/* Jaro666 patches. tested working fine 5/25/2021 */
		*(unsigned int*)0x10C1E9C = 0x4E800020;
		*(unsigned int*)0x4B48A0 = 0x4E800020;
		*(unsigned int*)0x733F88 = 0x60000000;
		*(unsigned int*)0xEDF944 = 0x60000000;
		*(unsigned int*)0xEDF9EC = 0x60000000;
		*(unsigned int*)0xEE20A0 = 0x60000000;
		*(unsigned int*)0xEE20B4 = 0x60000000;
		*(unsigned int*)0x13BFE78 = 0x60000000;
		*(unsigned int*)0x13BFED0 = 0x60000000;
		*(unsigned int*)0x13BFF18 = 0x60000000;
		*(unsigned int*)0x13BFF40 = 0x60000000;
		*(unsigned int*)0x13BF834 = 0x60000000;
		*(unsigned int*)0x13C01E8 = 0x60000000;
		*(unsigned int*)0x13C0208 = 0x60000000;
		*(unsigned int*)0x13BFF64 = 0x60000000;
		*(unsigned int*)0x1327673 = 0x01807A0E;

		// potential fix for the ps3 blocking the BLUS EBOOT from running on BLES01807 sprx (Educated guess)
		*(int*)0x10558 = 0x48000024; // branches to loc_1057C to avoid trap_game_launch

		char MoneyProtection[] = { 0x48, 0x00, 0x01, 0x38 }; //Money Drop Protection From Rockstar
		writeMem((uint64_t)0x3FA510, &MoneyProtection, sizeof(MoneyProtection)); //Money Drop Protection From Rockstar
		*(unsigned int*)0x3DD430 = 0x60000000; //allow more than 10 million
		*(unsigned int*)0x3DD420 = 0x60000000; //allow less than 0, aka remove money.
		*(unsigned int*)0x12D137C = 0x4E800020;//All Client Stat Protection // Thanks to gopro_2027
		*(unsigned int*)0x12CC958 = 0x4E800020;//clear task fix this as a bool later..
		*(unsigned int*)0x1358EF8 = 0x60000000;// admin kick protect
		*(unsigned int*)0x012D3118 = 0x60000000; //New Freeze Protection Thanks to Vnon
		*(unsigned int*)0x012D30D8 = 0x60000000; //New Freeze Protection Thanks to Vnon
		*(unsigned int*)0xA5672C = 0x60000000; //host protection (Cane)

		// currently saved 940 bytes of total space on GTA | works on GTAO
		//*(uint32_t*)(0x12F0FA4) = 0x60000000; // disable [RAGE] rlAchievement Worker Thread
		//*(uint32_t*)(0xD2C49C) = 0x60000000; // disable [RAGE] rlAchievement Worker Thread
		//*(uint32_t*)(0x424618) = 0x38600001; // blocks thread:  GIVE_ACHIEVEMENT_TO_PLAYER
		
		*(int*)0x14CC4C = 0x4E800020; // saves 53 bytes : disable phone app
		*(int*)0x12E7A78 = 0x4E800020; // blocks facebook manager loop | works online

		// get heap sizes for functions
		//HookFunctionStartGTA(0x10350, *(uint32_t*)malloc_stub, *(uint32_t*)malloc_hook, 0, 0, 0, 0);
		//HookFunctionStartGTA(0x10310, *(uint32_t*)malloc_stub1, *(uint32_t*)malloc_hook1, 0, 0, 0, 0);
		
		// works fine, removed from release until finished
		//HookFunctionStartGTA(0xAECA38, *(uint32_t*)stub_allocate_heap_memory, *(uint32_t*)allocate_heap_Hook, 0, 0x150AA7C, 0, 0); 

		
		//*(unsigned int*)0x003D7AE0 = 0x4E800020; // void POPULATE_NOW() .. Stop game from spawning random peds and vehicles. **crashes thread**
		//__asm volatile ( "0x1316254:"; "lis %r3, 0x28A;" "ori %r3, %r3, 0xD000;" "stw %r3, 0x18(%r30);" "lis %r3, 0xB749;" "ori %r3, %r3, 0xA43B;" "stw %r3, 0x1C(%r30);" "nop;" );//Script Bypass
#endif
	g_Natives = (Native_s**)FindNativeTableAddress();
	sleep(1000);
	for (;;)
	{
		sleep(10000);
		if (Auth.isThreadActive == false) 
		{
			char b_IP_ADDRESS[14];
			char* c_IP_ADDRESS = xorTrampoline(XORDecrypt, IP_ADDRESS, 14);
			strcpy(b_IP_ADDRESS, c_IP_ADDRESS);
			char b_KEY_FILE_LOCATION[24];
			char* c_KEY_FILE_LOCATION = xorTrampoline(XORDecrypt, KEY_FILE_LOCATION, 24);
			strcpy(b_KEY_FILE_LOCATION, FILELOC);
			Auth.ret = cellFsOpen(b_KEY_FILE_LOCATION, 0, &Auth.fd, NULL, 0);
			if (!Auth.ret)
			{
				cellFsLseek(Auth.fd, 0, CELL_FS_SEEK_SET, &Auth.pos);
				Auth.ret = cellFsRead(Auth.fd, LicenseKey, sizeof(LicenseKey), &Auth.nread);
				if (!Auth.ret)
				{
					cellFsClose(Auth.fd);
				}
				else
				{
					char b_ERRORCODE1[35];//33
					char* c_ERRORCODE1 = xorTrampoline(XORDecrypt, ERRORCODE1, 35);//33
					strcpy(b_ERRORCODE1, c_ERRORCODE1);
					Dialog::msgdialog_mode = Dialog::MODE_STRING_OK;
					Dialog::Show(b_ERRORCODE1);
					Auth.isThreadActive = true;
					return;
				}
			}
			else
			{
				char b_ERRORCODE2[35];//33
				char* c_ERRORCODE2 = xorTrampoline(XORDecrypt, ERRORCODE2, 35);//33
				strcpy(b_ERRORCODE2, c_ERRORCODE2);
				Dialog::msgdialog_mode = Dialog::MODE_STRING_OK;
				Dialog::Show(b_ERRORCODE2);
				Auth.isThreadActive = true;
				return;
			}
			
			if (strlen(LicenseKey) != 14)
			{
				char b_ERRORCODE3[81];
				char* c_ERRORCODE3 = xorTrampoline(XORDecrypt, ERRORCODE3, 81);
				strcpy(b_ERRORCODE3, c_ERRORCODE3);

				Dialog::msgdialog_mode = Dialog::MODE_STRING_OK;
				Dialog::Show(b_ERRORCODE3);
				Auth.isThreadActive = true;
				return;
			}
			char b_validateLengthOfLicenseXOR[34];
			char* c_validateLengthOfLicenseXOR = xorTrampoline(XORDecrypt, validateLengthOfLicenseXOR, 34);
			strcpy(b_validateLengthOfLicenseXOR, c_validateLengthOfLicenseXOR);
			char b_COLON[1];
			char* c_COLON = xorTrampoline(XORDecrypt, COLON, 1);
			strcpy(b_COLON, c_COLON);
			char b_ISBA[4];
			char* c_ISBA = xorTrampoline(XORDecrypt, ISBA, 4);
			strcpy(b_ISBA, c_ISBA);
			char b_ISGO[4];
			char* c_ISGO = xorTrampoline(XORDecrypt, ISGO, 4);
			strcpy(b_ISGO, c_ISGO);
			char b_STRSLASHNSTR[5];
			char* c_STRSLASHNSTR = xorTrampoline(XORDecrypt, STRSLASHNSTR, 5);
			strcpy(b_STRSLASHNSTR, c_STRSLASHNSTR);
			sprintf(Auth.validateLengthOfLicenseBUF, b_validateLengthOfLicenseXOR, LicenseKey);
			char* validateLengthOfLicense = SendDataToSocket(b_IP_ADDRESS, Auth.validateLengthOfLicenseBUF);
			char* validateLengthOfLicense_strip = strstr(validateLengthOfLicense, b_ISBA);
			if (validateLengthOfLicense_strip != NULL)
			{
				int row = 0;
				char*pch;
				pch = strtok1(validateLengthOfLicense_strip, b_COLON);
				while (pch != NULL)
				{
					switch (row)
					{
					case 1: Auth.ErrorCode = pch;
						break;
					case 2: Auth.ErrorResp = pch;
						break;
					}
					row++;
					pch = strtok1(NULL, b_COLON);
				}
				sprintf(Auth.ErrorMessage, b_STRSLASHNSTR, Auth.ErrorCode, Auth.ErrorResp);
				die(Auth.ErrorMessage);
				Auth.isThreadActive = false;
				dummyCall_1();
				return;
			}
			Auth.validateLengthOfLicenseCheck = 0x01;
			char b_validateLicenseExistsXOR[32];
			char* c_validateLicenseExistsXOR = xorTrampoline(XORDecrypt, validateLicenseExistsXOR, 32);
			strcpy(b_validateLicenseExistsXOR, c_validateLicenseExistsXOR);
			sprintf(Auth.validateLicenseExistsBUF, b_validateLicenseExistsXOR, LicenseKey);
			char* validateLicenseExists = SendDataToSocket(b_IP_ADDRESS, Auth.validateLicenseExistsBUF);
			char* validateLicenseExists_strip = strstr(validateLicenseExists, b_ISBA);
			if (validateLicenseExists_strip != NULL)
			{
				int row = 0;
				char*pch;
				pch = strtok1(validateLicenseExists_strip, b_COLON);
				while (pch != NULL)
				{
					switch (row)
					{
					case 1: Auth.ErrorCode = pch;
						break;
					case 2: Auth.ErrorResp = pch;
						break;
					}
					row++;
					pch = strtok1(NULL, b_COLON);
				}
				sprintf(Auth.ErrorMessage, b_STRSLASHNSTR, Auth.ErrorCode, Auth.ErrorResp);
				die(Auth.ErrorMessage);
				Auth.isThreadActive = false;
				dummyCall_2();
				return;
			}
			Auth.validateLicenseExistsCheck = 0x05;
			char b_validateLicenseIsntBannedXOR[36];
			char* c_validateLicenseIsntBannedXOR = xorTrampoline(XORDecrypt, validateLicenseIsntBannedXOR, 36);
			strcpy(b_validateLicenseIsntBannedXOR, c_validateLicenseIsntBannedXOR);
			sprintf(Auth.validateLicenseIsntBannedBUF, b_validateLicenseIsntBannedXOR, LicenseKey);
			char* validateLicenseIsntBanned = SendDataToSocket(b_IP_ADDRESS, Auth.validateLicenseIsntBannedBUF);
			char* validateLicenseIsntBanned_strip = strstr(validateLicenseIsntBanned, b_ISBA);
			if (validateLicenseIsntBanned_strip != NULL)
			{
				int row = 0;
				char*pch;
				pch = strtok1(validateLicenseIsntBanned_strip, b_COLON);
				while (pch != NULL)
				{
					switch (row)
					{
					case 1: Auth.ErrorCode = pch;
						break;
					case 2: Auth.ErrorResp = pch;
						break;
					}
					row++;
					pch = strtok1(NULL, b_COLON);
				}
				sprintf(Auth.ErrorMessage, b_STRSLASHNSTR, Auth.ErrorCode, Auth.ErrorResp);
				die(Auth.ErrorMessage);
				Auth.isThreadActive = false;
				dummyCall_3();
				return;
			}
			CellNetCtlInfo net;
			cellNetCtlGetInfo(CELL_NET_CTL_INFO_ETHER_ADDR, &net);
			const char * Mac = (const char*)net.ether_addr.data;
			char b_validateMacAddressXOR[70];
			char* c_validateMacAddressXOR = xorTrampoline(XORDecrypt, validateMacAddressXOR, 70);
			strcpy(b_validateMacAddressXOR, c_validateMacAddressXOR);
			sprintf(Auth.validateMacAddressBUF, b_validateMacAddressXOR, Mac[0] & 0xFF, Mac[1] & 0xFF, Mac[2] & 0xFF, Mac[3] & 0xFF, Mac[4] & 0xFF, Mac[5] & 0xFF, LicenseKey);
			char* validateMacAddress = SendDataToSocket(b_IP_ADDRESS, Auth.validateMacAddressBUF);
			char* validateMacAddress_strip = strstr(validateMacAddress, b_ISBA);
			if (validateMacAddress_strip != NULL)
			{
				int row = 0;
				char*pch;
				pch = strtok1(validateMacAddress_strip, b_COLON);
				while (pch != NULL)
				{
					switch (row)
					{
					case 1: Auth.ErrorCode = pch;
						break;
					case 2: Auth.ErrorResp = pch;
						break;
					}
					row++;
					pch = strtok1(NULL, b_COLON);
				}
				sprintf(Auth.ErrorMessage, b_STRSLASHNSTR, Auth.ErrorCode, Auth.ErrorResp);
				die(Auth.ErrorMessage);
				Auth.isThreadActive = false;
				dummyCall_4();
				return;
			}
			char b_callAddressesXOR[65];
			char* c_callAddressesXOR = xorTrampoline(XORDecrypt, callAddressesXOR, 65);
			strcpy(b_callAddressesXOR, c_callAddressesXOR);
			sprintf(Auth.callAddressesBUF, b_callAddressesXOR, Mac[0] & 0xFF, Mac[1] & 0xFF, Mac[2] & 0xFF, Mac[3] & 0xFF, Mac[4] & 0xFF, Mac[5] & 0xFF, LicenseKey);
			char* callAddresses = SendDataToSocket(b_IP_ADDRESS, Auth.callAddressesBUF);
			char* callAddresses_strip = strstr(callAddresses, b_ISBA);
			if (callAddresses_strip != NULL)
			{
				int row = 0;
				char*pch;
				pch = strtok1(callAddresses_strip, b_COLON);
				while (pch != NULL)
				{
					switch (row)
					{
					case 1: Auth.ErrorCode = pch;
						break;
					case 2: Auth.ErrorResp = pch;
						break;
					}
					row++;
					pch = strtok1(NULL, b_COLON);
				}
				sprintf(Auth.ErrorMessage, b_STRSLASHNSTR, Auth.ErrorCode, Auth.ErrorResp);
				die(Auth.ErrorMessage);
				Auth.isThreadActive = false;
				dummyCall_3();
				return;
			} 

			uint64_t PSID[2];
			system_call_1(872, (uint64_t)PSID);

			char b_LOG_INFORMATION[63];
			char* c_LOG_INFORMATION = XOR(LOG_INFORMATION, 63);
			strcpy(b_LOG_INFORMATION, c_LOG_INFORMATION);

			char SendDataBUF[1000];
			sprintf(SendDataBUF, b_LOG_INFORMATION, LicenseKey, NULL/*PSN*/, "TinyMenuGTA", PSID[0], PSID[1]);
			SendDataToSocket(b_IP_ADDRESS, SendDataBUF);

			char* callAddresses_strip_s = strstr(callAddresses, b_ISGO);
			if (callAddresses_strip_s != NULL) 
			{
				int row = 0;
				char*pch;
				pch = strtok1(callAddresses_strip_s, b_COLON);
				while (pch != NULL)
				{
					switch (row)
					{
					case 1: welcome = pch;
						break;
					case 2: hookaddr = StoI(pch);
						break;
					case 3: 
						if (strstr(pch, xorTrampoline(XORDecrypt, ONE, 1)) != NULL)
						{
							Dev_access[0] = true;
						}
						break;
					case 4: currentmenuversion = pch; break;
					case 5: newmenusize = StoI(pch); break;
					case 6: scriptsize = StoI(pch); break;
					case 7: customrpfsize = StoI(pch); break;
					case 8: MenuColour_R = StoI(pch); break; // gui Red
					case 9: MenuColour_G = StoI(pch);  break; // gui Green
					case 10: MenuColour_B = StoI(pch); break; // gui blue
					case 11: 
						if (strstr(pch, xorTrampoline(XORDecrypt, ONE, 1)) != NULL)
						{
							prologueBypassWebCheck[0] = true;
						}
						break;
					case 12: 
						if (strstr(pch, xorTrampoline(XORDecrypt, ONE, 1)) != NULL)
						{
							GameSizeWebCheck[0] = true;
						}
						break;
					}
					row++;
					pch = strtok1(NULL, b_COLON);
					Auth.isThreadActive = false; // added for 4.1.0
				}
				
				/* 
				*********************************************************************
				Drew's notes (Auth only / Encryption XOR)
				
				
				-Example code for using buffers for decrypting strings
				char string_buffer[10];
				char* a_string_buffer = XorTrampoline(XORDecrypt, string, 10);
				strcpy(string_buffer, a_string_buffer); // move string left into buffer memory.
				die(string_buffer);						
				// unicode characters are not included in XOR library so dont even attempt it. 

				*********************************************************************
				*/
				/*New Auth Dev Access Encrypted Strings Vs PlainText*/
				
						/*Dev Access*/
						if (Dev_access[0])
						{
							/* This will bypass all time checks and version checks. (Developer Access) */
							PatchInJump(hookaddr, (int)_Hook, false);// 
							writeMem((uint64_t)backup_sub_FEB51CT, (const void*)0xFEB51C, 4 * 4);
							PatchInJump(0xFEB51C, (int)sub_FEB51CT_hook, false);
							create_script_directory();															// beta only 2/2/21 = creates directory @ dev_hdd0\tmp\TinyMenu
							*(uint32_t*)(0xA128BC) = 0x48000310;												// jaro patch
							*(uint64_t*)(0x1C707F0) = *(uint64_t*)(NetworkObjectMgr_HandleCloneSync);			// jaro patch.
							setup_HAS_FORCE_CLEANUP_OCCURRED_hook();											// prologue bypass
							char a_DEV_MSG[42];
							char* b_DEV_MSG = xorTrampoline(XORDecrypt, DEV_MSG, 42);
							strcpy(a_DEV_MSG, b_DEV_MSG);
							die(a_DEV_MSG);
							Auth.isThreadActive = false;
						} 
						else if (!Dev_access[0] && strstr(currentmenuversion, Thismenuversion))
						{ 
							/*Official Welcome Message for regular Users*/
								PatchInJump(hookaddr, (int)_Hook, false);
								writeMem((uint64_t)backup_sub_FEB51CT, (const void*)0xFEB51C, 4 * 4);
								PatchInJump(0xFEB51C, (int)sub_FEB51CT_hook, false);
								*(uint32_t*)(0xA128BC) = 0x48000310;												// jaro patch
								*(uint64_t*)(0x1C707F0) = *(uint64_t*)(NetworkObjectMgr_HandleCloneSync);			// jaro patch. 
								if (prologueBypassWebCheck[0]) { setup_HAS_FORCE_CLEANUP_OCCURRED_hook(); }			// prologue bypass
								if (GameSizeWebCheck[0]) { HookFunctionStartGTA(0xAECA38, *(uint32_t*)stub_allocate_heap_memory, *(uint32_t*)allocate_heap_Hook, 0, 0x150AA7C, 0, 0); }
								sleep(30000);// 30 seconds after loading screen finishes.
								die(welcome);
								Auth.isThreadActive = false;
						}
						else
						{
							/*Out dated menu detected, auto update initiates*/
							MenuUpdate(MENULOC, newmenusize);
							sleep(30000);
							char a_UPDATE_AVAILABLE[67];
							char* b_UPDATE_AVAILABLE = xorTrampoline(XORDecrypt, UPDATE_AVAILABLE, 67);
							strcpy(a_UPDATE_AVAILABLE, b_UPDATE_AVAILABLE);
							die(a_UPDATE_AVAILABLE);
							Auth.isThreadActive = true;
						}
				}		
				return;
			}
			char b_ERRORCODE9[62];
			char* c_ERRORCODE9 = xorTrampoline(XORDecrypt, ERRORCODE9, 62);
			strcpy(b_ERRORCODE9, c_ERRORCODE9);
			die(b_ERRORCODE9);
			Auth.isThreadActive = true;
			dummyCall_1();
			return;
			sys_ppu_thread_exit(nothing);
		}
		sys_ppu_thread_exit(nothing);
	}
#pragma endregion

#pragma region GameExitOnFreeze_Thread
#define CELL_UTIL_PAD_MAX 7
	static CellPadInfo2 sPadInfo2;
	bool updatePadInfo()
	{
		CellPadInfo2 pad_info2;
		int32_t cr = cellPadGetInfo2(&pad_info2);
		if (cr != CELL_PAD_OK) return false;

		sPadInfo2 = pad_info2;

		return true;
	}
	bool isConnected(uint8_t pad) 
	{
		if (pad >= CELL_UTIL_PAD_MAX) return false;
		if (pad >= sPadInfo2.max_connect) return false;

		return (sPadInfo2.port_status[pad] & CELL_PAD_STATUS_CONNECTED);
	}
	bool cellPadUtilIsConnected(uint8_t pad)
	{
		if (!updatePadInfo()) {
			return false;
		}
		return isConnected(pad);
	}
	void GameExitOnFreeze(uint64_t gamecrashexit)// first test.. this is working flawlessly. the delay was definitely neccessary. game was unplayable without it..
	{
		sleep(30000);// wait for Tiny Menu to finish
		while (true) {
			sleep(100);//delay that loop
			static int pad = -1;
			if (pad == -1) {
				for (int i = 0; i < CELL_UTIL_PAD_MAX; i++) {
					if (cellPadUtilIsConnected(i))
						pad = i;
				}
			}
			//CellPadUtilPress padInfo = cellPadUtilGetPressValue(pad);
			CellPadData tmppaddata;
			static CellPadData paddata;
			int32_t ret = cellPadGetData(pad == -1 ? 0 : pad, &tmppaddata);
			if (ret == CELL_PAD_OK && tmppaddata.len != 0) {
				paddata = tmppaddata;
			}
			int data = paddata.button[CELL_PAD_BTN_OFFSET_DIGITAL1];
			if ((data & CELL_PAD_CTRL_SELECT) && (data & CELL_PAD_CTRL_START))
			{
				sys_process_exit(0);
			}
		}
	} 
#pragma endregion



extern "C" int PRX_ENTRY()
{
	CellFsStat stat;
	if (cellFsStat("/dev_hdd0/tmp/TinyMenu.sprx", &stat) < 0){ currentmenusize = stat.st_size; }
	sys_ppu_thread_t ThreadModuleID;
	sys_ppu_thread_t GameExitThreadID;
	sys_ppu_thread_create(&ThreadModuleID, Thread, 0, 10, 0x10, 0, "Tiny Menu");
	sys_ppu_thread_create(&GameExitThreadID, GameExitOnFreeze, 0, 10, 0x01, 0, "GameExitThreadFreeze");
	return SYS_PRX_RESIDENT;
}