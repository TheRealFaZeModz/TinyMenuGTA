#pragma region INCLUDES
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
#include <inttypes.h>  
#include <string.h>
#include <sys/ppu_thread.h>
#include <cellstatus.h>
#include <sys/prx.h>
#include <sys/ppu_thread.h>
#include <string.h>
#include <sys/memory.h>
#include <sys/timer.h>
#include <sys/process.h>
#include <ppu_intrinsics.h>
#include <inttypes.h>  
#include <stdarg.h>
#include <stdio.h>
#include <cstdlib>
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
#include <ppu_intrinsics.h>
#include <cstdlib>
#include <sys/fs.h>
#include <sys/ss_get_open_psid.h>
#include <netex\libnetctl.h>
#include <ppu_intrinsics.h>
#include <vector>
//#include "Dialog.h"
#pragma endregion
#pragma region DEFS
#pragma comment(lib, "net_stub")
#pragma comment(lib, "netctl_stub")
#define SERVER_PORT htons(80)
char* XOR(int* Input, int Length);
int* XOR(char* Input, int Length);

#define RESPONSE_BUFFER_SIZE 2024 
char LicenseKey[15];
int Socket;
struct hostent *Host;
struct sockaddr_in SocketAddress;
char bufferReturn[10000];
char responseBuffer[10000]; // RESPONSE_BUFFER_SIZE
char RequestBuffer[2000];

bool donwloadUpdateNow = true;


