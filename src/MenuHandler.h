#ifndef MENUHANDLER_H
#define MENUHANDLER_H

#include <set>
#include <ostream>

#include "Lesson.h"

using namespace std;

class MenuHandler
{
    public:
        MenuHandler(set<Lesson*> list);
        virtual ~MenuHandler();

        void mainMenu();

        friend ostream& operator<<(ostream &os, MenuHandler const &menuH);

    protected:
        set<Lesson*> LessonList;
};

#endif