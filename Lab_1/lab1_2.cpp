#include<iostream>
#include<fstream>

using namespace std;

long long int a, b;
int main() {
    ifstream file1;
    file1.open("aplusbb.in");
    ofstream file2;
    file2.open("aplusbb.out"); 
    file1 >> a >> b;
    file2 << (a+(b*b)) << endl;
    return 0;
}