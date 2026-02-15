"""
ID: ahsan.m1
LANG: PYTHON3
TASK: gift1
"""
import sys
sys.stderr.write('loaded in')
gift_accounts = {
}

with open("gift1.in", "r") as input_file:
    #five people, names. then after
    number_of_people = int(input_file.readline().strip())
    for gift_giver in range(number_of_people):
        gift_accounts[input_file.readline().strip()] = 0
    #accounts have been set up and tested
    #block: gift giver, \n, money, people
    for person in gift_accounts:
        gift_giver = input_file.readline().strip()
        money_and_people_to_give = input_file.readline().strip().split(" ")
        #make sure they are integers
        money_and_people_to_give[0] = int(money_and_people_to_give[0])
        money_and_people_to_give[1] = int(money_and_people_to_give[1])
        #take out his money
        gift_accounts[gift_giver] -= money_and_people_to_give[0]
        #now decide how much to give and keep
        if money_and_people_to_give[1] != 0:
            per_person_money = money_and_people_to_give[0]//money_and_people_to_give[1]
            gift_accounts[gift_giver] += money_and_people_to_give[0]%money_and_people_to_give[1]
        else:
            per_person_money = 0
            gift_accounts[gift_giver] += money_and_people_to_give[0]
        for gift_reciever in range(int(money_and_people_to_give[1])):
            gift_accounts[input_file.readline().strip()] += per_person_money

with open ("gift1.out", "w") as output_file:
    for person in gift_accounts:
        output_file.write(f"{person} {gift_accounts[person]}\n")

"""
name of gift giver
money number of people 
then said people in a list
so we will probably use that number of people to iterate and know how many ppl
EZ dubs
"""
"""
side notes:
we will probably need like a accounts list of integers
"""
