#include<stdio.h>
#include<math.h>
#include<time.h>
#define PI 3.1415

//for time calculations
clock_t start, end;
double cpu_time_used;

//Euler
//y(n+1) = y(n) + h*f(x,y)
//where f(x,y) = x+y
void euler()
{
	float x[6],y[6];
	x[0]=0.0;
	//initializing the x array
    	for(int i=1;i<6;i++)
    	{
    	x[i]=x[i-1]+0.2;
    	}
    
	y[0]=1.0;
	float h=0.2; 		// where h is the step division
	float f[5]; 		// array to store the function values
	printf("Values are \n");
	printf("%f\n",y[0]);
    
	for(int i=0;i<5;i++)
	{
    	f[i]=x[i]+y[i]; 		// stores the addition of (x+y)
    	y[i+1]=y[i]+(h*f[i]);  	//computes the y value
    	printf("%f\n",y[i+1]);
	}
}

//dynamic
void eulermodified()
{
	float x[6],y[6][4];
	x[0]=0.0;
    
	for(int i=1,j=0;i<6,j<4;i++,j++)
	{
  	x[i]=x[i-1]+0.2; 		//initializing x array
  	y[0][j]=1.0; 		//initializing the first row of the y array
	}
    
	float h=0.2;
	
//printing the first row of the array
	for(int i=0;i<4;i++)
	{
	printf("%f  ",y[0][i]);
	}
    
	printf("\n");
	for(int i=1;i<6;i++)
	{
    	y[i][0] = y[i-1][3]+h*(x[i-1]+y[i-1][3]);
    	printf("%f  ",y[i][0]);
   	 
    	y[i][1] = y[i-1][3]+(h/2)*((x[i-1]+y[i-1][3])+(x[i]+y[i][0]));
    	printf("%f  ",y[i][1]);
   	 
    	y[i][2] = y[i-1][3]+(h/2)*((x[i-1]+y[i-1][3])+(x[i]+y[i][1]));
    	printf("%f  ",y[i][2]);
   	 
    	y[i][3] = y[i-1][3]+(h/2)*((x[i-1]+y[i-1][3])+(x[i]+y[i][2]));
    	printf("%f  ",y[i][3]);
    
    	printf("\n");
	}
}

void eulermodified2()
{
    float x[6],y[6][4];
    x[0]=0.0;
    for(int i=1,j=0;i<6,j<4;i++,j++)
    {
   	 x[i]=x[i-1]+0.2;
   	 y[0][j]=1.0;
    }
    float h=0.2;

    for(int i=1;i<6;i++)
    {
   	 y[i][0]=y[i-1][3]+h*(x[i-1]+y[i-1][3]);

   	 y[i][1]=y[i-1][3]+(h/2)*((x[i-1]+y[i-1][3])+(x[i]+y[i][0]));

   	 y[i][2]=y[i-1][3]+(h/2)*((x[i-1]+y[i-1][3])+(x[i]+y[i][1]));

   	 y[i][3]=y[i-1][3]+(h/2)*((x[i-1]+y[i-1][3])+(x[i]+y[i][2]));
    }
}

//calculates the area of a circle
void Area_of_Circle(int radius)
{
  float area=PI*radius*radius;
  printf("\n\nArea of the circle is : %f\n",area);
}

//calculate the Arithmetic_Progression 
//using the first term of series is a and common difference is d
void Arithmetic_Progression (int a, int d, int n)
{
  int ai=a;
  int sum=0;
	for(int i=1;i<=n;i++)
	{
  	sum=sum+ai;
  	ai=ai+d;
	}
  printf("Sum of the AP is : %d\n",sum);
}


//calculate the Optimized Arithmetic Progression
void Optimized_Arithmetic_Progression(int a, int d, float n)
{
  int Optimized_sum;
  Optimized_sum=(n/2)*((2*a)+((n-1)*d));
  printf("Sum of the AP is (using approximation) : %d\n",Optimized_sum);
}

int main()
{
int count=0; 		// Counts iterations simulating code generator

double stateGrid[3]; //Simulates state Grid.

int flag1=0;  		// Flag variables simulate uncovering of approximation methods
int flag2=0;  		// in order to optimize given cell in state grid.

int i;
//Outer Loop simulates continuous code generation of scanner that selects which parts of code to optimize from polyhedral..

printf("\nThe State Grid representation (time taken for each computation):");
for(i=0;i<3;i++)
{
 stateGrid[i]=0;
 printf(" \t %f|",stateGrid[i]);
}
while(count!=2)
{

//circle
start = clock();
Area_of_Circle(5);
end = clock();
cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
stateGrid[0]=cpu_time_used;
printf("Time used for computation : %f\n\n\n",stateGrid[0]);
//Oap
if(flag1==1)
{
start = clock();
Optimized_Arithmetic_Progression(10,5,15);
end = clock();
cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
stateGrid[1]=cpu_time_used;
printf("Time used for computation : %f\n\n\n",stateGrid[1]);
}

//Arithmetic Progression 
if(flag1==0)
{
start = clock();
Arithmetic_Progression(10,5,15);
end = clock();
cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
stateGrid[1]=cpu_time_used;
printf("Time used for computation : %f\n\n\n",stateGrid[1]);
flag1=1;
}

//Euler Modified
if(flag2==1)
{
start = clock();
eulermodified2();
end = clock();
eulermodified();
cpu_time_used = (((double) (end - start)) / CLOCKS_PER_SEC)*10000;
stateGrid[2]=cpu_time_used;
printf("Time used for computation : %f\n\n\n",stateGrid[2]);
}

//Euler
if(flag2==0)
{
start = clock();
euler();
end = clock();
cpu_time_used = (((double) (end - start)) / CLOCKS_PER_SEC)*10000;
stateGrid[2]=cpu_time_used;
printf("Time used for computation : %f\n\n\n",stateGrid[2]);
flag2=1;
}

printf("The State Grid representation (time taken for each computation):");
for(i=0;i<3;i++)
{
 printf(" \t %f|",stateGrid[i]);
}
count++;

}
printf("\n Hence the above computation has been optimized!!");
return 0;

}
