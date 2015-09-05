#include<stdio.h>
#include<stdlib.h>
#define BLACK 0
#define RED 1

typedef struct _rbtnode{
	struct _rbtnode* left;
	struct _rbtnode* right;
	struct _rbtnode* parent;
	int key;
	char color;
} rbtnode;

typedef struct rbtree{
	rbtnode* root;
	int numNodes;
	rbtnode* nil;
} rbt;

/*
	input:
	key: key of the node
	------------------------------------------------------------------------------------------------------------------------------
	output:
	A node of type 'rbtnode' is allocated memory and returned with given key and left, right and parent pointers set to 'nil' node.
*/
rbtnode* createRBTNode(rbt* T,int key)
{
	rbtnode* newnode = (rbtnode*)malloc(sizeof(rbtnode));
	newnode->left=T->nil;
	newnode->right=T->nil;
	newnode->parent=T->nil;
	newnode->key=key;
	//algorithm for insertion requires new node for insertion to be coloured red
	newnode->color=RED;
	return newnode;
}

/*
	input:
	------------------------------------------------------------------------------------------------------------------------------
	output:
	An object of type 'rbt' is allocated memory and returned with 'root' ptr set to 'nil' node and 'numNodes' attribute set to 0.
*/
rbt* createRBTree()
{
	rbt* newrbt = (rbt*)malloc(sizeof(rbt));
	newrbt->numNodes=0;
	//sentinel nill node
	newrbt->nil = (rbtnode*)malloc(sizeof(rbtnode));
	newrbt->nil->left=NULL;
	newrbt->nil->right=NULL;
	newrbt->nil->parent=NULL;
	newrbt->nil->key=-1;
	newrbt->nil->color=BLACK;
	//set root to sentinel nill
	newrbt->root=newrbt->nil;
	return newrbt;
}

/*
	In the functions: search, minimum, maximum, successor and predecessor all referrences to NULL are replaced by 'nil'.
	Since the code for these has been carried forward from bst code, 'node' has been replaced with 'rbtnode' and 'tree' with 'rbt'.
*/

rbtnode* RBTreeSearch(rbt *T, rbtnode* x, int k)
{
	if(x==T->nil || k==x->key)
		return x;
	if(k<=x->key)
		return RBTreeSearch(T,x->left,k);
	else return RBTreeSearch(T,x->right,k);
}

rbtnode* RBTreeMinimum(rbt *T, rbtnode *root)
{
	while(root->left!=T->nil)
		root=root->left;
	return root;
}

rbtnode* RBTreeMaximum(rbt *T, rbtnode *root)
{
	while(root->right!=T->nil)
		root=root->right;
	return root;
}

rbtnode* RBTsuccessor(rbt *T, rbtnode *x)
{
	if(x->right!=T->nil)
		return RBTreeMinimum(T, x->right);
	rbtnode *y = x->parent;
	while(y!=T->nil && x==y->right)
	{
		x=y;
		y=y->parent;
	}
	return y;
}

rbtnode* RBTpredecessor(rbt *T, rbtnode *x)
{
	if(x->left!=T->nil)
		return RBTreeMaximum(T, x->left);
	rbtnode *y = x->parent;
	while(y!=T->nil && x==y->left)
	{
		x=y;
		y=y->parent;
	}
	return y;
}

void leftRotate(rbt *T, rbtnode *x)
{
	rbtnode* y= x->right;
	x->right=y->left;
	if(y->left!=T->nil)
		y->left->parent=x;
	y->parent=x->parent;
	if(x->parent==T->nil)
		T->root=y;
	else if(x==x->parent->left)
		x->parent->left=y;
	else x->parent->right=y;
	y->left=x;
	x->parent=y;
}

void rightRotate(rbt *T, rbtnode *y)
{
	rbtnode* x= y->left;
	y->left=x->right;
	if(x->right!=T->nil)
		x->right->parent=y;
	x->parent=y->parent;
	if(y->parent==T->nil)
		T->root=x;
	else if(y==y->parent->left)
		y->parent->left=x;
	else y->parent->right=x;
	x->right=y;
	y->parent=x;
}

