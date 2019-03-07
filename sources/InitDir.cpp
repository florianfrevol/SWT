#include <stdio.h>
#include <string.h>
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/types.h>

void write_file_to_another(std::string src, std::string dest)
{
    std::string line;
    std::string const HOME = std::getenv("HOME") ? std::getenv("HOME") : ".";
    std::ifstream file( HOME + "/tools/InitDir/" + src);
    std::ofstream outfile;

    outfile.open(dest, std::ios_base::app);
    if (file) {
        while (getline(file, line)) {
            outfile << line << std::endl;
        }
    } else
        std::cerr << "File Error" << std::endl;
}

char *convertStringToCharStars(std::string str)
{
    char *cstr = new char[str.length() + 1];
    strcpy(cstr, str.c_str());
    return (cstr);
}

void cpp()
{
    std::string src_folder = "sources";
    std::string headers_folder = "headers";
    struct stat sb;

    
    if (stat(convertStringToCharStars(src_folder), &sb) == -1) {
        mkdir(convertStringToCharStars(src_folder), 0777);
        write_file_to_another("src/main", src_folder + "/main.cpp");
    }
    if (stat(convertStringToCharStars(headers_folder), &sb) == -1) {
        mkdir(convertStringToCharStars(headers_folder), 0777);
        write_file_to_another("headers/main", headers_folder + "/main.hpp");
    }
    if (stat("Makefile", &sb) == -1)
        write_file_to_another("Makefiles/Makefile_cpp", "Makefile");
}

void c()
{
    std::string src_folder = "sources";
    std::string headers_folder = "headers";
    struct stat sb;

    if (stat(convertStringToCharStars(src_folder), &sb) == -1)
    {
        mkdir(convertStringToCharStars(src_folder), 0777);
        write_file_to_another("src/main", src_folder + "/main.c");
    }
    if (stat(convertStringToCharStars(headers_folder), &sb) == -1)
    {
        mkdir(convertStringToCharStars(headers_folder), 0777);
        write_file_to_another("headers/main", headers_folder + "/main.h");
    }
    if (stat("Makefile", &sb) == -1)
        write_file_to_another("Makefiles/Makefile_c", "Makefile");
}

int main(int argc, char **argv)
{
    if (argc < 2)
        return (84);

    if (strcmp(argv[1], "cpp") == 0)
        cpp();
    if (strcmp(argv[1], "c") == 0)
        c();
    return 0;
}