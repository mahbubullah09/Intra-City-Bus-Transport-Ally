#include<iostream>
#include<stdlib.h>
#define MAX_LEN 100
#define INFINITY 9999
#define MAX 8

using namespace std;


int i;
int sTN;
int SIZE= 100;
struct account {
int TN;
string name;
long phn_no;
string route;
string addrass;
string date;
float payable;
float paid;
float returned;


} ;

   void add_info(struct account info[], int i){
       int k,sTN;
        cout<<"Enter Ticket No: "<<i<<endl;
        info[i].TN=i;

         fflush(stdin);
         cout<<"Enter Customer Name: ";
         getline(cin, info[i].name);
         cout<<"Enter Phone number: ";
         cin>>info[i].phn_no;
         fflush(stdin);
         cout<<"Enter Route: ";
         getline(cin,info[i].route);
         fflush(stdin);
         cout<<"Enter Payment Date: ";
         getline(cin,info[i].date);
         fflush(stdin);
         cout<<"Enter Payable: ";
         cin>>info[i].payable;
         cout<<"Total Paid: ";
         cin>>info[i].paid;
         info[i].returned=info[i].paid-info[i].payable;
         cout<<"Returned: "<<info[i].returned;


   }


  void display(struct account info[], int indx){

    if(i==0)cout<<endl<<"No  data found!"<<endl;

    for (i=1; i<indx; i++){

        cout<<" ---------------------------------------"<<endl;
        cout<<"|  Ticket No: "<<info[i].TN<<endl;
        cout<<"|  Customer Name: "<<info[i].name<<endl;
        cout<<"|  Phone number: "<<info[i].phn_no<<endl;
        cout<<"|  Route: "<<info[i].route<<endl;
        cout<<"|  Payment Date: "<<info[i].date<<endl;
        cout<<"|  Total Payable: "<<info[i].payable<<endl;
        cout<<"|  Total Paid: "<<info[i].paid<<endl;
        cout<<"|  Returned: "<<info[i].returned<<endl;
        cout<<" ---------------------------------------"<<endl;


}
}


int fnd_info (struct account info[], int indx){
int ch;


        int sTN;
        cout<<"Enter Ticket No: ";
        cin>>sTN;
       for (int i = 1; i < indx; i++) {
        if (info[i].TN == sTN){
        cout<<" ---------------------------------------"<<endl;
        cout<<"|  Ticket No: "<<info[i].TN<<endl;
        cout<<"|  Customer Name: "<<info[i].name<<endl;
        cout<<"|  Phone number: "<<info[i].phn_no<<endl;
        cout<<"|  Route: "<<info[i].route<<endl;
        cout<<"|  Payment Date: "<<info[i].date<<endl;
        cout<<"|  Total Payable: "<<info[i].payable<<endl;
        cout<<"|  Total Paid: "<<info[i].paid<<endl;
        cout<<"|  Returned: "<<info[i].returned<<endl;
        cout<<" ---------------------------------------"<<endl;
            }
      else if(info[i].TN!=sTN) cout<<"No  data found!"<<endl;

         }

    }









void TicketCounter(){

int index=1;



 int choice;
 cout<<endl;
 cout<<"1. Book Ticket"<<endl;
 cout<<"2. Find Ticket Information"<<endl;
 cout<<"3. Display All"<<endl;
 cout<<"4. Exit from Ticket Counter"<<endl;


    struct account info[SIZE];

do{

    cout<<"\nENTER YOUR CHOICE"<<endl;
    cin>>choice;
    switch(choice){
    case 1:
        add_info(info, index);
         index++;
          break;
   case 2:fnd_info(info, index);
    break;
    case 3:
        display(info, index);
       break;

   case 4: cout<<"Exit from Ticket Counter"<<endl<<endl;
    break;
    default: cout<<"Invalid choice"<<endl;

    }
 }while(choice!=4);

}




