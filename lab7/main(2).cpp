#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_SUBJECTS 10

// Student structure definition
// It contains student's ID, name, an array to store scores of multiple subjects, and the total score.
typedef struct {
    char id[20];
    char name[50];
    int scores[MAX_SUBJECTS];
    int totalScore;
} Student;

// Function to compute the total score of a student
// It sums up all the scores of different subjects for a given student.
void computeStudentTotalScore(Student* student, int subjectCount) {
    student->totalScore = 0;
    for (int i = 0; i < subjectCount; i++) {
        student->totalScore += student->scores[i];
    }
}

// Comparison function for sorting students
// It first compares the total scores of two students in descending order.
// If the total scores are equal, it then compares their IDs in ascending order.
int compareStudentsForSorting(const void* a, const void* b) {
    Student* studentA = (Student*)a;
    Student* studentB = (Student*)b;
    if (studentA->totalScore != studentB->totalScore) {
        return studentB->totalScore - studentA->totalScore; // Sort by total score in descending order
    }
    return strcmp(studentA->id, studentB->id); // Sort by ID in ascending order if total scores are equal
}

// Function to print the ranking table of students
// It displays the rank, ID, name, total score, and scores of each subject for all students.
void printStudentRankingTable(Student students[], int studentCount, int subjectCount) {
    printf("Rank\tID\tName\tTotal\t");
    for (int i = 0; i < subjectCount; i++) {
        printf("Subject%d\t", i + 1);
    }
    printf("\n");

    int rank = 1;
    for (int i = 0; i < studentCount; i++) {
        if (i > 0 && students[i].totalScore != students[i - 1].totalScore) {
            rank = i + 1;
        }
        printf("%d\t%s\t%s\t%d\t", rank, students[i].id, students[i].name, students[i].totalScore);
        for (int j = 0; j < subjectCount; j++) {
            printf("%d\t\t", students[i].scores[j]);
        }
        printf("\n");
    }
}

int main() {
    int studentCount, subjectCount;

    // Prompt the user to enter the number of students
    printf("Enter the number of students: ");
    scanf("%d", &studentCount);
    // Prompt the user to enter the number of subjects
    printf("Enter the number of subjects: ");
    scanf("%d", &subjectCount);

    // Check if the entered number of students or subjects exceeds the maximum allowed values
    if (studentCount > MAX_STUDENTS || subjectCount > MAX_SUBJECTS) {
        printf("Error: Exceeds maximum allowed students or subjects.\n");
        return 1;
    }

    Student students[MAX_STUDENTS];

    // Input student data
    for (int i = 0; i < studentCount; i++) {
        // Prompt for student ID
        printf("Enter ID for student %d: ", i + 1);
        scanf("%s", students[i].id);
        // Prompt for student name
        printf("Enter name for student %d: ", i + 1);
        scanf("%s", students[i].name);
        // Prompt for scores of each subject
        printf("Enter scores for %d subjects: ", subjectCount);
        for (int j = 0; j < subjectCount; j++) {
            scanf("%d", &students[i].scores[j]);
        }
        // Compute the total score for the current student
        computeStudentTotalScore(&students[i], subjectCount);
    }

    // Sort the array of students using the custom comparison function
    qsort(students, studentCount, sizeof(Student), compareStudentsForSorting);

    // Print the ranking table of students
    printStudentRankingTable(students, studentCount, subjectCount);

    return 0;
}