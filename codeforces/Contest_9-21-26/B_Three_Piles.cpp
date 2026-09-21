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
        /*if bob adds, B gets bigger, meaning the overall thing shifts negatively
        if alice adds, A gets bigger, meanign the overall thing shifts postivly
        is it more optimal to get pos or neg
        this depends on the original set up
        we want to accentuate the original thing
        nvm bob wants closest to zero and alice wants to be far from it
        so we need to simulate each step then
        situations -> if we are already negative
                            alice makes decision
                            subtract by bob and take the loss
                            or take everything to get greater than bob
                            answer -> max (  abs(alice-bob) ,  (alice+pile-bob)  )
                            bob isnt gonna take more because he doesnt want to make anna have even more
                    if we are pos
                            anna lowk wants to just take everything and bob cant do nything abt it
                            yeah because wtf can bob do, anna just eats everything and 
                    if we are zero/equal
                            again anna just takes everything and easily crosses the gap
                            */
        int alice, bob, pile;
        cin >> alice >> bob >> pile;
        if(alice-bob<0){
            cout << max(abs(alice+pile-bob), abs(alice-bob)) << "\n";
        } else{
            cout << abs(alice+pile-bob) << "\n";
        }
    }
    return 0;
}