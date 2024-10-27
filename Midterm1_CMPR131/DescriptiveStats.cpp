#include "DescriptiveStats.h"
#include <cmath>
#include <map>
#include <fstream>
#include <algorithm>
#include <iomanip>

using namespace std;

//precondition: DescriptiveStats header
//postcondition: class default constructor
DescriptiveStats::DescriptiveStats()
{
    size = 0;
    isPopulation = false;
    array = new int[MAX_SIZE];  // Dynamically allocate memory for array
}

//precondition: DescriptiveStats header
//postcondition: class destructor
DescriptiveStats::~DescriptiveStats()
{
    delete[] array;  // Free the dynamically allocated memory
}

//precondition: int* array data set
//postcondition: return the size of our data set
int DescriptiveStats::getSize() const
{
    return size;
}

//precondition: none
//postcondtion: setter/mutator of user sample choice input
void DescriptiveStats::setIsPopulation(int ifIsPopulation)
{
    isPopulation = (ifIsPopulation == 1);
}

//precondition: setIsPopulation
//postcondtion: returns user sample choice input
bool DescriptiveStats::getIsPopulation() const
{
    return isPopulation;
}

//precondition: none
//postcondtion: setter/mutator of user integer data inputs
void DescriptiveStats::setInput(int newInput)
{
    if (size < MAX_SIZE) {
        array[size++] = newInput;  // Insert new input and increment size
    }
}

//precondition: setInput
//postcondtion: returns user integer data inputs
int DescriptiveStats::getInput(int index) const
{
    return (index >= 0 && index < size) ? array[index] : -1;  // Return input at specific index
}

//precondition: none
//postcondition: resets all memory from dynamic array 
void DescriptiveStats::clear()
{
    delete[] array;  // Free the old array memory
    array = new int[MAX_SIZE];  // Reallocate new memory for array
    size = 0;  // Reset size
}

//Precondition: int* array data set
//Postcondition: After running this function the function will find and return the smallest integer in our data set
int DescriptiveStats::Findminimum() const
{
    int minNumber = *array;  // Initialize with the first element

    for (int i = 1; i < size; i++)
    {
        if (array[i] < minNumber)
        {
            minNumber = array[i];  // Update if a smaller number is found
        }
    }
    return minNumber;
}

//Precondition: int* array data set
//Postcondition: After running this function the function will find and return the largest integer in our data set
int DescriptiveStats::Findmaximum() const
{
    int maxNumber = *array;  // Initialize with the first element

    for (int i = 1; i < size; i++)
    {
        if (array[i] > maxNumber)
        {
            maxNumber = array[i];  // Update if a larger number is found
        }
    }
    return maxNumber;
}

//precondition: int* array data set
//postcondition: returns the range of the data set
int DescriptiveStats::Findrange() const
{
    return Findmaximum() - Findminimum();  // Return the range
}

int DescriptiveStats::FindSum() const
{
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }

    return sum;
}

//precondition: int* array data set
//postcondition: returns the mean of the data set
double DescriptiveStats::FindMean() const
{
    return static_cast<double>(FindSum()) / size;  // Return mean
}

//Precondition: int* array data set
//Postcondition: After this function the function will return the median number in our integer data set
double DescriptiveStats::FindMedian() const
{
    int* tempArray = new int[size];
    copy(array, array + size, tempArray);  // Copy the array for sorting
    sort(tempArray, tempArray + size);  // Sort the copied array

    double median;
    if (size % 2 == 0) {  // If even number of elements

        median = (tempArray[size / 2 - 1] + tempArray[size / 2]) / 2.0;
    }
    else {  // If odd number of elements

        median = tempArray[size / 2];
    }

    delete[] tempArray;  // Free the temporary array memory
    return median;
}

//Precondition: int* array data set
//Postcondition: returns the number in the data set that occurs most frequently
string DescriptiveStats::FindMode() const
{
    map<int, int> frequencyMap;

    for (int i = 0; i < size; i++)
    {
        frequencyMap[array[i]]++;  // Count the frequency of each number
    }

    int maxFreq = 0;
    int modeValue = array[0];
    for (auto it : frequencyMap)
    {
        if (it.second > maxFreq)
        {
            maxFreq = it.second;
            modeValue = it.first;
        }
    }

    if (maxFreq == 1)
    {
        return "No mode";  // All values occur only once
    }

    return to_string(modeValue);
}

//precondition: data set is needed and if it is sample or population
//postcondition: returns the standard deviation of the data set based on wether it is sample or population
double DescriptiveStats::FindStandardDeviation() const
{
    double mean = FindMean();
    double sumSqDiff = 0;

    for (int i = 0; i < size; i++)
    {
        sumSqDiff += pow(array[i] - mean, 2);
    }

    if (isPopulation)
    {
        return sqrt(sumSqDiff / size);  // Population standard deviation
    }
    return sqrt(sumSqDiff / (size - 1));  // Sample standard deviation
}

