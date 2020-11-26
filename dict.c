/*dict.c
* 
* Created by Edward Tobias Franks (efranks@student.unimelb.edu.au) 
* 29/08/2020
*
* Print information relating to a business directory inputted by the user in  
* CSV format.
*
* To run the program, type:
* ./dict {input}.csv {ouptput}.txt
* 
* Parameters such as MAX_ENTRY_LENGTH and MAX_LINE_LENGTH can be adjusted 
* in "llbuilder.h". This program must be run in the same directory as 
* "llbuilder.h" and "llbuilder.c".
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "llbuilder.h"
#include "llbuilder.c"

void main(int argc, char **argv) {
    //Builds a Linked-List using the value stored in the CSV file 
    buildDict(argv[1]);    
	
	//Open output file in order to write to it
	FILE *outputFile = fopen(argv[2], "w");
	safemalloc(outputFile);
    
    //Recieves a search term from the user
    char userQuery[MAX_ENTRY_LENGTH];
    printf("Please search query:\n");

	//Searches Linked-list for user queries and prints results to txt file
    while(fgets(userQuery,MAX_ENTRY_LENGTH,stdin)!=NULL) {
		strtok(userQuery,"\n");
		printDict(userQuery,outputFile);
	}  

	//Closes the output file now that search is complete
	fclose(outputFile);
	
	//Free all nodes of the Linked-list
	freeDict();
}