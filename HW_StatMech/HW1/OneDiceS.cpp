/**************************************************************************
Date: 2018/3/26 StatMech Assignment 1 (due to 3/29)

Problem 1: One die with S sides (just change dice1(sides=8)

Environment: gcc-4.7 up (use C++11)

- Zlin Tsai. s106022501@m106.nthu.edu.tw
***************************************************************************/
#include <iostream>
#include <cmath>
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
        double mean_err, var_err, SD_err;
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
    double mean = 0.0, var = 0.0, SD = 0.0;     // mean, variance, and standard deviation
    
    start = time(NULL);

    /// roll the dice 
    for (int i=0; i<times; i++)
        histogram[roll(gen)-1] += 1;

    printf("sides         N_s       N_s-N/S        N_s/N    N_s/N-1/S\n\n");
    for (int i=0; i<histogram.size(); i++)
        printf("  %3d  %10d    % 10.4f   % 10.6f   % 10.6f\n", i+1, histogram[i],  abs((double)histogram[i] - (double)times/sides), \
                                                               (double)histogram[i]/times, abs((double)histogram[i]/times - (double)1.0/sides) );
    
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
    mean_err = 0.0;
    var_err = 0.0;
    SD_err = 0.0;
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

    end = time(NULL);
    cout << setprecision(16) << "\n\nNumber of trials: " << times << ", and time spent: " << end-start << " sec" << endl; 
    cout << "----------------------------------------------------------------------------" << endl;
    cout.flush();
}

double StdDeviation(vector<double> data)
{
    double var = 0.0, SD = 0.0, mean = 0.0;
    for (int i=0; i<data.size(); i++)
        mean += data[i];

    mean = mean/data.size();

    for (int i=0; i<data.size(); i++)
    {
        var += pow((data[i] - mean), 2);
    }
    var = var/data.size();

    SD = sqrt(var);

    return SD;
}

int main()
{
    Dice dice1(8);    // set sides
    Dice dice2(7);    // set sides

    vector<double> mean_err_avg, SD_err_avg;
    //double mean_err_avg = 0.0, SD_err_avg = 0.0;
    // problem 1.3
    //dice1.roll(10000000);
    //dice2.roll(10000000);

    // problem 1.4
    //dice1.roll(10);
    //dice1.roll(100);
    //dice1.roll(1000);
    //dice1.roll(10000);
    //int CN = 1000;
    /*for (int i=1; i<CN; i++)
    {
        dice1.roll(2000);
        mean_err_avg += dice1.mean_err;
        SD_err_avg += dice1.SD_err;
    }
    mean_err_avg = mean_err_avg/CN;
    SD_err_avg = SD_err_avg/CN;
    cout << "do avg : " << endl;
    cout << setprecision(8) << "\nmean error: " << mean_err_avg << "%, standard deviation error: " << SD_err_avg << "%." <<endl;
*/

    /*double result;
    int CN = 1000;
    ///
    mean_err_avg.clear();
    SD_err_avg.clear();
    for (int i=1; i<CN; i++)
    {
        dice1.roll(5000);
        //mean_err_avg.push_back(dice1.mean_err);
        SD_err_avg.push_back(dice1.SD_err);
    }

    result = StdDeviation(SD_err_avg);
    cout << "do avg : " << endl;
    cout << setprecision(8) << "standard deviation error SD: " << result << endl;

    ///
    mean_err_avg.clear();
    SD_err_avg.clear();
    for (int i=1; i<CN; i++)
    {
        dice1.roll(10000);
        SD_err_avg.push_back(dice1.SD_err);
    }

    result = StdDeviation(SD_err_avg);
    cout << "do avg : " << endl;
    cout << setprecision(8) << "standard deviation error SD: " << result << endl;

    ///
    mean_err_avg.clear();
    SD_err_avg.clear();
    for (int i=1; i<CN; i++)
    {
        dice1.roll(20000);
        SD_err_avg.push_back(dice1.SD_err);
    }

    result = StdDeviation(SD_err_avg);
    cout << "do avg : " << endl;
    cout << setprecision(8) << "standard deviation error SD: " << result << endl;

    ///
    mean_err_avg.clear();
    SD_err_avg.clear();
    for (int i=1; i<CN; i++)
    {
        dice1.roll(40000);
        SD_err_avg.push_back(dice1.SD_err);
    }

    result = StdDeviation(SD_err_avg);
    cout << "do avg : " << endl;
    cout << setprecision(8) << "standard deviation error SD: " << result << endl;
    ///
    mean_err_avg.clear();
    SD_err_avg.clear();
    for (int i=1; i<CN; i++)
    {
        dice1.roll(80000);
        SD_err_avg.push_back(dice1.SD_err);
    }

    result = StdDeviation(SD_err_avg);
    cout << "do avg : " << endl;
    cout << setprecision(8) << "standard deviation error SD: " << result << endl;*/
    dice1.roll(1000000);
    dice1.roll(10000000);
    dice1.roll(20000000);
    dice1.roll(30000000);
    dice1.roll(40000000);
    //dice1.roll(50000000);

    return 0;
}
