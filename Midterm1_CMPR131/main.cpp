#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "DescriptiveStats.h"
#include "input.h"

using namespace std;

// Function declaration for the menu
char menuOption();
void pause();

int main()
{
    //initializing DescriptiveStats class object
    DescriptiveStats array;

    //intitializing data input file
    fstream datafile;

    //will hold user integer data inputs
    int input = 0;

    //will hold dynamic array data size
    int size = 0;

    do
    {
        switch (menuOption())
        {
        case '0':  // Exit the program
        {
            exit(0);
        }
        break;

        case '1':  // Set data as Sample or Population
        {
            cout << "\n\t\tData Set Option Is Currently Set For Sample!";
            array.setIsPopulation(inputInteger("\n\t\tSelect The Data Set Option (0-Sample Or 1-Population): ", 0, 1));

            if (array.getIsPopulation() == 0)
            {
                cout << "\n\t\tThe Data Set Will Now Be Set To Sample!";
            }
            else
            {
                cout << "\n\t\tThe Data Set Will Now Be Set To Population!";
            }

            cout << endl;
            system("pause");
        }
        break;

        case '2':  // Input Data (Manual, Random, File)
        {
            //we will reset our dynamic array
            array.clear();
            char option1 = inputChar("\n\t\tChoose An Option (M) - Manual, (R) - Random, (F) - File, Or (X) - Return: ", static_cast<string>("MRFX"));

            switch (option1)
            {
            case 'M': // Manual input
            {
                size = inputInteger("\n\t\tSpecify The Size Of The Array: ", 3, 200);
                for (int i = 0; i < size; i++)
                {
                    cout << "\n\t\tPlease Enter Integer " << i + 1 << ": ";
                    array.setInput(inputInteger("", 1, 100));
                }
                //we will sort array
                array.sortArray();
                cout << "\n\t\tData Set Contains " << size << " Data Point(s)!\n";
                cout << "\t\t[  ";
                for (int i = 0; i < size; i++)
                {
                    cout << array.getInput(i);
                    if (i != size - 1)
                        cout << ", ";
                }
                cout << " ]" << endl;
                system("pause");
            }
            break;

            case 'R':  // Random input
            {
                srand(time(0));
                size = inputInteger("\n\t\tSpecify The Size Of The Array: ", 3, 200);
                for (int i = 0; i < size; i++)
                {
                    array.setInput(rand() % 100 + 1);
                }
                //we will sort array
                array.sortArray();
                cout << "\n\t\tData Set Contains " << size << " Data Point(s)!\n";
                cout << "\t\t[  ";
                for (int i = 0; i < size; i++)
                {
                    cout << array.getInput(i);
                    if (i != size - 1)
                        cout << ", ";
                }
                cout << " ]" << endl;
                system("pause");
            }
            break;

            case 'F':  // File input
            {
                string fileName = inputString("\n\t\tEnter the name of the file for analysis: ", true);
                datafile.open(fileName, ios::in);
                if (datafile.fail())
                {
                    cout << "\n\t\tSorry this file does not exist! Try again!" << endl;
                    cout << endl;
                    system("pause");
                    break;
                }
                while (!datafile.eof())
                {
                    datafile >> input;
                    array.setInput(input);
                }
                size = array.getSize();
                //we will sort array
                array.sortArray();
                cout << "\n\t\tData Set Contains " << size << " Data Point(s)!\n";
                cout << "\t\t[  ";
                for (int i = 0; i < size; i++)
                {
                    cout << array.getInput(i);
                    if (i != size - 1)
                        cout << ", ";
                }
                cout << " ]" << endl;
                datafile.close();
                system("pause");
            }
            break;

            case 'X':  // Return
            {
                break;
            }

            }

        }
        break;

        case 'A':  // Find Minimum
        {
            cout << endl;
            //if array is empty message below will output
            if (array.getSize() == 0)
            {
                cout << "\n\t\tNo data to analyze, go to option 2 and try again!";

                cout << endl;
                system("pause");
                break;
            }
            //we will call Findminimum function to output minimum
            cout << "\n\t\tMinimum: " << array.Findminimum() << endl;

            cout << endl;
            system("pause");
        }
        break;

        case 'B':  // Find Maximum
        {
            cout << endl;
            //if array is empty message below will output
            if (array.getSize() == 0) {
                cout << "\n\t\tNo data to analyze, go to option 2 and try again!";

                cout << endl;
                system("pause");
                break;
            }
            //we will call Findmaximum function to output maximum
            cout << "\n\t\tMaximum: " << array.Findmaximum() << endl;

            cout << endl;
            system("pause");
        }
        break;

        case 'C':  // Find Range
        {
            cout << endl;
            //if array is empty message below will output
            if (array.getSize() == 0)
            {
                cout << "\n\t\tNo data to analyze, go to option 2 and try again!";

                cout << endl;
                system("pause");
                break;
            }
            //we will call Findrange function to output range
            cout << "\n\t\tRange: " << array.Findrange() << endl;

            cout << endl;
            system("pause");
        }
        break;

        case 'D':  // Find Size
        {
            cout << endl;
            //if array is empty message below will output
            if (array.getSize() == 0)
            {
                cout << "\n\t\tNo data to analyze, go to option 2 and try again!";

                cout << endl;
                system("pause");
                break;
            }
            //we will output size of data set
            cout << "\n\t\tSize: " << array.getSize() << " Data Points" << endl;

            cout << endl;
            system("pause");
        }
        break;

        case 'E':  // Find Sum
        {
            cout << endl;
            //if array is empty message below will output
            if (array.getSize() == 0)
            {
                cout << "\n\t\tNo data to analyze, go to option 2 and try again!";

                cout << endl;
                system("pause");
                break;
            }
            //we will call FindSum function to output sum
            cout << "\n\t\tSum: " << array.FindSum() << endl;

            cout << endl;
            system("pause");
        }
        break;

        case 'F':  // Find Mean
        {
            cout << endl;
            //if array is empty message below will output
            if (array.getSize() == 0) {
                cout << "\n\t\tNo data to analyze, go to option 2 and try again!";

                cout << endl;
                system("pause");
                break;
            }
            //we will call FindMean function to output mean
            cout << "\n\t\tMean: " << array.FindMean() << endl;

            cout << endl;
            system("pause");
        }
        break;

        case 'G':  // Find Median
        {
            cout << endl;
            //if array is empty message below will output
            if (array.getSize() == 0) {
                cout << "\n\t\tNo data to analyze, go to option 2 and try again!";

                cout << endl;
                system("pause");
                break;
            }
            //we will call FindMedian function to output median
            cout << "\n\t\tMedian: " << array.FindMedian() << endl;

            cout << endl;
            system("pause");
        }
        break;

        case 'H':  // Find Mode
        {
            cout << endl;
            //if array is empty message below will output
            if (array.getSize() == 0) {
                cout << "\n\t\tNo data to analyze, go to option 2 and try again!";

                cout << endl;
                system("pause");
                break;
            }
            //we will call FindMode function to output mode
            cout << "\n\t\tMode: " << array.FindMode() << endl;

            cout << endl;
            system("pause");
        }
        break;

        case 'I':  // Find Standard Deviation
        {
            cout << endl;
            //if array is empty message below will output
            if (array.getSize() == 0) {
                cout << "\n\t\tNo data to analyze, go to option 2 and try again!";

                cout << endl;
                system("pause");
                break;
            }
            //we will call FindStandardDeviation function to output standard deviation
            cout << "\n\t\tStandard Deviation: " << array.FindStandardDeviation() << endl;

            cout << endl;
            system("pause");
        }
        break;

        case 'J':  // Find Variance
        {
            cout << endl;
            //if array is empty message below will output
            if (array.getSize() == 0) {
                cout << "\n\t\tNo data to analyze, go to option 2 and try again!";

                cout << endl;
                system("pause");
                break;
            }
            //we will call FindVariance function to output variance
            cout << "\n\t\tVariance: " << array.FindVariance() << endl;

            cout << endl;
            system("pause");
        }
        break;

        case 'K':  // Find Mid Range
        {
            cout << endl;
            //if array is empty message below will output
            if (array.getSize() == 0) {
                cout << "\n\t\tNo data to analyze, go to option 2 and try again!";

                cout << endl;
                system("pause");
                break;
            }
            //we will call FindMidRange function to output mid range
            cout << "\n\t\tMid Range: " << array.FindMidRange() << endl;

            cout << endl;
            system("pause");
        }
        break;

        case 'L':  // Find Quartiles
        {
            cout << endl;
            //if array is empty message below will output
            if (array.getSize() == 0) {
                cout << "\n\t\tNo data to analyze, go to option 2 and try again!";

                cout << endl;
                system("pause");
                break;
            }
            cout << "\n\t\tQuartiles: ";
            //we will call FindQuartiles function
            double* quartPtr = array.FindQuartiles();
            if (quartPtr[0] == NULL)
                cout << "Unknown";
            else {
                cout << "Q1: " << quartPtr[0] << ", Q2 (Median): " << quartPtr[1] << ", Q3: " << quartPtr[2];
            }

            cout << endl;
            system("pause");
        }
        break;

        case 'M':  // Interquartile Range
        {
            cout << endl;
            //if array is empty message below will output
            if (array.getSize() == 0) {
                cout << "\n\t\tNo data to analyze, go to option 2 and try again!";

                cout << endl;
                system("pause");
                break;
            }
            //we will call FindIQR function to output interquartile range
            cout << "\n\t\tInterquartile Range: " << array.findIQR() << endl;

            cout << endl;
            system("pause");
        }
        break;

        case 'N':  // Outliers
        {
            cout << endl;
            //if array is empty message below will output
            if (array.getSize() == 0) {
                cout << "\n\t\tNo data to analyze, go to option 2 and try again!";

                cout << endl;
                system("pause");
                break;
            }
            //we will call FindOutliers function
            double* outliers = array.FindOutliers();

            if (outliers == nullptr) {
                cout << "\n\t\tOutliers: none" << endl;
                cout << endl;
            }
            else {
                cout << "\n\t\tLower Outlier: " << (outliers[0] == 0 ? "None" : to_string(outliers[0])) << endl;
                cout << "\n\t\tUpper Outlier: " << (outliers[1] == 0 ? "None" : to_string(outliers[1])) << endl;
            }

            cout << endl;
            system("pause");
        }
        break;

        case 'O':  // Sum of Squares
        {
            cout << endl;
            //if array is empty message below will output
            if (array.getSize() == 0) {
                cout << "\n\t\tNo data to analyze, go to option 2 and try again!";

                cout << endl;
                system("pause");
                break;
            }
            //we will call FindSumOSquares function to output sum of squares
            cout << "\n\t\tSum of Squares: " << array.FindSumOfSquares() << endl;

            cout << endl;
            system("pause");
        }
        break;

        case 'P':  // Mean Absolute Deviation
        {
            cout << endl;
            //if array is empty message below will output
            if (array.getSize() == 0) {
                cout << "\n\t\tNo data to analyze, go to option 2 and try again!";

                cout << endl;
                system("pause");
                break;
            }
            //we will call FindMeanAbsoluteDeviation function to output mean absolute deviation
            cout << "\n\t\tMean Absolute Deviation: " << array.FindMeanAbsoluteDeviation() << endl;

            cout << endl;
            system("pause");
        }
        break;

        case 'Q':  // Root Mean Square
        {
            cout << endl;
            //if array is empty message below will output
            if (array.getSize() == 0) {
                cout << "\n\t\tNo data to analyze, go to option 2 and try again!";

                cout << endl;
                system("pause");
                break;
            }
            //we will call FindRootMeanSquare function to output root mean square
            cout << "\n\t\tRoot Mean Square: " << array.FindRootMeanSquare() << endl;

            cout << endl;
            system("pause");
        }
        break;

        case 'R':  // Standard Error of the Mean
        {
            cout << endl;
            //if array is empty message below will output
            if (array.getSize() == 0) {
                cout << "\n\t\tNo data to analyze, go to option 2 and try again!";

                cout << endl;
                system("pause");
                break;
            }

            //we will call FindSTDErrorOfMean function to output standard error of the mean
            cout << "\n\t\tStandard Error of the Mean: " << array.FindSTDErrorOfMean() << endl;

            cout << endl;
            system("pause");
        }
        break;

        case 'S':  // Skewness
        {
            cout << endl;
            //if array is empty message below will output
            if (array.getSize() == 0)
            {
                cout << "\n\t\tNo data to analyze, go to option 2 and try again!";

                cout << endl;
                system("pause");
                break;
            }
            //we will call FindSkewness function to output skewness
            cout << "\n\t\tSkewness: " << array.FindSkewness() << endl;

            cout << endl;
            system("pause");

        }
        break;

        case 'T':  // Kurtosis
        {

            cout << endl;
            //if array is empty message below will output
            if (array.getSize() == 0) {
                cout << "\n\t\tNo data to analyze, go to option 2 and try again!";

                cout << endl;
                system("pause");
                break;
            }
            //we will call FindKurtosis function to output kurtosis
            cout << "\n\t\tKurtosis: " << array.FindKurtosis() << endl;

            cout << endl;
            system("pause");
        }
        break;

        case 'U':  // Kurtosis Excess
        {
            cout << endl;
            //if array is empty message below will output
            if (array.getSize() == 0)
            {
                cout << "\n\t\tNo data to analyze, go to option 2 and try again!";

                cout << endl;
                system("pause");
                break;
            }
            //we will call FindKurtosisExcess function to output kurtosis of excess
            cout << "\n\t\tKurtosis Excess: " << array.FindKurtosisExcess() << endl;

            cout << endl;
            system("pause");
        }
        break;

        case 'V':  // Coefficient of Variation
        {
            cout << endl;
            //if array is empty message below will output
            if (array.getSize() == 0)
            {
                cout << "\n\t\tNo data to analyze, go to option 2 and try again!";

                cout << endl;
                system("pause");
                break;
            }
            //we will call FindCoefficientOfVariation function to output coefficient of variation
            cout << "\n\t\tCoefficient of Variation: " << array.FindCoefficientOfVariation() << endl;

            cout << endl;
            system("pause");
        }
        break;

        case 'W':  // Relative Standard Deviation
        {

            cout << endl;
            //if array is empty message below will output
            if (array.getSize() == 0) {
                cout << "\n\t\tNo data to analyze, go to option 2 and try again!";

                cout << endl;
                system("pause");
                break;
            }

            //we will call FindRelativeSTDDeviation to output relative standard deviation
            cout << "\n\t\tRelative Standard Deviation: " << array.FindRelativeSTDDeviation() << "%" << endl;

            cout << endl;
            system("pause");
        }
        break;

        case 'X':  // Frequencies
        {

            cout << endl;
            //if array is empty message below will output
            if (array.getSize() == 0)
            {
                cout << "\n\t\tNo data to analyze, go to option 2 and try again!";

                cout << endl;
                system("pause");
                break;
            }
            //we will call frequencyOfDataSet to output all data frequencies
            cout << "\n\t\tFrequencies: \n" << array.frequencyOfDataSet() << endl;

            cout << endl;
            system("pause");
        }
        break;

        case '3'://output all data to console and text file
        {

            cout << endl;
            //if array is empty message below will output
            if (array.getSize() == 0)
            {
                cout << "\n\t\tNo data to analyze, go to option 2 and try again!";

                cout << endl;
                system("pause");
                break;
            }

            cout << endl;

            cout << array;
            //user will enter name of file they want to save all data 
            string fileName = inputString("\n\t\tEnter an output file name(txt or dat format): ", true);
            //we will call printDataToFile function to save all data to text file
            array.printDataToFile(fileName);

            cout << endl;

            cout << "\n\t\tCongratulations your data has been saved in " << fileName << " text file!";

            cout << endl;
            cout << endl;

            system("pause");

        }
        break;


        default:
            cout << "\n\t\tInvalid option! Please try again." << endl;
            system("pause");
            break;
        }

    } while (true);

    return 0;
}


