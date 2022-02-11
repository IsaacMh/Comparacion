#include<iostream>
#include<algorithm>
#include<ctime>
#include<chrono>
using namespace std;

//RADIX SORT------------------------------------------------------
int getMaxx(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}
void CountingSort(int arr[], int size, int div)
{
    int output[size];
    int count[10] = {0};

    for (int i = 0; i < size; i++)
        count[ (arr[i]/div)%10 ]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = size - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/div)%10 ] - 1] = arr[i];
        count[ (arr[i]/div)%10 ]--;
    }

    for (int i = 0; i < size; i++)
        arr[i] = output[i];
}


void RadixSort(int arr[], int size)
{
    int m = getMaxx(arr, size);
    for (int div = 1; m/div > 0; div *= 10)
        CountingSort(arr, size, div);
}

// QUICK SORT-----------------------------------------------------
void swapp(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swapp(&arr[i], &arr[j]);
        }
    }
    swapp(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

//HEAPSORT--------------------------------------------------------
 void heapify(int arr[], int n, int i) {
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
      largest = left;

    if (right < n && arr[right] > arr[largest])
      largest = right;

    // Swap and continue heapifying if root is not largest
    if (largest != i) {
      swap(arr[i], arr[largest]);
      heapify(arr, n, largest);
    }
 }
  // main function to do heap sort
  void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);

    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
      swap(arr[0], arr[i]);

      // Heapify root element to get highest element at root again
      heapify(arr, i, 0);
    }
  }

  // Print an array
  void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
      cout << arr[i] << " ";
    cout << "\n";
  }


//Counting Sort------------------------------------------------------------------------------
void display(int *array, int size) {
   for(int i = 1; i<=size; i++)
      cout << array[i] << " ";
   cout << endl;
}
int getMax(int array[], int size) {
   int max = array[1];
   for(int i = 2; i<=size; i++) {
      if(array[i] > max)
         max = array[i];
   }
   return max; //the max element from the array
}
void countSort(int *array, int size) {
   int output[size+1];
   int max = getMax(array, size);
   int count[max+1];     //create count array (max+1 number of elements)
   for(int i = 0; i<=max; i++)
      count[i] = 0;     //initialize count array to all zero
   for(int i = 1; i <=size; i++)
      count[array[i]]++;     //increase number count in count array.
   for(int i = 1; i<=max; i++)
      count[i] += count[i-1];     //find cumulative frequency
   for(int i = size; i>=1; i--) {
      output[count[array[i]]] = array[i];
      count[array[i]] -= 1; //decrease count for same numbers
   }
   for(int i = 1; i<=size; i++) {
      array[i] = output[i]; //store output array to main array
   }
}
//-----------------------------------------------------------------------------------------------


int main() {

   int n;
   cout << "Enter the number of elements: ";
   cin >> n;
   int arr[n+1];       //create an array with given number of elements
   cout << "Enter elements:" << endl;
   for(int i = 1; i<=n; i++) {
      cin >> arr[i];
   }
chrono::steady_clock::time_point begin = chrono::steady_clock::now();
   cout << "Array before Sorting: ";
   display(arr, n);
   countSort(arr, n);
   cout << "COUNTING SORT: "<<endl;
   display(arr, n);

chrono::steady_clock::time_point end = chrono::steady_clock::now();

cout << "Time difference = " << chrono::duration_cast<chrono::microseconds>(end - begin).count() << "microsegundos" << endl;

chrono::steady_clock::time_point begin1 = chrono::steady_clock::now();
heapSort(arr, n+1);

cout << "HEAPSORT \n";
printArray(arr, n);
chrono::steady_clock::time_point end1 = chrono::steady_clock::now();

cout << "Time difference = " << chrono::duration_cast<chrono::microseconds>(end1 - begin1).count() << "microsegundos" << endl;
//---------------------------
chrono::steady_clock::time_point begin2 = chrono::steady_clock::now();
quickSort(arr, 0, n - 1);
    cout << "QUICKSORT: \n";
    printArray(arr, n);
chrono::steady_clock::time_point end2 = chrono::steady_clock::now();
cout << "Time difference = " << chrono::duration_cast<chrono::microseconds>(end2 - begin2).count() << "microsegundos" << endl;
chrono::steady_clock::time_point begin3 = chrono::steady_clock::now();
cout<<"RADIX SORT: "<<endl;
RadixSort(arr, n);
printArray(arr,n);
chrono::steady_clock::time_point end3 = chrono::steady_clock::now();
cout << "Time difference = " << chrono::duration_cast<chrono::microseconds>(end2 - begin2).count() << "microsegundos" << endl;



    return 0;
}

