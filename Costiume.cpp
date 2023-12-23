#include <iostream>    	// for input/output operations
#include <iomanip>     	// for formatted input/output
#include <fstream>     	// for file input/output operations
#include <cstdlib>    	// for general purpose functions
#include <ctime>       	// for functions involving time
#include <cstring>	// for functions involving string
#include<stdlib.h>
#include <chrono>	// for functions involving date
#include <ctime>	// for functions involving date

using namespace std;

struct s
{
   	char ctname[20];
   	int qty;
   	float crate;
}sr;

struct c
{
  	int recno;
	char custoname[20];
	char cname[20];
	int nodays;
	float rate;
	int idd;
	int imm;
	int iyy;
	int rdd;
	int rmm;
	int ryy;
	int ardd;
	int armm;
	int aryy;
	char ret;
}cr;

void customer();
void addrecord();
void cstock();
void addrec();
int vwone(char*);
void viewrec();
int vwall();
void modifyrec();
void deleterec();
void checkstat();
void addrecord();
void getdate();
int gtrate(char*);
void duedt();
void delcos(char*);
void addcos(char*);
void viewrecord();
int viewone(int);
int viewall();
void modifyrecord();
void deleterecord();
void returns();
void generatebill();
void checkstatus();
void getretdate();

int main()
{
	system("cls");
	int m;
	do
    	{
		cout<<"******** MAIN MENU ********"<<endl;
		cout<<"   1.Costume Stock Menu"<<endl;
		cout<<"   2.Customer Menu"<<endl;
		cout<<"   3.Exit"<<endl;
		cout<<"Enter your choice :  ";
		cin>>m;
		switch(m)
	   	{
	     		case 1:
		  		cstock();
		   		break;
			case 2:
				customer();
		    		break;
	     		case 3:
		   	        exit(0);
	     		default:
		     		{
		         		cout<<"\n Wrong option !!!"<<"\n Press any key to continue ";
		         		main();
		     		}
	   	}
	}while(m<2);
  }
 
void cstock()
  {
	system("cls");
	int c;
	do
	{
		cout<<"******** STOCK MENU **********"<<endl;
		cout<<"#------MAINTENANCE-----#"<<endl;
		cout<<"   1.Add costume item"<<endl;
		cout<<"   2.View costume item"<<endl;
		cout<<"   3.Modify costume item"<<endl;
		cout<<"   4.Delete costume item"<<endl;
		cout<<"#------TRANSACTION-------#"<<endl;
		cout<<"   5.Check status"<<endl;
		cout<<"   6.Back to Main Menu"<<endl;
		cout<<"Enter your choice :  ";
		cin>>c;
		switch(c)
		{
			case 1:
				addrec();
				break;
			case 2:
				viewrec();
				break;
			case 3:
				modifyrec();
				break;
			case 4:
				deleterec();
				break;
			case 5:
				checkstat();
				break;
			case 6:
				main();
			default:
			{
				cout<<"\n Wrong option !!!"<<"\n Press any key to continue ";
				cstock();
			}
		    }
	   }while(c<5);
 }

void addrec()
{
	ofstream ofile;
   	ifstream ifile;

   	char op;

   	ofile.open("CSTOCK.DAT",ios::binary|ios::app);
   	ifile.open("CSTOCK.DAT",ios::binary);

   	do
	{       
	    system("cls");
      	cout<<" Enter Costume name :  ";
      	cin>>sr.ctname;
      	cout<<" Enter Quantity :  ";
      	cin>>sr.qty;
      	cout<<" Enter costume rate :  ";
      	cin>>sr.crate;
      	ofile.write((char*)&sr,sizeof(sr));
      	cout<<"\n Do you want to add another costume ? (y/n)  ";
      	cin>>(op);
    } while(op=='y'||op=='Y');

	ofile.close();
    	ifile.close();
}

void viewrec()
{
	char cn[20];
	int v;

	system("cls");
	cout<<"*********** MENU ************" << endl;
	cout<<"1.View all costumes \n";
	cout<<"2.View a particular costume \n";
	cout<<"3.Back to Costume Menu \n";
	cout<<"Enter choice :  ";
	cin >> v;
	
	switch(v)
	{
		case 1: 
			vwall();
			break;
		case 2:
			{
				char op;
				do 
				{
					cout<<"\n Enter costume name to view :  ";
					cin>>cn;
					vwone(cn);
					cout<<" \n Do you want to view another costume ? (y/n)  ";
					cin>>op;
				} while(op=='y'||op=='Y');
				cstock();
				break;
			}
		case 3:
			cstock();
			break;
		default:
			{
				cout<<"\n Wrong option !!!"<<"\n Press any key to continue ";
				viewrec();
			}
	}
}

