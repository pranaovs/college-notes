def transposition_decrypt(cipher, key):
    n = len(cipher)
    col_lengths = [n // key] * key
    for i in range(n % key):
        col_lengths[i] = col_lengths[i] + 1
    columns = [""] * key
    index = 0
    for i in range(key):
        for _ in range(col_lengths[i]):
            columns[i] = columns[i] + cipher[index]
            index = index + 1
    plaintext = ""
    for row in range(max(col_lengths)):
        for col in range(key):
            if row < len(columns[col]):
                plaintext = plaintext + columns[col][row]

    print("Decrypted:", plaintext)


cipher1 = "H cb  irhdeuousBdi   prrtyevdgp nir  eerit eatoreechadihf paken ge b te dih aoa.da tts tn"
key = 9
transposition_decrypt(cipher1, key)