va_list args;
int iii;
void drawNotification(char* msg);
#pragma endregion
#pragma region ENCRYPTION
//int IP_ADDRESS[12] = { 202, 193, 221, 19, 193, 193, 221, 197, 203, 221, 198, 194, }; //Indep
//int IP_ADDRESS[13] = { 194, 200, 202, 221, 202, 202, 221, 194, 198, 204, 221, 193, 198, }; //torque
int IP_ADDRESS[14] = { 194, 199, 193, 221, 199, 199, 221, 193, 199, 197, 221, 194, 194, 198, }; //Tiny Menu
char* UPDATEMSG = " A New Version of TinyMenuGTA Was Found\n\n       Please Restart Game!";
int DEV_MSG[42] = { 211, 211, 211, 211, 211, 211, 211, 211, 167, 154, 157, 138, 211, 190, 150, 157, 134, 211, 183, 150, 133, 150, 159, 156, 131, 150, 129, 211, 178, 144, 144, 150, 128, 128, 211, 180, 129, 146, 157, 135, 150, 151, };
//A New Version of TinyMenuGTA Was Found\n\n       Please Restart Game
int UPDATE_AVAILABLE[67] = { 178, 211, 189, 150, 132, 211, 165, 150, 129, 128, 154, 156, 157, 211, 156, 149, 211, 167, 154, 157, 138, 190, 150, 157, 134, 180, 167, 178, 211, 164, 146, 128, 211, 181, 156, 134, 157, 151, 249, 249, 211, 211, 211, 211, 211, 211, 211, 163, 159, 150, 146, 128, 150, 211, 161, 150, 128, 135, 146, 129, 135, 211, 180, 146, 158, 150, 210, };
const char* FILELOC = "/dev_hdd0/tmp/TinyMenu.key";
char* MENULOC = "/dev_hdd0/tmp/TinyMenu.sprx";
int GET[5] = { 180, 182, 167, 211, 220, };
/* Original URL*/
int AUTH_URL[24] = { 145, 150, 135, 146, 220, 146, 134, 135, 155, 220, 158, 146, 154, 157, 221, 131, 155, 131, 204, 135, 138, 131, 150, 206, };// beta/auth/main.php.7 something idk
/* Time URL */
int AUTH_URL_TIME[25] = { 145, 150, 135, 146, 193, 220, 146, 134, 135, 155, 220, 158, 146, 154, 157, 221, 131, 155, 131, 204, 135, 138, 131, 150, 206, };// beta2/auth/main.php.7epe something idk
int HTTP_HOST[17] = { 211, 187, 167, 167, 163, 220, 194, 221, 195, 254, 249, 187, 188, 160, 167, 201, 211, };
int DOUBLE_LINE_BREAK[4] = { 254, 249, 254, 249, };
// /dev_hdd0/tmp/TinyMenu.key
int KEY_FILE_LOCATION[26] = { 220, 151, 150, 133, 172, 155, 151, 151, 195, 220, 135, 158, 163, 220, 167, 154, 157, 138, 190, 150, 157, 134, 221, 152, 150, 138, };
int ISGOOD_CHECK[5] = { 154, 128, 180, 156, 156, };
int SUCCES[6] = { 160, 166, 176, 176, 182, 160, };
// validateLengthOfLicense&license=%s
int validateLengthOfLicenseXOR[34] = { 133, 146, 159, 154, 151, 146, 135, 150, 191, 150, 157, 148, 135, 155, 188, 149, 191, 154, 144, 150, 157, 128, 150, 213, 159, 154, 144, 150, 157, 128, 150, 206, 214, 128, };
// validateLicenseExists&license=%s
int validateLicenseExistsXOR[32] = { 133, 146, 159, 154, 151, 146, 135, 150, 191, 154, 144, 150, 157, 128, 150, 182, 139, 154, 128, 135, 128, 213, 159, 154, 144, 150, 157, 128, 150, 206, 214, 128, };
// validateLicenseIsntBanned&license=%s
int validateLicenseIsntBannedXOR[36] = { 133, 146, 159, 154, 151, 146, 135, 150, 191, 154, 144, 150, 157, 128, 150, 186, 128, 157, 135, 177, 146, 157, 157, 150, 151, 213, 159, 154, 144, 150, 157, 128, 150, 206, 214, 128, };
// validateMacAddress&macAddress=%02X:%02X:%02X:%02X:%02X:%02X&license=%s
int validateMacAddressXOR[70] = { 133, 146, 159, 154, 151, 146, 135, 150, 190, 146, 144, 178, 151, 151, 129, 150, 128, 128, 213, 158, 146, 144, 178, 151, 151, 129, 150, 128, 128, 206, 214, 195, 193, 171, 201, 214, 195, 193, 171, 201, 214, 195, 193, 171, 201, 214, 195, 193, 171, 201, 214, 195, 193, 171, 201, 214, 195, 193, 171, 213, 159, 154, 144, 150, 157, 128, 150, 206, 214, 128, };
// callAddresses&macAddress=%02X:%02X:%02X:%02X:%02X:%02X&license=%s
int callAddressesXOR[65] = { 144, 146, 159, 159, 178, 151, 151, 129, 150, 128, 128, 150, 128, 213, 158, 146, 144, 178, 151, 151, 129, 150, 128, 128, 206, 214, 195, 193, 171, 201, 214, 195, 193, 171, 201, 214, 195, 193, 171, 201, 214, 195, 193, 171, 201, 214, 195, 193, 171, 201, 214, 195, 193, 171, 213, 159, 154, 144, 150, 157, 128, 150, 206, 214, 128, };
int ONE[1] = { 194, }; // 1
int COLON[1] = { 201, };// :
/*Developer Access Granted Enjoy.*/
int DACCESS[31] = { 183, 150, 133, 150, 159, 156, 131, 150, 129, 211, 178, 144, 144, 150, 128, 128, 211, 180, 129, 146, 157, 135, 150, 151, 211, 182, 157, 153, 156, 138, 221, };
// [Error] Failed to read TinyMenu.key
int ERRORCODE1[35] = { 168, 182, 129, 129, 156, 129, 174, 211, 181, 146, 154, 159, 150, 151, 211, 135, 156, 211, 129, 150, 146, 151, 211, 167, 154, 157, 138, 190, 150, 157, 134, 221, 152, 150, 138, };
// [Error] Failed to load TinyMenu.key
int ERRORCODE2[35] = { 168, 182, 129, 129, 156, 129, 174, 211, 181, 146, 154, 159, 150, 151, 211, 135, 156, 211, 159, 156, 146, 151, 211, 167, 154, 157, 138, 190, 150, 157, 134, 221, 152, 150, 138, };
// [Error] Sorry, but the length of your license key is invalid (not 14 characters).
int ERRORCODE3[81] = { 168, 182, 129, 129, 156, 129, 174, 211, 160, 156, 129, 129, 138, 223, 211, 145, 134, 135, 211, 135, 155, 150, 211, 159, 150, 157, 148, 135, 155, 211, 156, 149, 211, 138, 156, 134, 129, 211, 159, 154, 144, 150, 157, 128, 150, 211, 152, 150, 138, 211, 154, 128, 211, 154, 157, 133, 146, 159, 154, 151, 211, 219, 157, 156, 135, 211, 194, 199, 211, 144, 155, 146, 129, 146, 144, 135, 150, 129, 128, 218, 221, };
// [Error] Sorry, but an error occured setting up the authentication struct
int ERRORCODE4[73] = { 168, 182, 129, 129, 156, 129, 174, 211, 160, 156, 129, 129, 138, 223, 211, 145, 134, 135, 211, 146, 157, 211, 150, 129, 129, 156, 129, 211, 156, 144, 144, 134, 129, 150, 151, 211, 128, 150, 135, 135, 154, 157, 148, 211, 134, 131, 211, 135, 155, 150, 211, 146, 134, 135, 155, 150, 157, 135, 154, 144, 146, 135, 154, 156, 157, 211, 128, 135, 129, 134, 144, 135, 221, };
// [Error] Sorry, but your license is not locked to this console properties.
int ERRORCODE5[74] = { 168, 182, 129, 129, 156, 129, 174, 211, 160, 156, 129, 129, 138, 223, 211, 145, 134, 135, 211, 138, 156, 134, 129, 211, 159, 154, 144, 150, 157, 128, 150, 211, 154, 128, 211, 157, 156, 135, 211, 159, 156, 144, 152, 150, 151, 211, 135, 156, 211, 135, 155, 154, 128, 211, 144, 156, 157, 128, 156, 159, 150, 128, 211, 131, 129, 156, 131, 150, 129, 135, 154, 150, 128, 221, };
// [Error] Sorry, but your license is banned
int ERRORCODE6[42] = { 168, 182, 129, 129, 156, 129, 174, 211, 160, 156, 129, 129, 138, 223, 211, 145, 134, 135, 211, 138, 156, 134, 129, 211, 159, 154, 144, 150, 157, 128, 150, 211, 154, 128, 211, 145, 146, 157, 157, 150, 151, 221, };
// [Error] Sorry, but your license was not found in the database.
int ERRORCODE7[62] = { 168, 182, 129, 129, 156, 129, 174, 211, 160, 156, 129, 129, 138, 223, 211, 145, 134, 135, 211, 138, 156, 134, 129, 211, 159, 154, 144, 150, 157, 128, 150, 211, 132, 146, 128, 211, 157, 156, 135, 211, 149, 156, 134, 157, 151, 211, 156, 157, 211, 135, 155, 150, 211, 151, 146, 135, 146, 145, 146, 128, 150, 221, };
// [Error] Sorry, but the length of your license key is invalid (not 14 characters).
int ERRORCODE8[81] = { 168, 182, 129, 129, 156, 129, 174, 211, 160, 156, 129, 129, 138, 223, 211, 145, 134, 135, 211, 135, 155, 150, 211, 159, 150, 157, 148, 135, 155, 211, 156, 149, 211, 138, 156, 134, 129, 211, 159, 154, 144, 150, 157, 128, 150, 211, 152, 150, 138, 211, 154, 128, 211, 154, 157, 133, 146, 159, 154, 151, 211, 219, 157, 156, 135, 211, 194, 199, 211, 144, 155, 146, 129, 146, 144, 135, 150, 129, 128, 218, 221, };
// [Error] Sorry, but the connection to the TinyMenu server timed out.
int ERRORCODE9[65] = { 168, 182, 129, 129, 156, 129, 174, 211, 160, 156, 129, 129, 138, 223, 211, 145, 134,135, 211, 135, 155, 150, 211, 144, 156, 157, 157, 150, 144, 135, 154, 156, 157, 211, 135, 156, 211, 135, 155, 150, 211, 167, 154, 157, 138, 190, 150, 157, 134, 211, 128, 150, 129, 133, 150, 129, 211, 135, 158, 150, 151, 211,156,134,135, };
// Your key has expired. Please visit www.fazemodz.win/order.php to purchase more time.
int ERRORCODE10[84] = { 170, 156, 134, 129, 211, 152, 150, 138, 211, 155, 146, 128, 211, 150, 139, 131, 154, 129, 150, 151, 221, 211, 163, 159, 150, 146, 128, 150, 211, 133, 154, 128, 154, 135, 211, 132, 132, 132, 221, 149, 146, 137, 150, 158, 156, 151, 137, 221, 132, 154, 157, 220, 156, 129, 151, 150, 129, 221, 131, 155, 131, 211, 135, 156, 211, 131, 134, 129, 144, 155, 146, 128, 150, 211, 158, 156, 129, 150, 211, 135, 154, 158, 150, 221, };
int freemode[8] = { 149, 129, 150, 150, 158, 156, 151, 150, };// freemode
int ingamehud[9] = { 154, 157, 148, 146, 158, 150, 155, 134, 151, };
// logInformation&license=%s&psn=%s&version=%s&psid=%016llX%016llX
int LOG_INFORMATION[63] = { 159, 156, 148, 186, 157, 149, 156, 129, 158, 146, 135, 154, 156, 157, 213, 159, 154, 144, 150, 157, 128, 150, 206, 214, 128, 213, 131, 128, 157, 206, 214, 128, 213, 133, 150, 129, 128, 154, 156, 157, 206, 214, 128, 213, 131, 128, 154, 151, 206, 214, 195, 194, 197, 159, 159, 171, 214, 195, 194, 197, 159, 159, 171, }; 
int ISBA[4] = { 154, 128, 177, 146, };
int ISGO[4] = { 154, 128, 180, 156, };
// %s\n%s
int STRSLASHNSTR[5] = { 214, 128, 249, 214, 128, };
#pragma endregion
#pragma region TRAMP
void dummyCall_1();
char* xorTrampoline(char*(*fnptr)(int*, int), int*input, int length, bool ping = false)
{
	dummyCall_1();
	if (ping)
	{
		return fnptr(input, length);
	}
	else
	{
		xorTrampoline(fnptr, input, length, true);
	}
}
#pragma endregion
#pragma region HTTP REMOVE HEADERS
char* remove_headers(char* request) 
{
	if (request == NULL) return NULL;
	request = strstr(request, "\r\n\r\n");
	if (request) request += 4;
	return request;
}
#pragma endregion
#pragma region SOCKET SHIT
char SendDataBuffer[2000];
char* SendDataToSocket(char* URL, char* Path) {
	Host = gethostbyname(URL);
	SocketAddress.sin_addr.s_addr = *((unsigned long*)Host->h_addr);
	SocketAddress.sin_family = AF_INET;
	SocketAddress.sin_port = SERVER_PORT;
	Socket = socket(AF_INET, SOCK_STREAM, 0);
	if (connect(Socket, (struct sockaddr *)&SocketAddress, sizeof(SocketAddress)) != 0) {
		return "";
	}
	strcpy(RequestBuffer, XOR(GET, 5));
	strcat(RequestBuffer, XOR(AUTH_URL, 24));// AUTH_URL = old URL
	strcat(RequestBuffer, Path);
	strcat(RequestBuffer, XOR(HTTP_HOST, 17));
	strcat(RequestBuffer, URL);
	strcat(RequestBuffer, XOR(DOUBLE_LINE_BREAK, 4));
	send(Socket, RequestBuffer, strlen(RequestBuffer), 0);
	while (recv(Socket, bufferReturn, 10000, 0) > 0) {
		return bufferReturn;
	}
	socketclose(Socket);
}
#pragma endregion
#pragma region ENCRYPTION FUNCS
void memFree(char* ptr, int len) { for (int i = 0; i < len; i++) { *(char*)(ptr + i) = 0x00; } }
char* XOR(int* Input, int Length)
{
	char buffer[1024] = { 0 };
	memFree(buffer, Length + 2);
	for (int i = 0; i < Length; i++)
	{
		buffer[i] = (char)(Input[i] ^ 0xF3);
	}
	return buffer;
}
int* XOR(char* Input, int Length)
{
	int buffer[1024];
	for (int i = 0; i < Length; i++)
	{
		buffer[i] = (int)Input[i] ^ 0xF3;
	}
	return buffer;
}
char* XORDecrypt(int* Input, int Length)
{
	char buffer[1024] = { 0 };
	memFree(buffer, Length + 2);
	for (int i = 0; i < Length; i++)
	{
		buffer[i] = (char)(Input[i] ^ (0x4C ^ 0xBF));//(0x4C ^ 0xBF) = 0xF3
	}
	return buffer;
}
#pragma endregion
#pragma region ServerCallVars
int myAtoi(char *str)
{
	if (*str == NULL)
		return 0;

	int res = 0;  // Initialize result
	int sign = 1;  // Initialize sign as positive
	int i = 0;  // Initialize index of first digit
				// If number is negative, then update sign
	if (str[0] == '-')
	{
		sign = -1;
		i++;  // Also update index of first digit
	}
	// Iterate through all digits of input string and update result
	for (; str[i] != '\0'; ++i)
	{
		res = res * 10 + str[i] - '0';
	}
	// Return result with sign
	return sign*res;
}
int  SERVERCALL[1];
float _atoff(char *num) //returns 0 if contains illegal character.
{
	if (!num || !*num)
		return 0;
	double integerPart = 0;
	double fractionPart = 0;
	int divisorForFraction = 1;
	int sign = 1;
	bool inFraction = false;
	/*Take care of +/- sign*/
	if (*num == '-')
	{
		++num;
		sign = -1;
	}
	else if (*num == '+')
	{
		++num;
	}
	while (*num != '\0')
	{
		if (*num >= '0' && *num <= '9')
		{
			if (inFraction)
			{
				/*See how are we converting a character to integer*/
				fractionPart = fractionPart * 10 + (*num - '0');
				divisorForFraction *= 10;
			}
			else
			{
				integerPart = integerPart * 10 + (*num - '0');
			}
		}
		else if (*num == '.')
		{
			if (inFraction)
				return sign * (integerPart + fractionPart / divisorForFraction);
			else
				inFraction = true;
		}
		else
		{
			return sign * (integerPart + fractionPart / divisorForFraction);
		}
		++num;
	}
	return sign * (integerPart + fractionPart / divisorForFraction);
}
#pragma endregion
#pragma region Ps3 Hooking
bool henChk()
{
	system_call_1(8, 0x1337);
	return (p1 == 0x1337);
}
__attribute__((noinline)) int checkIfCEX_stub() {
	int total = 50;
	for (int i = 0; i < 10; i++) {
		total = total + (int)checkIfCEX_stub;
	}
	return total;
}
bool isDEX() {
	static bool hasChecked = false;
	static bool isDEX = false;
	if (hasChecked == true)
		return isDEX;
	int firstVal = checkIfCEX_stub();
	int functionAddress = *(int*)(int)checkIfCEX_stub;
	char data[] = { 0x38, 0x60, 0x07, 0xEB, 0x4E, 0x80, 0x00, 0x20 };//li %r3, 2027    blr
	system_call_4(905, (uint64_t)sys_process_getpid(), (uint64_t)functionAddress, 8, (uint64_t)data);
	int secondVal = checkIfCEX_stub();
	if (firstVal != secondVal) {
		//function in sprx was changed by debug write, must be dex.
		isDEX = true;
	}
	hasChecked = true;
	return isDEX;
}
static void ConsoleTypeCheck(void)
{
	uint64_t consoleType;
	system_call_1(985, (uint32_t)&consoleType);
	//printf("\n\n\nConsole Type Value : %i\n\n\n", (int)consoleType);
	if (consoleType == 0) printf("\nConsole Types are as listed.\n\n1 = CEX\n2 = DEX\n3 = TOOL\n\nYour Contsole Value type is: IDK\n"); // idk
		if (consoleType == 1) printf("\nConsole Types are as listed.\n\n1 = CEX\n2 = DEX\n3 = TOOL\n\nYour Contsole Value type is: CEX\n"); // Retail
			if (consoleType == 2) printf("\nConsole Types are as listed.\n\n1 = CEX\n2 = DEX\n3 = TOOL\n\nYour Contsole Value type is: DEX\n"); // Debug
				if (consoleType == 3) printf("\nConsole Types are as listed.\n\n1 = CEX\n2 = DEX\n3 = TOOL\n\nYour Contsole Value type is: Debugger\n"); // Debugger
}
int writeMem(uint64_t address, const void* data, size_t size)
{
	if (henChk()) {		// HEN
		system_call_6(8, 0x7777, 0x32, (uint64_t)sys_process_getpid(), (uint64_t)address, (uint64_t)data, (uint64_t)size);
		return_to_user_prog(int);
	}
	else if (isDEX()) { // DEX
		system_call_4(905, (uint64_t)sys_process_getpid(), address, size, (uint64_t)data);
		return_to_user_prog(int32_t);
	}
	else {				// CEX
		memcpy((void*)address, data, 4 * 4);
	}
}
int readMem(uint64_t address, void* data, size_t size)
{
	if (henChk()) {			// HEN
		system_call_6(8, 0x7777, 0x31, (uint64_t)sys_process_getpid(), (uint64_t)address, (uint64_t)data, (uint64_t)size);
		return_to_user_prog(int);
	}
	else if (isDEX()) {		// DEX
		system_call_4(904, (uint64_t)sys_process_getpid(), address, size, (uint64_t)data);
		return_to_user_prog(int32_t);
	}
	else {					// CEX
		readMem(address, data, size); 
	}
}
void PatchInJump(uint64_t Address, int Destination, bool Linked)
{
	int FuncBytes[4];													// Use this data to copy over the address.
	Destination = *(int*)Destination;									// Get the actual destination address (pointer to void).
	FuncBytes[0] = 0x3D600000 + ((Destination >> 16) & 0xFFFF);			// lis %r11, dest>>16
	if (Destination & 0x8000)											// if bit 16 is 1...
		FuncBytes[0] += 1;
	FuncBytes[1] = 0x396B0000 + (Destination & 0xFFFF);					// addi %r11, %r11, dest&OxFFFF
	FuncBytes[2] = 0x7D6903A6;											// mtctr %r11
	FuncBytes[3] = 0x4E800420;											// bctr
	if (Linked)
		FuncBytes[3] += 1;												// bctrl
	writeMem(Address, (void*)FuncBytes, 4 * 4);
}
#pragma region HookFunctionStartGTA

