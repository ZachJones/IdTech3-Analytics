//altlog.h - defines the functions for the alternate logging system

/*-------------- To disable all calls to Log_AltFile ---------------

#define Log_AltFile(...)

NB// Place this BEFORE the first call to Log_AltFile
--------------------------------------------------------------------*/

/*------------- To disable all calls to Log_AltConsole -------------

#define Log_AltConsole(...)

NB// Place this BEFORE the first call to Log_AltConsole
--------------------------------------------------------------------*/

/*---------------------- To disable altlog.c -----------------------

#define DISABLE_ALT_LOG

--------------------------------------------------------------------*/

/*--------------------- To set Alt_LogPriority ---------------------

priorityLevel = ALT_LOG_PRIORITY_VERBOSE;
priorityLevel = ALT_LOG_PRIORITY_DEBUG;
priorityLevel = ALT_LOG_PRIORITY_PERFORM;
priorityLevel = ALT_LOG_PRIORITY_WARN;
priorityLevel = ALT_LOG_PRIORITY_ERROR;
priorityLevel = ALT_LOG_PRIORITY_CRITICAL;

NB// If you set priority to PERFORM, any logs tagged as PERFORM, WARN, 
ERROR or CRITICAL will be logged
--------------------------------------------------------------------*/

/*-------------------------- Example log ---------------------------

char* filename = "test.txt";
Open_Alt(filename);

priorityLevel = ALT_LOG_PRIORITY_PERFORM;
Log_AltFile(ALT_LOG_PRIORITY_PERFORM, "Player Position = %f, %f, %f", from->origin[0], from->origin[1], from->origin[2]);

Close_Alt();

--------------------------------------------------------------------*/

#ifndef ALT_LOG_H
#define ALT_LOG_H

#define MAX_LOGFILENAMESIZE		1024

typedef enum
{
	ALT_LOG_PRIORITY_VERBOSE = 0,
	ALT_LOG_PRIORITY_DEBUG = 1,
	ALT_LOG_PRIORITY_PERFORM = 2,
	ALT_LOG_PRIORITY_WARN = 3,
	ALT_LOG_PRIORITY_ERROR = 4,
	ALT_LOG_PRIORITY_CRITICAL = 5
} Alt_LogPriority;

Alt_LogPriority priorityLevel;

typedef struct altLogFile_s
{
	char filename[MAX_LOGFILENAMESIZE];
	FILE *file;
	int numwrites;
} altLogFile_t;

static altLogFile_t altLog;

void Open_Alt(char *file);

void Log_AltFile(Alt_LogPriority priority, char *message, ...); //Log message to altlog.txt
void Log_AltConsole(Alt_LogPriority priority, char *message, ...); //Log message to the console

void Close_Alt(void);

#endif