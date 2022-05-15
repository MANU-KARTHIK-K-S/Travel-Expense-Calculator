#include<stdio.h>
#include<math.h>
void main()
{   int pass_num;
    printf("Enter the no of passengers : ");
	scanf("%d",&pass_num);
	int passenger[pass_num],expense=0,flag[pass_num],temp,items,contribution[pass_num],expen_tem[pass_num];
	printf("Enter the no of items purchased(cost of each tasks) : ");
	scanf("%d",&items);
	for(int i=0;i<items;i++)
	{
        printf("Enter the expense of item no %d : ",i+1);
		scanf("%d",&temp);
		expense+=temp;
	}
	printf("Enter the contribution of each person (alphabetical order): \n");
	for(int i=0;i<pass_num;i++)
	{
        printf("Contribution of person %d : ",i+1);
		scanf("%d",&contribution[i]);
		expen_tem[i] = passenger[i]=expense/pass_num;
		passenger[i]-=contribution[i];
		if (passenger[i]<0)
		{
			passenger[i]=abs(passenger[i]);
			printf("Person %d will get an amount of %d from others. \n\n",i+1,passenger[i]);
			flag[i]=2;
		}
        else
        {
            printf("Person %d will have to pay an amount of %d. \n\n",i+1,passenger[i]);
			flag[i]=1;
        }
		
		
	}
	printf("\n\n");
	for (int i = 0; i < pass_num; i++)
		{

			for (int j = 0; j < pass_num; j++)
			{
				if (flag[i]==0)	
				{
					break;
				}
				
				if (j!=i)
				{
					if (flag[i]==2 && flag[j]==1)
					{
						if (passenger[i]>passenger[j])
						{
							passenger[i]-=passenger[j];
							printf("person %d have to pay an amount of Rs. %d to person %d.\n",j+1,passenger[j],i+1);
							passenger[j]=flag[j]=0;
						}
						else
						{
							if (passenger[i]>0)
							{
								passenger[j]-=passenger[i];
								printf("person %d have to pay an amount of Rs. %d to person %d.\n",j+1,passenger[i],i+1);
								passenger[i]=flag[i]=0;
							}
							
						}
						
					}
					
				}
				
			}
			
		}
}
