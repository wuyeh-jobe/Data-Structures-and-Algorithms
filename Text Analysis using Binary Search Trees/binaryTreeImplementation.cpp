/************************************************************************/
/*                                                                      */
/* Interface file for a BINARY_TREE ADT                                 */
/*                                                                      */
/* Refer to lecture notes for details.                                  */
/*                                                                      */
/* David Vernon                                                         */
/* 5/3/2017 Added function to initialize the tree                       */
/*                                                                      */
/* Wuyeh Jobe (03/18/2020) added functions to  calculate height of tree,*/
/* assign element, print in order to file, calculate total and average	*/
/* probes for a word, find if a word exist.								*/
/************************************************************************/

#include "binaryTree.h"

/*** initialize a tree ***/

void initialize(BINARY_TREE_TYPE *tree, bool first_call) {
	/* we don't know what value *tree has when the program is launched      */
	/* so we have to be careful not to dereference it                       */
	/* if it's the first call to initialize, there is no tree to be deleted */
	/* and we just set *tree to NULL                                        */

	if (first_call) {
		first_call = false;
		*tree = NULL;
	}
	else {
		if (*tree != NULL)
		{
			postorder_delete_nodes(*tree);
			*tree = NULL;
		}

	}
}


/*** insert an element in a tree ***/

BINARY_TREE_TYPE *insert(ELEMENT_TYPE e,  BINARY_TREE_TYPE *tree ) {

	WINDOW_TYPE temp;

	if (*tree == NULL) {

		/* we are at an external node: create a new node and insert it */

		if ((temp = (NODE_TYPE) malloc(sizeof(NODE))) == NULL) 
			error("function insert: unable to allocate memory");
		else {
			
			e.n_probes = e.n_probes +  1;
			temp->element = e;
			temp->left    = NULL;
			temp->right   = NULL;
			*tree = temp;
		}
	}
	else if (strcmp(e.word, (*tree)->element.word) < 0) {
		e.wordLevel = e.wordLevel + 1;
		e.n_probes = e.n_probes +  1;
		insert(e, &((*tree)->left));
	}
	else if (strcmp(e.word, (*tree)->element.word) > 0) {
		e.wordLevel = e.wordLevel + 1;
		e.n_probes = e.n_probes +  1;
		insert(e, &((*tree)->right));
	}
	else{
		//e already is in the tree so don't add it
		//increase the frequency
		(*tree)->element.frequency = (*tree)->element.frequency + 1;
	}

	return(tree);
}

/** Check if a word is in a tree **/

int find(ELEMENT_TYPE e,  BINARY_TREE_TYPE tree ) {

	if (tree != NULL) {
		if (strcmp(e.word, tree->element.word) < 0) {
			find(e, tree->left);
		}
		else if (strcmp(e.word, tree->element.word) > 0) {
			find(e, tree->right);
		}
		else{
			return true;
		}
	}
	else{
		return false;
	}


}

/** Calculate height of the Binary tree **/

int treeHeight(BINARY_TREE_TYPE tree){

	int leftHeight = 0;
	int rightHeight = 0;
	if(tree != NULL){
		leftHeight = treeHeight(tree->left);
		rightHeight = treeHeight(tree->right);

		if (leftHeight > rightHeight){
			return (leftHeight + 1);
		}
		else{
			return (rightHeight + 1);
		}
	}
	else{
		return 0;
	}

}

/** Calculate the number of probes for the Binary Tree **/

/**int numberOfProbes(ELEMENT_TYPE e,  BINARY_TREE_TYPE tree){
	int static totalProbes = 0;
	int temp = 0;
	if (tree != NULL) {

		if (strcmp(e.word, tree->element.word) < 0) {
			totalProbes = totalProbes+1;
			numberOfProbes(e, tree->left);

		}
		else if (strcmp(e.word, tree->element.word) > 0) {
			totalProbes = totalProbes+1;
			numberOfProbes(e, tree->right);

		}
		else{
			totalProbes = totalProbes + 1;
			temp = totalProbes;
			totalProbes = 0;
			return temp;
		}
	}
	else{

		return 0;
	}
}**/

/** Calculate the total probes and the total number of words **/
int static probes = 0;
int static words = 0;
void totalProbes(BINARY_TREE_TYPE tree) {
	if (tree != NULL) {
		/** Traverse through the entire tree and get the number of probes for each word stored during insert **/
		totalProbes(tree->left);
		probes = probes + tree->element.n_probes; //keep running total of probes
		words++; //keep count of number of words
		totalProbes(tree->right);
		
	}
}

/** Calculates the average probes and reset the static variables above **/
double getAverageProbes(){
	int temp1, temp2;
	/* Check if the total number of words  is not zero before dividing */
	if (words!= NULL){
		/** Assign total probes and words to temporary variables in order to reset the static variables**/
		temp1 = probes;
		temp2 = words;
		/** Reset the variables **/
		probes = 0;
		words = 0;
		/** Calculate average number of probes by dividing the total number of probes **/
		/** with the total number of words **/
		return ((float)temp1/temp2);
	}
	else{
		return 0.0;
	}
}


