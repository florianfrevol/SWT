#include "SWT.hpp"

template <typename Out>
void split(const std::string &s, char delim, Out result)
{
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim))
    {
        *(result++) = item;
    }
}

std::string find_variable_config(std::string variable_to_find)
{
    std::string variable;
    std::string line;
    // std::string const HOME = std::getenv("HOME") ? std::getenv("HOME") : ".";
    std::ifstream file(".swt");
    std::string tempStr;
    
    if (file) {
        while (getline(file, line)) {
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

    std::vector<std::string> elems;
    split(value_to_change, '=', std::back_inserter(elems));

    std::string line;
    std::string const HOME = std::getenv("HOME") ? std::getenv("HOME") : ".";
    std::string delimiter = ":";
    std::string tempstr;
    bool val = false;
    std::ofstream outfile;
    struct stat sb;
    std::string temp_elem_0;

    if (stat(".swt", &sb) == -1)
            std::system(convertStringToCharStars(((std::string) "cp ").append(HOME).append("/tools/SWT/local_variable/base_src_folder.config ").append(".swt")));
    std::ifstream file(".swt");
    if (stat(".tmpswt", &sb) != -1)
        std::system("rm .tmpswt");
    outfile.open(".tmpswt", std::ios_base::app);
    if (file) {
        while (getline(file, line)) {
            tempstr = line;
            temp_elem_0 = elems.at(0);
            if (strcmp(convertStringToCharStars(tempstr.replace(elems.at(0).size(), tempstr.size(), "")), convertStringToCharStars(elems.at(0))) == 0) {
                tempstr.replace(0, tempstr.size(), temp_elem_0.append(delimiter.append(elems.at(1))));
                val = true;
            }
            if (val == false)
                outfile << line << std::endl;
            else {
                outfile << tempstr << std::endl;
                val = false;
            }
        }
        std::system("cp .tmpswt .swt; rm .tmpswt");
    }
    else
        std::cerr << "File Error" << std::endl;
}