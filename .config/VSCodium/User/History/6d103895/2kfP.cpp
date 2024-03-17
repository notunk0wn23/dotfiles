#include <iostream>
using namespace std;

int main()
{
    int num1, num2, sum;

    const string welcome = "Welcome to the simplest calculator on earth.";
    cout << welcome << endl;

    cout << "Enter Number 1 \n "
    cin >> num1

    cout << "Enter Number 2 \n "
    cin >> num2

    sum = num1 + num2

    cout << "The sum of " << num1 << " And " << num2 << " Is " << sum 
    cout << "Press enter to exit." << endl;
    cin.get();
    return 0;
}