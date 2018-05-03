/**************************************************************************
Date: 2018/3/26 StatMech Assignment 1 (due to 3/29)

Problem 0: One die with 6 sides

Environment: gcc-4.7 up (use C++11)

- Zlin Tsai. s106022501@m106.nthu.edu.tw
***************************************************************************/
#include <iostream>
#include <random>
#include <time.h>
#include <iomanip>

using namespace std;

class Dice
{
    private:
        int sides;

	public:
        Dice(int);
        vector<int> histogram;
        void roll(int);
};

Dice::Dice(int s)
{
    sides = s;
    histogram.assign(s, 0);                     // remember c++ start 0 (0, 1, 2, 3, 4, 5 for s = 6) 
}

void Dice::roll(int times)
{
    double start = 0, end = 0;                  // set time clock
    histogram.assign(sides, 0);                 // reset histogram to 0
    random_device rd;                           // non-deterministic generator  
    mt19937 gen(rd());                          // use mersenne twister and seed is rd
    uniform_int_distribution<> roll(1, sides);  // distribution range 1~sides
    
    start = time(NULL);
    for (int i=0; i<times; i++)
        histogram[roll(gen)-1] += 1;

    printf("sides         N_s       N_s-N/6        N_s/N    N_s/N-1/6\n\n");
    for (int i=0; i<histogram.size(); i++)
        printf("  %3d  %10d    % 10.4f   % 10.6f   % 10.6f\n", i+1, histogram[i],  abs((double)histogram[i] - (double)times/sides), \
                                                               (double)histogram[i]/times, abs((double)histogram[i]/times - (double)1.0/sides) );
    
    end = time(NULL);
    cout << setprecision(16) << "\nNumber of trials: " << times << ", and time spent: " << end-start << " sec\n\n" << endl; 
}

int main()
{
    Dice dice1(6);

    dice1.roll(1);
    dice1.roll(10);
    dice1.roll(100);
    dice1.roll(1000);
    dice1.roll(10000);
    dice1.roll(100000);
    dice1.roll(1000000);
    dice1.roll(10000000);
    dice1.roll(20000000);
    dice1.roll(30000000);
    dice1.roll(40000000);
    dice1.roll(50000000);

    return 0;
}