int vwall()
{
	int fl=0;
	int length;
	ifstream ifile("CSTOCK.DAT",ios::binary);
	ifile.seekg(0, ios::end);
   
	length=ifile.tellg();
   	if(length==0)
     	{
		cout<<" No costumes available !!!"<<endl;
      		fl=1;
      	}
   	else
     	{
      		ifile.seekg(0, ios::beg);

      		cout<<setfill('-')<<setw(1)<<"+"<<setw(19)<<"-"<<setw(1)<<"+"<<setw(10)<<"-"<<setw(1)<<"+"<<setw(10)<<"-"<<setw(1)<<"+"<<endl;
      		cout<<setfill(' ')<<setw(1)<<"|"<<setw(19)<<"Costume Name"<<setw(1)<<"|"<<setw(10)<<"Quantity"<<setw(1)<<"|"<<setw(10)<<"Rate"<<setw(1)<<"|"<<endl;
      		while(ifile.read((char*)&sr,sizeof(sr)))
	 	{
	  		cout<<setfill('-')<<setw(1)<<"+"<<setw(19)<<"-"<<setw(1)<<"+"<<setw(10)<<"-"<<setw(1)<<"+"<<setw(10)<<"-"<<setw(1)<<"+"<<endl;
	  		cout<<setfill(' ')<<setw(1)<<"|"<<setw(19)<<sr.ctname<<setw(1)<<"|"<<setw(10)<<sr.qty<<setw(1)<<"|"<<setw(10)<<sr.crate<<setw(1)<<"|"<<endl;
	  	}
      		
		cout<<setfill('-')<<setw(1)<<"+"<<setw(19)<<"-"<<setw(1)<<"+"<<setw(10)<<"-"<<setw(1)<<"+"<<setw(10)<<"-"<<setw(1)<<"+"<<endl;
      		
		ifile.close();
      	}

      	return fl;
}


int vwone(char cne[20])
{
	char op;
	int found=0;
	ifstream ifile("CSTOCK.DAT",ios::binary);

	while (ifile.read((char*)&sr,sizeof(sr)))
	{
		if((strcmp(sr.ctname,cne)==0))
		{
	      		cout<<setfill('-')<<setw(1)<<"+"<<setw(19)<<"-"<<setw(1)<<"+"<<setw(10)<<"-"<<setw(1)<<"+"<<setw(10)<<"-"<<setw(1)<<"+"<<endl;
	      		cout<<setfill(' ')<<setw(1)<<"|"<<setw(19)<<"Costume Name"<<setw(1)<<"|"<<setw(10)<<"Quantity"<<setw(1)<<"|"<<setw(10)<<"Rate"<<setw(1)<<"|"<<endl;
	      		cout<<setfill('-')<<setw(1)<<"+"<<setw(19)<<"-"<<setw(1)<<"+"<<setw(10)<<"-"<<setw(1)<<"+"<<setw(10)<<"-"<<setw(1)<<"+"<<endl;
	      		cout<<setfill(' ')<<setw(1)<<"|"<<setw(19)<<sr.ctname<<setw(1)<<"|"<<setw(10)<<sr.qty<<setw(1)<<"|"<<setw(10)<<sr.crate<<setw(1)<<"|"<<endl;
	      		cout<<setfill('-')<<setw(1)<<"+"<<setw(19)<<"-"<<setw(1)<<"+"<<setw(10)<<"-"<<setw(1)<<"+"<<setw(10)<<"-"<<setw(1)<<"+"<<endl;
	      		found=1;
	     	}
	}
      	if(found==0)
	{
		cout<<"\n Costume not found !!!"<<endl;
	}

       ifile.close();
       return found;
}

void modifyrec()
{
	char cn[20], ctnamee[20];
   	int v, qtye;
   	char op, one;
   	float ratee;
   	do
	{
      		system("cls");
      		int flag=0;
      	
		ifstream ifile("CSTOCK.DAT",ios::binary);
      		ofstream ofile("TEMP1.DAT",ios::binary);
      		cout<<"\n Enter Costume name to Modify : ";
      		cin>>cn;

		int found = vwone(cn);
      		if(found==1)
		{
	 		cout<<"\n Do you want to Modify this costume ? (y/n)  ";
	 		cin>>one;
	 		if(one=='y'||one=='Y')
	   		{
	    			while(ifile.read((char*)&sr,sizeof(sr)))
	       			{
					if(strcmp(sr.ctname,cn)==0)
		  			{
		   				cout<<" Enter the costume name :  ";
		   				cin>>ctnamee;
		   				strcpy(sr.ctname,ctnamee);
		   				cout<<" Enter Quantity :  ";
		   				cin>>qtye;
		   				sr.qty=qtye;
		   				cout<<" Enter costume rate :  ";
		   				cin>>ratee;
		   				sr.crate=ratee;
		   				flag=1;
		   			}
		 			ofile.write((char*)&sr,sizeof(sr));
				}
				ifile.close();
				ofile.close();
				remove("CSTOCK.DAT");
				rename("TEMP1.DAT","CSTOCK.DAT");
	      		}
	    		else
	       		cout<<"\n Record not Modified !!!"<<endl;
		}

		if(flag==1)
			cout<<"\n Record Modified !!!"<<endl;
		
		cout<<" \n Do you want to modify another record ? (y/n)  ";
		cin>>op;
	}while(op=='y'||op=='Y');
}

