#include <string>
#include <set>
#include <cstring>
#include <fstream>
#include <iostream>

#include "MenuHandler.h"
#include "Lesson.h"

using namespace std;

int main(int argc, char const *argv[])
{
    if(argc < 2)
    {
        cerr << "Error : no file provided" << endl;
        return 1;
    }

    string loadfile = argv[1];
    ifstream file(loadfile);
    if(!file.is_open())
    {
        cerr << "Error : file given couldn't be open" << endl;
        return 2;
    }
    
    set<Lesson*> lessonSet;
    string langBase, toLang;
    int number;
    while(true)
    {
        file >> langBase >> toLang >> number;
        if(strcmp(langBase.c_str(),"0") == 0)
            break;
        
        Lesson* newLesson = new Lesson(langBase, toLang, number);
        file.seekg(newLesson->add(file, file.tellg()));
        lessonSet.insert(newLesson);
    }
    
    MenuHandler mh(lessonSet);
    mh.mainMenu();
    
    return 0;
}