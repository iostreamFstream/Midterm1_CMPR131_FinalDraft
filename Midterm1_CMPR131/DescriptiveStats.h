#pragma once
#include <iostream>
#include <string>
using namespace std;

class DescriptiveStats
{

private:
    static const int MAX_SIZE = 100000;  // Maximum allowed size of the dataset
    int* array;  // Pointer to dynamically allocate array
    int size;  // Current size of the array
    bool isPopulation;  // Flag to determine if data represents a population or a sample

public:
    // Constructor and Destructor
    DescriptiveStats();  // Constructor to initialize array and variables
    ~DescriptiveStats();  // Destructor to deallocate dynamic memory

    // Get the current size of the dataset
    int getSize() const;

    // Set whether the data represents a population or a sample
    void setIsPopulation(int ifIsPopulation);  // Set population flag
    bool getIsPopulation() const;  // Get population flag

    // Input related functions
    void setInput(int newInput);  // Set input into the array
    int getInput(int index) const;  // Get input at a specific index
    void clear();  // Clear the array

    // Descriptive statistics functions
    int Findminimum() const;  // Find minimum value
    int Findmaximum() const;  // Find maximum value
    int Findrange() const;  // Find range (max - min)
    int FindSum() const;  // Find sum of all values
    double FindMean() const;  // Find mean of the data
    double FindMedian() const;  // Find median value
    string FindMode() const;  // Find mode of the data
    double FindStandardDeviation() const;  // Find standard deviation
    double FindVariance() const;  // Find variance
    void sortArray();  // Sort the array
    double FindMidRange() const;  // Find mid-range value
    double FindSumOfSquares() const;  // Find sum of squares
    double FindMeanAbsoluteDeviation() const;  // Find mean absolute deviation
    double FindRootMeanSquare() const;  // Find root mean square
    double FindSTDErrorOfMean() const;  // Find standard error of the mean
    double FindSkewness() const;  // Find skewness of the data
    double FindKurtosis() const;  // Find kurtosis of the data
    double FindKurtosisExcess() const;  // Find excess kurtosis
    double FindCoefficientOfVariation() const;  // Find coefficient of variation
    double FindRelativeSTDDeviation() const;  // Find relative standard deviation

    // Quartile, IQR, and Outliers
    double* FindQuartiles() const;  // Find quartiles (Q1, Q2, Q3)
    double findIQR() const;  // Find interquartile range (IQR)
    double* FindOutliers() const;  // Find outliers based on IQR

    // Frequencies
    string frequencyOfDataSet() const;  // Find the frequency of each data point

    // File output
    void printDataToFile(string fileName) const;  // Write data to file

    // Display array and operator overloading
    ostream& displayArray(ostream& out) const;  // Display the array
    friend ostream& operator<<(ostream& out, const DescriptiveStats& obj);  // Overload << operator


};

