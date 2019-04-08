#include<cstdlib>
#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;
int minDistance(int dist[], bool sptSet[],int V)
{
   // Initialize min value
   int min = INT_MAX, min_index;
  
   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;
  
   return min_index;
}
 int maxBenefit(int spl[],bool sptSet[],int V){
 	int max = INT_MIN, max_index;
  
   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && spl[v] >= max)
         max = spl[v], max_index = v;
   
   return max_index;
 
 }
int* dijkstra(int** graph,int ar[],int src,int V)
{    int *pred;
     pred=new int[V];
     bool sptSet[V]; 
	 for(int l=0;l<V;l++) pred[l]=-1;
	   for (int i = 0; i < V; i++)
        ar[i] = INT_MAX, sptSet[i] = false;
  
     
     ar[src] = 0;
  
     
     for (int count = 0; count < V-1; count++)
     {
       int u = minDistance(ar, sptSet,V);
  
      
       sptSet[u] = true;
  
       
       for (int v = 0; v < V; v++)
  
         if (!sptSet[v] && graph[u][v] && ar[u] != INT_MAX 
                                       && ar[u]+graph[u][v] < ar[v]){
			pred[v]=u;						   
            ar[v] = ar[u] + graph[u][v];
     }
 }
     return pred;
     }

 int Search(string a[],int n,string d){
 	if(d=="") return -1;
 	for(int i=0;i<n;i++){
 		if(a[i]==d) return i;
	 }
 		return -1;
	 }
 
 void printPath(string **ednm,int pred[],int src,int dst,string s[],int V){
 	stack<int> st;
 	int j=dst,i;
 	while(j>0){
 		st.push(j);
 		j=pred[j];
	 }
	 cout<<"Follows the follwing path:"<<endl;
	 int k=1;
	while(!st.empty()){
		i=st.top();
		st.pop();
		if(st.empty()) break;
		cout<<k<<".) "<<"From "<<s[i]<<" follows "<<ednm[i][st.top()]<<" to "<<s[st.top()]<<"."<<endl;
		k++;
	}
	 cout<<endl;
 }
 int searchD(int distance[],int b,int v,string s[]){
 	int x=0,i;
 	for(i=0;i<v && distance[i]>0;i++){
 		if(s[i]=="Macdonald" || s[i].find("cafe")!=string :: npos || s[i].find("bar")!=string :: npos || s[i].find("restaurant")!=string :: npos){
 			if(distance[i]<distance[x]) x=i;
		 }
	 }
	 return x;
 }
 int* dijkstraSF(int** sf,int ar[],int src,int V){
 	int *pred;
    pred=new int[V];
    for(int l=0;l<V;l++) pred[l]=-1;
     bool sptSet[V]; 
     for (int i = 0; i < V; i++){
        ar[i] = INT_MIN; sptSet[i] = false;
}
 
     ar[src] = 0;
  
 
     for (int count = 0; count < V-1; count++)
     {
       
       int u = maxBenefit(ar, sptSet,V);
  
       
       sptSet[u] = true;
  
       
       for (int v = 0; v < V; v++)
       
         if (!sptSet[v] && sf[u][v] && ar[u] != INT_MIN 
                                       && ar[u]+sf[u][v] > ar[v]){
			pred[v]=u;						   
            ar[v] = ar[u] + sf[u][v];
     }
 }
     return pred;
 }