void deleterec()
{
	char cn[20];
   	int v;
   	
      	system("cls");
      	cout<< "*********** MENU ************" << endl;
      	cout << "1.Delete a particular costume \n";
      	cout << "2.Delete all costumes \n";
      	cout << "3.Back to Costume Menu \n";
      	cout<<"Enter choice :  ";
      	cin >> v;
      	switch(v)
	{
	 	case 1:
			{
		 		char op;
		 		do 
				{
		     			int flag=0;
		     			char one;
		     			ifstream ifile("CSTOCK.DAT",ios::binary);
		     			ofstream ofile("TEMP1.DAT",ios::binary);
		     			cout<<"\n Enter Costume name to Delete :  ";
		     			cin>>cn;
		     			int found = vwone(cn);
		     			if(found==1)
		       			{
						cout<<"\n Are you sure you want to delete this Costume ? (y/n)";
						cin>>one;
						if(one=='y'||one=='Y')
			  			{
			   				while(ifile.read((char*)&sr,sizeof(sr)))
			      				{
			       					if(strcmp(sr.ctname,cn)!=0)
				 				{
				  					ofile.write((char*)&sr,sizeof(sr));
				  				}
							}
			       				flag=1;
			       				ifile.close();
			       				ofile.close();
		       					remove("CSTOCK.DAT");
		       					rename("TEMP1.DAT","CSTOCK.DAT");
		  				}
						else
		   					cout<<"\n Costume not deleted !!!"<<endl;
					}
	      				
					if(flag==1)
		 				cout<<"\n Costume deleted !!!"<<endl;
	      				ifile.close();
	      				cout<<" \n Do you want to delete another Costume ? (y/n)  ";
	      				cin>>op;
	    			} while(op=='y'||op=='Y');
	    			cstock();
	    			break;
	 		}

		case 2: 
			{
	  			char al;
	  			int fl=vwall();
	  			if(fl==0)
	  			{
					cout<<"\n Are you sure you want to delete all costumes ? (y/n)";
	  				cin>>al;
	  				if(al=='y'||al=='Y')
	    				{
	     					remove("CSTOCK.DAT");
	     					cout<<"\n All Costumes Deleted !!!"<<endl;
	     					ofstream ofile;
	     					ofile.open("CSTOCK.DAT",ios::binary|ios::app);
	     				}
	  				else
	     					cout<<"\n Costumes not Deleted !!!"<<endl;
	     			}
	     		
	     			cstock();
	     			break;
	  		}
 		
		case 3: 
			{
	 			cstock();
	 			break;
			}
		default:
			{
				cout<<"\n Wrong option !!!"<<"\n Press any key to continue ";
	 			deleterec();
			}
 	}
}

void checkstat()
{
	char r;
 	do
	{
 		system("cls");
 		char cn[20];

 		cout<<"\n Enter Costume Name to check status : ";
 		cin>>cn;
 		int td=gtrate(cn);
 		if(td==0)
    			cout<<"\n Costume is available"<<endl;
 		else
    			cout<<"\n Costume not available"<<endl;
 		
		cout<<"\n \n Do you want to check status of another Costume ? (y/n)  ";
 		cin>>r;

	}while(r=='y'||r=='Y');

	if(r!='y'||r!='Y')
  		cstock();
}

void customer()
{
	system("cls");
	int c;
	do
	{ 
		cout<<"******** CUSTOMER MENU ********"<<endl;
	 	cout<<"#------MAINTENANCE-----#"<<endl;
	 	cout<<"   1.Add record"<<endl;
	 	cout<<"   2.View record"<<endl;
		cout<<"   3.Modify record"<<endl;
	 	cout<<"   4.Delete a record"<<endl;
	 	cout<<"#------TRANSACTION-------#"<<endl;
		cout<<"   5.Costume Returns"<<endl;
	 	cout<<"   6.Generate bill"<<endl;
	 	cout<<"   7.Check status"<<endl;
	 	cout<<"   8.Back to Main Menu"<<endl;
	 	cout<<"Enter your choice :  ";
		cin>>c;
		switch(c)
	 	{
	  		case 1:
	            		addrecord();
		    		break;
	    		case 2:
	            		viewrecord();
		    		break;
	    		case 3:
		    		modifyrecord();
		    		break;
	    		case 4:
		    		deleterecord();
		    		break;
	    		case 5:
		    		returns();
		    		break;
	    		case 6:
		    		generatebill();
		    		break;
	    		case 7:
		    		checkstatus();
		    		break;
	    		case 8:
		    		main();
	    		default:
	            		{
					cout<<"\n Wrong option !!!"<<"\n Press any key to continue ";
					customer();
		    		}
	  	}
	}while(c<7);
 }

