
using namespace std;
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "library.h"

/*fxn defs*/

int readCounty(ifstream& fin, County arr[],int& size,int& numofcounties){
  numofcounties=0;
  for(int i=0;!fin.eof() && i<size;i++){
getline(fin,arr[i].name,',');
fin>>arr[i].startPop;
fin.ignore();
fin>>arr[i].endPop;
fin.ignore();
numofcounties++;
  }
  return numofcounties;
}

void printCounty(const County arr[],int& numofcounties){
cout<<endl<<"*Based on data from US Census Bureau*"<<endl<<endl;
cout<<fixed<<showpoint<<setw(20);
cout<<left<<"County Name"<<setw(20)<<"1969 Population"<<setw(20)<<"2019 Population"<<endl<<endl;

for(int i=0;i<numofcounties;i++){
  cout<<fixed<<showpoint<<setw(20)<<setprecision(0);
  cout<<left<<arr[i].name<<setw(20)<<int(arr[i].startPop)<<setw(20)<<int(arr[i].endPop)<<endl;
}

  
  float l1969,l2019,s1969,s2019,tot1969,tot2019,grewMostCa,grewLeastCa,growthPercentLeast,growthPercentMost;

  string nl1969,nl2019,ns1969,ns2019,ngrewMostCa,ngrewLeastCa;

l1969=0;l2019=0;s1969=9999999999;s2019=9999999999;tot1969=0;tot2019=0;grewMostCa=0;grewLeastCa=0;growthPercentLeast=0;growthPercentMost=0;

for(int i=0;i<numofcounties;i++){

  if(l1969<arr[i].startPop){
    nl1969=arr[i].name;
    l1969=arr[i].startPop;
  }
}
for(int i=0;i<numofcounties;i++){
  if(l2019<arr[i].endPop){
    nl2019=arr[i].name;
    l2019=arr[i].endPop;
  }
}
for(int i=0;i<numofcounties;i++){
  if(s1969>arr[i].startPop){
    ns1969=arr[i].name;
    s1969=arr[i].startPop;
  }
}
for(int i=0;i<numofcounties;i++){
  if(s2019>arr[i].endPop){
    ns2019=arr[i].name;
    s2019=arr[i].endPop;
  }
}
growthPercentMost=-99999999;
for(int i=0;i<numofcounties;i++){
  if(((arr[i].endPop-arr[i].startPop)/arr[i].startPop)>growthPercentMost){
    ngrewMostCa=arr[i].name;
    grewMostCa=(arr[i].endPop-arr[i].startPop);
    growthPercentMost = ((arr[i].endPop-arr[i].startPop)/arr[i].startPop);
  }
}
growthPercentLeast=99999999;
for(int i=0;i<numofcounties;i++){
 if(((arr[i].endPop-arr[i].startPop)/arr[i].startPop)<growthPercentLeast){
    ngrewLeastCa=arr[i].name;
    grewLeastCa=(arr[i].endPop-arr[i].startPop);
    growthPercentLeast = ((arr[i].endPop-arr[i].startPop)/arr[i].startPop);
  }
}
  for(int i=0;i<numofcounties;i++){
  tot1969+=arr[i].startPop;
  tot2019+=arr[i].endPop;
}

cout<<endl;
cout<<"There are "<< numofcounties+1<<" counties in California."<<endl;
cout<<"The Largest County in California in 1969 is: "<<nl1969<<" with "<<int(l1969)<<" people."<<endl;
cout<<"The Largest County in California in 2019 is: "<<nl2019<<" with "<<int(l2019)<<" people."<<endl;
cout<<"The Smallest County in California 1969 is: "<<ns1969<<" with "<<int(s1969)<<" people."<<endl;
cout<<"The Smallest County in California 2019 is: "<<ns2019<<" with "<<int(s2019)<<" people."<<endl;
cout<<"The County that grew the most in California from 1969-2019 is: "<<ngrewMostCa<<" by "<<int(grewMostCa)<<" people"<<" or "<<setprecision(2)<<growthPercentMost*100<<"% of the 1969 population."<<endl;
cout<<"The County that grew the least in California from 1969-2019 is: "<<ngrewLeastCa<<" by "<<int(grewLeastCa)<<" people "<<" or "<<setprecision(2)<<growthPercentLeast*100<<"% of the 1969 population."<<endl;
cout<<setprecision(0)<<"The total population in California in 1969 is: "<<int(tot1969)<<" people."<<endl;
cout<<setprecision(0)<<"The total population in California in 2019 is: "<<int(tot2019)<<" people."<<endl;
cout<<"From 1969-2019 California grew by "<<int(tot2019-tot1969)<<" people or "<<setprecision(2)<<((tot2019-tot1969)/tot1969)*100<<"% of the 1969 population."<<endl;
}

