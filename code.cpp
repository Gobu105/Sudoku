#include<iostream>
#include<conio.h>
using namespace std;

void dummy();
void board();
void input();
void check();
void change();
void setgame();

int a[82];
int position=0;
int value=0;
int num=0;
int flag=0;

int main()
{
	setgame();
	dummy();
	board();
	input();
	getch();
	return 0;
}

void setgame()
{
	a[1]=5;
	a[2]=3;
	a[5]=7;
	a[10]=6;
	a[13]=1;
	a[14]=9;
	a[15]=5;
	a[20]=9;
	a[21]=8;
	a[26]=6;
	a[28]=8;
	a[32]=6;
	a[36]=3;
	a[37]=4;
	a[40]=8;
	a[42]=3;
	a[45]=1;
	a[46]=7;
	a[50]=2;
	a[54]=6;
	a[56]=6;
	a[61]=2;
	a[67]=4;
	a[68]=1;
	a[69]=9;
	a[72]=5;
	a[77]=8;
	a[80]=7;
	a[81]=9;
}

void dummy()
{
	cout<<"For Position Reference Use This Board....."<<endl<<endl;
	cout<<" 1  2  3| 4  5  6| 7  8  9"<<endl;
	cout<<"10 11 12|13 14 15|16 17 18"<<endl;
	cout<<"19 20 21|22 23 24|25 26 27"<<endl;
	cout<<"=========================="<<endl;
	cout<<"28 29 30|31 32 33|34 35 36"<<endl;
	cout<<"37 38 39|40 41 42|43 44 45"<<endl;
	cout<<"46 47 48|49 50 51|52 53 54"<<endl;
	cout<<"=========================="<<endl;
	cout<<"55 56 57|58 59 60|61 62 63"<<endl;
	cout<<"64 65 66|67 68 69|70 71 72"<<endl;
	cout<<"73 74 75|76 77 78|79 80 81"<<endl;
}

void board()
{
	cout<<"\n\n\nThis Is Main Suduko Board....."<<endl<<endl;
	cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<"|"<<a[4]<<" "<<a[5]<<" "<<a[6]<<"|"<<a[7]<<" "<<a[8]<<" "<<a[9]<<endl;
	cout<<a[10]<<" "<<a[11]<<" "<<a[12]<<"|"<<a[13]<<" "<<a[14]<<" "<<a[15]<<"|"<<a[16]<<" "<<a[17]<<" "<<a[18]<<endl;
	cout<<a[19]<<" "<<a[20]<<" "<<a[21]<<"|"<<a[22]<<" "<<a[23]<<" "<<a[24]<<"|"<<a[25]<<" "<<a[26]<<" "<<a[27]<<endl;
	cout<<"================="<<endl;
	cout<<a[28]<<" "<<a[29]<<" "<<a[30]<<"|"<<a[31]<<" "<<a[32]<<" "<<a[33]<<"|"<<a[34]<<" "<<a[35]<<" "<<a[36]<<endl;
	cout<<a[37]<<" "<<a[38]<<" "<<a[39]<<"|"<<a[40]<<" "<<a[41]<<" "<<a[42]<<"|"<<a[43]<<" "<<a[44]<<" "<<a[45]<<endl;
	cout<<a[46]<<" "<<a[47]<<" "<<a[48]<<"|"<<a[49]<<" "<<a[50]<<" "<<a[51]<<"|"<<a[52]<<" "<<a[53]<<" "<<a[54]<<endl;
	cout<<"================="<<endl;
	cout<<a[55]<<" "<<a[56]<<" "<<a[57]<<"|"<<a[58]<<" "<<a[59]<<" "<<a[60]<<"|"<<a[61]<<" "<<a[62]<<" "<<a[63]<<endl;
	cout<<a[64]<<" "<<a[65]<<" "<<a[66]<<"|"<<a[67]<<" "<<a[68]<<" "<<a[69]<<"|"<<a[70]<<" "<<a[71]<<" "<<a[72]<<endl;
	cout<<a[73]<<" "<<a[74]<<" "<<a[75]<<"|"<<a[76]<<" "<<a[77]<<" "<<a[78]<<"|"<<a[79]<<" "<<a[80]<<" "<<a[81]<<endl;
}