void addrecord()
{
	ofstream ofile;
   	ifstream ifile;
   	int len,l=0;//,a,b,yy,dd,m,y;
   	char op;
   
	ofile.open("COSTUME.DAT",ios::binary|ios::app);
   	ifile.open("COSTUME.DAT",ios::binary);
   	ifile.seekg(0, ios::end);
      	len=ifile.tellg();
      
	if(len==0)
	{
		cr.recno=1;
	 	l=1;
	}
   	
	do
	{
      		system("cls");
      		if(l!=1)
	 	{ 
			ifile.seekg(0, ios::beg);
	   		while(ifile.read((char*)&cr,sizeof(cr)))
			{
	 		}
  			++cr.recno;
		}
      	
		getdate();
		
      		cout<<" Record number:  ";
     		cout<<cr.recno;
      		cout<<"\n Name of customer:  ";
      		cin>>cr.custoname;
		cout<<" Enter Costume name:  ";
      		cin>>cr.cname;

      		int qd=gtrate(cr.cname);
      		if(qd==0)
		{  
			delcos(cr.cname);
	   		cout<<" Enter no of days :  ";
	   		cin>>cr.nodays;
	   		cout<<" Costume rate per day :  "<<cr.rate<<endl;
	   		cout<<" Costume issue Date is :  ";
	   		cout<<cr.idd<<"-"<<cr.imm<<"-"<<cr.iyy;
	   		duedt();
	   		cout<<"\n Return Date  :  "<<cr.rdd<<"-"<<cr.rmm<<"-"<<cr.ryy;
	   		cr.ret='N';
	   		ofile.write((char*)&cr,sizeof(cr));
		}
    		else
	  	{
			--cr.recno;
	   		cout<<"\n Costume not available"<<endl;
		}
      		
		l=0;
      
		cout<<"\n Do you want to add another record ? (y/n)  ";
      		cin>>(op);
	} while(op=='y'||op=='Y');
      
	ofile.close();
      	ifile.close();
}

void delcos(char dc[20])
{
	ifstream ifile("CSTOCK.DAT",ios::binary);
      	ofstream ofile("TEMP2.DAT",ios::binary);
      	while(ifile.read((char*)&sr,sizeof(sr)))
	{
	    	if(strcmp(sr.ctname,dc)==0)
	       		sr.qty=sr.qty-1;
	    	
		ofile.write((char*)&sr,sizeof(sr));
	}
	ifile.close();
	ofile.close();
	remove("CSTOCK.DAT");
	rename("TEMP2.DAT","CSTOCK.DAT");
}

void duedt()
{
   	cr.rdd=cr.idd+cr.nodays;
   	cr.rmm=cr.imm;
   	cr.ryy=cr.iyy;
   	while(cr.rdd>31)
      	{
       		if((cr.rdd>31)&&(cr.rmm==1||cr.rmm==3||cr.rmm==5||cr.rmm==7||cr.rmm==8||cr.rmm==10||cr.rmm==12))
	  	{
	   		cr.rdd=cr.rdd-31;
	   		cr.rmm=cr.rmm+1;
	   		cr.ryy=cr.ryy;
	   		if(cr.rdd==0)
	     			cr.rdd=1;
	   		if(cr.rmm>12)
	     		{
	      			cr.rmm=1;
	      			cr.ryy=cr.ryy+1;
	      		}
	   	}
       		if((cr.rdd>31)&&(cr.rmm==4||cr.rmm==6||cr.rmm==9||cr.rmm==11))
	  	{
	   		cr.rdd=cr.rdd-30;
	   		cr.rmm=cr.rmm+1;
	   		cr.ryy=cr.ryy;
	   	}
       		if(cr.rdd>31&&cr.rmm==2)
	 	{
	  		if((cr.ryy%400==0)||(cr.ryy%4==0&&cr.ryy%100!=0))
	     		{
	      			cr.rdd=cr.rdd-29;
	      			cr.rmm=cr.rmm+1;
	      			cr.ryy=cr.ryy;
	      		}
	  		else
	     		{
	      			cr.rdd=cr.rdd-28;
	      			cr.rmm=cr.rmm+1;
	      			cr.ryy=cr.ryy;
	      		}
	    	}
	}

	if((cr.rdd==31)&&(cr.rmm==4||cr.rmm==6||cr.rmm==9||cr.rmm==11))
	{
		cr.rdd=cr.rdd-30;
	    	cr.rmm=cr.rmm+1;
	    	cr.ryy=cr.ryy;
	}

	if((cr.rdd==31||cr.rdd==30||cr.rdd==29)&&(cr.rmm==2))
	{
	    	if((cr.ryy%400==0)||(cr.ryy%4==0&&cr.ryy%100!=0))
	     	{
			cr.rdd=cr.rdd-29;
	      		cr.rmm=cr.rmm+1;
	      		cr.ryy=cr.ryy;
	      		if(cr.rdd==0)
		 	cr.rdd=1;
	      	}
	 	else
	     	{
	      		cr.rdd=cr.rdd-28;
	      		cr.rmm=cr.rmm+1;
	      		cr.ryy=cr.ryy;
	      	}
	}
}

