# Text Analysis using Binary Search Trees
The functionality of the program is defined as follows.

A program to analyse a set of text files.
For each file, a list of all distinct correctly-spelled words are compiled by reading them from the
file and inserting them in a binary search tree (BST). When all the words have been read from
that file, traverse the BST and write the words to an output file, one word per line, in
alphabetic order, together with the number of occurrences of each word in the file and, in
brackets, the level at which they are stored in the BST. The root of the tree is at
level 0. The program is case-insensitive, i.e. it treats "Tree" and "tree" as the
same word.
For each file,the average and the maximum number of probes (i.e. nodes examined)
to find a word in the BST are computed.
For each file, the text of the file with all incorrectly spelled words are written in upper case.
A word is deemed to be incorrectly spelled if it is not included in a list of words that is
provided as input to the program.

Input data with test cases are provided in an input file named input.txt.  
This input file is located in the data directory. Since this directory is a sibling directory of the bin directory 
where the example .exe file resides, the filename used when opening the file is "../data/input.txt". 

Output for the test case is written to an output file "../data/output.txt"

There are a maximum of eighty of characters in the message.  If message has more than eighty characters, only the first eighty are read.


Input
-----

- The input file (input.txt) contains a list of filenames with one filename per line. The
  filenames include the relative path to that file from the directory where the executable
  code is stored, e.g. "../data/textfile1.txt").
  The first filename in the input file is the name of the list of words to used when checking
  the spelling of words in all subsequent files.

Output
------

- The program writes to the output file ("output.txt") my Andrew Id, followed by (for
  each file): the text with the incorrectly spelled words in upper case, the maximum number of
  probes on a separate line, the average number of probes on a separate line, followed by the list
  of distinct correctly spelled words in alphabetic order, one word per line with its frequency of
  occurrence and the level at which it resides in the tree, and, finally, the separator
  ("--------------------") on a separate line.


Sample Input
------------

	../data/words.txt
	../data/textfile1.txt
	../data/textfile2.txt
	../data/textfile3.txt


Sample Output
-------------

	jwuyeh
	../data/textfile1.txt
	My heart is in the work
	My heart is in the WIRK
	Maximum number of probes: 4
	Average number of probes: 2.5
	heart         2 (1)
	in            2 (3)
	is            2 (2)
	my            2 (0)
	the           2 (1)
	work          1 (2)
	--------------------
	../data/textfile2.txt
	heart in is My the work
	Maximum number of probes: 6
	Average number of probes: 3.5
	heart         1 (0)
	in            1 (1)
	is            1 (2)
	my            1 (3)
	the           1 (4)
	work          1 (5)
	--------------------
	../data/textfile3.txt
	As a young African, I have found passion in ENGAGING in ACTIVITIES
	that improve the LIVES of people around me. Whether it is HELPING my
	family on the farm to improve food SUFFICIENCY at home. Or JOINING
	a group of STUDENTS from my town to help improve education in our
	community. Or JOINING a campus project to help restore INTEGRITY
	in our society.
	AFRICA'S Next Generation should change the narrative!
	Maximum number of probes: 11
	Average number of probes: 6.7
	a             3 (1)
	african       1 (2)
	around        1 (3)
	as            1 (0)
	at            1 (6)
	campus        1 (9)
	change        1 (10)
	community     1 (8)
	education     1 (7)
	family        1 (5)
	farm          1 (6)
	food          1 (7)
	found         1 (4)
	from          1 (6)
	generation    1 (7)
	group         1 (5)
	have          1 (3)
	help          2 (5)
	home          1 (4)
	i             1 (2)
	improve       3 (5)
	in            4 (4)
	is            1 (8)
	it            1 (7)
	me            1 (6)
	my            2 (7)
	narrative     1 (9)
	next          1 (8)
	of            2 (5)
	on            1 (6)
	or            2 (7)
	our           2 (8)
	passion       1 (3)
	people        1 (5)
	project       1 (6)
	restore       1 (7)
	should        1 (9)
	society       1 (8)
	that          1 (4)
	the           3 (5)
	to            3 (7)
	town          1 (8)
	whether       1 (6)
	young         1 (1)
	--------------------
	../data/textfile4.txt
	For each file, COMPILE a list of all distinct CORRECTLY-SPELLED WORDS by reading them from the
	file and INSERTING them in a BINARY search tree (BST). When all the WORDS have BEEN read from
	that file, TRAVERSE the BST and write the WORDS to AN OUTPUT file, one word per line, in
	ALPHABETIC order, together with the number of OCCURRENCES of each word in the file and, in
	BRACKETS, the level at which they ARE STORED in the BST. Remember, the root of the tree is at
	level 0. Your program should be CASE-INSENSITIVE, i.e. it should treat "Tree" and "tree" as the
	same word. 
	Maximum number of probes: 11
	Average number of probes: 6.4
	a             2 (2)
	all           2 (3)
	and           4 (6)
	as            1 (8)
	at            2 (7)
	be            1 (8)
	by            1 (5)
	distinct      1 (4)
	each          2 (1)
	file          5 (2)
	for           1 (0)
	from          2 (2)
	have          1 (4)
	ie            1 (5)
	in            5 (3)
	is            1 (6)
	it            1 (7)
	level         2 (5)
	line          1 (4)
	list          1 (1)
	number        1 (3)
	of            4 (2)
	one           1 (5)
	order         1 (7)
	per           1 (6)
	program       1 (7)
	read          1 (4)
	reading       1 (3)
	remember      1 (7)
	root          1 (8)
	same          1 (9)
	search        1 (6)
	should        2 (8)
	that          1 (7)
	the           11 (5)
	them          2 (4)
	they          1 (7)
	to            1 (6)
	together      1 (7)
	treat         1 (8)
	tree          4 (5)
	when          1 (6)
	which         1 (10)
	with          1 (9)
	word          3 (8)
	write         1 (7)
	your          1 (8)
	--------------------



