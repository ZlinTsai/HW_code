/**************************************************************************
Date: 2018/5/1 StatMech Assignment 2 (due to 5/3)

Problem 1: Generalized dice & Problem 2: Computer simulations of mismatched dice

Environment: gcc-4.7 up (use C++11)

- Zlin Tsai. s106022501@m106.nthu.edu.tw
***************************************************************************/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <random>
#include <time.h>
#include <iomanip>

using namespace std;

/// Construct a dice
/// Tool: roll, analysis data, save data

class Group_Dices
{
    private:
        int NumDices;
        vector<int> NumSides; 
        int min, max, total;                    // min and max of sum, total is total state of sum. 
        string mode;

    public:
        Group_Dices(int, vector<int>, string);
        vector<int> histogram;                  
        double mean, var, SD;                   // mean, variance, and standard deviation
        int trials;
        void roll(int);
        void AnalysisData();
        void SaveData();
};

Group_Dices::Group_Dices(int ND, vector<int> NS, string str)
{
    NumDices = ND;
    NumSides = NS;
    min = ND;
    max = 0;
    mode = str;
    for (int i=0; i<ND; i++)
        max += NS[i];

    total = max - min + 1;
    histogram.assign(total, 0);
}

void Group_Dices::roll(int t)
{
    trials = t;
    histogram.assign(total, 0);                 // reset histogram to 0
    random_device rd;                           // non-deterministic generator  
    mt19937 gen(rd());                          // use mersenne twister and seed is rd
    vector<int> data;
    data.assign(t, 0);

    for (int i=0; i<NumDices; i++)
    {
        uniform_int_distribution<int> rolls(1, NumSides[i]);
        for (int i=0; i<t; i++)
            data[i] += rolls(gen);
    }

    for (int i=0; i<t; i++)
        histogram[data[i] - min] += 1;
}

void Group_Dices::AnalysisData()
{
    cout << "\n**** probability of S at experiment ****" << endl;   
    for (int i=0; i<histogram.size(); i++)
        cout << "Prob(" << (i + min) << ") = " << (double)histogram[i]/trials << endl;

    /// experiment result
    for (int i=0; i<histogram.size(); i++)
    {
        mean += (i + min) * (double)histogram[i]/trials;
        var +=  pow((i + min), 2) * (double)histogram[i]/trials;
    }
    var = var - pow(mean, 2);
    SD = sqrt(var);

    cout << fixed << setprecision(6) << "\n" << endl;
    cout << "Number of trials: " << trials << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << setw(11) << "" << setw(15) << "Mean" << setw(15) << "Variance" << setw(25) << "Standard deviation" << "\n"<< endl;
    cout << setw(11) << "Experiment" << setw(15) << mean << setw(15) << var << setw(25) << SD << endl;

    /// theoretical prediction
    double mean_single = 0.0, mean_err = 0.0, var_err = 0.0, SD_err = 0.0;
    for (int i=0; i<NumDices; i++)
    {
        mean_single = 0.0;
        for (int j=0; j<NumSides[i]; j++)
        {
            mean_single += (j + 1) * 1.0/NumSides[i];
            var_err +=  pow((j + 1), 2) * 1.0/NumSides[i];
        }
        mean_err += mean_single;
        var_err -= pow(mean_single, 2);
    }
    SD_err = sqrt(var_err);
    cout << setw(11) << "Prediction" << setw(15) << mean_err << setw(15) << var_err << setw(25) << SD_err << endl;

    /// result
    mean_err = (mean_err - mean) / mean_err * 100;
    var_err = (var_err - var) / var_err * 100;
    SD_err = (SD_err - SD) / SD_err * 100;
    cout << setw(11) << "Errors (%)" << setw(14) << abs(mean_err) << "%" << setw(14) << abs(var_err) << "%" << setw(24) << abs(SD_err) << "%" << endl;

    cout << "------------------------------------------------------------------" << endl;
}

void Group_Dices::SaveData()
{
    if (mode == "2")
    {
        cout << "Sorry, this  program CANNOT saving at mode 2 now." << endl;
        return;
    }

    string file;
    file = "data/ND_" + to_string(NumDices) + "_NS_" + to_string(NumSides[0]) + ".csv";
    cout << "\nThe data already save at " << file << endl;
    ofstream fout(file);
    if (!fout)
        cout << "Fail to save (maybe need mkdir data/)" << endl;

    fout << "S,Prob(S)" << endl;
    fout.flush();
    for (int i=0; i<histogram.size(); i++)
    {
        fout << i + min  << "," << (double)histogram[i]/trials << endl;
    }
    fout.flush();
    fout.close();
}

int main()
{
    double start = 0, end = 0;                  // set time clock
    int NumDices, sides, trials;
    string tmp, nd, ns, mode, tr;
    vector<int> NumSides;

    /// Set parameter of dice
    cout << "\nInput your number of dices = ";
    cin >> NumDices;
    /*cin.ignore();
    getline(cin, nd);
    if (nd == "")
    {
        NumDices = 2;
        cout << "****";
    }
    else 
        NumDices = stoi(tmp);*/

    /// Set parameter of sides
    cout << "\nChoice your mode of dice:" << endl; 
    cout << "(1) the same number of sides for each dice. (default)" << endl;
    cout << "(2) mismatched dice." << endl;
    cout << "(1 or 2)";
    cin.ignore();                    // cin a something into buffer.
    getline(cin, mode);              // read buffer(include <Enter>).
    if (mode == "1" || mode == "")
    {
        cout << "\nUsing the same number of sides for each dice." << endl;
        cout << "Input your sides of dice :" << endl;
        cout << "the sides of dice = ";
        cin >> sides;

        for (int i=0; i<NumDices; i++)
            NumSides.push_back(sides);
    }
    else if (mode == "2")
    {
        cout << "\nUsing mismatched dice.";
        cout << "Input your sides of dice :" << endl;
        for (int i=0; i<NumDices; i++)
        {
            cout << "the sides of dice(" << i + 1 << ") = ";
            cin >> sides;
            NumSides.push_back(sides);
        }
    }
    else 
    {
        cerr << "\nthis is not valid mode!!" << endl;
        return 0;
    }

    /// Set parameter of trials
    cout << "\nInput your number of trials (default is 10000) = ";
    cin.ignore();
    getline(cin, tr);
    if (tr == "")
    {
        trials = 10000;
    }
    else 
    {
        trials = stoi(tr);
    }
    
    /// main
    start = time(NULL);

    Group_Dices GD(NumDices, NumSides, mode);
    GD.roll(trials);
    GD.AnalysisData();
    //GD.SaveData();

    end = time(NULL);
    cout << setprecision(16) << "time spent: " << end-start << " sec\n" << endl; 

    return 0;
}
