#include<stdio.h>
#include<string.h>
char p[5];
int power(int base,int exp){
    int y=1;
    int i;
    for(i=1;i<=exp;i++){
        y = y*base;
    }
    return y;

}

void def(int n){

	switch(n){
		case 0:
			strcpy(p,"0000");
			break;
		case 1:
			strcpy(p,"0001");
            		break;
		case 2:
			strcpy(p,"0010");
		            break;
		case 3:
			strcpy(p,"0011");
        		    break;
   		case 4:
			strcpy(p,"0100");
			break;
		case 5:
			strcpy(p,"0101");
			break;
		case 6:
			strcpy(p,"0110");
			break;
		case 7:
			strcpy(p,"0111");
			break;
		case 8:
			strcpy(p,"1000");
			break;	
		case 9:
			strcpy(p,"1001");
			break;
	}


}
void def2(int n){

	switch(n){
		case 0:
			strcpy(p,"0000");
			break;
		case 1:
			strcpy(p,"0001");
			break;
		case 2:
			strcpy(p,"0010");
			break;
		case 3:
			strcpy(p,"0011");
			break;
   		case 4:
			strcpy(p,"0100");
			break;
		case 5:
			strcpy(p,"1011");
			break;
		case 6:
			strcpy(p,"1100");
			break;
		case 7:
			strcpy(p,"1101");
			break;
		case 8:

			strcpy(p,"1110");
			break;
		case 9:
			strcpy(p,"1111");
			break;
	}


}
int numDigits(int n){
	int count = 0;
	while(n!=0){
		n = n/10;
		count++;
	}
	return count;
}

int compliment(int num,int dig){
	int sum=0;
	int i;
	for(i=0;i<dig;i++){
		sum = sum+9*power(10,i);
	}
	return sum - num;
}

int main(){
	int i,num1,dum,a,n;
	char *b;
	printf("Enter the decimal no: ");
	scanf("%d",&num1);
	printf("Enter the choice: \n1.BCD\n2.2421\nYour choice  ");
	scanf("%d",&i);
	int k;
	switch(i){
		case 1:
			i=0;
			dum = num1;
			n = numDigits(dum);
			printf("The BCD value of the decimal no is:  ");
			while(i<n){
				a = dum - (dum%(power(10,n-i-1)));
				a=a/(power(10,n-i-1));
				dum = dum%(power(10,n-i-1));

				i++;

				def(a);
				printf("%s",p);
			}

			i=0;
			dum = compliment(num1,n);
			printf("\nThe 9's compliment of the decimal is: %d",dum);
			printf("\nThe 9's compliment of the decimal in BCD is: ");
			while(i<n){
				a = dum - dum%(power(10,n-i-1));
				a=a/power(10,n-i-1);
				dum = dum%(power(10,n-i-1));
				i++;
				def(a);
				printf("%s",p);
			}
			printf("\nSince they ain't compliment of each other... BCD is not self-complimentary\n");
			break;
		case 2:
			i=0;
			dum = num1;
			n = numDigits(dum);
			printf("The 2421 value of the decimal no is:  ");
			while(i<n){
				a = dum - dum%(power(10,n-i-1));
				a=a/power(10,n-i-1);
				dum = dum%(power(10,n-i-1));
				i++;

				def2(a);
				printf("%s",p);
			}

			i=0;
			dum = compliment(num1,n);
			printf("\nThe 9's compliment of the decimal is: %d",dum);
			printf("\nThe 9's compliment of the decimal in 2421 is: ");
			while(i<n){
				a = dum - dum%(power(10,n-i-1));
				a=a/power(10,n-i-1);;
				dum = dum%(power(10,n-i-1));
				i++;
				def2(a);
				printf("%s",p);
			}
			printf("\nSince they are compliment of each other... 2421 is self-complimentary\n");
			break;
	}
	return 0;
}



