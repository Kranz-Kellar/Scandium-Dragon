#include "Logger.h"

const char* SD::Logger::logFileName = LOG_FILE_NAME;

#ifdef _DEBUG
bool SD::Logger::_IsLogToConsole = true;
#endif

void SD::Logger::_WriteToFile(const char* msg)
{
	//Later
}

const char* SD::Logger::_GetStatusString(LogStatus status)
{
	switch (status) {
	case LOG_DEBUG:
		_ChangeConsoleColor(CONSOLE_COLOR_DEBUG_BLUE);
		return "[DEBUG] ";
	case LOG_INFO:
		_ChangeConsoleColor(CONSOLE_COLOR_INFO_GREEN);
		return "[INFO] ";
	case LOG_WARNING:
		_ChangeConsoleColor(CONSOLE_COLOR_WARNING_YELLOW);
		return "[WARNING] ";
	case LOG_ERROR:
		_ChangeConsoleColor(CONSOLE_COLOR_ERROR_RED);
		return "[ERROR] ";
	case LOG_CRITICAL:
		_ChangeConsoleColor(CONSOLE_COLOR_CRITICAL_RED);
		return "[CRITICAL] ";
	}

	return "[UNKNOW]";
}

void SD::Logger::_ChangeConsoleColor(int colorNum)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, colorNum);
}

void SD::Logger::Log(LogStatus status, const char* msg)
{
	char buildedMessage[LOG_MESSAGE_SIZE] = "";
	strcat(buildedMessage, _GetStatusString(status));
	strcat(buildedMessage, msg);
	strcat(buildedMessage, "\n");

	_WriteToFile(buildedMessage);

	if (_IsLogToConsole) {
		printf(buildedMessage);
	}

	_ChangeConsoleColor(CONSOLE_COLOR_BASE);
}
