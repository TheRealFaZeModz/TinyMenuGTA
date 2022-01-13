#pragma once

void dialogReturn(int button, void *userdata) {}
#define dialog(text) cellMsgDialogOpen(1,text,dialogReturn,(void*) 0x0000aaab, NULL);


#pragma region Variables
Native_s** g_Natives;
int submenu = 0;
int submenuLevel;
int lastSubmenu[20];
int lastOption[20];
int optionCount;
//int currentOption;
bool optionPress = false;
bool rightPress = false;
bool leftPress = false;
bool fastRightPress = false;
bool fastLeftPress = false;
bool squarePress = false;
bool SpawnVehicle;

bool menuSounds = true;
bool keyboardActive = false;
int keyboardAction;
int *keyboardVar = 0;
char *infoText;
bool newTimerTick = true;
int maxTimerCount;
bool newTimerTick2 = true;
int maxTimerCount2;

bool instructions = true;
int instructCount;
int mov;
bool instructionsSetupThisFrame;
bool xInstruction;
bool squareInstruction;
bool lrInstruction;
int bannerTextRed = MenuColour_R; 
int bannerTextGreen = MenuColour_G;
int bannerTextBlue = MenuColour_B;
int bannerTextOpacity = 255;
int spritered = MenuColour_R;
int spritegreen = MenuColour_G;
int spriteblue = MenuColour_B;
int spriteopacity = 50;
bool undectedgmode = false;
bool Toggle = false;
int bannerTextFont = 1;
int bannerRectRed = MenuColour_R;
int bannerRectGreen = MenuColour_G;
int bannerRectBlue = MenuColour_B;
int bannerRectOpacity = 255;
int backgroundRed = 16;
int backgroundGreen = 16;
int backgroundBlue = 16;
int backgroundOpacity = 70;
int optionsRed = MenuColour_R;
int optionsGreen = MenuColour_G;
int optionsBlue = MenuColour_B;
int optionsOpacity = 255;
int optionsFont = 0;
float menuXCoord = 0.85f;
float menuYCoordMove = 0.70;
float textXCoord = 0.76f;
float menuYCoord = 0.45f;
float textYCoord = 0.20f;
int maxOptions = 18;
float checkboxshit = 0.875f;
float
UpDown = .1135f,
MenuWidth = .22f,
SpriteWidht = .3420f;
bool 
rockstarDeveloper,
badsportlobbyspoof = false;
#pragma endregion

#pragma region Random Defs
void Notify(char* Text, int Time = 4000)
{
	UI::_0xF42C43C7("STRING");
	UI::_ADD_TEXT_COMPONENT_STRING(Text);
	UI::_0x38F82261(Time, false);
}
void Notify(int Value, int Time = 4000)
{
	char buffer[100];
	sprintf(buffer, "%i", Value);
	Notify(buffer);
}
void Notify_Error(char* Text, int Time = 4000)
{
	char buffer[1024];
	sprintf(buffer, "%s%s", "~r~Error: ~w~", Text);
	Notify(buffer);
}
#pragma endregion

#pragma region structs_gopro_2027

/*
class scrThreadContext
{
public:
	std::uint32_t m_thread_id;           // 0x00
	joaat_t m_script_hash;               // 0x04
	eThreadState m_state;                // 0x08
	std::uint32_t m_instruction_pointer; // 0x0C
	std::uint32_t m_frame_pointer;       // 0x10
	std::uint32_t m_stack_pointer;       // 0x14
	float m_timer_a;                     // 0x18
	float m_timer_b;                     // 0x1C
	float m_timer_c;                     // 0x20 WAIT timer
	char _0x28[24];
	std::uint32_t m_stack_size;          // 0x40
	char _0x44[16];
};
class scrThread
{
public:
	scrThreadContext m_context;                           // 0x08
	void* m_stack;                                        // 0x54
	char _0x58[12];
	const char* m_exitMessage;                            // 0x64
	char m_name[32];                                                // 0x68
	char _0x88[8];
	std::uint32_t* m_unkPointer;                                // 0x90 
	char _0x94[20];
	scriptHandler* m_handler;                              // 0xA8 
	scriptHandlerNetComponent* m_netComponent;      // 0xAC 
	joaat_t m_scriptHash;                                    // 0xB0 
	char _0xB4[28];
	uint8_t m_flag1;                                 // 0xD0 
	uint8_t m_safeForNetworkGame;                    // 0xD1 
	uint8_t N0F18E0FF;                               // 0xD2 
	uint8_t N0F18BC4E;                               // 0xD3 
	uint8_t m_isMinigameScript;                      // 0xD4 
	uint8_t N0F192D5E;                               // 0xD5 
	uint8_t N0F193502;                               // 0xD6 
	uint8_t m_canBePaused;                           // 0xD7 
	uint8_t m_canRemoveBlipsFromOtherScripts;        // 0xD8 
	uint8_t N0F197F9C;                               // 0xD9 
	uint8_t N0F19A76A;                               // 0xDA 
	uint8_t N0F197F9D;                               // 0xDB 
	char _0x00DC[4];
	uint32_t* N0F17CF21;                             // 0xE0 
	char _0x00E4[4];
	uint32_t* N0F17CF23;                             // 0xE8 
	char _0x00EC[4];
};
*/
char *getClassName(unsigned int classAddress) {
	if (classAddress < 0x10000)
		return "ERROR";
	unsigned int classInfo = *(volatile unsigned int*)classAddress;
	if (classInfo < 0x10000)
		return "ERROR";
	classInfo = classInfo - 0x4;
	if (*(volatile unsigned int*)classInfo < 0x10000)
		return "ERROR";
	struct classNameInfo {
		unsigned int unk;
		char *name;
	};
	classNameInfo *className = (classNameInfo*)(*(volatile unsigned int*)classInfo);
	return className->name;
}
struct ClassData {//this would be the 0x19...
	unsigned int base;

	unsigned int getClassDataAddress() {
		return (unsigned int)&base;
	}
	char* className() {
		return getClassName(getClassDataAddress());
	}

	template <typename T>
	T(*call(unsigned int offset))(...) {//currently untested
		unsigned int __opd_s = *(volatile unsigned int*)(getClassDataAddress() + offset);
		T(*func)(...) = (T(*)(...)) & __opd_s;
		return func;
	}

};
#pragma endregion

#pragma region Option_Helpers
bool x;
bool y;
bool width;
bool height;
bool rotation;

