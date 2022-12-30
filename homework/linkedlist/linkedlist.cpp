#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

struct node{
char data[255]="";
node * next=NULL;
};

class linkedlist{
    private:
    node *head;
    int nnode=0;

    public:
    linkedlist(){
        head=NULL;
       
    }

    void insert_in_head(char data[]){
        node *nodo=new node;
        strcpy(nodo->data,data);
        if(head == NULL){
             head=nodo;
             nnode++;
        }
        else{
            nodo->next=head;
            head=nodo;
            nnode++;
        }
       

    }

     void insert_in_tail(char data[]){
        node *nodo=new node;
        node *last=new node;
        strcpy(nodo->data,data);
        if(head == NULL){
             head=nodo;
             nnode++;
        }
        else{
            last=head;
            for(int i=0;i<nnode-1;i++){
                last=last->next;
            }
            nnode++;
            last->next=nodo;

        }
       

    }

    void print_list_from_head(){
        node *nodo=new node;
        nodo=head;
        if(nodo==NULL){
            cout<<"lista vuota"<<endl;
        }
        for(int i=0;i<nnode;i++)
            {
            cout<<nodo->data<<endl;
            nodo=nodo->next;
        }
    }

    void print_head(){
        cout<<head->data<<endl;
    }
    int counter(){
        return nnode;
    }

    void algorithm(){
    node *nodo=new node;
    node *nodo2=new node;
    node *nodo3=new node;
    node *nodo4=new node;


    nodo=head;
    int a=nnode/2;

    for (int i=1;i<a+1;i++){
        nodo=nodo->next;
        if(i==a-1){
            nodo3=nodo;
        }
        //il mio ciclo si ferma al nodo n+1
        }
        //cout<<"IL nodo 3 è "<<nodo3->data<<endl;
        //nodo3 segna il nodo precedente
        //cout<<"Il nodo è "<<nodo->data<<endl;
        //nodo segna il nodo corrente
    nodo4=nodo3;
    //nodo 4 serve alla fine del ciclo per ricollegarmi alla prima metà della lista
    for(int j=a;j<nnode;j++){
    //da questo punto in poi parte il reverse della lista
    nodo2=nodo->next;//nodo 2 segna il nodo successivo
    nodo->next=nodo3;
    nodo3=nodo;
    nodo=nodo2;
    }
   nodo4->next=nodo3;

  
    
    }
    };

void test_case_1( linkedlist lista){
    cout<<"ESEGUO IL PRIMO CASO DI TEST"<<endl;
    lista.insert_in_tail("Lorenzo");
    lista.insert_in_tail("Luisa");
    lista.insert_in_tail("Angela");
    lista.insert_in_tail("Marco");
    lista.insert_in_tail("Francesca");
    lista.insert_in_tail("Roberto");
    lista.print_list_from_head();
    cout<<"Il numero di nodi della lista è "<<lista.counter()<<endl;
    lista.algorithm();
    lista.print_list_from_head();

}

void test_case_2( linkedlist lista){
    cout<<"ESEGUO IL SECONDO CASO DI TEST"<<endl;
    lista.insert_in_tail("Lorenzo");
    lista.insert_in_tail("Luisa");
    lista.insert_in_tail("Angela");
    lista.insert_in_tail("Marco");
    lista.insert_in_tail("Francesca");
    lista.insert_in_tail("Roberto");
    lista.insert_in_head("Mattia");
    lista.insert_in_head("Ilaria");
    lista.print_list_from_head();
    cout<<"Il numero di nodi della lista è "<<lista.counter()<<endl;
    lista.algorithm();
    lista.print_list_from_head();

}

void test_case_3( linkedlist lista){
    cout<<"ESEGUO IL TERZO CASO DI TEST"<<endl;
    lista.insert_in_head("Lorenzo");
    lista.insert_in_tail("Angela");
    lista.print_list_from_head();
    cout<<"Il numero di nodi della lista è "<<lista.counter()<<endl;
    lista.algorithm();
    lista.print_list_from_head();

}


int main(){
    linkedlist lista;
    linkedlist lista2;
    linkedlist lista3;
    cout<<"AVVIO IL PRIMO TEST CASE"<<endl;
    test_case_1(lista);
    cout<<"AVVIO IL SECONDO TEST CASE"<<endl;
    test_case_2(lista2);
    cout<<"AVVIO IL TERZO TEST CASE"<<endl;
    test_case_3(lista3);
    return 0;
}