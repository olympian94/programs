#include<stdio.h>
#include<stdlib.h>

#define RED 1
#define BLACK 0

struct _tree{
	struct _tree *left, *right, *p;
	int key;
	int color;
	void *data;
};
typedef struct _tree node;

typedef struct _root{
	node *root;
	node *nil;
}RBT;

RBT* createRBT()
{
	RBT *t;
	t=malloc(sizeof(RBT));
	node *nil=(node*)malloc(sizeof(node));
	nil->left=NULL;
	nil->right=NULL;
	nil->p=NULL;
	nil->key=0;
	nil->color=BLACK;
	nil->data=NULL;	
	t->nil=nil;
	t->root=t->nil;
	return t;
}

void leftRotate(RBT *t,node *x)
{
	node *y=x->right;
	x->right=y->left;
	if(y->left!=t->nil)
		y->left->p=x;
	y->p=x->p;
	if(x->p==t->nil)
		t->root=y;
	else if(x==x->p->left)
		x->p->left=y;
	else
		x->p->right=y;
	y->left=x;
	x->p=y;
}

void rightRotate(RBT *t,node *y)
{
	node *x=y->left;
	y->left=x->right;
	if(x->right!=t->nil)
		x->right->p=y;
	x->p=y->p;
	if(y->p==t->nil)
		t->root=x;
	else if(y==y->p->left)
		y->p->left=x;
	else
		y->p->right=x;
	x->right=y;
	y->p=x;
}
void RBinsertfixup(RBT *t, node *z)
{
	node *y;
	while(z->p->color==RED)
	{
		if(z->p==z->p->p->left)
		{
			y=z->p->p->right;
			if(y->color==RED)
			{
				z->p->color=BLACK;
				y->color=BLACK;
				z->p->p->color=RED;
				z=z->p->p;
			}
			else
			{
				if(z=z->p->right)
				{
					z=z->p;
					leftRotate(t,z);
				}
				z->p->color=BLACK;
				z->p->p->color=RED;
				rightRotate(t,z->p->p);				
			}
		}
		else
		{
			y=z->p->p->left;
			if(y->color==RED)
			{
				z->p->color=BLACK;
				y->color=BLACK;
				z->p->p->color=RED;
				z=z->p->p;
			}
			else
			{
				if(z=z->p->left)
				{
					z=z->p;
					rightRotate(t,z);
				}
				z->p->color=BLACK;
				z->p->p->color=RED;
				leftRotate(t,z->p->p);				
			}

		}
	}
	t->root->color=BLACK;
}

void RBinsert(RBT *t,node *z)
{
	//trailing ptr
	node *y=t->nil;
	node *x=t->root;
	//search for correct BST position
	while(x!=t->nil)
	{
		y=x;
		if(z->key<x->key)
			x=x->left;
		else
			x=x->right;	
	}
	//insert
	z->p=y;
	if(y==t->nil)
		t->root=z;
	else if(z->key<y->key)
		y->left=z;
	else 
		y->right=z;
	z->left=t->nil;
	z->right=t->nil;
	z->color=RED;
	RBinsertfixup(t,z);
}


node* newnode(int key, void *data)
{
	node* z=malloc(sizeof(node));
	z->key=key;
	z->data=data;
	return z;	
}

void inorder(RBT *t, node *q)
{
	if(q!=t->nil)
	{
		inorder(t,q->left);
		printf("\n(%d)\t",q->key);
		if(q->color)
			printf("RED");
		else
			printf("BLACK");
		inorder(t,q->right);
	}
}

void preorder(RBT *t,node *q)
{
	if(q!=t->nil)
	{
		printf("\n(%d)\t",q->key);
		if(q->color)
			printf("RED");
		else
			printf("BLACK");
		preorder(t,q->left);
		preorder(t,q->right);
	}
}

void postorder(RBT *t,node *q)
{
	if(q!=t->nil)
	{
		postorder(t,q->left);
		postorder(t,q->right);
		printf("\n(%d)\t",q->key);
		if(q->color)
			printf("RED");
		else
			printf("BLACK");
	}
}

void print_all_orders(RBT *t)
{
	if(t->root!=t->nil){
		printf("\nPRINTING ALL ORDERS-----------------------------");
		printf("\n#INORDER");
		inorder(t,t->root);
		printf("\n#PREORDER");
		preorder(t,t->root);
		printf("\n#POSTORDER");
		postorder(t,t->root);
		printf("\n");
	}
	else
		printf("\nRBT is empty. Cannot print.");
}

int main()
{
	RBT *tree1;
	tree1=createRBT();

	node *z=newnode(11,(int*)11);
	RBinsert(tree1,z);

	z=newnode(2,(int*)2);
	RBinsert(tree1,z);

	z=newnode(14,(int*)14);
	RBinsert(tree1,z);

	z=newnode(1,(int*)1);
	RBinsert(tree1,z);

	z=newnode(7,(int*)7);
	RBinsert(tree1,z);

	z=newnode(15,(int*)15);
	RBinsert(tree1,z);

	z=newnode(5,(int*)5);
	RBinsert(tree1,z);

	z=newnode(8,(int*)8);
	RBinsert(tree1,z);

	z=newnode(4,(int*)4);
	RBinsert(tree1,z);

	print_all_orders(tree1);
	return 0;
}	


/*
node* search(RBT *t,node *x, int key)
{
	while(x!=t->nil&&x->key!=key)
	{	
		if(key>x->key)
			x=x->right;
		else
			x=x->left;
	}
	return x;
}

node * min(RBT *t,node *x)
{
	while(x->left!=t->nil)
		x=x->left;
	return x;
}

node * max(RBT *t,node *x)
{
	while(x->right!=t->nil)
		x=x->right;
	return x;
}


node * successor(RBT *t,node *x)
{
	if(x->right!=t->nil)
		return min(t,x->right);
	node *y=x->p;
	while(y!=t->nil && x==y->right)
	{
		x=y;
		y=y->p;
	}
	return y;
}

node * predecessor(RBT *t, node *x)
{
	if(x->left!=t->nil)
		return max(t,x->left);
	node *y=x->p;
	while(y!=t->nil && x==y->left)
	{
		x=y;
		y=y->p;
	}
	return y;
}
*/

/*
	Predecessor(x)=node with the grestest key that is smaller than x.key
	case 1: x.left!=NULL
		predecessor(x)=right most node in left subtree of x
	case 2: x.right=NULL
		predecessor(x) is the lowest ancestor of x which whoose right child
		is also an ancestor of x
		(left child condition ensures the predecessor node has key just greater than x.key)
*/

/*
	Successor(x)=node with the smallest key that is greater than x.key
	case 1: x.right!=NULL
		successor(x)=left most node in rt subtree of x
	case 2: x.right=NULL
		successor(x) is the lowest ancestor of x which whoose left child
		is also an ancestor of x
		(left child condition ensures the successor node has key just greater than x.key)
*/