void addOption(char *option, bool keyboard = false, char *info = NULL)
{
	char buf[256];
	char *addOnText = ""; //add on text? came with the menu base idk hold
	optionCount++;
	if (currentOption == optionCount)
	{
		infoText = info;
		addOnText = "> ";//~r~, ~b~... color coding 
	}
	if (infoText)
	{
		//drawText(infoText, optionsFont, menuXCoord, ((optionCount + 1) * 0.035f + 0.125f), 0.4f, 0.4f, bannerTextRed, bannerTextGreen, bannerTextBlue, bannerTextOpacity, true);
	}
	snprintf(buf, sizeof(buf), "%s%s", addOnText, option);
	//draw option text
	drawText(buf, optionsFont, menuXCoord, menuYCoord + 0.04f + (optionCount - 1) * 0.02f, 0.3f, 0.3f, MenuColour_R, MenuColour_G, MenuColour_B, optionsOpacity, false);
	if (keyboard)
	{
		squarePress = true; // something like startKeyboard.. work on it sometime soon..
	}
}
char *ItoS(int num)
{
	char buf[30];
	snprintf(buf, sizeof(buf), "%i", num);
	return buf;
}
bool isNumericChar(char x)
{
	return (x >= '0' && x <= '9') ? true : false;
}
int StoI(char *str)
{
	if (*str == NULL)
		return 0;

	int res = 0,
		sign = 1,
		i = 0;

	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	for (; str[i] != '\0'; ++i)
	{
		if (isNumericChar(str[i]) == false)
			return 0;
		res = res * 10 + str[i] - '0';
	}
	return sign * res;
}
void startKeyboard(int action, char *defaultText, int maxLength)
{
	GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(0, "FMMC_KEY_TIP8", "", defaultText, "", "", "", maxLength);
	keyboardAction = action;
	keyboardActive = true;
}
char opt[100];
void drawTextRightJustify(char * text, int font, float x, float y, float scalex, float scaley, int r, int g, int b, int a)
{
	if (strcmp(SCRIPT::GET_THIS_SCRIPT_NAME(), "ingamehud") == 0)
	{
		UI::SET_TEXT_FONT(font);
		UI::SET_TEXT_SCALE(scalex, scaley);
		UI::SET_TEXT_RIGHT_JUSTIFY(true);
		UI::SET_TEXT_WRAP(0.1f, .95f);
		UI::SET_TEXT_COLOUR(255, 255, 255, 255);
		if (currentOption == optionCount)
		{
			UI::SET_TEXT_COLOUR(0, 0, 0, 255);
			UI::_SET_TEXT_ENTRY("STRING");
			_ADD_TEXT_COMPONENT_STRING(text);
			snprintf(opt, sizeof(opt), "%s", text);
		}
		else
		{
			UI::SET_TEXT_COLOUR(r, g, b, a);
			UI::_SET_TEXT_ENTRY("STRING");
			_ADD_TEXT_COMPONENT_STRING(text);;
		}
		UI::_DRAW_TEXT(x, y);
	}
}
void addOptionAnimation(char *option, char *dict, char *anim) {
	addOption(option);
	if (currentOption == optionCount && optionPress) {
		int targ_ped = PLAYER::GET_PLAYER_PED(selectedPlayer);
		STREAMING::REQUEST_ANIM_DICT(dict);
		if (STREAMING::HAS_ANIM_DICT_LOADED(dict)) {
			Vector3 coords = ENTITY::GET_ENTITY_COORDS(targ_ped, 1);
			int sceneID = NETWORK_CREATE_SYNCHRONISED_SCENE1(coords.x, coords.y, coords.z, 0, 0, 0, 2, 0, 1, 1.0f, 0.0f, 1.0f);
			NETWORK_ADD_PED_TO_SYNCHRONISED_SCENE1(targ_ped, sceneID, dict, anim, 8.0f, -8.0f, 120, 0, 100, 1);
			NETWORK::NETWORK_START_SYNCHRONISED_SCENE(sceneID);
		}
	}
}
void addOptionScenario(char *option, char *dict, char *anim) {
	addOption(option);
	if (currentOption == optionCount && optionPress) {
		int targ_ped = PLAYER::GET_PLAYER_PED(selectedPlayer);
		Vector3 coords = ENTITY::GET_ENTITY_COORDS(targ_ped, 1);
		AI::TASK_START_SCENARIO_IN_PLACE((selectedPlayer), ScenariosChar[ScenariosVar], 0, 1);
	}
} 
void addOptionRightJustify(char *option)
{
	if (currentOption <= maxOptions && optionCount <= maxOptions)//there supposed to be a scroll option on special and General li scrool like left or right?yep exactly i was confused scroller lmaohaha
		drawTextRightJustify(option, 4, textXCoord + .215, (optionCount * 0.035f + 0.123f), .57, .52, 255, 0, 255, 255);
	else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)// ill try to fix
		drawTextRightJustify(option, 4, textXCoord + .215, ((optionCount - (currentOption - maxOptions)) * 0.035f + 0.123f), .57, .52, 255, 0, 255, 255);
}
void playSound(char* sound)
{
	if (menuSounds)
		AUDIO::PLAY_SOUND_FRONTEND(-1, sound, "HUD_FRONTEND_DEFAULT_SOUNDSET");
}
void addCharIntOption(char *option, char **From, int*var, int min, int max, bool any = false)
{
	char buf[50];
	if (!any)
	{
		snprintf(buf, sizeof(buf), "%s: < %s >", option, From[*var]);
		addOption(buf);
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
		snprintf(buf, sizeof(buf), "%s: < %s >", option, From[*var]);
		addOption(buf);
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
	 
}
void addCharSwap(char *option, char **From, int*var, int min, int max, bool any = false, char *info = NULL) {
	char buf[50];
	char buf1[50];
	if (!any) {
		snprintf(buf, sizeof(buf), "%s", option);
		addOption(buf, info);
		snprintf(buf1, sizeof(buf1), "< %s >", From[*var]);
		drawTextRightJustify(buf1, 0, textXCoord + .215, (optionCount * 0.035f + 0.123f), .45, .45, 255, 255, 255, 255);
		if (currentOption == optionCount) {
			lrInstruction = true;
			if (rightPress) {
				playSound("NAV_UP_DOWN");
				if (*var >= max)*var = min;
				else*var = *var + 1;
			}
			else if (leftPress) {
				playSound("NAV_UP_DOWN");
				if (*var <= min)*var = max;
				else*var = *var - 1;
			}
		}
	}
	else {
		snprintf(buf, sizeof(buf), "%s", option);
		addOption(buf, info);
		snprintf(buf1, sizeof(buf1), "< %s >", From[*var]);
		addOptionRightJustify(buf1);
		if (currentOption == optionCount) {
			lrInstruction = true;
			if (rightPress) {
				playSound("NAV_UP_DOWN");
				if (*var >= max)*var = min;
				else*var = *var + 1;
			}
			else if (leftPress) {
				playSound("NAV_UP_DOWN");
				if (*var <= min)*var = max;
				else*var = *var - 1;
			}
		}
	}
}
void addIntTeleportOption(char *option, char **From, int*var, int min, int max, bool any = false)
{
	char buf[50];
	if (!any)
	{
		snprintf(buf, sizeof(buf), "%s: < %s >", option, From[*var]);
		addOption(buf);
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
		snprintf(buf, sizeof(buf), "%s: < %s >", option, From[*var]);
		addOption(buf);
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

}
void addFunBool(char *option, int *var, bool b00l, bool status = NULL)
{
	char buf[30];
	if (b00l)
		snprintf(buf, sizeof(buf), "%s: On", option);
	else
		snprintf(buf, sizeof(buf), "%s: Off", option);
	addOption(buf, NULL);
	int value = *var;
}
#pragma endregion

#pragma region Internals
unsigned int FindNativeTableAddress()
{
	unsigned int  l_uiNativeTableAddress = 0;
	unsigned int l_uiStartAddress = 0x390000;
	unsigned int l_uiAddress = 0;
	for (unsigned int i = 0; i < 0x10000; i++)
	{
		if (*(unsigned int*)(l_uiStartAddress + i) == 0x3C6072BD)
			if (*(unsigned int*)(l_uiStartAddress + i + 8) == 0x6063E002)
			{
				l_uiAddress = *(unsigned int*)(l_uiStartAddress + i + 0x10);
				l_uiAddress &= 0xFFFFFF;
				l_uiAddress += (l_uiStartAddress + i + 0x10) - 1;
				//printf("address: 0x%08x\n", l_uiAddress);
				break;
			}
	}
	l_uiNativeTableAddress = (*(unsigned int*)(l_uiAddress + 0x24) << 16) + (*(unsigned int*)(l_uiAddress + 0x2C) & 0xFFFF);
	l_uiNativeTableAddress -= 0x10000;
	return l_uiNativeTableAddress;
}
int NativeAddress(int Native, bool PatchInJump = true)
{
	int Hash = Native & 0xFF;
	int Table = *(int*)(FindNativeTableAddress() + (Hash * 4));
	while (Table != 0)
	{
		int NativeCount = *(int*)(Table + 0x20);
		for (int i = 0; i < NativeCount; i++)
		{
			if (*(int*)((Table + 0x24) + (i * 4)) == Native)
			{
				if (PatchInJump)
				{
					int NativeLocation = *(int*)(*(int*)((Table + 4) + (i * 4)));
					for (int i = 0; i < 50; ++i)
					{
						short CurrentPlace = *(short*)(NativeLocation + (i * 4));
						if (CurrentPlace == 0x4AE6 || CurrentPlace == 0x4AA8 || CurrentPlace == 0x4AE4 || CurrentPlace == 0x4AE5)
						{
							return (((*(int*)(NativeLocation + (i * 4))) - 0x48000001) + (NativeLocation + (i * 4))) - 0x4000000;
						}
					}
				}
				else
				{
					return *(int*)((Table + 4) + (i * 4));
				}

			}
		}
		Table = *(int*)(Table);
	}
}
void sleep(usecond_t time)  //1 second = 1000
{
	sys_timer_usleep(time * 1000);
}
char* FtoS(float input)
{
	char returnvalue[64];
	int wholenumber = (int)input;
	input -= wholenumber;
	input *= 100;
	sprintf(returnvalue, "%d.%d", wholenumber, (int)input);
	return returnvalue;
}

void DRAW_TEXTURE(char* Streamedtexture, char* textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a)
{
	if (!GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED((char*)Streamedtexture))
	{
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT((char*)Streamedtexture, false);
	}
	else
	{
		GRAPHICS::DRAW_SPRITE((char*)Streamedtexture, (char*)textureName, x, y, width, height, rotation, r, g, b, a);
	}
}
void TopLeftInstructionBox(char* text)
{
	char buf[500];
	snprintf(buf, sizeof(buf), "%s", text);
	UI::BEGIN_TEXT_COMMAND_DISPLAY_HELP("STRING");
	UI::_ADD_TEXT_COMPONENT_STRING(buf);
	UI::END_TEXT_COMMAND_DISPLAY_HELP(0, 0, 1, -1);
}
void addTitle(char *title)
{
	{ // setup box above this box for player info... v5.0.0
		// results found using this calc: https://www.calculatorsoup.com/calculators/math/math.php
		menuXCoord = 0.85 - (0.17f / 2.0f) + 0.005f; // result = 0.505
		menuYCoord = 0.67 - (0.3818f / 2.0f); // result = 0.4791
		char extraText[80];
		sprintf(extraText, "By FaZe Modz v%s", Thismenuversion);
		//drawText(title, bannerTextFont, 0.8055, 0.45, 0.3f, 0.73f, spritered, spritegreen, spriteblue, bannerTextOpacity, false);
		drawText(title, bannerTextFont, 0.8505, 0.45, 0.3f, 0.73f, MenuColour_R, MenuColour_G, MenuColour_B, bannerTextOpacity, true);
		if (submenu == Main_Menu) { drawText(extraText, 1, 0.766, 0.9332, 0.3f, 0.33f, MenuColour_R, MenuColour_G, MenuColour_B, 255, false); }
		GRAPHICS::DRAW_RECT(0.85, 0.70, 0.17, 0.5100, 0, 0, 0, 150); //base 
		GRAPHICS::DRAW_RECT(0.85, 0.446, 0.17, 0.0025, MenuColour_R, MenuColour_G, MenuColour_B, 255); //Top Bar
		GRAPHICS::DRAW_RECT(0.765, 0.70, 0.002, 0.5100, MenuColour_R, MenuColour_G, MenuColour_B, 255); //Left Side Bar 
		GRAPHICS::DRAW_RECT(0.935, 0.70, 0.002, 0.5100, MenuColour_R, MenuColour_G, MenuColour_B, 255); //Right Side Bar 
		GRAPHICS::DRAW_RECT(0.85, 0.9545, 0.17, 0.0025, MenuColour_R, MenuColour_G, MenuColour_B, 255); //Bottm Bar
		DRAW_TEXTURE("commonmenutu", "custom_mission", 0.85, 0.70, 0.26, 0.5400, 10, MenuColour_R, MenuColour_G, MenuColour_B, spriteopacity);//Star Backround Sprite Phuced Help :p Kinda
	}
}
int num = 1;
//Possible ifruit base
void AddPhoneContact(char* text)
{
	//request ifruit handle
	int scaleForm = GRAPHICS::REQUEST_SCALEFORM_MOVIE("cellphone_ifruit");
	//push function to the stack to change the data
	//GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION(scaleForm, "SET_DATA_SLOT");
	MOBILE::GET_MOBILE_PHONE_RENDER_ID1("cellphone_ifruit");
	//not sure
	GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_FLOAT((float)2);//could be a pc native not really sure
	//set data slot index
	GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_FLOAT((float)num);//some number idk yet | Going to use 1	 for now
	//not sure
	GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_FLOAT(0.0f);
	GRAPHICS::_BEGIN_TEXT_COMPONENT("STRING");
	//add our text
	UI::_ADD_TEXT_COMPONENT_STRING(text);//might just leave this as param text
	GRAPHICS::_END_TEXT_COMPONENT();
	GRAPHICS::_BEGIN_TEXT_COMPONENT("CELL_MP_999");
	GRAPHICS::_END_TEXT_COMPONENT();
	GRAPHICS::_BEGIN_TEXT_COMPONENT("CELL_MP_999");
	GRAPHICS::_END_TEXT_COMPONENT();
	//pop and call on the stack
	GRAPHICS::_POP_SCALEFORM_MOVIE_FUNCTION_VOID();
	//increment index for next item
	num += 1;
}

//call when user opens ifruit/ contacts app
#pragma region Option Helpers
bool freezecar;
void FreezeCarImport() {
	WriteBytes(0x13BF800, "%s: ON", 4);

}
void FreezeCarDefault() {
	WriteBytes(0x13BF800, "%s: OFF", 4);
}
void SessionCheck() {
	if (NETWORK::NETWORK_IS_IN_SESSION()) {
		if (freezecar) {
			FreezeCarImport();
			freezecar = true;
		}
	}
	else {
		if (freezecar) {
			FreezeCarDefault();
			freezecar = false;
		}
	}
}
void FreezeCarProtect() {
	if (freezecar) {
		SessionCheck();
	}
	else {
		FreezeCarDefault();
	}
}
void changeSubmenu(int newSubmenu)
{
	lastSubmenu[submenuLevel] = submenu;
	lastOption[submenuLevel] = currentOption;
	currentOption = 1;
	submenu = newSubmenu;
	submenuLevel++;
}
void addSubmenuOption(char *option, int newSubmenu, char *info = NULL)
{
	addOption(option, info);
	if (currentOption == optionCount)
	{
		xInstruction = true;
		if (optionPress)
			changeSubmenu(newSubmenu);
	}
}
void addBoolOption(char *option, bool b00l, char *info = NULL)
{
	char buf[30];
	if (b00l)
	{
		snprintf(buf, sizeof(buf), "%s: On", option);
		addOption(buf, info);
	}
	else
	{
		snprintf(buf, sizeof(buf), "%s: Off", option);
		addOption(buf, info);
	}
}
void addBoolOption(char *option, bool *b00l, char *info = NULL)
{
	char buf[30];
	if (*b00l)
	{
		snprintf(buf, sizeof(buf), "%s: On", option);
		addOption(buf, info);
	}
	else
	{
		snprintf(buf, sizeof(buf), "%s: Off", option);
		addOption(buf, info);
	}
	if (currentOption == optionCount)
	{
		xInstruction = true;
		if (optionPress)
			*b00l = !*b00l;
	}
}

template<typename TYPE>
void addCustomBoolOption(char *option, TYPE value, TYPE match, char *info = NULL)
{
	char buf[30];
	if (value == match)
	{
		snprintf(buf, sizeof(buf), "%s: On", option);
		addOption(buf, info);
	}
	else
	{
		snprintf(buf, sizeof(buf), "%s: Off", option);
		addOption(buf, info);
	}
}

void addIntOption(char *option, int *var, int min, int max, bool keyboard, char *info = NULL) 
{
	char buf[30];
	snprintf(buf, sizeof(buf), "%s: < %i >", option, *var);
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
		if (keyboard)
		{
			squareInstruction = true;
			if (squarePress)
			{
				startKeyboard(0, "", (strlen(ItoS(max)) + 1));
				keyboardVar = var;
			}
		}
	}
}
void addStringOption(char *option, char **value, int *var, int array_size, char *info = "") 
{
	char buf[90];
	addOption(option, info);
	snprintf(buf, sizeof(buf), "< %s >", value[*var]);
	drawTextRightJustify(buf, 4, textXCoord + .215, (optionCount * 0.035f + 0.123f), .57, .52, 255, 0, 255, 255);
	if (currentOption == optionCount)
	{
		lrInstruction = true;
		if (rightPress)
		{
			playSound("NAV_UP_DOWN");
			if (*var >= array_size) *var = 0;
			else*var = *var + 1;
		}
		else if (leftPress)
		{
			playSound("NAV_UP_DOWN");
			if (*var <= 0) *var = array_size;
			else*var = *var - 1;
		}
	}
}
void addFloatOption(char *option, float *var, float min, float max, bool holdPress, char *info = NULL)
{
	char buf[30];
	snprintf(buf, sizeof(buf), "%s: < %s >", option, FtoS(*var));
	addOption(buf, info);
	if (currentOption == optionCount)
	{
		lrInstruction = true;
		if (holdPress)
		{
			if (fastRightPress)
			{
				playSound("NAV_UP_DOWN");
				if (*var >= max)
					*var = min;
				else
					*var = *var + 0.01f;
			}
			else if (fastLeftPress)
			{
				playSound("NAV_UP_DOWN");
				if (*var <= min)
					*var = max;
				else
					*var = *var - 0.01f;
			}
		}
		else
		{
			if (rightPress)
			{
				playSound("NAV_UP_DOWN");
				if (*var >= max)
					*var = min;
				else
					*var = *var + 0.01f;
			}
			else if (leftPress)
			{
				playSound("NAV_UP_DOWN");
				if (*var <= min)
					*var = max;
				else
					*var = *var - 0.01f;
			}
		}
	}
}
void addTeleportOption(char *option, float x, float y, float z)
{
	addOption(option);
	if (currentOption == optionCount && optionPress)
	{
		uint handle = PLAYER::PLAYER_PED_ID();
		if (PED::IS_PED_IN_ANY_VEHICLE(handle, 0))
			handle = PED::GET_VEHICLE_PED_IS_IN(handle, 0);
		SET_ENTITY_COORDS1(handle, x, y, z, 0, 0, 0, 1);
	}
}
int newSubmenu = 0;//PB said keep for now

void SetupTimer(int tickTime)
{
	if (newTimerTick) {
		maxTimerCount = GAMEPLAY::GET_GAME_TIMER() + tickTime;
		newTimerTick = false;
	}
}

bool IsTimerReady()
{
	return GAMEPLAY::GET_GAME_TIMER() > maxTimerCount;
}

void ResetTimer()
{
	newTimerTick = true;
}

void SetupTimer2(int tickTime)
{
	if (newTimerTick2) {
		maxTimerCount2 = GAMEPLAY::GET_GAME_TIMER() + tickTime;
		newTimerTick2 = false;
	}
}

bool IsTimerReady2()
{
	return GAMEPLAY::GET_GAME_TIMER() > maxTimerCount2;
}

void ResetTimer2()
{
	newTimerTick2 = true;
}
void addKeyboardOption(char *option, int action, char *defaultText, int maxLength, char *info = NULL)
{
	addOption(option, info);
	if (currentOption == optionCount)
	{
		xInstruction = true;
		if (optionPress)
			startKeyboard(action, defaultText, maxLength);
	}
}

void set_text_component(char *text)
{
	GRAPHICS::_0x3AC9CB55("STRING");
	UI::_ADD_TEXT_COMPONENT_STRING(text);
	GRAPHICS::END_TEXT_COMMAND_SCALEFORM_STRING();
}

void instructionsSetup()
{
	mov = GRAPHICS::REQUEST_SCALEFORM_MOVIE("instructional_buttons");
	GRAPHICS::_0x7B48E696(mov, 255, 255, 255, 0);
	GRAPHICS::_0x215ABBE8(mov, "CLEAR_ALL");
	GRAPHICS::_0x02DBF2D7();
	GRAPHICS::_0x215ABBE8(mov, "SET_CLEAR_SPACE");
	GRAPHICS::_0x716777CB(200);
	GRAPHICS::_0x02DBF2D7();
	instructCount = 0;
}

void addInstruction(int button, char *text)
{
	if (!instructionsSetupThisFrame)
	{
		instructionsSetup();
		instructionsSetupThisFrame = true;
	}
	GRAPHICS::_0x215ABBE8(mov, "SET_DATA_SLOT");
	GRAPHICS::_0x716777CB(instructCount);
	GRAPHICS::_0x716777CB(button);
	set_text_component(text);
	GRAPHICS::_0x02DBF2D7();
	instructCount++;
}

void instructionsClose()
{
	GRAPHICS::_0x215ABBE8(mov, "DRAW_INSTRUCTIONAL_BUTTONS");
	GRAPHICS::_0x02DBF2D7();
	GRAPHICS::_0x215ABBE8(mov, "SET_BACKGROUND_COLOUR");
	GRAPHICS::_0x716777CB(0);
	GRAPHICS::_0x716777CB(0);
	GRAPHICS::_0x716777CB(0);
	GRAPHICS::_0x716777CB(80);
	GRAPHICS::_0x02DBF2D7();
}

#pragma endregion
int getOption()
{
	xInstruction = true;
	if (optionPress)
		return currentOption;
	else return 0;
}
bool firstopen = true;
void monitorButtons()
{
	SetupTimer(20);
	if (submenu == Closed)
	{
		if (firstopen)
		{
			if (IsTimerReady2())
			{
				addInstruction(BUTTON_START, "+   ");
				addInstruction(BUTTON_BACK, "Exit Game");
				instructionsClose();
				ResetTimer2();
			}
		}
		if (CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, Button_R1) && CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, Dpad_Right))//Menu Opens with these
		{
			AUDIO::PLAY_SOUND_FRONTEND(-1, "FLIGHT_SCHOOL_LESSON_PASSED", "HUD_AWARDS");// on menu open play sound
			submenu = Main_Menu;
			if (firstopen)
			{
				drawNotification("Welcome to Tiny Menu!");
				if (submenu == Main_Menu) { 
					char buff[80]; 
					sprintf(buff, "Welcome to TinyMenu V%s", Thismenuversion); 
					DoNotify(buff, 0);
				}
				firstopen = false;
			}
			submenuLevel = 0;
			currentOption = 1;
			playSound("YES");
		}
		ResetTimer();
	}
	else {
		
		{
			if (CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(0, Button_B))
			{
				if (submenu == Main_Menu)
				{
					submenu = Closed;
				}
				else
				{
					submenu = lastSubmenu[submenuLevel - 1];
					newSubmenu = lastSubmenu[submenuLevel - 1];
					currentOption = lastOption[submenuLevel - 1];
					submenuLevel--;
				}
				playSound("Back");
			}
			else if (CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(0, Button_A))
			{
				optionPress = true;
				playSound("SELECT");
			}
			else if (CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(0, Dpad_Up))
			{
				currentOption--;
				if (currentOption < 1)
				{
					currentOption = optionCount;
				}
				playSound("NAV_UP_DOWN");
			}
			else if (CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(0, Dpad_Down))
			{
				currentOption++;
				if (currentOption > optionCount)
				{
					currentOption = 1;
				}
				playSound("NAV_UP_DOWN");
			}
			else if (CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(0, Dpad_Right))
			{
				rightPress = true;
			}
			else if (CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(0, Dpad_Left))
			{
				leftPress = true;
			}
			else if (CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, Dpad_Right))
			{
				fastRightPress = true;
			}
			else if (CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, Dpad_Left))
			{
				fastLeftPress = true;
			}
			else if (CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(0, Button_X))
			{
				squarePress = true;
			}
			ResetTimer();
		}
	}
}
void normalMenuActions()
{
	UI::HIDE_HELP_TEXT_THIS_FRAME();
	CAM::SET_CINEMATIC_BUTTON_ACTIVE(0);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(10);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(6);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(7);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(9);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(8);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 19);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 20);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 21);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 27);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 54);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 123);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 124);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 125);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 126);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 138);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 139);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 140);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 177);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 178);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 179);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 207);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 166);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 167);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 177);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 178);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 193);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 194);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 195);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 202);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 203);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 204);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 205);
}
void resetVars()
{
	if (submenu != Closed)
		normalMenuActions();
	optionPress = false;
	rightPress = false;
	leftPress = false;
	fastRightPress = false;
	fastLeftPress = false;
	squarePress = false;
	infoText = NULL;
	instructionsSetupThisFrame = false;
	squareInstruction = false;
	xInstruction = false;
	lrInstruction = false;
}
#pragma endregion

