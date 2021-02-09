using namespace std;
/*struct*/
struct County {
	string name;
	float startPop;
	float endPop;
};

/*prototypes*/
int readCounty(ifstream&, County arr[], int&, int&);
void printCounty(const County arr[], int&);
void printSearch(const County arr[], int&);
void searchByPop(const County arr1[], County arr2[], int&, int&, float numkey, int&, int&);
void searchByWord(const County arr1[], County arr2[], int&, string wordkey, int&);
void addCounty(County arr1[], int&, int&, County&);
void deleteCounty(County arr1[], int&, int&, County&);
void getCounty(County& newCounty); #pragma once
