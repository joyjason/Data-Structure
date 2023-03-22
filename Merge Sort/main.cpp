//系級: 資訊二甲 10627134 許寓翔 資訊二甲 10627149 許?僑 
#include <iostream>
#include <vector>
#include <string.h>
#include <fstream>
#include <cstdlib> 
#include <time.h>
using namespace std;


struct Allstat{
    char putID[10] ;  //發訊者ID 
    char getID[10] ;  //收訊者ID 
    float weight ;  //量化權重 
};



class ExternalSort{
	private :
		fstream file;// INPUTFILE的宣告 
	public :
	    Allstat stat;
  	    vector<Allstat> list;
  	    void SelectSort();//處理內部排序的200筆資料 
  	    void InputFile();
  	    void Mission1();
  	    void Mission2();
  	    void InsertionSort();
  	    void ExternalMerge();
};

   
int main(int argc, char** argv) {
    int command = -1;
    ExternalSort Ext;
    while ( command != 0 ) {
	  cout << endl << "******* ExternalSort *******";
      cout << endl << "* 0. QUIT                  *";
      cout << endl << "* 1. ExternalSort          *";
      cout << endl << "* 2. Primary index         *";
      cout << endl << "****************************";
      cout << endl << "Input a choice(0, 1, 2): ";
      
      cin >> command;
      if ( command == 0 ) return 0;
      else if ( command == 1 ) Ext.Mission1();
      else if ( command == 2 ) Ext.Mission2(); 
    } // while
	return 0;
}

void ExternalSort::Mission1() {
	InsertionSort();//處理內部排序 
	ExternalMerge();//合併外部排序 
}

void ExternalSort::InsertionSort(){
	fstream outFile;// OUTPUTFILE的宣告 
	int stNo = 0;
	string name;
	cout << "Input a file number,[0] quit: ";
	cin >> name;//檔案名稱 
	if ( !name.compare( "0" ) ) return; 
	file.open( ( "pairs" + name + ".bin" ).c_str(), fstream::in | fstream::binary);//開啟檔案 
    if ( !file.is_open() ) return; // no such file
	//此時檔案已開成 
	
	if ( file.is_open() ) {
		file.seekg( 0, file.end );
		stNo = file.tellg() / sizeof(stat);
		file.seekg( 0, file.beg );
		int all = stNo / 200, index = -1;
		for ( int i = 0; i < stNo; ) {
		    for ( int j = 0; j < 200 ; j++ ) {//一次只讀200筆資料 以應付記憶體不足的可能 
			    file.read((char *)& stat, sizeof(stat) );
			    list.push_back( stat );
			    i++;
		    }
		    index++;
		    SelectSort();
		    
		    // 下一行 寫成檔案 EX: sorted501_94_0  
		    char alls[3];
		    char indexs[3];
			sprintf(alls, "%d", all);
			sprintf(indexs, "%d", index);
		    outFile.open( ( "sorted" + name + "_" + alls + "_" + indexs + ".bin" ).c_str(), fstream::out | fstream::binary);//寫入檔案 
		    for ( int num = 0; num < list.size(); num++ ) {
		    	outFile.write((char *)& list[num], sizeof(list[num])) ;
			}
		    list.clear();
		    outFile.close();
		}
		
	}
	file.close();
}

void ExternalSort::ExternalMerge(){
	

}

void ExternalSort::Mission2(){
	return ;
} 

void ExternalSort::InputFile() {
	int stNo = 0;
	string name;
	cout << "Input a file number,[0] quit: ";
	cin >> name;//檔案名稱 
	if ( !name.compare( "0" ) ) return; 
	file.open( ( "pairs" + name + ".bin" ).c_str(), fstream::in | fstream::binary);//開啟檔案 
    if ( !file.is_open() ) return; // no such file
	//此時檔案已開成 
	if ( file.is_open() ) {
		file.seekg( 0, file.end );
		stNo = file.tellg() / sizeof(stat);
		file.seekg( 0, file.beg );
		for (int i = 0; i < stNo; i++ ) {
			file.read((char *)& stat, sizeof(stat));
			list.push_back( stat );
		}
	}
	file.close();
} 

void ExternalSort::SelectSort(){
	int max = 0;
	for ( int i = 0; i < list.size(); i++ ) { // 尚未排序成功的資料列 
	    max = i;
		for ( int current = i; current < list.size() ; current++ ) { // 正在對比大小 
			if( list[current].weight > list[max].weight ) max = current;
		}	
		if ( i != max ) swap(list[i], list[max]); 
	}
}
