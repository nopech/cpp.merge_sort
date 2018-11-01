#include <iostream>

void merge(int T[], int l, int m, int r) {
    int i, j, k;
    int nl = m-l+1;
    int nr = r-m;
    int L[nl];
    int R[nr];
    
    for(int i=0; i<nl; i++) {
        L[i] = T[l+i];
    }
    for(int j=0; j<nr; j++) {
        R[j] = T[m+1+j];
    }
    
    i = 0; // first index of left subarray
    j = 0; // first index of right subarray
    k = l; // first index of merged subarray
    
    while(i < nl && j < nr) {
        if(L[i] <= R[j]) {
            T[k] = L[i];
            i++;
        }
        else {
            T[k] = R[j];
            j++;
        }
        k++;
    }
    
    while(i < nl) {
        T[k] = L[i];
        i++;
        k++;
    }
    
    while(j < nr) {
        T[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int T[], int l, int r) {
    if (l<r) {
        int m = l+(r-l)/2;
        mergeSort(T,l,m);
        mergeSort(T,m+1,r);
        
        merge(T,l,m,r);
    }
}

int main() {
    // Define values to sort
    int T[20] = {6, 5, 8, 9, 1, 3, 2, 4, 7, 16, 19, 14, 12, 10, 11, 17, 15, 13, 18, 20};
    int size = sizeof(T)/sizeof(T[0]);
    
    std::cout << "Unsorted array:" << std::endl;
    for (int i=0; i<size; i++) {
        std::cout << T[i] << " ";
    }
    std::cout << std::endl;
    
    mergeSort(T, 0, size-1);
    
    std::cout << "Sortet array:" << std::endl;
    for (int i=0; i<size; i++) {
            std::cout << T[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}