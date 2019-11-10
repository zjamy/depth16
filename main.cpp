#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
// #include <memory.h>


// we need to reference this for a better sequence data
// typedef struct
// {
//     FILE *fh;
//     int width, height;
//     int next_frame;
//     int seq_header_len, frame_header_len;
//     int frame_size;
// } depth_input_t;

#define DEPTH_MAGIC "D16"
#define MAX_DEPTH_HEADER 80
#define Y4M_FRAME_MAGIC "FRAME"
#define MAX_FRAME_HEADER 80

int height;
int width;
typedef struct depth_meta
{
    int undefined;
    int undefined;
    int undefined; /* data */
} depth_meta;
depth_meta metadata;

//This program uses the write and read functions.
using namespace std;
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cout << "argument error!" << endl;
        cout << "example: test c:/test.txt d:/testOut.txt" << endl;
        system("pause");
        exit(-1);
    }
    for (int i = 0; i < 3; i++)
    {
        cout << argv[i] << endl;
    }
    ifstream fileIn;
    fileIn.open(argv[1], ios::in); // input file
    if (fileIn.fail())
    {
        cout << "fileIn open error: " << endl;
        system("pause");
        exit(-1);
    }
    ofstream fileOut;
    fileOut.open(argv[2], ios::out); // output file
    if (!fileOut)
    {
        cout << "fileOut open error..." << endl;
        system("pause");
        exit(-1);
    }

    // places to add header file for 16bit depth header
    char header_str[4];
    fileOut << DEPTH_MAGIC << endl;
    fileOut << height << endl;
    fileOut << width << endl;
    fileOut << meta_data << endl;
    memset(header_str,'0',4*sizeof(char))

    //perpare the content data
    char str[500];
    while (!fileIn.eof())
    {
        memset(str, '\0', 500 * sizeof(char));
        fileIn.getline(str, 500);
        fileOut << str << endl;
        cout << str << endl;
    }
    fileIn.close();
    fileOut << "file perpared well" << endl;
    fileOut.close();
    system("pause");
    return 0;
}