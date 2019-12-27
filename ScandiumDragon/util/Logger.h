#pragma once

#include <stdio.h>
#include <string.h>
#include <windows.h>

#define LOG_FILE_NAME "SDEngine.log"
#define LOG_MESSAGE_SIZE 512
#define CONSOLE_COLOR_BASE 15
#define CONSOLE_COLOR_CRITICAL_RED 12
#define CONSOLE_COLOR_ERROR_RED 4
#define CONSOLE_COLOR_WARNING_YELLOW 14
#define CONSOLE_COLOR_INFO_GREEN 10
#define CONSOLE_COLOR_DEBUG_BLUE 8


namespace SD {

	enum LogStatus {
		LOG_DEBUG,
		LOG_INFO,
		LOG_WARNING,
		LOG_ERROR,
		LOG_CRITICAL
	};

	class Logger
	{
		static const char* logFileName;
		static void _WriteToFile(const char* msg);
		static const char* _GetStatusString(LogStatus status);
		static bool _IsLogToConsole;
		static void _ChangeConsoleColor(int colorNum);
	public:
		static void Log(LogStatus status, const char* msg);
	};

}
