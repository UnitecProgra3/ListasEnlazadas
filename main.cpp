#include <iostream>
using namespace std;

class Nodo
{
public:
    Nodo* sig;
    int num;

    Nodo(int num)
    {
        this->sig=NULL;
        this->num=num;
    }
};

class Lista
{
public:
    Nodo*inicio;

    Lista()
    {
        inicio=NULL;
    }

    void imprimir()
    {
        for(Nodo*temp=inicio;
            temp!=NULL;
            temp=temp->sig)
        {
            cout<<temp->num<<endl;
        }
    }

    void agregar(Nodo*nuevo)
    {
        if(inicio!=NULL)
        {
            Nodo*temp;
            for(temp=inicio;
                temp->sig!=NULL;
                temp=temp->sig);

            temp->sig=nuevo;
        }else
        {
            inicio=nuevo;
        }
    }

    void borrarUltimo()
    {
        if(inicio==NULL)
        {
            cout<<"La lista esta vacia"<<endl;
            return;
        }

        if(inicio->sig==NULL)
        {
            delete inicio;
            inicio=NULL;
            return;
        }

        Nodo*temp;
        for(temp=inicio;
            temp->sig->sig!=NULL;
            temp=temp->sig);

        delete temp->sig;
        temp->sig=NULL;
    }

    void borrarTodo()
    {
        while(inicio!=NULL)
        {
            borrarUltimo();
        }
    }

    void insertar(Nodo*nuevo,int pos)
    {
        Nodo*temp=inicio;
        for(int i=0;i<pos-1;i++)
        {
            temp=temp->sig;
        }

        nuevo->sig=temp->sig;
        temp->sig=nuevo;
    }
};

int main()
{
//    int* x=new int(10);
//    delete x;
//    x=new int(20);
    Lista l;
    while(true)
    {
        l.agregar(new Nodo(1));
        l.agregar(new Nodo(2));
        l.agregar(new Nodo(3));
        l.agregar(new Nodo(4));
        l.borrarTodo();
    }
    l.imprimir();
    cout<<"****";
    l.imprimir();

    return 0;
}
