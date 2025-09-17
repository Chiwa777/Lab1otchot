#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>

struct Student {
    char name[50];
    char surname[50];
    int course;
};

void createStudent(struct Student* s) {
    printf("������� ��� ��������: ");
    scanf("%s", s->name);
    printf("������� ������� ��������: ");
    scanf("%s", s->surname);
    printf("������� ���� ��������: ");
    scanf("%d", &s->course);
}

void printStudent(const struct Student* s) {
    printf("�������: %s %s, ����: %d\n", s->name, s->surname, s->course);
}

void toLowerCase(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void findStudentByNamePartial(const struct Student students[], int size, const char* searchTerm) {
    printf("\n���������� ������ �� ����� �����/������� '%s':\n", searchTerm);
    int found = 0;
    char searchLower[50];
    strcpy(searchLower, searchTerm);
    toLowerCase(searchLower);

    for (int i = 0; i < size; i++) {
        char nameLower[50], surnameLower[50];
        strcpy(nameLower, students[i].name);
        strcpy(surnameLower, students[i].surname);
        toLowerCase(nameLower);
        toLowerCase(surnameLower);

        if (strstr(nameLower, searchLower) != NULL || strstr(surnameLower, searchLower) != NULL) {
            printStudent(&students[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("�������� �� ������� '%s' �� �������\n", searchTerm);
    }
}

void findStudentByName(const struct Student students[], int size, const char* name) {
    printf("\n���������� ������ �� ������� ����� '%s':\n", name);
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printStudent(&students[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("������� � ������ '%s' �� ������\n", name);
    }
}

void findStudentBySurname(const struct Student students[], int size, const char* surname) {
    printf("\n���������� ������ �� ������ ������� '%s':\n", surname);
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(students[i].surname, surname) == 0) {
            printStudent(&students[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("������� � �������� '%s' �� ������\n", surname);
    }
}

void findStudentByCourse(const struct Student students[], int size, int course) {
    printf("\n���������� ������ �� ����� %d:\n", course);
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (students[i].course == course) {
            printStudent(&students[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("�������� �� ����� %d �� �������\n", course);
    }
}

void searchMenu(const struct Student students[], int size) {
    int choice;
    char searchTerm[50];
    char searchSurname[50];
    int searchCourse;

    do {
        printf("\n=== ���� ������ ��������� ===\n");
        printf("1. ����� �� ����� �����/������� (��������)\n");
        printf("2. ����� �� ������� �����\n");
        printf("3. ����� �� ������ �������\n");
        printf("4. ����� �� �����\n");
        printf("5. ��������� � ������� ����\n");
        printf("�������� �������: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("������� ����� ����� ��� ������� ��� ������: ");
            scanf("%s", searchTerm);
            findStudentByNamePartial(students, size, searchTerm);
            break;

        case 2:
            printf("������� ������ ��� ��� ������: ");
            scanf("%s", searchTerm);
            findStudentByName(students, size, searchTerm);
            break;

        case 3:
            printf("������� ������ ������� ��� ������: ");
            scanf("%s", searchSurname);
            findStudentBySurname(students, size, searchSurname);
            break;

        case 4:
            printf("������� ���� ��� ������: ");
            scanf("%d", &searchCourse);
            findStudentByCourse(students, size, searchCourse);
            break;

        case 5:
            printf("������� � ������� ����...\n");
            break;

        default:
            printf("�������� �����! ���������� �����.\n");
            break;
        }


    } while (choice != 5);
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    int array[10];

    for (int i = 0; i < 10; i++) {
        array[i] = rand() % 100;
    }

    printf("������ ������:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    printf("������� ����� ������������ � ����������� ���������: ");
    int min = INT_MAX;
    int max = 0;
    for (int i = 0; i < 10; i++) {
        if (array[i] > max) max = array[i];
    }
    for (int i = 0; i < 10; i++) {
        if (array[i] < min) min = array[i];
    }
    int res = max - min;
    printf("%d\n", res);

    int* arrayP;
    int size;
    printf("������� ������ �������:\n");
    scanf("%d", &size);

    arrayP = (int*)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        arrayP[i] = rand() % 100;
    }
    printf("������ ��������� �������:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arrayP[i]);
    }
    free(arrayP);

    printf("\n��������� �������:\n");
    int matrix[6][6];
    int rowsize[6] = { 0 };

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            matrix[i][j] = rand() % 100;
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            rowsize[i] += matrix[i][j];
        }
    }
    printf("����� ������ ������: \n");
    for (int i = 0; i < 6; i++) {
        printf("%d ", rowsize[i]);
    }
    printf("\n");


    printf("\n=== ������ �� ���������� STUDENT ===\n");

    struct Student students[3];


    printf("\n������� ������ ��� 3 ���������:\n");
    for (int i = 0; i < 3; i++) {
        printf("\n������� %d:\n", i + 1);
        createStudent(&students[i]);
    }

    printf("\n��� ��������:\n");
    for (int i = 0; i < 3; i++) {
        printStudent(&students[i]);
    }

    searchMenu(students, 3);

    printf("\n������� ���������� �����:");
    int rows;
    scanf("%d", &rows);

    printf("\n������� ���������� ��������:");
    int cols;
    scanf("%d", &cols);


    int** matr = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++)
    {
        matr[i] = (int*)malloc(cols * sizeof(int*));
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matr[i][j] = rand() % (21 - 10);
        }
    }

    int count = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matr[i][j] == 0) count++;
        }
    }
    printf("\n���������� ������� ���������: %d", count);


    return 0;
}