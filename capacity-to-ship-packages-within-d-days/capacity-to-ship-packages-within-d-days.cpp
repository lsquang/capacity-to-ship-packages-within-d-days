 
#include <iostream>
#include <vector>

using namespace std;


int count_day(vector<int>& weights, int max_weight) {
    int number_day = 1;
    int current_weight = 0;
    for (int value : weights) {
        current_weight += value;
        if (current_weight > max_weight) {
            number_day++;
            current_weight = value;
        }        
    }
    return number_day;
}

int shipWithinDays(vector<int>& weights, int D) {
    int min_weight = 0;
    int max_weight  = 0;
    for (int value : weights) {
        max_weight += value;
    }

    for (int value : weights) {
        if (value > min_weight) {
            min_weight = value;
        }
    }
    while (min_weight < max_weight) {
        int mid = (min_weight + max_weight) / 2;
        int number_of_day = count_day(weights, mid);
        if (number_of_day <= D) {
            max_weight = mid;
        }
        else {
            min_weight = mid + 1;
        }
    }

    return max_weight;
}

int main()
{
    vector<int> weights = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    cout << shipWithinDays(weights, 5) << endl;
}
 