void printSearch(const County arr[],int& numofcounties){
  
cout<<endl<<"*Based on data from US Census Bureau*"<<endl<<endl;
cout<<fixed<<showpoint<<setw(20);
cout<<left<<"County Name"<<setw(20)<<"1969 Population"<<setw(20)<<"2019 Population"<<endl<<endl;

for(int i=0;i<numofcounties;i++){
  cout<<fixed<<showpoint<<setw(20)<<setprecision(0);
  cout<<left<<arr[i].name<<setw(20)<<int(arr[i].startPop)<<setw(20)<<int(arr[i].endPop)<<endl;
}

  
  float l1969,l2019,s1969,s2019,tot1969,tot2019,grewMostCa,grewLeastCa,growthPercentLeast,growthPercentMost;

  string nl1969,nl2019,ns1969,ns2019,ngrewMostCa,ngrewLeastCa;

l1969=0;l2019=0;s1969=9999999999;s2019=9999999999;tot1969=0;tot2019=0;grewMostCa=0;grewLeastCa=0;growthPercentLeast=0;growthPercentMost=0;

for(int i=0;i<numofcounties;i++){

  if(l1969<arr[i].startPop){
    nl1969=arr[i].name;
    l1969=arr[i].startPop;
  }
}
for(int i=0;i<numofcounties;i++){
  if(l2019<arr[i].endPop){
    nl2019=arr[i].name;
    l2019=arr[i].endPop;
  }
}
for(int i=0;i<numofcounties;i++){
  if(s1969>arr[i].startPop){
    ns1969=arr[i].name;
    s1969=arr[i].startPop;
  }
}
for(int i=0;i<numofcounties;i++){
  if(s2019>arr[i].endPop){
    ns2019=arr[i].name;
    s2019=arr[i].endPop;
  }
}

  growthPercentMost=-99999999;
for(int i=0;i<numofcounties;i++){
  if(((arr[i].endPop-arr[i].startPop)/arr[i].startPop)>growthPercentMost){
    ngrewMostCa=arr[i].name;
    grewMostCa=(arr[i].endPop-arr[i].startPop);
    growthPercentMost = ((arr[i].endPop-arr[i].startPop)/arr[i].startPop);
  }
  growthPercentLeast=99999999;
}
for(int i=0;i<numofcounties;i++){
 if(((arr[i].endPop-arr[i].startPop)/arr[i].startPop)<growthPercentLeast){
    ngrewLeastCa=arr[i].name;
    grewLeastCa=(arr[i].endPop-arr[i].startPop);
    growthPercentLeast = ((arr[i].endPop-arr[i].startPop)/arr[i].startPop);
  }
}
  for(int i=0;i<numofcounties;i++){
  tot1969+=arr[i].startPop;
  tot2019+=arr[i].endPop;
}

cout<<endl;
cout<<"There are "<< numofcounties<<" counties in searched counties."<<endl;
cout<<"The Largest County in searched counties in 1969 is: "<<nl1969<<" with "<<int(l1969)<<" people."<<endl;
cout<<"The Largest County in searched counties in 2019 is: "<<nl2019<<" with "<<int(l2019)<<" people."<<endl;
cout<<"The Smallest County in searched counties 1969 is: "<<ns1969<<" with "<<int(s1969)<<" people."<<endl;
cout<<"The Smallest County in searched counties 2019 is: "<<ns2019<<" with "<<int(s2019)<<" people."<<endl;
cout<<"The County that grew the most in searched counties from 1969-2019 is: "<<ngrewMostCa<<" by "<<int(grewMostCa)<<" people"<<" or "<<setprecision(2)<<growthPercentMost*100<<"% of the 1969 population."<<endl;
cout<<"The County that grew the least in searched counties from 1969-2019 is: "<<ngrewLeastCa<<" by "<<int(grewLeastCa)<<" people "<<" or "<<setprecision(2)<<growthPercentLeast*100<<"% of the 1969 population."<<endl;
cout<<setprecision(0)<<"The total population in searched counties in 1969 is: "<<int(tot1969)<<" people."<<endl;
cout<<setprecision(0)<<"The total population in searched counties in 2019 is: "<<int(tot2019)<<" people."<<endl;
cout<<"From 1969-2019 the searched counties grew by "<<int(tot2019-tot1969)<<" people or "<<setprecision(2)<<((tot2019-tot1969)/tot1969)*100<<"% of the 1969 population."<<endl;
}




