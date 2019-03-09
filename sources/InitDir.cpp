
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

int main(int argc, char **argv)
{
    if (argc < 2)
        return (84);

    if (strcmp(argv[1], "cpp") == 0)
        cpp();
    if (strcmp(argv[1], "c") == 0)
        c();
    if (strcmp(argv[1], "update") == 0)
        update_makefile();
    return 0;
}