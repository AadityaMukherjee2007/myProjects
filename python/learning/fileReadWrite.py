with open('text.txt', 'w') as f:
	f.writelines("Hello, World!")
	f.writelines("Python is awesome...")

with open('text.txt', 'r') as f:
	print(f.readlines())