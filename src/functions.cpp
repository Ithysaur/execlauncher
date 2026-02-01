#include "../include/include.hpp"
#include <iostream>

RETURN_CODE printValidUsage()
{
    std::cout << "Unrecognized syntax. Valid usage:" << std::endl;
    std::cout << "execlaunch <exectuable>" << std::endl;
    std::cout << "-s <command> : runs a command when the executable starts" << std::endl;
    std::cout << "-e <command> : runs a command when the executable exits" << std::endl;
    return RETURN_CODE_SUCCESS;
}

RETURN_CODE executeCommand(const char* command, const char* usage)
{
    int exitCode = system(command);
    if (exitCode != 0)
    {
        std::cout << "Warning: command specifed by " << usage << " returned " << exitCode << ", a non-zero return code." << std::endl;
        return RETURN_CODE_COMMAND_FAILURE;
    }

    return RETURN_CODE_SUCCESS;
}

void executeExecutable(const char* executable)
{
    if (executeCommand(executable, "<executable>") == RETURN_CODE_COMMAND_FAILURE)
    {
        exit(RETURN_CODE_COMMAND_FAILURE);
    }
}

void executeStartAndEndCommands(std::thread &thread, const char* startCommand, const char* endCommand)
{
    executeCommand(startCommand, "-s");
    thread.join();
    executeCommand(endCommand, "-e");
}