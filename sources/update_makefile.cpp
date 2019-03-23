#include "SWT.hpp"

void listFiles(const std::string &path, std::function<void(const std::string &)> cb)
{
    if (auto dir = opendir(path.c_str()))
    {
        while (auto f = readdir(dir))
        {
            if (!f->d_name || f->d_name[0] == '.')
                continue;
            if (f->d_type == DT_DIR)
                listFiles(path + f->d_name + "/", cb);

            if (f->d_type == DT_REG)
                cb(path + f->d_name);
        }
        closedir(dir);
    }
}

    std::vector<char *> vector;
void update_makefile()
{

        std::system("make clean");

    listFiles(find_variable_config("SOURCE_FOLDER").append("/"), [](const std::string &path) {
        vector.push_back(convertStringToCharStars(path));
    });

    for (unsigned int i = 0; i < vector.size(); i++) {
        printf("%s\n", vector.at(i));
    }
}