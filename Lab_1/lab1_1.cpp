#include<iostream>
#include<fstream>

using namespace std;

long long int a, b;
int main() {
    ifstream file1;
    file1.open("aplusb.in");
    ofstream file2;
    file2.open("aplusb.out"); 
    file1 >> a >> b;
    file2 << a+b << endl;
    return 0;
}