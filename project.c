#include <stdio.h>

typedef struct student
{
    int rollno;
    char name[20];
    float marks;
    char course[20];
} student;

student arr[50];
int count = 0;

int main()
{
    int menu;
    do
    {
        printf("\n1. Add Student");
        printf("\n2. View Students");
        printf("\n3. Delete Student");
        printf("\n4. Search Student");
        printf("\n5. Update Student");
        printf("\n6. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &menu);
        switch (menu)
        {
            switch (menu)
            {
            case 1:
                printf("\nEnter Roll No: ");
                scanf("%d", &arr[count].rollno);
                printf("\nEnter Name: ");
                scanf(" %[^\n]", arr[count].name);
                printf("\nEnter Marks: ");
                scanf("%f", &arr[count].marks);
                printf("\nEnter Course: ");
                scanf(" %[^\n]", arr[count].course);
                count++;
                printf("Student added successfully!");
                break;
            case 2:
                if (count == 0)
                {
                    printf("\nNo students found!");
                    break;
                }
                for (int i = 0; i < count; i++)
                {
                    printf("\n--- Student %d ---", i + 1);
                    printf("\nRoll No: %d", arr[i].rollno);
                    printf("\nName: %s", arr[i].name);
                    printf("\nMarks: %.2f", arr[i].marks);
                    printf("\nCourse: %s", arr[i].course);
                }
                break;
            }
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            printf("Exiting...");
            break;
        default:
            printf("Invalid choice!");
        }
    } while (menu != 6);
    return 0;
}
