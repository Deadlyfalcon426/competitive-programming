#include <iostream>
using namespace std;
int main() {
    int W;
    cin >> W;
    int part1;
    int part2;

    if (W==2){
        cout << "NO";
    } else if (W%2==0){
        cout << "YES";
    } else{
        cout << "NO";
    }
}