#include <stdio.h>

typedef struct student {
    int rollno;
    char name[20];
    float marks;
    char course[20];
} student;

student arr[50];
int count = 0;

int main() {
    int menu;
    do {
        printf("\n1. Add Student");
        printf("\n2. View Students");
        printf("\n3. Delete Student");
        printf("\n4. Search Student");
        printf("\n5. Update Student");
        printf("\n6. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &menu);
        switch(menu) {
            case 1: break;
            case 2: break;
            case 3: break;
            case 4: break;
            case 5: break;
            case 6: printf("Exiting..."); break;
            default: printf("Invalid choice!");
        }
    } while(menu != 6);
    return 0;
}
