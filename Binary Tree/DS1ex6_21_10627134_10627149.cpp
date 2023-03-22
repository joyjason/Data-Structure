//系級: 資訊二甲 10627134 許寓翔 資訊二甲 10627149 許?橋 
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <fstream>
#include <cstdlib> 
using namespace std;
class Info{
	private :
       string rawR; // raw data of one record
       int ID;
       string Name; // college name
       string Type1;
       int Total;
       int HP;
       int Atk;
       int Def;
       int SpAtk;
       int SpDef;
       int Speed;
       int Gen;
       string Leg;
	public :
	  void newsch( string sch ) {
  		rawR = sch;
	  }
	  string getDat(){
	  	return rawR;
	  }
	  int getID(){
      	return ID;
	  }
      string getName(){
	  	return Name;
      }
      string getType1(){
	  	return Type1;
      }
      int getTotal(){
      	return Total;
	  }
	  int getHP(){
      	return HP;
	  }
	  int getAtk(){
      	return Atk;
	  }
	  int getDef(){
      	return Def;
	  }
	  void Printsix( int i ) {
	  	cout << "[ " << i << "]	"<< getID() << "	" <<  getName() << "				" <<  getType1() << "		" 
		  <<  getHP() << "	" <<  getAtk() << "	" <<  getDef() << endl;
	  }
	  void Printseven ( int i ) {
	  	cout << "[ " << i << "]	"<< getID() << "	" <<  getName() << "				" << getTotal() << "	" <<  getType1() << "		" 
		  <<  getHP() << "	" <<  getAtk() << "	" <<  getDef() << endl;
	  }
	  void DealDat( string data );
};

struct BST{
	vector<Info> Cur;
	BST *Left;
	BST *Right;
	BST *Last;
};

class Pokemon{
    private:
  	  Info binary;
  	  
    public:
	  vector<Info> list;
	  void mission1( BST *&tree );
      void mission2( BST *&tree );
      void mission3( BST *&tree );
      int findheight( BST *&tree );
      void traverse( BST *&tree, int num ,int &visit);
      void CreateTree( BST *&tree );
      void InputFile( string & name, string & fileNum );
};

void saveFile( string &name , char c); // save all records into a file
void DealN( string &name ); // 處理檔名
   
int main(int argc, char** argv) {
	Pokemon Pok;
	BST *tree = NULL; 
    int command = -1;
    while ( command != 0 ) {
	  cout << endl << "*** Binary Search Tree on Pokemon ***";
      cout << endl << "* 0. QUIT *";
      cout << endl << "* 1. Read one file to build BST     *";
      cout << endl << "* 2. Threshold search on one column *";
      cout << endl << "* 3. Delete the max on one column   *";
      cout << endl << "*************************************";
      cout << endl << "Input a choice(0, 1, 2, 3): ";
      cin >> command;
      if ( command == 0 ) return 1;
      else if ( command == 1 ) Pok.mission1( tree );
      else if ( command == 2 ) Pok.mission2( tree );
      else if ( command == 3 ) Pok.mission3( tree );
    } // while
	return 0;
}

void Pokemon::mission1( BST *&tree ) { // Select_sort & Bubble_sort
	string name, fileNum;
	ifstream fin;
	int height = 1,max = 1;
	cout << "Input a file number,[0] quit: ";
	cin >> name;
	InputFile( name, fileNum );
	CreateTree( tree );
}

int curnum = 1;
void Pokemon::mission2( BST *&tree ) { 
    int visit = 0,largest = 0;
    if ( tree == NULL ) {
    	cout << "ERROR :請先使用任務1" << endl; 
    	return ;
	}
	BST *first = tree;
	BST *temp = tree;
	int height = 1,max = 1,num = 0;
	
	
	
	
	
	while( tree->Right != NULL ) tree = tree->Right;//輸入不能超過largest的值 
	largest = tree->Cur[0].getHP();//輸入不能超過largest的值 
	tree = first;//輸入不能超過largest的值 
	cout << "Input a positive num[1 ~ "  << largest << "] = " ; 
	cin >> num;
	if ( num > largest && num > 0) {
		cout << "超過範圍,請重新執行任務2" << endl; 
		return;
	}
	
	
	
	
	cout << "	#	Name				Total	Type1		HP	Attack	Defence" << endl;
	while ( tree != NULL ) {
		if ( num > tree->Cur[0].getHP() ) {
		  tree = tree->Right;
		  visit++;
		}
		else if ( num <= tree->Cur[0].getHP() ) {
			traverse ( tree,num,visit );
			break;
		}
    }
    curnum = 1;
	tree = first;
	cout << "Number of visited nodes = " << visit << endl;
}

