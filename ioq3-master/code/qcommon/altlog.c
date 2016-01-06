//l_log.c <-- Same functionality

#include <stdarg.h>
#include <stdio.h>
#include <time.h>
#include "altlog.h"


typedef struct Alt_LogLevel
{
	int category;
	Alt_LogPriority priority;
	struct Alt_LogLevel *next;
} Alt_LogLevel;

//================================================

//#define DISABLE_ALT_LOG

#ifndef DISABLE_ALT_LOG

void Open_Alt(char *file)
{
	altLog.file = fopen(file,"a");
}

void Log_AltFile(Alt_LogPriority priority, char* message, ...)
{
	va_list varArgs; //Holds all variadic arguments

	if (!altLog.file) return; //If there's no file, don't log
	
	va_start(varArgs, message);

	if (priority >= priorityLevel)
	{
		fprintf(altLog.file, "Log Time: %02d", clock() * 1000 / CLOCKS_PER_SEC);

		if (priority == ALT_LOG_PRIORITY_CRITICAL)
		{
			fprintf(altLog.file, "[CRITICAL]");
			vfprintf(altLog.file, message, varArgs, priority);
			fprintf(altLog.file, "\n");
		}
		else if (priority == ALT_LOG_PRIORITY_ERROR)
		{
			fprintf(altLog.file, "[ERROR]");
			vfprintf(altLog.file, message, varArgs, priority);
			fprintf(altLog.file, "\n");
		}
		else if (priority == ALT_LOG_PRIORITY_WARN)
		{
			fprintf(altLog.file, "[WARNING]");
			vfprintf(altLog.file, message, varArgs, priority);
			fprintf(altLog.file, "\n");
		}
		else if (priority == ALT_LOG_PRIORITY_PERFORM)
		{
			fprintf(altLog.file, "[PERFORMANCE]");
			vfprintf(altLog.file, message, varArgs, priority);
			fprintf(altLog.file, "\n");
		}
		else if (priority == ALT_LOG_PRIORITY_DEBUG)
		{
			fprintf(altLog.file, "[DEBUG]");
			vfprintf(altLog.file, message, varArgs, priority);
			fprintf(altLog.file, "\n");
		}
		else if (priority == ALT_LOG_PRIORITY_VERBOSE)
		{
			fprintf(altLog.file, "[VERBOSE]");
			vfprintf(altLog.file, message, varArgs, priority);
			fprintf(altLog.file, "\n");
		}
	}

	va_end(varArgs);
	fflush(altLog.file); //Clear the file stream's output buffer
}

void Log_AltConsole(Alt_LogPriority priority, char* message, ...)
{
	va_list varArgs; //Holds all variadic arguments

	va_start(varArgs, message);

	if (priority >= priorityLevel)
	{
		printf("Log Time: %02d", clock() * 1000 / CLOCKS_PER_SEC);

		if (priority == ALT_LOG_PRIORITY_CRITICAL)
		{
			printf("[CRITICAL]");
			vprintf(message, varArgs, priority);
			printf("\n");
		}
		else if (priority == ALT_LOG_PRIORITY_WARN)
		{
			printf("[WARNING]");
			vprintf(message, varArgs, priority);
			printf("\n");
		}
		else if (priority == ALT_LOG_PRIORITY_PERFORM)
		{
			printf("[PERFORMANCE]");
			vprintf(message, varArgs, priority);
			printf("\n");
		}
		else if (priority == ALT_LOG_PRIORITY_VERBOSE)
		{
			printf("[VERBOSE]");
			vprintf(message, varArgs, priority);
			printf("\n");
		}
	}

	va_end(varArgs);
}

void Close_Alt(void)
{
	fclose(altLog.file);
}

#else

void Open_Alt(char *file){}

void Log_AltFile(Alt_LogPriority priority, char *message, ...){} //Log message to altlog.txt
void Log_AltConsole(Alt_LogPriority priority, char *message, ...){} //Log message to the console

void Close_Alt(void){}
#endif