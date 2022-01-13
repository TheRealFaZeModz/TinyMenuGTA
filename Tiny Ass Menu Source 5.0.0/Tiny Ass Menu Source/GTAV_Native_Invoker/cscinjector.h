
#include <sys/types.h> 
#include <cell/cell_fs.h>
#include <sys/stat.h>
#define VALID_ADDR(x) ((unsigned int)(x) > 0x10000)




bool tryToStartScript = false;
char* g_scriptNameToStart = "";
int g_scriptStackSizeToStart = 0;
//int lastStartedScriptID = 0;
int* lastStartedScriptIDPointer;

void startScriptLoop() {
	if (tryToStartScript) {
		if (SCRIPT::HAS_SCRIPT_LOADED(g_scriptNameToStart)) {
			printf("Starting script!!!!!!!!!!!!!!!\n");
			*lastStartedScriptIDPointer = SYSTEM::START_NEW_SCRIPT(g_scriptNameToStart, g_scriptStackSizeToStart);
			SCRIPT::SET_SCRIPT_AS_NO_LONGER_NEEDED(g_scriptNameToStart);
			tryToStartScript = false;
			printf("Script started!\n");
		}
	}
}

bool isScriptRunning(char* script) {
	if (SCRIPT::_0x029D3841(GAMEPLAY::GET_HASH_KEY(script)) == 0) {
		return false;
	}
	return true;
}

int defaultScriptIdSaveParam = 0;
void ToggleScript(char* script, int stackSize, int* scriptIDSave = &defaultScriptIdSaveParam)
{
	if (SCRIPT::DOES_SCRIPT_EXIST(script))
	{
		if (!isScriptRunning(script))
		{
			printf("Queing script to be started!\n");
			lastStartedScriptIDPointer = scriptIDSave;
			SCRIPT::REQUEST_SCRIPT(script);
			tryToStartScript = true;
			g_scriptNameToStart = script;
			g_scriptStackSizeToStart = stackSize;
		}
		else
		{
			printf("Script being toggled off!\n");
			GAMEPLAY::TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME(script);//get all with the script name
			if (*scriptIDSave != 0) {
				SCRIPT::TERMINATE_THREAD(*scriptIDSave);//for ones with mis matching names
				*scriptIDSave = 0;
			}
		}
	}
	else {
		PRINT("Error with script!");
	}
}










bool readFile(char* file, char buf[], int size, unsigned int offset) {
	int fd;
	int ret;
	uint64_t pos;
	uint64_t nread;
	cellFsChmod(file, 0777/*S_IRWXU|S_IRGRP|S_IXGRP|S_IROTH*/);//set permissions
	ret = cellFsOpen(file, 0, &fd, NULL, 0);
	if (!ret)
	{
		cellFsLseek(fd, offset, CELL_FS_SEEK_SET, &pos);
		ret = cellFsRead(fd, buf, size, &nread);
		if (!ret)
		{
			cellFsClose(fd);
			return true;
		}
	}
	return false;
}

int getFileSize(char* file) {
	int fd;
	int ret;
	int rval = -1;
	uint64_t pos;
	uint64_t nread;
	ret = cellFsOpen(file, 0, &fd, NULL, 0);
	if (!ret) {
		CellFsStat sb;
		ret = cellFsFstat(fd, &sb);
		if (!ret) {
			rval = sb.st_size;
		}
		cellFsClose(fd);
	}
	return rval;
}





int rsc7 = 0;


uint ReadUInt32(char* file, uint pos, bool pointer)
{
	int offset = pos + rsc7;
	char buf[4];
	readFile(file, buf, 4, offset);
	if (pointer && buf[0] == 0x50)
		buf[0] = 0x0;
	return *(uint*)((int)buf);
}


char* ReadBytes(char* file, uint pos, int length) {
	char buffer[0x4000 + 0x1000];//0x4000 is the max read...
	readFile(file, buffer, length, pos + rsc7);
	return buffer;
}


void ReadBytesToMem(char* file, int startReadOffset, int length, int addressInTheirMemory, float* percentPointer = 0) {

	readFile(file, (char*)(addressInTheirMemory + startReadOffset), length, startReadOffset + rsc7);



}

void PS3dotSetMemory(int addressWrite, char* data, int size) {
	//printf("Data writing: 0x%X\n Size: %i\n", data, size);
	//write(addressWrite, data, size);
	memcpy((void*)addressWrite, data, size);

}

unsigned int ReadUInt32Mem(unsigned int address) {
	//return read32(address);
	return *(unsigned int*)address;
}

void SetUInt32Mem(unsigned int address, unsigned int value) {
	//write(address, (char*)&value, sizeof(int));
	*(unsigned int*)address = value;
}