void Pokemon::mission3( BST *&tree ){
	int height = 0;
	if ( tree == NULL ) {
    	cout << "ERROR :請先使用任務1" << endl; 
    	return;
	}
	BST *first = tree;
	while( tree->Right != NULL ) tree = tree->Right;
	cout << "#	Name	Type1	Type2	Total	HP	Attack	Defense	Sp.Atk	Sp.Def	Speed	Generation	Legendary" << endl;
	if ( tree->Cur.size() > 1 ) {
	  cout << tree->Cur[0].getDat() << endl ;
	  tree->Cur.erase( tree->Cur.begin() );	
	}
	else if ( tree == first ) {//最大值為樹的頂端時 
		cout << tree->Cur[0].getDat() << endl ;
		first = first->Left;
		delete tree;
	}
	else if ( tree->Left == NULL ) {//左邊無節點 
		cout << tree->Cur[0].getDat() << endl ;
		tree->Last->Right = NULL;
		delete tree;
	}
	else if ( tree->Left != NULL ) {
		cout  << tree->Cur[0].getDat() << endl ;
		tree->Last->Right = tree->Left;
		tree->Left->Last = tree->Last;
		delete tree;
	}
	tree = first;
	height = findheight( tree ) ;
	cout << "HP tree height = " << height << endl;
}

int Pokemon::findheight( BST *&tree ) {
  if ( tree == NULL )
    return 0 ;
  else if ( findheight(tree->Left) > findheight(tree->Right)) return findheight(tree->Left) + 1;
  else return findheight(tree->Right) + 1;
}
void Pokemon::traverse ( BST *&tree, int num , int &visit){
	
	if ( tree != NULL ) {
		if ( num < tree->Cur[0].getHP()  ){
			traverse ( tree->Right ,num ,visit);
			for ( int i = 0; i < tree->Cur.size(); i++ ) {
		      tree->Cur[i].Printseven( curnum );
		      curnum++;
		    }
		    traverse ( tree->Left ,num ,visit);
		    visit++;
		}
		else if ( num == tree->Cur[0].getHP()  ){
			traverse ( tree->Right ,num ,visit);
			for ( int i = 0; i < tree->Cur.size(); i++ ) {
		      tree->Cur[i].Printseven( curnum );
		      curnum++;
		    }
		    visit++;
		}
	    else if ( num > tree->Cur[0].getHP() ) {
	    	traverse ( tree->Right ,num ,visit);
	    	visit++;
		}
	}
}
void Pokemon::CreateTree( BST *&tree ) {
	int height = 1,max = 1;
	BST *temp = new BST;//用來記錄當前上一筆資料 
	tree = new BST;
	tree->Cur.push_back(list[0]);// 第一筆 
	tree->Left = NULL;// 第一筆 
	tree->Right = NULL;// 第一筆 
	BST *first = tree;// 第一筆 
	cout << "	#	Name				Type1		HP	Attack	Defence" << endl;
	list[1].Printsix( 1 );//印前六筆資料 
	for ( int i = 1; i < list.size(); i++ ) {// 建立二元樹
	  list[i].Printsix( i + 1 );//印前六筆資料 
	  while ( tree != NULL ) {//找到最底端 
	    temp = tree;//紀錄為上一筆 
		if ( list[i].getHP() > tree->Cur[0].getHP() ) tree = tree->Right; 
		else if ( list[i].getHP() < tree->Cur[0].getHP()) tree = tree->Left;
		else if ( list[i].getHP() == tree->Cur[0].getHP() ) break;// 相等 
		height++;
      }
      
      if ( tree == NULL ) {//將資料擺進該有的位置 
        tree = new BST;
	  	tree->Cur.push_back(list[i]);
	  	tree->Left = NULL;
	  	tree->Right = NULL;
	  	tree->Last = temp;
	  	if ( temp->Cur[0].getHP() < list[i].getHP() ) temp->Right = tree;
	  	else temp->Left = tree;
      }
      else {
      	tree->Cur.push_back(list[i]);
	  }
	  
      tree = first;
      if ( max < height ) max = height;
      height = 1;
	}
	cout << "HP tree height = " << max << endl;
}

