#ifndef LIST_H
#define LIST_H
#include <QString>
#include <QDebug>
#include <QFile>

class Node {
    int EAN;
    int Price;
    QString Name,Manufacter;
    class Node *ptr;
    friend class List;
};

class List {
    Node *head;
    int E_,P_;
    QString N_,M_;
    Node * Prev(Node* node) {
        if (isEmpty()==false) {
            return nullptr;
        }
        if (node == head) {
            return nullptr;
        }
        Node* p = head;
        while (p != node) {
            p=p->ptr;
        }
        return p;
    }
public:
    Node* endptr=nullptr;  //tail -> endp
    Node* freeptr=nullptr;  //find->free
    List () {
        head = nullptr;
    }
    ~List(){}

    bool isEmpty () {
        if (head == nullptr) {
            return false;
        } else {
            return true;
        }
    }

    Node* Adding (int EAN_, int Price_, QString Name_, QString Manufacter_, Node* node ) {
        Node *uzel = new Node();
        uzel->EAN=EAN_;
        uzel->Price=Price_;
        uzel->Name=Name_;
        uzel->Manufacter=Manufacter_;
        if(node==nullptr) {
            uzel->ptr=head;
            if (head == nullptr) {
                endptr=uzel;
            }
            head = uzel;
            return  uzel;
        } else {
            if (head == nullptr) {
                uzel->ptr = nullptr;
                head = uzel;
                endptr = uzel;
                return uzel;
            }
            else {
                uzel->ptr=nullptr;
                node->ptr = uzel;
                endptr = uzel;
                return uzel;
            }
        }
    }

    QString Deletion(int DC_) {

        if(Find(DC_)==nullptr) {return "Нет такого узла";}
        if(Find(DC_)==head) {
            head = head->ptr;
            freeptr=nullptr;
            return "Корневой узел удален";
        } else {
        Node *p =Prev(Find(DC_));
        p->ptr=Find(DC_)->ptr;
        delete Find(DC_);
        freeptr=nullptr;
        return "Узел удален";
        }
    }

    Node* Next (Node* node) {
        if (isEmpty()==false) {
            return nullptr;
        } else {
            return node->ptr;
        }
    }

    Node* Find ( int EAN_) {
        Node*p = head;
        while (p!=nullptr) {
            if (EAN_==p->EAN) {
                freeptr = p;
                return p;
            }
            p=Next(p);
        }
        return nullptr;
    }

    void CorrcetEAN(Node* p, int EAN_) {
        p->EAN = EAN_;
    }

    void CorrcetPrice(Node* p, int Price_) {
        p->Price=Price_;
    }

    void CorrcetName(Node* p,QString Name_) {
        p->Name=Name_;
    }

    void CorrcetManufacter(Node* p, QString Manufacter_) {
        p->Manufacter=Manufacter_;
    }

    int returnerEAN (Node* node) {
        return node->EAN;
    }

    int returnerPrice (Node* node) {
        return node->Price;
    }

    QString returnerName (Node* node) {
        return node->Name;
    }

    QString returnerManufacter(Node* node) {
        return node->Manufacter;
    }

    void Output (int EAN_) {
        Node* p = Find(EAN_);
        QFile file ("D:\\out.txt");
        if (file.open(QIODevice::WriteOnly)) {
            QTextStream out(&file);
            out<<p->Price;
            out<<p->EAN;
            out<<p->Manufacter;
            out<<p->Name;
            file.close();
        }
    }

    void Input () {
        QFile file ("D:\\in.txt");
        if (file.open(QIODevice::ReadOnly)) {
            QTextStream in(&file);
            QString str;
            while (!in.atEnd()) {
                str=in.readLine();
                N_ = str;
                str=in.readLine();
                M_=str;
                str=in.readLine();
                E_=str.toInt();
                str=in.readLine();
                P_=str.toInt();
                Adding(E_,P_,N_,M_,endptr);
            }
            file.close();
        }
    }

};



#endif // LIST_H
