#include<iostream>
using namespace std;
#define TRUE 1
#define FALSE 0
//A BST
class tree
{
	private:
	struct node{
		node *l;
		int data;
		node *r;
	} *p;
	public:
	tree();
	//take ele to search for, using reference and ptr, return FOUND, ptr to node having ele
	void search(int n, int &found, node * &parent);
	void insert(int n);
	//traversal choice : in,pre,post
	void traverse(int ch);
	//inorder(symmetric)
	void in(node *q);
	//preorder : root,lft,rt
	void pre(node *q);
	//postorder : lft,rt,root
	void post(node *q);
	int operator ==(tree t);
	int compare(node *pp, node *qq);
	void operator = (tree t);
	node *copy(node *q);
	node *getRoot()
	{	return p;
	}
};
tree::tree()
{
	p=NULL;
}
void tree::search(int n, int& found, node * &parent)
{
	node *q;
	found=FALSE;
	parent=NULL;
	//tree is empty
	if(p==NULL){
		cout<<endl<<"Tree is empty, search cancelled.";
		return;
	}
	q=p;
	while(q!=NULL)
	{
		if(q->data==n){
			found=true;
			return;
		}
		if(q->data>n){
			parent=q;
			q=q->l;
		}
		else{
			parent=q;
			q=q->r;
		}
	}
}

void tree::insert(int n)
{
	int found;
	node *t, *parent;
	search(n,found,parent);
	if(found==TRUE)
		cout<<endl<<n<<"\tis already present in BST";
	else{
		t= new node;
		t->data=n;
		t->l=NULL;
		t->r=NULL;
		if(parent==NULL)
			p=t;
		else
			parent->data>n?parent->l=t:parent->r=t;
	}
}

void tree::traverse(int ch)
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

void tree::in(node *q)
{
	if(q!=NULL)
	{
		in(q->l);
		cout<<endl<<"**\t"<<q->data;
		in(q->r);
	}
}

void tree::pre(node *q)
{
	if(q!=NULL)
	{
		cout<<endl<<"**\t"<<q->data;
		pre(q->l);
		pre(q->r);
	}
}

void tree::post(node *q)
{
	if(q!=NULL)
	{
		post(q->l);
		post(q->r);
		cout<<endl<<"**\t"<<q->data;
	}
}

int tree::operator == (tree t)
{
	int flag;
	flag= compare(p,t.p); 
	return flag;
}

int tree::compare(node *pp, node *qq)
{
	static int flag;
	if(pp==NULL&&qq==NULL)
		return TRUE;
	else
	{
		if(pp!=NULL&&qq!=NULL)
		{
			if(pp->data!=qq->data)
				flag=FALSE;	
			else
			{
				flag=compare(pp->l,qq->l);
				flag=compare(pp->r,qq->r);
			}
		}
	}
	return flag;
}

void tree::operator = (tree t)
{
	p=copy(t.p);
}

tree::node* tree::copy(node *q)
{
	node *t;
	if(q!=NULL)
	{
		t=new node;
		t->data=q->data;
		t->l=copy(q->l);
		t->r=copy(q->r);
		return t;
	}
	else
		return NULL;
}

int main()
{
	tree t1, t2;
	t1.insert(20);
	t1.insert(17);
	t1.insert(6);
	t1.insert(8);
	t1.insert(10);
	t1.insert(20);
	t1.insert(7);
	t1.insert(18);
	t1.insert(13);
	t1.insert(12);
	t1.insert(5);
	t1.insert(6);
	t1.traverse(1);
	t1.traverse(2);
	t1.traverse(3);
	//
	t2.insert(99);
	t2.insert(44);
	t2.insert(88);
	t2.insert(11);
	t2.traverse(1);
	if(t1==t2)
		cout<<endl<<"equal trees.";
	t2=t1;
	if(t1==t2)
		cout<<endl<<"equal trees.";
	else
		cout<<endl<<"trees are not equal.";
	t2.traverse(1);
	cout<<endl<<"t1==t2?\t"<<(t1==t2)<<endl;
	return 0;
}
