#include <string>
#include <set>
#include <cstring>
#include <fstream>
#include <iostream>
#include "Lesson.h"

using namespace std;

int main()
{
    set<Lesson*> lessonSet;
    string loadfile = "template";
    ifstream file(loadfile);
    string langBase, toLang;
    int number;
    while(true)
    {
        file >> langBase >> toLang >> number;
        if(strcmp(langBase.c_str(),"0") == 0)
            break;
        
        //cout << langBase << " " << toLang << " " << number << endl;
        Lesson* newLesson = new Lesson(langBase, toLang, number);
        file.seekg(newLesson->add(file, file.tellg()));
        lessonSet.insert(newLesson);
    }
    
    set<Lesson*>::const_iterator it;
    for(it = lessonSet.begin(); it != lessonSet.end(); ++it)
    {
        cout << **it << endl;
        (*it)->askElement(1);
    }

    return 0;
}