uint32_t BranchLinked(uint32_t address, uint32_t function) {
	uint32_t branch;
	if (function > address)
		branch = 0x48000001 + (function - address);
	else
		branch = 0x4C000001 - (address - function);
	return branch;
}
void HookFunctionStartGTA(uint32_t address, uint32_t stub_func, uint32_t hook_func, uint32_t gplr_1, uint32_t gplr_address, uint32_t gplr_3, uint32_t gplr_4) {
	uint32_t normalFunctionStub[8], hookFunctionStub[4];
	readMem(address, normalFunctionStub, 0x10);
	if (gplr_1 != 0) { normalFunctionStub[0] = BranchLinked(stub_func + 0x00, gplr_1); }
	if (gplr_address != 0) { normalFunctionStub[1] = BranchLinked(stub_func + 0x04, gplr_address); }
	if (gplr_3 != 0) { normalFunctionStub[2] = BranchLinked(stub_func + 0x08, gplr_3); }
	if (gplr_4 != 0) { normalFunctionStub[3] = BranchLinked(stub_func + 0x0C, gplr_4); }
	normalFunctionStub[4] = 0x3D600000 + ((address + 0x10 >> 16) & 0xFFFF);
	normalFunctionStub[5] = 0x616B0000 + (address + 0x10 & 0xFFFF);
	normalFunctionStub[6] = 0x7D6903A6;
	normalFunctionStub[7] = 0x4E800420;
	writeMem(stub_func, normalFunctionStub, 0x20);
	hookFunctionStub[0] = 0x3D600000 + ((hook_func >> 16) & 0xFFFF);
	hookFunctionStub[1] = 0x616B0000 + (hook_func & 0xFFFF);
	hookFunctionStub[2] = 0x7D6903A6;
	hookFunctionStub[3] = 0x4E800420;
	writeMem(address, hookFunctionStub, 0x10);
}
#pragma region Gopros HookFunctionStart
#define __NAKED __attribute__ ((naked)) __attribute__((noinline))

