//============================================================================
// Name        : ee.cpp
// Author      : er
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include<iostream>
#include<iomanip>
using namespace std;
#include<stdlib.h>
//#include<stdio.h>
#define null 0
struct node{
	int exponent;
	double coeff;
	struct node* pnext;
};
int main(void)
{
	ios::sync_with_stdio(false);
	struct node* head1=null;
	struct node* p2=null;
	struct node* p1=null;
	struct node* head2=null;
	struct node* head3=null;
	int k,i;
	cin>>k;
	for(i=0;i<k;i++)
	{
		p1=(struct node*)malloc(sizeof(struct node));
		cin>>p1->exponent;
		cin>>p1->coeff;
		p1->pnext=null;
		if(i==0)
		{
			head1=p1;
			p2=p1;
		}
		else
		{
		  p2->pnext=p1;
		  p2=p1;
		}
	}
	cin>>k;
	for(i=0;i<k;i++)
	{
		p1=(struct node*)malloc(sizeof(struct node));
		cin>>p1->exponent;
		cin>>p1->coeff;
		p1->pnext=null;
		if(i==0)
		{
			head2=p1;
			p2=p1;
		}
		else
		{
		  p2->pnext=p1;
		  p2=p1;
		}
	}
	i=0;
	while(head1!=null&&head2!=null)
	{
		if(head2->exponent>head1->exponent)
		{
			p1=(struct node*)malloc(sizeof(struct node));
			p1->exponent=head2->exponent;
			p1->coeff=head2->coeff;
			p1->pnext=null;
			if(i==0)
			{
				head3=p1;
				p2=p1;
			}
			else
			{
				p2->pnext=p1;
				p2=p1;
			}
			p1=head2;
			head2=p1->pnext;
			free(p1);
			i++;
		}
		else if(head2->exponent<head1->exponent)
		{
			p1=(struct node*)malloc(sizeof(struct node));
			p1->exponent=head1->exponent;
			p1->coeff=head1->coeff;
			p1->pnext=null;
			if(i==0)
			{
				head3=p1;
				p2=p1;
			}
			else
			{
				p2->pnext=p1;
				p2=p1;
			}
			p1=head1;
			head1=p1->pnext;
			free(p1);
			i++;
		}
		else
		{	p1=(struct node*)malloc(sizeof(struct node));
			p1->exponent=head1->exponent;
			p1->coeff=head1->coeff+head2->coeff;
			p1->pnext=null;
			if(i==0)
			{
				head3=p1;
				p2=p1;
			}
			else
			{
				p2->pnext=p1;
				p2=p1;
			}
			p1=head2;
			head2=p1->pnext;
			free(p1);
			p1=head1;
			head1=p1->pnext;
			free(p1);
			i++;
		}
	}
	while(head1!=null)
	{
		p1=(struct node*)malloc(sizeof(struct node));
			p1->exponent=head1->exponent;
			p1->coeff=head1->coeff;
			p1->pnext=null;
			if(i==0)
			{
				head3=p1;
				p2=p1;
			}
			else
			{
				p2->pnext=p1;
				p2=p1;
			}
			p1=head1;
			head1=p1->pnext;
			free(p1);
			i++;
	}
	while(head2!=null)
	{
		p1=(struct node*)malloc(sizeof(struct node));
			p1->exponent=head2->exponent;
			p1->coeff=head2->coeff;
			p1->pnext=null;
			if(i==0)
			{
				head3=p1;
				p2=p1;
			}
			else
			{
				p2->pnext=p1;
				p2=p1;
			}
			p1=head2;
			head2=p1->pnext;
			free(p1);
			i++;
	}
	p2=head3;
	k=0;
	while(p2!=null)
	{
		if(p2->coeff==0)
			k++;
		p2=p2->pnext;
	}
	if(i!=k)
	    cout<<(i-k)<<' ';
	else
		cout<<(i-k);
    for(k=0;k<i;k++)
	{
        if(head3->coeff!=0.0)
		{
		cout<<head3->exponent;
		cout<<' ';
		cout<<fixed<<setprecision(1);
		cout<<head3->coeff;
		//printf("%.1f",head3->coeff);
		if(k<(i-1)&&head3->pnext->coeff!=0) cout<<' ';
		}
		p1=head3;
		head3=p1->pnext;
		free(p1);
	}
	return 0;
}
