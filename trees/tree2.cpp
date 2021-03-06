#include<iostream>
#include<cstdio.h>
using namespace std;
#define TRUE 1
#define FALSE 0
//a bst
class tree_c
{
	private:
	struct node{
		node *left,*right;
		int data;
	}*tree;
	public:
	tree();
	//take element to search for, return FOUND, ptr to node 
	void search(int n,int &found,node *&parent);
	void insert(int n);
	//choose b/w in, pre, post- orders
	void traverse(int n);

	void pre(node *q);
	void in(node *q);	//inorder(symmetric)
	void post(node *q);
	int operator ==(tree_c t);
	//compare 2 trees
	int compare(node *pp,node *qq);	
	void operator = (tree t);
	//return ptr to root of tree to which tree at q is copied
	node *copy(node *q);
	node *getRoot(){ return tree;}	
};

tree_c::tree_c()
{
	tree=NULL;
}

void tree_c::search(int value, int &found, node *&parent)
{
	node *q;
	found=FALSE;
	parent=NULL;
	//tree empty
	if(tree==NULL)
	{
		printf("\nTree is empty, coudnt search.");
		return;
	}	
	q=tree;
	while(q!=NULL)
	{
		if(q->data==value)
		{
			found=TRUE;
			return;
		}
		if(value<q->data)
		{
			parent=q;
			q=q->left;
		}
		if(value>q->data)
		{
			parent=q;
			q=q->right;
		}
	}
}

void tree_c::insert(int n)
{
	int found; node *parent, *t;
	search(n,found,parent);
	/*
		when you conduct a search on bst, if the element is found, its parent is retured, else
		the search stops just at the node which would have the element as its child. So we can 
		use this fact when inserting and make use of the 'parent' ptr return by the search algo
		when the element is not present.
	*/
	if(!found)
	{
		t=new node;
		node->data=n;
		node->left=NULL;
		node->right=NULL;
		if(parent==NULL)
			tree=t;
		n > parent->data ? parent->right=t : parent->left = t;
	}
}

void tree_c::traverse(int ch)
{
	switch(ch)
	{
		case 1 : cout<<endl<<"INORDER TRAVERSAL";
			 in(p);
			 break;	
		case 2 : cout<<endl<<"PREORDER TRAVERSAL";
			 pre(p);
			 break;
		case 3 : cout<<endl<<"POSTORDER TRAVERSAL";
			 post(p);
			 break;
		default : cout<<endl<<"Invalid traversal choice specified.";
	}
	cout<<endl;
}

void tree_c::pre(node *q)
{
	if(q!=NULL)
	{
		printf("\n%d",q->data);
		pre(q->left);
		pre(q->right);
	}
}

void tree_c::in(node *q)
{
	if(q!=NULL)
	{
		in(q->left);
		printf("\n%d",q->data);
		in(q->right);
	}
}

void tree_c::post(node *q)
{
	if(q!=NULL)
	{
		post(q->left);
		post(q->right);
		printf("\n%d",q->data);
	}
}

int tree_c::operator ==(tree_c t)
{
	int flag=compare(tree,t.tree);
	return flag;
}

int tree_c::compare(node *pp, node *qq)
{
	static int flag;	//needs to retain value b/w function calls
	if(pp==NULL&&qq==NULL)
		return TRUE;
	else
	{
		if(pp!=NULL && qq!=NULL)	
		{
			if(pp->data!=qq->data)
				return FALSE;	
			else
			{
				flag=compare(pp->left,qq->left);
				flag=compare(pp->right,qq->right);
			}
		}
	}
}

void tree_c::operator = (tree_c t)
{
	tree=copy(t.tree);
}

//note the function declaration carefully
tree_c::node* tree_c::copy (node *q)
{
	node *t;	
	if(q!=NULL)
	{
		t=new node;
		t->data=q->data;
		t->left=copy(q->left);
		t->right=copy(q->right);
		return t;
	}
	else
		return NULL;
}
