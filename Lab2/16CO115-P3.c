#include<stdio.h>
#include<math.h>

static int countAct =0;

int summer(int num1,int num2,int n){
    int count = 0,a,b,i,sum = 0;
    int c=0;
    while(num1!=0||num2!=0||c!=0){
        a = num1%10;
        b = num2%10;
        num1 = num1/10;
        num2 = num2/10;

        if((a+b+c)>=n){
            i = a+b+c-n;
            c = 1;
        }
        else{
            i=a+b+c;
            c=0;
        }

        sum = sum+i*power(10,count);

        count++;

    }
    return sum;

}
int power(int base,int exp){
    int y=1;
    int i;
    for(i=1;i<=exp;i++){
        y = y*base;
    }
    return y;

}

int sub(int num1,int num2,int n){
	int flag = -1,a,b,c,num22,count=0,sum=0,i;

	int num11 = num1;
   	 num22=num2;

	c=0;
	sum=0;
    	while(num11!=0||num22!=0||c!=0){
		a = num11%10;
		b = num22%10;
		num11 = num11/10;
		num22 = num22/10;
		i = a-b-c;
		if(i<0){
		    i = i+n;
		    c = 1;
		}
		else
		    c = 0;
		if(num11==0&&num22==0&&c>0){
			return -1;

		}
		sum = sum+i*power(10,count);
		count++;



    }



	countAct = summer(countAct,1,n);
	return sum;
}

int main(){

	int num1,num2,n,i,flag=-1;
	char t = 'y';
	while(t=='y'){
		printf("\nEnter the Divident: ");
		scanf("%d",&num1);
		printf("Enter the Divisor: ");
		scanf("%d",&num2);
		printf("Enter the Base: ");
		scanf("%d",&n);
		int r;
		i = num1;
		while(i!=0){
			r = i;
			i = sub(i,num2,n);
			//printf("i = %d\n",i);
			if(i==-1){
				flag = 1;
				break;
			}

		}
		if(flag!=1)
			r=0;
		printf("\nQuotient: %d",countAct);
		printf("\nRemainder: %d",r);
		printf("\nDo you want to continue? y/n\n Your choice..");
		char k;
		scanf("%c",&k);
		scanf("%c",&t);
		countAct = 0;

	}
	return 0;
}


