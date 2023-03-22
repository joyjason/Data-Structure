//¨t¯Å: ¸ê°T¤G¥Ò 10627134 ³\´Jµ¾ ¸ê°T¤G¥Ò 10627149 ³\?¾ô 
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <fstream>
#include <cstdlib> 
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
class Info{
	private :
       string rawR; // raw data of one record
       string cname; // college name
       string dname; // department name
       int sNO; // number of students
       int gNO; // number of graduates
       int tNO;// teachers
       int cnameID ;
       int dnameID ;
	public :
	  void newsch( string sch ) {
  		rawR = sch;
	  }
	  void print() {
		cout << rawR << "\n" <<endl;
	  }
	  string getDat(){
	  	return rawR;
	  }
	  string getcname(){
	  	return cname;
      }
      string getdname(){
	  	return dname;
      }
	  int getsNO(){
	  	return sNO;
	  }
	  int getgNO(){
	  	return gNO;
	  }
	  int setgNO( int max ){
	  	gNO = max;
	  }
	  int gettNO(){
	  	return tNO;
	  }
	  int getcnameID(){
	  	return cnameID;
	  }
	  int getdnameID(){
	  	return dnameID;
	  }
	  void DealDat( string data );
};

class schoollist{
    private:
  	  Info binary;
    public:
	  vector<Info> list;
	  vector<Info> list2;
	  void mission1( int &stop );
      void mission2( int &stop );
      void mission3( int &stop );
      void InputFile( string & name, string & fileNum );
      void saveFile( string & fileNum , char c, vector<Info> list );
      void SelectSort();
      void BubbleSort();
      void Mergesort( int front, int end, vector<Info> &temp );
      void Merge(int front, int mid, int end , vector<Info> &temp);
      int Partition( int front, int end );
      void Qsort( int front, int end );
      void Quicksort();
      int MaxDigit();
      void radixsort();
};

void saveFile( string &name , char c); // save all records into a file
void DealN( string &name ); // ³B²zÀÉ¦W
    
int main(int argc, char** argv) {
	schoollist schools;
    int command = -1;
    int stop = -1;
    while ( command != 0 ) {
	  cout << endl << "******** Sorting Algorithms ********";
      cout << endl << "* 0. QUIT *";
      cout << endl << "* 1. Selection sort Vs. Bubble sort*";
      cout << endl << "* 2. Merge sort Vs. Quick sort     *";
      cout << endl << "* 3. Radix sort                    *";
      cout << endl << "*************************************";
      cout << endl << "Input a choice(0, 1, 2, 3): ";
      cin >> command;
      if ( command == 0 ) return 1;
      else if ( command == 1 ) schools.mission1( stop );
      else if ( command == 2 ) schools.mission2( stop );
      else if ( command == 3 ) schools.mission3( stop );
      
      if ( stop == 0 ) return 0;
    } // while
	return 0;
}


void schoollist::mission1( int & stop ) { // Select_sort & Bubble_sort
	string name, fileNum;
	ifstream fin;
	int stime = 0,btime = 0;
	cout << "Select_sort & Bubble_sort: please input 501,502.....[0] quit: ";
	cin >> name;
	InputFile( name, fileNum );
	for ( int i = 0; i < list.size(); i++ ) list2.push_back(list[i]);
	SelectSort();
	saveFile( fileNum , 's' , list); // copy Data
	list.clear();
	
	BubbleSort();
	saveFile( fileNum , 'b' , list2 ); // copy Data
	list2.clear();
}


void schoollist::mission2( int & stop ) { // Merge_sort & Quick_sort
	string name, fileNum;
	ifstream fin;
	double Start, End;
	cout << "Merge_sort & Quick_sort: please input 501,502.....[0] quit: ";
	cin >> name;
	InputFile( name, fileNum );
	for ( int i = 0; i < list.size(); i++ ) list2.push_back(list[i]);
	
	vector<Info> temp;
	for ( int i = 0; i < list.size(); i++ ) temp.push_back(list[i]);
	
	Start = clock();
	Mergesort( 0, list.size() - 1, temp);//////// Merge Sort
	list.clear();
	for ( int i = 0; i < temp.size(); i++ ) list.push_back(temp[i]);
	End = clock();
	cout << (End - Start)  << endl;
	saveFile( fileNum , 'm' , list); // copy Data
	
	
	
	Quicksort();
	saveFile( fileNum , 'q' , list2 ); // copy Data
	list2.clear();
}

void schoollist::mission3( int & stop ) { // radixsort
	string name, fileNum;
	ifstream fin;
	double Start, End;
	cout << "RadixSort: please input 501,502.....[0] quit: ";
	cin >> name;
	InputFile( name, fileNum );	
	Start = clock();
	radixsort();
	End = clock();
	cout << (End - Start)  << endl;
	
	saveFile( fileNum , 'r' , list); // copy Data
	list.clear();
}

