#include<iostream> 
 #include<conio.h> 
 using namespace std; 
  
 void board(); 
 void input(); 
 void check(); 
 void change(); 
 void setgame(); 
  
 int a[10][10]; 
 int r=0;
 int c=0;
 int value=0; 
 int num=0; 
 int flag=0; 
  
 int main() 
 { 
         setgame(); 
         board(); 
         input(); 
         getch(); 
         return 0; 
 } 
  
 void setgame() 
 { 
         a[1][1]=5; 
         a[1][2]=3; 
         a[1][5]=7; 
         a[2][1]=6; 
         a[2][4]=1; 
         a[2][5]=9; 
         a[2][6]=5; 
         a[3][2]=9; 
         a[3][3]=8; 
         a[3][7]=6; 
         a[4][1]=8; 
         a[4][5]=6; 
         a[4][9]=3; 
         a[5][1]=4; 
         a[5][4]=8; 
         a[5][6]=3; 
         a[5][9]=1; 
         a[6][1]=7; 
         a[6][5]=2; 
         a[6][9]=6; 
         a[7][2]=6; 
         a[7][7]=2; 
         a[8][4]=4; 
         a[8][5]=1; 
         a[8][6]=9; 
         a[8][9]=5; 
         a[9][5]=8; 
         a[9][8]=7; 
         a[9][9]=9; 
 } 
  
 void board() 
 { 
         cout<<"\n\n\nThis Is Main Suduko Board....."<<endl<<endl; 
         cout<<a[1][1]<<" "<<a[1][2]<<" "<<a[1][3]<<"|"<<a[1][4]<<" "<<a[1][5]<<" "<<a[1][6]<<"|"<<a[1][7]<<" "<<a[1][8]<<" "<<a[1][9]<<endl; 
         cout<<a[2][1]<<" "<<a[2][2]<<" "<<a[2][3]<<"|"<<a[2][4]<<" "<<a[2][5]<<" "<<a[2][6]<<"|"<<a[2][7]<<" "<<a[2][8]<<" "<<a[2][9]<<endl; 
         cout<<a[3][1]<<" "<<a[3][2]<<" "<<a[3][3]<<"|"<<a[3][4]<<" "<<a[3][5]<<" "<<a[3][6]<<"|"<<a[3][7]<<" "<<a[3][8]<<" "<<a[3][9]<<endl; 
         cout<<"================="<<endl;
         cout<<a[4][1]<<" "<<a[4][2]<<" "<<a[4][3]<<"|"<<a[4][4]<<" "<<a[4][5]<<" "<<a[4][6]<<"|"<<a[4][7]<<" "<<a[4][8]<<" "<<a[4][9]<<endl; 
         cout<<a[5][1]<<" "<<a[5][2]<<" "<<a[5][3]<<"|"<<a[5][4]<<" "<<a[5][5]<<" "<<a[5][6]<<"|"<<a[5][7]<<" "<<a[5][8]<<" "<<a[5][9]<<endl; 
         cout<<a[6][1]<<" "<<a[6][2]<<" "<<a[6][3]<<"|"<<a[6][4]<<" "<<a[6][5]<<" "<<a[6][6]<<"|"<<a[6][7]<<" "<<a[6][8]<<" "<<a[6][9]<<endl; 
         cout<<"================="<<endl;
         cout<<a[7][1]<<" "<<a[7][2]<<" "<<a[7][3]<<"|"<<a[7][4]<<" "<<a[7][5]<<" "<<a[7][6]<<"|"<<a[7][7]<<" "<<a[7][8]<<" "<<a[7][9]<<endl; 
         cout<<a[8][1]<<" "<<a[8][2]<<" "<<a[8][3]<<"|"<<a[8][4]<<" "<<a[8][5]<<" "<<a[8][6]<<"|"<<a[8][7]<<" "<<a[8][8]<<" "<<a[8][9]<<endl; 
         cout<<a[9][1]<<" "<<a[9][2]<<" "<<a[9][3]<<"|"<<a[9][4]<<" "<<a[9][5]<<" "<<a[9][6]<<"|"<<a[9][7]<<" "<<a[9][8]<<" "<<a[9][9]<<endl; 
 } 
  
 void change() 
 { 
         if(r>9 || c>9 || r<0 || c<0) 
         { 
                 cout<<"Invalid move"<<endl; 
                 num=1; 
         } 
         else if(a[r][c]==1 || a[r][c]==2 || a[r][c]==3 || a[r][c]==4 || a[r][c]==5 || a[r][c]==6 || a[r][c]==7 || a[r][c]==8 || a[r][c]==9) 
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
                 else if(flag == 1) 
                 { 
                         cout<<"Entered value does not fit in that place"<<endl; 
                         flag--;
                         goto start; 
                 } 
                 else
                 { 
                         system("CLS"); 
                         a[r][c]=value; 
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
                         cout<<"\n\nPositon :: "<<endl; 
                         cout<<"\n\nRow :: ";
                         cin>>r;
                         cout<<"\n\nColumn :: ";
                         cin>>c; 
                         change(); 
                 } 
         } 
 } 
  
 void check() 
 {
    //row
    for(int i=1;i<=9;i++)
    {
        if(a[i][c]==value)
        {
            flag++;
            break;
        }
    }
    //column
    for(int i=1;i<=9;i++)
    {
        if(a[r][i]==value)
        {
            flag=1;
            break;
        }
    }
    //box
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            if(a[][]==value)
            {
                flag=1;
                break;
            }
        }
    }
 }