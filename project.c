#include <stdio.h>
#include <string.h>

typedef struct student {
    int rollno;
    char name[20];
    float marks;
    char course[20];
} student;

student arr[50];
int count = 0;

void saveToFile() {
    FILE *fp;
    fp = fopen("students.dat", "wb");
    if (fp == NULL) {
        printf("Error saving!");
        return;
    }
    for (int i = 0; i < count; i++) {
        fwrite(&arr[i], sizeof(student), 1, fp);
    }
    fclose(fp);
}

void loadFromFile() {
    FILE *fp;
    fp = fopen("students.dat", "rb");
    if (fp == NULL) {
        return;
    }
    while (fread(&arr[count], sizeof(student), 1, fp) == 1) {
        count++;
    }
    fclose(fp);
}

int login() {
    char username[20], password[20];
    char correct_user[] = "Surya";
    char correct_pass[] = "5432";
    int attempts = 3;

    printf("\n===== STUDENT MANAGEMENT SYSTEM =====");
    while (attempts > 0) {
        printf("\n\nUsername: ");
        scanf("%s", username);
        printf("Password: ");
        scanf("%s", password);

        if (strcmp(username, correct_user) == 0 && strcmp(password, correct_pass) == 0) {
            printf("\nLogin successful! Welcome!");
            return 1;
        } else {
            attempts--;
            if (attempts > 0)
                printf("Wrong credentials! %d attempts left.", attempts);
        }
    }
    printf("\nToo many failed attempts. Exiting.");
    return 0;
}

void addstudents() {
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
}

void viewstudents() {
    if (count == 0) {
        printf("\nNo students found!");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("\n--- Student %d ---", i + 1);
        printf("\nRoll No: %d", arr[i].rollno);
        printf("\nName: %s", arr[i].name);
        printf("\nMarks: %.2f", arr[i].marks);
        printf("\nCourse: %s", arr[i].course);
    }
}

void deletestudents() {
    int rollno;
    printf("\nEnter Roll No: ");
    scanf("%d", &rollno);
    for (int i = 0; i < count; i++) {
        if (arr[i].rollno == rollno) {
            for (int j = i; j < count - 1; j++) {
                arr[j] = arr[j + 1];
            }
            count--;
            printf("Student deleted successfully!");
            return;
        }
    }
    printf("Student not found!");
}

void searchstudents() {
    int rollno;
    printf("\nEnter Roll No: ");
    scanf("%d", &rollno);
    for (int i = 0; i < count; i++) {
        if (arr[i].rollno == rollno) {
            printf("\nRoll No: %d", arr[i].rollno);
            printf("\nName: %s", arr[i].name);
            printf("\nMarks: %.2f", arr[i].marks);
            printf("\nCourse: %s", arr[i].course);
            return;
        }
    }
    printf("Student not found!");
}

void updatestudents() {
    int rollno;
    printf("\nEnter Roll No: ");
    scanf("%d", &rollno);
    for (int i = 0; i < count; i++) {
        if (arr[i].rollno == rollno) {
            printf("\nEnter New Roll No: ");
            scanf("%d", &arr[i].rollno);
            printf("\nEnter New Name: ");
            scanf(" %[^\n]", arr[i].name);
            printf("\nEnter New Marks: ");
            scanf("%f", &arr[i].marks);
            printf("\nEnter New Course: ");
            scanf(" %[^\n]", arr[i].course);
            printf("Student updated successfully!");
            return;
        }
    }
    printf("Student not found!");
}

int main() {
    if (login() == 0) {
        return 0;
    }



    int menu;
    do {
        printf("\n\n1. Add Student");
        printf("\n2. View Students");
        printf("\n3. Delete Student");
        printf("\n4. Search Student");
        printf("\n5. Update Student");
        printf("\n6. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &menu);

        switch (menu) {
        case 1:
            addstudents();
            saveToFile();
            break;
        case 2:
            viewstudents();
            break;
        case 3:
            deletestudents();
            saveToFile();
            break;
        case 4:
            searchstudents();
            break;
        case 5:
            updatestudents();
            saveToFile();
            break;
        case 6:
            printf("Goodbye!");
            break;
        default:
            printf("Invalid choice!");
        }
    } while (menu != 6);

    return 0;
}
