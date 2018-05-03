/**************************************************************************
Date: 2018/5/1 StatMech Assignment 2 (due to 5/3)

Problem 1: Generalized dice

Environment: gcc-4.7 up (use C++11)

- Zlin Tsai. s106022501@m106.nthu.edu.tw
***************************************************************************/
#include <iostream>
#include <cmath>
#include <random>
#include <time.h>
#include <iomanip>

using namespace std;

/// Construct statistical method 
/// return: vector {mean, var, SD}

template <class T> 
vector<double> stat(vector<T> raw_data)
{
    double var = 0.0, SD = 0.0, mean = 0.0;
    for (int i=0; i<raw_data.size(); i++)
        mean += raw_data[i];

    mean = mean/raw_data.size();

    for (int i=0; i<raw_data.size(); i++)
    {
        var += pow((raw_data[i] - mean), 2);
    }

    var = var/raw_data.size();
    SD = sqrt(var);

    vector<double> data;
    data.push_back(mean);
    data.push_back(var);
    data.push_back(SD);

    return data;
}

/// Construct a dice
/// Tool: roll, analysis_data

class Dice
{
    private:
        int sides;

    public:
        Dice(int);
        vector<int> histogram;                  // 
        double mean, var, SD;                   // mean, variance, and standard deviation
        int times;
        void roll(int);
        void analysis_data();
};

Dice::Dice(int s)
{
    sides = s;
    histogram.assign(s, 0);                     // remember c++ start 0 (0, 1, 2, 3, 4, 5 for s = 6) 
}

void Dice::roll(int t)
{
    times = t;
    histogram.assign(sides, 0);                 // reset histogram to 0
    random_device rd;                           // non-deterministic generator  
    mt19937 gen(rd());                          // use mersenne twister and seed is rd
    uniform_int_distribution<> roll(1, sides);  // distribution range 1~sides

    /// roll the dice 
    for (int i=0; i<t; i++)
        histogram[roll(gen)-1] += 1;
}

void Dice::analysis_data()
{
    printf("sides         N_s       N_s-N/S        N_s/N    N_s/N-1/S\n\n");
    for (int i=0; i<histogram.size(); i++)
        printf("  %3d  %10d    %10.4f   %10.6f   %10.6f\n", i+1, histogram[i],  abs((double)histogram[i] - (double)times/sides), \
                                                        (double)histogram[i]/times, abs((double)histogram[i]/times - 1.0/sides) );
    
    /// experiment result
    for (int i=0; i<histogram.size(); i++)
    {
        mean += (i + 1) * (double)histogram[i]/times;
        var +=  pow((i + 1), 2) * (double)histogram[i]/times;
    }
    var = var - pow(mean, 2);
    SD = sqrt(var);

    cout << setprecision(8) << "\nmean: " << mean << ", variance: " << var << ", standard deviation: " << SD << endl;

    /// theory predication
    cout << "\n**** Check by theoretical prediction ****" << endl; 
    double mean_err = 0.0, var_err = 0.0, SD_err = 0.0;
    for (int i=0; i<histogram.size(); i++)
    {
        mean_err += (i + 1) * 1.0/sides;
        var_err +=  pow((i + 1), 2) * 1.0/sides;
    }
    var_err = var_err - pow(mean, 2);
    SD_err = sqrt(var_err);

    cout << setprecision(8) << "\nmean: " << mean_err << ", variance: " << var_err << ", standard deviation: " << SD_err << endl;

    /// result
    cout << "\n**** Check error ****" << endl; 
    mean_err = (mean_err - mean) / mean_err * 100;
    var_err = (var_err - var) / var_err * 100;
    SD_err = (SD_err - SD) / SD_err * 100;
    cout << setprecision(8) << "\nmean error: " << mean_err << "%, variance error: " << var_err << "%, standard deviation error: " << SD_err << "%." << endl;

    cout << "----------------------------------------------------------------------------" << endl;
}

int main()
{
    double start = 0, end = 0;                  // set time clock
    Dice dice1(6);
    dice1.roll(10000);
    dice1.analysis_data();

    start = time(NULL);
    end = time(NULL);
    cout << setprecision(16) << "\n\nNumber of trials: " << "10000" << ", and time spent: " << end-start << " sec" << endl; 

    return 0;
}
