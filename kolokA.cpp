#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class K1 {
private:
    string * p1;
public:
    K1(): p1(new string("Brak")) {}
    K1(const string& s): p1(new string(s)){}
    K1(const K1& k): p1(new string(*(k.p1))){}
    ~K1(){ delete p1; }
    friend ostream& operator<<(ostream& os,const K1& k){
        os << *(k.p1);
        return os;
    }

    K1& operator=(const K1& k){
        if(this != &k){
            delete p1;
            p1 = new string(*(k.p1));
        }
        return *this;
    }
    
    K1& operator=(const string& s){
        *p1 = s;
        return *this;
    }

    friend istream& operator >>(istream& is, K1& k){ 
        return is >> *(k.p1);
    }

    friend K1 operator +(const K1& k, const string& s){
        return K1(*(k.p1) + s);
    }
    friend K1 operator +(const string& s, const K1& k){
        return K1(s + *(k.p1));
    }
};

class K2 {
private:
    K1 txt[2];
    int w1;
public:
    K2():  w1(0){}
    K2(const K1& k1, const K1& k2, int w):txt{k1,k2}, w1(w){}
    K2(const string& s1, const string& s2, int w): txt{s1,s2}, w1(w){}
    K2(const K2& k): txt{k.txt[0],k.txt[1]},w1(k.w1){}
    
    friend ostream& operator<<(ostream& os, const K2& k){
        os << k.txt[0] << "\t" << k.txt[1] << "\t" << k.w1 << endl;
        return os;
    }
    
    friend istream& operator>>(istream& is, K2& k){
        is >> k.txt[0] >> k.txt[1] >> k.w1;
        return is;
    }
    K2 operator +(int w) const{
        K2 temp(*this);
        temp.w1 += w;
        return temp;
    }
    K2& operator +=(int w) {
        w1 += w;
        return *this;
    }
    K2 operator + (const string& s) const{
        return K2(txt[0], txt[1]+s, w1);
       
    }
     friend K2 operator+ (const string& s, const K2& k){
        return K2(k.txt[0],  s+ k.txt[1] , k.w1);
    }
};

int main(){
K2 ob1, ob2;
const K2 * wsk1 = new K2("Ala", "Koala", 15);
const K2 ob3(*wsk1);
delete wsk1;
wsk1 = 0;

const K2 * wsk2 = new K2(ob3);
ob2 = *wsk2;
cout << ob1 << *wsk2;
delete wsk2;
wsk2 = 0;

cout << ob2;
cout << (ob2 + 10);             
cout << "****** 3 *****\n" << endl;

K2 tab[4];
ifstream plik ("plik is good");                     
if (plik.good()){
    for (size_t i {0}; i < 4; i++){
        plik >> tab[i];
    }
}
plik.close();
for (size_t i {0}; i < 4; i++){
    tab[i] += 1;
    cout << tab[i];
}

cout << "****** 4 *****\n" << endl;

tab[1] = tab[1] + " Kowalska"; 
tab[3] = "Bocian " + tab[3];    

for (int i = 0; i < 4; ++i) {
    cout << tab[i];
}
cout << "****** 5 *****\n" << endl;
}