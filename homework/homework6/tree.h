typedef struct tree {
	unsigned int depth;
	char* username;
	char* password;
	struct tree* leftChild; 
	struct tree* rightChild; 
} node;
#define MAX 100
int convert_to_line(void);
node* insert(char* , char* , node* , int );
void show(node*, char);
