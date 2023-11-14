#include <iostream>
#include <stdlib.h>

using namespace std;

class Process{
	int id, bt, at, ct, tat, wt;
	public:
	void input(Process *p, int n){
		for(int i=0; i<n; i++){
			cout << "\nEnter arrival time for process :";
			cin >> p[i].at;
			cout << "\nEnter burst time for process "; 
			cin >> p[i].bt;
			p[i].id = i+1;
		}
	}
	//Calculating CT, TAT and WT:
	void calc(Process *p, int n){
		int sum=0, t;
		sum += p[0].at;
		for(int i=0; i<n; i++){
			sum += p[i].bt;
			p[i].ct = sum;
			p[i].tat = p[i].ct - p[i].at;
			p[i].wt = p[i].tat - p[i].bt;
			if(i+1!=n && p[i+1].at>sum){ // if System is left idle because processes have not arrived yet
				t = p[i+1].at - sum;
				sum += t;
			}
		}
	}
	//Sorting process w.r.t. arrival times
	void sort(Process *p, int n){
		int i, j, temp;
		for(i=0; i<n; i++)
			for(j=0; j<n-1-i; j++)
				if(p[j].at > p[j+1].at){
					temp = p[j].bt; //Swap BT
					p[j].bt = p[j+1].bt;
					p[j+1].bt = temp;
					
					temp = p[j].at; //Swap AT
					p[j].at = p[j+1].at;
					p[j+1].at = temp;
					
					temp = p[j].id; //Swap ID
					p[j].id = p[j+1].id;
					p[j+1].id = temp;
				}
	}
	void display(Process *p, int n){
		cout << "Processes\tBurst Time\tArrival Time\tCompletion Time\tTurnaround Time\tWaiting time\n";
		for(int i=0; i<n; i++){
			cout<< p[i].id << "\t\t" << p[i].bt << "\t\t" << p[i].at<< "\t\t" << p[i].ct << "\t\t" << p[i].tat << "\t\t" << p[i].wt << endl;
		}
	}
};

int main(){
	int n;
	cout << "Enter total processes to work with: ";
	cin >> n;
	Process *p = new Process[n];
	Process f;
	f.input(p, n);
	f.sort(p, n);
	f.calc(p, n);
	f.display(p, n);
	return 0;
}