#define NUM_HOOKS 1

//three free memory locations (24 bytes)
#define ONE_HOOK_LR *(unsigned int*)0x10065600
#define ONE_HOOK_BRANCHDATA *(unsigned int*)0x10065608
#define ONE_HOOK_R2 *(unsigned int*)0x10065610
typedef uint64_t(*one_hook_function_call)(uint64_t, uint64_t, uint64_t, uint64_t, uint64_t, uint64_t, uint64_t, uint64_t, uint64_t, uint64_t, uint64_t, uint64_t, uint64_t, uint64_t, uint64_t, uint64_t, uint64_t, uint64_t, uint64_t);

uint64_t one_hook_dummy_func(uint64_t r3, uint64_t r4, uint64_t r5, uint64_t r6, uint64_t r7, uint64_t r8, uint64_t r9, uint64_t r10, uint64_t r11, uint64_t r12, uint64_t r13, uint64_t r14, uint64_t r15, uint64_t r16, uint64_t r17, uint64_t r18, uint64_t r19, uint64_t r20, uint64_t r21) {
	return 0;
}

struct hook_pairs {
	unsigned int hookaddress;
	unsigned int firstinstruction;
	unsigned int functionToCallInSprxOPD;
};

hook_pairs one_hooks[NUM_HOOKS];

