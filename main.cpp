#include <iostream>
#include<cstdlib>
#define rm 8
#define cm 8
using namespace std;
class linkedlist
{
    struct node
    {
        int row;
        int col;
        node *link;
    }*start,*start1;
public:
    linkedlist()
    {
        start1=NULL;
        start=NULL;
    }
    void insertend(int x,int y);
    void display(char a[rm][cm]);
    void maze(char a[rm][cm],char newa[rm][cm],int sr,int sc,int dr,int dc);
    void deletebeg();
    bool checkright(int i,int j,char a[rm][cm],char newa[rm][cm]);
    bool checkleft(int i,int j,char a[rm][cm],char newa[rm][cm]);
    bool checkup(int i,int j,char a[rm][cm],char newa[rm][cm]);
    bool checkdown(int i,int j,char a[rm][cm],char newa[rm][cm]);
    void gamestart(char newa[rm][cm],char sol[rm][cm],int sr,int sc,int dr,int dc);
    bool check(int i, int j);
    void insert_stack(int x,int y)
{
    node *n1=new node;
            n1->row=x;
            n1->col=y;
        if(start1==NULL)
        {
            start1=n1;
            n1->link=NULL;
        }
        else
        {
         n1->link=start1;
         start1=n1;
        }
}

void delete_stack()
{
   node *t1=start1;
   start1=start1->link;
   t1->link=NULL;
   delete(t1);

}
int stack_size()
{
    node *ptr=start1;
    int c=0;
    while(ptr!=NULL)
    {
         c++;
        ptr=ptr->link;
    }
    cout<<c;
    return c;

}

struct node* chances(char sol[rm][cm],int flag[rm][cm])
{
    int sizes=stack_size();
    if(sizes<=5)
    {
        while(start1->link!=NULL)
        {
            sol[start1->row][start1->col]=' ';
            flag[start1->row][start1->col]=0;
            delete_stack();
        }
    }
    else
    {
        int len=sizes-5;
        while(sizes!=len)
        {
            sol[start1->row][start1->col]=' ';
            flag[start1->row][start1->col]=0;
            delete_stack();
            sizes -=1;
        }
    }

}



    void insertbeg(int x,int y)
    {
        node *temp=new node;
        temp->row=x;
        temp->col=y;
        if(start1==NULL)
        {
            start1=temp;
            start1->link=NULL;

        }
        else
        {
            temp->link=start;
            start1=temp;

        }
    }
};
void linkedlist::insertend(int x,int y)
{
    if(start==NULL)
    {
        node *temp;
        temp=new node;
        temp->row=x;
        temp->col=y;
        temp->link=NULL;
        start=temp;
    }
    else
    {
        node *temp1;
        temp1=start;
        while(temp1->link!=NULL)
        {
            temp1=temp1->link;
        }
        node *temp;
        temp=new node;
        temp->row=x;
        temp->col=y;
        temp->link=NULL;
        temp1->link=temp;
    }
}