// Function definition for displaying the menu
char menuOption()
{

    system("cls");

    cout << "\n\tDescriptive statistics are brief descriptive coefficients that summarize a given data set,";
    cout << "\n\twhich can be either a representation of the entire population or a sample of a population.";
    cout << "\n\tDescriptive statistics are broken down into measures of central tendency and measure of";
    cout << "\n\tvariability(spread). Measures of central tendency include the mean, the median, and mode. While";
    cout << "\n\tmeasures of variability include standard deviation, variance, minimum, and maximum variables,";
    cout << "\n\tkurtosis, and skewness";

    cout << "\n";

    cout << "\n\tCMPR131 - Chapter 1: Descriptive statistics - Oscar Gallardo - Brissa Hoke - Alfonso Valle - Marco Martinez - (10/23/2024)";
    cout << "\n\t" << string(110, char(205));
    cout << "\n\t\t1> Select Data Set Option";
    cout << "\n\t\t2> Select Data Input Option, Store Data Into A Sorted Array & Display The Data Set";
    cout << "\n\t" << string(110, char(205));
    cout << "\n\t\tA> Minimum                                        M> Interquartile Range";
    cout << "\n\t\tB> Maximum                                        N> Outlier";
    cout << "\n\t\tC> Range                                          O> Sum of Squares";
    cout << "\n\t\tD> Size                                           P> Mean Absolute Deviation";
    cout << "\n\t\tE> Sum                                            Q> Root Mean Square";
    cout << "\n\t\tF> Mean                                           R> STD Error Of The Mean";
    cout << "\n\t\tG> Median                                         S> Skewness";
    cout << "\n\t\tH> Mode                                           T> Kurtosis";
    cout << "\n\t\tI> Standard Deviation                             U> Kurtosis Excess";
    cout << "\n\t\tJ> Variance                                       V> Coefficient of Variation";
    cout << "\n\t\tK> Mid Range                                      W> Relative Standard Deviation";
    cout << "\n\t\tL> Quartile                                       X> Frequencies";
    cout << "\n\t" << string(110, char(205));
    cout << "\n\t\t3> Display all results (Options A....X) and write out to a textfile";
    cout << "\n\t" << string(110, char(205));
    cout << "\n\t\t0> Exit";
    cout << "\n\t" << string(110, char(205));


    return inputChar("\n\t\tOption: ", static_cast<string>("0123ABCDEFGHIJKLMNOPQRSTUVWX"));

    system("pause");

}
// Global pause function
void pause()
{
    cout << "\n\tPress Enter to continue...";
    cin.ignore(); // To consume any leftover input in the buffer
    cin.get();    // Waits for the user to press Enter
}