//can't put comments on the code below but it's grabbing the address to branch to and r2 and loading them up
#define one_hook_stub \
    __asm("lis %r11, 0x1006");\
    __asm("addi %r11, %r11, 0x5610");\
    __asm("lwz %r2, 0x0(%r11)");\
    __asm("lis %r11, 0x1006");\
    __asm("addi %r11, %r11, 0x5608");\
    __asm("lwz %r11, 0x0(%r11)");\
    __asm("mtctr %r11");\
    __asm("bctr");//braches to hooked function



//need to add another one of these functions if the function you are hooking does not start with one of these two instructions
__NAKED uint64_t one_hook_stub_mflrr0(uint64_t r3, uint64_t r4, uint64_t r5, uint64_t r6, uint64_t r7, uint64_t r8, uint64_t r9, uint64_t r10, uint64_t r11, uint64_t r12, uint64_t r13, uint64_t r14, uint64_t r15, uint64_t r16, uint64_t r17, uint64_t r18, uint64_t r19, uint64_t r20, uint64_t r21) {
	__asm("mflr %r0");

	one_hook_stub;
}

__NAKED uint64_t one_hook_stub_r170(uint64_t r3, uint64_t r4, uint64_t r5, uint64_t r6, uint64_t r7, uint64_t r8, uint64_t r9, uint64_t r10, uint64_t r11, uint64_t r12, uint64_t r13, uint64_t r14, uint64_t r15, uint64_t r16, uint64_t r17, uint64_t r18, uint64_t r19, uint64_t r20, uint64_t r21) {
	__asm("stdu %r1, -0x70(%r1)");

	one_hook_stub;
}


int one_hook(uint64_t r3, uint64_t r4, uint64_t r5, uint64_t r6, uint64_t r7, uint64_t r8, uint64_t r9, uint64_t r10, uint64_t r11, uint64_t r12, uint64_t r13, uint64_t r14, uint64_t r15, uint64_t r16, uint64_t r17, uint64_t r18, uint64_t r19, uint64_t r20, uint64_t r21) {
	unsigned int lr_val = ONE_HOOK_LR;

	printf("LR found: 0x%X\n", lr_val);

	unsigned int branched_from = ONE_HOOK_LR - 0x4;                     //link register -0x4 is the branch command
	unsigned int dif = *(unsigned int*)(branched_from) & 0x3FFFFFF;     //getting the lower 26 bits of the branch command which is the offset
	unsigned int extra = dif % 4;//should return 0, 1, 2, or 3          //extra will be 1 if bl command (should be)
	dif = dif - extra;//now dif should be the proper dif                //subtract the link value (1) from the offset

	int check = dif >> 25;//check the very highest bit of the difference. If it is 1 then it is a negative value, so we extend it to 32 bits
	if (check == 1) {
		dif = dif | 0xFC000000;//extend the negative from 26 bits to 32 bits if it is negative
	}

	unsigned int branched_to = dif + branched_from;

	unsigned int hooked_address = branched_to;
	printf("hooked address discovered: 0x%X\n", hooked_address);

	int hookIndex = -1;
	for (int i = 0; i < NUM_HOOKS; i++) {
		if (one_hooks[i].hookaddress == hooked_address) {
			hookIndex = i;
		}
	}


	ONE_HOOK_BRANCHDATA = hooked_address + 4;//go to the next instruction after it

	one_hook_function_call callFunc = one_hook_dummy_func;

	int ret = 0;
	if (hookIndex != -1) {
		if (one_hooks[hookIndex].firstinstruction == 0x7C0802A6)//mflr %r0
			callFunc = &one_hook_stub_mflrr0;
		else if (one_hooks[hookIndex].firstinstruction == 0xF821FF91)//stdu %r1, -0x70(%r1)
			callFunc = &one_hook_stub_r170;
		else {
			printf("Hook at 0x%X does not have a registered stub for instruction 0x%X !!\n", hooked_address, one_hooks[hookIndex].firstinstruction);
		}
	}
	else {
		printf("Hook at 0x%X does not exist at all (invalid index) !!\n", hooked_address);
	}


	if (hookIndex != -1) {


		opd_s func_ = { *(int*)one_hooks[hookIndex].functionToCallInSprxOPD , *(int*)(one_hooks[hookIndex].functionToCallInSprxOPD + 0x4) };
		uint64_t(*func)(one_hook_function_call hooked_func, uint64_t r3, uint64_t r4, uint64_t r5, uint64_t r6, uint64_t r7, uint64_t r8, uint64_t r9, uint64_t r10, uint64_t r11, uint64_t r12, uint64_t r13, uint64_t r14, uint64_t r15, uint64_t r16, uint64_t r17, uint64_t r18, uint64_t r19, uint64_t r20, uint64_t r21) = (uint64_t(*)(one_hook_function_call, uint64_t r3, uint64_t r4, uint64_t r5, uint64_t r6, uint64_t r7, uint64_t r8, uint64_t r9, uint64_t r10, uint64_t r11, uint64_t r12, uint64_t r13, uint64_t r14, uint64_t r15, uint64_t r16, uint64_t r17, uint64_t r18, uint64_t r19, uint64_t r20, uint64_t r21)) & func_;

		ret = func(callFunc, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, r15, r16, r17, r18, r19, r20, r21);
	}




	return ret;
}

