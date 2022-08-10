def IntToRoman(num):
    val = [1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000]
    rom = ['I', 'IV', 'V', 'IX', 'X', 'XL', 'L', 'XC', 'C', 'CD', 'D', 'CM', 'M']

    i = 12

    while num != 0:
        while i>=0:
            div = num//val[i]
            num = num % val[i]
            print(div*rom[i], end="")
            i = i-1

num = 85
IntToRoman(num)