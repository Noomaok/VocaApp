#ifndef LESSON_H
#define LESSON_H

#include <string>
#include <fstream>
#include <ostream>
#include <vector>

using namespace std;

typedef struct Word{
    string landBase;
    string translate1;
    string translate2;
} Word;

class Lesson
{
    public:
        Lesson(string langBase, string toLang, int lessonNumber);
        virtual ~Lesson();

        streampos add(ifstream &file, streampos currentPos);
        vector<string> split(string strToSplit, char delimiter);
        int nbElements();
        void askElement(int index);

        friend bool operator<(const Lesson &a, const Lesson &b);
        friend ostream& operator<<(ostream &os, Lesson const &lesson);

    protected:
        vector<Word> words;
        string langBase;
        string toLang;
        int lessonNumber;
        const char DELIMITER = '|';
};

#endif