#include<stdio.h>
#include<stdlib.h>

struct gnode{
	struct gnode *next;
	char name;
	char color;
	struct gnode *p;
	int d;
};
typedef struct gnode VERTEX;
typedef struct gll{
	int numNodes;
	VERTEX *next;
	char name;
} GHEAD;

VERTEX* createVertex(char name)
{
	VERTEX *v=(VERTEX*)malloc(sizeof(VERTEX));
	v->next=NULL;
	v->p=NULL;
	v->name=name;
	v->color='W';
	v->d=0;
	return v;
}
