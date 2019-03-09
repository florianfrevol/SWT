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
#include <dirent.h>

void cpp();
void c();
void write_file_to_another(std::string src, std::string dest);
char *convertStringToCharStars(std::string str);
void update_makefile();
std::string find_variable_config(std::string variable_to_find);
void print_help_initdir();
void change_local_value(std::string value_to_change);
void print_help_change_initdir();
void print_help_swt();