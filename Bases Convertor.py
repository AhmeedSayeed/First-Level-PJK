#Noureldin Mohamed Amin    20230444
#Ahmed Sayed Ahmed	       20230021
#Ayman Mohamed Emam	       20230083


#Function to convert from binary to decimal
def binary_to_decimal(binary):
    binary = str(binary)
    lenBin = len(binary)
    decimal = 0

    for i in binary:
        if i == "1" or i == "0":
            if i == "1":
                decimal = decimal + (1 * (2 ** (lenBin - 1)))
            lenBin = lenBin - 1


    print("The decimal number is", decimal)



#Function to convert from binary to hexadecimal
def binary_to_hexa(binary):
    binary = str(binary)
    lenbin = len(binary)
    if lenbin % 4 == 1:
        binary = binary.zfill(lenbin + 3)
    elif lenbin % 4 == 2:
        binary = binary.zfill(lenbin + 2)
    elif lenbin % 4 == 3:
        binary = binary.zfill(lenbin + 1)
    lenbin = len(binary)
    hexa_output = ""
    power = 0
    sum_of_every_4nums = 0
    while (lenbin > 0):
        for i in range(0, 4):
            sum_of_every_4nums = sum_of_every_4nums + (2 ** power) * int(binary[lenbin - 1])
            power = power + 1
            lenbin = lenbin - 1
            if sum_of_every_4nums == 10:
                sum_of_every_4nums = "A"
            elif sum_of_every_4nums == 11:
                sum_of_every_4nums = "B"
            elif sum_of_every_4nums == 12:
                sum_of_every_4nums = "C"
            elif sum_of_every_4nums == 13:
                sum_of_every_4nums = "D"
            elif sum_of_every_4nums == 14:
                sum_of_every_4nums = "E"
            elif sum_of_every_4nums == 15:
                sum_of_every_4nums = "F"
        hexa_output = str(sum_of_every_4nums) + hexa_output
        sum_of_every_4nums = 0
        power = 0
    print("The number in hexa is", hexa_output)



#Function to convert from binary to octal
def binary_to_octal(binary):
    binary = str(binary)
    lenbin = len(binary)
    if lenbin % 3 == 1:
        binary = binary.zfill(lenbin + 2)
    elif lenbin % 3 == 2:
        binary = binary.zfill(lenbin + 1)
    lenbin = len(binary)
    octal_output = ""
    power = 0
    sum_of_every_3nums = 0
    while (lenbin > 0):
        for i in range(0, 3):
            sum_of_every_3nums = sum_of_every_3nums + (2 ** power) * int(binary[lenbin - 1])
            power = power + 1
            lenbin = lenbin - 1

        octal_output = str(sum_of_every_3nums) + octal_output
        sum_of_every_3nums = 0
        power = 0
    print("The number in octal is", octal_output)



#Function to convert from decimal to binary
def decimal_to_binary(decimal):
    decimal = int(decimal)
    binary = 0
    i = 1
    while decimal > 0:
        remainder = decimal % 2
        decimal = decimal // 2
        binary = binary + (remainder * i)
        i = i * 10

    print("The number in Binary is ", binary)



#Function to convert from decimal to hexadecimal
def decimal_to_hexa(decimal):
    decimal = int(decimal)
    hexa = []
    while decimal > 0:
        remainder = (decimal % 16)
        index = remainder
        if index == 10:
            index = "A"
        elif index == 11:
            index = "B"
        elif index == 12:
            index = "C"
        elif index == 13:
            index = "D"
        elif index == 14:
            index = "E"
        elif index == 15:
            index = "F"
        hexa.insert(0, str(index))
        decimal = decimal // 16
    hexastr = " "
    for i in hexa:
        hexastr += str(i)

    print("The number in hexadecimal is", hexastr)



#Function to convert from decimal to octal
def decimal_to_octal(decimal):
    decimal = int(decimal)
    octal = 0
    i = 1
    while decimal > 0:
        remainder = decimal % 8
        decimal = decimal // 8
        octal = octal + (remainder * i)
        i = i * 10

    print("The number in Octal is ", octal)



#Function to convert from hexa to binary
def hexa_to_binary(hexa):
    hexa = str(hexa)
    n = 1
    binary_output = " "
    for i in hexa:
        i = i.upper()
        if i == "A":
            i = 10
        elif i == "B":
            i = 11
        elif i == "C":
            i = 12
        elif i == "D":
            i = 13
        elif i == "E":
            i = 14
        elif i == "F":
            i = 15
        binary = 0
        n = 1
        i = int(i)
        while i > 0:
            remainder = i % 2
            i = i // 2
            binary = binary + (remainder * n)
            n = n * 10

        binary = str(binary).zfill(4)
        binary_output = binary_output + binary

    print("The number in Binary is ", binary_output)



#Function to convert from hexa to decimal
def hexa_to_decimal(hexa):
    hexa = str(hexa)
    lenhexa = len(hexa)
    decimal = 0

    for i in hexa:
        if i == "0" or i == "1" or i == "2" or i == "3" or i == "4" or i == "5" or i == "6" or i == "7" or i == "8" or i == "9" or i == "A" or i == "B" or i == "C" or i == "D" or i == "E" or i == "F" or i == "a" or i == "b" or i == "c" or i == "d" or i == "e" or i == "f":
            if i == "A" or i == "a":
                i = 10
            if i == "B" or i == "b":
                i = 11
            if i == "C" or i == "c":
                i = 12
            if i == "D" or i == "d":
                i = 13
            if i == "E" or i == "e":
                i = 14
            if i == "F" or i == "f":
                i = 15
            decimal = decimal + ((16 ** (lenhexa - 1)) * int(i))
            lenhexa = lenhexa - 1

    print("The decimal number is", decimal)