//recreation of 9B45E4 getN4rage10scrProgramE

int getValue(int scriptNameHash) {
	int origHash = scriptNameHash;
	scriptNameHash = scriptNameHash & 0x1F;
	int baseAddressToSearchOn = 0x1E6FB8C/*BLES*/;
	int specialaddr = baseAddressToSearchOn + scriptNameHash + 1;
	int off = specialaddr % 4;
	//printf("Real: 0x%X, off: 0x%X, aligned: 0x%X\n", specialaddr, off, specialaddr - off);

	int foundVal = ReadUInt32Mem(specialaddr - off);

	if (!VALID_ADDR(foundVal)) {
		//printf("error not valid!\n");
		return 0;
	}

	char* arr = (char*)&foundVal;
	char valueRead = arr[off];
	int rageScript = 0;
	while (true) {
		int newaddr = baseAddressToSearchOn + (valueRead << 2);
		//printf("Checking address: 0x%X, off 0x%X\n", newaddr, valueRead);

		rageScript = ReadUInt32Mem(newaddr + 0xA4);//I guess this froze
		if (VALID_ADDR(rageScript)) {

			unsigned int scriptHashRead = ReadUInt32Mem(rageScript + 0x38);
			if (origHash == scriptHashRead) {
				return rageScript;
			}
			else {
				//printf("Hashes not matching: r:0x%X s:0x%X\n", scriptHashRead, origHash);
			}
		}
		else {
			//printf("FATAL ERROR: Unexpected bad value read! *(int*)(0x%X+0xA4) = unexpected 0x%X\n", newaddr, rageScript);
		}
		int r3 = baseAddressToSearchOn + valueRead + 0x21;
		off = r3 % 4;
		int gotten = ReadUInt32Mem(r3 - off);
		char* arr = (char*)&gotten;
		valueRead = arr[off];
		if (valueRead == 0)
			return 0;
	}
	return rageScript;
}



void inject(char* file, bool checkNatives, unsigned int scriptHash) {

	//uint pointer = (uint)getN4rage10scrProgramE(GAMEPLAY::GET_HASH_KEY(overriteScriptName));//NEED TO UPDOOT THIS
	uint pointer = getValue(scriptHash/*0xa57e7489*/);
	if (!VALID_ADDR(pointer)) {

		return;
	}

	unsigned int scriptHashRead = ReadUInt32Mem(pointer + 0x38);
	if (scriptHashRead != scriptHash) {
		//printf("Script hash found is not correct! 0x%X found but want 0x%X\n", scriptHashRead, scriptHash);
		return;
	}



	rsc7 = 0;

	if (ReadUInt32(file, 0, false) == 0x52534337)
		rsc7 = 16;
	uint nativeCount = ReadUInt32(file, 0x20, false);
	uint nativePointer = ReadUInt32(file, 0x2C, true);


	if (ReadUInt32Mem(pointer + 0x20) < nativeCount) {

		return;
	}

	uint memNativePointer = ReadUInt32Mem(pointer + 0x2C);
	uint codeLength = ReadUInt32(file, 0x10, false);
	SetUInt32Mem(pointer + 0x10, codeLength);
	uint stringLength = ReadUInt32(file, 0x48, false);
	SetUInt32Mem(pointer + 0x48, stringLength);
	uint staticCount = ReadUInt32(file, 0x18, false);
	SetUInt32Mem(pointer + 0x18, staticCount);

	int nativesOPDList[0x500];


	for (uint i = 0; i < nativeCount; i++)
		nativesOPDList[i] = getOPDOfNative(ReadUInt32(file, nativePointer + (i * 4), false));

	PS3dotSetMemory(memNativePointer, (char*)nativesOPDList, nativeCount * 4);





	uint codePointerList = ReadUInt32(file, 8, true);

	int memCodePointerList = ReadUInt32Mem(pointer + 8);

	for (uint i = 0; i < (codeLength / 0x4000) + 1; i++)
	{
		uint codePagePointer = ReadUInt32(file, codePointerList + (i * 4), true);
		//printf("n\n");
		int memCodePagePointer = ReadUInt32Mem(memCodePointerList + (i * 4));
		if (!VALID_ADDR(memCodePagePointer)) {
			//printf("ERROR: Code page %i is not valid!\n", i);
			return;
		}
		if (i == codeLength / 0x4000) {
			char* bytes = ReadBytes(file, codePagePointer, (int)codeLength % 0x4000);
			PS3dotSetMemory(memCodePagePointer, bytes, (int)codeLength % 0x4000);
		}
		else {
			char* bytes = ReadBytes(file, codePagePointer, 0x4000);
			PS3dotSetMemory(memCodePagePointer, bytes, 0x4000);
		}
	}


	uint stringPointer = ReadUInt32(file, 0x44, true);
	int memStringPointer = ReadUInt32Mem(pointer + 0x44);
	for (uint i = 0; i < (stringLength / 0x4000) + 1; i++)
	{
		uint stringPagePointer = ReadUInt32(file, stringPointer + (i * 4), true);
		int strPtr = ReadUInt32Mem(memStringPointer + (i * 4));
		if (!VALID_ADDR(strPtr)) {
			//printf("ERROR: String page %i is not valid!\n", i);
		}
		if (i == stringLength / 0x4000) {
			char* bytes = ReadBytes(file, stringPagePointer, (int)stringLength % 0x4000);
			PS3dotSetMemory(strPtr, bytes, (int)stringLength % 0x4000);
		}
		else {
			char* bytes = ReadBytes(file, stringPagePointer, 0x4000);
			PS3dotSetMemory(strPtr, bytes, 0x4000);
		}
	}




	uint staticPointer = ReadUInt32(file, 0x24, true);
	char* bytes64536 = ReadBytes(file, staticPointer, (int)staticCount * 4);
	PS3dotSetMemory(0x10025000, bytes64536, (int)staticCount * 4);

	SetUInt32Mem(pointer + 0x24, 0x10025000);



}