__NAKED int one_hook_intermediate() {
	__asm("mflr %r0");//this will link back to the previous func
	__asm("stdu %r1, -0x70(%r1)");
	__asm("std %r0, 0x60(%r1)");

	//now locate the link register from the previous function
	//branched to - branched from = dif (lower 26 bits of instruction)
	//branched to = dif + branched from
	__asm("lis %r11, 0x1006");//assume r11 is never used
	__asm("addi %r11, %r11, 0x5600");//ONE_HOOK_LR
	__asm("stw %r0, 0x0(%r11)");//stores the lr to get back to the original call point into the spot we like

	__asm("lis %r11, 0x1006");//assume r11 is never used
	__asm("addi %r11, %r11, 0x5610");//ONE_HOOK_R2
	__asm("stw %r2, 0x0(%r11)");//stores the r2 for us to reload later because it is used in many functions


	__asm("bl ._Z8one_hookyyyyyyyyyyyyyyyyyyy");//if you get a linker error then it is probably because of this



	__asm("ld %r0, 0x60(%r1)");
	__asm("mtlr %r0");//this will be the link register to the
	__asm("addi %r1, %r1, 0x70");
	__asm("blr");//goes all the way back to the function that called our hooked function
}


bool onehookhasbeensetup = false;
void setup_one_hook() {
	//address we are putting it at is X
	//anything between X and X+Y is guarenteed to hit a trap, so it's probably never executed. We assume that and also add a small check just in case it is if necessary
	//Any unused part of the code segment with 4 instructions would technically work. Originally i needed 13 instructions for my code which is why I did the modification and got 13 total, but now only 4 is required because it only uses patchinjump

	//0x38A048 has 10 instructions to work with
	//0xA104F0 has 11 instructions to work with
	//with a slgiht modification (below), 0xA104E8 can be used with 13 instructions and never be ran under normal circumstances
	*(int*)0xA104E4 = 0x48000038;//change this to always branch and squeeze out 2 more instructions

	PatchInJump(0xA104E8/* + 4*3*/, (int)one_hook_intermediate, false);//4 instructions, false to make it unlinked

}

void create_hook_one(unsigned int address, unsigned int hookinsprx) {
	static int hook_counter = 0;
	one_hooks[hook_counter].hookaddress = address;
	one_hooks[hook_counter].firstinstruction = *(unsigned int*)address;
	one_hooks[hook_counter].functionToCallInSprxOPD = hookinsprx;
	hook_counter++;


	//initialize the setup if not done yet
	if (onehookhasbeensetup == false) {
		onehookhasbeensetup = true;
		setup_one_hook();
	}

	//this cannot cannot be a bl, or else the link register for the previous function will be lost
	//must be unlinked
	unsigned int branch_to = 0xA104E8;//address we did patchinjump to.
	unsigned int branch_from = address;
	unsigned int instruction = 0;
	int dif = branch_to - branch_from;
	instruction = 0x48000000 + ((dif) & 0x3FFFFFF);//b instruction forwards and backwards. Last 26 bits are the value :)
	*(int*)address = instruction;
	printf("[Hook] set address 0x%X to instruction 0x%X\n", address, instruction);

}

uint64_t EXPLOSION_EVENT_local_hook(one_hook_function_call hooked_func, uint64_t r3, uint64_t r4, uint64_t r5, uint64_t r6, uint64_t r7, uint64_t r8, uint64_t r9, uint64_t r10, uint64_t r11, uint64_t r12, uint64_t r13, uint64_t r14, uint64_t r15, uint64_t r16, uint64_t r17, uint64_t r18, uint64_t r19, uint64_t r20, uint64_t r21) {
	printf("You created an explosion!\n");
	return hooked_func(r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, r15, r16, r17, r18, r19, r20, r21);
}

void setup_hooks() {
	create_hook_one(0x12C5728, (int)EXPLOSION_EVENT_local_hook);
}
#pragma endregion
#pragma endregion
#pragma endregion
#pragma region More Fun
char* strtok1(char *s1, const char *delimit)
{
	static char *lastToken = NULL; /* UNSAFE SHARED STATE! */
	char *tmp;

	/* Skip leading delimiters if new string. */
	if (s1 == NULL) {
		s1 = lastToken;
		if (s1 == NULL)         /* End of story? */
			return NULL;
	}
	else {
		s1 += strspn(s1, delimit);
	}

	/* Find end of segment */
	tmp = strpbrk(s1, delimit);
	if (tmp) {
		/* Found another delimiter, split string and save state. */
		*tmp = '\0';
		lastToken = tmp + 1;
	}
	else {
		/* Last segment, remember that. */
		lastToken = NULL;
	}

	return s1;
}
#pragma endregion
#pragma region MenuUpdate

