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

streampos Lesson::Add(ifstream &file, streampos currentPos)
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
        //cout << line << endl;
        vector<string> words = Split(line, DELIMITER);
        cout << words.front() << endl; //" " << words.at(1) << " " << words.at(2) << endl;
        string w = words.at(1);
        cout << w << endl;  
    }
    return file.tellg();
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

vector<string> Lesson::Split(string strToSplit, char delimiter)
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