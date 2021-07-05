#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<double>::size_type vec_sz;


int main()
{
    vector<double> dataset{1, 2, 4, 0, 9, -3, 9, 4, 93, 45, 100};
    double Q1, Q2, Q3;
    
    // sort first
    sort(dataset.begin(), dataset.end());
    vec_sz size = dataset.size();
    
    vec_sz mid = size / 2;

    if (size % 2 == 0)
    {
        Q2 = (dataset[mid-1] + dataset[mid]) / 2;
        Q1 = dataset[mid/2];
        Q3 = dataset[(mid+size)/2];
    }
    else
    {
        Q2 = dataset[mid];
        Q1 = dataset[mid/2];
        Q3 = dataset[(mid+size)/2];
    }

    cout << "Q1, Q2, Q3: " << Q1 << " " << Q2 << " " << Q3 << endl;

    


}