#ifndef HEAPTREE_H
#define HEAPTREE_H

#include <iostream> 
//#include <cstdlib>
#include <iomanip>
#include <math.h>
#include "K_aryTree.h"
using namespace std; 

class HeapTree{
    public :  
        int keyArray[100] ;
        int size ;
        HeapTree( int k ,int );
        void swap( int[],int,int);
        void add( int ,int);
        void insert( int );
        void remove( int );
        void removeMin();
        void upHeapBubbling( int );
        void downHeapBubbling();        
        void heapSort();
        int min();
        
        void print();  
    private :
        K_aryTree K;
        int k_ary;
        
};
HeapTree::HeapTree( int k ,int s):k_ary(k),size(s){
}
void HeapTree::swap(int k[] , int v, int u) { 
    int temp = k[v];  
    k[v] = k[u];  
    k[u] = temp;  
}  

void HeapTree::add( int x ,int size){
    cout << size;
    size++;
    cout << size;
    keyArray[size] = x ;
    }
void HeapTree::insert( int x,  int size){
    
    add(x ,size);
    //upHeapBubbling( size );    
}
void HeapTree::remove( int x ){
    swap( keyArray , x , size );
    size--;
    downHeapBubbling();                      
}
void HeapTree::removeMin(){
    remove( keyArray[1] );    
}
void HeapTree::upHeapBubbling( int startPoint){
  
    int parentIndex = (int)floor((startPoint-2)/k_ary+1);
    if( keyArray[startPoint] < keyArray[parentIndex] ){ 
        swap( keyArray , startPoint , parentIndex ) ;
        int nextStart = parentIndex;
        upHeapBubbling( nextStart );
    }      
}
void HeapTree::downHeapBubbling(){}
void HeapTree::heapSort(){}

int HeapTree::min(){
    return keyArray[1];    
}     
void HeapTree::print(){
    int firstSize = size  ;
    cout << "\narray of HeapTree:";
    for( int i =1; i <= size ;i++)
        cout << keyArray[i] << setw(4); 
    cout << "\nsorted array     :";
    for(int i =1; i <=firstSize ;i++){
        cout << keyArray[1]<< setw(4);
        removeMin(); 
    }    
    
}
 
    
#endif
