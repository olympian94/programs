#include<iostream>
using namespace std;
#define MAX 10
class queue
{
	private:
	int arr[MAX];
	int front, rear;
	public:
	queue()
	{
		front=-1;
		rear=-1;
	}
	void addq(int item)
	{
		if((rear==MAX-1&&front==0)||(rear+1==front))
		{
			cout<<endl<<"Queue is full";
			return;
		}
		if(rear==MAX-1)
			rear=0;
		else
			rear+=1;
		arr[rear]=item;
		if(front==-1)
			front=0;
	}
	int delq()
	{
		int data;
		if(front==-1)
		{
			cout<<endl<<"Queue is empty, cannot delete element.";
			return -99;
		}
		else
		{
			data=arr[front];
			if(front==rear)
			{
				cout<<endl<<"**front==rear**";
				front=-1;
				rear=-1;
			}
			else
			{
				if(front==MAX-1){
					cout<<endl<<"**front==MAX-1**";
					front=0;
				}
				else
				{
					cout<<endl<<"**front++**";
					front+=1;
				}
			}
			return data;
		}
	}
	void printq()
	{
		if(front==-1)
			cout<<endl<<"List is empty.";
		else{
			cout<<endl<<"**************************";
			cout<<endl<<"Front,Rear\t"<<front<<","<<rear;
			for(int j=front; j<rear; j++)
				cout<<endl<<arr[j];
			cout<<endl;
		}
	}
};

int main()
{
	queue aq;
	aq.printq();
	aq.addq(1);
	aq.addq(2);
	aq.addq(3);
	aq.addq(4);
	aq.addq(5);
	aq.addq(6);
	aq.addq(7);
	aq.addq(8);
	aq.addq(9);
	aq.addq(10);
	aq.addq(11);
	aq.printq();
	aq.delq();
	aq.delq();
	aq.delq();
	aq.printq();
	aq.addq(12);
	aq.addq(13);
	aq.addq(14);
	aq.printq();
}
