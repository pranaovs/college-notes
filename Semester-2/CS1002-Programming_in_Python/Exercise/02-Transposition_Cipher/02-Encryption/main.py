def transposition(temp, key):
    temp1 = []
    temp2 = []
    temp1 = list(temp)
    for i in range(0, key):
        temp2.append(temp1[i])
    for j in range(key, len(temp1)):
        for k in range(0, key):
            if j % key == k:
                temp2[k] = temp2[k] + temp1[j]
    temp = ""
    for i in temp2:
        temp = temp + i
    print(temp)


temp1 = "Underneath a huge oak tree there was of swine a huge company,"
temp2 = "That grunted as they crunched the mast: For that was ripe and fell full fast."
key = 7
transposition(temp1, key)
transposition(temp2, key)