void RBTInsertFixup(rbt *T, rbtnode* z)
{
	while(z->parent->color==RED)
	{
		if(z->parent==z->parent->parent->left)
		{
			rbtnode *y= z->parent->parent->right;
			if(y->color==RED)
			{
				z->parent->color=BLACK;
				y->color=BLACK;
				z->parent->parent->color=RED;
				z=z->parent->parent;
			}
			else
			{
				if(z=z->parent->right)
				{
					z=z->parent;
					leftRotate(T,z);
				}
				z->parent->color=BLACK;
				z->parent->parent->color=RED;
				rightRotate(T,z->parent->parent);
			}
		}
		else
		{
			rbtnode *y= z->parent->parent->left;
			if(y->color==RED)
			{
				z->parent->color=BLACK;
				y->color=BLACK;
				z->parent->parent->color=RED;
				z=z->parent->parent;
			}
			else 
			{
				if(z=z->parent->left)
				{
					z=z->parent;
					rightRotate(T,z);
				}

				z->parent->color=BLACK;
				z->parent->parent->color=RED;
				leftRotate(T,z->parent->parent);	
			}
		}
	}
	T->root->color=BLACK;
}

void RBTInsert(rbt *T, rbtnode* z)
{
	rbtnode* y = T->nil; //trailing pointer
	rbtnode* x = T->root;
	//find position to insert to according to bst property
	while(x!=T->nil)
	{
		y=x;
		if(z->key<=x->key)
			x=x->left;
		else x=x->right;
	}
	//insert node
	z->parent=y;
	if(y==T->nil)
		T->root=z;               
	else if(z->key<=y->key)
		y->left=z;
	else y->right=z;
	z->left=T->nil;
	z->right=T->nil;
	z->color=RED;
	T->numNodes+=1;
	//call fixup procedure to preserve RBT properties
	RBTInsertFixup(T,z);
}

void inorder(rbt *T, rbtnode *root)
{
	if(root!=T->nil)
	{
		inorder(T, root->left);
		printf("\n%d\t(%d)",root->key,root->color);
		inorder(T, root->right);
	}
}

void preorder(rbt *T, rbtnode *root)
{
	if(root!=T->nil)
	{
		printf("\n%d\t(%d)",root->key,root->color);
		preorder(T, root->left);
		preorder(T, root->right);
	}
}

void postorder(rbt *T, rbtnode *root)
{
	if(root!=T->nil)
	{
		postorder(T,root->left);
		postorder(T,root->right);
		printf("\n%d\t(%d)",root->key,root->color);
	}
}

void printTree(rbt* T, int choice)
{
	printf("\n0:BLACK, 1:RED.");
	printf("\nRBTree has %d nodes.",T->numNodes);
	switch(choice)
	{
		case 0:	printf("\nINORDER");
				inorder(T, T->root);
		break;

		case 1: printf("\nPREORDER");
				preorder(T, T->root);
		break;

		case 2:	printf("\nPOSTORDER");
				postorder(T, T->root);
		break;

		case 3: printf("\nINORDER");
				inorder(T, T->root);
				printf("\nPREORDER");
				preorder(T, T->root);
				printf("\nPOSTORDER");
				postorder(T, T->root);
		break;
		default: printf("\nWrong tree traversal choice given, choose from: 0-inorder, 1-preorder, 2-postorder or 3-all orders only.");
	}
}

int main(int argc, char const *argv[])
{

	int size, j;
	rbt *rbt1 = createRBTree();
	rbtnode* all_nodes[10]={NULL};
	all_nodes[0]=createRBTNode(rbt1,11);
	all_nodes[1]=createRBTNode(rbt1,2);
	all_nodes[2]=createRBTNode(rbt1,14);
	all_nodes[3]=createRBTNode(rbt1,1);
	all_nodes[4]=createRBTNode(rbt1,7);
	all_nodes[5]=createRBTNode(rbt1,15);

	size=6;
	for(j=0; j<size; j++)
		RBTInsert(rbt1,all_nodes[j]);
	
	printTree(rbt1,0);

	printf("\n");
	return 0;
}