#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node *next;
	void *val;
};
typedef struct node NODE;
typedef struct ll{
	int numNodes;
	NODE *next;
} HEAD;

struct gnode{
	struct gnode *next;
	char name;
	char color;
	struct gnode *p;
	//path length from src of BFS to this vertex
	int d;
	//discovery and fin time of the node in DFS
	int disc, fin;
};
typedef struct gnode VERTEX;


HEAD* createList();
void insertAtHead(HEAD*,void*);
void insertAtTail(HEAD*,void*);
void insertAtPos(HEAD*,void *,int);
void* deleteFromHead(HEAD*);
void* deleteFromTail(HEAD*);
void* deleteFromPos(HEAD*,int);
HEAD* createList()
{
	HEAD* head;
	head=(HEAD*)malloc(sizeof(HEAD));
	head->next=NULL;
	head->numNodes=0;
	return head;
}

VERTEX* createVertex(char name)
{
	VERTEX *v=(VERTEX*)malloc(sizeof(VERTEX));
	v->p=NULL;
	v->name=name;
	v->color='W';
	v->d=0;
	v->disc=0;
	v->fin=0;
	return v;
}

void insertAtHead(HEAD* head, void *val_inp)
{
	NODE *node=(NODE*)malloc(sizeof(NODE));
	node->val=val_inp;
	node->next=head->next;
	head->next=node;
	head->numNodes+=1;
}

void insertAtTail(HEAD* head, void* val_inp)
{
	NODE *node=(NODE*)malloc(sizeof(NODE));
	node->val=val_inp;
	node->next=NULL;
	if(head->next==NULL)
		head->next=node;
	else
	{
		NODE *temp=head->next;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=node;
	}
	head->numNodes+=1;
}

void insertAtPos(HEAD* head, void* val_inp,int pos)
{
	if(pos<0||pos>(head->numNodes-1))
		printf("\nInvalid position specified: %d. Cannot insert element.",pos);
	else
	{
		NODE *node=(NODE*)malloc(sizeof(NODE));
		node->next=NULL;
		node->val=val_inp;
		int j;
		if(pos==0)
		{
			node->next=head->next;
			head->next=node;
		}
		else
		{
			NODE *temp=head->next;
			for(j=0; j<pos-1; j++)
				temp=temp->next;
			node->next=temp->next;
			temp->next=node;
		}
		head->numNodes+=1;		
	}
}


void* deleteFromHead(HEAD* head)
{
	if(head->next==NULL){
		printf("\nList empty. Cannot delete from head.");
		return NULL;
	}
	void* deleted_ele;
	NODE *temp=head->next;
	head->next=temp->next;
	deleted_ele=temp->val;
	free(temp);
	head->numNodes-=1;
	return deleted_ele;	
}

void* deleteFromTail(HEAD* head)
{
	if(head->next==NULL){
		printf("\nList empty. Cannot delete from Tail.");
		return NULL;}
	void* deleted_ele;
	NODE *temp=head->next;
	while(temp->next->next!=NULL)
		temp=temp->next;
	deleted_ele=temp->next->val;
	free(temp->next);
	temp->next=NULL;
	head->numNodes-=1;
	return deleted_ele;	
}

void* deleteFromPos(HEAD *head, int pos)
{
	if(head->next==NULL){
		printf("\nList empty. Cannot delete from pos= %d.",pos);
		return NULL;}
	else if(pos<0||pos>(head->numNodes-1)){
		printf("\nInvalid position specified: %d. Cannot Delete Element.",pos);
		return NULL;
	}
	if(pos==0)
		return deleteFromHead(head);
	else if(pos==head->numNodes)
		return deleteFromTail(head);
	else{
		NODE *temp=head->next;
		NODE *temp2;
		int j; void* deleted_ele;
		for(j=0; j<pos-1; j++)
			temp=temp->next;
		temp2=temp->next;//to be deleted;
		deleted_ele=temp2->val;
		temp->next=temp2->next;
		free(temp2);
		head->numNodes-=1;		
		return deleted_ele;
	}
}

