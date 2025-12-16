#include<stdio.h>
#include<stdlib.h>
#include<search.h>
#include<string.h>
#include<time.h>

#define SIZE 100
#define STR_SIZE 8
#define MAX_RANGE 10000

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
	/*
	 * Keep track of allocated memory 
	 */
	char *key_list[SIZE];
	char *data_list[SIZE];
	int key_index = 0;
	int data_index = 0;

	// Init hash table
	printf("hcreate %d\n",hcreate(SIZE));

	while(--n){
		itemsToStore.data = (char*) calloc(STR_SIZE,sizeof(char));
		itemsToStore.key = (char*) calloc(STR_SIZE,sizeof(char));
		int num = rand()%MAX_RANGE;
		sprintf(itemsToStore.data,"%d",num);
		sprintf(itemsToStore.key,"%d",num);
		
		// Insert it in table
		hsearch(itemsToStore,ENTER);
	
		//printf("Enter: %x\n",hsearch(itemsToStore, ENTER));
		printf("Inserted %s\n",(char*)itemsToStore.data);
		key_list[key_index++] = itemsToStore.key;
		data_list[data_index++] = itemsToStore.data;
	}
	itemsToSearch.key = (char*) calloc(8,sizeof(char));
	while(1){
		int num = rand()%MAX_RANGE;
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
	// Free allocated memory
	while(--data_index && --key_index){
		free(key_list[key_index]);
		free(data_list[data_index]);
	}
	
	return 0;
}
