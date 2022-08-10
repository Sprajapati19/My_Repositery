import random

def Game():
    number = random.randint(1, 100)
    count = 0
    while(True):
        try:
            count += 1
            num = input("\nEnter your guess between 1 to 100 : ")

            if int(num) == number:
                print(
                    f"You have guessed correct number And your score is {count}.")
                with open("Score.txt", "r+") as f:
                    score = f.read()
                if count < int(score):
                    with open("Score.txt", "w") as f:
                        f.write(str(count))
                break

            elif int(num) > number and int(num) < 101:
                print("Your guess is larger, please guess small number.\n")

            elif int(num) < number and int(num) > 0:
                print("Your guess is smaller, please guess larger number.\n")

            else:
                print("\nEnter the number within range of 1 to 100.")

        except Exception:
            print("Invalid Entry! please enter a number.")


print("\n*****Welcome to the Number Guess Game*****")
while(True):
    num = int(input('''
Press 1 :- to play
Press 2 :- To Exit the Game\n
Enter your choice : '''))
    try:
        if num == 1:
            Game()
        elif num == 2:
            print("Thanks for playing the Game, Hope you have enjoyed it.")
            exit()
        else:
            print("Invalid Entry!")
    except Exception:
        print("Invalid entry! Enter 1 or 2.")