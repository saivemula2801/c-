#include <iostream>
#include <fstream>
#include <string>
#include<bits/stdc++.h>
using namespace std;
class student
{
	public:
	string name;
	int rank;
	double hallticket;
	string p1,p2,p3,p4,p5,p6,p7,p8,p9;//p10,p11,p12,p13,p14,p15,p16,p17,p18;
	string allot;
	student()
	{
	}
};
bool compare(student a,student b)
{
	if(a.rank < b.rank)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
class university
{
	public:
		string coll;
		string b1,b2,b3,b4,b5,b6;
		int c1,c2,c3;
		university()
		{
			
		}
};
void stu(student c[],int n)
{
	ifstream file ("nta.txt");
    if(file.is_open())
    {
    	int i;
    	for(int i=0;i<n;i++)
    	{
    		file>>c[i].name>>c[i].rank>>c[i].hallticket>>c[i].p1>>c[i].p2>>c[i].p3>>c[i].p4>>c[i].p5
			>>c[i].p6>>c[i].p7>>c[i].p8;
			c[i].allot="NULL";
		}
    }
    sort(c,c+n,compare);
    cout<<"student option entries with respect to hallticket \n"<<"\n";
    for(int i=0;i<n;i++)
    {
    	cout<<"name :"<<c[i].name<<" , "<<"hallticket : "<<c[i].hallticket<<", "<<"rank : "<<c[i].rank<<",  "<<"options are: "<<c[i].p1<<","<<c[i].p2<<","
		<<c[i].p3<<","<<c[i].p4<<","<<c[i].p5<<","
			<<c[i].p6<<","<<c[i].p7<<","<<c[i].p8;
    	cout<<"\n";
	}
}
void uni(university u[])
{
	cout<<"\n"<<"\n";

	ifstream fin("clg.txt");
	if(fin.is_open())
	{
		for(int i=0;i<3;i++)
		{
			fin>>u[i].coll>>u[i].b1>>u[i].b2>>u[i].b3>>u[i].b4>>u[i].b5>>u[i].b6;
		}
	}
	cout<<"colleges and the branches with respect to colleges \n"<<"\n";
	for(int i=0;i<3;i++)
	{
		cout<<"college name : "<<u[i].coll<<" , "<<"branches are :"<<u[i].b1<<","<<u[i].b2<<","<<u[i].b3<<","
		<<u[i].b4<<","<<u[i].b5<<","<<u[i].b6<<"\n";
	}
	cout<<"\n "<<"\n";
}
class council
{
	public:
		string college;
		string branch;
		int hallticket;
		string name;
};
void allotment(council co[],student c[],university u[],int n,int seat)
{
	cout<<"allotment order of students with their option entry \n";
    for(int i=0;i<3;i++)
    {
    	u[i].c1=0;
    	u[i].c2=0;
    	u[i].c3=0;
	}
	for(int i=0;i<n;i++)
	{
		if(c[i].allot!="success")
		{
			
			for(int j=0;j<3;j++)
			{
				if(u[j].c1<seat)
				{
					if(c[i].p1==u[j].b1)
					{
					
				    	c[i].allot="success";
					  //  cout<<"hallticket :"<<c[i].hallticket<<" \n "<<"college :"<<u[j].coll<<" \n "<<"branch :"<<c[i].p1<<" \n "<<"\n";
					    co[i].hallticket=c[i].hallticket;
					    co[i].college=u[j].coll;
					    co[i].branch=c[i].p1;
					    co[i].name=c[i].name;
				    	u[j].c1=u[j].c1+1;
				    	break;
				    }
			    }
				else if(u[j].c2<seat)
				{
				    	if(c[i].p1==u[j].b2)
			     		{
					
				    	    c[i].allot="success";
					       // cout<<"hallticket :"<<c[i].hallticket<<" \n "<<"college :"<<u[j].coll<<" \n "<<"branch :"<<c[i].p1<<" \n ";
					       co[i].hallticket=c[i].hallticket;
					    co[i].college=u[j].coll;
					    co[i].branch=c[i].p1;
					     co[i].name=c[i].name;
					       // cout<<"\n";
				    	    u[j].c2=u[j].c1+2;
				    	    break;
				        }
				}
				else if(u[j].c3<seat)
				{
						if(c[i].p1==u[j].b3)
						{
							c[i].allot="success";
						//	cout<<"hallticket :"<<c[i].hallticket<<" \n "<<"college :"<<u[j].coll<<" \n "<<"branch :"<<c[i].p1<<" \n ";
						co[i].hallticket=c[i].hallticket;
					    co[i].college=u[j].coll;
					    co[i].branch=c[i].p1;
					     co[i].name=c[i].name;
							//cout<<"\n";
							u[j].c3=u[j].c3+1;
							break;
						}
				}
				
			}
	    }
	    if(c[i].allot!="success")
	    {
	    	
	    	for(int j=0;j<3;j++)
			{
				if(u[j].c1<seat)
				{
					if(c[i].p2==u[j].b1)
					{
					
				    	c[i].allot="success";
					 //   cout<<"hallticket :"<<c[i].hallticket<<" \n "<<"college :"<<u[j].coll<<" \n "<<"branch :"<<c[i].p2<<" \n ";
					   // cout<<"\n";
					    co[i].hallticket=c[i].hallticket;
					    co[i].college=u[j].coll;
					    co[i].branch=c[i].p2;
					     co[i].name=c[i].name;
				    	u[j].c1=u[j].c1+1;
				    	break;
				    }
			    }
				else if(u[j].c2<seat)
				{
				    	if(c[i].p2==u[j].b2)
			     		{
					
				    	    c[i].allot="success";
					     //   cout<<"hallticket :"<<c[i].hallticket<<" \n "<<"college :"<<u[j].coll<<" \n "<<"branch :"<<c[i].p2<<" \n ";
					       // cout<<"\n";
					        co[i].hallticket=c[i].hallticket;
					    co[i].college=u[j].coll;
					    co[i].branch=c[i].p2;
					     co[i].name=c[i].name;
				    	    u[j].c2=u[j].c2+1;
				    	    break;
				        }
				}
				else if(u[j].c3<seat)
				{
						if(c[i].p2==u[j].b3)
						{
							c[i].allot="success";
							//cout<<"hallticket :"<<c[i].hallticket<<" \n "<<"college :"<<u[j].coll<<" \n "<<"branch :"<<c[i].p2<<" \n ";
						//	cout<<"\n";
							co[i].hallticket=c[i].hallticket;
					    co[i].college=u[j].coll;
					    co[i].branch=c[i].p2; 
						co[i].name=c[i].name;
					    
							u[j].c3=u[j].c3+1;
							break;
						}
				}
				
			}
	    }
	    
	    if(c[i].allot!="success")
	    {
		
			for(int j=0;j<3;j++)
			{
				if(u[j].c1<seat)
				{
					if(c[i].p3==u[j].b1)
					{
					
				    	c[i].allot="success";
					  //  cout<<"hallticket :"<<c[i].hallticket<<" \n "<<"college :"<<u[j].coll<<" \n "<<"branch :"<<c[i].p3<<" \n ";
					  //  cout<<"\n";
					    co[i].hallticket=c[i].hallticket;
					    co[i].college=u[j].coll;
					    co[i].branch=c[i].p3;
					     co[i].name=c[i].name;
				    	u[j].c1=u[j].c1+1;
				    	break;
				    }
				}
				else if(u[j].c2<seat)
			    {
				    	if(c[i].p3==u[j].b2)
			     		{
					
				    	    c[i].allot="success";
					     //   cout<<"hallticket :"<<c[i].hallticket<<" \n "<<"college :"<<u[j].coll<<" \n "<<"branch :"<<c[i].p3<<" \n ";
					        //cout<<"\n";
					        co[i].hallticket=c[i].hallticket;
					    co[i].college=u[j].coll;
					    co[i].branch=c[i].p3;
					     co[i].name=c[i].name;
				    	    u[j].c2=u[j].c2+1;
				    	    break;
				        }
				}
				else if(u[j].c3<seat)
				{
						if(c[i].p3==u[j].b3)
						{
							c[i].allot="success";
						//	cout<<"hallticket :"<<c[i].hallticket<<" \n "<<"college :"<<u[j].coll<<" \n "<<"branch :"<<c[i].p3<<" \n ";
						//	cout<<"\n";
							co[i].hallticket=c[i].hallticket;
					    co[i].college=u[j].coll;
					    co[i].branch=c[i].p3;
					     co[i].name=c[i].name;
							u[j].c3=u[j].c3+1;
							break;
						}
				}
				
			}
	    }
	    
	    if(c[i].allot!="success")
	    {
	    	
	    	for(int j=0;j<3;j++)
			{
				if(u[j].c1<seat)
				{
					if(c[i].p4==u[j].b1)
					{
					
				    	c[i].allot="success";
					 //   cout<<"hallticket :"<<c[i].hallticket<<" \n "<<"college :"<<u[j].coll<<" \n "<<"branch :"<<c[i].p4<<" \n ";
					   // cout<<"\n";
					    co[i].hallticket=c[i].hallticket;
					    co[i].college=u[j].coll;
					    co[i].branch=c[i].p4;
					     co[i].name=c[i].name;
				    	u[j].c1=u[j].c1+1;
				    	break;
				    }
			    }
				else if(u[j].c2<seat)
				{
				    	if(c[i].p4==u[j].b2)
			     		{
					
				    	    c[i].allot="success";
					      //  cout<<"hallticket :"<<c[i].hallticket<<" \n "<<"college :"<<u[j].coll<<" \n "<<"branch :"<<c[i].p4<<" \n ";
					       // cout<<"\n";
					        co[i].hallticket=c[i].hallticket;
					    co[i].college=u[j].coll;
					    co[i].branch=c[i].p4;
					     co[i].name=c[i].name;
				    	    u[j].c2=u[j].c2+1;
				    	    break;
				        }
				}
				else if(u[j].c3<seat)
				{
						if(c[i].p4==u[j].b3)
						{
							c[i].allot="success";
							//cout<<"hallticket :"<<c[i].hallticket<<" \n "<<"college :"<<u[j].coll<<" \n "<<"branch :"<<c[i].p4<<" \n ";
							//cout<<"\n";
							co[i].hallticket=c[i].hallticket;
					    co[i].college=u[j].coll;
					    co[i].branch=c[i].p4;
					     co[i].name=c[i].name;
							u[j].c3=u[j].c3+1;
							break;
						}
				}
				
			}
	    }
		
		if(c[i].allot!="success")
		{
			
			for(int j=0;j<3;j++)
			{
				if(u[j].c1<seat)
				{
					if(c[i].p5==u[j].b1)
					{
					
				    	c[i].allot="success";
					 //   cout<<"hallticket :"<<c[i].hallticket<<" \n "<<"college :"<<u[j].coll<<" \n "<<"branch :"<<c[i].p5<<" \n ";
					 //   cout<<"\n";
					    co[i].hallticket=c[i].hallticket;
					    co[i].college=u[j].coll;
					    co[i].branch=c[i].p5;
					     co[i].name=c[i].name;
				    	u[j].c1=u[j].c1+1;
				    	break;
				    }
				}
				else if(u[j].c2<seat)
			    {
				    	if(c[i].p5==u[j].b2)
			     		{
					
				    	    c[i].allot="success";
					    //    cout<<"hallticket :"<<c[i].hallticket<<" \n "<<"college :"<<u[j].coll<<" \n "<<"branch :"<<c[i].p5<<" \n ";
					     //   cout<<"\n";
					        co[i].hallticket=c[i].hallticket;
					    co[i].college=u[j].coll;
					    co[i].branch=c[i].p5;
					     co[i].name=c[i].name;
				    	    u[j].c2=u[j].c2+1;
				    	    break;
				        }
				}
				else if(u[j].c3<seat)
				{
						if(c[i].p5==u[j].b3)
						{
							c[i].allot="success";
						//	cout<<"hallticket :"<<c[i].hallticket<<" \n "<<"college :"<<u[j].coll<<" \n "<<"branch :"<<c[i].p5<<" \n ";
						//	cout<<"\n";
							co[i].hallticket=c[i].hallticket;
					    co[i].college=u[j].coll;
					    co[i].branch=c[i].p5;
					     co[i].name=c[i].name;
							u[j].c3=u[j].c3+1;
							break;
						}
				}
				
			}
		}
		if(c[i].allot!="success")
		{
			
			for(int j=0;j<3;j++)
			{
				if(u[j].c1<seat)
				{
					if(c[i].p6==u[j].b1)
					{
					
				    	c[i].allot="success";
					  //  cout<<"hallticket :"<<c[i].hallticket<<" \n "<<"college :"<<u[j].coll<<" \n "<<"branch :"<<c[i].p6<<" \n ";
					 //   cout<<"\n";
					    co[i].hallticket=c[i].hallticket;
					    co[i].college=u[j].coll;
					    co[i].branch=c[i].p6;
					     co[i].name=c[i].name;
				    	u[j].c1=u[j].c1+1;
				    	break;
				    }
				}
				else if(u[j].c2<seat)
			    {
				    	if(c[i].p6==u[j].b2)
			     		{
					
				    	    c[i].allot="success";
					       // cout<<"hallticket :"<<c[i].hallticket<<" \n "<<"college :"<<u[j].coll<<" \n "<<"branch :"<<c[i].p6<<" \n ";
					        
					        co[i].hallticket=c[i].hallticket;
					    co[i].college=u[j].coll;
					    co[i].branch=c[i].p6;
					     co[i].name=c[i].name;
				    	    u[j].c2=u[j].c2+1;
				    	    break;
				        }
				}
				else if(u[j].c3<seat)
				{
						if(c[i].p6==u[j].b3)
						{
							c[i].allot="success";
						//	cout<<"hallticket :"<<c[i].hallticket<<" \n "<<"college :"<<u[j].coll<<" ,\n "<<"branch :"<<c[i].p6<<" \n ";
						//	cout<<"\n";
							co[i].hallticket=c[i].hallticket;
					    co[i].college=u[j].coll;
					    co[i].branch=c[i].p6;
					     co[i].name=c[i].name;
							u[j].c3=u[j].c3+1;
							break;
						}
				}
				
			}
	    }
	}
	cout<<"the students who are not alloted any seats in colleges \n";
	for(int i=0;i<n;i++)
	{
		if(c[i].allot!="success")
		{
			cout<<c[i].name<<" , "<<c[i].hallticket<<"\n";
		}
	}
	cout<<"wait for next counciling \n";
}
int main()
{
	student c[20];
	int n;
	string data;
	cout<<"enter how many students are participating in seat allotment \n";
	cin>>n;
	int seat;
	cout<<"enter how many seats are there in a course of each respective college \n";
	cin>>seat;
	
	stu(c,n);
	
	cout<<"\n"<<"\n";
	university u[3];
	uni(u);
	council co[15];
	allotment(co,c,u,n,seat);
	cout<<"\n";
	for(int i=0;i<n;i++)
	{
		cout<<"name :"<<co[i].name<<"\n"<<"hallticket :"<<co[i].hallticket<<" \n "<<"college :"<<co[i].college<<" \n "<<"branch :"<<co[i].branch<<" \n "<<"\n";
	}
    int ht;
    cout<<"enter hall ticket for allotment \n";
    cin>>ht;
    for(int i=0;i<n;i++)
    {
    	if(ht==co[i].hallticket)
    	{
    		cout<<"name :"<<co[i].name<<"\n"<<"hallticket :"<<co[i].hallticket<<" \n "<<"college :"<<co[i].college<<" \n "<<"branch :"<<co[i].branch<<" \n "<<"\n";
		}
	}
    
     
   
    return 0;
}