void printBFSGraph(HEAD* graph[], int size)
{
	int j,k;
	for(j=0; j<size; j++)
	{
		printf("\n");
		NODE *temp=graph[j]->next;
		VERTEX *t;
		for(k=0; k<graph[j]->numNodes; k++)
		{
			t=(VERTEX*)temp->val;
			printf("%c (COLOR=%c) (d=%d)",t->name,t->color,t->d);
			if(t->p!=NULL)
				printf("(p=%c)",t->p->name);
			printf("\t");
			temp=temp->next;
		}
	}
	printf("\n");
}

void printDFSGraph(HEAD* graph[], int size)
{
	int j,k;
	for(j=0; j<size; j++)
	{
		printf("\n->");
		NODE *temp=graph[j]->next;
		VERTEX *t;
		for(k=0; k<graph[j]->numNodes; k++)
		{
			t=(VERTEX*)temp->val;
			printf("%c (COLOR=%c) (disc=%d) (fin=%d)",t->name,t->color,t->disc,t->fin);
			if(t->p!=NULL)
				printf("(p=%c)",t->p->name);
			printf("\t");
			temp=temp->next;
		}
	}
	printf("\n");
}

BFS(HEAD *graph[],int size, VERTEX *src)
{
	//for each u belonging to graph-{src}
	int j,k;	
	VERTEX *temp_v;
	NODE *temp;
	for(j=0; j<size; j++)
	{
		//the nxt line gets us the first ele of every adj list (on iteration) and thus we can cover all vertices
		//by taking first vertex of each adj list
		temp=graph[j]->next;
		temp_v=(VERTEX*)temp->val;
		if(temp_v!=src)
		{
			temp_v->color='W';
			temp_v->d=size+1;
			temp_v->p=NULL;
		}
	}
	src->color='G';
	src->d=0;
	src->p=NULL;
	HEAD* queue=createList();
	insertAtTail(queue,src);
	VERTEX *u, *v;
	while(queue->next!=NULL)	
	{
		u=(VERTEX*)deleteFromHead(queue);	//return value of the func is the void ptr to the vertex
		//find head of adj list of u
		for(j=0; j<size; j++)
		{
			temp=graph[j]->next;
			temp_v=(VERTEX*)temp->val;
			if(temp_v==u)
				break;
		}
		//make temp point to first ele in adj list of u (not 'u' itself)
		//j preserves the value of ptr in graph[] array which is the head of adj list of u
		temp=temp->next;
		
		for(k=0; k<graph[j]->numNodes-1; k++)//-1 because first ele of adj list of u is u itself
		{
			v=(VERTEX*)temp->val;
			if(v->color=='W')
			{
				v->color='G';
				v->d=u->d+1;
				v->p=u;	
				insertAtTail(queue,v);
			}
			temp=temp->next;
		}
		u->color='B';
	}
}

int time;
DFS(HEAD * graph[],int size)
{
	//for each vertex u belonging to graph G
	int j,k;
	VERTEX *u,*v;
	NODE* temp;
	int time;
	for(j=0; j<size; j++)
	{
		//by looking at first entry of every adj list, we get to visit all the vertices
		temp=graph[j]->next;
		v=(VERTEX*)temp->val;
		v->color='W';
		v->p=NULL;
	}
	time=0;
	//for each vertex u belonging to graph G
	for(j=0; j<size; j++)
	{
		temp=graph[j]->next;
		u=(VERTEX*)temp->val;
		if(u->color=='W')
			DFS_VISIT(graph,size,u);
	}
	
}

DFS_VISIT(HEAD *graph[],int size,VERTEX *u)
{
	printf("\ncalling dfs_visit on %c",u->name);
	time++;
	u->disc=time;
	u->color='G';

	int j,k;
	NODE *temp;
	VERTEX *v;
	//find adj list of u
	int u_index;
	for(j=0; j<size; j++)
	{
		temp=graph[j]->next;
		v=(VERTEX*)temp->val;
		if(v==u)
			break;
	}
	u_index=j;
	temp=temp->next;
	//for each v in adj list of u		
	for(k=0; k<graph[j]->numNodes-1; k++)
	{
		v=(VERTEX*)temp->val;
		printf("\nvisit on %c, temp at %c j=%d graph[j]->numNodes-1=%d",u->name,v->name,j,graph[j]->numNodes-1);
		if(v->color=='W')
		{
			v->p=u;
			DFS_VISIT(graph,size,v);
		}
		temp=temp->next;
	}
	printf("\nblackening %c",u->name);
	u->color='B';
	
	time++;
	u->fin=time;
//	printDFSGraph(graph,size);
}

