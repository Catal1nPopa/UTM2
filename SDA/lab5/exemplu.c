// void quick_sort (int *a, int n) {
//     if (n < 2)
//         return;
//     int p = a[n / 2];
//     int *l = a;
//     int *r = a + n - 1;
//     while (l <= r) {
//         if (*l < p) {
//             l++;
//         }
//         else if (*r > p) {
//             r--;
//         }
//         else {
//             int t = *l;
//             *l = *r;
//             *r = t;
//             l++;
//             r--;
//         }
//     }
//     quick_sort(a, r - a + 1);
//     quick_sort(l, a + n - l);
// }
//
// int main () {
//     int a[] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1};
//     int n = sizeof a / sizeof a[0];
//     quick_sort(a, n);
//     printf("%d", a[]);
//     return 0;
// }
//
// }
//
//
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <time.h>


int main()
{
    int array[10];
    int x, p;
    int count;
    int i=0;

    srand(time(NULL));

    for(count=0;count<10;count++){
        array[count]=rand()%10+1;
    }

    while(i<10){
        int r=rand()%10+1;

        for (x = 0; x < i; x++)
        {
            if(array[x]==r){
                break;
            }
        }
        if(x==i){
            array[i++]=r;
        }
    }
    for(p=0;p<10;p++){
        printf("%d ", array[p]);
    }
    return 0;
}