void linkedlist::display(char arr[rm][cm])
 {int i,j;
      for(i=0;i<rm;i++)
    {
        for(j=0;j<cm;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
 }

bool linkedlist::checkright(int i,int j,char a[rm][cm],char newa[rm][cm])
{
    if(check(i,j)&&a[i][j]!='|' && newa[i][j]!='*'&&newa[i][j]!='$')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
bool linkedlist::checkleft(int i,int j,char a[rm][cm],char newa[rm][cm])
{
    if(check(i,j)&&a[i][j]!='|' && newa[i][j]!='*'&&newa[i][j]!='$')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
bool linkedlist::checkup(int i,int j,char a[rm][cm],char newa[rm][cm])
{
    if(check(i,j)&&a[i][j]!='|' && newa[i][j]!='*'&&newa[i][j]!='$')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
bool linkedlist::checkdown(int i,int j,char a[rm][cm],char newa[rm][cm])
{

    if(check(i,j)&&a[i][j]!='|' && newa[i][j]!='*'&&newa[i][j]!='$')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
bool linkedlist::check(int i ,int j)
{
    if(i>=1&&i<rm-1&&j>=1&&j<cm-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void linkedlist::deletebeg()
{

 node *temp=start;
start=start->link;
 delete (temp);

}
void  linkedlist::maze(char a[rm][cm],char newa[rm][cm],int sr,int sc,int dr,int dc)
{
  char ch;
int flag=0,i=sr,j=sc;
insertend(sr,sc);
node *ptr=start;
newa[ptr->row][ptr->col]='*';
if(ptr->row==dr&&ptr->col==dc)
{
    cout<<"ACTUAL PATH"<<endl;
}
else
{
    while(start!=NULL)
    {
        i=start->row;
        j=start->col;
        newa[i][j]='*';
        if(i==dr&&j==dc)
        {
            flag=1;
            break;
        }
        deletebeg();
        if(checkright(i,j+1,a,newa))
        {
            newa[i][j+1]='$';
            insertend(i,j+1);
        }
        if(checkleft(i,j-1,a,newa))
        {
            newa[i][j-1]='$';
            insertend(i,j-1);
        }
         if(checkup(i-1,j,a,newa))
        {
            newa[i-1][j]='$';
            insertend(i-1,j);
        }
         if(checkdown(i+1,j,a,newa))
        {
            newa[i+1][j]='$';
            insertend(i+1,j);
        }

    }
}
    if(flag==1)
    {
        cout<<"found path"<<endl;
        for(i=0;i<rm;i++)
{
    for(j=0;j<cm;j++)
        {
       cout<<newa[i][j]<<" ";

        }
        cout<<endl;

}
    }

}
void linkedlist::gamestart(char newa[rm][cm],char sol[rm][cm],int sr,int sc,int dr,int dc)

{
    char option;
    int i,j;
    int points=0,f=0,f1,chance=3;
    newa[sr][sc]='*';
    int flag[rm][cm]={0};
    insert_stack(sr,sc);
    flag[sr][sc]=1;
    cout<<"game starts"<<endl;
    cout<<"enter the option a(left),s(down),d(right),w(up)";
    cin>>option;
    while(option!='q')

    {

        if(option=='w')
        {
            sr--;
              if(sr==dr&&sc==dc)
                {
                    sol[sr][sc]='*';
                    points=points+1;
                    f=1;
                }
                else if(flag[sr][sc]==1)
                    {
                           sr++;
                         cout<<"wrong way"<<endl;
                      }
                else if(newa[sr][sc]=='*' ||newa[sr][sc]=='$')
      {          sol[sr][sc]='*';
                 points=points+1;
                 insert_stack(sr,sc);
                 flag[sr][sc]=1;
      }

else if(newa[sr][sc]=='|' || newa[sr][sc]==' ' || newa[sr][sc]=='!' || newa[sr][sc]=='-')
      {
 chances(sol,flag);
 sr=start1->row;
 sc=start1->col;
 chance -=1;
 points=0;
if(chance==0){f1=1;}
      }
            }


            else if(option=='a')
        {

            sc--;
              if(sr==dr&&sc==dc)
                {
                    sol[sr][sc]='*';
                    points=points+1;
                    f=1;
                }
                else if(flag[sr][sc]==1)
                    {
                           sc++;
                         cout<<"wrong way"<<endl;
                      }
                else if(newa[sr][sc]=='*' ||newa[sr][sc]=='$')
      {          sol[sr][sc]='*';
                 points=points+1;
                 insert_stack(sr,sc);
                 flag[sr][sc]=1;
      }

else if(newa[sr][sc]=='|' || newa[sr][sc]==' ' || newa[sr][sc]=='!' || newa[sr][sc]=='-')
      {
 chances(sol,flag);
 sr=start1->row;
 sc=start1->col;
 chance -=1;
 points=0;
if(chance==0){f1=1;}
      }
}
      else if(option=='s')
        {

            sr++;
                          if(sr==dr&&sc==dc)
                {
                    sol[sr][sc]='*';
                    points=points+1;
                    f=1;
                }
                else if(flag[sr][sc]==1)
                    {
                           sr--;
                         cout<<"wrong way"<<endl;
                      }
                else if(newa[sr][sc]=='*' ||newa[sr][sc]=='$')
      {          sol[sr][sc]='*';
                 points=points+1;
                 insert_stack(sr,sc);
                 flag[sr][sc]=1;
      }

else if(newa[sr][sc]=='|' || newa[sr][sc]==' ' || newa[sr][sc]=='!' || newa[sr][sc]=='-')
      {
 chances(sol,flag);
 sr=start1->row;
 sc=start1->col;
 chance -=1;
 points=0;
if(chance==0){f1=1;}
      }

        }
       else if(option=='d')
        {

           sc++;
                         if(sr==dr&&sc==dc)
                {
                    sol[sr][sc]='*';
                    points=points+1;
                    f=1;
                }
                else if(flag[sr][sc]==1)
                    {
                           sc--;
                         cout<<"wrong way"<<endl;
                      }
                else if(newa[sr][sc]=='*' ||newa[sr][sc]=='$')
      {          sol[sr][sc]='*';
                 points=points+1;
                 insert_stack(sr,sc);
                 flag[sr][sc]=1;
      }

else if(newa[sr][sc]=='|' || newa[sr][sc]==' ' || newa[sr][sc]=='!' || newa[sr][sc]=='-')
      {
 chances(sol,flag);
 sr=start1->row;
 sc=start1->col;
 chance -=1;
 points=0;
if(chance==0){f1=1;}
      }




    }
   system("CLS");
 if(f==1)
    {display(sol);cout<<"points :"<<points<<endl<<"!! CONGRATULATIONS YOU WON ";break;}
    else if(f1==1){cout<<"POINTS-->"<<points<<endl<<"## GAME OVER ##"<<endl;break;}
    else {cout<<"POINTS-->"<<points<<endl<<"LIVES-->"<<chance<<endl;display(sol);}
    cout<<endl;
     cout<<"enter the option a(left),s(down),d(right),w(up)";
    cin>>option;

    }

}

int main()
{
linkedlist l;
cout<<"source is at 1,1 coordinate and destination is at 6,6 coordinate"<<endl;
int i,j;
char a[rm][cm],newa[rm][cm],sol[rm][cm];
a[0][0]=' -';a[0][1]='-';a[0][2]='-';a[0][3]='-';a[0][4]='-';a[0][5]='-';a[0][6]='-';a[0][7]='-';
a[1][0]='!';a[1][1]=' ';a[1][2]='|';a[1][3]='|';a[1][4]=' ';a[1][5]='|';a[1][6]=' ';a[1][7]='!';
a[2][0]='!';a[2][1]=' ';a[2][2]='|';a[2][3]=' ';a[2][4]=' ';a[2][5]=' ';a[2][6]=' ';a[2][7]='!';
a[3][0]='!';a[3][1]=' ';a[3][2]='|';a[3][3]=' ';a[3][4]='|';a[3][5]='|';a[3][6]=' ';a[3][7]='!';
a[4][0]='!';a[4][1]=' ';a[4][2]=' ';a[4][3]=' ';a[4][4]=' ';a[4][5]=' ';a[4][6]=' ';a[4][7]='!';
a[5][0]='!';a[5][1]='|';a[5][2]=' ';a[5][3]='|';a[5][4]='|';a[5][5]=' ';a[5][6]=' ';a[5][7]='!';
a[6][0]='!';a[6][1]=' ';a[6][2]=' ';a[6][3]='|';a[6][4]=' ';a[6][5]=' ';a[6][6]='@';a[6][7]='!';
a[7][0]='-';a[7][1]='-';a[7][2]='-';a[7][3]='-';a[7][4]='-';a[7][5]='-';a[7][6]='-';a[7][7]='-';
 for(i=0;i<rm;i++)
    {
        for(j=0;j<cm;j++)
        {
            newa[i][j]=a[i][j];
            sol[i][j]=a[i][j];
        }
    }
l.display(a);
l.maze(a,newa,1,1,6,6);
 l.gamestart(newa,sol,1,1,6,6);
}
