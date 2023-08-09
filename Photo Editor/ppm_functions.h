#ifndef ppm_include
#define ppm_include
#include <fstream>
#include <iostream>
using namespace std;
int print_file_options();
int print_operation_options();
int get_user_input(int choices);
bool open_files(ifstream &in, ofstream &out, int file, int operation);
bool read_header_information(ifstream &ppmIn, int &width, int &height, int &maxValue);
void write_header_information(ofstream &ppmOut, int width, int height, int maxValue);
void read_and_write_modified_pixels(ifstream &ppmIn, ofstream &ppmOut, int choice2, int width, int height, int maxValue);
#endif