void schoollist::SelectSort(){
	double Start, End;
	int max = 0;
	Start = clock();
	for ( int i = 0; i < list.size(); i++ ) { // ©|¥¼±Æ§Ç¦¨¥\ªº¸ê®Æ¦C 
	    max = i;
		for ( int current = i; current < list.size() ; current++ ) { // ¥¿¦b¹ï¤ñ¤j¤p 
			if( list[current].getgNO() > list[max].getgNO() ) max = current;
		}	
		if ( i != max ) swap(list[i], list[max]); 
	}
	End = clock();
	cout << (End - Start)  << endl;
}
void schoollist::BubbleSort(){
	double Start, End;
	Start = clock();
	for ( int i = 0; i < list2.size(); i++ ) { // ©|¥¼±Æ§Ç¦¨¥\ªº¸ê®Æ¦C 
		for ( int current = 0; current + 1 < list2.size() - i ; current++ ) { // ¥¿¦b¹ï¤ñ¤j¤p 
			if( list2[current].getgNO() < list2[current + 1].getgNO() ) swap(list2[current], list2[current + 1]);
		}
    }
    End = clock();
	cout << (End - Start)  << endl;
}

void schoollist::Merge(int front, int mid, int end, vector<Info> &temp) {
	Info junk;
	junk.setgNO( 0 );
	vector<Info> Left(temp.begin()+front, temp.begin()+mid+1);
	vector<Info> Right(temp.begin()+mid+1, temp.begin()+end+1);
	
	int idxLeft = 0, idxRight = 0;
	
	Left.insert(Left.end(), junk );
	Right.insert(Right.end(), junk );
	for (int i = front; i <= end; i++) {
		if (Left[idxLeft].getgNO()>Right[idxRight].getgNO()) {
			temp[i] = Left[idxLeft];
			idxLeft++;
		} 
		else {
			temp[i] = Right[idxRight];
			idxRight++;
		}
		
	}
	
} 
void schoollist::Mergesort( int front, int end, vector<Info> &temp) {
	if (front>=end) return;
	int mid = (front + end)/2;
    Mergesort(front, mid, temp);
    Mergesort(mid+1, end, temp);
	Merge( front, mid, end, temp);
}

int schoollist::Partition( int front, int end ) {
    int pivot = 0 ;
    int i = 0 ;
 pivot = list2[end].getgNO(); //åŸºæº–é»ž 
    i = front - 1;
    for (int num = front; num < end; num++) {
        if (list2[num].getgNO() > pivot) {
            i++;
            swap(list2[i], list2[num]);
        }
    }
    i++;
    swap(list2[i], list2[end]);
    return i;
}

void schoollist::Qsort( int front, int end ) {
 int pivot = 0;
    if ( end > front ) {
        pivot = Partition( front, end );
        Qsort( front, pivot - 1 );
        Qsort( pivot + 1, end );
    }  
} 
void schoollist::Quicksort() {
 double Start, End;
 Start = clock();
 int front = 0;
 int end = 0 ;
 end = list2.size() - 1 ;
 Qsort( front, end );
 End = clock();
 cout << (End - Start)  << endl; 
 
}
int schoollist::MaxDigit(){
	int max = 0, digit = 0;
	for( int i = 0; i < list.size(); i++ ) {
	    if ( list[i].getgNO() > max ) max = list[i].getgNO();
	}
	for ( int i = 1; max/ i != 0 ; i = i * 10 ) {
		digit++;
	}
	return digit;
}
void schoollist::radixsort(){
    int d = MaxDigit(); //¸ê®Æ¸Ìªº³Ì¤j¦ì¼Æ 
    vector<Info> temp;
    for ( int i = 0; i < list.size(); i++ ) temp.push_back(list[i]);
    int *count = new int[10]; //­p¼Æ¾¹
    int i, j, k;
    int radix = 1;
    for(i = 1; i <= d; i++) //¶i¦æd¦¸±Æ§Ç
    {
        for(j = 0; j < 10; j++)
            count[j] = 0; //¨C¦¸¤À°t«e²MªÅ­p¼Æ¾¹
        for(j = 0; j < list.size(); j++)
        {
            //k = (data[j] / radix) % 10; //²Î­p¨C­Ó±í¤¤ªº¬ö¿ý¼Æ 
            k = ( list[j].getgNO() / radix) % 10; //²Î­p¨C­Ó±í¤¤ªº¬ö¿ý¼Æ 
            count[k]++;
        }
        for(j = 8; j >= 0; j--) count[j] = count[j + 1] + count[j]; //±Ntmp¤¤ªº¦ì¸m¨Ì¦¸¤À°tµ¹¨C­Ó±í
        for(j = list.size() - 1; j >= 0; j--) //±N©Ò¦³±í¤¤¬ö¿ý¨Ì¦¸¦¬¶°¨ìtmp¤¤
        {
            k = (list[j].getgNO() / radix) % 10;
            temp[count[k] - 1] = list[j];
            count[k]--;
        }
        
        list.clear();
        for ( int i = 0; i < temp.size(); i++ ) list.push_back(temp[i]);
        
        radix = radix * 10;
    }
    
}
void schoollist::saveFile( string & fileNum , char c, vector<Info> list) { // save all records into a file
  string num;
  if ( c == 's' ) num = "Select_sort" + fileNum + ".txt";
  else if ( c == 'b' ) num = "Bubble_sort" + fileNum + ".txt";
  else if ( c == 'm' ) num = "Merge_sort" + fileNum + ".txt";
  else if ( c == 'q' ) num = "Quick_sort" + fileNum + ".txt";
  else if ( c == 'r' ) num = "Radix_sort" + fileNum + ".txt";
  ofstream fout( num.c_str() );
  for ( int i = 0; i < list.size() ; i++ ) {
  	fout << list[i].getDat() << endl;
  }
}

