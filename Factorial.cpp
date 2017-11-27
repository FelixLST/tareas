#include <iostream>
using namespace std;
double factorial(int);
int main()
{   int n;
    cout << "Introduzca numero: ";
    cin >> n;
    cout << "factorial: " << factorial(n) << endl;
    
}
long double factorial(int n)
{
    long double fact;
    if (n==0)
        return 1;
    else
         return n*factorial(n-1);
} 