int openFile(char* file) {
	int fd;
	int ret;
	cellFsChmod(file, 0777/*S_IRWXU|S_IRGRP|S_IXGRP|S_IROTH*/);//set permissions
	ret = cellFsOpen(file, 0, &fd, NULL, 0);
	if (!ret)
	{
		return fd;
	}
	return -1;
}
int readFile(int fd, char buf[], int size, unsigned int offset) {
	int ret;
	uint64_t pos;
	uint64_t nread;
	cellFsLseek(fd, offset, CELL_FS_SEEK_SET, &pos);
	ret = cellFsRead(fd, buf, size, &nread);
	if (!ret) {
		return true;
	}
	return false;
}
void closeFile(int fd) {
	cellFsClose(fd);
}
uint readFileArray(int fd, uint index)
{
	int offset = index * 4;
	char buf[4];
	readFile(fd, buf, 4, offset);
	return *(uint*)((int)buf);
}

bool renderPercents = false;
float percentOnFirstPart = 0;
float percentOnSecondPart = 0;
void injectScriptIntoMemory(char* file) {
	percentOnFirstPart = 0;
	percentOnSecondPart = 0;
	renderPercents = true;
	int baseAddress = 0x10025000;

	rsc7 = 0;

	if (ReadUInt32(file, 0, false) == 0x52534337)
		rsc7 = 16;

	uint nativeCount = ReadUInt32(file, 0x20, false);
	uint nativePointer = ReadUInt32(file, 0x2C, true);

	int sizeOfNativesTable = nativeCount * 4;
	int endOfNativesTable = nativePointer + sizeOfNativesTable;

	int filesize = getFileSize(file) - rsc7;
	ReadBytesToMem(file, 0, nativePointer, baseAddress, &percentOnFirstPart);

	ReadBytesToMem(file, endOfNativesTable, filesize - endOfNativesTable, baseAddress + endOfNativesTable, &percentOnSecondPart);//read from after native pointer to end



	int nativesOPDList[0x500];

	for (uint i = 0; i < nativeCount; i++) {
		nativesOPDList[i] = getOPDOfNative(ReadUInt32(file, nativePointer + (i * 4), false));


	}
	PS3dotSetMemory(baseAddress + nativePointer, (char*)nativesOPDList, nativeCount * 4);
	renderPercents = false;
}


