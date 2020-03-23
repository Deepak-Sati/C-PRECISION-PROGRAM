#include <stdio.h>
#include <stdlib.h>

const double CONSTVAL = 5.94017125272043;

double y[24] = 
{

0.89608802455664  , -0.083381608939051    , 0.24686007793153   , 0                     , 0.067658648473815 , -0.21072103131565 , 0 ,
0.048790164169432 , 0.13976194237516      , 0.17395330712344   , 0.13976194237516      , 0                 , 0.095310179804325 ,
0.086177696241052 , 0 , 0.086177696241052 , -0.072570692834835 , 0 , 0.22020940501452  , 0.17980808272355  ,
0.25084337466372  , 0.14606631905197      , 0.34629704820832   , 4.4841028037230

};

double rand_num[24];

void generate_random() 
{
  for (int i = 0; i < 24; i++)
      rand_num[i] = ((float)rand()/(float)(RAND_MAX)) * 7.0;                // Random values in range [0,7)
}

double sum()
{
double sm=0.0;
  for(int i = 0; i < 24; i++)
      sm += (rand_num[i]*y[i]);                                             // Total sum of given equation
return sm;
}

void print()
{
for(int i=0;i<24;i++)
printf("Randomly Generated value of %c is = %lf \n",i+97,rand_num[i]);      // ASCII value of letters 
}

void main() 
{
   generate_random();

   double current_sum = 5.435066;
   double remaining = CONSTVAL - current_sum;
   rand_num[23] =  remaining / (double)y[23];                              // Adjusting last value according to given sum

   print();
   printf("\n --- Total Sum of given equation is --- \n");
   printf("\n%.12lf\n\n",sum());

}
