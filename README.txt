-------------------------------
Bulls and Cows - Project Mleko
-------------------------------

1. Main information about project
	This is my implementaion of Bulls and Cows game. It's written in C++ and
	dont't use 3rd party libraries. There are no GUI, the game works in console.
	You're free to share, modify and use source code of game for non-commercial use

Basic Rules: You get the sequence and number of tries (lives). Symbols (both numbers or
letters) are unique and don't repeat in single sequence. You make a guess and getting
number of bulls (matching symbols) and cows (symbols that are in word, but not match place)
Your goal is to guess the word without reaching 0 lives.

2. Main Menu Information

In main menu you can select:

1 - Game Mode with Words; will start a game and read words from words.txt, then select one
2 - Game Mode with Numbers; also start a game, but instead randomly generate the number
3 - Exit the Game 

3. Working with Words.txt 

An error may occur during reading words.txt file and there are few possible reasons:
1) words.txt doesnt't exist - in this case you should create this file and follow instruction how to arrange elements
2) words.txt written not in lower case - rename file to words and make sure extension is txt
3) words.txt not in same directory as the code/binaries - move file to the same directory 

HOW TO ARRANGE FILE:
1) Make sure first line is a number - this number is the value of words that will be read by the game. 
The number can't be lower than 10 and words above the value won't be read  
2) The other lines will be words. Make sure each words written in lower case and divided with space
or new line only. Other symbols, such as commas and periods will be counted as part of word
3) Words with symbols other than aplhabetic letter won't be read. This includes numbers, punctuation marks, etc.

EXAMPLE:
15
hello this is a example pine brush cleric chess 
nice one ring road again white list