void dijkstra(int G[MAX][MAX],int n,int startnode) {
 int cost[MAX][MAX],distance[MAX],pred[MAX];
   int visited[MAX],Count,mindistance,nextnode,i,j;
   for(i=0;i<n;i++)
      for(j=0;j<n;j++)
   if(G[i][j]==0)
      cost[i][j]=INFINITY;
   else
      cost[i][j]=G[i][j];
   for(i=0;i<n;i++) {
      distance[i]=cost[startnode][i];
      pred[i]=startnode;
      visited[i]=0;
   }
   distance[startnode]=0;
   visited[startnode]=1;
   Count=1;
   while(Count<n-1) {
      mindistance=INFINITY;
      for(i=0;i<n;i++)
         if(distance[i]<mindistance&&!visited[i]) {
         mindistance=distance[i];
         nextnode=i;
      }
      visited[nextnode]=1;
      for(i=0;i<n;i++)
         if(!visited[i])
      if(mindistance+cost[nextnode][i]<distance[i]) {
         distance[i]=mindistance+cost[nextnode][i];
         pred[i]=nextnode;
      }
      Count++;
   }

   //print the path and distance of each node
char a[8][3];
    a[0][0]='R';
    a[0][1]='A';
    a[0][2]='N';

    a[1][0]='M';
    a[1][1]='Y';
    a[1][2]='M';

    a[2][0]='S';
    a[2][1]='Y';
    a[2][2]='L';

    a[3][0]='R';
    a[3][1]='A';
    a[3][2]='J';

    a[4][0]='D';
    a[4][1]='H';
    a[4][2]='K';

    a[5][0]='K';
    a[5][1]='H';
    a[5][2]='L';

    a[6][0]='B';
    a[6][1]='A';
    a[6][2]='R';

    a[7][0]='C';
    a[7][1]='T';
    a[7][2]='G';


   for(i=0;i<n;i++)
   if(i!=startnode) {
        int temp=i;
   //     int temp2=i;
        int k;
        cout<<endl;
        cout<<"Distance: "<<distance[temp]<<" KM"
        <<"   |   Ticket Price: "<< distance[temp] * 2.20 <<"   |   Route: ";
        //2.20 per KM rate

            for (k=0;k<3;k++)
                cout<<a[i][k];

            j=i;
            do
            {
                j=pred[j];
                cout<<"<-";
                for (k=0;k<3;k++)
                cout<<a[j][k];


            }
            while(j!=startnode);
}
}

void routevisual() {
   int G[MAX][MAX],i,j,n=8,u;


    G[0][0]=0;
    G[0][1]=292;
    G[0][2]=503;
    G[0][3]=211;
    G[0][4]=298;
    G[0][5]=INFINITY;
    G[0][6]=INFINITY;
    G[0][7]=INFINITY;
    G[1][0]=292;
    G[1][1]=0;
    G[1][2]=191;
    G[1][3]=239;
    G[1][4]=110;
    G[1][5]=INFINITY;
    G[1][6]=INFINITY;
    G[1][7]=INFINITY;

    G[2][0]=503;
    G[2][1]=191;
    G[2][2]=0;
    G[2][3]=INFINITY;
    G[2][4]=235;
    G[2][5]=INFINITY;
    G[2][6]=INFINITY;
    G[2][7]=358;
    G[3][0]=211;
    G[3][1]=239;
    G[3][2]=INFINITY;
    G[3][3]=0;
    G[3][4]=243;
    G[3][5]=266;
    G[3][6]=337;
    G[3][7]=INFINITY;

    G[4][0]=298;
    G[4][1]=110;
    G[4][2]=235;
    G[4][3]=243;
    G[4][4]=0;
    G[4][5]=221;
    G[4][6]=182;
    G[4][7]=248;
    G[5][0]=INFINITY;
    G[5][1]=INFINITY;
    G[5][2]=INFINITY;
    G[5][3]=266;
    G[5][4]=221;
    G[5][5]=0;
    G[5][6]=112;
    G[5][7]=INFINITY;
    G[6][0]=INFINITY;
    G[6][1]=INFINITY;
    G[6][2]=INFINITY;
    G[6][3]=337;
    G[6][4]=182;
    G[6][5]=112;
    G[6][6]=0;
    G[6][7]=238;
    G[7][0]=INFINITY;
    G[7][1]=358;
    G[7][2]=INFINITY;
    G[7][3]=INFINITY;
    G[7][4]=248;
    G[7][5]=INFINITY;
    G[7][6]=238;
    G[7][7]=0;
  //Rangpur->Mymensingh->Sylhet->Rajshahi->Dhaka->Khulna->Barisal->CTG
  cout<<" ---------------------------------------"<<endl;
    cout<<"|  0.Rangpur"<<endl;
    cout<<"|  1.Mymensingh"<<endl;
    cout<<"|  2.Sylhet"<<endl;
    cout<<"|  3.Rajshahi"<<endl;
    cout<<"|  4.Dhaka"<<endl;
    cout<<"|  5.Khulna"<<endl;
    cout<<"|  6.Barisal"<<endl;
    cout<<"|  7.Chittagong"<<endl;
    cout<<" ---------------------------------------"<<endl;
    cout<<"Enter Current Location: " ;
    cin>>u;
   dijkstra(G,n,u);

}

int main()
{

    system("Color 7D");
    int choice1;

    struct account info[SIZE];

do{
    cout<<endl;
    cout<<endl;
    cout<<"1. Route Visualization"<<endl;
    cout<<"2. Ticket Counter"<<endl;
    cout<<"3. Exit"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"ENTER YOUR CHOICE: ";
    cin>>choice1;
    switch(choice1){
    case 1: routevisual();
    break;
    case 2: TicketCounter();
    break;

    case 3: cout<<"Exit"<<endl;
    break;
    default: cout<<"Invalid choice"<<endl;
    }
 }while(choice1!=3);
}

