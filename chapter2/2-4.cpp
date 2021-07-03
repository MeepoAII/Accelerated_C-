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
    string allstars(cols, '*');
    string middle_blank(cols-2, ' ');
    string middle_row = '*' + middle_blank + '*';
    string LR_blank(padX, ' ');
    string greeting_row = '*' + LR_blank + greeting + LR_blank + '*';


    // write a blank line to seperate the output from the input
    cout << endl;

    // write rows rows of output
    // invariant: we have written r rows so far
    for (int r = 0; r != rows; ++r)
    {
        if (r == 0 || r == rows - 1) cout << allstars << endl;
        else
        {
            if (r == padY + 1) cout << greeting_row << endl;
            else cout << middle_row << endl;
        }

    }

    return 0;
}