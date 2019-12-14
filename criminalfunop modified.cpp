#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
int c=0;//login flag
int cc=0;//class 1
int ccc=0;//class 2
int scount=0;
int scount2=0;
int tcount1=0;
int tcount2=0;
int kk;
class criminal
{
public:
char name[50],type_of_cell[50],warden_name[50],type_crime[50];
int id,age,aid,apwd,j;
char oname[50],otype_of_cell[50],owarden_name[50],otype_crime[50];
int oid,oage;
};
class Incriminal :public criminal
{
public :
Incriminal()//default constructor
{
    aid=5905;
    apwd=8015;
}
Incriminal(int no,char n[],int a,char wn[],char cell[],char crime[])//parameterized constructor
{
    id=no;
    strcpy(name,n);
    age=a;
    strcpy(warden_name,wn);
    strcpy(type_of_cell,cell);
    strcpy(type_crime,crime);
}
public:
int validate()
{
cout<<"\nLogIn:\n";
cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
cout<<"\n\tAdmin ID : ";
cin>>aid;
cout<<"\n\tPassword : ";
cin>>apwd;
if(aid==5905 && apwd==8015)
{
    c=1;
cout<<"\n$$$$$$$$$$$$$$$$$$$ *Login Successfully* $$$$$$$$$$$$$$$$$$$$$$\n";

}
else
{
cout<<"\n\nIncorrect username or password !!!\n";
c--;
return validate();
}
}
void virtual details()
{
    cout<<"\n";
    cout<<id<<"\t"<<name<<"\t"<<age<<"\t"<<warden_name<<"\t\t"<<type_of_cell<<"\t\t\t"<<type_crime;
}
void virtual search_c(int k,Incriminal r[])
{
cout<<"\n\n-------------------------------------------------------------------------------------\n\n";
   cout<<"ID\tNAME\tAGE\tWARDEN_NAME\tTYPES_OF_CELL\t\tTYPE_OF_CRIME\n\n";
    cout<<"-------------------------------------------------------------------------------------\n\n";
 for(int i=0;i<scount;i++)
{
   if(r[i].id==k)
   {
       cout<<r[i].id<<"\t"<<r[i].name<<"\t"<<r[i].age<<"\t"<<r[i].warden_name<<"\t\t"<<r[i].type_of_cell<<"\t\t"<<r[i].type_crime;

   }
   if(i==scount)
   {
   cout<<"Data not found";
   }

}
}
void virtual search_c(char k[],Incriminal r[])
{
    int i;
    cout<<"-------------------------------------------------------------------------------------\n\n";
 cout<<"ID\tNAME\tAGE\tWARDEN_NAME\tTYPES_OF_CELL\t\tTYPE_OF_CRIME\n\n";
    cout<<"-------------------------------------------------------------------------------------\n\n";
 for( i=0;i<scount;i++)
{
   if(strcmp(r[i].type_crime,k)==0)
   {
       cout<<r[i].id<<"\t"<<r[i].name<<"\t"<<r[i].age<<"\t"<<r[i].warden_name<<"\t\t"<<r[i].type_of_cell<<"\t\t"<<r[i].type_crime;
        tcount1++;
   }

 if(i==scount)
   {
   cout<<"Data not found";
   }

}
}
 Incriminal operator=(Incriminal k[])
      {
         id = this->id;
         strcpy(name,this->name);
      }
};
class outCriminal :public Incriminal//inherit from
{
public:

outCriminal()
{
}

outCriminal(int no,char n[],int a,char wn[],char cell[],char crime[])//parameterized constructor
{
    oid=no;
    strcpy(oname,n);
    oage=a;
    strcpy(owarden_name,wn);
    strcpy(otype_of_cell,cell);
    strcpy(otype_crime,crime);
}
void details()
{
    cout<<"\n";
    cout<<oid<<"\t"<<oname<<"\t"<<oage<<"\t"<<owarden_name<<"\t\t"<<otype_of_cell<<"\t\t\t"<<otype_crime;
}
void search_c(int k,outCriminal out[])
{
cout<<"\n\n-------------------------------------------------------------------------------------\n\n";
   cout<<"ID\tNAME\tAGE\tWARDEN_NAME\tTYPES_OF_CELL\t\tTYPE_OF_CRIME\n\n";
    cout<<"-------------------------------------------------------------------------------------\n\n";
 for(int i=0;i<scount2;i++)
{
   if(out[i].oid==k)
   {
       cout<<out[i].oid<<"\t"<<out[i].oname<<"\t"<<out[i].oage<<"\t"<<out[i].owarden_name<<"\t\t"<<out[i].otype_of_cell<<"\t\t"<<out[i].otype_crime;

   }
 if(i==scount2)
   {
   cout<<"Data not found";
   }
}
}
void search_c(char k[],outCriminal out[])
{
    int i;
    cout<<"-------------------------------------------------------------------------------------\n\n";
 cout<<"ID\tNAME\tAGE\tWARDEN_NAME\tTYPES_OF_CELL\t\tTYPE_OF_CRIME\n\n";
    cout<<"-------------------------------------------------------------------------------------\n\n";
 for( i=0;i<scount2;i++)
{
   if(strcmp(out[i].otype_crime,k)==0)
   {
       cout<<out[i].oid<<"\t"<<out[i].oname<<"\t"<<out[i].oage<<"\t"<<out[i].owarden_name<<"\t\t"<<out[i].otype_of_cell<<"\t\t"<<out[i].otype_crime;

   }
 if(i==scount2)
   {
   cout<<"Data not found";
   }
}
}

outCriminal operator=(outCriminal k[])//operator overloading 2
      {
         oid = this->oid;
         strcpy(oname,this->oname);
      }
      void      friend addDetail(Incriminal r[],outCriminal out[]);
};

