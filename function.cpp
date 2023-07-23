#include "sorting.h"
#include "DataGenerator.h"

//Swap 2 elements
void swap(int& a, int& b)
{
	int x = a;
	a = b;
	b = x;
}

//////////////////////////////////////////////////////////////////////
//Original sort function
//Selection sort 
void selectionSort(int* a, int n)
{
	int i, j, min_idx;
	for (i = 0; i < n - 1; i++) {
		min_idx = i;
		for (j = i + 1; j < n; j++) {
			if (a[j] < a[min_idx])
				min_idx = j;
		}
		if (min_idx != i) {
			swap(a[min_idx], a[i]);
		}
	}
}

//Insertion sort 
void insertionSort(int* a, int n)
{
	for (int i = 1; i < n; i++)
	{
		int j = i - 1;
		int key = a[i];
		while (a[j] > key && j >= 0)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}

//Bubble sort 
void bubbleSort(int* a, int n)
{
	for (int i = n - 1; i >= 0; i--)
	{
		bool swapped = false;
		//day max ve cuoi mang
		for (int j = 0; j < i; j++)
			if (a[j] > a[j + 1])
			{
				swapped = true;
				swap(a[j], a[j + 1]);
			}
		if (!swapped)
			return;
	}
}

//Heap sort 
void heapify(int* a, int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n && a[l] > a[largest])
		largest = l;
	if (r < n && a[r] > a[largest])
		largest = r;
	if (largest != i) {
		swap(a[i], a[largest]);
		heapify(a, n, largest);
	}
}

void heapSort(int* a, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(a, n, i);
	for (int i = n - 1; i > 0; i--) {
		swap(a[0], a[i]);
		heapify(a, i, 0);
	}
}

//Merge sort 
void merge(int* a, int first, int mid, int last)
{
	int n1 = mid - first + 1;
	int n2 = last - mid;
	int* L = new int[n1];
	int* R = new int[n2];
	for (int i = 0; i < n1; i++)
		L[i] = a[first + i];
	for (int j = 0; j < n2; j++)
		R[j] = a[mid + j + 1];
	int i = 0;
	int j = 0;
	int k = first;
	while (i < n1 && j < n2)
		a[k++] = (L[i] < R[j]) ? L[i++] : R[j++];

	while (j < n2)
		a[k++] = R[j++];
	while (i < n1)
		a[k++] = L[i++];
	delete[] L;
	delete[] R;
}

void mergeSort(int* a, int first, int last)
{
	if (first < last)
	{

		int mid = first + (last - first) / 2;
		mergeSort(a, first, mid);
		mergeSort(a, mid + 1, last);
		merge(a, first, mid, last);
	}
}

//Quick sort 
int medianOfThree(int* a, int left, int right) 
{
	int middle = left + (right - left) / 2;
	if (a[left] > a[middle]) {
		swap(a[left], a[middle]);
	}
	if (a[left] > a[right]) {
		swap(a[left], a[right]);
	}
	if (a[middle] > a[right]) {
		swap(a[middle], a[right]);
	}
	return middle;
}