//Precondition: int* data set
//Postcondition: returns the variance of a sample data set.
double DescriptiveStats::FindVariance() const
{
    return pow(FindStandardDeviation(), 2);  // Variance is SD squared
}

void DescriptiveStats::sortArray()
{
    sort(array, array + size);  // Sort the main array
}

//Precondition int* array data set
//Postcondition: Returns the mid range of the data set.
double DescriptiveStats::FindMidRange() const
{
    return (Findminimum() + Findmaximum()) / 2.0;
}

//precondition: int* array data set
//postcondition: returns the sum of squares of the data set
double DescriptiveStats::FindSumOfSquares() const
{
    double mean = FindMean();
    double sumOfSquares = 0;
    for (int i = 0; i < size; i++) {
        sumOfSquares += pow(array[i] - mean, 2);
    }
    return sumOfSquares;
}

//Precondition: int* array data set
//Postcondition: After calling this function the function will return the mean absolute deviation of the integers in our data set
double DescriptiveStats::FindMeanAbsoluteDeviation() const
{

    double mean = FindMean();
    double mad = 0;
    for (int i = 0; i < size; i++)
    {
        mad += abs(array[i] - mean);
    }

    return mad / size;
}

//Precondition: int* array data set
//Postcondition: returns the Root Mean Square of the dataset.
double DescriptiveStats::FindRootMeanSquare() const
{
    double sumOfSquares = 0;
    for (int i = 0; i < size; i++)
    {
        sumOfSquares += pow(array[i], 2);
    }

    return sqrt(sumOfSquares / size);
}

//pre: needs the data set and whether the calculations are population or sample
//post: returns the standard error of mean of the data set
double DescriptiveStats::FindSTDErrorOfMean() const
{
    return FindStandardDeviation() / sqrt(size);
}

//Precondition: int* array data set
//Postcondition: After calling out this function our program will return the skewness of our data set based on sample calculation
double DescriptiveStats::FindSkewness() const
{
    double sum1 = 0.00;//sum1 variable will hold the sum of all integers of our data set subtracted by the mean of our data set

    double calculate = 0.00;///calculate variable will hold subtraction of the integers in our data set by the mean of our data set and divided by the standard deviation

    double calculate3 = (size - 1) * (size - 2);//calculate variable will hold subtraction of the integers in our data set

    double skewness1 = 0.00;//variable skewness will hold the skewness of our data set

    double std1 = FindStandardDeviation();//we will calculation the standard deviation

    double std2 = pow(FindStandardDeviation(), 3);//

    double sum2 = FindSum();//we will calculate the sum of the integers in our data set

    if (isPopulation)
    {

        for (int i = 0; i < size; i++)//for loop will loop through all of the integers in our data set
        {

            calculate = pow((array[i] - FindMean()), 3);//we will subtract the integers of our data set by the mean and raise it to power of 3

            sum1 += calculate;//we will add all numbers calculated from our calculate variable

        }

        skewness1 = (sum1) / (size * std2);//we will calculate skewmess of the population calculation

        return skewness1;//we will return skewness

    }
    else
    {

        for (int i = 0; i < size; i++)//for loop will loop through all of the integers in our data set
        {

            calculate = pow(((array[i] - FindMean()) / (std1)), 3);//we will subtract the integers of our data set by the mean, we will divide this value by the standard deviation and raise it to power of 3

            sum1 += calculate;//we will add all numbers calculated from our calculate variable

        }

        skewness1 = (size / calculate3) * (sum1);//we will calculate skewness of the sample calculation

        return skewness1;//we will return skewness

    }

}

