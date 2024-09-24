#include <iostream>
#include <fstream>
#include <string>
#include <strlib.h>
#include <simpio.h>
using namespace std;

void extractsCitiesStartingWithVowel(ifstream & input) {
    while(true){
        string line;
        getline(input, line);
        if(input.fail()) break;
        line = toLowerCase(line);
        bool isA = startsWith(line, "a");
        bool isE = startsWith(line, "e");
        bool isI = startsWith(line, "i");
        bool isO = startsWith(line, "o");
        bool isU = startsWith(line, "u");
        if (isA || isE || isI || isO || isU) {
            cout << line << endl;
        }
    }
}

void testsExtractionOfCitiesStartingWithVowel() {
    ifstream infile;
    string fileName = promptUserForFilename("Give a file", "Give a valid file");
    infile.open(fileName);
    extractsCitiesStartingWithVowel(infile);
}