DFS_TOPO(HEAD * graph[],int size, HEAD *tlist)
{
	//for each vertex u belonging to graph G
	int j,k;
	VERTEX *u,*v;
	NODE* temp;
	int time;
	for(j=0; j<size; j++)
	{
		//by looking at first entry of every adj list, we get to visit all the vertices
		temp=graph[j]->next;
		v=(VERTEX*)temp->val;
		v->color='W';
		v->p=NULL;
	}
	time=0;
	//for each vertex u belonging to graph G
	for(j=0; j<size; j++)
	{
		temp=graph[j]->next;
		u=(VERTEX*)temp->val;
		if(u->color=='W')
			DFS_VISIT_TOPO(graph,size,u,tlist);
	}
	
}

DFS_VISIT_TOPO(HEAD *graph[],int size,VERTEX *u, HEAD *tlist)
{
	printf("\ncalling dfs_visit on %c",u->name);
	time++;
	u->disc=time;
	u->color='G';

	int j,k;
	NODE *temp;
	VERTEX *v;
	//find adj list of u
	for(j=0; j<size; j++)
	{
		temp=graph[j]->next;
		v=(VERTEX*)temp->val;
		if(v==u)
			break;
	}
	temp=temp->next;
	//for each v in adj list of u		
	for(k=0; k<graph[j]->numNodes-1; k++)
	{
		v=(VERTEX*)temp->val;
		printf("\nvisit on %c, temp at %c j=%d graph[j]->numNodes-1=%d",u->name,v->name,j,graph[j]->numNodes-1);
		if(v->color=='W')
		{
			v->p=u;
			DFS_VISIT_TOPO(graph,size,v,tlist);
		}
		temp=temp->next;
	}
	printf("\nblackening %c",u->name);
	u->color='B';
	time++;
	u->fin=time;
	insertAtHead(tlist,u);
//	printDFSGraph(graph,size);
}

HEAD* topo_sort(HEAD* graph[],int size)
{
	HEAD *tlist=createList();
	DFS_TOPO(graph,size,tlist);
	return tlist;
}

//NOTE: compute_transpose creates a new transposed Graph
void compute_transpose(HEAD* graph[], int size, HEAD *graph_transpose[], VERTEX *vertices[])
{
//	VERTEX *vertices[size];
//	HEAD *graph_transpose[size];
	NODE *temp, *temp2;
	VERTEX *v;
	int j,k;
	for(j=0; j<size; j++)
	{
		graph_transpose[j]=createList();
		v=graph[j]->next->val;
		vertices[j]=createVertex(v->name);
		temp=graph[j]->next;
		v=(VERTEX*)temp->val;
		vertices[j]->name=v->name;
		vertices[j]->p=v->p;
		vertices[j]->color=v->color;
		vertices[j]->d=v->d;
		vertices[j]->disc=v->disc;
		vertices[j]->fin=v->fin;
		insertAtTail(graph_transpose[j],vertices[j]);// preserve order of vertices as in orginal graph
	}

	VERTEX *u, *z;
	char name2;
	int m;
	//for each vertex 'u'
	for(j=0; j<size; j++)
	{
		temp=graph[j]->next;
		v=(VERTEX*)temp->val;
		//for each vertex 'v' in the adj list of 'u' ie considering edge u->v
		for(k=0; k<graph[j]->numNodes-1; k++)
		{	
			temp=temp->next;	
			u=(VERTEX*)temp->val;
			name2=u->name;
			//find vertex with name2 in graph_transpose and create edge v->u
			for(m=0; m<size; m++)
			{
				temp2=graph_transpose[m]->next;
				z=temp2->val;
				if(z->name==name2)
				{
			//can do this because we preserved the vertex-header mapping frm graph to graph-transpose
			//ie if graph[j] pts to adj list of vertex 'a' then so will graph_transpose[j]
					insertAtTail(graph_transpose[m],vertices[j]);
					break;
				}
			}
		}
	}
}