int gtrate(char ct[20])
{
    int fd=0, f=0;
    ifstream ifile("CSTOCK.DAT",ios::binary);
    ifile.seekg(0, ios::beg);
    
    while(ifile.read((char*)&sr,sizeof(sr)))
    {
      if((strcmp(sr.ctname,ct)==0)&&(sr.qty!=0))
	    {
	            cr.rate=sr.crate;
	            f=1;
	            fd=0;
	    }
    }
    
    if(f==0)
	    fd=1;
    
    ifile.close();
    return fd;
}

void getdate()
{
	auto now = chrono::system_clock::now();

  	time_t currentTime = chrono::system_clock::to_time_t(now);
  	struct tm* timeInfo = localtime(&currentTime);
  
	cr.idd = timeInfo->tm_mday;
	cr.imm = 1 + timeInfo->tm_mon; 
	cr.iyy = 1900 + timeInfo->tm_year;
}

void viewrecord()
{
	int newrec, v;
      	system("cls");
      	cout<< "*********** MENU ************" << endl;
      	cout << "1.View all records \n";
      	cout << "2.View a particular record \n";
      	cout << "3.Back to Customer Menu \n";
      	cout<<"Enter choice :  ";
      	cin >> v;
      	switch(v)
	{
		case 1: 
	   		viewall();
	   		break;
		case 2:
			{
	  			char op;
	  			do 
				{
	      				cout<<"\n Enter record no. to view :  ";
	      				cin>>newrec;
	      				viewone(newrec);
	      				cout<<" \n Do you want to view another record ? (y/n)  ";
	      				cin>>op;
	      			} while(op=='y'||op=='Y');
	      			customer();
	      			break;
	      		}
	  	case 3:
			  customer();
			  break;
	  	default:
		  	{
				cout<<"\n Wrong option !!!"<<"\n Press any key to continue ";
		   		viewrecord();
			}
	}
}

int viewone(int newrec)
{
   	char op;
   	int found=0,a,b,y,e,f,g;
   	ifstream ifile("COSTUME.DAT",ios::binary);
   	while (ifile.read((char*)&cr,sizeof(cr)))
	{
	   	if(cr.recno==newrec)
	     	{
	      		a= cr.idd; b= cr.imm; y= cr.iyy;
	      		e= cr.rdd; f= cr.rmm; g= cr.ryy;
	      		cout<<setfill('-')<<setw(1)<<"+"<<setw(5)<<"-"<<setw(1)<<"+"<<setw(19)<<"-"<<setw(1)<<"+"<<setw(11)<<"-"<<setw(1)<<"+"<<setw(6)<<"-"<<setw(1)<<"+"<<setw(7)<<"-"<<setw(1)<<"+"<<setw(11)<<"-"<<setw(1)<<"+"<<setw(12)<<"-"<<setw(1)<<"+"<<endl;
	      		cout<<setfill(' ')<<setw(1)<<"|"<<setw(5)<<"R.No"<<setw(1)<<"|"<<setw(19)<<"Customer Name"<<setw(1)<<"|"<<setw(11)<<"Costume"<<setw(1)<<"|"<<setw(6)<<"Days"<<setw(1)<<"|"<<setw(7)<<"Rate"<<setw(1)<<"|"<<setw(11)<<"Issue Date"<<setw(1)<<"|"<<setw(12)<<"Return Date"<<setw(1)<<"|"<<endl;
	      		cout<<setfill('-')<<setw(1)<<"+"<<setw(5)<<"-"<<setw(1)<<"+"<<setw(19)<<"-"<<setw(1)<<"+"<<setw(11)<<"-"<<setw(1)<<"+"<<setw(6)<<"-"<<setw(1)<<"+"<<setw(7)<<"-"<<setw(1)<<"+"<<setw(11)<<"-"<<setw(1)<<"+"<<setw(12)<<"-"<<setw(1)<<"+"<<endl;
	      		cout<<setfill(' ')<<setw(1)<<"|"<<setw(5)<<cr.recno<<setw(1)<<"|"<<setw(19)<<cr.custoname<<setw(1)<<"|"<<setw(11)<<cr.cname<<setw(1)<<"|"<<setw(6)<<cr.nodays<<setw(1)<<"|"<<setw(7)<<cr.rate<<setw(1)<<"|"<<setw(4)<<a<<"-"<<b<<"-"<<y<<setw(1)<<"|"<<setw(5)<<e<<"-"<<f<<"-"<<g<<setw(1)<<"|"<<endl;
	      		cout<<setfill('-')<<setw(1)<<"+"<<setw(5)<<"-"<<setw(1)<<"+"<<setw(19)<<"-"<<setw(1)<<"+"<<setw(11)<<"-"<<setw(1)<<"+"<<setw(6)<<"-"<<setw(1)<<"+"<<setw(7)<<"-"<<setw(1)<<"+"<<setw(11)<<"-"<<setw(1)<<"+"<<setw(12)<<"-"<<setw(1)<<"+"<<endl;
	      		found=1;
	     	}
	}

      	if(found==0)
	 	cout<<"\n Record not found !!!"<<endl;

       ifile.close();
       return found;
 }

