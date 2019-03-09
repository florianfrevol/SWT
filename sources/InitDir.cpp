
#include "SWT.hpp"

void write_file_to_another(std::string src, std::string dest)
{
    std::string line;
    std::string const HOME = std::getenv("HOME") ? std::getenv("HOME") : ".";
    std::ifstream file( HOME + "/tools/SWT/" + src);
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

int initdir(int argc, char **argv)
{
    if (argc < 3 || strcmp(argv[2], "--help") == 0)
        print_help_initdir();
    if (strcmp(argv[2], "-cpp") == 0)
        cpp();
    if (strcmp(argv[2], "-c") == 0)
        c();
    if (strcmp(argv[2], "-update") == 0)
        update_makefile();
    if (strcmp(argv[2], "-change") == 0 && (argc < 4 || strcmp(argv[3], "--help") == 0))
        print_help_change_initdir();
    if (argc > 3 && strcmp(argv[2], "-change") == 0)
        change_local_value(argv[3]);
}

int main(int argc, char **argv)
{
    if (argc < 2 || strcmp(argv[1], "--help") == 0)
        print_help_swt();
    if (argc >= 2 && strcmp(argv[1], "-initdir") == 0)
        initdir(argc, argv);
    return (0);
}