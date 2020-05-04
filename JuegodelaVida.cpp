#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;

long binario(long num){
	if(num < 2)
		return num;
	else
		return num%2 + (10 * binario(num/2));
}
	
	int main(){
		long num, bin;
		int index =8;
		int contador =0;
		int n,z=0;
		
		int vec[10][10];
		int vec1[10][10];
		
		
		for(int i=1;i<9;i++)
		{
			for(int j=1;j<9;j++)
			{
				vec[i][j]=0;
				vec1[10][10]=0;
			}
			
		}
		for(int i=0;i<9;i++)
		{
			vec[0][i]=3;
			vec1[0][i]=3;
			vec[i][0]=3;
			vec1[i][0]=3;
			vec[9][i]=3;
			vec1[9][i]=3;
			vec[i][9]=3;
			vec1[i][9]=3;
		}
		
		cout<<"Bienvenido al juego de la vida "<<endl;
		cout<<"Ingrese el numero de iteraciones: ";
		cin>>n;
		cout<<endl<<"Ingrese valores dentro del rango de (0-255)"<<endl;
		
		for(int i=1;i<9;i++)
		{
			index=8;
			
				
			cout<<"Ingrese el numero "<<i<<" : ";
			cin>>num;
			while(num<0 || num>255)
			{
				cout<<"Numero fuera de rango"<<endl;
				cout<<"Ingrese otro numero "<<i<<" : ";
				cin>>num;
			}
			bin=binario(num);
			
			
			while(bin!=0)
			{
				vec[i][index]=bin%10;
				bin/=10;
				index--;
			}
		}
		cout<<endl<<endl;
		system("cls");
		
		cout<<"          Configuracion inicial:"<<endl<<endl;
		for(int i=1;i<9;i++)
		{
			cout<<"          ";
			for(int j=1;j<9;j++)
			{
				cout<<vec[i][j]<<" ";
			}cout<<endl<<endl;
			
		}
		
		while(z<n)
		{
			Sleep(1000);
			system("cls");
			for(int i=1;i<9;i++)
			{
				for(int j=1;j<9;j++)
				{contador=0;
					
					if(vec[i-1][j-1]==0 || vec[i-1][j-1]==1)
					{
						contador+=vec[i-1][j-1];
					}
					
					if(vec[i][j-1]==0 || vec[i][j-1]==1)
					{
						contador+=vec[i][j-1];
					}
					
					if(vec[i+1][j-1]==0 || vec[i+1][j-1]==1)
					{
						contador+=vec[i+1][j-1];
					}
					
					if(vec[i-1][j]==0 || vec[i-1][j]==1)
					{
						contador+=vec[i-1][j];
					}
					
					if(vec[i+1][j]==0 || vec[i+1][j]==1)
					{
						contador+=vec[i+1][j];
					}
					
					if(vec[i-1][j+1]==0 || vec[i-1][j+1]==1)
					{
						contador+=vec[i-1][j+1];
					}
					
					if(vec[i][j+1]==0 || vec[i][j+1]==1)
					{
						contador+=vec[i][j+1];
					}
					
					if(vec[i+1][j+1]==0 || vec[i+1][j+1]==1)
					{
						contador+=vec[i+1][j+1];
					}
					
					if(vec[i][j]==0 && contador == 3)
					{
						vec1[i][j]=1;
					}
					else
					{
						if(vec[i][j]==1 && (contador==2 || contador ==3))
						{
							vec1[i][j]=1;
						}
						else
						{
							vec1[i][j]=0;
						}
					}
					
					
					
					
					
					
					
					
				}
				
				
			}
			cout<<endl<<endl;
			for(int i=1;i<9;i++)
			{
				cout<<"          ";
				for(int j=1;j<9;j++)
				{
					cout<<vec1[i][j]<<" ";
				}cout<<endl<<endl;
				
			}
			
			for(int i=1;i<9;i++)
			{
				for(int j=1;j<9;j++)
				{
					vec[i][j]=vec1[i][j];
				}
				
			}
			z++;
		}
		
		
		
		
		
		
		
		
		
		return 0;
	}