int viewall()
{
	int fl=0;
   	int length,a,b,y,e,f,g;
   	ifstream ifile("COSTUME.DAT",ios::binary);
   	ifile.seekg(0, ios::end);
   	length=ifile.tellg();
   	if(length==0)
     	{
		cout<<" No records available"<<endl;
      		fl=1;
      	}
   	else
     	{
      		ifile.seekg(0, ios::beg);
      		cout<<setfill('-')<<setw(1)<<"+"<<setw(5)<<"-"<<setw(1)<<"+"<<setw(19)<<"-"<<setw(1)<<"+"<<setw(11)<<"-"<<setw(1)<<"+"<<setw(6)<<"-"<<setw(1)<<"+"<<setw(7)<<"-"<<setw(1)<<"+"<<setw(11)<<"-"<<setw(1)<<"+"<<setw(12)<<"-"<<setw(1)<<"+"<<endl;
      		cout<<setfill(' ')<<setw(1)<<"|"<<setw(5)<<"R.No"<<setw(1)<<"|"<<setw(19)<<"Customer Name"<<setw(1)<<"|"<<setw(11)<<"Costume"<<setw(1)<<"|"<<setw(6)<<"Days"<<setw(1)<<"|"<<setw(7)<<"Rate"<<setw(1)<<"|"<<setw(11)<<"Issue Date"<<setw(1)<<"|"<<setw(12)<<"Return Date"<<setw(1)<<"|"<<endl;
      		while(ifile.read((char*)&cr,sizeof(cr)))
	 	{
	  		a= cr.idd; b= cr.imm; y= cr.iyy;
	  		e= cr.rdd; f= cr.rmm; g= cr.ryy;
	  		cout<<setfill('-')<<setw(1)<<"+"<<setw(5)<<"-"<<setw(1)<<"+"<<setw(19)<<"-"<<setw(1)<<"+"<<setw(11)<<"-"<<setw(1)<<"+"<<setw(6)<<"-"<<setw(1)<<"+"<<setw(7)<<"-"<<setw(1)<<"+"<<setw(11)<<"-"<<setw(1)<<"+"<<setw(12)<<"-"<<setw(1)<<"+"<<endl;
	  		cout<<setfill(' ')<<setw(1)<<"|"<<setw(5)<<cr.recno<<setw(1)<<"|"<<setw(19)<<cr.custoname<<setw(1)<<"|"<<setw(11)<<cr.cname<<setw(1)<<"|"<<setw(6)<<cr.nodays<<setw(1)<<"|"<<setw(7)<<cr.rate<<setw(1)<<"|"<<setw(4)<<a<<"-"<<b<<"-"<<y<<setw(1)<<"|"<<setw(5)<<e<<"-"<<f<<"-"<<g<<setw(1)<<"|"<<endl;
      		}
      		
		cout<<setfill('-')<<setw(1)<<"+"<<setw(5)<<"-"<<setw(1)<<"+"<<setw(19)<<"-"<<setw(1)<<"+"<<setw(11)<<"-"<<setw(1)<<"+"<<setw(6)<<"-"<<setw(1)<<"+"<<setw(7)<<"-"<<setw(1)<<"+"<<setw(11)<<"-"<<setw(1)<<"+"<<setw(12)<<"-"<<setw(1)<<"+"<<endl;
      		
		ifile.close();
      }

      return fl;
}

void modifyrecord()
{
   	int newrec, v;
   	char op, one;
   	int noodays,cnoo,ratee;
   	char cnamee[20], custoname[20];
   	do
	{
      		system("cls");
      		int flag=0;
      		ifstream ifile("COSTUME.DAT",ios::binary);
      		ofstream ofile("TEMP.DAT",ios::binary);
      		cout<<"\n Enter record no. to Modify : ";
      		cin>>newrec;
      		int found = viewone(newrec);
      		if(found==1)
		{
	 		cout<<"\n Do you want to Modify this record ? (y/n)  ";
	 		cin>>one;
	 		if(one=='y'||one=='Y')
	   		{
	    			while(ifile.read((char*)&cr,sizeof(cr)))
	       			{
					if(cr.recno==newrec)
		  			{
		   				cout<<"\n Enter the customer name :  ";
		   				cin>>cr.custoname;
		   				cout<<" Enter the costume name :  ";
		   				cin>>cnamee;
		   				strcpy(cr.cname,cnamee);
		  				cout<<" Enter the number of days :  ";
		   				cin>>noodays;
		   				cr.nodays=noodays;
		   				cout<<" Enter costume price :  ";
		   				gtrate(cr.cname);
		   				cout<<cr.rate;
		   				getdate();
		   				duedt();
		   				flag=1;
		   			}
		 			ofile.write((char*)&cr,sizeof(cr));
				}
				ifile.close();
				ofile.close();
				remove("COSTUME.DAT");
				rename("TEMP.DAT","COSTUME.DAT");
	      		}
	    		else
	       			cout<<"\n Record not Modified !!!"<<endl;
		}

		if(flag==1)
			cout<<"\n Record Modified !!!"<<endl;
	    
		cout<<" \n Do you want to modify another record ? (y/n)  ";
	    	cin>>op;

	} while(op=='y'||op=='Y');
}

