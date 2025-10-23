while True:	 # infinite while loop
	a = float(input("Enter 1st. Number: "))  # Takes input from user and stores the value in the variable 'a'
	b = float(input("Enter 2nd. Number: "))  # Takes input from user and stores the value in the variable 'b'

	if a == 0.0 and b == 0.0:  # If condition is true statement will be executed
		break
		
	print("\nOperations: \n '+' --> addition\n '-' --> subtraction\n '*' --> multiplication\n '/' --> division\n\n")  # Prints out the text in "  "
	op = input("Enter Operator: ")  # Takes input from user and stores the value in the variable 'op'

	if op == '0':  # If condition is true statement will be executed
		break
	
	if op == '+':  # If condition is true statement will be executed
		c = a + b
	elif op == '-':  # If condition is true statement will be executed
		c = a - b
	elif op == '*':  # If condition is true statement will be executed
		c = a * b
	elif op == '/':  # If condition is true statement will be executed
		c = a / b
					
	print("Answer = " + str(c) + "\n")  # Prints out the text in "  "