void change()
{
	if((position>81)||(position<0))
	{
		cout<<"Invalid move"<<endl;
		num=1;
	}
	else if(a[position]==1 || a[position]==2 || a[position]==3 || a[position]==4 || a[position]==5 || a[position]==6 || a[position]==7 || a[position]==8 || a[position]==9)
	{
		cout<<"Invalid move"<<endl;
		num=1;
	}
	else
	{
		start:
		cout<<"Value :: ";
		cin>>value;
		check();
		if((value>9)||(value<1))
		{
			cout<<"Invalid move"<<endl;
			goto start;
		}
		else if(flag>=1)
		{
			cout<<"Entered value does not fit in that place"<<endl;
			flag=0;
			goto start;
		}
		else
		{
			system("CLS");
			a[position]=value;
			dummy();
			board();
		}
	}
}

void input()
{
	for(int i=1;i<=81;i++)
	{
		if(num==1)
		{
			i--;
			num--;
		}
		else
		{
			cout<<"\n\nPositon :: ";
			cin>>position;
			change();
		}
	}
}

void check()
{
	//row
	int rem=0;
	rem = position % 9;
	switch (rem)
	{
	case 0:
		{
			for(int i=1;i<=8;i++)
			{
				if(a[position]==a[position-i])
				{
					flag++;
					
				}break;
			}
			break;
		}
		case 1:
		{
			for(int i=1;i<=8;i++)
			{
				if(a[position]==a[position+i])
				{
					flag++;
					
				}break;
			}
			break;
		}
		case 2:
		{
			if(a[position]==a[position-1])
			{
				flag += 1;
			}
			for(int i=1;i<=7;i++)
			{
				if(a[position]==a[position+i])
				{
					flag++;
				}break;
			}
			break;
		}
		case 3:
		{
			for(int i=1;i<=2;i++)
			{
				if(a[position]==a[position-i])
				{
					flag++;
					
				}break;
			}
			for(int i=1;i<=6;i++)
			{
				if(a[position]==a[position+i])
				{
					flag++;
					
				}break;
			}
			break;
		}
		case 4:
		{
			for(int i=1;i<=3;i++)
			{
				if(a[position]==a[position-i])
				{
					flag++;
					
				}break;
			}
			for(int i=1;i<=5;i++)
			{
				if(a[position]==a[position+i])
				{
					flag++;
					
				}break;
			}
			break;
		}
		case 5:
		{
			for(int i=1;i<=4;i++)
			{
				if(a[position]==a[position-i])
				{
					flag++;
					
				}break;
			}
			for(int i=1;i<=4;i++)
			{
				if(a[position]==a[position+i])
				{
					flag++;
					
				}break;
			}
			break;
		}
		case 6:
		{
			for(int i=1;i<=5;i++)
			{
				if(a[position]==a[position-i])
				{
					flag++;
					
				}break;
			}
			for(int i=1;i<=3;i++)
			{
				if(a[position]==a[position+i])
				{
					flag++;
					
				}break;
			}
			break;
		}
		case 7:
		{
			for(int i=1;i<=6;i++)
			{
				if(a[position]==a[position-i])
				{
					flag++;
					
				}break;
			}
			for(int i=1;i<=2;i++)
			{
				if(a[position]==a[position+i])
				{
					flag++;
					
				}break;
			}
			break;
		}
		case 8:
		{
			for(int i=1;i<=7;i++)
			{
				if(a[position]==a[position-i])
				{
					flag++;
					
				}break;
			}
			if(a[position]==a[position+1])
			{
				flag++;
				
			}
			break;
		}
		default:
			break;
	}
}
