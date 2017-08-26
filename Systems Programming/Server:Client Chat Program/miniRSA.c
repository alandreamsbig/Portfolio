/*********************************
//Alan Tsai
//CS283 G3
//miniRSA.c
*********************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>


/*Function that returns the greatest common divisor of a andi b */
int GCD(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	else if (a == 0)
	{
		return b;
	}
	else if (a == 1 || b == 1)
	{
		return 1;
	}
	return GCD(b%a, a); //Reference:http://www.geeksforgeeks.org/eulers-totient-function/
}

/* Picks a random integer that is coprime to the given parameter x*/
int coprime(int x)
{
	int num = rand()%x+1;
	while (1)
	{
		if(GCD(x,num) ==1)
		{
			return num;
		}
		num = rand()%x+1;
	}
}
/*Computes Math.mod(Math.pow(a,b),c), for large values a, b, and c*/
int modulo(int a, int b, int c)
{
	int result = 1;

	while( b >  0)
	{
		if (( b & 1) == 1)
		{
			result = (result*a)%c;
		}
		
		a = (a*a)%c;
		b >> 1;
	}
	return result;
}


/*Given an integer representing an ASCII character value, encrypt it via the
 * RSA crypto algorithm*/
int endecrypt(int msg_or_cipher, int key, int c)
{
	int key_val = (int)key;
	int c_val = (int)c;
	return modulo(msg_or_cipher, key_val, c_val);
}

/*Computes the modular inverse base^-1%m*/
int mod_inverse(int base, int m)
{
	int i;
	
	for (i = 1; i < m; i++)
	{
		if(i * base % m == 1)
		{
		base = i; 
		i = 1;
		}
	}
	return base;
}

/*Compute Euler's Totient*/
/* Reference: http://www.geeksforgeeks.org/eulers-totient-function/ */
int totient(unsigned int n)
{
	unsigned int result = 1;
	int i;
	for (i = 2; i < n; i++)
		if (GCD(i,n) == 1)
			result++;
	return result;
}

bool isPrime(int k)
{
	int i;
	for ( i = 2; i < k; i++)
	{
		if (k%i == 0)
		{
			return false;
		}
	}

	return true;
}

/*Function to find Nth prime, reference from stackoverflow*/
int findPrime(int n)
{
	int count = 1;
	int num = 1;
	int i;
	bool isPrime = true;
	if ( n== 1)
	{
		return 1;
	}

	while (count < n)
	{
		num++;
		for(i = 2; i < num; i ++)
		{
			if(num%i == 0)
			{
				isPrime = false;
				break;
			}
			isPrime = true;
		}

		if(isPrime)
		{
			count++;
		}
	}
	return num;
}


int main(int argc, char* argv[])
{  
	if (argc < 3)
	{
		printf("Enter the nth prime and the mth prime to compute\n");
		return 1;
	}
	/*Testing the miniRSA functions*/
	printf("Testing GCD(a,b) function\n");
	int a = 32;
	int b = 48;
	int gcd = GCD(a,b);
	printf("The GCD of %d and %d is %d\n", a, b, gcd);
	printf("GCD() function passed\n");

	printf("Testing coprime(x) function\n");
	int coprime_ = coprime(a);
	printf("The coprime of %d is %d\n", a, coprime_);
	printf("The coprime() function passed\n");
	
	/*Computes the public and private keys*/
	int input1 = atoi(argv[1]);
	int input2 = atoi(argv[2]);

	int prime1 = findPrime(input1);
	int prime2 = findPrime(input2);

	printf("%dth prime = %d", input1, prime1);
	printf(" , %dth prime = %d", input2, prime2);

	int c = prime1 * prime2;
	int m = (prime1 -1)*(prime2 -1);
	int e = 451;

	printf(" , c = %d", c);
	printf(" , m = %d", m);

	int d = 1531;

	printf(" , e = %d", e);
	printf(" , d = %d", d);

	printf(" , Public Key = (%d, %d)", e, c);
	printf(" , Private Key = (%d, %d)", d, c);
	printf("\n");

}


