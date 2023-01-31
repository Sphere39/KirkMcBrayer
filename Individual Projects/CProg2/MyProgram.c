#include <stdio.h>
long a = 10000; 
long b = 0; 
long c = 2800;
long d = 0;
long e = 0; 
long f[2801]; 
long g = 0;
int main ()
{
	//Terse Version
	printf("Terse Version:\n");
	for (;b - c;) 
		f[++b] = a / 5;
		for(;d = 0, g = c * 2 ; c -= 14, printf("%.4d", e + d / a), e = d % a)
			for(b = c;d += f[b] * a, f[b] = d % --g, d /= g--, --b; d *= b);
	//Verbose Version
	printf("\nVerbose Version:\n");
	while (b - c)
	{
		b = b + 1;
		f[b] = a / 5;
	}
	while(g = c * 2)
	{
		b = c;
		d = d + (f[b] * a); 
		g = g - 1; 
		f[b] = d % g;
		d = d / g;
		g = g - 1;
		while(b = b - 1)
		{
			d = d * b;
			d = d + (f[b] * a);
			g = g - 1;
			f[b] = d % g;
			d = d / g;
			g = g - 1;
		}
		c = c -14;
		printf("%.4d", e + d / a);
		e = d % a;
		d = 0;
	}
	return 0;
}


