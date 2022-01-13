#include <sys/return_code.h>
#include <sysutil/sysutil_oskdialog.h>
#include <sysutil/sysutil_msgdialog.h>


static int connect_to_CAPPI(void)
{
	struct sockaddr_in sin;
	int s;

	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = 0x7F000001; //127.0.0.1 (localhost)
	sin.sin_port = htons(6333);
	s = socket(AF_INET, SOCK_STREAM, 0);
	if (s < 0)
	{
		return -1;
	}

	if (connect(s, (struct sockaddr *)&sin, sizeof(sin)) < 0)
	{
		return -1;
	}

	return s;
}


static int connect_to_webman(void)
{
	struct sockaddr_in sin;
	int s;

	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = 0x7F000001; //127.0.0.1 (localhost)
	sin.sin_port = htons(80);         //http port (80)
	s = socket(AF_INET, SOCK_STREAM, 0);
	if (s < 0)
	{
		return -1;
	}

	if (connect(s, (struct sockaddr *)&sin, sizeof(sin)) < 0)
	{
		return -1;
	}

	return s;
}

static void sclose(int *socket_e)
{
	if (*socket_e != -1)
	{
		shutdown(*socket_e, SHUT_RDWR);
		socketclose(*socket_e);
		*socket_e = -1;
	}
}


struct timeval
{
	int tv_usec;
	int tv_sec;
};
timeval tv;

static void send_wm_request(const char *cmd)
{
	// send command
	int conn_s = -1;
	conn_s = connect_to_webman();

	//struct timeval tv;
	tv.tv_usec = 0;
	tv.tv_sec = 3;
	setsockopt(conn_s, SOL_SOCKET, SO_SNDTIMEO, &tv, sizeof(tv));
	setsockopt(conn_s, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));

	if (conn_s >= 0)
	{
		char wm_cmd[1048];
		int cmd_len = sprintf(wm_cmd, "GET %s HTTP/1.0\r\n", cmd);
		send(conn_s, wm_cmd, cmd_len, 0);
		sclose(&conn_s);
	}
}



static void send_CCAPI_request(const char *cmd)
{
	// send command
	int conn_s = -1;
	conn_s = connect_to_CAPPI();

	//struct timeval tv;
	tv.tv_usec = 0;
	tv.tv_sec = 3;
	setsockopt(conn_s, SOL_SOCKET, SO_SNDTIMEO, &tv, sizeof(tv));
	setsockopt(conn_s, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));

	if (conn_s >= 0)
	{
		char wm_cmd[1048];
		int cmd_len = sprintf(wm_cmd, "GET %s HTTP/1.0\r\n", cmd);
		send(conn_s, wm_cmd, cmd_len, 0);
		sclose(&conn_s);
	}
}

void fixSpaces(char** szReturn) {
	char *str = *szReturn;
	char _returnStr[512];// = (char*)Malloc(128);

	_returnStr[0] = '\0';

	int dwStrIndex = 0;

	for (int i = 0; i < strlen(str) + 1; i++) {
		if (str[i] != 0x20) {
			_returnStr[dwStrIndex] = str[i];
			dwStrIndex++;
		}
		else
		{
			_returnStr[dwStrIndex] = '%';
			_returnStr[dwStrIndex + 1] = '2';
			_returnStr[dwStrIndex + 2] = '0';
			dwStrIndex += 3;
		}


		_returnStr[dwStrIndex] = '\0';
	}

	*szReturn = _returnStr;
}

bool CCAPI = true;
bool WebMan;

void DoNotify(char *szFormat, int id = 0) {
	char _notify_buffer[512];
	if (CCAPI == true)
	{
		snprintf(_notify_buffer, 512, "/ccapi/notify?id=%i&msg=%s", id, szFormat);
		send_CCAPI_request(_notify_buffer);
	}
	else if (WebMan == true)
	{
		fixSpaces(&szFormat);
		snprintf(_notify_buffer, 512, "/notify.ps3mapi?msg=%s", szFormat);
		send_wm_request(_notify_buffer);
	}
}

void Buzzer(int snd = 1)
{
	char _notify_buffer[512];
	if (CCAPI == true)
	{
		snprintf(_notify_buffer, 512, "/ccapi/ringbuzzer?type=%i", snd);
		send_CCAPI_request(_notify_buffer);
	}
	else if (WebMan == true)
	{
		snprintf(_notify_buffer, 512, "/buzzer.ps3mapi?mode=%i", snd);
		send_wm_request(_notify_buffer);
	}
}
namespace Dialog
{
	bool Finished = false;
	bool YESNO = false;

	enum {
		MODE_IDLE = 0,
		MODE_ERRORCODE_DIALOG_TEST,
		MODE_STRING_OK,
		MODE_STRING_YESNO,
		MODE_STRING_DIALOG_3,
		MODE_STRING_DIALOG_4,
		MODE_STRING_DIALOG_5,
		MODE_CHECK_PROGRESSBAR_1,
		MODE_RUNNING,
		MODE_CHECK_TIMEOUT,
		MODE_TIMEOUT_NEXT,
		MODE_EXIT
	};

