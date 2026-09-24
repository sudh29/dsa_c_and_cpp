#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    double score;
} Student;

void print_student(const Student *s) {
    printf("Student ID: %d | Name: %s | Score: %.2f\n", s->id, s->name, s->score);
}

int main(void) {
    printf("=== C Structs and Typedefs ===\n");
    Student s1;
    s1.id = 101;
    strncpy(s1.name, "Alice Smith", sizeof(s1.name) - 1);
    s1.score = 94.5;

    Student s2 = {102, "Bob Jones", 88.0};

    print_student(&s1);
    print_student(&s2);
    return 0;
}