void printTOPOlist(HEAD *tlist)
{
	if(tlist->next==NULL)
		printf("\nTopo list empty, cannot print.");
	else
	{
		NODE *temp;
		VERTEX *t;
		temp=tlist->next;
		while(temp!=NULL)
		{
			t=(VERTEX*)temp->val;
			printf("\n%c (COLOR=%c) (disc=%d) (fin=%d)",t->name,t->color,t->disc,t->fin);
			if(t->p!=NULL)
				printf("(p=%c)",t->p->name);
			temp=temp->next;
		}
		printf("\n");
	}
}

//NOTE compute_transpose2 modifies the input graph
void compute_transpose2(HEAD* graph[], int size)
{
	int j,k,m;
	NODE *temp,*temp2;
	VERTEX *u,*v,*z;
	int *rec_arr=(int*)malloc(sizeof(int)*size);
	for(j=0; j<size; j++)
	{
		rec_arr[j]=graph[j]->numNodes;
	}
	char name;
	//for each 'u' in G
	for(j=0; j<size; j++)
	{
		temp=graph[j]->next;
		u=(VERTEX*)temp->val;
		//for each 'v' in adj list of 'u' ie edge u->v
		for(k=0; k<rec_arr[j]-1; k++)
		{
			temp=temp->next;
			v=(VERTEX*)temp->val;
			name=v->name;
			//find adj list of 'v'
			for(m=0; m<size; m++)
			{
				temp2=graph[m]->next;
				z=(VERTEX*)temp2->val;
				//add edge v->u
				if(z->name==name)
				{
					insertAtTail(graph[m],u);
					break;
				}
			}

		}
	}	
	for(j=0; j<size; j++)
	{
		z=(VERTEX*)graph[j]->next->val;
		while(rec_arr[j]--)
			deleteFromHead(graph[j]);
		insertAtHead(graph[j],z);
	}
}

HEAD* DFS_SCC(HEAD * graph[],int size)
{
	//for each vertex u belonging to graph G
	int j,k;
	VERTEX *u,*v;
	NODE* temp;
	HEAD *fintimes=createList();
	int time;
	for(j=0; j<size; j++)
	{
		//by looking at first entry of every adj list, we get to visit all the vertices
		temp=graph[j]->next;
		v=(VERTEX*)temp->val;
		v->color='W';
		v->p=NULL;
	}
	time=0;
	//for each vertex u belonging to graph G
	for(j=0; j<size; j++)
	{
		temp=graph[j]->next;
		u=(VERTEX*)temp->val;
		if(u->color=='W')
			DFS_VISIT_SCC(graph,size,u,fintimes);
	}
	return fintimes;
}

DFS_VISIT_SCC(HEAD *graph[],int size,VERTEX *u,HEAD* fintimes)
{
	printf("\ncalling dfs_visit on %c",u->name);
	time++;
	u->disc=time;
	u->color='G';

	int j,k;
	NODE *temp;
	VERTEX *v;
	//find adj list of u
	int u_index;
	for(j=0; j<size; j++)
	{
		temp=graph[j]->next;
		v=(VERTEX*)temp->val;
		if(v==u)
			break;
	}
	u_index=j;
	temp=temp->next;
	//for each v in adj list of u		
	for(k=0; k<graph[j]->numNodes-1; k++)
	{
		v=(VERTEX*)temp->val;
		printf("\nvisit on %c, temp at %c j=%d graph[j]->numNodes-1=%d",u->name,v->name,j,graph[j]->numNodes-1);
		if(v->color=='W')
		{
			v->p=u;
			DFS_VISIT_SCC(graph,size,v,fintimes);
		}
		temp=temp->next;
	}
	printf("\nblackening %c",u->name);
	u->color='B';
	
	time++;
	u->fin=time;
	insertAtHead(fintimes,u);
//	printDFSGraph(graph,size);
}
/*
DFS_FOR_SCC(HEAD * graph[],int size)
{
	//for each vertex u belonging to graph G
	int j,k;
	VERTEX *u,*v;
	NODE* temp;
	int time;
	for(j=0; j<size; j++)
	{
		//by looking at first entry of every adj list, we get to visit all the vertices
		temp=graph[j]->next;
		v=(VERTEX*)temp->val;
		v->color='W';
		v->p=NULL;
	}
	time=0;
	//for each vertex u belonging to graph G acc to decreasing fin time
	int *mi=(int*)malloc(sizeof(int)*size);
	int *fin=(int*)malloc(sizeof(int)*size);
	for(j=0; j<size; j++)
	{
		u=(VERTEX*)graph[j]->next->val;
		fin[j]=u->fin;
	}
	
	for(j=0; j<size; j++)
	{
		temp=graph[j]->next;
		u=(VERTEX*)temp->val;
		if(u->color=='W')
			DFS_VISIT(graph,size,u);
	}
	
}
*/
void SCC(HEAD* graph[],int size)
{
	HEAD *fintimes;
	fintimes=DFS_SCC(graph,size);
	compute_transpose2(graph,size);
	int j;
/*	//check fin times
	VERTEX *v;
	NODE *temp;
	temp=fintimes->next;
	for(j=0; j<size; j++)
	{
		v=(VERTEX*)temp->val;
		printf("\n%d",v->fin);
		temp=temp->next;
	}
*/
}