void quickSort(int* a, int left, int right) 
{
	if (left >= right) {
		return;
	}

	int pivotIndex = medianOfThree(a, left, right);
	int pivot = a[pivotIndex];

	int i = left;
	int j = right;
	while (i <= j) {
		while (a[i] < pivot) {
			i++;
		}
		while (a[j] > pivot) {
			j--;
		}
		if (i <= j) {
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}

	quickSort(a, left, j);
	quickSort(a, i, right);
}

//Radix sort 
int getMaxDigit(int* a, int n)
{
	int maxx = INT_MIN, count = 0;
	for (int i = 0; i < n; i++)
		if (a[i] > maxx)
			maxx = a[i];
	while (maxx > 0)
	{
		count++;
		maxx = maxx / 10;
	}
	return count;
}

int digit(int a, int k)
{
	int digitK = 0;
	for (int i = 1; i <= k; i++)
		if (a > 0)
		{
			digitK = a % 10;
			a = a / 10;
		}
		else return 0;
	return digitK;
}

void radixCounting(int* a, int n, int k)
{
	int numberDigit[10] = { 0 };
	int* b = new int[n];
	for (int i = 0; i < n; i++) {
		numberDigit[digit(a[i], k)]++;
	}
	for (int i = 1; i < 10; i++) {
		numberDigit[i] += numberDigit[i - 1];
	}
	for (int i = n - 1; i >= 0; i--) {
		int j = digit(a[i], k);
		b[numberDigit[j]] = a[i];
		numberDigit[j]--;
	}
	for (int i = 1; i <= n; i++) {
		a[i - 1] = b[i];
	}
	delete[] b;
}

void radixSort(int* a, int n)
{
	int Maxdigit = getMaxDigit(a, n);
	for (int i = 1; i <= Maxdigit; i++) {
		radixCounting(a, n, i);
	}
}

//Shaker sort 
void shakerSort(int* a, int n)
{
	bool swapped = true;
	int start = 0;
	int end = n - 1;

	while (swapped) {
		swapped = false;
		for (int i = start; i < end; ++i) {
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				swapped = true;
			}
		}
		if (!swapped)
			break;
		swapped = false;
		--end;
		for (int i = end - 1; i >= start; --i) {
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				swapped = true;
			}
		}
		++start;
	}
}

//Shell sort 
void shellSort(int* a, int n)
{
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; i += 1)
		{
			int temp = a[i];
			int j;
			for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
				a[j] = a[j - gap];
			a[j] = temp;
		}
	}
}

//Counting sort 
void countingSort(int* input_array, int n, int r)
{
	int* output_array;
	output_array = new int[n];
	int* count_array;
	count_array = new int[r]();

	for (int i = 0; i < n; i++) {
		++count_array[input_array[i]];
	}
	for (int i = 1; i < r; i++) {
		count_array[i] += count_array[i - 1];
	}
	for (int i = n - 1; i >= 0; i--) {
		output_array[--count_array[input_array[i]]] = input_array[i];
	}
	for (int i = 0; i < n; i++) {
		input_array[i] = output_array[i];
	}

	delete[] output_array;
	delete[] count_array;
}

//Flash sort 
void flashSort(int* a, int n)
{
	int minVal = a[0];
	int max = 0;
	int m = int(0.45 * n);
	int* l = new int[m];
	for (int i = 0; i < m; i++)
		l[i] = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] < minVal)
			minVal = a[i];
		if (a[i] > a[max])
			max = i;
	}
	if (a[max] == minVal)
		return;
	double c1 = (double)(m - 1) / (a[max] - minVal + 1);
	for (int i = 0; i < n; i++) {
		int k = int(c1 * (a[i] - minVal));
		++l[k];
	}
	for (int i = 1; i < m; i++)
		l[i] += l[i - 1];
	swap(a[max], a[0]);
	int nmove = 0;
	int j = 0;
	int k = m - 1;
	int t = 0;
	int flash;
	while (nmove < n - 1) {
		while (j > l[k] - 1) {
			j++;
			k = int(c1 * (a[j] - minVal));
		}
		flash = a[j];
		if (k < 0) break;
		while (j != l[k]) {
			k = int(c1 * (flash - minVal));
			int hold = a[t = --l[k]];
			a[t] = flash;
			flash = hold;
			++nmove;
		}
	}
	delete[] l;
	insertionSort(a, n);
}

