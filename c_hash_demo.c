#include<stdio.h>
#include<stdlib.h>
#include<search.h>
#include<string.h>
#include<time.h>

#define SIZE 100

/*
 *  Generating SIZE number of random numbers
 *  store them in a Hash Table
 *  Run a while(1) generate a random 
 *  number and search in hash if it is there 
 *  NOTE: set a smaller number range for easy search i.e {0 to 10000}
 */
int main()
{
	// Init Random number generator with time(0)
	srand(time(0));
	ENTRY itemsToStore;
	ENTRY itemsToSearch;
	ENTRY *isFound = NULL;
	int n = SIZE;

	// Init hash table
	printf("hcreate %d\n",hcreate(SIZE));

	while(--n){
		itemsToStore.data = (char*) calloc(8,sizeof(char));
		itemsToStore.key = (char*) calloc(8,sizeof(char));
		int num = rand()%10000;
		sprintf(itemsToStore.data,"%d",num);
		sprintf(itemsToStore.key,"%d",num);
		
		// Insert it in table
		hsearch(itemsToStore,ENTER);
	
		//printf("Enter: %x\n",hsearch(itemsToStore, ENTER));
		printf("Inserted %s\n",itemsToStore);
	}
	itemsToSearch.key = (char*) calloc(8,sizeof(char));
	while(1){
		int num = rand()%10000;
		sprintf(itemsToSearch.key,"%d",num);
		isFound = hsearch(itemsToSearch,FIND);
		if(isFound != NULL){

			printf("\t\tGot it %s :: %s\n\n", isFound->key, (char*)isFound->data);
			break;
		}else{
			printf("Did not get it %d\n",num);
		}
	}

	// Delete Hash Table
	hdestroy();
	return 0;
}
