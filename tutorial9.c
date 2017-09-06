#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product { 
	float price; 
	char productName[30]; 
	
	struct product *next;
}; 

// To traverse the struct linked list I just need to
// track the first and last node in the list

struct product *pFirstNode = NULL;
struct product *pLastNode = NULL;

void createNewList(){

	// Set aside enough space in memory for this struct

	struct product *pNewStruct = (struct product *) malloc(sizeof(struct product));
		
	// We can assign the value directly for the structs 
	// reference for the next struct in the linked list
		
	pNewStruct->next = NULL;
	
	printf("Enter Product Name: ");
	
	// The & is needed only because scanf() is used
	
	scanf("%s", (pNewStruct)->productName);
	
	printf("Enter Product Price: ");
		
	scanf("%f", &(pNewStruct)->price);
	
	// When the first struct is created all of the following
	// refer to the same struct
	
	pFirstNode = pLastNode = pNewStruct;
	

}

void inputData(){
	
	if(pFirstNode == NULL){
	
		createNewList();
	
	} else {
	
		// Set aside enough space in memory for this struct
	
		struct product *pNewStruct = (struct product *) malloc(sizeof(struct product));
	
		printf("Enter Product Name: ");
	
		// The & is needed only because scanf() is used
	
		scanf("%s", (pNewStruct)->productName);
	
		printf("Enter Product Price: ");
		
		scanf("%f", &(pNewStruct)->price);
	
		// If the first and last struct are equal we know this
		// is the second struct in the list
	
		if(pFirstNode == pLastNode){
		
			// Assign the value of next for the first struct to
			// this new one since the new one is the second struct
		
			pFirstNode->next = pNewStruct;
			
			// Since this is the second struct we know the last 
			// struct is equal to this new one
			
			pLastNode = pNewStruct;
			
			// Since this is the last struct in the list it has
			// NULL stored in its next
			
			pNewStruct->next = NULL;
		
		} else {
		
			// We know that this is at least the third struct in the
			// list so we don't need to touch the pFirstNode.
			// We instead just change the pLastNode value for next
			// from NULL to our new struct 
		
			pLastNode->next = pNewStruct;
			
			pNewStruct->next = NULL;
			
			pLastNode = pNewStruct;

		
		}
	
	}

}

void removeData(){
	
	int i;
	printf("which item to delete?\n\n");
	scanf("%d", &i);
	printf("deleting the %d product ", i);
	
	struct product *pProducts = pFirstNode;
	
	while(i-2)
	{
		
		pProducts = pProducts->next;
		i--;
		
	}
	
	printf("link\n\n");
	printf("(%s)\n\n", pProducts->productName);
	(pProducts->next) = (pProducts->next)->next;
	
	printf("(%s)\n\n", (pProducts->next)->productName);

	//free(pProducts->next);



}

void outputData(){

	// This temporarily takes the location of the structs in the 
	// linked list as we cycle through them to the end

	struct product *pProducts = pFirstNode;

	printf("Products Entered\n\n");
	
	// Until the ptr reaches a value of NULL for next we'll
	// keep printing out values
	
	while(pProducts != NULL){
	
		printf("%s costs %.2f\n\n", pProducts->productName, pProducts->price);
		
		// Switch to the next struct in the list
		
		pProducts = pProducts->next;
	
	}

}

struct product* searchForProduct(char *productName){

	struct product *pProductIterator = pFirstNode;

	while(pProductIterator != NULL){

		int areTheyEqual = strncmp(pProductIterator->productName,
					productName, 30);

		if(!areTheyEqual){
			
			printf("%s was found and it costs %.2f\n\n",
				pProductIterator->productName,
				pProductIterator->price);

			return pProductIterator;
		}

		pProductIterator = pProductIterator->next;

	}
	printf("%s wasn't found\n\n", productName);

	return NULL;

	
}

int main(){

	
	inputData();
	
	inputData();

	inputData();
	
	inputData();
	
	//searchForProduct("one");
	removeData();

	outputData();

        return 0;
}