void searchByPop(const County arr1[],County arr2[],int& answer1,int& answer2,float numkey, int& numofcounties, int& index){
  
  switch (answer1){
    case 1:
    switch (answer2){
    case 1:
      for(int i=0;i<numofcounties;i++){
        if(arr1[i].startPop>=numkey){
          arr2[index]=arr1[i];
          index++;
        }
      }
      
    break;

    case 2:
for(int i=0;i<numofcounties;i++){
  if(arr1[i].startPop<=numkey){
    arr2[index]=arr1[i];
    index++;
  }
}

    break;
    
    default:
    cout<<endl<<"ERROR: Enter a valid number for larger or smaller"<<endl;
    
  }

    break;

    case 2:
    switch (answer2){
    case 1:
    for(int i=0;i<numofcounties;i++){
  if(arr1[i].endPop>=numkey){
    arr2[index]=arr1[i];
    index++;
  }
}

    break;

    case 2:
for(int i=0;i<numofcounties;i++){
  if(arr1[i].endPop<=numkey){
    arr2[index]=arr1[i];
    index++;
  }
}

    break;
    
    default:
    cout<<endl<<"ERROR: Enter a valid number for larger or smaller"<<endl;
    
  }

    break;

    default:
    cout<<endl<<"ERROR: Enter a valid number for 1969 or 2019"<<endl;
    
  }
  
}

void searchByWord(const County arr1[],County arr2[],int& numofcounties,string wordkey,int& index){
  for(int i=0;i<numofcounties;i++){
  if (arr1[i].name.find(wordkey) != string::npos){
arr2[index]=arr1[i];
index++;
  }
  
  }
}


void addCounty( County arr1[], int& numofcounties,int& size, County& newCounty){
  int pos,count;
  count=0;

for(int i=numofcounties;i>=0&&i<=numofcounties&&count!=1;i--){
if (arr1[i].name<newCounty.name){
  pos=i+1;
  count++;
}
}
numofcounties++;
size++;

//exited, segentation fault error thrown after loop below! why???
for(int i=size;i>=pos;i--){
  arr1[i]=arr1[i-1];
}
  arr1[pos]=newCounty;
}

void deleteCounty( County arr1[], int& numofcounties,int& size, County& newCounty){
  cout<<endl<<"Enter the name of the county you wish to remove: ";
  getline(cin,newCounty.name);
  int pos,count;
  count=0;
for(int i=numofcounties;i>=0&&i<=numofcounties&&count!=1;i--){
if (arr1[i].name<newCounty.name){
  pos=i+1;
  count++;
}
}
for(int i=pos;i<=size-2;i++){
  arr1[i]=arr1[i+1];
}
  size--;
  numofcounties--;
}
void getCounty(County& newCounty){
   cout<<endl<<"Enter the name of the county: ";
  getline(cin,newCounty.name);
  cout<<endl<<"Enter the population of the county in 1969: ";
  cin>>newCounty.startPop;
  cin.ignore();
  cout<<endl<<"Enter the population of the county in 2019: ";
  cin>>newCounty.endPop;
  cin.ignore();
}
