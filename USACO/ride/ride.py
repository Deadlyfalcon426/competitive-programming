"""
ID: ahsan.m1
LANG: PYTHON3
TASK: ride
"""
import sys
sys.stderr.write('loaded in') 
with open("ride.in", "r") as input_file:
    first = input_file.readline().strip()
    second = input_file.readline().strip()
sys.stderr.write('loaded in file') 
confirmations = []
alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
number_converted = [1] * 2
for character in first:
    number_converted[0] *= alphabet.index(character)+1
for character in second:
    number_converted[1] *= alphabet.index(character)+1
sys.stderr.write('did the list comprehensions')
number_converted[0] = number_converted[0]%47
number_converted[1] = number_converted[1]%47
sys.stderr.write("set up the list")
with open("ride.out", "w") as output_file:
    if number_converted[0]==number_converted[1]:
        output_file.write("GO\n")
    else:
        output_file.write("STAY\n")
sys.stderr.write('printed to file')