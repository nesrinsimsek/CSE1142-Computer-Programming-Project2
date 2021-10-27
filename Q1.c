// Nesrin Şimşek 150119664

#include <stdio.h>
#include <math.h>

int numOfDigits; // initializes the numOfDigits variable for all functions

// calculates and prints the reversed version of the number that is entered by the user
void reverseN(int *number, int N){
	
	int remainder, forThePartNotReversed, thePartNotReversed, stopReversingLimit, reversedNumber, reversedPart=0;
	
	forThePartNotReversed = pow(10, N); /* is multiplied by the not reversed part of the number and summed by the reversed part 
										in order to calculate the reversed number */

	thePartNotReversed = *number / forThePartNotReversed; // calculates the part that is not reversed in the number

	stopReversingLimit = pow(10, (N-1));  // is used as a limit to end the loop for reversing calculation

	numOfDigits = count(*number);  // the number of digits of the number that is entered by the user
	
	/* makes some calculations to reach the reversed number when the part that is wanted to be 
	reversed has less number of digits than the whole number */
    while (*number >= thePartNotReversed && N < numOfDigits ) {
		
		remainder = *number % 10;
		
        if(reversedPart < stopReversingLimit )		
        	reversedPart = reversedPart * 10 + remainder;         
		
		else		
        	reversedNumber = reversedPart + (*number * forThePartNotReversed);     	
        
		*number = *number / 10;
	}

	/* makes some calculations to reach the reversed number when the part that is wanted to be 
	reversed has the same number of digits with the whole number */
    while (*number > 0 && N == numOfDigits) {
        
		remainder = *number % 10;
        
		reversedPart = reversedPart * 10 + remainder;
        
		*number = *number / 10;
        
		reversedNumber = reversedPart;
    }
    
	*number = reversedNumber; // at the end of all calculations *number becomes equal to the reversedNumber
	
}


// calculates the number of digits of a number
int count(int num) {
	
	int count = 0;
    
	while (num != 0) {
        num = num / 10;
        ++count;
    }
    
    return count;
}


// reads the number and the value in order to determine the reversing part
/* if the number of digits of the part that is wanted to be reversed is greater than the number of digits of the whole number,
prints a related warning and ends the program */
/* if there is no problem about size of the part that is wanted to be reversed, corresponding function 'reverseN' is executed and at the end,
the current value of *number is printed which is equal to the reversedNumber */
int main() {
	
	int N, num, *number;
	
	scanf("%d%d", &num, &N);
	
	number = &num;
	
	numOfDigits = count(num);

	if(numOfDigits < N)
		printf("N must be less than %d!", N);	
    
	else {
		reverseN(&num, N);
		printf("%d", *number);
	}
		
	
	
}
