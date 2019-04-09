#include <stdio.h>

int binsearch(int x, int v[], int n);


int main()
{
    int in_order_numbers[] = {1,2,3,7,8,9};
    int place = binsearch(3, in_order_numbers, 6);
    if (place != -1) 
        printf("%d\n", in_order_numbers[place]);
    else
        printf("%s\n", "Not Found!");
    return 0;
}

int binsearch(int x, int v[], int n){
    int low, high, mid;

    low = 0;
    high = n - 1;
    while(low <= high){
        mid = (low+high) / 2;
        if (x < v[mid]) 
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else    /* found match */
            return mid;
    }
    return -1;  /* no match */
}

