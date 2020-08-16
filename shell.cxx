/*
 * shell.cxx
 * 
 * Copyright 2016 Gabriel Vargas <gabreta@VmGabriel96>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <iostream>
#include <time.h>
#include <sys/time.h>

using namespace std;

double timeval_diff(struct timeval *a, struct timeval *b)
{
    return
	(double)(a->tv_sec + (double)a->tv_usec/1000000) -
	(double)(b->tv_sec + (double)b->tv_usec/1000000);
}

int aleatorio ()
{
    int a = rand() % 5000 + 5000;
    return a;
}

void ordenshell (int * a, int N)
{
    int i,j,h;
    int v;
    for(h = 0; h <= N/9; h = ((3*h)+1));
    for(; h>0; h/=3)
    {
	for(i=h;i<N; i+=1)
	{
	    v=a[i];
	    j=i;
	    while(j >= h && a[j-h] > v)
	    {
		a[j] = a[j-h];
		j-=h;
	    }
	    a[j]=v;
	}
    }
}

void llenar (int * a, int n)
{
    for (int i=0;i<n;i++)
    {
	a[i]=aleatorio();
    }
}

void imprimir (int * a, int n)
{
    cout <<"[ ";
    for (int i=0;i<n;i++)
    {
	cout<<a[i]<<" ";
    }
    cout <<"]"<<endl;
}

int main(int argc, char **argv)
{
    int n;

    for (n=100;n<=400;n+=20)
    {
	struct timeval t_ini, t_fin;
	double secs;
    
	int * num = new int [n];
	
	llenar(num,n);

	gettimeofday(&t_ini, NULL);
	ordenshell(num,n);
	gettimeofday(&t_fin, NULL);

	secs = timeval_diff(&t_fin, &t_ini);

	cout <<"Time with "<<n<<" is "<<secs<<endl;

	delete []num;
    }
    
    return 0;
}

