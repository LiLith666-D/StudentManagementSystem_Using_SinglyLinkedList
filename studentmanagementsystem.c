#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Student {
    int rollNo;
    char name[50];
    float cgpa;
    struct Student* next;
};
struct Student* head = NULL;
void insertStudent(int rollNo, char name[], float cgpa) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    newStudent->rollNo = rollNo;
    strcpy(newStudent->name, name);
    newStudent->cgpa = cgpa;
    newStudent->next = NULL;
    if (head == NULL) {
        head = newStudent;
    } else {
        struct Student* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newStudent;
    }
    printf("Added New Student Record successfully!\n");
    printf("New Student Record → Roll No: %d | Name: %s | CGPA: %.2f\n",
           rollNo, name, cgpa);
}
void deleteStudent(int rollNo) {
    struct Student* temp = head;
    struct Student* prev = NULL;
    if (temp != NULL && temp->rollNo == rollNo) {
        head = temp->next;
        free(temp);
        printf("Student Record with Roll No %d deleted successfully!\n", rollNo);
        return;
    }
    while (temp != NULL && temp->rollNo != rollNo) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Student Record with Roll No %d not found.\n", rollNo);
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Student Record with Roll No %d deleted successfully!\n", rollNo);
}
void searchStudent(int rollNo) {
    struct Student* temp = head;
    while (temp != NULL) {
        if (temp->rollNo == rollNo) {
            printf("Student Record Found:\n");
            printf("Roll No: %d\nName: %s\nCGPA: %.2f\n",
                   temp->rollNo, temp->name, temp->cgpa);
            return;
        }
        temp = temp->next;
    }
    printf("Student Record with Roll No %d not found.\n", rollNo);
}
void displayAll() {
    struct Student* temp = head;
    if (temp == NULL) {
        printf("No Student Records found.\n");
        return;
    }
    printf("\nStudent Records:\n");
    while (temp != NULL) {
        printf("Roll No: %d | Name: %s | CGPA: %.2f\n",
               temp->rollNo, temp->name, temp->cgpa);
        temp = temp->next;
    }
}
int main() {
    int update, rollNo, n;
    char name[50];
    float cgpa;
    while (1) {
        printf("\n===== STUDENT RECORD MANAGEMENT SYSTEM =====\n");
        printf("1. Add New Student Record(s)\n");
        printf("2. Remove Existing Student Record(s)\n");
        printf("3. Search Student Record\n");
        printf("4. Display All Students Records\n");
        printf("5. Completed Updation of Student Records\n");
        printf("Enter your choice: ");
        scanf("%d", &update);
        switch (update) {
            case 1:
                printf("How many students do you want to add? ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("\nEnter Roll No: ");
                    scanf("%d", &rollNo);
                    printf("Enter Name: ");
                    scanf("%s", name);
                    printf("Enter CGPA: ");
                    scanf("%f", &cgpa);
                    insertStudent(rollNo, name, cgpa);
                }
                break;
            case 2:
                printf("How many students do you want to delete? ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("\nEnter Roll No to delete: ");
                    scanf("%d", &rollNo);
                    deleteStudent(rollNo);
                }
                break;
            case 3:
                printf("Enter Roll No: ");
                scanf("%d", &rollNo);
                searchStudent(rollNo);
                break;
            case 4:
                displayAll();
                break;
            case 5:
                printf("Completed with Updation Of Student Records...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
