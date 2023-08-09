// The include section adds extra definitions from the C++ standard library.

#include "ppm_functions.h"

// We will use the standard library namespace in our programs.
using namespace std;

/**
 * @brief Prints the options menu for which file 
 * to open and returns the number of files that can be opened.
 * @return int number of options available
 */
int print_file_options(){
    cout << "Which image to load? \n" 
    << "  1. Brick \n" << "  2. Wallpaper \n" << "  3. Private \n"
    << "Enter 1, 2, or 3: ";
    return 3;
}

/**
 * @brief Prints the options menu for which file
 *  processing to perform and returns the number of options that can be performed.
 * @return int number of options available
 */
int print_operation_options(){
    cout << "Which process to apply? \n" 
    << "  1. Grayscale \n" << "  2. Inversion \n" << "  3. Seprate by color \n "
    << "Enter 1, 2, or 3: ";
    return 2;
}

/**
 * @brief Get the user input object and test to see
 * if thier choice was valid
 * @param choices which image the user choses / which operation
 * ex: brick, wallpaper, grayscale, invert, etc.
 * @return int value chosen
 */
int get_user_input(int choices){
    int user1, x;
    bool test = true;
    do{
            cin >> user1;
            if(cin.fail() || user1 < 1 || user1 > 3){
                cerr << "Inavlid Input." << endl;
                test = false;
                cin.clear();
                cin.ignore();
                cout << "Enter 1, 2, or 3: ";
            } else {
                test = true;
                x = user1;
            }
    } while(test != true);
    return x;
}

/**
 * @brief Opens the corresponding files for reading 
 * and writing based on the file and operation chosen
 * Verifies that both files successfully opened
 * @param in the image the user chooses to use
 * @param out the output to the operation the user chooses to do
 * @param file which of brick, wallpaper, personal the user chooses to use
 * @param operation which of grayscale and invert the user chooses to use
 * @return true if both files successfully opened
 * @return false if file fails to open
 */
bool open_files(ifstream &in, ofstream &out, int file, int operation){
    string out_file_op_suffix_name;
    switch (operation) {
        case 1:
            out_file_op_suffix_name = "_graysclae";
            break;
        case 2:
            out_file_op_suffix_name = "_inverted";
            break;
        case 3:
            out_file_op_suffix_name = "_separate_by_color";
            break;
    }
    string  file_name, in_file_name, out_file_name;
    switch(file) {
        case 1:
          file_name = "brick";
          break;
        case 2:
          file_name = "wallpaper";
          break;
        case 3:
          file_name = "private";
          break;                

    }

    in_file_name = file_name + ".ppm";
    out_file_name = file_name +  out_file_op_suffix_name + ".ppm";
    in.open(in_file_name);
                if(in.fail()){
                cerr << "Could not open input file!" << endl;
                return false;
                }
    out.open(out_file_name);
            if(out.fail()){
                cerr << "Could not open output file!" << endl;
                return false;
            }
    return true;
}

/**
 * @brief Reads the header block of the file (the first four values)
 * @param ppmIn the stream to the image that the user chooses
 * @param width the width of the image the user chooses
 * @param height the height of the image the user chooses
 * @param maxValue the max value of rgb which is always 255
 * @return true if a P3 file
 * @return false if anything but a P3 file
 */
bool read_header_information(ifstream &ppmIn, int &width, int &height, int &maxValue){
    char c1, c2;
    ppmIn >> c1 >> c2 >> width >> height >> maxValue;
    if(c1 == 'P' && c2 == '3'){
        return true;
    }else{ 
        cerr << "Not a P3 file" << endl;
        return false;
    }
}

/**
 * @brief writes the header block of the file (the first four values)
 * @param ppmOut the stream to the file that the operation will be writing to
 * @param width the width of the image the user chooses
 * @param height the height of the image the user chooses
 * @param maxValue the max value of rgb which is always 255
 */
void write_header_information(ofstream &ppmOut, int width, int height, int maxValue){
     ppmOut << "P3 \n" << width << " " << height << endl;
     ppmOut << maxValue << endl;
}

/**
 * @brief Reads all the pixel data from the input file.
 * For each pixel read writes to the output file 
 * the modified pixel value based on the selected operation.
 * @param ppmIn the stream to the image that the user chooses
 * @param ppmOut the stream to the file that the operation will be writing to
 * @param choice2 which operation the user would like to use grayscale or invert
 * @param width the width of the image the user chooses
 * @param height the height of the image the user chooses
 * @param maxValue the max value of rgb which is always 255
 */
void read_and_write_modified_pixels(ifstream &ppmIn, ofstream &ppmOut, int choice2, int width, int height, int maxValue){
    int red,green,blue,gray;
    while (!ppmIn.eof()) {
        ppmIn >> red >> green >> blue;
        if(choice2 == 1){
           gray = 0.2989 * red + 0.5870 * green + 0.1140 * blue;
           ppmOut << gray << " " << gray << " " << gray << "     ";
        } else if (choice2 == 2) {
           ppmOut << maxValue - red << " " << maxValue - green << " " << maxValue - blue << "     ";
        } else {
            int* a = new int[3 * width * height];
            for (int h=0; h < height; h++) {
                for (int w=0; w < width; w++) {
                    ppmIn >> red >> green >> blue;
                        *(a + 0 + w*3 + h*width) = red;
                        *(a + 1 + w*3 + h*width) = green;
                        *(a + 2 + w*3 + h*width) = blue;
                    
                }
            }
            for (int h=0; h < height; h++) {
                for (int w=0; w < width; w++) {
                    ppmOut << *(a + 0+ w*3 + h*width) << " " << *(a + 1 + w*3 + h*width) << " " <<  *(a + 2 + w*3 + h*width) << " " ;
                }
            }
                   
        }
    }
}


