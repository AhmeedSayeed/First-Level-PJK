#Noureldin Mohamed Amin    20230444
#Ahmed Sayed Ahmed	       20230021
#Ayman Mohamed Emam	       20230083


#Function to compute one's complement
def ones_complement(binary):
    ones_complement = ""
    for i in binary:
        if i == "1" or i == "0":
            if i == "1":
                ones_complement += "0"
            elif i == "0":
                ones_complement += "1"

    print("The one's complement of {} is {}".format(binary, ones_complement))



#Function to compute two's complement
def twos_complement(binary):
    ones_complement = ""
    for i in binary:
        if i == "1" or i == "0":
            if i == "1":
                ones_complement += "0"
            elif i == "0":
                ones_complement += "1"

    carry = 0
    result = " "
    binary1 = "1"
    if len(binary1) > len(ones_complement):
        max_length = len(binary1)
    else:
        max_length = len(ones_complement)
    binary1 = binary1.zfill(max_length)
    ones_complement = ones_complement.zfill(max_length)
    for i in range(max_length - 1, -1, -1):
        if int(binary1[i]) + int(ones_complement[i]) + carry == 0:
            result = "0" + result
            carry = 0
        elif int(binary1[i]) + int(ones_complement[i]) + carry == 1:
            result = "1" + result
            carry = 0
        elif int(binary1[i]) + int(ones_complement[i]) + carry == 2:
            result = "0" + result
            carry = 1
        elif int(binary1[i]) + int(ones_complement[i]) + carry == 3:
            result = "1" + result
            carry = 1
    if carry == 1:
        result = "1" + result

    print("The two's complement of {} is {}".format(binary,result))



#Function to compute Addition
def addition(binary1,binary2):
    carry = 0
    result = " "
    if len(binary1) > len(binary2):
        max_length = len(binary1)
    else:
        max_length = len(binary2)
    binary1 = binary1.zfill(max_length)
    binary2 = binary2.zfill(max_length)
    for i in range(max_length - 1, -1, -1):
        if int(binary1[i]) + int(binary2[i]) + carry == 0:
            result = "0" + result
            carry = 0
        elif int(binary1[i]) + int(binary2[i]) + carry == 1:
            result = "1" + result
            carry = 0
        elif int(binary1[i]) + int(binary2[i]) + carry == 2:
            result = "0" + result
            carry = 1
        elif int(binary1[i]) + int(binary2[i]) + carry == 3:
            result = "1" + result
            carry = 1
    if carry == 1:
        result = "1" + result

    print("The addition of two binary numbers = ",result)