int main()
{
	HEAD* graph[10];
	int size=8,j,k;
	for(j=0; j<size; j++)
		graph[j]=createList();

	VERTEX *a=createVertex('a');	
	VERTEX *b=createVertex('b');
	VERTEX *c=createVertex('c');
	VERTEX *d=createVertex('d');
	VERTEX *e=createVertex('e');
	VERTEX *f=createVertex('f');
	VERTEX *g=createVertex('g');
	VERTEX *h=createVertex('h');
	
	insertAtTail(graph[0],a);
	insertAtTail(graph[0],b);

	insertAtTail(graph[1],b);
	insertAtTail(graph[1],e);
	insertAtTail(graph[1],f);
	insertAtTail(graph[1],c);

	insertAtTail(graph[2],c);
	insertAtTail(graph[2],d);
	insertAtTail(graph[2],g);

	insertAtTail(graph[3],d);
	insertAtTail(graph[3],c);
	insertAtTail(graph[3],h);

	insertAtTail(graph[4],e);
	insertAtTail(graph[4],a);
	insertAtTail(graph[4],f);

	insertAtTail(graph[5],f);
	insertAtTail(graph[5],g);

	insertAtTail(graph[6],g);
	insertAtTail(graph[6],h);
	insertAtTail(graph[6],f);

	insertAtTail(graph[7],h);
	insertAtTail(graph[7],h);

	HEAD *g2[10];
	VERTEX *v2[10];
//	compute_transpose(graph,size,g2,v2);
//	printDFSGraph(graph,size);
//	printDFSGraph(g2,size);
//	compute_transpose2(graph,size);
//	printDFSGraph(graph,size);
	SCC(graph,size);
	return 0;
}


//--------------------------------EXAMPLE 1
/*
	HEAD* graph1[10];
	int size=8,j,k;
	char name='r';
	for(j=0; j<size; j++)
		graph1[j]=createList();
*/
	/*
		create vertices	
		0,1,2,3,4,5,6,7
		r,s,t,u,v,w,x,y
	*/
	
/*	//vertices for graph 1
	VERTEX* r, *s, *t, *u, *v, *w, *x, *y;
	r=createVertex('r');
	s=createVertex('s');
	t=createVertex('t');
	u=createVertex('u');
	v=createVertex('v');
	w=createVertex('w');
	x=createVertex('x');
	y=createVertex('y');


	insertAtTail(graph1[0],r);
	insertAtTail(graph1[0],s);
	insertAtTail(graph1[0],v);

	insertAtTail(graph1[1],s);
	insertAtTail(graph1[1],r);		
	insertAtTail(graph1[1],w);	

	insertAtTail(graph1[2],t);
	insertAtTail(graph1[2],u);
	insertAtTail(graph1[2],x);
	insertAtTail(graph1[2],w);

	insertAtTail(graph1[3],u);
	insertAtTail(graph1[3],t);
	insertAtTail(graph1[3],x);	
	insertAtTail(graph1[3],y);	

	insertAtTail(graph1[4],v);
	insertAtTail(graph1[4],r);

	insertAtTail(graph1[5],w);	
	insertAtTail(graph1[5],s);	
	insertAtTail(graph1[5],t);	
	insertAtTail(graph1[5],x);	

	insertAtTail(graph1[6],x);	
	insertAtTail(graph1[6],w);	
	insertAtTail(graph1[6],t);
	insertAtTail(graph1[6],u);
	insertAtTail(graph1[6],y);

	insertAtTail(graph1[7],y);
	insertAtTail(graph1[7],x);
	insertAtTail(graph1[7],u);

	printBFSGraph(graph1,size);	
	BFS(graph1,size,s);
	printBFSGraph(graph1,size);
*/	