//Precondition: int* array data set
//Postcondition: Returns the Kurtosis of a sample data set
double DescriptiveStats::FindKurtosis() const
{

    double kurtosis = 0.0;//variable kurtosis will hold the kurtosis of our data set

    double sum1 = 0.00;//variable sum1 will hold the sum of the individual integers subtracted by the mean in our data set
    /////////////////////

    double sum2 = FindSum();//we will calculate the sum of the integers in our data set

    double calculate1 = 0.00;//for calculate1 we will subtract the integers in our data set by the mean of our data set and raise it to the power of 4

    double calculate2 = (size) * (size + 1);//we will calculate the size of our data set by the size of our data set plus 1

    //we will calculate the size of our data subtracted by 1 then multiplied by the size of our data set minus 2
    //multiplied again by the size of our data subtracted by 3
    double calculate3 = (size - 1) * (size - 2) * (size - 3);//

    double calculateFinal = calculate2 / calculate3;//we will divide calculate2 by calculate3

    double std1 = pow(FindStandardDeviation(), 4);//we will calculate the standard deviation and raise it to the power of 4

    double std2 = FindStandardDeviation();//we will calculate the standard deviation

    if (isPopulation)//if user chooses population calculation the value below will be calculated
    {
        for (int i = 0; i < size; i++)//
        {

            calculate1 = pow((array[i] - FindMean()), 4);//we will subtract the integers in our data set by the mean of our data set and raise it to the power of 4

            sum1 += calculate1;//we will calculate the sum of the individual integers subtracted by the mean in our data set

        }
        kurtosis = (sum1) / (size * std1);//we will calculate the kurtosis

        return kurtosis;//we will return the kurtosis

    }
    else//if user chooses sample calculation the value below will be calculated
    {
        for (int i = 0; i < size; i++)//
        {

            calculate1 = pow(((array[i] - FindMean()) / (std2)), 4);//we will subtract the integers in our data set by the mean of our data set and raise it to the power of 4

            sum1 += calculate1;//we will calculate the sum of the individual integers subtracted by the mean in our data set

        }
        kurtosis = (sum1)*calculateFinal;//we will calculate the kurtosis

        return kurtosis;//we will return the kurtosis

    }

}

//precondition: needs the data set and whether the calculations are population or sample
//postcondition: returns the kurtosis excess of the data set
double DescriptiveStats::FindKurtosisExcess() const
{
    //if the data set is less than or equal to 3, this will return the array without calculations
    if (size <= 3)
        return -1.0;

    double kurtosis = FindKurtosis();//we will call our findKurtosis function in order to 
    ////////////////////////////////////////////////use the kurtosis in our data in order to fund kurtosis excess

    if (isPopulation)////////////////if the user wants population calculation then the value below will be outputted
        return kurtosis - 3;//we will return kurtosis excess based on population calculation
    else//if the user chooses sample calculation then the value below will be outputted
    {
        double subtract = pow(static_cast<double>(size) - 1, 2) * 3;
        subtract /= (static_cast<double>(size) - 2) * (static_cast<double>(size) - 3);
        return kurtosis - subtract;//we will return kurtosis excess based on sample calculation
    }

}

//Precondition: int* array data set
//Postcondition: After calling out this function our program will return the coefficient of variation of our data set
//////////////// based on sample calculation
double DescriptiveStats::FindCoefficientOfVariation() const
{
    return (FindStandardDeviation() / FindMean());
}

//pre: needs the data set and whether the calculations are population or sample
//post: returns the relative standard deviation of the data set
double DescriptiveStats::FindRelativeSTDDeviation() const
{
    return FindCoefficientOfVariation() * 100;  // Relative SD is the same as CoV
}

//precondiiton: needs the data set
//postcondition: returns a pointer to a sized 3 array containing the data set's quartiles or a "NULL" if the data set is size 3 or less
double* DescriptiveStats::FindQuartiles() const
{

    double* quartiles = new double[3];  // Dynamically allocate space for quartiles
    int* tempArray = new int[size];
    copy(array, array + size, tempArray);
    sort(tempArray, tempArray + size);

    quartiles[1] = FindMedian();  // Q2 (Median)

    if (size % 2 == 0) {  // For even-sized arrays
        DescriptiveStats lowerHalf, upperHalf;
        for (int i = 0; i < size / 2; i++) {
            lowerHalf.setInput(tempArray[i]);
        }
        for (int i = size / 2; i < size; i++) {
            upperHalf.setInput(tempArray[i]);
        }
        quartiles[0] = lowerHalf.FindMedian();  // Q1
        quartiles[2] = upperHalf.FindMedian();  // Q3
    }
    else {  // For odd-sized arrays

        DescriptiveStats lowerHalf, upperHalf;
        for (int i = 0; i < size / 2; i++)
        {
            lowerHalf.setInput(tempArray[i]);
        }
        for (int i = (size / 2) + 1; i < size; i++)
        {
            upperHalf.setInput(tempArray[i]);
        }
        quartiles[0] = lowerHalf.FindMedian();  // Q1
        quartiles[2] = upperHalf.FindMedian();  // Q3
    }

    delete[] tempArray;
    return quartiles;
}

//precondition: int* array data set
//postcondititon: we will create a pointer that will hold the data of our vector and through calculations
//we will output the interquartile range of our data set
double DescriptiveStats::findIQR() const
{
    double* quartiles = FindQuartiles();
    double IQR = quartiles[2] - quartiles[0];  // IQR = Q3 - Q1
    delete[] quartiles;  // Free memory for quartiles
    return IQR;
}

