#include<stdio.h>

#include<stdlib.h>

int main()

{

int n=17;

int *p,q,**s;

p=&n;

q=*p;

s=&p;


printf("\np::%d",&(*p));

printf("\nn::%d",n);

printf("\np::%d",p);

printf("\nq::%d",q);

printf("\ns::%d",s);

p++;

printf("\np::%d",p);

p=p+1;

printf("\np+1::%d",p);

}