//-------------------------EXAMPLE 2
/*
	HEAD* graph2[10];
	int size2=6, j,k;
	for(j=0; j<size2; j++)
		graph2[j]=createList();
	/*
		create vertices	
		0,1,2,3,4,5
		u,v,w,x,y,z
	*/

	//vertices for graph2
/*
	VERTEX *u, *v, *w, *x, *y, *z;
	u=createVertex('u');
	v=createVertex('v');
	w=createVertex('w');
	x=createVertex('x');
	y=createVertex('y');
	z=createVertex('z');

	insertAtTail(graph2[0],u);
	insertAtTail(graph2[0],v);
	insertAtTail(graph2[0],x);
		
	insertAtTail(graph2[1],v);
	insertAtTail(graph2[1],y);

	insertAtTail(graph2[2],w);
	insertAtTail(graph2[2],y);
	insertAtTail(graph2[2],z);

	insertAtTail(graph2[3],x);
	insertAtTail(graph2[3],v);

	insertAtTail(graph2[4],y);
	insertAtTail(graph2[4],x);

	insertAtTail(graph2[5],z);
	insertAtTail(graph2[5],z);//a self loop

	printDFSGraph(graph2,size2);	
	DFS(graph2,size2);
	printDFSGraph(graph2,size2);	
*/

/*
//---------------------TOPOLOGICAL SORT EXAMPLE: PROF. BUMSTEAD'S DRESSING ORDER
	HEAD* graph[10];
	int size=9, j,k;
	for(j=0; j<size; j++)
		graph[j]=createList();
	//vertices;
	VERTEX *undershorts, *socks, *pants, *shoes, *watch, *belt, *shirt, *tie, * jacket;
	undershorts=createVertex('u');
	socks=createVertex('o');
	pants=createVertex('p');
	shoes=createVertex('h');
	watch=createVertex('w');
	belt=createVertex('b');
	shirt=createVertex('s');
	tie=createVertex('t');
	jacket=createVertex('j');


//-----------------order2
	insertAtTail(graph[0],undershorts);
	insertAtTail(graph[0],pants);
	insertAtTail(graph[0],shoes);

	insertAtTail(graph[1],socks);
	insertAtTail(graph[1],shoes);

	insertAtTail(graph[2],watch);

	insertAtTail(graph[3],pants);
	insertAtTail(graph[3],belt);
	insertAtTail(graph[3],shoes);

	insertAtTail(graph[4],shoes);

	insertAtTail(graph[5],belt);
	insertAtTail(graph[5],jacket);

	insertAtTail(graph[6],shirt);
	insertAtTail(graph[6],tie);
	insertAtTail(graph[6],belt);


	insertAtTail(graph[7],tie);
	insertAtTail(graph[7],jacket);

	insertAtTail(graph[8],jacket);

*/
/*
//---------------order1, TOPO SORT EXAMPLE
	insertAtTail(graph[0],shirt);
	insertAtTail(graph[0],tie);
	insertAtTail(graph[0],belt);

	insertAtTail(graph[1],watch);

	insertAtTail(graph[2],undershorts);
	insertAtTail(graph[2],pants);
	insertAtTail(graph[2],shoes);

	insertAtTail(graph[3],pants);
	insertAtTail(graph[3],belt);
	insertAtTail(graph[3],shoes);

	insertAtTail(graph[4],shoes);

	insertAtTail(graph[5],belt);
	insertAtTail(graph[5],jacket);

	insertAtTail(graph[6],socks);
	insertAtTail(graph[6],shoes);

	insertAtTail(graph[7],tie);
	insertAtTail(graph[7],jacket);

	insertAtTail(graph[8],jacket);

	
//	DFS(graph,size);
//	printDFSGraph(graph,size);
	HEAD *tlist=topo_sort(graph,size);
	printTOPOlist(tlist);
*/
