
#include	<stdio.h>
int main(void)
{
   double amount, q, GST, b, d, rd, ini, rn, ipe, rpe;
   int x, a, id, ni, pe;
   float change;

   printf("Please enter the amount to be paid: $");
   scanf("%lf", &amount);
   GST = amount*.13 + .005;
   printf("GST: %.2lf\n", GST);
   amount = amount + GST;
   printf("Balance owing: $%.2lf\n", amount);
   x = amount;
   change = amount - x;
   printf("Loonies required: %d, balance owing $%.2lf\n", x, change);
   q = change / (0.25);
   a = q;
   b = change - (a*0.25);
   printf("Quarters required: %d, balance owing $%.2lf\n", a, b);
   d = b / 0.10;
   id = d;
   rd = b - (id*0.10);
   printf("Dimes required: %d, balance owing $%.2lf\n", id, rd);
   ini = rd / 0.05;
   ni = ini;
   rn = rd - (ni*0.05);
   printf("Nickels required: %d, balance owing $%.2lf\n", ni, rn);
   ipe = rn / 0.01;
   pe = ipe;
   rpe = rn - (pe*0.01);
   printf("Pennies required: %d, balance owing $%.2lf\n", pe, rpe);

   return 0;
}

