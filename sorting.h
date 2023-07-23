#pragma once
#include <iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include <chrono>

void swap(int& a, int& b);

//Original sort function
void selectionSort(int* a, int n);
void insertionSort(int* a, int n);
void bubbleSort(int* a, int n);
void heapify(int* a, int n, int i);
void heapSort(int* a, int n);
void merge(int* a, int first, int mid, int last);
void mergeSort(int* a, int first, int last);
int medianOfThree(int* a, int left, int right);
void quickSort(int* a, int left, int right);
int getMaxDigit(int* a, int n);
int digit(int a, int k);
void radixCounting(int* a, int n, int k);
void radixSort(int* a, int n);
void shakerSort(int* a, int n);
void shellSort(int* a, int n);
void radixSort(int* a, int n);
void countingSort(int* input_array, int n, int r);
void flashSort(int* a, int n);

//Running time function
void runSelectionSort(int* a, int n, double& runtime);
void runInsertionSort(int* a, int n, double& runtime);
void runBubbleSort(int* a, int n, double& runtime);
void runHeapSort(int* a, int n, double& runtime);
void runMergeSort(int* a, int n, double& runtime);
void runQuickSort(int* a, int n, double& runtime);
void runRadixSort(int* a, int n, double& runtime);
void runShakerSort(int* a, int n, double& runtime);
void runShellSort(int* a, int n, double& runtime);
void runCountingSort(int* a, int n, double& runtime);
void runFlashSort(int* a, int n, double& runtime);

//Counting comparisons function
void countSelectionSort(int* a, int n, long long& count_compare);
void countInsertionSort(int* a, int n, long long& count_compare);
void countBubbleSort(int* a, int n, long long& count_compare);
void countHeapify(int* a, int n, int i, long long& count_compare);
void countHeapSort(int* a, int n, long long& count_compare);
void countMerge(int* a, int first, int mid, int last, long long& count_compare);
void countMergeSort(int* a, int first, int last, long long& count_compare);
int countMedianOfThree(int* a, int left, int right, long long& count_compare);
void countQuickSort(int* a, int left, int right, long long& count_compare);
int countGetMaxDigit(int* a, int n, long long& count_compare);
int countDigit(int a, int k, long long& count_compare);
void countRadixCounting(int* a, int n, int k, long long& count_compare);
void countRadixSort(int* a, int n, long long& count_compare);
void countShakerSort(int* a, int n, long long& count_compare);
void countShellSort(int* a, int n, long long& count_compare);
void countCountingSort(int* input_array, int n, int r, long long& count_compare);
void countFlashSort(int* a, int n, long long& count_compare);