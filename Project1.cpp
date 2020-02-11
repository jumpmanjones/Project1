
/*SpellCheck <Project1.cpp>
 * EE 312 submission by
 * <Pranav Nelakonda>
 * <pn5474>
 * Slip Days used <0>
 * Fall 2019
 */

#include <stdio.h> // provides declarations for printf and putchar
#include <stdint.h> // provides declarations for int32_t uint32_t and the other (new) standard C types

/* All of your code must be in this file. Please no #includes other than standard system headers (ie.., stdio.h, stdint.h)
 *
 * Many students find it helpful to declare global variables (often arrays). You are welcome to use
 * globals if you find them helfpul. Global variables are by no means necessary for this project.
 */

/* You must write this function (spellCheck). Do not change the way the function is declared (i.e., it has
 * exactly two parameters, each parameter is a standard (mundane) C string (see SpellCheck.pdf).
 * You are expected to use reasonable programming style. I *insist* that you indent
 * reasonably and consistently in your code. I strongly encourage you to avoid big functions
 * So, plan on implementing spellCheck by writing two or three other "support functions" that
 * help make the actual spell checking easier for you.
 * There are no explicit restictions on using functions from the C standard library. However,
 * for this project you should avoid using functionality from the C++ standard libary. You will
 * almost certainly find it easiest to just write everything you need from scratch!
 */
int checkLetters(char a, char b){
	if(a == b)
		return 1;
	if(a == (b+32))
		return 1;
	if((a+32) == b)
		return 1;
	return 0;

}



int dicWord(char dictionary[], char tested[], int size){
	int spaceCnt = 0;
	int still = 1;

	for(int counter = 0; dictionary[counter] != '\0'; counter++){
		still = 1;	
		if(dictionary[counter] == '\n'){
		

 			int start = counter - spaceCnt;
				if(size == spaceCnt){
					for(int cnt = 0; cnt < spaceCnt; cnt++){
						if(!checkLetters(dictionary[start+cnt], tested[cnt])){
							still = 0;
						}	
					}
					if(still){
						return 0;
					}	
				}
			spaceCnt = 0;
		}
		else{
		spaceCnt++;
		}
			
	}
	return 1;	

}

void makeWord(char article[], int size, int loc, char dictionary[]){
	int startingPoint = loc - size;
	char temp[size];
	for(int idx = 0; idx < size; idx++){
		
		temp[idx] = article[idx + startingPoint];
		}
	int notWord = dicWord(dictionary,temp,size);
	if(notWord){
		for(int i = 0; i < size ; i++){
			
			printf("%c" , temp[i]);
		}
	printf("\n");
	}
}

void spellCheck(char article[], char dictionary[]) {
	
	int index = 0;
	int count = 0;
	while(article[index] != '\0'){
		if(article[index] < 65 || article[index] > 122){
	
			
			
			if(count >= 2){
				makeWord(article, count, index,dictionary);

			}
			count = 0;
			
		}
		else{
			count++;
		}
		index++;
		
	}

	if(article[index - 1] == ' ' || article[index - 1] == '\n'){
		count--;
		index--;
	}

	if(count >= 2){
		makeWord(article, count, index,dictionary); 
	}
}
