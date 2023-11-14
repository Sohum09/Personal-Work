#include <bits/stdc++.h>
#define totalprocess 5
using namespace std;
struct process{
	int at, bt, pr, pno;
}proc[50];

//Comparison function for priority check:
bool comp(process a, process b){
	if(a.at==b.at)
		return a.pr < b.pr;
	return a.at < b.at;
}

//Finding Waiting Time:
void findWT(int wt[]){
	int service[50]; //This will store the cumulative burst time for each process
	service[0] = proc[0].at; //To skip to the arrival time of the first process
	wt[0] = 0;
	
	for(int i=1; i<totalprocess; i++){
		service[i] = proc[i-1].bt + service[i-1];
		wt[i] = service[i] - proc[i].bt;
		if(wt[i] < 0)
			wt[i] = 0;
	}
}

void findTAT(int tat[], int wt[]){
	for(int i=0; i<totalprocess; i++)
		tat[i] = proc[i].bt + wt[i];
}

void findgc(){
	int wt[50], tat[50];
	findWT(wt);
	findTAT(tat, wt);
	int stime[50], ctime[50];
	stime[0] = 0;
	ctime[0] = stime[0] + tat[0];
	for(int i=1; i<totalprocess; i++){
		stime[i] = ctime[i-1];
		ctime[i] = stime[i] + tat[i] - wt[i];
	}
	//display
	cout << "Processes\tBurst Time\tArrival Time\tPriority\tCompletion Time\tTurnaround Time\tWaiting time\n";
	for(int i=0; i<totalprocess; i++)
		cout << proc[i].pno << "\t\t" << proc[i].bt<<"\t\t" << proc[i].at <<"\t\t"<< proc[i].pr <<"\t\t"<< ctime[i] <<"\t\t"<< tat[i] <<"\t\t"<< wt[i] << endl; 
}

int main(){
	int at[] = {1,2,3,4,5};
	int bt[] = {3,5,1,7,4};
	int pr[] = {3,4,1,7,8};
	
	for(int i=0; i<totalprocess; i++){
		proc[i].at = at[i];
		proc[i].bt = bt[i];
		proc[i].pr = pr[i];
		proc[i].pno = i+1;
	}
	
	sort(proc, proc+totalprocess, comp);
	findgc();
	return 0;
}
