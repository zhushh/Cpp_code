#include "commonList.h"

#include <iostream>
#include <string>

#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define NUM 5
#define NAME_MAX_LENGTH 100

typedef struct Node {
    char name[NAME_MAX_LENGTH];
    TListHead list;
} Student;

Student stu[NUM];
TListHead g_studentList;

void InitStudentList() {
    InitListHead(&g_studentList);

    for (unsigned int i = 0; i < NUM; i++) {
        stu[i].name[0] = '\0';
        //ListAddTail(&g_studentList, &(stu[i].list));
    }
}

void printStudentList(TListHead* l) {
    TListHead* cur = l;
    
    if (ListEmpty(cur)) 
        return;

    do {
        Student *curStu = ListGetEntry(cur, Student, list);
        printf("%s\n", curStu->name);
        cur = cur->next;
    } while (cur->next != l);
}

int main()
{
    InitStudentList();

    string name;
    for (int i = 0; i < NUM; i++) {
        cin >> name;
        strncpy_s(stu[i].name, name.c_str(), NAME_MAX_LENGTH);
        ListAddTail(&g_studentList, &(stu[i].list));
    }

    printStudentList(g_studentList.next);

    system("pause");
    return 0;
}

