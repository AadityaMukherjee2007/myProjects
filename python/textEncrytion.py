txt = input("Text: ")
key = int(input("Key: "))

enTxt = ""
x = 0

while (x < len(txt)):
    enTxt += chr(ord(txt[x]) + key)
    x += 1

print("Encryted Text: " + enTxt)
