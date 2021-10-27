// Nesrin Þimþek 150119664


#include <stdio.h>

int size; // initializes the size variable for all functions

// prints letter X
void print_X(int size, int maxIndexOfStarInARow) {
	
	int i, j;
	
	// this loop is executed for size times 
	// the height of the letter is equal to the size 
	for(i=1; i <= size; i++) {					
		
		// this loop is executed for size times 
		// the width of the letter is equal to the size 
		// maxIndexOfStarInARow is equal to the size at the beginning	
		for(j=1; j <= size; j++) {		
			
			if(j == i || j == maxIndexOfStarInARow)  // prints star when j is equal to i or maxIndexOfStarInARow										  	
				printf("*");								
			
			else   //prints space when j is less or greater than i				
				printf(" ");			
		}
		
		--maxIndexOfStarInARow;	 // decreases maxIndexOfStarInARow by one after every loop execution for each row
		printf("\n");	
	}
	
}


// prints letter Z
void print_Z(int size,int maxIndexOfStarInARow) {
	
	int i, j, k;
	
	// this loop is executed for size times 
	// the height of the letter is equal to the size 
	for(i=1; i <= size; i++) {
			
		// prints top and bottom of the letter Z 				
		if(i == 1 || i == size) { 					
			for(k=1; k <= size; k++) // this loop is executed for size times which means width of the letter is equal to the size
				printf("*");			
		}		
		
		// prints the rest of the letter Z
		// maxIndexOfStarInARow is equal to the size at the beginning 		
	    else{					
			
			for(j=1; j <= size; j++) {				
			
				if(j < maxIndexOfStarInARow || j > maxIndexOfStarInARow)
					printf(" ");
	
				else 		
					printf("*");
			}
		}		
		
		--maxIndexOfStarInARow;	// decreases maxIndexOfStarInARow by one after every loop execution for each row
		printf("\n");
	}

}


// prints letter W
void print_W(int size, int maxIndexOfStarInARow) {
	
	int i, j, k, l, m;
	
		// this loop is executed for size times 
		// the height of the letter is equal to the size
		for(i=1; i <= size; i++) {
		
			// this loop prints the first line of the letter W
			// this loop is executed for size-1 times 
			for(j=1; j < size ; j++) {
				
				if(j == i )
					printf("*");
				
				else 			
					printf(" ");
			}
			
			// this loop is executed for size-1 times
			// this loop prints the second line of the letter W
			// maxIndexOfStarInARow is equal to the size at the beginning
			for(k=1; k < size ; k++) {
				
				if( k == maxIndexOfStarInARow) 					
					printf("*");					
					
				else
					printf(" ");						
			}
			
			// this loop is executed for size-1 times
			// this loop prints the third line of the letter W
			for(l=1; l < size ; l++) {
				
				if(l == i )
					printf("*");
				
				else 			
					printf(" ");
			}
			
			// this loop is executed for size times
			// this loop prints the last line of the letter W
			// maxIndexOfStarInARow is equal to the size at the beginning
			for(m=size; m >= 1 ; m--) {
				
				if( m == i) 				
					printf("*");					
					
				else
					printf(" ");						
			}
					
			--maxIndexOfStarInARow;	
			printf("\n");
		}

}


// prints letter Y
void print_Y(int size, int maxIndexOfStarInARow){
	int i, j, k, l;
		
		// this loop prints the top part of the letter Y
		// this loop is executed for size/2+1 times 
		// the height of the top part of letter Y is equal to the value of size/2+1
		for(i=1; i <= size / 2 + 1; i++){
			
			// this loop is executed for size times 
			// the width of the letter Y is equal to the size
			// maxIndexOfStarInARow is equal to the size at the beginning
			for(j=1; j <= size; j++){
							
				if(j == i || j == maxIndexOfStarInARow)
					printf("*");
				
				else 				
					printf(" ");
							
			}		
			
			--maxIndexOfStarInARow;	
			printf("\n");			
		}
		
		// this loop prints the bottom part of the letter Y
		// this loop is executed for size/2 times 
		// the height of the bottom part of the letter Y is equal to the value of size/2
		for(k=1; k <= size / 2; k++){
				
				for(l=1 ;l <= size; l++){
				
					if(l == size / 2 + 1)
						printf("*");				
					
					else
						printf(" ");
				}
				
				printf("\n");
		}
		
}


// takes the size of the letters as an input from the user
// if the user enters an invalid size value, prints a warning and asks again until it is valid
void readSize() {
	
	while(1) {
		
		scanf(" %d", &size);	
		
		if(size % 2 == 0 || size < 5)	
			printf("Invalid size. Enter the size again: ");							
		
		else			
			break;
	}
	
}


// takes the letter as an input from the user
// if the user enters an invalid letter, prints a warning and asks again until it is valid
// if the letter is valid, executes the corresponding function to print the letter
void readLetter() {
	
	char letter;
	
	while(1) {
		
		scanf(" %c", &letter);
		
		if(letter == 'X') {
			printf("\n");				
			print_X(size, size);
			break;
		}
			
		else if(letter == 'Z') {
			printf("\n");
			print_Z(size, size);
			break;
		}
		
		else if(letter == 'W') {
			printf("\n");
			print_W(size, size);
			break;
		}
		
		else if(letter == 'Y') {
			printf("\n");
			print_Y(size, size);
			break;
		}
		
		else
			printf("Invalid letter. Enter the letter again: ");				
	}
			
}


// executes the functions about to read the size value or the letter from the user
// asks the user whether s/he wants to continue or not after a letter is printed 
// returns to the beginning of the whole process in order to print new letters if the user wants to continue 
// prints goodbye and ends the program if the user does not want to continue
int main() {
	
	char ch;
	printf("Welcome to the letter printer.\n");
	
	while(1) {
	
		printf("Enter the size: ");
		readSize();
				
		printf("Enter the letter: ");
		readLetter();	
			
		printf("\n\n\n\nWould you like to continue? (Y or N): ");
		
		scanf(" %c",&ch);
		
		if(ch == 'N') {		
			printf("Goodbye :)");
			break;
		}			
	}
	
	return 0;	
}
