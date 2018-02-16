#include <iostream>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <ctime>

using namespace std;


int minDistance(int a[], int n, long long & operations){
    operations = 0L;
    int dmin = LONG_MAX;  // Inf
    for ( int i = 0 ; i < n ; i++ ){
        for ( int j = 0 ; j < n ; j++ ){
            if ( i != j ){
                // We separated the condition to count the
                // access to the array ONLY when it really happens.
                operations ++;
                if ( abs(a[i] - a[j]) < dmin ){
                    operations ++;
                    dmin = abs(a[i] - a[j]);
                }
            }
        }
    }

    return dmin;
}

int minDistance2(int a[], int n, long long & operations){
    operations = 0L;
    int dmin = LONG_MAX;  // Inf
    for ( int i = 0 ; i < n - 1 ; i++ ){
        for ( int j = i + 1 ; j < n ; j++ ){
            operations ++; // counter
            int temp = abs(a[i] - a[j]);
            if ( temp < dmin ){
                dmin = temp;
            }
        }
    }

    return dmin;
}

int main()
{
    srand((unsigned)time(0));
    int a [100000];
    int sizes [] = {5, 20, 50, 100, 300, 500, 1000, 5000, 10000, 20000000};
    int sizesn = 10;

    for (int i = 0 ; i < sizesn ; i++ ){
        for ( int j = 0 ; j < sizes[i] ; j++ ){
            a[j] = (rand()%1000000);
        }
        long long operations = 0;
        long long operations2 = 0;

        int time1start = 0;
        int time1end = 0;
        int delta1 = 0;
        int time2start = 0;
        int time2end = 0;
        int delta2 = 0;

        for ( int j = 0 ; j < 100 ; j++ ){
            time1start = clock();
            //minDistance(a, sizes[i], operations);
            time1end = clock();
            time2start = clock();
            minDistance2(a, sizes[i], operations2);
            time2end = clock();
            delta1 += (time1end - time1start);
            delta2 += (time2end - time2start);
        }


        cout << "Size: " << sizes[i];
        cout << ", Operations 1: " << operations;
        cout << ", Operations 2: " << operations2;
        cout << " Time 1: " << (delta1 / 100.0);
        cout << " Time 2: " << (delta2 / 100.0) << endl;

    }

    return 0;
}
