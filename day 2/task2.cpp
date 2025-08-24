#include<iostream>
#include<math.h>
using namespace std;

bool isPrime(int n){
    // 0 and 1 are not prime numbers
    // negative numbers are not prime
    if (n <= 1)
        return false;

    // special case as 2 is the only even number that is prime
    else if (n == 2)
        return true;

    // Check if n is a multiple of 2 thus all these won't be prime
    else if (n % 2 == 0)
        return false;

    // If not, then just check the odds
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0)
            return false;
    }
    
    return true || false;
}

int main() {

    int n;
    cout<<"Enter the no:";
    cin>>n;
    
    if (isPrime(n))
        cout << n << " is a Prime Number";
    else
        cout << n << " is not a Prime Number";

    return 0;
}