void addDetail(Incriminal r[],outCriminal out[])
{
int i;
char kk[10];
cout<<"\nEnter the type of crime:\t:";
cin>>kk;
cout<<"ID\tNAME\tAGE\tWARDEN_NAME\tTYPES_OF_CELL\t\tTYPE_OF_CRIME\n\n";
    cout<<"-------------------------------------------------------------------------------------\n\n";

 for( i=0;i<scount;i++)
{
   if(strcmp(r[i].type_crime,kk)==0)
   {
       cout<<r[i].id<<"\t"<<r[i].name<<"\t"<<r[i].age<<"\t"<<r[i].warden_name<<"\t\t"<<r[i].type_of_cell<<"\t\t"<<r[i].type_crime;
               tcount1++;
   }
cout<<"\n";
}
 for( i=0;i<scount2;i++)
{
   if(strcmp(out[i].otype_crime,kk)==0)
   {
       cout<<out[i].oid<<"\t"<<out[i].oname<<"\t"<<out[i].oage<<"\t"<<out[i].owarden_name<<"\t\t"<<out[i].otype_of_cell<<"\t\t"<<out[i].otype_crime;
               tcount2++;
   }
cout<<"\n";
}



int result=tcount1+tcount2;
if(result>0)
{
cout<<"\n**************The total count is ------->:\t"<<result;
tcount1=0;
tcount2=0;
}
else
cout<<"\nDatabase not found\n";
}

