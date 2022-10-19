#include <stdlib.h>
#include "std.h"
#include"functions.h"
extern s*head;
extern Uint8 List[10];
extern Uint8 List[10];
extern Uint8 counter;
extern Uint8 ID;
extern Uint8 YEAR;
extern Uint8 SUBJECT[3];
extern Uint8 GRADES[3];
extern Uint8 choice;
int main()
{printf("###################School DataBase###################\n");

 printf("------------------------------------------------------\n");
    printf("1 to Add Entry to the database\n2 search for student information using ID\n3 delete a student information from the data base\n4 search for an ID\n5 is the database full?\n6 how many number of entry in the database?!\n7 get list of the IDs\n");
    printf("------------------------------------------------------\n");
    while(1)
    {
        printf("\nenter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the ID: ");
            scanf("%d",&ID);
            printf("Enter the Year: ");
            scanf("%d",&YEAR);
            int z=1;
            for(int i=0;i<3;i++)
            {
                printf("Enter Subject[%d]:",z);
                scanf("%d",(SUBJECT + i));
                z++;
            }
            z = 1;
            for(int k=0;k<3;k++)
            {
                printf("Subject [%d] grade(0-100) is: ",z);
                scanf("%d",(GRADES + k));
                z++;
            }
            if(SDB_AddEntry(ID,YEAR,SUBJECT,GRADES))
            printf("the ID is added successfully ");
            break;
        case 2:
            printf("Enter the ID: ");
            scanf("%d",&ID);
            if(!SDB_ReadEntry(ID, &YEAR, SUBJECT, GRADES))
            {
                printf("Not a valid ID\n");
            }
            else
            {
                      printf("The year: %d\n", YEAR);
            int o=1;
            for(int i=0;i<3;i++)
            {
                printf("subject[%d] %d\n",o,*(SUBJECT+i));
                printf("grade of subject [%d] %d\n",o,*(GRADES+i));
                o++;
            }
            }

            break;
        case 3:
            printf("Enter the id : ");
            scanf("%d",&ID);
            SDB_DeleteEntry(ID);
            break;
        case 4:
            printf("Enter the ID: ");
            scanf("%d",&ID);
            SDB_IsIdExist(ID);
            if(SDB_IsIdExist(ID))
                printf("the id has been found");
            else
                printf("the id is not found");
            break;
        case 5:
            SDB_IsFull();
            if (SDB_IsFull())
                printf("the database is full");
            else
                printf("the database is not full");
            break;
        case 6:
            SDB_GetUsedSize();
            printf("%d", SDB_GetUsedSize());
            break;
        case 7:
            SDB_GetIdList( List);

                printf("the IDs is: ");
            for(int i=0;i<counter;i++)
                printf("%d ", List[i]);
            printf("\n");
            break;
        default:
            printf("please Enter a number between (1-7)");
            break;

            }
    }
    return 0;
}


