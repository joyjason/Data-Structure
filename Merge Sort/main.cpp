//�t��: ��T�G�� 10627134 �\�J�� ��T�G�� 10627149 �\?�� 
#include <iostream>
#include <vector>
#include <string.h>
#include <fstream>
#include <cstdlib> 
#include <time.h>
using namespace std;


struct Allstat{
    char putID[10] ;  //�o�T��ID 
    char getID[10] ;  //���T��ID 
    float weight ;  //�q���v�� 
};



class ExternalSort{
	private :
		fstream file;// INPUTFILE���ŧi 
	public :
	    Allstat stat;
  	    vector<Allstat> list;
  	    void SelectSort();//�B�z�����ƧǪ�200����� 
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
	InsertionSort();//�B�z�����Ƨ� 
	ExternalMerge();//�X�֥~���Ƨ� 
}

void ExternalSort::InsertionSort(){
	fstream outFile;// OUTPUTFILE���ŧi 
	int stNo = 0;
	string name;
	cout << "Input a file number,[0] quit: ";
	cin >> name;//�ɮצW�� 
	if ( !name.compare( "0" ) ) return; 
	file.open( ( "pairs" + name + ".bin" ).c_str(), fstream::in | fstream::binary);//�}���ɮ� 
    if ( !file.is_open() ) return; // no such file
	//�����ɮפw�}�� 
	
	if ( file.is_open() ) {
		file.seekg( 0, file.end );
		stNo = file.tellg() / sizeof(stat);
		file.seekg( 0, file.beg );
		int all = stNo / 200, index = -1;
		for ( int i = 0; i < stNo; ) {
		    for ( int j = 0; j < 200 ; j++ ) {//�@���uŪ200����� �H���I�O���餣�����i�� 
			    file.read((char *)& stat, sizeof(stat) );
			    list.push_back( stat );
			    i++;
		    }
		    index++;
		    SelectSort();
		    
		    // �U�@�� �g���ɮ� EX: sorted501_94_0  
		    char alls[3];
		    char indexs[3];
			sprintf(alls, "%d", all);
			sprintf(indexs, "%d", index);
		    outFile.open( ( "sorted" + name + "_" + alls + "_" + indexs + ".bin" ).c_str(), fstream::out | fstream::binary);//�g�J�ɮ� 
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
	cin >> name;//�ɮצW�� 
	if ( !name.compare( "0" ) ) return; 
	file.open( ( "pairs" + name + ".bin" ).c_str(), fstream::in | fstream::binary);//�}���ɮ� 
    if ( !file.is_open() ) return; // no such file
	//�����ɮפw�}�� 
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
	for ( int i = 0; i < list.size(); i++ ) { // �|���ƧǦ��\����ƦC 
	    max = i;
		for ( int current = i; current < list.size() ; current++ ) { // ���b���j�p 
			if( list[current].weight > list[max].weight ) max = current;
		}	
		if ( i != max ) swap(list[i], list[max]); 
	}
}