#pragma region Rare Funcs
bool RplayerFcar = false;
bool toggleIP = false;
void KickFromCar(int VehicleHandle)
{
	AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::GET_PLAYER_PED(VehicleHandle));
}
#pragma endregion

#pragma region Other Loop
void otherLoop()
{
	if (rainmoney) {
		float RandomX = GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(-5, 5);
		float RandomY = GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(-5, 5);
		float RandomZ = GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(3, 4);
		Vector3 SpawnLocation = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS1(PLAYER::PLAYER_PED_ID(), RandomX, RandomY, RandomZ);
		DROP40(SpawnLocation);
		rainmoneycooldown = GAMEPLAY::GET_GAME_TIMER() + 50;
	}
	if (keyboardActive)
	{
		if (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 1)
		{
			keyboardActive = false;
			switch (keyboardAction)
			{
			case 0: //addIntOption
				*keyboardVar = StoI(GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT());
				break;
			}
		}
		else if (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 2 || GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 3)
		{
			keyboardActive = false;
		}
		if (driveontype == 1)
		{
			if (VEHICLE::IS_VEHICLE_ON_ALL_WHEELS(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false)))
			{
				if (CONTROLS::IS_CONTROL_PRESSED(2, Button_R2))
				{
					VEHICLE::SET_VEHICLE_FORWARD_SPEED(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false), 30.0f); //30.0f is speed
				}
				else if (CONTROLS::IS_CONTROL_RELEASED(2, Button_R2))
				{
					VEHICLE::SET_VEHICLE_FORWARD_SPEED(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false), 0.0f); //0.0f is speed
				}
			}

		}
		else if (driveontype == 2) //Code Fucked Beyond Recognition
		{
			if (CONTROLS::IS_CONTROL_PRESSED(2, Button_R2))
			{
				//printf("R2 Pressed\n");
				VEHICLE::SET_VEHICLE_FORWARD_SPEED(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), true), ENTITY::GET_ENTITY_SPEED(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false) + 1)); //30.0f is speed
			}
			else if (CONTROLS::IS_CONTROL_RELEASED(2, Button_R2))
			{
				VEHICLE::SET_VEHICLE_FORWARD_SPEED(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), true), 0.0f); //0.0f is speed
			}
			if (CONTROLS::IS_CONTROL_PRESSED(2, Button_R1))
			{
				//printf("R1 Pressed\n");
				Vector3 rot = ENTITY::GET_ENTITY_ROTATION(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), true), 2);
				ENTITY::SET_ENTITY_ROTATION(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), true), rot.x, rot.y, rot.z += 1.5, 2, 1); //Thanks 2 TheRoulleteBoi, Dont ask me to explain I cant..
			}
			if (CONTROLS::IS_CONTROL_PRESSED(2, Button_L1))
			{
				//printf("L1 Pressed\n");
				Vector3 rot = ENTITY::GET_ENTITY_ROTATION(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), true), 2);
				ENTITY::SET_ENTITY_ROTATION(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), true), rot.x, rot.y, rot.z -= 1.5, 2, 1);
			}
			if (CONTROLS::IS_CONTROL_PRESSED(2, Button_L2))
			{
				//printf("L2 Pressed\n");
				VEHICLE::SET_VEHICLE_FORWARD_SPEED(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), true), -30.0f); //30.0f is speed
			}
			else if (CONTROLS::IS_CONTROL_RELEASED(2, Button_L2))
			{
				VEHICLE::SET_VEHICLE_FORWARD_SPEED(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), true), 0.0f); //0.0f is speed
			}
		}
		if (VehicleNOS) {
			int AddSpeed = 50;  // Range of 0 to 100 is advised
			if (PLAYER::IS_PLAYER_PRESSING_HORN(PLAYER::PLAYER_PED_ID()))
			{
				int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				if ((PLAYER::IS_PLAYER_PRESSING_HORN(PLAYER::PLAYER_ID())) && (VEHICLE::IS_VEHICLE_ON_ALL_WHEELS(veh)))
				{
					//AUDIO::SET_VEHICLE_BOOST_ACTIVE(veh, 1);// Add sound effect
					NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(PED::GET_VEHICLE_PED_IS_IN(selectedPlayer, false)); //Need This to Get Control of Online Players Vehicle..
					float Speed = ENTITY::GET_ENTITY_SPEED(veh) + (float)AddSpeed;         // Calculate new speed
					VEHICLE::SET_VEHICLE_FORWARD_SPEED(veh, Speed);                  // Set new speed
				}
			}
		}

		//if (unlimitedammo) {
			//WEAPON::SET_PED_INFINITE_AMMO_CLIP(PLAYER::PLAYER_PED_ID(), false); Old Way of Writing it
		//}

		if (noragdoll) {
			PED::SET_PED_CONFIG_FLAG(PLAYER::PLAYER_PED_ID(), PED_FLAG_CAN_FLY_THRU_WINDSCREEN, false); //1 = true 0 =false
			PED::SET_PED_CONFIG_FLAG(PLAYER::PLAYER_PED_ID(), PED_FLAG_NO_COLLISION, true);
			PED::SET_PED_CONFIG_FLAG(PLAYER::PLAYER_PED_ID(), PED_FLAG_DIES_BY_RAGDOLL, false);
			PED::SET_PED_CAN_RAGDOLL(PLAYER::PLAYER_PED_ID(), false);
			PED::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(PLAYER::PLAYER_PED_ID(), false);
			PLAYER::SET_PLAYER_INVINCIBLE(PLAYER::PLAYER_PED_ID(), false);
			ENTITY::SET_ENTITY_INVINCIBLE(0xC1213A21, false);
			PED::SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE(PLAYER::PLAYER_PED_ID(), 1);
			PLAYER::GIVE_PLAYER_RAGDOLL_CONTROL(PLAYER::PLAYER_PED_ID(), false);
			PED::SET_PED_RAGDOLL_ON_COLLISION(PLAYER::PLAYER_PED_ID(), false);
			if (PED::IS_PED_RAGDOLL(PLAYER::PLAYER_PED_ID()) == true)
			{
				PED::RESET_PED_RAGDOLL_TIMER(PLAYER::PLAYER_PED_ID());
			}
		}
	}
	if (driftmod) {
		if (CONTROLS::IS_CONTROL_PRESSED(2, Button_X))//Square On Playstation
		{
			int veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
			VEHICLE::SET_VEHICLE_REDUCE_GRIP(veh, true);
		} if (CONTROLS::IS_CONTROL_RELEASED(2, Button_X))
		{
			int veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
			VEHICLE::SET_VEHICLE_REDUCE_GRIP(veh, false);
		}
	}
	if (clearArea)
	{
		Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
		GAMEPLAY::_CLEAR_AREA_OF_EVERYTHING(coords.x, coords.y, coords.z, 50000.0f, 1, 1, 1, 1); 
		GAMEPLAY::CLEAR_AREA_OF_COPS(coords.x, coords.y, coords.z, 5000.0f, 1);
	}
	if (rainweapons) {
		float RandomX = GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(-5, 5);//spread -15, 15 = 0
		float RandomY = GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(-5, 5);
		float RandomZ = GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(3, 4);
		Vector3 me = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), RandomX, RandomY, RandomZ);
		OBJECT::CREATE_AMBIENT_PICKUP(WepPickupArray[GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 48)], me.x, me.y, me.z, 0, 0, 1, false, true);
		rainweaponscooldown = GAMEPLAY::GET_GAME_TIMER() + 50; //Code Thanks to PB Modz
	}
	if (bool_player[5] && !bool_player[6]) {
		Vector3 MyPos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
		Vector3 TheirCoordss = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), false);
		float Distance = GAMEPLAY::GET_DISTANCE_BETWEEN_COORDS(MyPos.x, MyPos.y, MyPos.z, TheirCoordss.x, TheirCoordss.y, TheirCoordss.z, false);
		if (Distance < 100)
			PRINT("~r~You Are Too Close To Target");
		else {
			FreezePedID = PED::CREATE_PED(21, 0x3F039CBA, TheirCoordss.x, TheirCoordss.y, TheirCoordss.z, 0, 1, 0);
			if (FreezePedID != 0) {
				ATTACH_ENTITY_TO_ENTITY1(FreezePedID, PLAYER::GET_PLAYER_PED(selectedPlayer)); //PB is a boss but dont ask what this does
				DeleteSpawnedPedFreezeDelay = GAMEPLAY::GET_GAME_TIMER() + 500; bool_player[6] = true;
				char buff[50];
				char* name = PLAYER::GET_PLAYER_NAME(selectedPlayer);
				snprintf(buff, sizeof(buff), "Freezing %s", name);
				PRINT(buff);
			}
		}
	}
	else if (bool_player[6] && bool_player[7] < GAMEPLAY::GET_GAME_TIMER()) {
		PED::DELETE_PED(&FreezePedID);
		PRINT("~g~Target  Froze!");
		bool_player[6] = false;
		bool_player[5] = false;
	}
	if (CONTROLS::IS_CONTROL_JUST_PRESSED(0, Button_X), superRun)
	{
		ENTITY::APPLY_FORCE_TO_ENTITY(PLAYER::PLAYER_PED_ID(), true, 0, 60, 0, 0, 0, 0, true, true, true, true, false, true);
	}

	if (neverwanted)
	{
		PLAYER::CLEAR_PLAYER_WANTED_LEVEL(PLAYER::PLAYER_PED_ID());//For the record This never worked!
	}
	if (rapidfire)
	{
		Hash cur;
		if (WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &cur, 1))
		{
			if (WEAPON::IS_WEAPON_VALID(cur))
			{
				if (!WEAPON::HAS_WEAPON_ASSET_LOADED(cur))
				{
					WEAPON::REQUEST_WEAPON_ASSET(cur, 31, 0);
				}
				PED::SET_PED_FIRING_PATTERN(PLAYER::PLAYER_PED_ID(), FIRING_PATTERN_BURST_FIRE_PUMPSHOTGUN);
				if (CONTROLS::IS_CONTROL_PRESSED(2, INPUT_ATTACK))
				{
					Vector3 camvf = get_coords_from_cam(3.0f);
					Vector3 camvt = get_coords_from_cam(100.0f);
					GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS1(camvf.x, camvf.y, camvf.z,
						camvt.x, camvt.y, camvt.z,
						250, 1, cur, PLAYER::PLAYER_PED_ID(), 0, 1, 500.0f);
				}
			}
		}
	}
	if (fcar) {
		FlyingCar();
	}
	if (selfoffradar) {
		WriteInt32(ReadInt32(0x1E70394) + 0x22284, 2147483647);
		Write_Global(2390201 + PLAYER::PLAYER_ID() * 223 + 170, 1);
		Write_Global(2394218 + 55, 2147483647);
	}
	else {
		WriteInt32(ReadInt32(0x1E70394) + 0x22284, 0);
	}
	if (NoCops)
	{
		Write_Global(2410912 + 4141, 5);
		Write_Global(2410912 + 4144, 2147483647);
	}
	else {
		Write_Global(2410912 + 4141, 0);
	}
	if (HasNeons)
	{
		LoopingNeons();
	}
	if (superRun)//superRun is the bool
	{
		(CONTROLS::IS_CONTROL_JUST_PRESSED(0, Button_X));
		ENTITY::APPLY_FORCE_TO_ENTITY(PLAYER::PLAYER_PED_ID(), true, 0, 60, 0, 0, 0, 0, true, true, true, true, false, true);
	}
	if (dorollercoaster) {
		if (spawnrollercoaster()) {
			dorollercoaster = false;
		}
	}
	if (moneyrain) {
		Dropmoney;
	}
	if (deposit)
	{
		direct_deposit();
	}
	if (loop40K_)
	{
		Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), 0);
		float Loc[3];
		STREAMING::REQUEST_MODEL(0x113FD533);
		if (STREAMING::HAS_MODEL_LOADED(0x113FD533) == 1)
		{
			OBJECT::CREATE_AMBIENT_PICKUP(0xCE6FDD6B, MyCoords.x, MyCoords.y, MyCoords.z + 1.2, 0, 40000, 0x113FD533, 0, 1);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(0x113FD533);
		}
	}
	if (wanted)
	{
		PLAYER::CLEAR_PLAYER_WANTED_LEVEL(PLAYER::PLAYER_ID());
		PLAYER::SET_PLAYER_WANTED_LEVEL_NOW(PLAYER::PLAYER_ID(), false);
	}
	else
	{
		PLAYER::SET_PLAYER_WANTED_LEVEL_NOW(PLAYER::PLAYER_ID(), true);
	}
	if (ghostrider1) {
		if (int_PlayerOption[1] < GAMEPLAY::GET_GAME_TIMER()) {
			for (int i = 0; i < 5; i++) {
				STREAMING::_REQUEST_DLC_PTFX_ASSET("scr_rcbarry2");
				_SET_PTFX_ASSET_NEXT_CALL("scr_rcbarry2");
				_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("scr_clown_death", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, ParticleManBones[i], 0.3, 1, 1, 1);
			}
			int_PlayerOption[1] = GAMEPLAY::GET_GAME_TIMER() + 900;
		}
	}
	if (ghostrider2) {
		if (int_PlayerOption[1] < GAMEPLAY::GET_GAME_TIMER()) {
			for (int i = 0; i < 5; i++) {
				STREAMING::_REQUEST_DLC_PTFX_ASSET("scr_agencyheist");
				_SET_PTFX_ASSET_NEXT_CALL("scr_agencyheist");
				_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("scr_fbi_dd_breach_smoke", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, ParticleManBones[i], 0.1, 1, 1, 1);
			}
			int_PlayerOption[1] = GAMEPLAY::GET_GAME_TIMER() + 900;
		}
	}
	if (tube) {
		if (Tube()) {
			tube = false;
		}
	}
	if (Radaroff)
	{
		UI::DISPLAY_RADAR(false);
	}
	else {
		UI::DISPLAY_RADAR(true);
	}
	if (RevealAll)
	{
		Write_Global(2394218 + 56, 2147483647);
		Write_Global(2390201 + PLAYER::PLAYER_ID() * 223 + 172, 1);
	}
	else {
		Write_Global(2390201 + PLAYER::PLAYER_ID() * 223 + 172, 0);
	}
	if (Resetviewlp) {
		static int delay = 0;
		if (delay < GAMEPLAY::GET_GAME_TIMER()) {
			ResetPlayerView(selectedPlayer);
			delay = GAMEPLAY::GET_GAME_TIMER() + 200;
		}
	}
	if (Godmodplveh) {
		Vehicle pv = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED(selectedPlayer), 0);
		ENTITY::SET_ENTITY_INVINCIBLE(pv, 1);
		VEHICLE::SET_VEHICLE_CAN_BREAK(pv, 0);
		ENTITY::SET_ENTITY_CAN_BE_DAMAGED(pv, 0);
		ENTITY::SET_ENTITY_PROOFS(pv, 1, 1, 1, 1, 1, 1, 1, 1);
		VEHICLE::SET_VEHICLE_STRONG(pv, 1);
		VEHICLE::SET_VEHICLE_CAN_BE_VISIBLY_DAMAGED(pv, 1);
		VEHICLE::SET_VEHICLE_DIRT_LEVEL(pv, 1.0);
	}
	else {
		Vehicle pv = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED(selectedPlayer), 0);
		ENTITY::SET_ENTITY_INVINCIBLE(pv, 0);
		VEHICLE::SET_VEHICLE_CAN_BREAK(pv, 1);
		ENTITY::SET_ENTITY_CAN_BE_DAMAGED(pv, 1);
		ENTITY::SET_ENTITY_PROOFS(pv, 0, 0, 0, 0, 0, 0, 0, 0);
		VEHICLE::SET_VEHICLE_STRONG(pv, 0);
		VEHICLE::SET_VEHICLE_CAN_BE_VISIBLY_DAMAGED(pv, 0);
		VEHICLE::SET_VEHICLE_DIRT_LEVEL(pv, 15.0);
	}
	if (fakeloop40)
	{
		STREAMING::REQUEST_MODEL(0x113FD533);
		if (STREAMING::HAS_MODEL_LOADED(0x113FD533) == 1)
		{
			Vector3 c = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), true);
			OBJECT::CREATE_AMBIENT_PICKUP(0xCE6FDD6B, c.x, c.y, c.z + 1.6, 0, 0, 0x113FD533, 0, 1);//0x113FD533 money bags
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(0x113FD533);
		}
	}
	if (specPlayer)
	{
		NETWORK::NETWORK_SET_IN_SPECTATOR_MODE(1, PLAYER::GET_PLAYER_PED(selectedPlayer));
	}
	else {
		NETWORK::NETWORK_SET_IN_SPECTATOR_MODE(0, PLAYER::GET_PLAYER_PED(selectedPlayer));
	}
	if (clientwanted)
	{
		int Args3[2];
		Args3[0] = 356;
		Args3[1] = selectedPlayer;
		TriggerScriptEvent(Args3, 3, selectedPlayer);
	}
	if (forcefeld)
	{
		Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), 1);
		FIRE::ADD_EXPLOSION(Coords.x, Coords.y, Coords.z, 0x08, 640.00, 0, 1, 0);
	}
	if (BigPunch)
	{
		GAMEPLAY::SET_EXPLOSIVE_MELEE_THIS_FRAME(PLAYER::PLAYER_ID());
	}
	if (BossMode) {
		for (int i = 0; i < 18; i++) {
			if (PLAYER::IS_PLAYER_TARGETTING_ENTITY(i, PLAYER::PLAYER_PED_ID())) {
				Vector3 Pos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(i), true);
				FIRE::ADD_EXPLOSION(Pos.x, Pos.y, Pos.z, 27, 5.0, 1, 0, 0);
			}
		}
	}
	if (depositfreeze) {
		if (PLAYER::GET_PLAYER_MAX_ARMOUR(PLAYER::GET_PLAYER_PED(selectedPlayer)) != 170 & PLAYER::GET_PLAYER_MAX_ARMOUR(PLAYER::GET_PLAYER_PED(selectedPlayer)) != 1997) {
			static int delay = 0;
			if (delay < GAMEPLAY::GET_GAME_TIMER()) {
				givePlayerMoney(selectedPlayer, 100000000/*0x7FFFFFFF*/);
				delay = GAMEPLAY::GET_GAME_TIMER() + 250;
			}
		}
		else 
		{
			PRINT("~r~ERROR: ~w~CANNOT FREEZE OTHER TINYMENU USERS!");
		}
	}//Update V2.2.0
	if (DoorsOpen)
	{
		int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		Vehicle networkedcar = NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(VehID);
		if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(networkedcar))
		{
			OpenDoors(networkedcar);
		}
	}
	else if (!DoorsOpen)
	{
		int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		Vehicle networkedcar = NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(VehID);
		if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(networkedcar))
		{
			VEHICLE::SET_VEHICLE_DOORS_SHUT(networkedcar, false);
		}
	}
	if (doUndriveableCar)
	{
		undriveablePlayersCar(selectedPlayer);
	}
	if (RplayerFcar)
	{
		KickFromCar(PED::GET_VEHICLE_PED_IS_IN(selectedPlayer, false));
	}
	if (Shotsling)
	{
		slingshot(selectedPlayer);
	}
	if (clonefreeze)
	{
		ClonePed(selectedPlayer);
	}
	if (dropkickpro)
	{
			// heh u thought it would be that easy to find :p
	}
	if (adminkickprotect)
	{
		*(unsigned int*)0x9FBBC8 = 0x60000000;
		*(unsigned int*)0x9FBBCC = 0x60000000;
		*(unsigned int*)0x9FBA00 = 0x60000000;
	}
	
	/*
	if (teleprotect)
	{
		*(int*)0x12D0584 = 0x4e800020;
	}
	else
	{
		*(int*)0x12D0584 = 0x7C08024A6;
	}
	if (NonHostKickProtect)
	{
		*(int*)0x12D1A50 = 0x4e800020;
	}
	else
	{
		*(int*)0x12D1A50 = 0x7C08024A6;
	}
	if (fakeleavefix)
	{
		*(int*)0x12C2988 = 0x4e800020;
	}
	else
	{
		*(int*)0x12C2988 = 0x7C08024A6;
	}
	if (RPfix)
	{
		*(int*)0x12D1E28 = 0x4e800020;
	}
	else
	{
		*(int*)0x12D1E28 = 0x7C08024A6;
	}
	if (BankFix)
	{
		*(int*)0x12CB55C = 0x4e800020;
	}
	else
	{
		*(int*)0x12CB55C = 0x7C08024A6;
	}
	if (Minigame)
	{
		*(int*)0x12C8D60 = 0x4e800020;
	}
	else
	{
		*(int*)0x12C8D60 = 0x7C08024A6;
	}
	if (FXPro)
	{
		*(int*)0x12C5638 = 0x4e800020;
	}
	else
	{
		*(int*)0x12C5638 = 0x7C08024A6;
	}
	if (ControlPro)
	{
		*(int*)0x12C3C74 = 0x4e800020;
	}
	else
	{
		*(int*)0x12C3C74 = 0x7C08024A6;
	}
	if (SpamPro)
	{
		*(int*)0x12BD36C = 0x4e800020;
	}
	else
	{
		*(int*)0x12BD36C = 0x7C08024A6;
	}
	if (TimePro)
	{
		*(int*)0x12BDFCC = 0x4e800020;
	}
	else
	{
		*(int*)0x12BDFCC = 0x7C08024A6;
	}*/
	if (weatherpro)
	{
		*(int*)0x12D5098 = 0x4e800020;
	}
	else
	{
		*(int*)0x12D5098 = 0x7C08024A6;
	}
	if (oneshot)
	{
		PLAYER::SET_PLAYER_WEAPON_DAMAGE_MODIFIER(PLAYER::PLAYER_ID(), 9999);
	}
	else
	{
		PLAYER::SET_PLAYER_WEAPON_DAMAGE_MODIFIER(PLAYER::PLAYER_ID(), 1);
	}
	if (ghostrider11) {
		if (int_PlayerOption[1] < GAMEPLAY::GET_GAME_TIMER()) {
			for (int i = 0; i < 5; i++) {
				STREAMING::_REQUEST_DLC_PTFX_ASSET("scr_rcbarry2");
				_SET_PTFX_ASSET_NEXT_CALL("scr_rcbarry2");
				_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("scr_clown_death", selectedPlayer, 0, 0, 0, 0, 0, 0, ParticleManBones[i], 0.3, 1, 1, 1);
			}
			int_PlayerOption[1] = GAMEPLAY::GET_GAME_TIMER() + 900;
		}
	}
	if (Give_RP)//Test These
	{
		int Args[5];
		Args[0] = 0xD8;
		Args[1] = selectedPlayer;
		Args[2] = 10000; //RP Level
		Args[3] = 0;
		Args[4] = 0;
		TriggerScriptEvent1(Args, 5, selectedPlayer);
	}
	if (Take_RP)
	{
		int Args[5];
		Args[0] = 0xD8;
		Args[1] = selectedPlayer;
		Args[2] = -10000;//RP Level
		Args[3] = 0;
		Args[4] = 0;
		TriggerScriptEvent1(Args, 5, selectedPlayer);
	}
	if (ClearPlayrTaskLoop)
	{
		endTask(selectedPlayer);
	}
	if (TeleportToMe)
	{
		TeleportVehicle = PED::GET_VEHICLE_PED_IS_IN(selectedPlayer, true);
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(TeleportVehicle);
		if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(TeleportVehicle))
		{
			Vector3 MyLoc = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
			ENTITY::SET_ENTITY_COORDS(TeleportVehicle, MyLoc.x, MyLoc.y, MyLoc.z, true, false, false, true);
			TeleportToMe = false;
		}
	}//start of Vehicle Binds
	if (leftfix) { if (CONTROLS::IS_CONTROL_JUST_PRESSED(0, Dpad_Left)) VEHICLE::SET_VEHICLE_FIXED(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID())); }
	if (downscorch) { if (CONTROLS::IS_CONTROL_JUST_PRESSED(0, Dpad_Down)) ENTITY::SET_ENTITY_RENDER_SCORCHED(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false), 1); } //1 = Render entity burnt true
	for (int i = 0; i < 16; i++)//Variable we made for all players in lobby
	{
		playrhornboost(selectedPlayer);
	}
	if (doModdedT20)
	{
		if (spawnModdedT20()) { doModdedT20 = false; }
			
	}
	if (doBoatNTrailer)
	{
		if (spawnBoatNTrailer()){ doBoatNTrailer = false; }
			
	}
	if (doFlatBed)
	{
		if (spawnFlatBed()){ doFlatBed = false; }
			
	}
	if (doTruck)
	{
		if (spawn_Truck()){ doTruck = false; }
			
	}
	if (doJetSki)
	{
		if (spawnJetSki()){ doJetSki = false; }
			
	}

	if (doRampTruck)
	{
		if (RampTruck()){ doRampTruck = false; }
			
	}
	if (doBusTruck)
	{
		if (BusTruck()){ doBusTruck = false; }
			
	}
	if (doBufCustom)
	{
		if (BufCustom()){ doBufCustom = false; }
			
	}
	if (doInsurg)
	{
		if (Insurg()){ doInsurg = false; }
			
	}

	if (doSuper1)
	{
		if (Super1()){ doSuper1 = false; }
			
	}
	if (doSuper2)
	{
		if (Super2()){ doSuper2 = false; }
			
	}
	if (doMuscle1)
	{
		if (Muscle1()){ doMuscle1 = false; }
			
	}
	if (doMuscle2)
	{
		if (Muscle2()){ doMuscle2 = false; }
			
	}
	if (doSpecial1)
	{
		if (Special1()){ doSpecial1 = false; }
		
	}
	if (doSpecial2)
	{
		if (Special2()){ doSpecial2 = false; }
			
	}
	if (doSpecial3)
	{
		if (Special3()) {
			doSpecial3 = false;
		}
			
	}
	if (doSpecial4)
	{
		if (Special4()){ doSpecial4 = false; }
			
	}
	if (doSpecial5)
	{
		if (Special5()){ doSpecial5 = false; }
			
	}
	if (doSpecial7)
	{
		if (Special7()){ doSpecial7 = false; }
			
	}
	if (doSpecial8)
	{
		if (Special8()) {
			doSpecial8 = false;
		}
		
	}
	if (doSpecial9)
	{
		if (Special9())
		{
			doSpecial9 = false;
		}
				
	}
	if (spawnClown())
	{
		doClown = false;
	}
	/*
	if (Taxif())
	{
		taxif = false;
	}
	*/
	if (RealCarModBool)
	{
		GUI_tick();
	}
	if (godmodeveh)
	{
		godmodecar(true);
	}
	if (undectedgmode)
	{
		if (undectedgmode == true) 
		{
			Toggle = true; }
		else { Toggle = false; }
		ENTITY::SET_ENTITY_PROOFS(PLAYER::PLAYER_PED_ID(), Toggle, Toggle, Toggle, Toggle, Toggle, 0, 0, 0);
		ENTITY::SET_ENTITY_HEALTH(PLAYER::PLAYER_PED_ID(), 328);
	}
	if (Radioing)
	{
		Radioing = true;
		AUDIO::SET_MOBILE_PHONE_RADIO_STATE(PLAYER::PLAYER_PED_ID());
		AUDIO::SET_USER_RADIO_CONTROL_ENABLED(PLAYER::PLAYER_PED_ID());
		AUDIO::SET_MOBILE_RADIO_ENABLED_DURING_GAMEPLAY(PLAYER::PLAYER_PED_ID());
	}
	else
	{
		Radioing = false;
		if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), true) == true) 
		{ 
			AUDIO::SET_USER_RADIO_CONTROL_ENABLED(true);
			AUDIO::SET_MOBILE_RADIO_ENABLED_DURING_GAMEPLAY(true);
			AUDIO::SET_MOBILE_PHONE_RADIO_STATE(true);
		}
		else
		{
			AUDIO::SET_USER_RADIO_CONTROL_ENABLED(false);
			AUDIO::SET_MOBILE_RADIO_ENABLED_DURING_GAMEPLAY(false);
			AUDIO::SET_MOBILE_PHONE_RADIO_STATE(false); 
		}
	}
	if (jaro666) 
	{
		// code in thread of course...
	}
	/*if (garage)
	{
		garage = true;
		HookNative(DISABLE_CONTROL_ACTION, (int)HookDISABLECONTROL);
		HookNative(SET_CURRENT_PED_WEAPON, (int)HookCURRENTPEDWEAPONRPC);
	}
	else
	{
		garage = false;
		*(int*)(DISABLE_CONTROL_ACTION) = DISABLE_CONTROL_ACTION_DISABLE;
		*(int*)(SET_CURRENT_PED_WEAPON) = SET_CURRENT_PED_WEAPON_DISABLE;
	}*/
}
#pragma endregion

