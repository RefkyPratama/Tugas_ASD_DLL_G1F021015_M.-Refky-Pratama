#include <iostream>
using namespace std;


struct Sendal{
  string merek, jenis, ukuran;
  Sendal *prev;
  Sendal *next;
};

Sendal *head, *tail, *cur, *newNode, *del, *beforeNode;

// Create Double Linked List
void createDoubleLinkedList( string SDL[3] ){
  head = new Sendal();
  head->merek = SDL[0];
  head->jenis = SDL[1];
  head->ukuran = SDL[2];
  head->prev = NULL;
  head->next = NULL;
  tail = head;
}

int countDoubleLinkedList()
{
  if( head == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    cur = head;
    int jumlah = 0;
    while( cur != NULL ){
      jumlah++;      
      
      cur = cur->next;
    }
    return jumlah;
  }
}


void addFirst( string SDL[3] ){
  if( head == NULL ){
    cout << "Double Linked List belum selesai!!!";
  }else{
    newNode = new Sendal();
    newNode->merek = SDL[0];
    newNode->jenis = SDL[1];
    newNode->ukuran = SDL[2];
    newNode->prev = NULL;
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }
}

// Add Last
void addLast( string SDL[3] ){
  if( head == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    newNode = new Sendal();
    newNode->merek = SDL[0];
    newNode->jenis = SDL[1];
    newNode->ukuran = SDL[2];
    newNode->prev = tail;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
  }
}


void addMiddle( string SDL[3], int posisi ){
  if( head == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{

    if( posisi == 1 ){
      cout << "Posisi 1 itu bukan posisi tengah!!!" << endl;
    }else if( posisi < 1 || posisi > countDoubleLinkedList() ){
      cout << "Posisi diluar jangkauan!!!" << endl;
    }else{
      newNode = new Sendal();
      newNode->merek = SDL[0];
      newNode->jenis = SDL[1];
      newNode->ukuran = SDL[2];
      
      
      cur = head;
      int NO = 1;
      while( NO <  posisi - 1){
        cur = cur->next;
        NO++;
      }

      beforeNode = cur->next;
      newNode->prev = cur;
      newNode->next = beforeNode;
      cur->next = newNode;
      beforeNode->prev = newNode;
    }

  }
}

void removeFirst()
{
  if( head == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    del = head;
    head = head->next;
    head->prev = NULL;
    delete del;
  }
}


void removeLast()
{
  if( head == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    del = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete del;
  }
}


void removeMiddle(int posisi){
  if( head == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    if( posisi == 1 || posisi == countDoubleLinkedList() ){
      cout << "Posisi bukan posisi tegah!!" << endl;
    }else if( posisi < 1 || posisi > countDoubleLinkedList() ){
      cout << "Posisi diluar jangkauan!!" << endl;
    }else{
      int NO = 1;
      cur = head;
      while( NO < posisi - 1 ){
        cur = cur->next;
        NO++;
      }
      del = cur->next;
      beforeNode = del->next;
      cur->next = beforeNode;
      beforeNode->prev = cur;
      delete del;
    }
  }
}


void printDoubleLinkedList()
{
  if( head == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    cout << "Jml Data : " << countDoubleLinkedList() << endl;
    cout << "Isi Data : " << endl;
    cur = head;
    while( cur != NULL ){
    	
      cout << "merek sendal : " << cur->merek << endl;
      cout << "jenis sendal : " << cur->jenis << endl;
      cout << "ukuran sendal : " << cur->ukuran << "\n" << endl;
      
      cur = cur->next;
    }
  }
}

int main(){

  string newSPT[3] = {"SWALLOW", "CASUAL", "42"};
  createDoubleLinkedList(newSPT);

  printDoubleLinkedList();

  string SPT2[3] = {"NIKE", "CASUAL", "41"};

  addFirst( SPT2 );

  printDoubleLinkedList();

  string SPT3[3] = {"ANDO", "CASUAL", "39"};

  addLast( SPT3 );

  printDoubleLinkedList();

  string SPT4[3] = {"EIGER", "Sendal Gunung", "40"};
  addMiddle(SPT4, 3);

  printDoubleLinkedList();

  removeMiddle(2);

  printDoubleLinkedList();


}
