#include "SWT.hpp"

void cpp()
{
    std::string src_folder = find_variable_config("SOURCE_FOLDER");
    std::string headers_folder = find_variable_config("HEADER_FOLDER");
    struct stat sb;

    if (stat("SrcCpy/gitignore/gitignore", &sb) == -1)
        write_file_to_another("SrcCpy/gitignore/gitignore", ".gitignore");
    if (stat(convertStringToCharStars(src_folder), &sb) == -1)
    {
        mkdir(convertStringToCharStars(src_folder), 0777);
        write_file_to_another("SrcCpy/src/main", src_folder + "/main.cpp");
    }
    if (stat(convertStringToCharStars(headers_folder), &sb) == -1)
    {
        mkdir(convertStringToCharStars(headers_folder), 0777);
        write_file_to_another("SrcCpy/headers/main", headers_folder + "/main.hpp");
    }
    if (stat("Makefile", &sb) == -1)
        write_file_to_another("SrcCpy/Makefiles/Makefile_cpp", "Makefile");
}

void c()
{
    std::string src_folder = find_variable_config("SOURCE_FOLDER");
    std::string headers_folder = find_variable_config("HEADER_FOLDER");
    struct stat sb;

    if (stat("SrcCpy/gitignore/gitignore", &sb) == -1)
        write_file_to_another("SrcCpy/gitignore/gitignore", ".gitignore");
    if (stat(convertStringToCharStars(src_folder), &sb) == -1)
    {
        mkdir(convertStringToCharStars(src_folder), 0777);
        write_file_to_another("SrcCpy/src/main", src_folder + "/main.c");
    }
    if (stat(convertStringToCharStars(headers_folder), &sb) == -1)
    {
        mkdir(convertStringToCharStars(headers_folder), 0777);
        write_file_to_another("SrcCpy/headers/main", headers_folder + "/main.h");
    }
    if (stat("Makefile", &sb) == -1)
        write_file_to_another("SrcCpy/Makefiles/Makefile_c", "Makefile");
}