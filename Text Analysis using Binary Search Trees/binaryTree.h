/************************************************************************/
/*                                                                      */
/* Interface file for a BINARY_TREE ADT                                 */
/*                                                                      */
/* Refer to lecture notes for details.                                  */
/*                                                                      */
/* David Vernon                                                         */
/* 5/3/2017 Added function to initialize the tree                       */
/*                          
/* Wuyeh Jobe (03/18/2020) added functions to  calculate height of tree,*/
/* assign element, print in order to file, calculate number of probes   */
/* for a word, find if a word exist.									*/
/************************************************************************/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE  1

typedef  struct {
            char *word;
			int frequency;
			int wordLevel;
			int n_probes;
         } ELEMENT_TYPE;

typedef struct node *NODE_TYPE;

typedef struct node {
            ELEMENT_TYPE element;
            NODE_TYPE left, right;
         } NODE;

typedef NODE_TYPE BINARY_TREE_TYPE;

typedef BINARY_TREE_TYPE WINDOW_TYPE;

/*** function prototypes ***/

/*** initialize a tree ***/
void initialize(BINARY_TREE_TYPE *tree, static bool first_call);
 
/*** insert an element in a tree ***/
BINARY_TREE_TYPE *insert(ELEMENT_TYPE e,  BINARY_TREE_TYPE *tree );
 
/*** returns & deletes the smallest node in a tree (i.e. the left-most node) */
ELEMENT_TYPE delete_min(BINARY_TREE_TYPE *tree);

/*** delete an element in a tree ***/
BINARY_TREE_TYPE *delete_element(ELEMENT_TYPE e, BINARY_TREE_TYPE *tree);

/*** inorder traversal of a tree, printing node elements **/
int inorder(BINARY_TREE_TYPE tree, int n);

/*** print all elements in a tree by traversing inorder ***/
int print(BINARY_TREE_TYPE tree);

/*** error handler: print message passed as argument and take appropriate action ***/
int error(char *s);

/*** assign values to an element ***/
int assign_element_value(ELEMENT_TYPE *e, /*int frequency,*/ char w[]);

/*** delete all nodes ***/
int postorder_delete_nodes(BINARY_TREE_TYPE tree);
 
/** Check if a word is in a tree **/
int find(ELEMENT_TYPE e,  BINARY_TREE_TYPE tree );

/** Calculate the height of the tree **/
int treeHeight(BINARY_TREE_TYPE tree);

/** Calculate the the number of probes required for a word
int numberOfProbes(ELEMENT_TYPE e,  BINARY_TREE_TYPE tree);**/

/*** inorder traversal of a tree, printing words to the file with their freqeuncy **/
int print_inorder_to_file(BINARY_TREE_TYPE tree, FILE *fp_out, int n);

/** Calculate the level at which a word is **/
/*int level(ELEMENT_TYPE e,  BINARY_TREE_TYPE tree);*/

/** Calculate the total probes and the total number of words **/
void totalProbes(BINARY_TREE_TYPE tree);

/** return the total probes for the tree **/
double getAverageProbes();
