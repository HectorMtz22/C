typedef struct tree {
	unsigned int depth;
	char* user;
	char* pass;
	struct tree* leftChild; 
	struct tree* rightChild; 
} node;
#define MAX 100
int convert_to_line(char*, char*);
node* insert(char* , char* , node* , int );
void show(node*, char);
