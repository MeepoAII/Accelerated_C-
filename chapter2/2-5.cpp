#include <iostream>
#include <string>
using namespace std;

int main()
{
    const int square_length = 5;
    const int rectangle_long = 6;
    const int rectangle_short = 4;
    const int triangle_length = 8;

    // square
    string square_side(square_length, '*');
    string square_blank(square_length - 2, ' ');
    string square_middle_row = '*' + square_blank + '*';
    for (int i = 0; i < square_length; ++i)
    {
        if (i == 0 || i == square_length - 1) cout << square_side << endl;
        else cout << square_middle_row << endl;
    }

    // rectangle
    //略

    // triangle
    for (int i = 0; i < triangle_length; ++i)
    {
        if (i == 0) cout << '*' << endl;

        if (i == triangle_length - 1)
        {
            string triangle_allstar(i+2, '*');
            cout << triangle_allstar << endl;
        }
        else
        {
            string tmp(i, ' ');
            cout << '*' << tmp << '*' << endl;
        }
        
        
    }



}