void deleterecord()
{
	int newrec, v;
      	system("cls");
      	cout<< "*********** MENU ************" << endl;
      	cout << "1.Delete a particular record \n";
      	cout << "2.Delete all records \n";
      	cout << "3.Back to Customer Menu \n";
      	cout<<"Enter choice :  ";
      	cin >> v;
      	switch(v)
	{
	 	case 1:
			{
		 		char op;
		 		do 
				{
		     			int flag=0;
		     			char one;
		     			ifstream ifile("COSTUME.DAT",ios::binary);
		     			ofstream ofile("TEMP.DAT",ios::binary);
		     
					cout<<"\n Enter record no. to Delete :  ";
		     			cin>>newrec;
		     
					int found = viewone(newrec);
		     			if(found==1)
		       			{
						cout<<"\n Are you sure you want to delete this record ? (y/n)";
						cin>>one;
			
						if(one=='y'||one=='Y')
			  			{
			   				while(ifile.read((char*)&cr,sizeof(cr)))
			      				{
			       					if(cr.recno==newrec)
				  					addcos(cr.cname);
			       					
								if(cr.recno!=newrec)		 				
				  					ofile.write((char*)&cr,sizeof(cr));
				  			}
						}
			       
						flag=1;
			       			ifile.close();
			       			ofile.close();
			       			remove("COSTUME.DAT");
			       			rename("TEMP.DAT","COSTUME.DAT");
			  		}
					else
			   			cout<<"\n Record not deleted !!!"<<endl;
		      			
					if(flag==1)
			 			cout<<"\n Record deleted !!!"<<endl;
		      			
					ifile.close();
		      			
					cout<<" \n Do you want to delete another record ? (y/n)  ";
		      			cin>>op;
		    		} while(op=='y'||op=='Y');
		    	
				customer();
		    		break;
		 	}
		
		case 2: 
			{
		  		char al;
		  		int fl=viewall();
		  		if(fl==0)
		  		{
					cout<<"\n Are you sure you want to delete all records ? (y/n)";
		  			cin>>al;
		 			if(al=='y'||al=='Y')
		    			{
						ifstream ifile("COSTUME.DAT",ios::binary);
		    				while(ifile.read((char*)&cr,sizeof(cr)))
			  			{
							addcos(cr.cname);
						}
		     
						remove("COSTUME.DAT");
		     				cout<<"\n All records Deleted !!!"<<endl;
		     				ofstream ofile;
		     				ofile.open("COSTUME.DAT",ios::binary|ios::app);
		     			}
		  			else
		     				cout<<"\n Records not Deleted !!!"<<endl;
		  		}
		     		customer();
		  	}
		
		case 3: 
			customer();
		 	break;
	
		default:
			{
				cout<<"\n Wrong option !!!"<<"\n Press any key to continue ";
		 		deleterecord();
			}
	}
}

void addcos(char de[20])
{
	ifstream ifile("CSTOCK.DAT",ios::binary);
      	ofstream ofile("TEMP3.DAT",ios::binary);
      	while(ifile.read((char*)&sr,sizeof(sr)))
	{
		if(strcmp(sr.ctname,de)==0)
	       		sr.qty=sr.qty+1;
	    	
		ofile.write((char*)&sr,sizeof(sr));
	}
	
	ifile.close();
	ofile.close();
	remove("CSTOCK.DAT");
	rename("TEMP3.DAT","CSTOCK.DAT");
}

void returns()
{
   	char op, one;
   	do
	{
      		system("cls");
      		int flag=0, nr;
      		int newrec;
      		cout<<"\n Enter record no. to return costume : ";
      		cin>>newrec;
      		nr=newrec;
      		int found = viewone(newrec);
      		ifstream ifile("COSTUME.DAT",ios::binary);
      		ofstream ofile("TEMP5.DAT",ios::binary);
      		if(found==1)
		{
	 		cout<<"\n Do you want to return this costume ? (y/n)  ";
	 		cin>>one;
	 		if(one=='y'||one=='Y')
	   		{
		   		while(ifile.read((char*)&cr,sizeof(cr)))
				{
			 		if(cr.recno==nr)
			   		{ 
						addcos(cr.cname);
						cr.ret='R';
			     			flag=1; 
					}
			  	
					ofile.write((char*)&cr,sizeof(cr));
				}
		  	}
	      		else
	       			cout<<"\n Costume return not recorded !!!"<<endl;
	    	}
	 	if(flag==1)
	   	{ 
			ifile.close();
	     		ofile.close();
	     
			remove("COSTUME.DAT");
	     		rename("TEMP5.DAT","COSTUME.DAT");
	     		cout<<"\n Costume return recorded !!!"<<endl;
	     	}
	  	else
	     	{
	      		ifile.close();
	      		ofile.close();
	      	}
	 
		cout<<" \n Do you want to enter return of another costume ? (y/n)  ";
		cin>>op;
   	}while(op=='y'||op=='Y');
}

