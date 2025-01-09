//AndriyHelloQuit9Increment Compilator on C++17
//2024.12.31_14:58
/*
   mm   m    m  mmmm   mmmm
   ##   #    # m"  "m #"  "m   m
  #  #  #mmmm# #    # #m  m#   #
  #mm#  #    # #    #  """ #"""#"""
 #    # #    #  #mm#" "mmm"    #
                   #
*/

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <cstdlib>

#define VERSION "0.1"
#define NAMEPROGRAM "AHQ9P"

#define C_ARG_AHQ9P_REQUID      2
#define V_AHQ9PFILEARG_CMD      1

#define TRUELENGTHSTR           1

const time_t CURRENTDATE = time(0);
const char* STRINGCURRENTDATE = ctime(&CURRENTDATE);

using namespace std;
using namespace std::filesystem;

bool CheckEnd (const string &sourceString, const string &stringTest, int startStr = 4) {
    return ((sourceString.substr((sourceString.length() - startStr), (sourceString.length() - TRUELENGTHSTR))) == stringTest);
}

int main (int argc, char *argv[]) {
    string ahq9pName;
    ifstream ahq9p_file;
    string ahq9p_code;
    ofstream cppCode;

    string cppName = "ahq9p.cpp";

    if (argc < C_ARG_AHQ9P_REQUID) {
        cout << "AHQ9PLUS: fatal error: no input files\ncompilation terminated.\nahq9pc <file.ahq>" << endl;
        exit (1);
    }

    if ( (CheckEnd(argv[V_AHQ9PFILEARG_CMD], ".ahq")) && (exists(argv[V_AHQ9PFILEARG_CMD])) ) {
        ahq9pName = argv[V_AHQ9PFILEARG_CMD];
        ahq9p_file.open(argv[V_AHQ9PFILEARG_CMD]);
    } else {
        cout << "File not exist or not have a extention .ahq" << endl;
        exit (1);
    }

    if ( !exists(cppName) ) {
        cppCode.open (cppName);
    } else {
        remove (cppName);
        cppCode.open (cppName);
    }

    cppCode << "//CODE GENERETED BY AHQ9P ON " << STRINGCURRENTDATE                                                                                 << endl
            << "#include <iostream>\n#include <fstream>\n#include <string>\n"                                                                       << endl
            << "using namespace std;"                                                                                                               << endl
            << "void h () { cout<<\"Hello World!\"<<endl; }"                                                                                        << endl
            << "void q (string fn) { ifstream f(fn, ifstream::in); string str; while ( getline (f, str) ) { cout << str << endl; } }"  << endl
            << "void d () { for (int i = 99; i>=1; i--) { \
                            cout << i << \" bottles of beer on the wall,\" << endl \
                                 << i << \" bottles of beer.\" << endl \
                                 << \"Take one down, pass it around,\" << endl; } \
                            cout << \"No bottles of beer on the wall.\" << endl; }"                                                                 << endl
            << "int main () { int i = 0; ";

    cppCode.close();
    cppCode.open(cppName, ios::app);
    getline(ahq9p_file, ahq9p_code);

    for (auto i = ahq9p_code.begin(); i != ahq9p_code.end(); i++) {
        switch(*i){
        case 'H':
            cppCode << "h();";
            break;
        case 'Q':
            cppCode << "q(\"" <<  ahq9pName << "\");";
            break;
        case '9':
            cppCode << "d();";
            break;
        case '+':
            cppCode << "i++;";
            break;
        }
    }
    cppCode << "}";
    cppCode.close();

    system("/usr/bin/g++ ahq9p.cpp -o ahq9p");
    system("/usr/bin/rm -rf ahq9p.cpp");
}