//////////////////////////////////////////////////////////////////////
//Running time function
//Selection sort
void runSelectionSort(int* a, int n, double& runtime)
{
	auto start = chrono::high_resolution_clock::now();

	selectionSort(a, n);

	auto end = chrono::high_resolution_clock::now();
	runtime = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

//Insertion sort
void runInsertionSort(int* a, int n, double& runtime)
{
	auto start = chrono::high_resolution_clock::now();

	insertionSort(a, n);

	auto end = chrono::high_resolution_clock::now();
	runtime = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

//Buble sort
void runBubbleSort(int* a, int n, double& runtime)
{
	auto start = chrono::high_resolution_clock::now();

	bubbleSort(a, n);

	auto end = chrono::high_resolution_clock::now();
	runtime = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

//Heap sort	
void runHeapSort(int* a, int n, double& runtime)
{
	auto start = chrono::high_resolution_clock::now();

	heapSort(a, n);

	auto end = chrono::high_resolution_clock::now();
	runtime = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

//Merge sort
void runMergeSort(int* a, int n, double& runtime)
{
	auto start = chrono::high_resolution_clock::now();

	mergeSort(a, 0, n - 1);

	auto end = chrono::high_resolution_clock::now();
	runtime = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

//Quick sort
void runQuickSort(int* a, int n, double& runtime)
{
	auto start = chrono::high_resolution_clock::now();

	quickSort(a, 0, n - 1);

	auto end = chrono::high_resolution_clock::now();
	runtime = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

//Radix sort
void runRadixSort(int* a, int n, double& runtime)
{
	auto start = chrono::high_resolution_clock::now();

	radixSort(a, n);

	auto end = chrono::high_resolution_clock::now();
	runtime = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

//Shaker sort
void runShakerSort(int* a, int n, double& runtime)
{
	auto start = chrono::high_resolution_clock::now();

	shakerSort(a, n);

	auto end = chrono::high_resolution_clock::now();
	runtime = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

//Shell sort
void runShellSort(int* a, int n, double& runtime)
{
	auto start = chrono::high_resolution_clock::now();

	shellSort(a, n);

	auto end = chrono::high_resolution_clock::now();
	runtime = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

//Counting sort
void runCountingSort(int* a, int n, double& runtime)
{
	int r = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > r) {
			r = a[i];
		}
	}
	r++;

	auto start = chrono::high_resolution_clock::now();

	countingSort(a, n, r);

	auto end = chrono::high_resolution_clock::now();
	runtime = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

//Flash sort
void runFlashSort(int* a, int n, double& runtime)
{
	auto start = chrono::high_resolution_clock::now();

	flashSort(a, n);

	auto end = chrono::high_resolution_clock::now();
	runtime = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

//////////////////////////////////////////////////////////////////////
//Counting comparisons function
//Selection sort
void countSelectionSort(int* a, int n, long long& count_compare)
{
	int i, j, min_idx;
	for (i = 0; ++count_compare && i < n - 1; i++) {
		min_idx = i;
		for (j = i + 1; ++count_compare && j < n; j++) {
			if (++count_compare && a[j] < a[min_idx])
				min_idx = j;
		}
		if (++count_compare && min_idx != i)
			swap(a[min_idx], a[i]);
	}
}

//Insertion sort
void countInsertionSort(int* a, int n, long long& count_compare)
{
	for (int i = 1; ++count_compare && i < n; i++) {
		int key = a[i];
		int j = i - 1;
		while (++count_compare && a[j] > key && ++count_compare && j >= 0)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}

//Bubble sort
void countBubbleSort(int* a, int n, long long& count_compare)
{
	for (int i = n - 1; ++count_compare && i >= 0; i--)
	{
		bool swapped = false;
		for (int j = 0; ++count_compare && j < i; j++)
			if (++count_compare && a[j] > a[j + 1])
			{
				swapped = true;
				swap(a[j], a[j + 1]);
			}
		if (!swapped)
			return;
	}
}

//Heap sort
void countHeapify(int* a, int n, int i, long long& count_compare)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (++count_compare && l < n && ++count_compare && a[l] > a[largest])
		largest = l;
	if (++count_compare && r < n && ++count_compare && a[r] > a[largest])
		largest = r;
	if (++count_compare && largest != i) {
		swap(a[i], a[largest]);
		countHeapify(a, n, largest, count_compare);
	}
}

void countHeapSort(int* a, int n, long long& count_compare)
{
	for (int i = n / 2 - 1; ++count_compare && i >= 0; i--)
		countHeapify(a, n, i, count_compare);
	for (int i = n - 1; ++count_compare && i > 0; i--) {
		swap(a[0], a[i]);
		countHeapify(a, i, 0, count_compare);
	}
}

//Merge sort
void countMerge(int* a, int first, int mid, int last, long long& count_compare)
{
	int n1 = mid - first + 1;
	int n2 = last - mid;
	int* L = new int[n1];
	int* R = new int[n2];
	for (int i = 0; ++count_compare && i < n1; i++)
		L[i] = a[first + i];
	for (int j = 0; ++count_compare && j < n2; j++)
		R[j] = a[mid + j + 1];
	int i = 0;
	int j = 0;
	int k = first;
	while (++count_compare && i < n1 && ++count_compare && j < n2)
		a[k++] = (L[i] < R[j]) ? L[i++] : R[j++];
	count_compare++;
	while (++count_compare && j < n2)
		a[k++] = R[j++];
	while (++count_compare && i < n1)
		a[k++] = L[i++];
	delete[] L;
	delete[] R;
}

void countMergeSort(int* a, int first, int last, long long& count_compare)
{
	if (first < last)
	{
		int mid = first + (last - first) / 2;
		countMergeSort(a, first, mid, count_compare);
		countMergeSort(a, mid + 1, last, count_compare);
		countMerge(a, first, mid, last, count_compare);
	}
}

//Quick sort
int countMedianOfThree(int* a, int left, int right, long long& count_compare)
{
	int mid = (left + right) / 2;

	if (++count_compare && a[left] > a[mid]) {
		swap(a[left], a[mid]);
	}
	if (++count_compare && a[left] > a[right]) {
		swap(a[left], a[right]);
	}
	if (++count_compare && a[mid] > a[right]) {
		swap(a[mid], a[right]);
	}
	return a[mid];
}

void countQuickSort(int* a, int left, int right, long long& count_compare)
{
	if (left >= right)
		return;

	int pivot = countMedianOfThree(a, left, right, count_compare);

	int i = left;
	int j = right;
	while (++count_compare && i <= j) {
		while (++count_compare && a[i] < pivot)
			i++;

		while (++count_compare && a[j] > pivot)
			j--;

		if (++count_compare && i <= j) {
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}

	countQuickSort(a, left, j, count_compare);
	countQuickSort(a, i, right, count_compare);
}

//Radix sort
int countGetMaxDigit(int* a, int n, long long& count_compare)
{
	int maxx = INT_MIN, count = 0;
	for (int i = 0; ++count_compare && i < n; i++)
		if (++count_compare && a[i] > maxx)
			maxx = a[i];
	while (++count_compare && maxx > 0)
	{
		count++;
		maxx = maxx / 10;
	}
	return count;
}

int countDigit(int a, int k, long long& count_compare)
{
	int digitK = 0;
	for (int i = 1; ++count_compare && i <= k; i++)
		if (++count_compare && a > 0)
		{
			digitK = a % 10;
			a = a / 10;
		}
		else return 0;
	return digitK;
}

void countRadixCounting(int* a, int n, int k, long long& count_compare)
{
	int numberDigit[10] = { 0 };
	int* b = new int[n];
	for (int i = 0; ++count_compare && i < n; i++) {
		numberDigit[countDigit(a[i], k, count_compare)]++;
	}
	for (int i = 1; ++count_compare && i < 10; i++) {
		numberDigit[i] += numberDigit[i - 1];
	}
	for (int i = n - 1; ++count_compare && i >= 0; i--) {
		int j = countDigit(a[i], k, count_compare);
		b[numberDigit[j]] = a[i];
		numberDigit[j]--;
	}
	for (int i = 1; ++count_compare && i <= n; i++) a[i - 1] = b[i];
	delete[] b;
}

void countRadixSort(int* a, int n, long long& count_compare)
{
	int Maxdigit = countGetMaxDigit(a, n, count_compare);
	for (int i = 1; ++count_compare && i <= Maxdigit; i++) {
		countRadixCounting(a, n, i, count_compare);
	}
}

//Shaker sort
void countShakerSort(int* a, int n, long long& count_compare)
{
	bool swapped = true;
	int start = 0;
	int end = n - 1;

	while (++count_compare && swapped) {
		swapped = false;
		for (int i = start; ++count_compare && i < end; ++i) {
			if (++count_compare && a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				swapped = true;
			}
		}
		if (++count_compare && !swapped)
			break;
		swapped = false;
		--end;
		for (int i = end - 1; ++count_compare && i >= start; --i) {
			if (++count_compare && a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				swapped = true;
			}
		}
		++start;
	}
}

//Shell sort
void countShellSort(int* a, int n, long long& count_compare)
{
	for (int gap = n / 2; ++count_compare && gap > 0; gap /= 2)
	{
		for (int i = gap; ++count_compare && i < n; i++)
		{
			int temp = a[i];
			int j;
			for (j = i; ++count_compare && j >= gap && ++count_compare && a[j - gap] > temp; j -= gap)
			{
				a[j] = a[j - gap];
			}
			a[j] = temp;
		}
	}
}

//Counting sort
void countCountingSort(int* input_array, int n, int r, long long& count_compare)
{
	count_compare = 0;
	int* output_array;
	output_array = new int[n];
	int* count_array;
	count_array = new int[r];
	for (int i = 0; ++count_compare && i < r; i++) {
		count_array[i] = 0;
	}
	for (int i = 0; ++count_compare && i < n; i++) {
		++count_array[input_array[i]];
	}
	for (int i = 1; ++count_compare && i < r; i++) {
		count_array[i] = count_array[i] + count_array[i - 1];
	}
	for (int i = 0; ++count_compare && i < n; i++) {
		output_array[--count_array[input_array[i]]] = input_array[i];
	}
	for (int i = 0; ++count_compare && i < n; i++) {
		input_array[i] = output_array[i];
	}
}

//Flash sort
void countFlashSort(int* a, int n, long long& count_compare)
{
	int minVal = a[0];
	int max = 0;
	int m = int(0.45 * n);
	int* l = new int[m];
	for (int i = 0; ++count_compare && i < m; i++)
		l[i] = 0;
	for (int i = 1; ++count_compare && i < n; i++)
	{
		if (++count_compare && a[i] < minVal)
			minVal = a[i];
		if (++count_compare && a[i] > a[max])
			max = i;
	}
	if (++count_compare && a[max] == minVal)
		return;
	double c1 = (double)(m - 1) / (a[max] - minVal + 1);
	for (int i = 0; ++count_compare && i < n; i++)
	{
		int k = int(c1 * (a[i] - minVal));
		++l[k];
	}
	for (int i = 1; ++count_compare && i < m; i++)
		l[i] += l[i - 1];
	swap(a[max], a[0]);
	int nmove = 0;
	int j = 0;
	int k = m - 1;
	int t = 0;
	int flash;
	while (++count_compare && nmove < n - 1)
	{
		while (++count_compare && j > l[k] - 1)
		{
			j++;
			k = int(c1 * (a[j] - minVal));
		}
		flash = a[j];
		if (++count_compare && k < 0) break;
		while (++count_compare && j != l[k])
		{
			k = int(c1 * (flash - minVal));
			int hold = a[t = --l[k]];
			a[t] = flash;
			flash = hold;
			++nmove;
		}
	}
	delete[] l;
	countInsertionSort(a, n, count_compare);
}