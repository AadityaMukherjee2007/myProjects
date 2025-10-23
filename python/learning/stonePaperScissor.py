import random
import sys

option = ['stone', 'paper', 'scissor']
player_score = 0
computer_score = 0
scoreDifference = 0

def compute(player, computer):
    global computer_score, player_score, scoreDifference
    if player == computer:
        print('Draw')
    elif player == option[0] and computer == option[1]:
        print('Computer Wins!')
        computer_score += 1
    elif player == option[1] and computer == option[0]:
        print('Player Wins!')
        player_score += 1
    elif player == option[0] and computer == option[2]:
        print('Player Wins!')
        player_score += 1
    elif player == option[2] and computer == option[0]:
        print('Computer Wins!')
        computer_score += 1
    elif player == option[1] and computer == option[2]:
        print('Computer Wins!')
        computer_score += 1
    elif player == option[2] and computer == option[1]:
        print('Player Wins!')
        player_score += 1

    scoreDifference = abs(computer_score - player_score)
    
    print('Player Score:', player_score)
    print('Computer Score:', computer_score)


def play():
    player = 0
    while True:
        player = int(input("\nPlayer: "))

        if player < 1 or player > 3:
            print('Error')
            continue
        else:
            break

    comp = random.choice(option)
    compute(option[player - 1], comp)

print('''
Options:
1 --> Stone
2 --> Paper
3 --> Scissor
''')

while True:
    if scoreDifference == 3:
        sys.exit() 
    play()