#Function to convert from hexa to octal
def hexa_to_octal(hexa):
    hexa = str(hexa)
    lenHexa = len(hexa)
    decimal = 0

    for i in hexa:
      if i.isdigit():
        decimal = decimal + ((16 ** (lenHexa - 1)) * int(i))
      elif i.upper() in ['A', 'B', 'C', 'D', 'E', 'F']:
        decimal = decimal + ((16 ** (lenHexa - 1)) * (ord(i.upper()) - ord('A') + 10))
      else:
        print("Error: Input is not a valid hexadecimal number.")
        break

      lenHexa = lenHexa - 1

    octal = 0
    i = 1

    while decimal > 0:
      remainder = decimal % 8
      decimal = decimal // 8
      octal = octal + (remainder * i)
      i = i * 10

    print("The Octal number is",octal)



#Function to convert from octal to binary
def octal_to_binary(octal):
    octal = str(octal)
    n = 1
    binary_output = " "
    for i in octal:
        binary = 0
        i = int(i)
        n = 1
        while i > 0:
            remainder = i % 2
            i = i // 2
            binary = binary + (remainder * n)
            n = n * 10

        binary = str(binary).zfill(3)
        binary_output = binary_output + binary

    print("The number in Binary is ", binary_output)



#Function to convert from octal to decimal
def octal_to_decimal(octal):
    octal = str(octal)
    lenoctal = len(octal)
    decimal = 0

    for i in octal:
        if i == "0" or i == "1" or i == "2" or i == "3" or i == "4" or i == "5" or i == "6" or i == "7" or i == "8":
            decimal = decimal + ((8 ** (lenoctal - 1)) * int(i))
            lenoctal = lenoctal - 1

    print("The decimal number is", decimal)



#Function to convert from octal to hexadecimal
def octal_to_hexa(octal):
    octal = str(octal)
    lenoctal = len(octal)
    decimal = 0

    for i in octal:
       if i == "0" or i == "1" or i == "2" or i == "3" or i == "4" or i == "5" or i == "6" or i == "7" or i == "8":
            decimal = decimal + ((8 ** (lenoctal - 1)) * int(i))
            lenoctal = lenoctal - 1
       else:
        print("Please enter a valid number")
        break


    hexa = []
    while decimal > 0:
        remainder = (decimal % 16)
        index = remainder
        if index == 10:
            index = "A"
        elif index == 11:
            index = "B"
        elif index == 12:
            index = "C"
        elif index == 13:
            index = "D"
        elif index == 14:
            index = "E"
        elif index == 15:
            index = "F"
        hexa.insert(0, str(index))
        decimal = decimal // 16
    hexastr = " "
    for i in hexa:
       hexastr += str(i)

    print("The number in hexadecimal is",hexastr)



#Start the Program: The UI
while True:
#Menu 1: Choose use the program or exit
  print("Menu 1")
  print("** Numbering system converter **")
  print("A) Insert a new number")
  print("B) Exit program")
  choice = input("Choose A or B: ")
  choice = choice.upper()
  if choice == "A":
    number = input("Enter a number: ") #Input the number on which operations are performed
    # Check if the choice is valid or not
  elif choice == "B":
     break
  else:
    print("Please select a valid choice")
    continue

#Menu 2: Choose the base of the number
  while True:
    print("Menu 2")
    print("** Please select the base you want to convert a number from **")
    print("A) Decimal")
    print("B) Binary")
    print("C) Octal")
    print("D) Hexadecimal")
    from_base = input("Choose A or B or C or D:")
    from_base = from_base.upper()
    # Check if the choice is valid or not
    if from_base == "A" or from_base == "B" or from_base == "C" or from_base == "D":
      break
    else:
      print("Please select a valid choice")
      continue
#Menu 3: Choose the base to which the number will be converted
  while True:
    print("Menu 3")
    print("** Please select the base you want to convert a number to **")
    print("A) Decimal")
    print("B) Binary")
    print("C) Octal")
    print("D) Hexadecimal")
    to_base = input("Choose A or B or C or D:")
    to_base =to_base.upper()
# Check if the choice is valid or not
    if to_base == "A" or to_base == "B" or to_base == "C" or to_base == "D":
      break
    else:
      print("Please select a valid choice")
      continue
#choose the operation, Depending on the Bases which were selected
  if from_base == "A" and to_base == "A":
     print("The number in Decimal is ",number)
  elif from_base == "B" and to_base == "B":
     print("The number in Binary is ",number)
  elif from_base == "C" and to_base == "C":
     print("The number in Octal is ",number)
  elif from_base == "D" and to_base == "D":
     print("The number in Hexadecimal is ",number)
  elif from_base == "A" and to_base == "B":
     decimal_to_binary(number)
  elif from_base == "A" and to_base == "C":
     decimal_to_octal(number)
  elif from_base == "A" and to_base == "D":
     decimal_to_hexa(number)
  elif from_base == "B" and to_base == "A":
     binary_to_decimal(number)
  elif from_base == "B" and to_base == "C":
     binary_to_octal(number)
  elif from_base == "B" and to_base == "D":
     binary_to_hexa(number)
  elif from_base == "C" and to_base == "A":
     octal_to_decimal(number)
  elif from_base == "C" and to_base == "B":
     octal_to_binary(number)
  elif from_base == "C" and to_base == "D":
     octal_to_hexa(number)
  elif from_base == "D" and to_base == "A":
     hexa_to_decimal(number)
  elif from_base == "D" and to_base == "B":
     hexa_to_binary(number)
  elif from_base == "D" and to_base == "C":
     hexa_to_octal(number)