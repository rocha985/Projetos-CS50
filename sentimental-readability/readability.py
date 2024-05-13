import math

text = input("text")


def count_letters(text):
    letters = 0
    for char in text:
        if char.isalpha():
            letters += 1
    return letters


def count_words(text):
    words = len(text.split())
    return words


def count_sentences(text):
    sentences = 0
    for char in text:
        if char in [".", "!", "?"]:
            sentences += 1
    return sentences


letters = count_letters(text)
words = count_words(text)
sentences = count_sentences(text)

l = letters / words * 100
s = sentences / words * 100
points = (0.0588 * l) - (0.296 * s) - 15.8

if points >= 16:
    print("Grade 16+")
elif points < 1:
    print("Before Grade 1")
else:
    print(f"Grade {round(points)}")
