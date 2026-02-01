#include "../include/include.hpp"
#include <cstring>

std::thread executable;

int main(int argc, const char** argv)
{
    executable = std::thread(executeExecutable, argv[0]);

    switch (argc)
    {
    case 3:
        if (strcmp(argv[1], "-s") || strcmp(argv[1], "-S") || strcmp(argv[1], "--start") || strcmp(argv[1], "--Start"))
        {
            executeCommand(argv[2], "-s");
            executable.detach();
        }
        else if (strcmp(argv[1], "-e") || strcmp(argv[1], "-E") || strcmp(argv[1], "--exit") || strcmp(argv[1], "--Exit"))
        {
            executable.join();
            executeCommand(argv[2], "-e");
        }
        else if (strcmp(argv[1], "-se") || strcmp(argv[1], "-sE") || strcmp(argv[1], "-Se") || strcmp(argv[1], "-SE"))
        {
            executeStartAndEndCommands(executable, argv[2], argv[2]);
        }
        else
        {   
            printValidUsage();
            executable.detach();
            return RETURN_CODE_INVALID_INPUT;
        }
        break;
    case 5:
        //if the first input is some form of -s and the second some form of -e
        if ((strcmp(argv[1], "-s") || strcmp(argv[1], "-S") || strcmp(argv[1], "--start") || strcmp(argv[1], "--Start"))
            && (strcmp(argv[3], "-e") || strcmp(argv[3], "-E") || strcmp(argv[3], "--exit") || strcmp(argv[3], "--Exit")))
        {
            executeStartAndEndCommands(executable, argv[2], argv[4]);
        }
        //if the first input is some form of -e and the second some form of -s
        else if ((strcmp(argv[3], "-s") || strcmp(argv[3], "-S") || strcmp(argv[3], "--start") || strcmp(argv[3], "--Start"))
            && (strcmp(argv[1], "-e") || strcmp(argv[1], "-E") || strcmp(argv[1], "--exit") || strcmp(argv[1], "--Exit")))
        {
            executeStartAndEndCommands(executable, argv[4], argv[2]);
        }
        else
        {
            printValidUsage();
            executable.detach();
            return RETURN_CODE_INVALID_INPUT;
        }
        break;
    default:
        printValidUsage();
        return RETURN_CODE_INVALID_INPUT;
    }
    
    return RETURN_CODE_SUCCESS;
}