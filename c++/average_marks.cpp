#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter Range: ";
    cin >> n;

    string names[n];
    double marks[n];

    for (int i = 0; i < n; i++)
    {
        cout << endl << "Student " << (i + 1) << ": \n";
        cout << "Enter Name: ";
        cin >> names[i];

        cout << "Enter Marks: ";
        cin >> marks[i];
    }

    int highest = marks[0], lowest = marks[0], sum = 0, c;
    double avg;

    for (int i = 0; i < n; i++)
    {
        sum += marks[i];

        if (highest < marks[i])
        {
            highest = marks[i];
            c = i;
        }
        else if (lowest > marks[i])
        {
            lowest = marks[i];
        }
    }

    avg = sum / (double) n;
    cout << endl << "Marks:\nHighest: " << highest << " [" + names[c] + "]";
    cout << "\nLowest: " << lowest;
    cout << "\nAverage: " << avg << endl;

    return 0;
}