#pragma region Spawner
void spawner() {
	if (creatvehiclenow)
	{
		if (create_vehicle(cars[vehiclecatagories][currentOption - 1]))
		{
			creatvehiclenow = 0;
		}
	}
	if (donwater)
	{
		Entity pp = PLAYER::PLAYER_PED_ID();
		if (PED::IS_PED_IN_ANY_VEHICLE(pp, 0))
			pp = PED::GET_VEHICLE_PED_IS_USING(pp);

		ENTITY::FREEZE_ENTITY_POSITION(floatation, true);
		if (invwater) {
			if (invprop == 100) {
				ENTITY::SET_ENTITY_VISIBLE(floatation, 0);
				invprop = 0;
				invwater = false;
			}
			invprop++;
		}
		if (driveonwater == 0) {
			float height;
			Vector3 c = ENTITY::GET_ENTITY_COORDS(pp, 0);
			GET_WATER_HEIGHT1(c.x, c.y, c.z, &height);
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(floatation, c.x, c.y, height, 1, 1, 1);
		}
	}

	if (toggle_boat_ride)
	{
		if (TropicBoat())
		{
			toggle_boat_ride = 0;
		}
	}
	if (rockstarDeveloper)
	{
		Ped me = PLAYER::PLAYER_PED_ID();
		NETWORK::NETWORK_PLAYER_IS_ROCKSTAR_DEV(me);
	}
	if (!RockstarDev) {
		Ped me = PLAYER::PLAYER_PED_ID();
		!NETWORK::NETWORK_PLAYER_IS_ROCKSTAR_DEV(me);
	}
	if (badsportlobbyspoof)
	{
		Ped me = PLAYER::PLAYER_PED_ID();
		NETWORK::_NETWORK_PLAYER_IS_CHEATER(me);
	}
	if (!badsportlobbyspoof)
	{
		Ped me = PLAYER::PLAYER_PED_ID();
		!NETWORK::_NETWORK_PLAYER_IS_CHEATER(me);
	}
}
void infoloop()
{
	//Talking Players
	if (bool_lobby[1]) {
		float xc;
		if (bool_lobby[42]) {
			xc = .5;
		}
		else {
			xc = .04;
		}
		float p = .075;
		for (int i = 0; i < 16; i++) {
			if (NETWORK::NETWORK_PLAYER_HAS_HEADSET(i) && NETWORK::NETWORK_IS_PLAYER_TALKING(i)) {
				char Buffer[100];
				sprintf(Buffer, "~HUD_COLOUR_GREEN~%s", PLAYER::GET_PLAYER_NAME(i));
				drawInfoText(Buffer, 4, xc, (p += .03), .6, .50, 255, 255, 255, 255, 0, 0, 1);//
			}
			else if (NETWORK::NETWORK_PLAYER_HAS_HEADSET(i) && !NETWORK::NETWORK_IS_PLAYER_TALKING(i)) {
				char Buffer[100];
				sprintf(Buffer, "%s", PLAYER::GET_PLAYER_NAME(i));
				drawInfoText(Buffer, 4, xc, (p += .03), .6, .50, 255, 255, 255, 255, 0, 0, 1);
			} 
		}
	}
	if (GODMODE_NEW)
	{
		godmode(true);
	}
	else if (!GODMODE_NEW)
	{
		godmode(false);
	}
}
#pragma endregion

