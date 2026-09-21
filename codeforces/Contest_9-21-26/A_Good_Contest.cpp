#include <iostream>
using namespace std;

#define int long long

signed main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_cases;
    cin >> test_cases;
    for (int tcase = 0; tcase < test_cases; tcase++) {
        int num_participants;
        cin >> num_participants;
        int uno, dos, tres;
        cin >> uno >> dos >> tres;
        uno=num_participants-uno;
        dos=num_participants-dos;
        tres=num_participants-tres;
        int maxx = max(max(uno, dos) , max(dos, tres));
        cout << maxx << "\n";
    }
    return 0;
}