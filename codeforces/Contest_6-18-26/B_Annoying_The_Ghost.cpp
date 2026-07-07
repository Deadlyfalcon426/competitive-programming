//bismillah
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    //input
    int test_cases;
    cin >> test_cases;
    for (int tcase = 0; tcase<test_cases; tcase++){
        int num_numbers;
        cin >> num_numbers;
        vector<int> final_array;
        vector<int> beginning_array;
        vector<int> sorted_array;
        vector<bool> correct_position; correct_position.resize(num_numbers);
        vector<int> far_off; far_off.resize(num_numbers);
        int temp;
        //fill in original array
        for(int i = 0; i<num_numbers;i++){
            cin >> temp;
            beginning_array.push_back(temp);
        }
        //fill in final product array
        for(int i = 0; i<num_numbers;i++){
            cin >> temp;
            final_array.push_back(temp);
            
        }
        //create sorted original array
        sorted_array=beginning_array;
        sort(sorted_array.begin(), sorted_array.end());
        bool is_working = true;
        for(int i = 0; i<num_numbers;i++){
            if(sorted_array[i]>final_array[i]){
                is_working=false;
                break;
            }
        }
        if(is_working==false){
            cout<<"-1\n";
            continue;
        }
        //alright remember the correct positions thing
        //lets put it to use
        //by filling in places where they are far off
        //perhaps like lowk pointing out where the closest thing is.
        //in the end, our main goal is preventing swaps
        vector<int> indexes;
        indexes.resize(num_numbers);
        //listing all indexes of dudes
        for(int i = 0; i<num_numbers;i++){
            indexes[i] = find(beginning_array.begin(), beginning_array.end(), sorted_array[i]) - beginning_array.begin();
        }
        //alright going out on a limb here
        // we know its possible to add to all of them and get the numbers we need
        //im going to wing an algorithm to iterate over the indexes and add the correct amount to the main thingie
        for(int i = 0; i<num_numbers;i++){
            beginning_array[indexes[i]] = final_array[i];
        }
        //lets lowk check if those guys are already in the right spot
        for(int i = 0; i<num_numbers;i++){
            if(final_array[i]==beginning_array[i]){
                correct_position[i]=true;
            }
        }
        //above has to work because we already know its possible to add to everything to get what we want
        //alr lowk time for the big dude, the sorting
        //also btw theres no way it isnt possible if we have the numbers
        //insertion sort here-a we-a go
        
        int swap_counter = 0;
        /*
        for(int i = 1; i<num_numbers;i++){
            int key = beginning_array[i];
            int j = i-1;
            while(j>=0 && beginning_array[j]>=key){
                beginning_array[j+1] = beginning_array[j];
                j-=1;
                swap_counter++;
            }
            beginning_array[j+1] = key;
        }
        */
        //lets lowk try like smth new
        for(int i = 0;i<num_numbers;i++){
            if(correct_position[i]==false){
                swap_counter+=abs(i-(find(beginning_array.begin(), beginning_array.end(), final_array[i])-beginning_array.begin()));
            }
        }
        cout<<swap_counter<<"\n";
    }
}