int main()
{
	int v;
    //dijkstra(graph, 0);
    ifstream ifs("yes.txt");
 //   string line;
// cout<<"mn";
    int k=0;
    for(string line;getline(ifs,line);){
    	v=stoi(line);
    	//cout<<v;
    	break;
	}
	int **dist=new int*[v];
	for(int i=0;i<v;i++) dist[i]=new int[v];
    int **cost=new int*[v];
	for(int i=0;i<v;i++) cost[i]=new int[v]; 
	int **time=new int*[v];
	for(int i=0;i<v;i++) time[i]=new int[v]; 
	int **sf=new int*[v];
	for(int i=0;i<v;i++) sf[i]=new int[v];               
    int index,distance[v];
    int *pred;
	string s[v],src,dst,x="",y="";
	string **ednm=new string*[v];
	for(int i=0;i<v;i++) ednm[i]=new string[v];
	//cout<<"f";
	int ch=0;
    for(string line;getline(ifs,line);){
    	if(line=="$") break;
    	s[k]=line;
    	k++;
	}
	k=0;
	int l=0;
	for(string line;getline(ifs,line);){
		if(line=="\n" || line=="") break;
    	istringstream iss(line);
    	string buff;
    	while(iss>>buff){
    		ednm[k][l]=buff;
    		//cout<<ednm[k][l]<<endl;
    		l++;
		}
		l=0;
		k++;
 }
 k=0;
 l=0;
 //cout<<"kj";
	for(string line;getline(ifs,line);){
		if(line=="\n" || line=="") break;
    	stringstream ss1(line);
    	string buff;
    	while(ss1>>buff){
    		dist[k][l]=stoi(buff);
    		l++;
    //	cout<<buff<<endl;
		}
		l=0;
		k++;
	}
	
	k=0;
	l=0;
	for(string line;getline(ifs,line);){
		if(line=="\n" || line=="") break;
    	stringstream ss2(line);
    	string buff;
    	while(ss2>>buff){
    		cost[k][l]=stoi(buff);
    		//cout<<buff<<endl;
			l++;
		}
		l=0;
		k++;
	}
	k=0;
	l=0;
	for(string line;getline(ifs,line);){
		if(line=="\n" || line=="") break;
    	stringstream ss3(line);
    	string buff;
    	while(ss3>>buff){
    		time[k][l]=stoi(buff);
    //cout<<buff<<endl;
			l++;
		}
		l=0;
		k++;
	}
	k=0;
	l=0;
	for(string line;getline(ifs,line);){
		if(line=="\n" || line=="") break;
    	stringstream ss4(line);
    	string buff;
    	while(ss4>>buff){
    		sf[k][l]=stoi(buff);
    		//cout<<buff<<endl;
			l++;
		}
		l=0;
		k++;
	}	
	ifs.close();
	cout<<"\n \t Welcome our valuable customer "<<endl;
	cout<<"Places we Covered:"<<endl;
	for(int i=0;i<v;i++){
		cout<<(i+1)<<".) "<<s[i]<<endl;
	}
	while(ch>=0){
		string ui;
		cout<<"Do you want to continue(Yes/No)?"<<endl;
		cin>>ui;
		if(ui=="No") return 0;
		cout<<"\n Enter source place: ";
		cin>>src;
		cout<<"Enter destination place: ";
		cin>>dst;
		int b=Search(s,v,src);
		int d=Search(s,v,dst);
	//	cout<<b<<" "<<d<<endl;
		cout<<"\n Enter your highest priority for finding path :"<<endl;
		cout<<" 1.Distance \n 2.Time \n 3.Cost(want to prefer cab or bus etc.) \n 4.Want to stay at some intermidiatory place \n 5.Special Factor like want to prefer natural beautiful path etc.";
		cout<<"\n \n  Please select an option or -1 to exit:";
		cin>>ch;
		if(ch<0) exit(0);
		switch(ch){
			case 1: //cout<<"f"<<endl;
			        pred=dijkstra(dist,distance,b,v);
			        printPath(ednm,pred,b,d,s,v);
			        cout<<"Distance of your trip is: "<<distance[d]<<" Kms. "<<endl;
			        break;
			case 2: pred=dijkstra(time,distance,b,v);
			        printPath(ednm,pred,b,d,s,v);
			        cout<<"Estimated Time of your Trip is approx : "<<distance[d]<<" min "<<endl;
			        break;
			case 3: 
			        pred=dijkstra(cost,distance,b,v);
			        printPath(ednm,pred,b,d,s,v);
			        cout<<"Estimated cost of your planned trip is: Rs. "<<distance[d]<<endl;
			        break;
			case 4: {
				int t=0;    
				cout<<" Do you want to go to a, (1) specified place which you are certain of or, \n (2) you just want to hang out at some cafe/bar/restaurant?"<<endl;
				while(t!=1 && t!=2){
				cout<<"Enter your choice: ";	
				cin>>t;
				if(t!=1 && t!=2)
				   cout<<endl<<"Please enter valid choice.";
			}
			if(t==1){
			  cout<<endl<<" Enter 1st place:";
			  cin>>x;
			  cout<<endl<<"Enter 2nd place or \"No\" to skip:";
			  cin>>y;
			  if(y=="No") y="";
			  int d1=Search(s,v,x);
			  int d2=Search(s,v,y);
		      pred=dijkstra(time,distance,b,v);
		      cout<<"Way to "<<s[d1]<<endl;
		      printPath(ednm,pred,b,d1,s,v);
		      int temp1=distance[d1],temp2=0,temp3;
		      if(d2>=0){
		      pred=dijkstra(time,distance,d1,v);
		      cout<<"Way to "<<s[d2]<<endl;
		      printPath(ednm,pred,d1,d2,s,v);
		     temp2=distance[d2];
		  }
		    else d2=d1;
		      pred=dijkstra(time,distance,d2,v);
		      cout<<"Way to "<<s[d]<<endl;
		      printPath(ednm,pred,d2,d,s,v);
		      temp3=distance[d];
		      cout<<"Estimated time of your trip is: "<<(temp1+temp2+temp3)<<" min "<<endl;
		     
		  }
			else{
				pred=dijkstra(time,distance,b,v);
				index=searchD(distance,b,v,s);
				cout<<"Way to "<<s[index]<<endl;
				printPath(ednm,pred,b,index,s,v);
				int temp1=distance[index],temp2;
				pred=dijkstra(time,distance,index,v);
				cout<<"Way to "<<s[d]<<endl;
				printPath(ednm,pred,index,d,s,v);
				temp2=distance[d];
				cout<<"Estimated time of your trip is: "<<(temp1+temp2)<<" min "<<endl;
			}
				break;
			}
			case 5: 
			        pred=dijkstraSF(sf,distance,b,v); 
			        printPath(ednm,pred,b,d,s,v);
			        break;
			default: cout<<"Please enter legal choice: ";
		}
}
	
delete[] pred;
for(int i=0;i<v;i++) delete[] dist;
delete[] dist;   

for(int i=0;i<v;i++) delete[] cost;
delete[] cost;

for(int i=0;i<v;i++) delete[] time;
delete[] time;

for(int i=0;i<v;i++) delete[] sf;
delete[] sf;

for(int i=0;i<v;i++) delete[] ednm;
delete[] ednm;

return 0;
}