Solution Strategy
-----------------
	0 - Print andrew Id into the output file
	1 - Read the file paths in the input file (print all the output file except the first one)
	2 - Open each file and read the words one by one
	3 - Each time a word is read, it is converted into lower case and unwanted characters (punctuations, 's)
	    are removed from the word
	4 - The words in the first file (containing the dictionary words) are inserted into a binary search tree
	5 - For the remaining files (containing text to be analysed), each time a word is read and step 3 carried 
	    out, we check if the word is in the dictionary;
	6 - If the word is in the dictionary, we insert it into the a second tree for the purpose of analysis, and print
		the original word to the output file.
		Before inserting, the insert function checks if a word is not already in the dictionary and if it is, it increases
		the frequency for the word, and not add it to the tree.
		Also, the insert help calculate the level, and the number of probes for each word (node)
	7 - If the word is not in the dictionary, we convert in to upercase and print it to the output file
	8 - After processing all the words for a file, the height of the tree (second one), is calculated to determine
		the maximum number of probes. This is then printed to the output file
	9 - The average probe is calculated by adding together the probes for each word (calculated during insert) and deviding
	    by the total number of words. This is then printed to the output file
	10 - Afterwards, the words in the tree (second one) are printed in order with their frequency and level calculated during
		 during insert
	11 - Print '--------------------' to the output file



Test Strategy
-------------

	The program has been tested with a variety of test data sets that reflect all valid conditions, including boundary conditions:

	- When a text file has no words - Maximum number and average number of probes are 0
	- A text file with more text that the test case provide - A long list of words with more uppercase words, and high
	  frequency for commonly used word
	- When a text file has a word with multiple punctuation marks and word in the dictionary - Punctuations not shown in
	  the list of words printed in order, and word maintains original form in the corpus printed
	- When a text file has a word with multiple punctuation marks and word not in the dictionary - Word not shown in
	  the list of words printed in order, and printed in uppercase in the corpus printed
	- When a text file has 's and word is in dictionary - Word shown in the list printed in order without 's
	- When a text file has 's and word is not in the dictionary - Word not shown in the list printed in order and
	  highlighted in upper case in the corpus printed
	- When text file contains just one word  - Max and Average number of probes should be 1
	- When text file contains a word with a hypen and word in the dictionary - Should not be highlighted in uppercase and should
	  list of words printed in order
	- When text file contain words with just punctuations


Order of Complexity
--------------------
	- Reading the words in the files: O(m) * O(n) where n is the number of files where m is the 
	  number of words in the file
	- Searching in the dictionary: O(n log n) where n is the number of words in the file
	- Calculating the height: O(n) where n is number of words in the file
	- Calculating the average probes: O(n) where n is the number of words in the file
	- THE TIME COMPLEXITY OF THE ALGORITHM IS O(n log n)

File organization
-----------------

	textAnalysis.h                  interface file:      
	contains the declarations required to use the functions that implement the solution to this problem
	typically, these will include the definitions of the abstract data types used in the implementation

	textAnalysisImplementation.cpp  implementation file: 
	contains the definitions of the functions that implement the algorithms used in the implementation

	textAnalysisApplication.cpp     application file:    
	contains the code that instantiates the abstract data types and calls the associated functions
	in order to effect the required functionality for this application


Author
------

Wuyeh Jobe, Carnegie Mellon University Africa
03/18/2020
