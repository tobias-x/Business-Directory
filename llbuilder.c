//This program contains all functions relating to the construction, manipulation, and accessing of the Linked-list

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

busList *busListHead=NULL;

//Builds the Linked-list using data from user-inputted CSV
void buildDict(char* dataFile) {
	char refLine[MAX_LINE_LENGTH];
	FILE *openDataFile = fopen(dataFile, "r");
	busList *prevNode, *currentNode=(busList*)malloc(sizeof(busList));
	safemalloc(currentNode);

	while(fgets(refLine, MAX_LINE_LENGTH, openDataFile)!=NULL) {
        
        //Constructs linked-list using cstrtok function
        prevDelim=0;
        currentNode->censusYear = strdup(cstrtok(refLine, ','));
        currentNode->blockID=strdup(cstrtok(refLine, ','));
        currentNode->propertyID=strdup(cstrtok(refLine, ','));
        currentNode->baseProperty=strdup(cstrtok(refLine, ','));
        currentNode->CLUESmallArea=strdup(cstrtok(refLine, ','));
        currentNode->tradingName=strdup(cstrtok(refLine, ','));
        currentNode->industryCode=strdup(cstrtok(refLine, ','));
        currentNode->industryDescription=strdup(cstrtok(refLine, ','));
        currentNode->xCor=strdup(cstrtok(refLine, ','));
        currentNode->yCor=strdup(cstrtok(refLine, ','));
        currentNode->location=strdup(cstrtok(refLine, ','));
		free(cstrtok(refLine,','));
        
        //Shifts "currentNode" to the nextNode using a forward-chaining algorithm
		if(busListHead==NULL) {
			busListHead=currentNode;
		}
		else {
			prevNode->next=currentNode;
		}
		currentNode->next = (busList*)malloc(sizeof(busList));
		safemalloc(currentNode->next);
		prevNode=currentNode;
		currentNode=currentNode->next;
	}
    fclose(openDataFile);
	printf("Finished building");
}

//Prints the dictionary to the output file determined by user 
void printDict(char searchQuery[MAX_ENTRY_LENGTH], FILE* openOutput) {
    busList *currentNode=busListHead;
    currentNode=currentNode->next;
    int resultCount=0;
    
    //Loops through each node, printing results to the specified file
    while(currentNode->next!=NULL){
        if(strcmp(currentNode->tradingName,searchQuery)==0) {
			fprintf(openOutput,"%s --> ",currentNode->tradingName);
            fprintf(openOutput,"Census year: %s || ",currentNode->censusYear); 
			fprintf(openOutput,"Block ID: %s || ",currentNode->blockID); 
			fprintf(openOutput,"Property ID: %s || ",currentNode->propertyID); 
			fprintf(openOutput,"Base property ID: %s || ",currentNode->baseProperty); 
			fprintf(openOutput,"CLUE small area: %s || ",currentNode->CLUESmallArea); 
			fprintf(openOutput,"Industry (ANZSIC4) code: %s || "
			,currentNode->industryCode); 
			fprintf(openOutput,"Industry (ANZSIC4) description: %s || "
			,currentNode->industryDescription); 
			fprintf(openOutput,"x coordinate: %s || ",currentNode->xCor);
			fprintf(openOutput,"y coordinate: %s || ",currentNode->yCor);
			fprintf(openOutput,"Location: %s || \n",currentNode->location);
			resultCount++;
        }
        currentNode=currentNode->next;
    }
    if(resultCount==0){
        printf("\nNOTFOUND\n");
        fprintf(openOutput,"\nNOTFOUND\n");
    }
}

void freeDict() {
	busList* tempNode;
	while(busListHead!= NULL) {
		tempNode=busListHead;
		busListHead=busListHead->next;
		free(tempNode);
	}
}