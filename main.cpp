#include "sorting.h"
#include "DataGenerator.h"

//Write array into new file
void writeFile(string filename, int* arr, int size)
{
	ofstream ofs(filename);
	if (!ofs.is_open())
		cout << "Cannot open file! \n";
	
	else
	{
		ofs << size << '\n';
		for (int i = 0; i < size - 1; i++)
			ofs << arr[i] << " ";
		ofs << arr[size - 1];
		ofs.close();
	}
}

//Get information of algorithm
int getAlgorithm(string sort_algorithm) 
{
	if (sort_algorithm == "selection-sort")
		return 1;
	if (sort_algorithm == "insertion-sort")
		return 2;
	if (sort_algorithm == "bubble-sort")
		return 3;
	if (sort_algorithm == "heap-sort")
		return 4;
	if (sort_algorithm == "merge-sort")
		return 5;
	if (sort_algorithm == "quick-sort")
		return 6;
	if (sort_algorithm == "radix-sort")
		return 7;
	if (sort_algorithm == "shaker-sort")
		return 8;
	if (sort_algorithm == "shell-sort")
		return 9;
	if (sort_algorithm == "counting-sort")
		return 10;
	if (sort_algorithm == "flash-sort")
		return 11;
	return 0;
}

string algorithm(int algrthm) 
{
	switch (algrthm) 
	{
	case 1: return "Selection Sort";
	case 2: return "Insertion Sort";
	case 3: return "Bubble Sort";
	case 4: return "Heap Sort";
	case 5: return "Merge Sort";
	case 6: return "Quick Sort";
	case 7: return "Radix Sort";
	case 8: return "Shaker Sort";
	case 9: return "Shell Sort";
	case 10: return "Counting Sort";
	default: return "Flash Sort";
	}
}

//Get information of input order
int getInputOrder(string order) 
{
	if (order == "-rand")
		return 1;
	if (order == "-nsorted")
		return 2;
	if (order == "-sorted")
		return 3;
	if (order == "-rev")
		return 4;
	return 0;
}

string inputOrder(int ord) 
{
	switch (ord) 
	{
	case 1: return "Randomized";
	case 2: return "Nearly Sorted";
	case 3: return "Sorted";
	case 4: return "Reverse Sorted";
	}
}

//Get information of output type
int getOutputType(string output_type) {
	if (output_type == "-time")
		return 1;
	if (output_type == "-comp")
		return 2;
	if (output_type == "-both")
		return 3;
	return 0;
}

//Sort array
void sortAlgorithm(int* arr, int size, int algrthm)
{
	int r = arr[0];
	for (int i = 1; i < size; i++) {
		if (arr[i] > r) {
			r = arr[i];
		}
	}
	r++;
	switch (algrthm) {
	case 1:	 selectionSort(arr, size);		break;
	case 2:  insertionSort(arr, size);		break;
	case 3:  bubbleSort(arr, size);			break;
	case 4:  shakerSort(arr, size);			break;
	case 5:  shellSort(arr, size);			break;
	case 6:  heapSort(arr, size); 			break;
	case 7:  mergeSort(arr, 0, size - 1);	break;
	case 8:  quickSort(arr, 0, size - 1);	break;
	case 9:  countingSort(arr, size, r);	break;
	case 10: radixSort(arr, size);			break;
	case 11: flashSort(arr, size);			break;
	}
}

//Get runtime of algorithm
void runAlgorithm(int* arr, int size, int algrthm, double& runtime)
{
	switch (algrthm) {
	case 1:	 runSelectionSort(arr, size, runtime);	break;
	case 2:  runInsertionSort(arr, size, runtime);	break;
	case 3:  runBubbleSort(arr, size, runtime);		break;
	case 4:  runShakerSort(arr, size, runtime);		break;
	case 5:  runShellSort(arr, size, runtime);		break;
	case 6:  runHeapSort(arr, size, runtime); 		break;
	case 7:  runMergeSort(arr, size, runtime);		break;
	case 8:  runQuickSort(arr, size, runtime);		break;
	case 9:  runCountingSort(arr, size, runtime);	break;
	case 10: runRadixSort(arr, size, runtime);		break;
	case 11: runFlashSort(arr, size, runtime);		break;
	}
}

//Get comparisons of algorithm
void countAlgorithm(int* arr, int size, int algrthm, long long& count_compare)
{
	int r = arr[0];
	for (int i = 1; i < size; i++) {
		if (arr[i] > r) {
			r = arr[i];
		}
	}
	r++;
	switch (algrthm) {
	case 1:	 countSelectionSort(arr, size, count_compare);		break;
	case 2:  countInsertionSort(arr, size, count_compare);		break;
	case 3:  countBubbleSort(arr, size, count_compare);			break;
	case 4:  countShakerSort(arr, size, count_compare);			break;
	case 5:  countShellSort(arr, size, count_compare);			break;
	case 6:  countHeapSort(arr, size, count_compare); 			break;
	case 7:  countMergeSort(arr, 0, size - 1, count_compare);	break;
	case 8:  countQuickSort(arr, 0, size - 1, count_compare);	break;
	case 9:  countCountingSort(arr, size, r, count_compare);	break;
	case 10: countRadixSort(arr, size, count_compare);			break;
	case 11: countFlashSort(arr, size, count_compare);			break;
	}
}

//Output on command line
void output(int output_type, double runtime, long long count_compare)
{
	switch (output_type) {
	case 1:
		cout << "Running time: " << runtime << "ms" << endl;
		break;
	case 2:
		cout << "Comparisons: " << count_compare << endl;
		break;
	default:
		cout << "Running time: " << runtime << "ms" << endl;
		cout << "Comparisons: " << count_compare << endl;
		break;
	}
}

void cmd2 (int algrthm, string sort_algorithm, int size, int order, int output_type) 
{
	int* arr = new int[size];
	GenerateData(arr, size, order - 1);
	writeFile("input.txt", arr, size);
	sortAlgorithm(arr, size, algrthm);
	writeFile("output.txt", arr, size);

	cout << "ALGORITHM MODE \n";
	cout << "Algorithm: " << algorithm(algrthm) << endl;
	cout << "Input size: " << size << endl;
	cout << "Input order: " << inputOrder(order) << endl;

	for (int i = 0; i < 25; i++)
		cout << "-";
	cout << endl;

	double runtime = 0;
	runAlgorithm(arr, size, algrthm, runtime);
	long long count_compare = 0;
	countAlgorithm(arr, size, algrthm, count_compare);
	output(output_type, runtime, count_compare);
}

int main(int argc, char* argv[]) 
{
	if (argc == 6) 
	{
		if (string(argv[1]) == "-a") 
		{
			int algrthm = getAlgorithm(argv[2]);
			if (atoi(argv[3]) > 1000000 || atoi(argv[3]) <= 0)
				return 0;
			int order = getInputOrder(string(argv[4]));
			int output_type = getOutputType(string(argv[5]));
			if (order && output)
				cmd2(algrthm, argv[2], atoi(argv[3]), order, output_type);
		}
	}
	else
	{
		cout << "Wrong syntaxes! Usage: \n";
		cout << "<Execution file> -a <Algorithm> <Input size> -<Input order> -<Output parameter(s)> \n";
	}

	return 0;
}
