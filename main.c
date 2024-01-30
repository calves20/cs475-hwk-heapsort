#include <stdio.h>
#include "employee.h"

#define MAX_EMPLOYEES 5

void heapSort(Employee *A, int n);  // Assuming heapSort is defined in heap.c
void printList(Employee *A, int n); // Assuming printList is defined in heap.c

int main() {
    Employee employees[MAX_EMPLOYEES];
    int i;

    // Filling the array with user input
    for (i = 0; i < MAX_EMPLOYEES; i++) {
        printf("Enter name for employee %d: ", i + 1);
        scanf("%s", employees[i].name); // assuming names do not have spaces
        printf("Enter salary for employee %d: ", i + 1);
        scanf("%d", &employees[i].salary);
    }

    // Sorting the array
    heapSort(employees, MAX_EMPLOYEES);

    // Printing the sorted list
    printList(employees, MAX_EMPLOYEES);

    return 0;
}

