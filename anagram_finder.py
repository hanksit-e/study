def word_to_dict(word):
    word_dict = dict()
    for ch in word:
        if ch not in word_dict:
            word_dict[ch] = 1
        else:
            word_dict[ch] += 1
    return word_dict


def is_anagram(word1, word2):
    return word_to_dict(word1) == word_to_dict(word2)


def main():
    print("Enter word: ", end='')
    target = input()
    print("Enter file name: ", end='')
    fname = input()
    with open(fname, 'r') as file:
        for line in file:
            if is_anagram(line.strip().lower(), target):
                print(line.strip())


if __name__ == '__main__':
    main()

