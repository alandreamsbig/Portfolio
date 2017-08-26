/************************************************************************
  @author: Alan Tsai
  CS283
  Assingment G1
  July 12, 2016
Program: Anagram solver using hash table and linked list implementation for
data structures.
**************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define HASHSIZE 1000

/*Used as reference
http://www.sanfoundry.com/c-program-implement-hash-tables-chaining-with-singly-linked-lists/
*/

struct hash *hashTable = NULL;

/*Creats hash node struct*/
typedef struct node{
	int hashValue;
	char *word;
	struct node *next;
}node;

/*setting up hashtable*/
struct hash {
	struct node *head;
	int count;
};

void insertToHash(int hashValue, char *word);
void print_list();
struct node *createNode(int hashValue, char *word);
int HashValue(char *word);
//void list_sort(struct node *head);
//void isAnagram(char *sortedword, char*word);

/* Creates new nodes with the hashValue, word and next */
struct node *createNode(int hashValue, char *word){
	
	struct node *newnode; 
	
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->hashValue = hashValue;
	newnode->word = malloc(strlen(word)+1); 
	
	strcpy(newnode->word, word);
	newnode ->next = NULL; 
	
	return newnode;
}

/*insert nodes to the hashtable buckets */
void insertToHash(int hashValue, char *word){
	int hashIndex = hashValue % HASHSIZE;
	struct node *newnode = createNode(hashValue, word);
	
	if(!hashTable[hashIndex].head){
		hashTable[hashIndex].head = newnode;
		hashTable[hashIndex].count = 1;
		
		return;
	}
	//adding new node to the list
	newnode->next = (hashTable[hashIndex].head);
	
	//update the head of the list and # of nodes in the bucket
	hashTable[hashIndex].head = newnode;
	hashTable[hashIndex].count++;
	return;
}


/*Compute the ascii value sum of all the words in the dictionary*/
int HashValue(char *word){
	int sum = 0;
	int i = 0;
	
	for (i=0; i < strlen(word); i++){
		int val = (int)word[i];
		
		if(val >= 65 && val <=90){
			val+=32;
		}
		else if(val < 97 || val > 122){
			continue;
		}
			sum +=(val -96);
	}
	return sum;
}

/*
void list_sort(struct node *head){
	int sorted = 0;

	if (*head == NULL || (*head) -> next == NULL
			return;
			while(!sorted){

			struct node *first = head;
			struct node *curr = *head;
			struct node *next = (*head)->next;
			
			sorted = 1;

			while(next){

			int cmp = strcmp(curr->word, next->word);
			if (cmp > 0){
			curr -> next = next -> next;
			*first = next;
			sorted = 0
			}

			first = &curr ->next;
			curr = next;
			next = next ->next;
			}
			}

}
*/
/*
void isAnagram(char *sortedword, char*word){
	int word_len = strlen(word);
	int i = 0;
	for (i = 0; i < word_len; i++){
		word[i] = list_sort(word[i]);
		list_sort(word);
		return strcmp(sortedword, word)
	}
}
*/


/*Prints the hashtable and bucket elements*/
void print_list(){
	struct node *mynode;
	
	int i;
	
	for (i = 0; i < HASHSIZE; i++){
		
		if (hashTable[i].count == 0)
			continue;
			mynode = hashTable[i].head;
		if(!mynode)
			continue;
		
		printf("\nWords in the index %d in Hash Table\n", i);
		
		while(mynode != NULL){
			printf("Sum of Ascii:%d ", mynode->hashValue);
			printf("%s",mynode->word);
			mynode = mynode ->next;
		}
	}
	return;
}

int main(void) {
    FILE* dict = fopen("/usr/share/dict/words", "r"); //open the dictionary for read-only access
    if(dict == NULL) {
        return;
    }

    // Read each line of the file, and print it to screen
    char word[128];
	 
	 hashTable = (struct hash*)calloc(HASHSIZE, sizeof(struct hash));
    
	 while(fgets(word, sizeof(word), dict) != NULL) {
        printf("%s\n", word);
		  int hashValue = HashValue(word);
		  node *dummy = malloc(sizeof(node));
		  dummy -> word = word;
		  dummy -> next = NULL;
		  free(dummy);
		  insertToHash(hashValue, word);
		  
	 }
	 print_list();
}