void schoollist::InputFile( string & name , string & fileNum ) {
	ifstream fin;
	fileNum = name;
    DealN( name );// ³B²zINPUT
	fin.open( name.c_str() );
    while ( !fin ) {
    	cout << "### " << name << " does not exist! ###" << endl;
    	cout << "input 501,502.....[0] quit: " << endl;
		cin >> name;
		DealN( name );// ³B²zINPUT
		fin.open( name.c_str() );
	}
	string tempdat;
	for ( int n = 0; n < 3 ; n++ ) {// ¥h±¼¼ÐÃD
		getline(fin,tempdat);
	}
	int i = 0;
	while ( getline(fin,tempdat) ) { // ¨C¦¸Åª¤@¦æ
	    binary.DealDat( tempdat ) ;// input data to class
    	list.push_back(binary); // add data to last one;
	}

}

void DealN( string & name ){
	string temp;
    if ( name.at(0) >= '0' && name.at(0) <= '9' && name.at(1) >= '0' && name.at(1) <= '9' ) {
	  temp = "input" + name + ".txt";
	  name = temp;
    }

}
void Info::DealDat( string data ) {
	  	int tabcount = 0 ;
        int tabstart = -1 ;
        int tabend = 0 ;
        string infostring = "";
      	rawR = data;
	  	string temp;
	  	for ( int i = 0; tabcount < 10 ; i++ ) {
	  	  if ( data[i] == '\t' ) { // ±qrawRÅª¨ú¸ê°T(sNO.gNO.cname.gname) 
            tabcount++;
			tabend = i;
			if ( tabcount == 1 ) {
              for ( int k = tabstart + 1 ; k < tabend ; k++ ) infostring = infostring + data[k] ;
              cnameID = atoi( infostring.c_str() );
              infostring = "" ;
            } // if
	        else if ( tabcount == 2 ) {
              for ( int k = tabstart + 1 ; k < tabend ; k++ ) infostring = infostring + data[k] ;
              cname = infostring ;
              infostring = "" ;
            } // else if
            else if ( tabcount == 3 ) {
              for ( int k = tabstart + 1 ; k < tabend ; k++ ) infostring = infostring + data[k] ;
              dnameID = atoi( infostring.c_str() ) ;
              infostring = "" ;
            } // else if
            else if ( tabcount == 4 ) {
              for ( int k = tabstart + 1 ; k < tabend ; k++ ) infostring = infostring + data[k] ;
              dname = infostring ;
              infostring = "" ;
            } // else if
            else if ( tabcount == 7 ) {
              for ( int k = tabstart + 1 ; k < tabend ; k++ ) {
                if ( data[k] != '"' && data[k] != ',' )
                  infostring = infostring + data[k] ;
              } // for
              sNO = atoi( infostring.c_str() ) ;
              infostring = "" ;
            } // else if
            else if ( tabcount == 8 ) {
              for ( int k = tabstart + 1 ; k < tabend ; k++ ) {
                if ( data[k] != '"' && data[k] != ',' )
                  infostring = infostring + data[k] ;
              } // for
              tNO = atoi( infostring.c_str() ) ;
              infostring = "" ;
            } // else if
            else if ( tabcount == 9 ) {
              for ( int k = tabstart + 1 ; k < tabend ; k++ ) {
                if ( data[k] != '"' || data[k] != ',' )
                  infostring = infostring + data[k] ;
              } // for
              gNO = atoi( infostring.c_str() ) ;
              infostring = "" ;
            } // else if
            tabstart = tabend;
          } // if
      	}
	  } // DealDat


