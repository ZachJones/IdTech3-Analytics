//altlog.h - defines the functions for the alternate logging system

//l_log.h <-- Same functionality

#ifndef ALT_LOG_H
#define ALT_LOG_H


#define MAX_LOGFILENAMESIZE		1024
#define TRUE 1
#define FALSE 0

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

extern int logCreated;

void Open_Alt(char *file);

void Close_Alt(void);

void Log_Alt(char *message, ...); //Log message to ALTLOG

#endif