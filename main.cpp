#include <iostream> 
#include "HeapTree.h"
using namespace std;    

int main(void) { 
   
    int k =2 ; 

    cout << "choose degree k( >=2):" ;
    cin >> k ;
    HeapTree T(k) ;
    cout << "input : 20,30,90,80,10,40,60,70,50,0 "<<endl;
    T.add( 0 );//ivector[0];
    T.insert(0);T.insert(10);T.insert(20);T.insert(30);T.insert(40);
    T.insert(50);T.insert(60);T.insert(70);T.insert(80);T.insert(90);
    
    //T.downHeapBubbling( 3 );   
    T.print();
    for( int i =0 ; i <3 ; i++ ){
        int c =1 ;
        int keyValue ;
        cout << "\nchoose 1( for insert ) or 2 ( for remove ) :" ;
        cin >> c ;
        if ( c == 1){
            cout << "inserted key :" ;
            cin >> keyValue ;
            T.insert(keyValue);            
            T.print();    
        }   
        else if( c == 2 ){
            cout << "remove key :" ;
            cin >> keyValue ;
            T.remove(keyValue); 
            T.print();    
        }    
        else 
            cout << "wrong select. ";
    }    
    system("PAUSE");
    return 0; 
}