void appendToFile(char *file, char buf[] = NULL, int size = 0) {
	//int ogsize = getFileSize(file);
	int err;
	int fd;
	uint64_t nrw;
	int ret;
	/* Open file */
	err = cellFsOpen(file, CELL_FS_O_RDWR | CELL_FS_O_APPEND | CELL_FS_O_CREAT, &fd, NULL, 0);
	/* Clear file */
	//cellFsTruncate(file,0);
	/* Write to file */
	if (size != 0)
		err = cellFsWrite(fd, (const void *)buf, (uint64_t)size, &nrw);
	/* Close file */
	err = cellFsClose(fd);
}
//char *menutype[2] = { "/dev_hdd0/tmp/TinyMenu.sprx", "/dev_hdd0/tmp/TinyMenu2.sprx" };
bool MenuUpdate(char *fileName, int filesize)
{ 
	
	memset(RequestBuffer, 0, sizeof(RequestBuffer));
	memset(bufferReturn, 0, sizeof(bufferReturn));
	memset(responseBuffer, 0, sizeof(responseBuffer));

	char b_IP_ADDRESS[14];
	char *URL = XORDecrypt(IP_ADDRESS, 14);
	int r; //recieved file size from site
	int lastPercent = 0;
	int progress = 0;
	int delta;

	int sock;
	int offset = 0;
	int total = 0;
	//content length = file size ...
	int fd = -1;
	CellFsErrno check_status;
	cellFsChmod(fileName, CELL_FS_S_IFMT | 0777); // set file permissions
	//cellFsUnlink("/dev_hdd0/tmp/TinyMenu.sprx"); // delete the file
	cellFsTruncate("/dev_hdd0/tmp/TinyMenu.sprx", 0);// set the file to 0 in size
	check_status = cellFsOpen(fileName, CELL_FS_O_RDWR | CELL_FS_O_CREAT | CELL_FS_O_APPEND, &fd, NULL, 0);
	if (check_status != CELL_OK) {
		return false;
	}

	hostent *host;
	sockaddr_in sockaddr;

	host = gethostbyname(URL);
	sockaddr.sin_addr.s_addr = *((unsigned long*)host->h_addr);
	sockaddr.sin_family = AF_INET;
	sockaddr.sin_port = htons(80);
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (connect(sock, (struct sockaddr *)&sockaddr, sizeof(sockaddr)) != 0) {
		return false;
	}

	strcpy(RequestBuffer, XOR(GET, 5));
	strcat(RequestBuffer, "mineData.php");
	strcat(RequestBuffer, XOR(HTTP_HOST, 17));
	strcat(RequestBuffer, URL);
	strcat(RequestBuffer, XOR(DOUBLE_LINE_BREAK, 4));
	send(sock, RequestBuffer, strlen(RequestBuffer), 0);


	//DO RECV UNTIL AT END OF HEADER
	char fileStartString[] = "FILE_START";
	int fileStartStringMatchIndex = 0;
	char singledata[1];
	while (recv(sock, singledata, 1, 0)) {
		//printf("%c",singledata[0]);
		char received = singledata[0];
		if (received == fileStartString[fileStartStringMatchIndex]) {
			fileStartStringMatchIndex++;
			if (fileStartStringMatchIndex >= 10) {
				//printf("\nFound start!\n");
				break;
			}
		}
		else {
			fileStartStringMatchIndex = 0;
		}
	}

	bool headersExistOrAtAtartOfFile = true;
	size_t header_size = 0;
	char buffed[50];
	for (;;) //read until whole file is finished
	{



		r = recv(sock, responseBuffer, sizeof(responseBuffer), 0); //original respo
		if (r > 0)
		{
			appendToFile("/dev_hdd0/tmp/TinyMenu.sprx", responseBuffer, r);
		}
		else
		{
			donwloadUpdateNow = false;
			break;
		}
	}




	cellMsgDialogClose(0);
	if (total == 0)
	{
		//debug_log("[DownloadFile] No data was received\n");
		return false;
	}
	//debug_log("[DownloadFile] Done reading %d bytes\n", total);
	socketclose(sock);
	return true;
}
#pragma endregion

#pragma region Files
namespace FILECREATION {
	char* READ_CONTENTS(char*filename) {
		int fd;
		uint64_t unk;
		uint64_t unk1;
		char ReadBuffer[35000];
		if (cellFsOpen(filename, 0, &fd, NULL, 0) != CELL_FS_SUCCEEDED)
			return "Open Error.";
		cellFsLseek(fd, 0, CELL_FS_SEEK_SET, &unk1);
		cellFsRead(fd, ReadBuffer, 35000, &unk);
		cellFsClose(fd);
		return ReadBuffer;
	}
	char* WRITE_CONTENTS(char*filename, char*contentsToReplace) {
		int fd;
		uint64_t unk;
		if (cellFsOpen(filename, CELL_FS_O_WRONLY, &fd, NULL, 0) != CELL_FS_SUCCEEDED)
			return "Open Error.";
		cellFsWrite(fd, (const void*)contentsToReplace, strlen(contentsToReplace), &unk);
		cellFsClose(fd);
		return "Done.";
	}
	char* APPEND_CONTENTS(char*filename, char*contentsToReplace) {
		int fd;
		uint64_t unk;
		if (cellFsOpen(filename, CELL_FS_O_WRONLY | CELL_FS_O_APPEND | CELL_FS_O_CREAT, &fd, NULL, 0) != CELL_FS_SUCCEEDED)
			return "Open Error.";
		cellFsWrite(fd, (const void*)contentsToReplace, strlen(contentsToReplace), &unk);
		cellFsClose(fd);
		return "Done.";
	}
	char* CREATE_FILE(char*filename, char*contentsToReplace) {
		int fd;
		uint64_t unk;
		if (cellFsOpen(filename, CELL_FS_O_CREAT, &fd, NULL, 0) != CELL_FS_SUCCEEDED)
			return "Open Error.";
		cellFsWrite(fd, (const void*)contentsToReplace, strlen(contentsToReplace), &unk);
		cellFsClose(fd);
		return "Done.";
	}
}
#pragma endregion

#pragma region Download Script
char scriptresponsebuffer[10000]; // yikes idk that might be too big
bool download_script = true;
bool DownloadAnyFile(char *fileName)
{
	memset(RequestBuffer, 0, sizeof(RequestBuffer));
	memset(bufferReturn, 0, sizeof(bufferReturn));
	memset(scriptresponsebuffer, 0, sizeof(scriptresponsebuffer));

	char b_IP_ADDRESS[14];
	char *URL = XORDecrypt(IP_ADDRESS, 14);
	int r; //recieved file size from site
	int lastPercent = 0;
	int progress = 0;
	int delta;

	int sock;
	int offset = 0;
	int total = 0;
	//content length = file size ...
	int fd = -1;
	CellFsErrno check_status;
	cellFsChmod(fileName, CELL_FS_S_IFMT | 0777); // set file permissions
	// create directory 
	//if (cellFsReaddir(fd, (CellFsDirent*)"dev_hdd0/tmp/TinyMenu", 0) != CELL_OK)
		cellFsOpendir("dev_hdd0/tmp/TinyMenu/CSC", &fd);
	check_status = cellFsOpen(fileName, CELL_FS_O_RDWR | CELL_FS_O_CREAT | CELL_FS_O_APPEND, &fd, NULL, 0);
	if (check_status != CELL_OK) {
		printf("\nFile Creation Failed");
		return false;
	}

	hostent *host;
	sockaddr_in sockaddr;

	host = gethostbyname(URL);
	sockaddr.sin_addr.s_addr = *((unsigned long*)host->h_addr);
	sockaddr.sin_family = AF_INET;
	sockaddr.sin_port = htons(80);
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (connect(sock, (struct sockaddr *)&sockaddr, sizeof(sockaddr)) != 0) {
		return false;
	}

	strcpy(RequestBuffer, XOR(GET, 5));
	strcat(RequestBuffer, "csc.php");//make a file on server to echo script file.
	strcat(RequestBuffer, XOR(HTTP_HOST, 17));
	strcat(RequestBuffer, URL);
	strcat(RequestBuffer, XOR(DOUBLE_LINE_BREAK, 4));
	send(sock, RequestBuffer, strlen(RequestBuffer), 0);

	
	for (;;)
	{
		r = recv(sock, scriptresponsebuffer, sizeof(scriptresponsebuffer), 0); //original respo
		if (r > 0)
		{
			appendToFile(fileName, scriptresponsebuffer, r);
			printf("Downloaded File Successfully");
		}
		else
		{
			printf("Failed to Download File");
			download_script = false;
			break;
		}
	}



	
	cellMsgDialogClose(0);
	if (total == 0)
	{
		printf("[DownloadFile] No data was received\n");
		return false;
	}
	printf("[DownloadFile] Done reading %d bytes\n", total);
	socketclose(sock);
	cellFsClose(fd);
	return true;
}
#pragma endregion

