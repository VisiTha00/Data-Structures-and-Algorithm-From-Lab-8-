#include <iostream>
#include <vector>

using namespace std;


vector<int> insertionSort(vector<int> numbers,int n){
    int length = n;
    numbers.g
    for(int i=1; i<length; i++){
        int value = numbers[i];
        int index = i;
        while(index > 0 && numbers[index-1]>value){
            numbers[index] = numbers[index-1];
            index = index - 1;
            }
            numbers[index] = value;
        }
        return numbers;
    }

double medianFinder(vector<int> numbers){
    double median = 0.0;
    if(numbers.size() % 2 == 1){
        int mid = (int)numbers.size()/2;
        median = (double)numbers[mid];
    }
    else{
        int mid = (int)numbers.size()/2;
        median = ((double)(numbers[mid-1] + numbers[mid]))/2;
    }
    return median;
}

int main()
{
    int number;
    int iter;
    vector<int> numbers;
    cout << "Enter the number of elements you want to input:- ";
    cin >> iter;
    for(int i = 0; i < iter; i++){
        cout << "Enter the number:- ";
        cin >> number;
        numbers.push_back(number);
        numbers = insertionSort(numbers,numbers.size());
        double median = medianFinder(numbers);
        cout << "Sorted" << "\t\t" << "Median"<< endl;
        cout<<"[ ";
        for(int i =0; i < numbers.size(); i++){
            cout <<numbers[i] <<" ";
        }
        cout<<"]\t\t";
        printf("%.1f \n",median);
    }
    return 0;
}
