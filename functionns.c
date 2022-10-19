#include"std.h"
#include"functions.h"


Uint8 counter = 0;

s*head = NULL;
Uint8 List[10] = {0};
Uint8 ID = 0;
Uint8 YEAR = 0;
Uint8 SUBJECT[3] = {0};
Uint8 GRADES[3] = {0};
Uint8 choice = 0;
_Bool SDB_AddEntry(Uint8 Id,Uint8 Year,Uint8 *Subjects, Uint8 *Grades)
{
    if(SDB_IsFull())
        return 0;
   else
   {

    s*add=(s*)malloc(sizeof(s));
    add->id=Id;
    add->year=Year;
    for(int i = 0; i < 3; i++)
    {
        add->subject[i]=*(Subjects + i);
        add->grades[i]=*(Grades + i);
    }

    add->next = head;
    head = add;
    counter++;


    return 1;

   }
}
_Bool SDB_ReadEntry(Uint8 Id,Uint8 *Year,Uint8 *Subjects, Uint8 *Grades)
{
    s*read=head;
    while(read !=NULL)
    {
        if(read->id == Id)
            {
                *Year = read->year;
                for (int i=0;i<3;i++)
                {
                    Subjects[i] = read->subject[i];
                    Grades[i] = read->grades[i];
                }
                return 1;

            }
        read=read->next;
    }
    return 0;

}
void SDB_DeleteEntry(Uint8 Id)
{
    s*temp1=head;
    s*temp2=head;
    while(temp1!=NULL)
    {
        if(temp1->id==Id)
        {
            printf("the Id Number %d is found\n",Id);

        if(temp1==temp2)// this condition will run if the id that we want to delete is the first node of the linked list
        {
            head=head->next;
            free(temp1);
        }
        else
        {
            temp2->next=temp1->next;
            free(temp1);
        }
        printf("succefully deleted\n");
        counter--;
        temp2=temp1;
        temp1=temp1->next;
        return;
        }

    }
    printf("the ID %d is not found\n",Id);

}
_Bool SDB_IsIdExist(Uint8 ID)
{
    s*temp1=head;
    while(temp1!= NULL)
    {
        if(temp1->id==ID)
            return 1;
        temp1 = temp1->next;
    }
    return 0;
}
_Bool SDB_IsFull(void)
{
    if (counter==10)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
Uint8 SDB_GetUsedSize(void)
{
    return counter;
}
void SDB_GetIdList(Uint8 *List)
{
    s* temp = head;
    Uint8 i = 0;
    while(temp != NULL)
    {
        List[i] = temp->id;
        temp = temp->next;
        i++;
    }
}

