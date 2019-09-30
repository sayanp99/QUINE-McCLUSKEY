--------------------------------------------------- QUINE McCLUSKEY IMPLEMENTATION USING C++ -------------------------------------------------

NAME : SAYAN PAL
ROLL : 18CS8003
SUBJECT : CS302 Assignment 1

STATEMENT : Implementation of Quine McCluskey Logic Minimization. Your program should be able to solve upto 26 variables logic minimization.
Inputs to your pragram are to be generated automatically.

------------------------
How to RUN the program :
------------------------

The program consists of a Two Files:

1. quineMcCluskey.cpp --> This file contains the main function where we specify the number of variables and the minterms. This file also contains the
working codes for quine McCluskey implementation for Logic Minimization.

2. README.txt --> This file contains all the information on how to compile and run as well as the methods used for logic minimization.

#1. Extract the Zip File QM_18CS8003.zip
#2. The zip file contains two files : quineMcCluskey.cpp and README.txt
#3. Open the file quineMcCluskey.cpp
#4. Compile the program in a gcc/c++ compiler supporting C++ 11 & above.
#5. Run the Program.
#6. Provide the desired inputs as asked in the program.

--------------
INPUT Format :
--------------

1. Input the number of variables between 0-26.
2. Input the last two digits of your desired roll number.
3. The roll no. entered was randomized according to the following code:

	//Psuedo code to generate randomly minterms
	srand(roll);
	int power=pow(2,no);
	nom=rand()%power;
    	vector<int> temp1;
	for(long long int i=0;i<nom;i++)
		temp1.push_back(rand()%power);

	Here the generated minterms are stored in a vector "temp1".

-------------------
Working Procedure :
-------------------

Quine-McCluskey Method : For this algorithm, I've created only one class that do all of the hard work. The QM class, which holds all the functions that are required
			 for running of the program.

The QM class contains the following functions :-

getVars() : It takes input the number of variables required and produces the respective variables as output.

decimalToBinary() : It takes a decimal input and produces the corresponding binary output.

fourbit() : It takes convert binary into four bits such as binary of 2 is 10 and it will get converted to 0010. 

isGreyCode() : It checks whether the hamming distance is 1 or not between the fourbits of adjacent groups.

complement(): If the hamming distance is one between two corresponding fourbits then the bit position where the hamming distance changes by 1 bit gets replaced with "-" sign.

stInVector() : It checks whether a string exists in a given vector or not and returns the output as bool i.e. TRUE or FALSE.

reduce() : It takes input of the minterm vector and reduces them to corresponding reduced_minterm values with the help of other functions and returns the minimized binary expressions.

binaryToAlphabet() : It converts the reduced binary expressions to their corresponding alphabetical expressions.

vectorsAreEqual() : It checks whether the given two vectors are equal or not and returns the output as bool i.e. TRUE or FALSE.

rand() : It generates the random values from the provided input value range. It creates the same sequence again and again everytime the program runs.

unique() : It takes in the starting and the ending of the vector and produces all the unique elements.
 
atoi() : This function takes a string which represents an integer as an arguement and returns its value.        

-------------------
Running the Tests :
-------------------
# A Sample test output is here:


	Enter the number of variables: 5

	Enter last two digit of  your roll number as an argument of srand() function: 33 

	The random minterms generated are :
	1 9 14 16 21 25 29 

	The reduced boolean expression in SOP form:
	bc'd'e+a'c'd'e+a'bcde'+acd'e+ab'c'd'e'+abd'e

	Would you like to enter another expression? (y/n)
	n

	---END---

#1. At first we put in the number of variables 
#2. Then we input the roll no that is to be passed in the arguement of the srand() function
#3. Then the random minterms are generated
#4. At last the reduced boolean expression is produced as output.
 
---------
Sources :
---------

1. https://www.geeksforgeeks.org/the-c-standard-template-library-stl/

2. https://en.wikipedia.org/wiki/Quine%E2%80%93McCluskey_algorithm

3. https://www.allaboutcircuits.com/technical-articles/everything-about-the-quine-mccluskey-method/

4. https://www.tutorialspoint.com/digital_circuits/digital_circuits_quine_mccluskey_tabular_method.htm

5. https://www.geeksforgeeks.org/digital-logic-minimization-boolean-functions/
