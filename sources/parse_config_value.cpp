#include "SWT.hpp"

std::string find_variable_config(std::string variable_to_find)
{
    std::string variable;
    std::string line;
    std::string const HOME = std::getenv("HOME") ? std::getenv("HOME") : ".";
    std::ifstream file(HOME + "/tools/SWT/local_variable/base_src_folder.config");
    std::string tempStr;    
    
    if (file) {
        while (getline(file, line))
        {
            tempStr = line;
            if (strcmp(convertStringToCharStars(line.replace(variable_to_find.size(), line.size(), "")), convertStringToCharStars(variable_to_find)) == 0)
                variable = tempStr.replace(0, variable_to_find.size() + 1, "");
        }
    }
    else
        std::cerr << "File Error" << std::endl;
    return (variable);
}

void change_local_value(std::string value_to_change)
{
    
}