#Function to compute Subtraction
def subtraction(binary1, binary2):
    if len(binary1) > len(binary2):
        max_length = len(binary1)
    else:
        max_length = len(binary2)
    binary1 = binary1.zfill(max_length)
    binary2 = binary2.zfill(max_length)
    sub = ""
    ones_comp_bin2 = ""  #one's complement for binary 2
    sum_bin1_ones_com_bin2 = ""  # sum of binary1 and  one's comp of bin2
    if binary1 == binary2:
        sub = "0"
    elif binary1 > binary2:
        for i in binary2:
            if i == "1" or i == "0":
                if i == "1":
                    ones_comp_bin2 += "0"
                elif i == "0":
                    ones_comp_bin2 += "1"
        carry = 0
        for i in range(max_length - 1, -1, -1):
            if int(binary1[i]) + int(ones_comp_bin2[i]) + carry == 0:
                sum_bin1_ones_com_bin2 = "0" + sum_bin1_ones_com_bin2
                carry = 0
            elif int(binary1[i]) + int(ones_comp_bin2[i]) + carry == 1:
                sum_bin1_ones_com_bin2 = "1" + sum_bin1_ones_com_bin2
                carry = 0
            elif int(binary1[i]) + int(ones_comp_bin2[i]) + carry == 2:
                sum_bin1_ones_com_bin2 = "0" + sum_bin1_ones_com_bin2
                carry = 1
            elif int(binary1[i]) + int(ones_comp_bin2[i]) + carry == 3:
                sum_bin1_ones_com_bin2 = "1" + sum_bin1_ones_com_bin2
                carry = 1
        if carry == 1:
            sum_bin1_ones_com_bin2 = "1" + sum_bin1_ones_com_bin2

        if len(sum_bin1_ones_com_bin2) <= max_length:
            for i in sum_bin1_ones_com_bin2:
                if i == "1" or i == "0":
                    if i == "1":
                        sub += "0"
                    elif i == "0":
                        sub += "1"

        elif len(sum_bin1_ones_com_bin2) > max_length:
            len_sum_bin1_ones_com_bin2 = len(sum_bin1_ones_com_bin2)
            sum_bin1_ones_com_bin2 = list(sum_bin1_ones_com_bin2)
            sum_bin1_ones_com_bin2[0] = "0"
            overflow = "1"  # add to result
            overflow = overflow.zfill(len_sum_bin1_ones_com_bin2)
            carry = 0
            for i in range(len_sum_bin1_ones_com_bin2 - 1, -1, -1):
                if int(sum_bin1_ones_com_bin2[i]) + int(overflow[i]) + carry == 0:
                    sub = "0" + sub
                    carry = 0
                elif int(sum_bin1_ones_com_bin2[i]) + int(overflow[i]) + carry == 1:
                    sub = "1" + sub
                    carry = 0
                elif int(sum_bin1_ones_com_bin2[i]) + int(overflow[i]) + carry == 2:
                    sub = "0" + sub
                    carry = 1
                elif int(sum_bin1_ones_com_bin2[i]) + int(overflow[i]) + carry == 3:
                    sub = "1" + sub
                    carry = 1
            if carry == 1:
                sub = "1" + sub
    print("The subtraction of two binary numbers = ", sub)



#Start the Program: The UI
while True:
#Menu 1: Choose use the program or exit
   print("Menu 1")
   print("** binary calculator **")
   print("A) insert a new number")
   print("B) Exit ")
   choice = input("Choose A or B: ")
   choice = choice.upper()
# Check if the choice is valid or not
   if choice == "A":
    #Input the number on which operations are performed and check if the number is binary or not
      while True:
          number1 = input("Enter a binary number: ")
          number_Check = int(number1)
          while number_Check > 0:
              if (number_Check % 10) != 1 and (number_Check % 10) != 0:
                  print(number1, "is not a binary number. Please insert a valid binary number")
                  break
              number_Check = number_Check // 10
          else:
              break

   elif choice == "B":
     break
   else:
    print("please select a valid choice")
    continue

#Menu 2: Choose the base of the number
   while True:
      print("Menu 2")
      print("** please select the operation **")
      print("A) Compute one's complement")
      print("B) Compute two's complement")
      print("C) addition")
      print("D) subtraction")
      operation = input("Please select an operation: ")
      operation = operation.upper()
      # Check if the choice is valid or not
      if operation == "A" or operation == "B" or operation == "C" or operation == "D":
         break
      else:
         print("please select a valid choice")
         continue
# choose the operation, Depending on the choices which were selected
   if operation == "A":
        ones_complement(number1)
   elif operation == "B":
        twos_complement(number1)
   elif operation == "C" or operation == "D" :
       # Input the second number on which operations are performed and check if the number is binary or not
       while True:
           number2 = input("Please insert the second number: ")
           number_Check2 = int(number2)
           while number_Check2 > 0:
               if (number_Check2 % 10) != 1 and (number_Check2 % 10) != 0:
                   print(number2, "is not a binary number. Please insert a valid binary number")
                   break
               number_Check2 = number_Check2 // 10
           else:
               break
       if operation == "C":
            addition(number1, number2)
       elif operation == "D":
            subtraction(number1, number2)