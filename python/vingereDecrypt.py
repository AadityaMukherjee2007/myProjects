def vigenere_decrypt(ciphertext, key):
    decrypted_text = ""
    key = key.upper()
    key_index = 0

    for char in ciphertext:
        if char.isalpha():
            shift = ord(key[key_index]) - ord('A')
            if char.islower():
                base = ord('a')
            else:
                base = ord('A')
            decrypted_char = chr((ord(char) - base - shift) % 26 + base)
            decrypted_text += decrypted_char
            key_index = (key_index + 1) % len(key)
        else:
            decrypted_text += char

    return decrypted_text

print(vigenere_decrypt("vrpefbgltjeendid", "ecrm"))