def subsequences(s):
    if len(s) == 0:
        return ['']
    else:
        rest = subsequences(s[1:])
        result = []
        for item in rest:
            result.append(item)
            result.append(s[0] + item)
        return result

string = input('Masukkan string: ')
print(subsequences(string))