bool injectAlreadyInjectedFile(char* file, bool checkNatives, unsigned int scriptHash) {

	int baseAddress = 0x10025000;

	uint pointer = getValue(scriptHash);
	if (!VALID_ADDR(pointer)) {
		return false;
	}

	unsigned int scriptHashRead = ReadUInt32Mem(pointer + 0x38);
	if (scriptHashRead != scriptHash) {
		return false;
	}




	rsc7 = 0;

	if (ReadUInt32(file, 0, false) == 0x52534337)
		rsc7 = 16;

	uint nativeCount = ReadUInt32(file, 0x20, false);
	uint nativePointer = ReadUInt32(file, 0x2C, true);

	if (ReadUInt32Mem(pointer + 0x20) < nativeCount) {
		return false;
	}

	uint memNativePointer = ReadUInt32Mem(pointer + 0x2C);
	uint codeLength = ReadUInt32(file, 0x10, false);
	SetUInt32Mem(pointer + 0x10, codeLength);
	uint stringLength = ReadUInt32(file, 0x48, false);
	SetUInt32Mem(pointer + 0x48, stringLength);
	uint staticCount = ReadUInt32(file, 0x18, false);
	SetUInt32Mem(pointer + 0x18, staticCount);



	SetUInt32Mem(pointer + 0x2C, baseAddress + nativePointer);





	uint codePointerList = ReadUInt32(file, 8, true);

	int memCodePointerList = ReadUInt32Mem(pointer + 8);
	for (uint i = 0; i < (codeLength / 0x4000) + 1; i++)
	{
		uint codePagePointer = ReadUInt32(file, codePointerList + (i * 4), true);

		SetUInt32Mem(memCodePointerList + (i * 4), baseAddress + codePagePointer);


	}


	uint stringPointer = ReadUInt32(file, 0x44, true);
	int memStringPointer = ReadUInt32Mem(pointer + 0x44);
	for (uint i = 0; i < (stringLength / 0x4000) + 1; i++)
	{
		uint stringPagePointer = ReadUInt32(file, stringPointer + (i * 4), true);

		SetUInt32Mem(memStringPointer + (i * 4), baseAddress + stringPagePointer);


	}




	uint staticPointer = ReadUInt32(file, 0x24, true);

	SetUInt32Mem(pointer + 0x24, baseAddress + staticPointer);


	return true;
}





bool loadingScriptLoopThing(char *filenameandpath) // use  static buffer
{
	
	char* scriptName = "fm_deathmatch_creator";
	if (SCRIPT::HAS_SCRIPT_LOADED(scriptName)) {
		return injectAlreadyInjectedFile(filenameandpath/*"/dev_hdd0/tmp/DevScript.csc"*/, true, 0xa57e7489);
		
	}
	else {
		SCRIPT::REQUEST_SCRIPT(scriptName);
		//PRINT("~r~ERROR! DUMMY SCRIPT NOT LOADED PROPERLY! PLEASE TRY AGAIN");
		return false;
	}
}

// EG: readDir("/dev_hdd0/tmp/gopro_2027/XML/spooner",addMapSpoonerCallback);
enum DIRECTORY_ENUM {
	DIRECTORY_INVALID = -1
};
bool readDir(const char *dirName, void(*callback)(char* path, int type)) {
	int count = 0;
	int fd = 0;
	CellFsDirent entry;
	uint64_t read = 0;
	uint64_t err = 0;
	if (err = cellFsOpendir(dirName, &fd) >= 0) {
		while (err = cellFsReaddir(fd, &entry, &read) >= 0) {

			if (entry.d_namlen == 0)
				break;
			if (!(strstr(".", entry.d_name) || strstr("..", entry.d_name))) {
				callback(entry.d_name, entry.d_type);
				count++;
			}
			read++;
		}
		cellFsClosedir(fd);
		return count;
	}
	else {
		printf("Error opening dir! 0x%X\n", err);
		return DIRECTORY_INVALID;
	}
}
int stacksize = 2024;
int lastLoadedScript = 0;
void callback_read_directories_scripts(char *filename, int type) {
	if (type == CELL_FS_TYPE_REGULAR) {
		addOption(filename);
		if (optionPress && optionCount == currentOption) {
			//first stop anyy previous instances of the script
			char* scriptName = "fm_deathmatch_creator";
			GAMEPLAY::TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME(scriptName);//get all with the script name
			if (lastLoadedScript != 0) {
				printf("Terminating old script\n");
				SCRIPT::TERMINATE_THREAD(lastLoadedScript);//for ones with mis matching names
				lastLoadedScript = 0;
			}
			static char buff[256];//static makes it like same as if it was defined outside of the function, so it won't be deleted after the function returns
			snprintf(buff, sizeof(buff), "/dev_hdd0/tmp/TinyMenu/CSC/%s", filename);
			printf("Loading %s\n",buff);
			bool injectedValidd = loadingScriptLoopThing(buff);//ovewrites the memory of the dummy script with out mod menu script

			if (injectedValidd) {
				PRINT("~g~Script Loaded");
				printf("Script loaded successfully!\n");
			} else {
				PRINT("~r~Error count not inject script! Please try again!");
			}

		}
	}
}


int ff;
CellFsErrno status;
CellFsStat *sb;


bool create_script_directory()
{
	if (cellFsStat("/dev_hdd0/tmp/TinyMenu", sb) != CELL_OK)
	{
		return cellFsMkdir("/dev_hdd0/tmp/TinyMenu", S_IRWXO | S_IRWXU | S_IRWXG | S_IFDIR | CELL_FS_S_IFDIR | 0777);
	}
	return false;
}