class ageexception
{
public:
int ag;
ageexception()
{
}
ageexception(int a)
{
ag=a;
}
};
int main()
{
Incriminal a;
Incriminal r[50],*p;
outCriminal out[50];
ofstream output1("incriminal",ios::app);
ofstream output2("outcriminal",ios::app);
int num,ae;
int f=0,ff=0;
int i,opt2;
p=&out[0];
char wne[20],typec[20],typet[50],cnam[20];
a.validate();
if(c==1)
{
char opt;
cout<<"\n\t\t\t\t\t\t\t\t$$$ WELCOME $$$\n\n";

do//main do
{
cout<<"\n\n1.ON jail criminal operation\t\t2.OFF jail criminal operation\t\t3.Exit\n\n";
cout<<"Your option:\t\t:";
cin>>opt2;
ofstream output1("incriminal",ios::app);
ofstream output2("outcriminal",ios::app);
switch(opt2)//main switch
{
case 1://our jail
do
{
ofstream output1("criminal",ios::app);
cout<<"\n\n***1.Add criminal details***\n";
cout<<"\n***2.Crimals records***\n";
cout<<"\n***3.Work details***\n";
cout<<"\n***4.Search a particular criminal id\n";
cout<<"\n***5.Search a Theft criminals\n";
cout<<"\n***6.Find how many particular crimes are in our data storage\n";
cout<<"\n***7.Copy the particular criminal details\n";
cout<<"\n***Q.Quit***\n";
cout<<"\nYour Choice Enter :::\t";
cin>>opt;
switch(opt)//second switch
{
case '1':
    int o;
    cout<<"\nHow many criminal to be add ?\t:";
    cin>>o;
scount=scount+o;
   for(i=cc;i<scount;i++)
{
cc++;
if(!output1)
{
cout<<"cannot open file"<<endl;
}


    cout<<"\n\n";
    cout<<"\tCriminal Details\t:"<<++f<<"\n";
     cout<<"\n-------------------------------------------\n\n";
    output1<<"\nCriminal Details: "<<f<<endl;
       output1<<"\n---------------------------------------"<<endl;
    cout<<"\nCriminal id\t:";
    cin>>num;
    output1<<"\nCriminal id: "<<num<<endl;
    cout<<"\nCriminal name\t:";
    cin>>cnam;
    output1<<"\nCriminal name: "<<cnam<<endl;
    try
    {
    cout<<"\nAge of criminal\t:";
    cin>>ae;
    if(ae<16)
    throw ageexception();
    }
        catch(ageexception ob)
        {
        cout<<"\n"<<ae<<"  is invalid age because this minor criminal\n";
        i--;
        f--;
        continue;
        }
output1<<"\nAge: "<<ae<<endl;
    cout<<"\nType of crime\t:";
    cin>>typet;
    output1<<"\nType of crime: "<<typet<<endl;
    cout<<"\nWarden name to be watching\t:";
    cin>>wne;
    output1<<"\nWarden name for watch: "<<wne<<endl;
    cout<<"\nType of cell to assign\t:";
    cin>>typec;
    output1<<"\nCell type: "<<typec<<endl<<endl;
   r[i]=Incriminal(num,cnam,ae,wne,typec,typet);
    }
break;
case '2':
        cout<<"\n********************************************ON CRIMINAL DETAILS*****************************************\t\t\t\n";
        cout<<"-------------------------------------------------------------------------------------\n\n";
       cout<<"ID\tNAME\tAGE\tWARDEN_NAME\tTYPES_OF_CELL\t\tTYPE_OF_CRIME\n\n";
    cout<<"-------------------------------------------------------------------------------------\n\n";
for(i=0;i<scount;i++)
{

    r[i].details();
}
break;
case '3':

break;
case '4':
    int key;
    cout<<"Please give the criminal id:\t";
    cin>>key;
    r[0].search_c(key,r);
break;
case '5':
char k[10];
cout<<"Please give the type of crime\t:";
cin>>k;
r[0].search_c(k,r);
break;
case '6':
addDetail(r,out);
break;
case '7':
 int i;
 char kk[10];
 Incriminal c[10];
cout<<"Please give the type of crime\t:";
cin>>kk;
 cout<<"ID\tNAME\tTYPE_OF_CRIME\tTYPES_OF_CELL\t\n\n";
    cout<<"--------------------------------------------------------------------------\n\n";
 for( i=0;i<scount;i++)
{
   if(strcmp(r[i].type_crime,kk)==0)
   {
c[i]=r[i];
cout<<c[i].id<<"\t"<<c[i].name<<"\t"<<c[i].type_crime<<"\t\t"<<c[i].type_of_cell<<endl;

   }
else
cout<<"Data not found";
}
break;
}//local switch1
}
while(opt!='Q');
break;//main case 1
//complete injail criminals


/*--------------------------------------------------out jail-----------------------------------*/
case 2://Out jail
do
{
ofstream output2("outcriminal",ios::app);
cout<<"\n\n***1.Add Outcriminal details***\n";
cout<<"\n***2.OutCrimals records***\n";
cout<<"\n***3.Work details***\n";
cout<<"\n***4.Search a particular criminal id\n";
cout<<"\n***5.Search a Theft criminals\n";
cout<<"\n***6.Find how many particular crimes are in our data storage\n";
cout<<"\n***7.Copy the particular Outcriminal details\n";
cout<<"\n***Q.Quit***\n";
cout<<"\nYour Choice Enter :::\t";
cin>>opt;

switch(opt)
{
case '1':
    int o;
    cout<<"\nHow many Outcriminal to be add ?\t:";
    cin>>o;
scount2=scount2+o;
   for(i=ccc;i<scount2;i++)
{
ccc++;

if(!output2)
{
cout<<"cannot open file"<<endl;
}


    cout<<"\n\n";
    cout<<"\tOutCriminal Details\t:"<<++ff<<"\n";
     cout<<"\n-------------------------------------------\n\n";
        output2<<"\OutCriminal Details: "<<ff<<endl;
       output2<<"\n---------------------------------------"<<endl;
    cout<<"\nOutCriminal id\t:";
    cin>>num;
    output2<<"\nOutCriminal id: "<<num<<endl;
    cout<<"\nOutCriminal name\t:";
    cin>>cnam;
    output2<<"\nOutCriminal name: "<<cnam<<endl;
    try
    {
    cout<<"\nAge of Outcriminal\t:";
    cin>>ae;
    if(ae<16)
    throw ageexception();
    }
        catch(ageexception ob)
        {
        cout<<"\n"<<ae<<"  is invalid age because this minor criminal\n";
        i--;
        f--;
        continue;
        }
output1<<"\nAge: "<<ae<<endl;
    cout<<"\nType of crime\t:";
    cin>>typet;
    output2<<"\nType of crime: "<<typet<<endl;
    cout<<"\nWarden name to be watching\t:";
    cin>>wne;
    output2<<"\nWarden name for watch: "<<wne<<endl;
    cout<<"\nType of cell to assign\t:";
    cin>>typec;
    output2<<"\nCell type: "<<typec<<endl<<endl;
   out[i]=outCriminal(num,cnam,ae,wne,typec,typet);
    }
break;
case '2':
cout<<"\n********************************************OUT CRIMINAL DETAILS*****************************************\t\t\t\n";
cout<<"-------------------------------------------------------------------------------------\n\n";
       cout<<"\nID\tNAME\tAGE\tWARDEN_NAME\tTYPES_OF_CELL\t\tTYPE_OF_CRIME\n\n";
    cout<<"-------------------------------------------------------------------------------------\n\n";
for(i=0;i<scount2;i++)
{

    p->details();
}
break;
case '3':
break;
case '4':
    int key;
    cout<<"Please give the criminal id:\t";
    cin>>key;
    out[0].search_c(key,out);
break;
case '5':
char k[10];
cout<<"Please give the type of crime\t:";
cin>>k;
out[0].search_c(k,out);
break;
case '6':
addDetail(r,out);
break;
case '7':
 int i;
 char kk[10];
 outCriminal c2[10];
cout<<"Please give the type of crime\t:";
cin>>kk;
 cout<<"--------------------------------------------------------------------------\n\n";
 cout<<"ID\tNAME\tTYPE_OF_CRIME\tTYPES_OF_CELL\t\n\n";
    cout<<"--------------------------------------------------------------------------\n\n";
 for( i=0;i<scount2;i++)
{
   if(strcmp(out[i].otype_crime,kk)==0)
   {
c2[i]=out[i];
cout<<c2[i].oid<<"\t"<<c2[i].oname<<"\t"<<c2[i].otype_crime<<"\t\t"<<c2[i].otype_of_cell<<endl;

   }
else
cout<<"Data not found";
}
break;

break;//main case 2
}//local switch 2
}//local do
while(opt!='Q');
}//outer switch
}//main do

while(opt2!=3);//main do
}//main if
else
    cout<<"error occur";
    output1.close();
    output2.close();
}//main function
