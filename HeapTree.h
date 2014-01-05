#ifndef HEAPTREE_H
#define HEAPTREE_H

#include <iostream> 
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <math.h>
using namespace std; 

class HeapTree{
    public :  
        HeapTree( int k  );
        int size() ;
        void add( int );
        void insert( int );
        void remove( int );
        void removeMin();
        void upHeapBubbling( int );
        void downHeapBubbling( int );
        int minOfChildren( int );        
        int min();
        
        void print();  
    private :
        vector<int> ivector;
        int k_ary;
        
};

HeapTree::HeapTree( int k ):k_ary(k){
    vector<int> ivector;
}

int HeapTree::size(){
    return  ivector.size()-1;   
}    

void HeapTree::add( int keyValue ){
    ivector.push_back( keyValue );
    }
    
void HeapTree::insert( int keyValue ){
    
    add( keyValue );
    upHeapBubbling( size() );    
}
// 
void HeapTree::remove( int keyValue ){
    int index =0;
    if( keyValue == ivector[1] )
        index = 1;
    else{    
        for ( int i = 1 ; i <=size() ; i++ ){
            if(  keyValue == ivector[i] )
                index = i;  
        }
        if( index ==0)
            cout << "can't find this key!";  
    }       
    swap( ivector[index],ivector[size()] );
    ivector.pop_back();
    downHeapBubbling( index );                      
}

void HeapTree::removeMin(){
    remove( ivector[1] );    
}
 
void HeapTree::upHeapBubbling( int index ){
    
    int parentIndex = (int)floor((index-2)/k_ary+1);
    if  ( parentIndex ==0 );
    else if (  ivector[ index ]< ivector[ parentIndex ] ){ 
            swap( ivector[ index ],ivector[ parentIndex ]) ;
            upHeapBubbling( parentIndex );
    }      
}
// 
void HeapTree::downHeapBubbling( int  index ){
    if( minOfChildren( index ) <= size()){// ensure it's in vector
        //cout << minOfChildren( index );
        swap( ivector[ index ],ivector[ minOfChildren ( index ) ] );
        downHeapBubbling ( minOfChildren  ( index )  );  
    }  
}
int HeapTree::minOfChildren( int index ){
    int numOfChildren = k_ary;
    int count =0;
    int indexOfChildren [ numOfChildren ];// 有 indexOfChildren[ 0 ]( index 的第一個child's index )
                            // ~ indexOfChildren[ numOfChildren ]( index 的第k_ary個child's index )
    while( count < numOfChildren ){
        indexOfChildren[ count ] = k_ary * index- ( k_ary-2 )+ count ;
        if( indexOfChildren[ count ] > size()){
           // cout << "\n\nindex " << index <<" only has " << count <<" child/children" ;
            numOfChildren = count ;
        }         
        else
            count++;   
    }
    if( numOfChildren ==0 ){
        //cout << "\nindex " << index <<" has no child ." ;
        return ivector.size();
    }        
    else if ( numOfChildren==1 ){
        return  size();
    }
    else{
        int indexOfMin ;
        int min =ivector[ indexOfChildren[0] ];
        for( int i =1 ; i < numOfChildren ; i++ ) {
            if( ivector[ indexOfChildren[i] ] < min )
                min = ivector [indexOfChildren[i]];
        }   
        for( int j=0; j< size() ; j++){
            ivector[ j ] ==min ;
            indexOfMin = j;
        }
        return indexOfMin;
    }    
}

int HeapTree::min(){
    return ivector[1] ;    
}     
void HeapTree::print(){
    
    vector<int> Print = ivector;
    cout << "\narray of HeapTree:";
    for (vector<int>::iterator it = ivector.begin()+1 ; it != ivector.end(); ++it)
        cout << setw(4) << *it;
    cout << "\nsorted array     :";
    while(ivector.size()>1){
        cout << setw(4) << ivector[1];
        removeMin(); 
    }    
    ivector = Print ;
    
}
 
    
#endif
