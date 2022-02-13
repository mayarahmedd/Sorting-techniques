#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>




void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


void selectionSort(int array[], int size)
{
    for (int step = 0; step < size - 1; step++)
    {
        int min_idx = step;
        for (int i = step + 1; i < size; i++)
        {
            // Select the minimum element in each loop.
            if (array[i] < array[min_idx])
                min_idx = i;
        } // put min at the correct position
        swap(&array[min_idx], &array[step]);
    }
}



void insertionSort(int arr[], int n)

{

    int i, j,key;

    for (i = 1; i < n; i++)
    {
        key=arr[i];
        j=i-1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }

}



void bubbleSort(int arr[], int n)

{

    int i,j;
    for(i=0; i<n-1; i++)
    {
        for (j=0; j<n-i-1; j++)
        {
            if(arr[j]>arr[j+1])
                swap(&arr[j],&arr[j+1]);
        }
    }
}


void merge(int arr[], int l, int m, int r)

{
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;/* create temp arrays */
    int L[n1],R[n2];/* Copy data to temp arrays L[] and R[] */
    for(i=0; i<n1; i++)
    {
        L[i]=arr[l+i];
    }
    for(j=0; j<n2; j++)
    {
        R[j]=arr[m+1+j];
    }/* Merge the temp arrays back into arr[l..r]*/
    i=0;
    j=0;
    k=l;
    while(i<n1&&j<n2)
    {
        if(L[i]<=R[j])
        {
            arr[k]=L[i];
            i++;
        }
        else
        {
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r)

{

    if (l < r)
    {

        // Same as (l+r)/2, but avoids overflow for

        // large l and h

        int m = l + (r - l) / 2;



        // Sort first and second halves

        mergeSort(arr, l, m);

        mergeSort(arr, m + 1, r);



        merge(arr, l, m, r);

    }

}



int partition(int arr[],int first,int last)
{
    int lasts1=first;
    int firstUnknown=first+1;
    while(firstUnknown<=last)
    {
        if(arr[firstUnknown]<arr[first])
        {
            lasts1=lasts1+1;
            swap(&arr[firstUnknown], &arr[lasts1]);
        }
        firstUnknown=firstUnknown+1;
    }
    swap(&arr[first], &arr[lasts1]);
    return lasts1;
}

void quicksort(int arr[],int first,int last)
{
    int q;

    if(first<last)
    {
        q=partition(arr,first,last);
        quicksort( arr, first, q-1);
        quicksort( arr, q+1, last);
    }
}


void heapify(int arr[], int n, int i)
{
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right; // Swap and continue heapifying if root is not largest
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--) // Build max heap
        heapify(arr, n, i); // Heap sort
    for (int i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]); // Heapify root element to get highest element at root again
        heapify(arr, i, 0);
    }
}


void printArray(int array[], int size,char* choice)
{


    char*str1="Y";

    if(strcasecmp(str1, choice)==0)
    {
        printf("Sorted array:\n");
        for (int i = 0; i < size; ++i)
        {
            printf("%d ", array[i]);
        }
        printf("\n");
    }
}
void Copy(int array[],int temp[],int n)
{
    for (int i=0; i<n; i++)
        temp[i]=array[i];

}
int * getRandom(int size )
{

    int *r=(int*)malloc(size*4),i;
    if(r==NULL)
    {
        printf("allocatio failure");
        exit(1);
    }


    for ( int i = 0; i < size; ++i)
    {
        r[i] = rand();

    }
    return r;
}
char* checkChoice(char *choice )
{
    char str1[]="Y";
    char str2[]="N";


    while(strcasecmp(str1, choice)!=0&&strcasecmp(str2, choice)!=0)
    {

        printf("please re- choose (Y/N) \n");
        gets(choice);

    }
    return choice;
}
int main()
{
    int *array;
    int *temp=NULL;
    int size;
    char choice[4];
    clock_t t;
    double time_taken;
    for(size=10000; size<=150000; size=size+35000)
    {

        printf("Do you want to print the folloing sorted array of size %d  choose (Y/N) \n",size);

    gets(choice);



    strcpy(choice,checkChoice(choice));

        printf("array of the following size:   %d \n",size);
        array = getRandom(size);
        temp=realloc(temp,size*4);


        Copy(array,temp,size);
        t = clock();
        selectionSort(temp, size);
        t = clock() - t;
        time_taken = ((double)t)/CLOCKS_PER_SEC; // calculate the elapsed time
        printf("The program of selection sort took %Lf seconds to execute\n", time_taken);

        printArray(temp, size,choice);




        Copy(array,temp,size);
        t = clock();
        insertionSort(temp, size);
        t = clock() - t;
        time_taken = ((double)t)/CLOCKS_PER_SEC; // calculate the elapsed time
        printf("The program of insertionSort took %Lf seconds to execute\n", time_taken);
        printArray(temp, size,choice);





        Copy(array,temp,size);
        t = clock();
        bubbleSort(temp, size);
        t = clock() - t;
        time_taken = ((double)t)/CLOCKS_PER_SEC; // calculate the elapsed time
        printf("The program of bubbleSort took %Lf seconds to execute\n", time_taken);
        printArray(temp, size,choice);




        Copy(array,temp,size);
        t = clock();
        mergeSort(temp, 0,size-1);
        t = clock() - t;
        time_taken = ((double)t)/CLOCKS_PER_SEC; // calculate the elapsed time
        printf("The program of mergeSort took %Lf seconds to execute\n", time_taken);
        printArray(temp, size,choice);


        Copy(array,temp,size);
        t = clock();
        quicksort(temp,  0,size-1);
        t = clock() - t;
        time_taken = ((double)t)/CLOCKS_PER_SEC; // calculate the elapsed time
        printf("The program of quicksort took %Lf seconds to execute\n", time_taken);
        printArray(temp, size,choice);


        Copy(array,temp,size);
        t = clock();
        heapSort(temp, size);
        t = clock() - t;
        time_taken = ((double)t)/CLOCKS_PER_SEC; // calculate the elapsed time
        printf("The program of heapSort took %Lf seconds to execute \n", time_taken);
        printArray(temp, size,choice);



    }
    free(temp);

    return 0;
}




