#include <iostream> 
#include "HeapTree.h"
using namespace std;    

int main(void) { 
   
    int k =2 ; 

    cout << "choose degree k( >=2):" ;
    cin >> k ;
    HeapTree T(k,10) ;
    cout << "input : 20,30,90,80,0,40,60,70,50,10 "<<endl;
    T.keyArray[1]=20;T.keyArray[2]=30;T.keyArray[3]=90;T.keyArray[4]=80;
    T.keyArray[5]=0 ;T.keyArray[6]=40;T.keyArray[7]=60;T.keyArray[8]=70;
    T.keyArray[9]=50;T.keyArray[10]=10;
    T.heapSort();
   
    T.print();
    for( int i =0 ; i <3 ; i++ ){
        int c =1 ;
        int keyValue ;
        cout << "\nchoose 1( for insert ) or 2 ( for remove ) :" ;
        cin >> c ;
        if ( c == 1){
            cout << "key :" ;
            cin >> keyValue ;
            T.insert(keyValue);
            
            T.print();    
        }   
        else if( c == 2 ){
            cout << "key :" ;
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


