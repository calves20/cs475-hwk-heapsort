/*
 * heapsort.c
 *
 *  Created on: Jul 1, 2013
 *      Author @ Curtis Alves
 */
#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "heap.h"

/**
 * Sorts a list of n employees in descending order
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the heap
 */
void heapSort(Employee *A, int n) {
    int i;

    // Building the heap
    buildHeap(A, n);

    // Sorting process
    for (i = n - 1; i > 0; i--) {
        swap(&A[0], &A[i]);  // Swapping the root of the heap with the last element
        heapify(A, 0, i);    // Heapifying the reduced heap
    }
}

/**
 * Given an array A[], we want to get A[] into min-heap property
 * We only need to run heapify() on internal nodes (there are floor(n/2) of them)
 * and we need to run it bottom up (top-down cannot build a heap)
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the heap
 */
void buildHeap(Employee *A, int n) {
    int i;

    // Heapifying every element from A[n/2 - 1] down to A[0]
    for (i = n / 2 - 1; i >= 0; i--) {
        heapify(A, i, n);
    }
}

/**
 * We want to start with A[i] and percolate it downward
 * if it is greater than either left or right child.
 *
 * @param	*A	Pointer to the list of employees
 * @param	i	Index of current element to heapify
 * @param	n	Size of the heap
 */
void heapify(Employee *A, int i, int n) {
    int left = 2 * i + 1;    // Index of left child
    int right = 2 * i + 2;   // Index of right child
    int smaller = i;         // Start by assuming the current element is the smallest

    // Check if left child is within range and smaller than current element
    if (left < n && A[left].salary < A[smaller].salary) {
        smaller = left;
    }

    // Check if right child is within range and smaller than the smallest found so far
    if (right < n && A[right].salary < A[smaller].salary) {
        smaller = right;
    }

    // If the smallest salary is not the current element, swap and heapify further
    if (smaller != i) {
        swap(&A[i], &A[smaller]);

        // Heapify the affected subtree
        heapify(A, smaller, n);
    }
    // The recursion will stop when the smallest salary is at the current index
    // or when the child indices are out of the array bounds
}


/**
 * Swaps the locations of two Employees
 * @param *e1 An Employee
 * @param *e2 Another Employee to swap with
 */
void swap(Employee *e1, Employee *e2) {
    Employee temp = *e1;
    *e1 = *e2;
    *e2 = temp;
}


/**
 * Outputs an array of Employees
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
void printList(Employee *A, int n) {
    int i;

    // First, print each employee's details on separate lines
    for (i = 0; i < n; i++) {
        printf("Name: %s\nSalary: %d\n\n", A[i].name, A[i].salary);
    }

    // Then, print a summary line with all employees
    printf("[");
    for (i = 0; i < n; i++) {
        printf("id=%s sal=%d", A[i].name, A[i].salary);
        if (i < n - 1) {
            printf("], [");
        }
    }
    printf("]");
}
