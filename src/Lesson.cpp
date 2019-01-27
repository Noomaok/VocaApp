#include "Lesson.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <sstream>

using namespace std;

Lesson::Lesson(string langBase, string toLang, int lessonNumber)
:langBase(langBase), toLang(toLang), lessonNumber(lessonNumber)
{
#ifdef MAP
    cout << "Constructor of <Lesson>" << endl;
#endif
}

Lesson::~Lesson()
{
#ifdef MAP
    cout << "Destructor of <Lesson>" << endl;
#endif
}

streampos Lesson::add(ifstream &file, streampos currentPos)
{
    file.seekg(currentPos);
    string line;
    getline(file, line);
    while(true)
    {
        getline(file, line);
        if(strcmp(line.c_str(), "||") == 0)
        {
            break;
        }
        vector<string> w = split(line, DELIMITER);
        Word newWord;
        newWord.landBase = w.front();
        newWord.translate1 = w.at(1);
        newWord.translate2 = w.at(2);
        words.push_back(newWord);
    }
    return file.tellg();
}

vector<string> Lesson::split(string strToSplit, char delimiter)
{
    stringstream ss(strToSplit);
    string item;
    vector<string> splittedString;
    while(getline(ss, item, delimiter))
    {
        splittedString.push_back(item);
    }
    return splittedString;
}

int Lesson::nbElements()
{
    return words.size();
}

void Lesson::askElement(int index)
{
    cout << "What is the translation of <" << words.at(index).landBase << "> in " << toLang << endl;
    string s;
    cin >> s;
    if(s == words.at(index).translate1 || s == words.at(index).translate2)
        cout << "Good" << endl;
    else
        cout << "Bad" << endl;
    cout << "Answer : " << words.at(index).translate1 << "   " << words.at(index).translate2 << endl;
}

bool operator<(const Lesson &a, const Lesson &b)
{
    return a.lessonNumber < b.lessonNumber;
}

ostream& operator<<(ostream &os, Lesson const &lesson)
{
    os << lesson.langBase << " to " << lesson.toLang << ", Lesson number " << lesson.lessonNumber;
    return os;
}