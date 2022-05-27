#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double arr[3][5], PivotEle = 0;
	int pivotColumn = 0, pivotRow=0, lead=0;
	bool flag = true;
	cout << "\t\t\t\t"<<setw(50) << setfill('*')<<" ";
	cout << "\n\t\t\t\t\t\t  Simplex Method\n";
	cout << "\t\t\t\t" << setw(50) << setfill('*') << " ";
	cout << "\nPlease Enter Simplex Table:";
	for (int i = 0; i < 3; i++)
	{
		cout << "\nRow("<<i+1<<")-:>> ";
		for (int j = 0; j < 5; j++)
		{
			cin >> arr[i][j];
		}
	}
	
	for (int i = 0; i < 5; i++)
	{
		if (arr[2][i]<arr[2][pivotColumn])
		{
			pivotColumn = i;
		}
	}

		if ((arr[0][4]/arr[0][pivotColumn]) < (arr[1][4] / arr[1][pivotColumn]))
		{
			pivotRow = 0;
		}
		else
		{
			pivotRow = 1;
		}
		PivotEle = arr[pivotRow][pivotColumn];
		cout << setw(55) << setfill('*') << "\n";
		cout << "Pivot column is column number " << pivotColumn+1 << " , " << "Pivot row is row number " << pivotRow+1 <<" , "<< "Pivot Element= " << PivotEle << "\n";
		cout << setw(55) << setfill('*') << "\n";
		while (flag==true&&lead<3)
		{
			double d, m;
			for (int i = 0; i < 3; i++)
			{
				d = arr[lead][lead];
				m = arr[i][lead] / d;
				for (int j = 0; j < 5; j++)
				{
					if (i==lead)
					{
						arr[i][j] /= d;
					}
					else
					{
						arr[i][j] -= arr[lead][j] * m;
					}
				}
			}
			lead++;
			for (int k = 0; k < 5; k++)
			{
				if (arr[2][k]<0)
				{
					flag = true;
					break;
				}
				else
				{
					flag = false;
				}
			}
			if (flag == true)
			{
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						cout << " (" << arr[i][j] << ") ";
					}
					cout << endl;
				}
			for (int i = 0; i < 5; i++)
			{
				if (arr[2][i] < arr[2][pivotColumn])
				{
					pivotColumn = i;
				}
			}

			if ((arr[0][4] / arr[0][pivotColumn]) < (arr[1][4] / arr[1][pivotColumn]))
			{
				pivotRow = 0;
			}
			else
			{
				pivotRow = 1;
			}
			PivotEle = arr[pivotRow][pivotColumn];
	
				cout << setw(55) << setfill('*') << "\n";
				cout << "Pivot column is column number " << pivotColumn + 1 << " , " << "Pivot row is row number " << pivotRow + 1 << " , " << "Pivot Element= " << PivotEle << "\n";
				cout << setw(55) << setfill('*') << "\n";
			}
		}
		cout << " \nSolution:\n";
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				cout << " ("<<arr[i][j]<<") ";
			}
			cout << endl;
		}
		cout << " \nMax Z= " << arr[2][4]<<"\n";
}