/** Calculate the level at which a word is

int level(ELEMENT_TYPE e,  BINARY_TREE_TYPE tree){
	int static levelcount = -1;
	int temp = 0;
	if (tree != NULL) {

		if (strcmp(e.word, tree->element.word) < 0) {
			levelcount = levelcount+1;
			level(e, tree->left);

		}
		else if (strcmp(e.word, tree->element.word) > 0) {
			levelcount = levelcount+1;
			level(e, tree->right);

		}
		else{
			levelcount = levelcount + 1;
			temp = levelcount;
			levelcount = -1;
			return temp;
		}
	}
	else{

		return -1;
	}
}*/



/*** returns & deletes the smallest node in a tree (i.e. the left-most node) */

ELEMENT_TYPE delete_min(BINARY_TREE_TYPE *tree) {

	ELEMENT_TYPE e;
	BINARY_TREE_TYPE p;

	if ((*tree)->left == NULL) {

		/* tree points to the smallest element */

		e = (*tree)->element;

		/* replace the node pointed to by tree by its right child */

		p = *tree;
		*tree = (*tree)->right;
		free(p);

		return(e);
	}
	else {

		/* the node pointed to by tree has a left child */

		return(delete_min(&((*tree)->left)));
	}

}

/*** delete an element in a tree ***/

BINARY_TREE_TYPE *delete_element(ELEMENT_TYPE e, BINARY_TREE_TYPE *tree) {

	BINARY_TREE_TYPE p;

	if (*tree != NULL) {

		if (strcmp(e.word, (*tree)->element.word) < 0) 
			delete_element(e, &((*tree)->left));

		else if (strcmp(e.word, (*tree)->element.word) > 0)
			delete_element(e, &((*tree)->right));

		else if (((*tree)->left == NULL) && ((*tree)->right == NULL)) {

			/* leaf node containing e - delete it */

			p = *tree;
			free(p);
			*tree = NULL;
		} 
		else if ((*tree)->left == NULL) {

			/* internal node containing e and it has only a right child */
			/* delete it and make treepoint to the right child          */

			p = *tree;
			*tree = (*tree)->right;
			free(p);
		}
		else if ((*tree)->right == NULL) {

			/* internal node containing e and it has only a left child */
			/* delete it and make treepoint to the left child          */

			p = *tree;
			*tree = (*tree)->left;
			free(p);
		}
		else {

			/* internal node containing e and it has both left and right child */
			/* replace it with leftmost node of right sub-tree                 */      
			(*tree)->element = delete_min(&((*tree)->right));
		}
	}     
	return(tree);
}


/*** inorder traversal of a tree, printing node elements **/

int inorder(BINARY_TREE_TYPE tree, int n) {

	int i;

	if (tree != NULL) {
		inorder(tree->left, n+1);

		for (i=0; i<n; i++) printf("        ");
		printf("%d (%d) %s\n", tree->element.frequency,tree->element.n_probes, tree->element.word);

		inorder(tree->right, n+1);
	}
	return(0);
}

/*** inorder traversal of a tree, printing words to the file with their freqeuncy **/

int print_inorder_to_file(BINARY_TREE_TYPE tree, FILE *fp_out, int n) {

	if (tree != NULL) {
		print_inorder_to_file(tree->left,fp_out, n+1);
		/*totalProbes = totalProbes + tree->element.n_probes;
		totalWords = totalWords + 1;*/
		fprintf(fp_out, "%-13s %-1d (%d)\n", tree->element.word, tree->element.frequency,tree->element.wordLevel /*, level(tree->element, tree)*/);

		print_inorder_to_file(tree->right,fp_out, n+1);
	}
	return(0);
}



/*** inorder traversal of a tree, deleting node elements **/

int postorder_delete_nodes(BINARY_TREE_TYPE tree) {

	if (tree != NULL) {
		postorder_delete_nodes(tree->left);
		postorder_delete_nodes(tree->right);
		free(tree);
	}
	return(0);
}

/*** print all elements in a tree by traversing inorder ***/

int print(BINARY_TREE_TYPE tree) {

	printf("Contents of tree by inorder traversal: \n");

	inorder(tree,0);

	printf("--- \n");

	return(0);
}


/*** error handler:  
print message passed as argument and take appropriate action ***/

int error(char *s) {

	printf("Error: %s\n",s);

	exit(0);
}

/*** assign values to an element ***/

int assign_element_value(ELEMENT_TYPE *e, char w[]) {

	e->word = (char *) malloc(sizeof(char) * (strlen(w)+1));
	strcpy(e->word, w);
	e->frequency = 1;
	e->wordLevel = 0;
	e->n_probes = 0;
	return(0);
}