//Precondition: int* array data set
//Postcondition: returns a pointer containing all the outliers in the dataSet
double* DescriptiveStats::FindOutliers() const
{

    double IQR = findIQR();
    double* outliers = new double[size];
    int outlierCount = 0;

    double* quartiles = FindQuartiles();
    double lowerBound = quartiles[0] - 1.5 * IQR;
    double upperBound = quartiles[2] + 1.5 * IQR;
    delete[] quartiles;

    for (int i = 0; i < size; i++)
    {

        if (array[i] < lowerBound || array[i] > upperBound)
        {
            outliers[outlierCount++] = array[i];  // Add outliers
        }
    }

    if (outlierCount == 0)
    {
        delete[] outliers;  // No outliers found, free memory
        return nullptr;
    }

    double* resultOutliers = new double[outlierCount];
    copy(outliers, outliers + outlierCount, resultOutliers);  // Copy to final outliers array
    delete[] outliers;
    return resultOutliers;
}

//Precondition: int* array data set
//Postcondition: Displays a frequency table of every index in the data set.
string DescriptiveStats::frequencyOfDataSet() const
{

    map<int, int> freqMap;
    for (int i = 0; i < size; i++)
    {
        freqMap[array[i]]++;
    }

    string result = "\n\n\t\tFrequency Table: \n";
    result += "\t\tVALUE: \t\tFREQUENCY:\t\tFREQUENCY %:\n";
    result += "\t\t" + string(60, '=') + "\n";

    for (auto& entry : freqMap)
    {
        result += "\t\t" + to_string(entry.first) + " \t\t\t " + to_string(entry.second) +
            " \t\t\t" + to_string(static_cast<float>(entry.second) / size * 100) + "%\n";
    }

    return result;
}

//precondition: takes the data set and whether it calculates based on population or sample
//postcondition: creates an output file with the data set and its calculations
void DescriptiveStats::printDataToFile(string fileName) const
{
    ofstream outFile(fileName);
    if (outFile.is_open())
    {
        outFile << *this;
        outFile.close();
    }
}

//precondition: int* array data set
//postcondtion: returns all integers in dynamic array
ostream& DescriptiveStats::displayArray(ostream& out) const
{
    out << "[ ";
    for (int i = 0; i < size; i++) {
        out << array[i];
        if (i != size - 1) out << ", ";
    }
    out << " ]\n";
    return out;

}

//precondiiton: needs the data set and wether the calculations are population or sample
//postcondition: displays the data set and its subsequent calculations
ostream& operator<<(ostream& out, const DescriptiveStats& obj)
{
    out << "\nData set contains " << obj.size << " data points:\n";
    obj.displayArray(out);

    // Output statistics
    out << "\nMinimum: " << obj.Findminimum();
    out << "\nMaximum: " << obj.Findmaximum();
    out << "\nRange: " << obj.Findrange();
    out << "\nMean: " << obj.FindMean();
    out << "\nMedian: " << obj.FindMedian();
    out << "\nMode: " << obj.FindMode();
    out << "\nStandard Deviation: " << obj.FindStandardDeviation();
    out << "\nVariance: " << obj.FindVariance();
    out << "\nMid Range: " << obj.FindMidRange();
    out << "\nSum of Squares: " << obj.FindSumOfSquares();
    out << "\nMean Absolute Deviation: " << obj.FindMeanAbsoluteDeviation();
    out << "\nRoot Mean Square: " << obj.FindRootMeanSquare();
    out << "\nStandard Error of Mean: " << obj.FindSTDErrorOfMean();
    out << "\nSkewness: " << obj.FindSkewness();
    out << "\nKurtosis: " << obj.FindKurtosis();
    out << "\nKurtosis Excess: " << obj.FindKurtosisExcess();
    out << "\nCoefficient of Variation: " << obj.FindCoefficientOfVariation();
    out << "\nRelative Standard Deviation: " << obj.FindRelativeSTDDeviation() << "%";

    double* quartiles = obj.FindQuartiles();
    out << "\nQuartiles: Q1 = " << quartiles[0] << ", Q2 = " << quartiles[1] << ", Q3 = " << quartiles[2];
    delete[] quartiles;

    out << "\nInterquartile Range (IQR): " << obj.findIQR();

    double* outliers = obj.FindOutliers();
    if (outliers != nullptr) {
        out << "\nOutliers: [ ";
        for (int i = 0; outliers[i] != '\0'; i++) {
            out << outliers[i];
            if (outliers[i + 1] != '\0') out << ", ";
        }
        out << " ]";
        delete[] outliers;
    }
    else {
        out << "\nOutliers: None";
    }

    out << obj.frequencyOfDataSet();

    return out;
}