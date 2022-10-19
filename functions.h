#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include"std.h"


typedef struct student
{
    Uint8 id;
    Uint8 year;
    Uint8 subject[3];
    Uint8 grades[3];
    struct student *next;

}s;

_Bool SDB_IsFull(void);
Uint8 SDB_GetUsedSize(void);
_Bool SDB_AddEntry(Uint8 Id,Uint8 Year,Uint8 *Subjects, Uint8 *Grades);
void SDB_DeleteEntry(Uint8 Id);
_Bool SDB_ReadEntry(Uint8 Id,Uint8 *Year,Uint8 *Subjects, Uint8 *Grades);
void SDB_GetIdList(Uint8 *List);
_Bool SDB_IsIdExist(Uint8 ID);




#endif // FUNCTIONS_H_INCLUDED