void Pokemon::InputFile( string & name , string & fileNum ) {
	ifstream fin;
	fileNum = name;
	list.clear();
    DealN( name );// 處理INPUT
	fin.open( name.c_str() );
    while ( !fin ) {
    	cout << "### " << name << " does not exist! ###" << endl;
    	cout << "input 501,502.....[0] quit: " << endl;
		cin >> name;
		DealN( name );// 處理INPUT
		fin.open( name.c_str() );
	}
	string tempdat;
	getline(fin,tempdat);// 去掉標題
	while ( getline(fin,tempdat) ) { // 每次讀一行
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
	  	  if ( data[i] == '\t' ) { // 從rawR讀取資訊(sNO.gNO.cname.gname) 
            tabcount++;
			tabend = i;
			if ( tabcount == 1 ) {
              for ( int k = tabstart + 1 ; k < tabend ; k++ ) infostring = infostring + data[k] ;
              ID = atoi( infostring.c_str() );
              infostring = "" ;
            } // if
	        else if ( tabcount == 2 ) {
              for ( int k = tabstart + 1 ; k < tabend ; k++ ) infostring = infostring + data[k] ;
              Name = infostring ;
              infostring = "" ;
            } // else if
            else if ( tabcount == 3 ) {
              for ( int k = tabstart + 1 ; k < tabend ; k++ ) infostring = infostring + data[k] ;
              Type1 = infostring ;
              infostring = "" ;
            } // else if
            else if ( tabcount == 5 ) {
              for ( int k = tabstart + 1 ; k < tabend ; k++ ) {
                if ( data[k] != '"' && data[k] != ',' )
                  infostring = infostring + data[k] ;
              } // for
              Total = atoi( infostring.c_str() ) ;
              infostring = "" ;
            } // else if
            else if ( tabcount == 6 ) {
              for ( int k = tabstart + 1 ; k < tabend ; k++ ) {
                if ( data[k] != '"' && data[k] != ',' )
                  infostring = infostring + data[k] ;
              } // for
              HP = atoi( infostring.c_str() ) ;
              infostring = "" ;
            } // else if
            else if ( tabcount == 7 ) {
              for ( int k = tabstart + 1 ; k < tabend ; k++ ) {
                if ( data[k] != '"' && data[k] != ',' )
                  infostring = infostring + data[k] ;
              } // for
              Atk = atoi( infostring.c_str() ) ;
              infostring = "" ;
            } // else if
            else if ( tabcount == 8 ) {
              for ( int k = tabstart + 1 ; k < tabend ; k++ ) {
                if ( data[k] != '"' || data[k] != ',' )
                  infostring = infostring + data[k] ;
              } // for
              Def = atoi( infostring.c_str() ) ;
              infostring = "" ;
            } // else if
            else if ( tabcount == 9 ) {
              for ( int k = tabstart + 1 ; k < tabend ; k++ ) {
                if ( data[k] != '"' || data[k] != ',' )
                  infostring = infostring + data[k] ;
              } // for
              SpAtk = atoi( infostring.c_str() ) ;
              infostring = "" ;
            } // else if
            else if ( tabcount == 10 ) {
              for ( int k = tabstart + 1 ; k < tabend ; k++ ) {
                if ( data[k] != '"' || data[k] != ',' )
                  infostring = infostring + data[k] ;
              } // for
              SpDef = atoi( infostring.c_str() ) ;
              infostring = "" ;
            } // else if
            else if ( tabcount == 11 ) {
              for ( int k = tabstart + 1 ; k < tabend ; k++ ) {
                if ( data[k] != '"' || data[k] != ',' )
                  infostring = infostring + data[k] ;
              } // for
              Speed = atoi( infostring.c_str() ) ;
              infostring = "" ;
            } // else if
            else if ( tabcount == 12 ) {
              for ( int k = tabstart + 1 ; k < tabend ; k++ ) {
                if ( data[k] != '"' || data[k] != ',' )
                  infostring = infostring + data[k] ;
              } // for
              Gen = atoi( infostring.c_str() ) ;
              infostring = "" ;
            } // else if
            else if ( tabcount == 13 ) {
              for ( int k = tabstart + 1 ; k < tabend ; k++ ) infostring = infostring + data[k] ;
              Leg = infostring ;
              infostring = "" ;
            } // else if
            tabstart = tabend;
          } // if
      	}
	  } // DealDat
