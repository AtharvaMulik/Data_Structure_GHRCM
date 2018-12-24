# include<stdio.h>


void main()
{
	int a[10],i,j,n,temp;


	printf("\n enter no of elements");

	scanf("%d",&n);


	printf("\n enter elements");

	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}

	printf("\n before");

	for(i=0;i<n;i++)
	{
		printf("\n %d",a[i]);
	}


	for(i=0;i<n;i++)
	{

		for(j=i;j<n;j++)
		{
			if(a[i]>a[j])
			{
			    temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}

	printf("\n after");

	for(i=0;i<n;i++)
	{
		printf("\n %d",a[i]);
	}

}
