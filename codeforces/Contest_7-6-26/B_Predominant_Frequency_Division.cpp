//bismillah
#include <iostream>
using namespace std;

int main(){
    //input
    int test_cases;
    cin >> test_cases;
    for (int tcase = 0; tcase<test_cases; tcase++){
        int length;
        cin >> length;
        int stage = 1;
        int one_count = 0;
        int two_count = 0;
        int three_count = 0;
        int stage_length = 0;
        int current;
        bool it_worked = false;
        bool extra_three_flag = false;
        for(int i = 0; i<length;i++){
            cin >> current;
            stage_length++;
            if(current==1){
                one_count++;
            }else if(current==2){
                two_count++;
            } else{
                three_count++;
            }
            //so this above has read in the new item
            if(stage==1){
                if(one_count>=two_count+three_count  && stage_length!=0){
                    if(one_count>two_count+three_count){
                        extra_three_flag=true;
                    }
                    one_count=0;
                    two_count=0;
                    three_count=0;
                    stage=2;
                    stage_length=0;
                    continue;
                }
            }
            if(stage==2){
                if(extra_three_flag==true && current==3){
                    three_count=0;
                    stage_length=0;
                    extra_three_flag=false;
                }
                if(one_count+two_count>=three_count && stage_length!=0){
                    one_count=0;
                    two_count=0;
                    three_count=0;
                    stage=3;
                    stage_length=0;
                    continue;
                }
            }
            if(stage==3 && stage_length!=0){
                it_worked=true;
            }
        }
        //final thingy
        if(it_worked){
            cout<<"YES"<<"\n";
        } else{
            cout<<"NO"<<"\n";
        }
    }
    
}
    /*
    what are scenarios
    lets see
    what if we iterate through, in stages yeah
    so we go through and keep track of how many 1s we have
    1s are our greatest resource, we would be happy with just [1,1,1]
    2 is ok, ideally in the middle, not ideally in the start
    3 is an op fr, we wanna be eliminating those guys using the last section
    I THINK
    PERHAPS
    WE FIND WORKING REGIONS, THEN WE DUMP REST IN THE LAST PART
    from the problem:
        For example, the array [2,1,1,3,3,1,2,3]
        can be split into three parts: [2,1,1,3]
        , [3,1,2]
        , and [3]
        . And the array [2,1,3,3,3,2,3]
        cannot be split in such a way.
    for the first one we could look until we got our thing
    so then [2,1], [1], [3,3,1,2,3]
    fairs or nah?
    but i feel like edge cases would obliterate this
    also this thing assumes its always working, i would need a model that detects when shi not gonna work
    so we need to be aware of which section we are in, and if we run out of space for next section we have an issue
    all sections have to work, so if the first section doesnt work there is a problem
    in the first section, WE MUST BE GREEDY AND USE ALL THE ONES SINCE WE CANNOT ACCOMODATE 2
    IN THE SECOND ITS ALL OR NOTHING AND THEN DUMP ALL OF THE 3 INTO LAST
    THIS LOWK MIGHT WORK
    alr bro legendary comeback here we go time to implement

    alr one singular edge case got me where the first section unfortunately could not be greedy
    what if we allowed the first edge case to take on as much as it could bear
    say if length is greater than 3, then we allow the 1st section to take on an extra three
    this is gonna be a pain to implement but i think this can fix it
    actually not even if length is greater than three...
    because if the 1st section takes on an extra three that would otherwise belong to sect. 2
    then sect 2 woulnt be able to handle it regardless
    ok so im worried there will be another edge case but i think we just implement this one and submit
    
    ok submitted again and wrong answer on test 2 so yeah we fried on edge cases
    probably went too hard on implementation
    well wtf was i supposed to do

    yeah ion know how to fix this 😂✌️ lowk might give up
    the code is so shitty i dont think it can be fixed

    alr all or nothing from the half-court, i think the bug was that the flag never changed and just kept allowing the second section to bypass the the first 3
    WHAAATATTSTTATATTA IT WOOROOOREKKKKSKSKK
    MY VICTORY IS DUE TO ALLAH SWT
    ALHAMDULILAH
    */
