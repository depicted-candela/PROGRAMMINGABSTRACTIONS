#include <iostream>
#include <fstream>
#include <hashmap.h>
#include <filesystem>
#include "exercise1_6.h"
using namespace std;

ifstream currentFile;
int generalOperation;
HashMap<int, string> ACTIONS = {{0, "(1) Add a new line"}, {1, "(2) Count locations"}, {2, "(3) Reverse coordinates"}};
HashMap<int, string> generalOperations = {{0, "(1) Creates File"}, {1, "(2) Edits File"}};

void createsFile(string &pathFolder, string &fileName, string &pathFile) {
    while (true) {
        while (true) {
            cout << "Write the path to specify the folder where will be saved the file: ";
            cin >> pathFolder;
            if(std::filesystem::is_directory(pathFolder)) break;
        }
        while (true) {
            cout << "Write the name of the file (not including the extension): ";
            cin >> fileName;
            if(fileName.find('.') != std::string::npos) break;
        }
        pathFile = pathFolder + "/" + fileName + ".txt";
        ofstream file(pathFile);
        if (file.is_open()) {
            file.close();
            break;
        }
    }
}

void printsPreview() {
    int actions = ACTIONS.size();
    int printCounter = 0;
    cout << "File                           | Actions" << endl;
    while(true) {
        string line;
        int lineWidth;
        getline(currentFile, line);
        lineWidth = (printCounter <= actions) ? 25 : 50;
        if (printCounter < actions && currentFile.fail()) break;
        if (printCounter < actions) {
            if (!currentFile.fail()) cout << setw(lineWidth) << right << line;
            cout << ACTIONS.get(printCounter) << endl;
        } else {
            cout << endl;
        }
        printCounter++;
    }
}

void whatToDoWithOpenFile () {
    printsPreview();
}

void withCreatedFile() {
    string pathFolder;
    string fileName;
    string pathFile;
    createsFile(pathFolder, fileName, pathFile);
    currentFile.open(pathFile);
    whatToDoWithOpenFile();
}

void performsGeneralPath() {
    switch (generalOperation) {
    case 0:
        withCreatedFile();
        break;
    default: cout << ":)" << endl;
    }
}

bool isAnOperation(int generalOperation) {
    if (!generalOperations.containsKey(generalOperation)) return false;
    return true;
}

void selectsGeneralPath () {
    int genOperation;
    for (int i = 0; i < generalOperations.size(); i++) {
        cout << generalOperations.get(i) << endl;
    }
    cout << "What do you want to do?: ";
    while(true) {
        int realOperation;
        cin >> skipws >> genOperation;
        realOperation = genOperation - 1;
        if(isAnOperation(realOperation)) {
            generalOperation = realOperation;
            break;
        }
        cout << "Input a valid operation: ";
    }
}

void cliForGISOperations() {
    selectsGeneralPath();
    performsGeneralPath();
}
