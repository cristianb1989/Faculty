
#include<stdio.h>
#include<math.h> // se foloseste pt delta
	int main()
	{
		double a, b, c, d;
		printf("a="); scanf("%lf", &a);
		printf("b="); scanf("%lf", &b);
		printf("c="); scanf("%lf", &c);
		if (a==0)
		{
			if (b==0)
			{
				if (c==0)
				{
					printf("Orice x este solutie a ecuatiei\n");
				}
				else
				{
					printf("Nu exista nici o solutie\n");
				}
			}
			else
			{
				printf("Solutia ecuatiei este x = %lf\n", -c/b);
			}
		}
		else
		{
			d = (b*b)-(4*a*c);
			if (d>=0)
				{
					printf("x1 = %lf\nx2= %lf\n", (-b+sqrt(d))/(2*a), (-b-sqrt(d))/(2*a)); // se foloseste sqrt pentru radical
				}
			else
			{
				printf("Nu exista solutie reala\n");
			}
		}
	return 0;

	}
