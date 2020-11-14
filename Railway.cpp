#include <string>
#include<cstdio>
#include <iostream>
#include <time.h>
#include <unistd.h>
#include <ctime>
using namespace std;
long int reg_no=202000,timepass;
struct node{
 string name;
 string notice;
 long int aadhaar_no;
 long int phone_no;
 int age;
 string gender;
 int seat_no;
 int coach_no;
 int reg_no;
 string status;
 struct node *link;
};
void ins_tic(struct node **front,struct node **rear,string fname,int age,long int ad_no,long int ph_no,int seat_no,int co_no,int reg_no,string gender,string status)
{
   struct node *temp;
   temp=(struct node *)malloc(sizeof(struct node));
   temp->name=fname;
   temp->age=age;
   temp->aadhaar_no=ad_no;
   temp->phone_no=ph_no;
   temp->seat_no=seat_no;
   temp->coach_no=co_no;
   temp->reg_no=reg_no;
   temp->gender=gender;
   temp->status=status;
   temp->notice=" ";
   if(*front == NULL && *rear == NULL)
   {
       *rear = temp;
       *front = *rear;
   }
   else
   {
       (*rear)->link = temp;
       *rear = temp;
        (*rear)->link = NULL;
      
   }
  
}
void display_list(struct node **front,struct node **wfront)
{
   system("clear");
   struct node *temp,*temp1;
   temp = *front;
   temp1 = *wfront;
   cout<<"\n\n-----------------------------------------------------------------------------\n";
   cout<<"\t\t\t\tRESERVED TICKETS\n";
   cout<<"-----------------------------------------------------------------------------\n";
   cout<<"\t  NAME\t\t\tAGE\t\tGENDER\t\tPHONE NO.\t\t\tREG_NO\t\tSTATUS\n";
   cout<<"-----------------------------------------------------------------------------\n";
   while(temp != NULL)
   {
       cout<<"\t"<<temp->name;
       cout<<"\t\t"<<temp->age;
       cout<<"\t\t"<<temp->gender;
       cout<<"\t\t"<<temp->phone_no;
       cout<<"\t\t\t"<<temp->reg_no;
       cout<<"\t\t"<<temp->status;
       cout<<endl;
       temp = temp->link;
   }
   cout<<"\n\n-----------------------------------------------------------------------------\n";
   cout<<"\t\t\t\tWAITING LIST\n";
   cout<<"-----------------------------------------------------------------------------\n";
   cout<<"\t  NAME\t\tAGE\t\tGENDER\t\tPHONE NO.\t\tREG_NO\t\tSTATUS\n";
   cout<<"-----------------------------------------------------------------------------\n";
   while(temp1 != NULL)
   {
       cout<<"\t"<<temp1->name;
       cout<<"\t\t"<<temp1->age;
       cout<<"\t\t"<<temp1->gender;
       cout<<"\t\t"<<temp1->phone_no;
       cout<<"\t\t\t"<<temp1->reg_no;
       cout<<"\t\t"<<temp1->status;
       cout<<endl;
       temp1 = temp1->link;
   }
   cout<<"\n\t\tPLEASE ENTER ANY NUMBER TO CONTINUE : ";
   cin>>timepass;
   system("clear");
}
 
 
void Cancel_Ticket(struct node** front,struct node** rear,int reg_num,struct node** wfront,struct node** wrear)
{
   struct node *temp = NULL;
   temp = *front;
   while(temp != *rear)
   {
       if(temp->reg_no == reg_num)
       {
           break;
       }
       temp = temp->link;
   }
 
   temp->status="CANCELLED";
    cout<<"\t\tNAME : "<<temp->name<<"\t\t"<<"CONTACT : "<<temp->phone_no<<endl;
    cout<<"\n\t\t---------------------------------------------------------------\n";
    cout<<"\t\tYOUR TICKET HAS BEEN CANCELLED"<<endl;
    cout<<"\n\t\t---------------------------------------------------------------\n";
    cout<<"\t\tPLEASE ENTER ANY NUMBER TO CONTINUE : ";
    cin>>timepass;
   (*rear)->link=(*wfront);
   (*rear)=(*wfront);
   (*wfront)=(*wfront)->link;
    (*rear)->link=NULL;
   (*rear)->coach_no=temp->coach_no;
   (*rear)->seat_no=temp->seat_no;
   (*rear)->status="CONFIRMED";
 
 
}
 
