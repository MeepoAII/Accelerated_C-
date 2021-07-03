#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    // ask for the person's name
    cout << "Please enter your first name: ";

    // read the name
    string name;
    cin >> name;

    // build the message that we intend to write
    const string greeting = "Hello, " + name + "!";

    // the number of blanks surrounding the greeting

    int padX;
    int padY;
    cout << "padX: ";
    cin >> padX;
    cout << endl;
    cout << "padY: ";
    cin >> padY;

    // the number of rows and columns to write
    const int rows = padY * 2 + 3;
    const string::size_type cols = greeting.size() + padX * 2 + 2;

    // write a blank line to seperate the output from the input
    cout << endl;

    // write rows rows of output
    // invariant: we have written r rows so far
    for (int r = 0; r != rows; ++r)
    {
        string::size_type c = 0;
        while (c != cols)
        {
            if (r == padY + 1 && c == padX + 1)
            {
                cout << greeting;
                c += greeting.size();
            }
            else
            {
                if (r == 0 || r == rows - 1 ||
                c == 0 || c == cols - 1)
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
                ++c;
            }
        }
        cout << endl;
    }

    return 0;
}