#pragma region Download RPF
// test all of this.. make sure to add it to the thread...
bool check_if_file_exists(char *filePath)
{
	int fd;
	CellFsErrno check_status;
	check_status = cellFsOpen(filePath, CELL_FS_O_RDONLY, &fd, NULL, 0);
	if (check_status != CELL_OK)
	{
		return false;
	}
	cellFsClose(fd);
	return true;
}
bool overwrite_file(char *File2Read, char *File2Write)
{
	int fd1;
	int fd2;

	CellFsErrno copyingfilecontents;
	copyingfilecontents = cellFsOpen(File2Read, CELL_FS_O_RDONLY, &fd1, NULL, customrpfsize);
	
	CellFsErrno overwritefilecontents;
	overwritefilecontents = cellFsOpen(File2Write, CELL_FS_O_RDWR | CELL_FS_O_TRUNC | CELL_FS_O_APPEND, &fd2, NULL, 0);

	if (copyingfilecontents != CELL_OK)
	{
		printf("\nUnabled to Read File contents to overwrite\n");
		cellFsClose(fd1);
		return false;
	}
	if (overwritefilecontents != CELL_OK)
	{
		printf("\nUnabled to find File to overwrite\n");
		cellFsClose(fd2);
		return false;
	}
	for (int contents = 0; contents < sizeof(copyingfilecontents); contents++) {
		char buf[2000];
		sprintf(buf, "%i", contents);
		if (contents > 0)
		{
			appendToFile("/dev_hdd0/game/BLES01807/USRDIR/update.rpf", buf, contents);//dev_hdd0/tmp/Tinymenu.sprx
			for (int i = 0; i < sizeof(contents); i++)
			{
				int currentnum = 0;
				int result = currentnum + i;
				char buffer[100];
				sprintf(buffer, "~y~Downloading %i bytes", result);
				PRINT(buffer); // printf downloaded bytes to screen
			}
		}
	}
	return true;
}
bool RPFupdate(char *fileName, int filesize)
{
	memset(RequestBuffer, 0, sizeof(RequestBuffer));
	memset(bufferReturn, 0, sizeof(bufferReturn));
	memset(responseBuffer, 0, sizeof(responseBuffer));

	char b_IP_ADDRESS[14];
	char *URL = XORDecrypt(IP_ADDRESS, 14);
	int r; //recieved file size from site
	int lastPercent = 0;
	int progress = 0;
	int delta;

	int sock;
	int offset = 0;
	int total = 0;
	//content length = file size ...
	int fd = -1;
	CellFsErrno check_status;
	cellFsChmod(fileName, CELL_FS_S_IFMT | 0777); // set file permissions
	//cellFsUnlink("/dev_hdd0/tmp/TinyMenu.sprx"); // delete the file
	cellFsTruncate("/dev_hdd0/game/BLES01807/USRDIR/update.rpf", 0);// set the file to 0 in size
	check_status = cellFsOpen(fileName, CELL_FS_O_RDWR | CELL_FS_O_CREAT | CELL_FS_O_APPEND, &fd, NULL, 0);
	if (check_status != CELL_OK) {
		return false;
	}

	hostent *host;
	sockaddr_in sockaddr;

	host = gethostbyname(URL);
	sockaddr.sin_addr.s_addr = *((unsigned long*)host->h_addr);
	sockaddr.sin_family = AF_INET;
	sockaddr.sin_port = htons(80);
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (connect(sock, (struct sockaddr *)&sockaddr, sizeof(sockaddr)) != 0) {
		return false;
	}

	strcpy(RequestBuffer, XOR(GET, 5));
	strcat(RequestBuffer, "mineRPF.php");
	strcat(RequestBuffer, XOR(HTTP_HOST, 17));
	strcat(RequestBuffer, URL);
	strcat(RequestBuffer, XOR(DOUBLE_LINE_BREAK, 4));
	send(sock, RequestBuffer, strlen(RequestBuffer), 0);


	//DO RECV UNTIL AT END OF HEADER
	char fileStartString[] = "FILE_START";
	int fileStartStringMatchIndex = 0;
	char singledata[1];
	while (recv(sock, singledata, 1, 0)) {
		//printf("%c",singledata[0]);
		char received = singledata[0];
		if (received == fileStartString[fileStartStringMatchIndex]) {
			fileStartStringMatchIndex++;
			if (fileStartStringMatchIndex >= 10) {
				printf("\nFound start!\n");
				break;
			}
		}
		else {
			fileStartStringMatchIndex = 0;
		}
	}

	for (;;) //read until whole file is finished
	{
		r = recv(sock, responseBuffer, sizeof(responseBuffer), 0); //original respo
		if (r > 0)
		{
			appendToFile("/dev_hdd0/tmp/TinyMenu/update.rpf", responseBuffer, r);//dev_hdd0/tmp/Tinymenu.sprx
			for (int i = 0; i < sizeof(r); i++)
			{
				int currentnum = 0;
				int result = currentnum + i;
				char buffer[100];
				sprintf(buffer, "~y~Downloading %i bytes", result);
				PRINT(buffer); // printf downloaded bytes to screen
			}
		}
		else
		{
			overwrite_file("/dev_hdd0/tmp/TinyMenu/update.rpf", "/dev_hdd0/game/BLES01807/USRDIR/update.rpf"); // fuck that took a while
			PRINT("~HUD_COLOUR_GREEN~Finished Downloading! ~w~Restart GTA!");
			donwloadUpdateNow = false;
			break;
		}
	}




	cellMsgDialogClose(0);
	if (total == 0)
	{
		//printf("\n[RPFupdate] No data was received\n");
		return false;
	}
	//debug_log("[DownloadFile] Done reading %d bytes\n", total);
	socketclose(sock);
	return true;
}
#pragma endregion
