// Had a discussion with Ravi Shrimal.

#include <stdlib.h>    // including the libraries needed to run the program
#include <stdio.h>

typedef struct node{   // defining a new data type node with attributes data and
    int data;       //pointer to previous and next node
	struct node* next;
	struct node* prev;
}node;

struct node* first;  //initializing a global pointer to the head and tail of the doubly linked list
struct node* last;

struct node* getNewNode(int x){  //function to create a new node
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data =x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

struct node* insert(int x){        //function to add the created new node at the end 
    struct node* newNode = getNewNode(x);   //of the doubly linked list
	struct node* temp;
	
	
	if(first==NULL){
		first=newNode;
		last=first;
		
		return newNode;

	}
	else{
		temp=newNode;
		temp->prev = last;
		temp->next = NULL;
		last->next = temp;
		last = newNode;
	}
	return newNode;
}

void print(){        //function to print all the elements of the doubly linked list
	
	struct node* temp;
	temp=first;
	while(temp!=0){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf(" \n");
	return;
}

 
int toString(char a[]) { //function to take care of string which is inputted and 
//also take care of comparisons between positive and negative integers and also 0. 
	int c=0,polarity=0, m=0, n=0;
 
  	if (a[0] == '-') {  
    	polarity= -1;
  	}
    if (polarity== -1) {  
    	m = 1;
  	}
  	else {
    	m = 0;
  	}
    n = 0;
    for (c = m; a[c] != '\0'; c++) {
    	n = (n * 10) + a[c] - '0';
    	printf("%d\n",n);
  	}
 
  	if (polarity == -1) {
    	n = -n;
  	}
    return n;
}
int main(){
	int n,i;
	
	scanf("%d\n",&n);
	char c[n][100];
	printf("The number of lines in the input file = %d\n", n);
	
	for(i=0;i<n;i++){
		
		scanf("%s\n",c[i]);
		printf("\nc[%d]=%s\n",i,c[i]);
	}
	first=NULL;
	int v;
	
	for(i=0;i<n;i++){
		if( c[i][0] =='P'){
			print();
		}
		else{
			v = toString(c[i]) ;
			struct node* temp = insert(v);
			int c= temp->data;
		    while((temp->prev !=NULL) && (temp->prev->data>c)){
		        temp->data = temp->prev->data;
				temp=temp->prev;
		    }
	        temp->data = c;	
		}
	}
	printf("Final sorted list:");
	print();
}