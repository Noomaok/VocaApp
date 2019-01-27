#include <iostream>
#include <ostream>

#include "MenuHandler.h"
#include "Lesson.h"

using namespace std;

MenuHandler::MenuHandler(set<Lesson*> list)
: LessonList(list)
{
#ifdef MAP
    cout << "Constructor of <MenuHandler>" << endl;
#endif
}

MenuHandler::~MenuHandler()
{
    set<Lesson*>::const_iterator it = LessonList.begin();
    while(it != LessonList.end())
    {
        delete *it++;
    }

#ifdef MAP
    cout << "Destructor of <MenuHandler>" << endl;
#endif
}

void MenuHandler::mainMenu()
{
    cout << *this;
}

ostream& operator<<(ostream &os, MenuHandler const &menuH)
{
    set<Lesson*>::const_iterator it = menuH.LessonList.begin();
    while(it != menuH.LessonList.end())
    {
        os << **it << " : " << (*it++)->nbElements() << " items" << endl;
    }
    return os;
}