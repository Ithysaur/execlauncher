#pragma once
#include <cstdint>
#include <cstdlib>
#include <thread>

#define RETURN_CODE uint8_t
#define RETURN_CODE_SUCCESS 0
#define RETURN_CODE_INVALID_INPUT 1
#define RETURN_CODE_COMMAND_FAILURE 2
#define RETURN_CODE_UPPER_LIMIT 255

RETURN_CODE printValidUsage();
RETURN_CODE executeCommand(const char* command, const char* usage);
void executeExecutable(const char* executable);
void executeStartAndEndCommands(std::thread &thread, const char* startCommand, const char* endCommand);