void generatebill()
{
   	char op;
   	do
	{
   int found=0, h;
   ifstream ifile("COSTUME.DAT",ios::binary);
   cout<<"\n Enter record no. to generate bill :  ";
   cin>>h;
   while(ifile.read((char*)&cr,sizeof(cr)))
      {
       int a, b, c, e, f, g, k, i, j;
       float price;
       price=cr.nodays*cr.rate;
       if(cr.recno==h)
	 {
	  getretdate();
	  
	  a=cr.ardd; b=cr.armm; c=cr.aryy;
	  e=cr.idd; f=cr.imm; g=cr.iyy;
	  k=cr.rdd; i=cr.rmm; j=cr.ryy;
	  cout<<"\n Record No : "<<cr.recno<<setw(28)<<"Bill Date : "<<a<<"-"<<b<<"-"<<c<<endl;
	  cout<<"\n Customer name : "<<cr.custoname<<endl;
	  cout<<"\n Issue Date : "<<e<<"-"<<f<<"-"<<g<<setw(20)<<"Return Date : "<<k<<"-"<<i<<"-"<<j<<endl;
	  cout<<setfill('-')<<setw(1)<<"+"<<setw(18)<<"-"<<setw(1)<<"+"<<setw(8)<<"-"<<setw(1)<<"+"<<setw(10)<<"-"<<setw(1)<<"+"<<setw(15)<<"-"<<setw(1)<<"+"<<endl;
	  cout<<setfill(' ')<<setw(1)<<"|"<<setw(18)<<"Costume"<<setw(1)<<"|"<<setw(8)<<"Days"<<setw(1)<<"|"<<setw(10)<<"Rate"<<setw(1)<<"|"<<setw(15)<<"Total Due"<<setw(1)<<"|"<<endl;
	  cout<<setfill('-')<<setw(1)<<"+"<<setw(18)<<"-"<<setw(1)<<"+"<<setw(8)<<"-"<<setw(1)<<"+"<<setw(10)<<"-"<<setw(1)<<"+"<<setw(15)<<"-"<<setw(1)<<"+"<<endl;
	  cout<<setfill(' ')<<setw(1)<<"|"<<setw(18)<<cr.cname<<setw(1)<<"|"<<setw(8)<<cr.nodays<<setw(1)<<"|"<<setw(10)<<cr.rate<<setw(1)<<"|"<<setw(15)<<price<<setw(1)<<"|"<<endl;
	  cout<<setfill('-')<<setw(1)<<"+"<<setw(18)<<"-"<<setw(1)<<"+"<<setw(8)<<"-"<<setw(1)<<"+"<<setw(10)<<"-"<<setw(1)<<"+"<<setw(15)<<"-"<<setw(1)<<"+"<<endl;
	  cout<<setfill(' ');
	  found=1;
	  }
	 }
       if(found==0)
	  cout<<"\n Record not found !!!"<<endl;
       ifile.close();
       cout<<"\n Do you want to generate another bill ? (y/n)  ";
       cin>>op;
      }while(op=='y'||op=='Y');
   }

void checkstatus()
{
 	char r;
 	do
	{
 		system("cls");
 		int fl=0, rno, e, f, g, k, i, j;
 		ifstream ifile("COSTUME.DAT",ios::binary);
 		cout<<"\n Enter record number to check status : ";
 		cin>>rno;
 		while(ifile.read((char*)&cr,sizeof(cr)))
    		{
     			if(cr.recno==rno)
      			{
       				e=cr.idd; f=cr.imm; g=cr.iyy;
      				k=cr.rdd; i=cr.rmm; j=cr.ryy;
       				
				cout<<"\n Customer name : "<<cr.custoname<<endl;
      				cout<<"\n Costume : "<<cr.cname<<endl;
       				cout<<"\n Issue Date : "<<e<<"-"<<f<<"-"<<g<<endl;
       				cout<<"\n Return Date : "<<k<<"-"<<i<<"-"<<j<<endl;
       				
				if(cr.ret=='R')
	 				cout<<"Costume has been returned !!!"<<endl;
       				else
	 				cout<<"Costume not returned !!!"<<endl;
       				
				fl=1;
       			}
    		}
    
		if(fl==0)
      			cout<<"\n Record not found !!!"<<endl;
    		
		ifile.close();
		
		cout<<"\n Do you want to check status of another record ? (y/n)  ";
		cin>>r;
	}while(r=='y'||r=='Y');

	if(r!='y'||r!='Y')
  		customer();
}

void getretdate()
{
	auto now = chrono::system_clock::now();

  	time_t currentTime = chrono::system_clock::to_time_t(now);
  	struct tm* timeInfo = localtime(&currentTime);
  
	cr.ardd = timeInfo->tm_mday;
	cr.armm = 1 + timeInfo->tm_mon; 
	cr.aryy = 1900 + timeInfo->tm_year;
}