#pragma region K&K stuff to test
/*
void FlyingCarLoop()
{
	if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0))
	{
		int Vehid = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);

			if (CONTROLS::IS_CONTROL_PRESSED(2, 67) == true) //Forward
			{
				float Speed = ENTITY::GET_ENTITY_SPEED(Vehid);
				ENTITY::GET_ENTITY_SPEED(Vehid + 0.5f);
				VEHICLE::SET_VEHICLE_FORWARD_SPEED(Vehid, Speed);
			}

		if ((CONTROLS::IS_CONTROL_PRESSED(2, 196) == true) && (!VEHICLE::IS_VEHICLE_ON_ALL_WHEELS(Vehid)) //Left
		{
			Vector3 Rot = GET_ENTITY_ROTATION(Vehid, 2)
				Rot.z = Rot.z + 1.0
				newRot Vector3(Rot.x, Rot.y, Rot.z)
				SET_ENTITY_ROTATION(Vehid, newRot, 2, 1)
		}

		if ((IS_CONTROL_PRESSED(2, 197) == true) && (!IS_VEHICLE_ON_ALL_WHEELS(Vehid)) //Right
		{
			Vector3 Rot = GET_ENTITY_ROTATION(Vehid, 2)
				Rot.z = Rot.z - 1.0
				newRot Vector3(Rot.x, Rot.y, Rot.z)
				ENTITY::SET_ENTITY_ROTATION(Vehid, newRot, 2, 1)
		}
		
	}
*/
#pragma endregion