	static int msgdialog_mode = MODE_IDLE;

	static void cb_dialogText1(int button_type, void *userdata)
	{
		switch (button_type) {

		case CELL_MSGDIALOG_BUTTON_OK:
			msgdialog_mode = MODE_EXIT;
			break;
		case CELL_MSGDIALOG_BUTTON_ESCAPE:
			msgdialog_mode = MODE_EXIT;
			break;

		default:
			msgdialog_mode = MODE_EXIT;
			break;
		}
	}
	static void cb_dialogText2(int button_type, void *userdata)
	{
		switch (button_type) {

		case CELL_MSGDIALOG_BUTTON_YES:
			YESNO = true;
			msgdialog_mode = MODE_EXIT;
			break;

		case CELL_MSGDIALOG_BUTTON_NO:
			msgdialog_mode = MODE_EXIT;
			break;

		case CELL_MSGDIALOG_BUTTON_ESCAPE:
			msgdialog_mode = MODE_EXIT;
			break;

		default:
			break;
		}
	}
	static void cb_dialogText3(int button_type, void *userdata)
	{
		switch (button_type) {
		default:
			msgdialog_mode = MODE_EXIT;
			break;
		}
	}

	void _sleep(usecond_t time)
	{
		sys_timer_usleep(time * 1000);
	}
	int _console_write(const char * s)
	{
		uint32_t len;
		system_call_4(403, 0, (uint64_t)s, std::strlen(s), (uint64_t)&len);
		return_to_user_prog(int);
	}
	void Showprogress(const char* msg, const char* Secondmessage = "", int time = 100)
	{
		unsigned int type = CELL_MSGDIALOG_TYPE_SE_TYPE_NORMAL
			| CELL_MSGDIALOG_TYPE_BG_VISIBLE
			| CELL_MSGDIALOG_TYPE_BUTTON_TYPE_NONE
			| CELL_MSGDIALOG_TYPE_DISABLE_CANCEL_ON
			| CELL_MSGDIALOG_TYPE_DEFAULT_CURSOR_NONE
			| CELL_MSGDIALOG_TYPE_PROGRESSBAR_SINGLE;
		cellMsgDialogOpen2(type, msg, NULL, NULL, NULL);
		cellMsgDialogProgressBarSetMsg(CELL_MSGDIALOG_PROGRESSBAR_INDEX_DOUBLE_UPPER, Secondmessage);
		for (int i = 0; i < 100; i++)
		{
			cellMsgDialogProgressBarInc(CELL_MSGDIALOG_PROGRESSBAR_INDEX_SINGLE, 1);
			_sleep(time);
		}
		_console_write("Progressbar Finished");
		cellMsgDialogClose(2);
	}

	void ShowYESNO(char* msg)
	{
		int ret = 0;
		unsigned int type = CELL_MSGDIALOG_TYPE_SE_TYPE_NORMAL
			| CELL_MSGDIALOG_TYPE_BG_INVISIBLE
			| CELL_MSGDIALOG_TYPE_BUTTON_TYPE_YESNO
			| CELL_MSGDIALOG_TYPE_DISABLE_CANCEL_ON
			| CELL_MSGDIALOG_TYPE_DEFAULT_CURSOR_YES;


		switch (msgdialog_mode)
		{
		case MODE_IDLE:
			break;

		case MODE_STRING_YESNO:
			cellMsgDialogOpen2(type, msg, cb_dialogText2, NULL, NULL);
			Dialog::ShowYESNO("Welcome");
			msgdialog_mode = MODE_RUNNING;
			Dialog::Showprogress("Now Loading SPRX ", "Y", 20);
			break;

		case MODE_EXIT:
			cellMsgDialogClose((float)1);
			break;

		default:
			break;

		}


	}
	void Show(char* msg)
	{

		unsigned int type = CELL_MSGDIALOG_TYPE_SE_TYPE_ERROR
			| CELL_MSGDIALOG_TYPE_BG_INVISIBLE
			| CELL_MSGDIALOG_TYPE_BUTTON_TYPE_OK
			| CELL_MSGDIALOG_TYPE_DISABLE_CANCEL_ON
			| CELL_MSGDIALOG_TYPE_DEFAULT_CURSOR_OK;


		switch (msgdialog_mode)
		{
		case MODE_IDLE:
			break;

		case MODE_STRING_OK:
			cellMsgDialogOpen2(type, msg, cb_dialogText1, NULL, NULL);
			msgdialog_mode = MODE_EXIT;
			break;

		case MODE_EXIT:
			cellMsgDialogClose((float)5);
			break;

		default:
			break;

		}

		while (Dialog::msgdialog_mode != Dialog::MODE_EXIT) {}  //wait for the dialog to end :P
	}

	void End()
	{
		Finished = false;
		YESNO = false;
	}


}
