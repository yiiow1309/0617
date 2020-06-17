#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
struct trump
{
	int order;
	char shape[3];
	int number;
};

void make_card(struct trump m_card[])
{
	int i,j;
	char shape[4][3]={"��","��","��","��"};
	for(i=0;i<4;i++)
	{
		for(j=i*13;j<i*13+13;j++)
		{
			m_card[j].order=i;
			strcpy(m_card[j].shape,shape[i]);
			m_card[j].number=j%13+1;
		
			switch(m_card[j].number)
			{
				case 1:
					m_card[j].number='A';
				case 11:
					m_card[j].number='J';
				case 12:
					m_card[j].number='Q';
				case 13:
					m_card[j].number='K';
					break;
			}
		}
	}
}
void display_card(struct trump m_card[])
{
	int i, count=0;
	for(i=0;i<52;i++)
	{
		printf("%s",m_card[i].shape);
		if(10<m_card[i].number)
			printf("%-2c",m_card[i].number);
		else
			printf("%-2d",m_card[i].number);
		count++;
		if(i%13+1==13)
		{
			printf("\n");
			count=0;
		}	
	}
}
void shuffle_card(struct trump m_card[])
{
	int i,rnd;
	struct trump tmep;
	srand(time(NULL));
	for(i=0;i<52;i++)
	{
		rnd=rand()%52;
		struct trump temp=m_card[rnd];
		m_card[rnd]=m_card[i];
		m_card[i]=temp;
	}
}
int main(void)
{
	
	struct trump card[52];
	make_card(card);
	shuffle_card(card);
	display_card(card);
	return 0;
}