void notice(struct node** front,struct node** rear,string note1,struct node** wfront,struct node** wrear){
 struct node *temp = NULL;
   temp = *front;
   while(temp != NULL)
   {   temp->status="CANCELLED";
       temp->notice=note1;
    
       temp = temp->link;
   }
 if(*wfront==NULL){
   temp = *wfront;
   while(temp != NULL)
   {   temp->status="CANCELLED";
       temp->notice=note1;
    
       temp = temp->link;
   }
 }
 
}
void display_ticket(struct node** front,struct node** rear,struct node** wfront,struct node** wrear,int reg_no)
{
  int t,id=0;
    struct node *temp = NULL,*temp1 = NULL;
    temp = *front;
    temp1 = *wfront;
    while(temp != NULL)
    {
        if(temp->reg_no == reg_no)
        {
          id = 1;
            break;
        }
        temp = temp->link;
    }
    if(id == 0)
    {
      while(temp1 != NULL)
      {
        if(temp1->reg_no == reg_no)
        {
          id = 2;
          break; 
        } 
        temp1 = temp1->link;
      }
    }
    if(id == 0)
    {
      cout<<"\n\t\tREGISTRATION NUMBER NOT FOUND !"<<endl;
      cout<<"\n\t\t--------------------------------------------------------\n";
      cout<<"\t\tPLEASE ENTER ANY NUMBER TO CONTINUE : ";
      cin>>timepass;
    }
    else if(id == 1)
    {
      id = 0;
      cout<<"---------------------------------------------------------------------------------"<<endl;
      if(temp->notice != " ")
      {
        cout<<"!!!\t\tNOTICE : "<<temp->notice<<"\t\t!!!"<<endl<<endl;
      }
      cout<<"NAME : "<<temp->name<<"\t\t\t"<<"CONTACT : "<<temp->phone_no<<endl<<endl;
      cout<<"AGE : "<<temp->age<<"\t\t"<<"REG_NO : "<<temp->reg_no<<"\t\t"<<"GENDER : "<<temp->gender<<endl<<endl;
      cout<<"AADHAAR_NO : "<<temp->aadhaar_no<<endl<<endl;
      cout<<"SEAT NUMBER : "<<temp->seat_no<<"\t\t"<<"COACH_NO : "<<temp->coach_no<<endl<<endl;
      cout<<"CURRENT STATUS : "<<temp->status<<endl;
      cout<<"---------------------------------------------------------------------------------"<<endl;
      cout<<"\n\n\nENTER ANY NUMBER TO CONTINUE : ";
      cin>>t;
    }
    else if(id == 2)
    {
      id = 0;
      cout<<"---------------------------------------------------------------------------------"<<endl;
       cout<<" "<<temp1->notice<<endl;
      cout<<"NAME : "<<temp1->name<<"\t\t\t"<<"CONTACT : "<<temp1->phone_no<<endl<<endl;
      cout<<"AGE : "<<temp1->age<<"\t\t"<<"REG_NO : "<<temp1->reg_no<<"\t\t"<<"GENDER : "<<temp1->gender<<endl<<endl;
    // cout<<"Booking Date : "<<temp->time<<"\t\t"<<endl<<endl;
      cout<<"AADHAAR_NO : "<<temp1->aadhaar_no<<endl<<endl;
      cout<<"SEAT_NUMBER : NA\t\tCOACH_NO : NA"<<temp1->coach_no<<endl<<endl;
      cout<<"CURRENT STATUS : "<<temp1->status<<endl;
      cout<<"---------------------------------------------------------------------------------"<<endl;
      cout<<"\n\n\nENTER ANY NUMBER TO CONTINUE : ";
      cin>>t;
    }
}
int main()
{
   int ch=-1,data,Admin_count=0,choice_admin=-1,choice_user=-1;
   string pass = "",password = "1234",gender,note;
   struct node *front = NULL;
   struct node *rear = NULL;
   struct node *wfront=NULL;
   struct node *wrear=NULL;
   string fname,lname;
   long int ad_no,ph_no,gen;
   int age,co_no=1,seat_no=0,max_num_nor=0,max_num_citizen=0;
  
   system("clear");
   cout<<"\n\n\n\n\n\n\n\t\t-----------------------------------------------------\n\t\t|||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
   cout<<"\t\t-----------------------------------------------------\n\n";
   cout<<"\t\t\t\t** RAILWAY RESERVATION SYSTEM **\n\n";
   cout<<"\t\t-----------------------------------------------------\n\t\t|||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
   cout<<"\t\t-----------------------------------------------------\n\n";
   getchar();
   while(ch!=5)
   {
       entry:system("clear");
       cout<<"\n\n\n\n\n\n\t\t---------------------------------------------------\n";
       cout<<"\t\t< = = = = = : FACILITIES AVAILABLE : = = = = = =  > ";
       cout<<"\n\t\t---------------------------------------------------\n";
       cout<<"\t\t\t\t1. ADMIN LOGIN.\n\t\t\t\t2. BOOK A TICKET.\n\t\t\t\t3. VIEW TICKET STATUS.\n\t\t\t\t4. CANCEL A TICKET.\n\t\t\t\t5. EXIT\n";
       cout<<"\t\t---------------------------------------------------\n";
       cout<<"\t\t\tPLEASE ENTER A NUMBER : ";
       cin>>ch;
       switch(ch)
       {
       case 1:
           system("clear");
           while(Admin_count <= 2)
           {
               cout<<"\n\n\n\n\t\t-----------------------------------------------\n";
               cout<<"\t\t\t\t||||||||||||||**|||||||||||||||\n";
               cout<<"\t\t-----------------------------------------------\n\n";
               cout<<"\t\t\tPLEASE ENTER PASSWORD : ";
               cin>>pass;
               cout<<"\n\t\t-----------------------------------------------\n";
               cout<<"\t\t\t\t||||||||||||||**|||||||||||||||\n";
               cout<<"\t\t-----------------------------------------------\n";
               if(pass == password)
               {
                   cout<<"\n\t\t\t\t*ADMIN ACCESS GRANTED!\n"<<endl;
                   cout<<"\t\t-----------------------------------------------\n";
                   cout<<"\t\t-----------------------------------------------\n";
                   cout<<"\t\tPLEASE ENTER ANY NUMBER TO CONTINUE : ";
                   cin>>timepass;
                   system("clear");
                   choice_admin=0;
                   while(choice_admin!=4)
                   {
                       cout<<"\n\n\n\n\n\t\t-------------------------------------------------\n";
                       cout<<"\t\t|||||||||||||||||||||||||||||||||||||||||||||||||\n";
                       cout<<"\t\t-------------------------------------------------\n";
                       cout<<"\t\t\t\tOPTIONS AVAILABLE\n";
                       cout<<"\t\t-------------------------------------------------\n";
                       cout<<"\t\t\t1. DISPLAY ALL BOOKINGS."<<endl;
                       cout<<"\t\t\t2. CREATE A NOTICE."<<endl;
                       cout<<"\t\t\t3. MAIN MENU"<<endl;
                       cout<<"\t\t-------------------------------------------------\n";
                       cout<<"\t\t\tENTER YOUR CHOICE : ";
                       cin>>choice_admin;
                       switch(choice_admin)
                       {
                       case 1:
                           display_list(&front,&wfront);
                           break;
                       case 2:
                           cout<<"\t\t\tEnter the notice to be displayed as a reason of cancellation : ";
                           cin>>note;
                           notice(&front, &rear,note,&wfront, &wrear);
                           break;
                       case 3:
                           goto entry;
                           break;
                       default:
                           break;
                       }
                   }
               }
               else
               {
                   cout<<"\n\t\t\t    * ACCESS DENIED *\n"<<endl;
                   cout<<"\t\t-----------------------------------------------\n";
                   cout<<"\t\t-----------------------------------------------\n";
                   cout<<"\t\tPLEASE ENTER ANY NUMBER TO CONTINUE : ";
                   cin>>timepass;
                   //Sleep(2000);
                   system("clear");
                   Admin_count++;
                   goto entry;
               }
           }
           if(Admin_count == 3)
           {
               Admin_count=0;
               goto entry;
           }
           break;
       case 2:
           system("clear");
           cout<<"\n\n\n\n\n\t\t-------------------------------------------------------\n";
           cout<<"\t\t*******************************************************\n";
           cout<<"\t\t-------------------------------------------------------\n";
           cout<<"\t\t\t\t\t : ENTER DETAILS : \n";
           cout<<"\t\t-------------------------------------------------------\n";
           cout<<"\t\t\t NAME (FIRST_LAST) : ";
           cin>>fname;
           //cout<<"\n\t\t\tLAST NAME : ";
           //cin>>lname;
           cout<<"\n\t\t\tGENDER : 1. MALE\n\t\t\t\t\t 2. FEMALE\n\t\t\t\t\t 3. OTHER\n\t\t\tENTER A NUMBER : ";
           cin>>gen;
           if(gen==1)
               gender="MALE";
           else if(gen==2)
               gender="FEMALE";
           else
               gender="OTHERS";
           cout<<"\n\t\t\tAGE : ";
           cin>>age;
           if(age>=60)
           {
               max_num_citizen++;
           }
           else
           {
               max_num_nor++;
           }
           cout<<"\n\t\t\tADHAAR NUMBER : ";
           cin>>ad_no;
           cout<<"\n\t\t\tPHONE NUMBER : ";
           cin>>ph_no;
          //  cout<<"\n\t\t\tDATE AND TIME : "<<dt<<endl;
           reg_no++;
           if(seat_no<=2 && co_no<=2)
           {
               if(max_num_citizen<=2 && max_num_nor<=2)
               {
                   seat_no++;
                   ins_tic(&front,&rear,fname,age,ad_no,ph_no,seat_no,co_no,reg_no,gender,"CONFIRMED");
                   cout<<"\n\t\t-------------------------------------------------------\n";
                   cout<<"\t\t\t\t\tTICKET CONFIRMED!!!!!!";
               }
               else if(max_num_nor>2)
               {
                   if(age<60)
                   {
                       ins_tic(&wfront,&wrear,fname,age,ad_no,ph_no,seat_no,co_no,reg_no,gender,"WAITING");
                       cout<<"\n\t\t-------------------------------------------------------\n";
                       cout<<"\t\t\t\t\tTICKET NOT CONFIRMED!!!!!!";
                   }
                   else
                   {
                       seat_no++;
                       ins_tic(&front,&rear,fname,age,ad_no,ph_no,seat_no,co_no,reg_no,gender,"CONFIRMED");
                       cout<<"\n\t\t-------------------------------------------------------\n";
                       cout<<"\t\t\t\t\tTICKET CONFIRMED!!!!!!";
                   }
               }
           }
           else
           {
               cout<<"\n\t\t-------------------------------------------------------\n";
               cout<<"\t\t\t\t\tTICKET NOT CONFIRMED!!!!!!";
               ins_tic(&wfront,&wrear,fname,age,ad_no,ph_no,seat_no,co_no,reg_no,gender,"WAITING");
           }
           if(seat_no==2)
           {
               seat_no=0;
               co_no++;
           }
           cout<<"\n\t\t-------------------------------------------------------\n";
           cout<<"\t\t\t\tNOTE YOUR TICKET NUMBER : "<<reg_no;
           cout<<"\n\t\t-------------------------------------------------------\n";
           cout<<"\n\t\t\t*----DETAILS TAKEN SUCCESSFULLY----*";
           cout<<"\n\t\t-------------------------------------------------------\n";
           cout<<"\t\t*******************************************************\n";
           cout<<"\t\t-------------------------------------------------------\n";
         cout<<"\t\tPLEASE ENTER ANY NUMBER TO CONTINUE : ";
         int oneone;
         cin>>oneone;
           getchar();
           break;
       case 3:
          system("clear");
          cout<<"\n\n\n\t\t---------------------------------------------------------------";
          cout<<"\n\t\t***************************************************************";
          cout<<"\n\t\t---------------------------------------------------------------";
          cout<<"\n\t\tENTER REGISTRATION NUMBER OF YOUR TICKET : ";
          cin>>reg_no;
          cout<<"\n\t\t---------------------------------------------------------------\n";
          display_ticket(&front,&rear,&wfront,&wrear,reg_no);
          break;
       case 4:
        system("clear");
        cout<<"\n\n\n\t\t---------------------------------------------------------------";
        cout<<"\n\t\t***************************************************************";
        cout<<"\n\t\t---------------------------------------------------------------";
        cout<<"\n\t\tPLEASE ENTER YOUR REGISTRATION NUMBER : ";
        int tic_num;
        cin>>tic_num;
        cout<<"\n\t\t---------------------------------------------------------------\n";
        Cancel_Ticket(&front,&rear, tic_num, &wfront,&wrear);
        break;
      case 5:
        cout<<"\n\t\tTHANK YOU FOR REGISTERING USING OUR PORTAL"<<endl;
        break;
       default:
           system("clear");
           cout<<"\n\n\n\n\n\n\t\t-----------------------------------\n";
           cout<<"\t\t|\t|||||||||||**||||||||||||\t |\n";
           cout<<"\n\t\t (: PLEASE ENTER A VALID NUMBER :)\n\n";
           cout<<"\t\t|\t|||||||||**||||||||||||||||\t |\n";
           cout<<"\t\t-----------------------------------\n";
           cout<<"\t\tENTER ANY NUMBER TO CONTIUE : ";
           cin>>timepass;
           goto entry;
           break;
       }
   }
   if(ch != 5)
   {
     goto entry;
   }
}
