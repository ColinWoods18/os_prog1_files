/*
  Here is some example code for Program 1.  You don't have to use any of
  it, but if you are having trouble, it might get you started.
  The etype used through this is the template class your need to create
  in this class, etype means Example TYPE
*/
#include <cstdlib>  //This is for the exit command.
#include <queue>
#include <iostream>

using namespace std;


/*
 *  In the class below, it declares a "queue<etype>" array.     
 *  you don't need to use the STL queue (but you can), choose a data structure
 * that you think works.   If you choose to write you own queue class, then 
 * it has better follow all the requirements to a queue, to include the O time
 * minimum timing requirements of c++
*/


template <class etype>
class QueueArray
{

  public:
    QueueArray(int);
    ~QueueArray();
    int Asize();
    etype Dequeue();
    int Enqueue(const etype &item,const int index);
    int QAsize(); 
    int Qsize(int index) ;
    etype* Qstate(int index);

  private:
    int size = 10;      //size of the array
    queue<etype>* array;   //the array of queues.  It must be an array (not a vector)
    int totalItems; //total number of items stored in the queues
};

//Constructor for the queue array.  It sets the default size
//to 10, initializes the private variables size and totalItems
template <class etype>
QueueArray<etype>::QueueArray(int sz):size(sz),totalItems(0)
{
  array = new queue<etype>[size];
  if( array == NULL)
  {
    cout << "Not enough memory to create the array" << endl;
    exit(-1);
  }
}

template <class etype>
int QueueArray<etype>::Asize(){
  return size;
}  

template <class etype>
QueueArray<etype>::~QueueArray(){
  delete [] array;
}

template <class etype>
int QueueArray<etype>::Enqueue(const etype &item,const int index){
  if (index > sizeof(array)-1 || index < 0 ){
    return -1;} else {
      array[index].push(item);
      return 1;
      }
    return 0;
}

template <class etype>
int QueueArray<etype>::Qsize(int index){
  if(index < 0 || index > sizeof(array)-1){
    return -1;} else {
  return array[index].size();
  }
}

template <class etype>
int QueueArray<etype>::QAsize(){
  int sum = 0;
  for(int i = 0; i < Asize(); i++){
    sum += Qsize(i);
      }
  return sum;
}

template <class etype>
etype  QueueArray<etype>::Dequeue(){
  for(int i=0;i<Asize(); i++){
    if(Qsize(i)>0){
     char temp =  array[i].front();
     array[i].pop(); 
     return temp;
    }
  }
  return 0;
}

template <class etype>
etype* QueueArray<etype>::Qstate(int index){
  if(index < 0 || index > Asize()){
    return NULL;
  }else {
    queue<etype> temp;
    temp = array[index];
    etype* ss = new etype[Qsize(index)];
    for(int i = 0; i < Qsize(index); i++)
      {	 
      	 ss[i] = temp.front();
      	 temp.pop();
      }
   return ss;
  } 
}
    
  


