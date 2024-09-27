#include <hashmap.h>
#include <fstream>
#include <simpio.h>
using namespace std;

void extractsParagraph(string &line) {
    int startingIndex, lineLength;
    startingIndex = 0;
    lineLength = line.length();
    for (int i = 0; i < lineLength; i++) {
        if (line.at(i) == '\"') startingIndex = i + 1;
    }
    line = line.substr(startingIndex, lineLength - 2);
}

void savesWordInMap(HashMap<string, int> &countedWords, string word) {
    if (countedWords.containsKey(word)) {
        countedWords.put(word, countedWords[word] + 1);
        return;
    }
    countedWords.put(word, 1);
}

void countsWordFrequencyInLine(HashMap<string, int> &countedWords, string &line) {
    int latestIndex, lineLength;
    string word;
    latestIndex = 0;
    extractsParagraph(line);
    lineLength = line.length();
    for (int i = 0; i < lineLength; i++) {
        if (line.at(i) == ' ') {
            word = line.substr(latestIndex - 1, i);
            savesWordInMap(countedWords, word);
            latestIndex = i;
        }
    }
    word = line.substr(latestIndex + 1, lineLength - 1);
    savesWordInMap(countedWords, word);
}

void createsSortedArrayWithWordFrequencies(HashMap<string, int> &countedWords, Vector<string> &keys, Vector<int> &values) {
    keys = countedWords.keys();
    values = countedWords.values();
    int keysSize = keys.size();
    // Bubble sorting based on the values in the pairs
    for (int i = 0; i < keysSize - 1; ++i) {
        for (int j = 0; j < keysSize - 1 - i; ++j) {
            if (values[j] < values[j + 1]) {
                int tempValue = values[j];
                string tempKey = keys[j];
                values[j] = values[j + 1];
                values[j + 1] = tempValue;
                keys[j] = keys[j + 1];
                keys[j + 1] = tempKey;
            }
        }
    }
}

string readsFile() {
    return promptUserForFilename("Give the file's path:", "Give a valid path:");
}

void countsWordFrequency() {
    Vector<string> keys;
    Vector<int> values;
    string filePath = readsFile();
    HashMap<string, int> countedWords;
    fstream file;
    file.open(filePath);
    string line;
    while (getline(file, line)) {
        extractsParagraph(line);
        countsWordFrequencyInLine(countedWords, line);
    }
    createsSortedArrayWithWordFrequencies(countedWords, keys, values);
    for (int i = 0; i < keys.size(); i++) cout << keys[i] << ": " << values[i] << endl;
}


