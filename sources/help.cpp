#include "SWT.hpp"

void print_help_initdir()
{
    std::cout << "USAGE: ./swt initdir [str]\n" << std::endl;
    std::cout << "\t--help\t\t\tPrint this help" << std::endl;
    std::cout << "\t-c/cpp\t\t\tInitialise repository (c or cpp)" << std::endl;
    std::cout << "\t-update\t\t\tUpdate Makefile depending on sources folder" << std::endl;
    std::cout << "\t-change \t\tChange the value \"-change --help\" to see more" << std::endl;
    exit(0);
}

void print_help_change_initdir()
{
    std::cout << "USAGE: ./swt initdir -change [variable_to_change]=[value], (ex: SOURCE_FOLDER=src)\n" << std::endl;
    std::cout << "\t--help\t\t\tPrint this help" << std::endl;
    std::cout << "\tSOURCE_FOLDER\t\tYou're sources folder" << std::endl;
    std::cout << "\tHEADER_FOLDER\t\tYou're headers folder" << std::endl;
    exit(0);
}

void print_help_swt()
{
    std::cout << "USAGE: ./swt [str]\n" << std::endl;
    std::cout << "\t--help\t\t\tPrint this help" << std::endl;
    std::cout << "\t-initdir\t\tInitialize a repository" << std::endl;
}