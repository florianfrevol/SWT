#include "SWT.hpp"

std::vector<char *> open_dir(const char *str)
{

    DIR *dir;
    struct dirent *dent;
    dir = opendir(str);
    std::vector<char *> vector;

    if (dir != NULL) {
        while ((dent = readdir(dir)) != NULL) {
            if ((strcmp(dent->d_name, ".") == 0 || strcmp(dent->d_name, "..") == 0 || (*dent->d_name) == '.')) {
            } else {
                vector.push_back(dent->d_name);
            }
        }
    }
    return (vector);
}

void update_makefile()
{
    std::vector<char *> vector ;
    
    std::system("make clean");
    vector = open_dir("sources");
    for (unsigned int i = 0; i < vector.size(); i++) {
        printf("%s\n", vector.at(i));
    }
}