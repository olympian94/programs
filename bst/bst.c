#include<stdio.h>
#include<stdlib.h>

typedef struct _tree_node{
	struct _tree_node *left;
	struct _tree_node *right;
	struct _tree_node *parent;
	int key;
	void *data;
} node;

typedef struct _tree{
	node* root;
	int numNodes;
} tree;

tree* createTree()
{
	tree *newtree = (tree*)malloc(sizeof(tree));
	newtree->root=NULL;
	newtree->numNodes=0;
	return newtree;
}

node* createNode(int key)
{
	node* newnode = (node*)malloc(sizeof(node));
	newnode->left=NULL;
	newnode->right=NULL;
	newnode->parent=NULL;
	newnode->key=key;
	newnode->data=NULL;
	return newnode;
}

//x=root. k=key
node* treeSearch(node* x, int k)
{
	if(x==NULL of k==x->key)
		return x;
	if(k<=x.key)
		return treeSearch(x->left,k);
	else return treeSearch(x->right,k);
}

node* treeMinimum(node *root)
{
	while(root->left!=NULL)
		root=root->left;
	return root;
}

node* treeMaximum(node *root)
{
	while(root->right!=NULL)
		root=root->right;
	return root;
}

node* successor(node *x)
{
	if(x->right!=NULL)
		return treeMinimum(x->right);
	node *y = x->parent;
	while(y!=NULL && x==y->right)
	{
		x=y;
		y=y->parent;
	}
	return y;
}

node* predecessor(node *x)
{
	if(x->left!=NULL)
		return treeMaximum(x->left);
	node *y = x->parent;
	while(y!=NULL && x==y->left)
	{
		x=y;
		y=y->parent;
	}
	return y;
}

void treeInsert(tree *T, node *z)
{
	node* y = NULL; //trailing pointer
	node* x = T->root;
	while(x!=NULL)
	{
		y=x;
		if(z->key<=x->key)
			x=x->left;
		else x=x->right;
	}
	z->parent=y;
	if(y==NULL)
		T->root = z;
	else if(z->key<=y->key)
		y->left=z;
	else y->right=z;
	T->numNodes+=1;
}

void transplant(tree *T, node *u, node *v)
{
	if(u->parent==NULL)
		T->root=v;
	else if(u==u->parent->right)
		u->parent->right=v;
	else u->parent->left=v;
	if(v!=NULL)
		v->parent=u->parent;
}

void treeDelete(tree *T, node *z)
{
	node *temp = z;
	if(z->right==NULL)
		transplant(T,z,z->left);
	else if(z->left==NULL)
		transplant(T,z,z->right);
	else
	{
		//case where z has both children : l and r. Find successor of 'z'
		node *y = treeMinimum(z->right);
		if(y->parent!=z)
		{
			//case where successor is not the child of z: replace 'y' by right child of 'y' and finally replace 'z' by 'y'
			transplant(T,y,y->right);
			y->right=z->right;
			y->right->parent=y;
		}
		//replacing z by y
		transplant(T,z,y);
		y->left=z->left;
		y->left->parent=y;
	}
	free(temp);
	T->numNodes-=1;
}

void inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("\n%d",root->key);
		inorder(root->right);
	}
}

void preorder(node *root)
{
	if(root!=NULL)
	{
		printf("\n%d",root->key);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(node *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("\n%d",root->key);
	}
}

void printTree(tree* T, int choice)
{
	printf("\nTree has %d nodes.",T->numNodes);
	switch(choice)
	{
		case 0:	printf("\nINORDER");
				inorder(T->root);
		break;

		case 1: printf("\nPREORDER");
				preorder(T->root);
		break;

		case 2:	printf("\nPOSTORDER");
				postorder(T->root);
		break;

		case 3: printf("\nINORDER");
				inorder(T->root);
				printf("\nPREORDER");
				preorder(T->root);
				printf("\nPOSTORDER");
				postorder(T->root);
		break;
		default: printf("\nWrong tree traversal choice given, choose from: 0-inorder, 1-preorder, 2-postorder or 3-all orders only.");
	}
}

int main(int argc, char const *argv[])
{
	node *all_nodes[10]={NULL};
	int j, size;
	all_nodes[0]=createNode(12);
	all_nodes[1]=createNode(5);
	all_nodes[2]=createNode(2);
	all_nodes[3]=createNode(9);
	all_nodes[4]=createNode(13);
	all_nodes[5]=createNode(15);
	all_nodes[6]=createNode(18);
	all_nodes[7]=createNode(19);
	all_nodes[8]=createNode(17);
	size=9; //no of nodes in all_nodes that have been allocated memory by calling createNode()

	tree* t1=createTree();

	for(j=0; j<size; j++)
	{
		treeInsert(t1,all_nodes[j]);
	}

	printTree(t1,3);

	treeDelete(t1,all_nodes[0]);
	printTree(t1,3);
	treeDelete(t1,all_nodes[1]);
	printTree(t1,3);
	treeDelete(t1,all_nodes[2]);
	printTree(t1,3);

	printf("\n");
	return 0;
}