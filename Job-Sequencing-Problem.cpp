/*
Sort the structure according to decreasing order of profit
See the code
*/


#include<iostream>
#include<algorithm>  //to use sort()
   
using namespace std;

// A structure to represent a job
struct Job
{
   char id;         // Job Id
   int deadline;    // Deadline of job
   int profit;     // Profit if job is over before or on deadline
};


// This function is used for sorting all jobs according to profit
bool comparison(Job a, Job b)
{
     return (a.profit > b.profit);
}

//our function
void Job_Sequence(struct Job arr[],int size)
{
	int current_time,remaining_time,last_printed_time;
	
	//Sort the structure according to decreasing order of profit                                                   CHECK
	sort(arr,arr+size,comparison);
	
	for(int i=0;i<size;i++)
	{
		cout<<"\n"<<arr[i].profit;
	}
	
	cout<<"\n { ";
	//iterate over the structure.
	for(int i=0;i<size;i++)
	{
		//cout<<"\ni => "<<i;
		//First wala to anyhow display hoga hi hoga
		if(i==0)
		{
			cout<<" "<<arr[i].id;
			last_printed_time=arr[i].deadline;
		}		
		
		current_time=arr[i].deadline;
		//cout<<"\ncurrent_time => "<<current_time;
		//current activity is already printed and every job takes 1 unit only
		remaining_time=current_time-1; 
		//cout<<"\nremaining_time => "<<remaining_time;
		//ab yaha se agli job select karo jo print karni hai
			for(int j=i+1 && (remaining_time!=0);j<size;j++)
			{
				//cout<<"\nj => "<<j;
				
				if(remaining_time==0)
				{
					break;
				}
				
				//agli job jo choose hogi vo remaining time me fit honi chaiye and time bhi remaining hona chaiye varna 
				//i ko increase
				//karo agar remaining_time 0 hua to
				if(remaining_time<=arr[j].deadline)
				{
					//check condition:
					//agla current time vohi hoga jo pichle printed time se > hoga bzoc we have exhausted Curr time in j loop 
					//nhi to repitition hoga
					//i++ karte jao jab tak condition satisfy nhi hogi 
					//also first element is an exception bcoz tab kuch last printed nhi hai
					if(last_printed_time<=arr[j].deadline)
					{
						//print karo us job ko
						cout<<" "<<arr[j].id<<" ";
						last_printed_time=arr[j].deadline;
						//cout<<"\nlast_printed_time => "<<last_printed_time;
						//print karne ke baad time ek se kam karo
						remaining_time--;
						
				   }
							
				}
			}
		}
		
	cout<<" } ";	
	}


int main()
{
	//STATIC inputs:
	
	int size=4;
	
	Job arr[] = { 
					{'a', 2, 100}, 
					{'b', 1, 19}, 
					{'c', 2, 27},
                    {'d', 1, 25}, 
				    {'e', 3, 15}
				};
				
	cout<<"\nThe sequence required => ";
	Job_Sequence(arr,size);			
                   
	
return 0;
}
