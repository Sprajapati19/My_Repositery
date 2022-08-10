sum = 0
GoodsPrice = []
GoodsName = []
while(True):
    UserInput = input("Enter the price of item or Press q to exit : \n")
    try:
        if UserInput != "q":
            sum += int(UserInput)
            GoodsPrice.append(int(UserInput))
            Name = input("Enter the name of item : ")
            GoodsName.append(Name)
            print(f"Order total so far : {sum}")

        else:
            print(
                f"Thanks for Purchasing goods! your total Bill price is {sum}")
            break

    except Exception:
        print("Invalid Entry! Try again.")

print("\n*****Sri Ram Kirana Store*****")
for i, item in enumerate(GoodsPrice):
    for j in range(1):
        print(f"{i+1}) {GoodsName[i]} : Rs{item}")

print("""---------------
Total = """, sum)