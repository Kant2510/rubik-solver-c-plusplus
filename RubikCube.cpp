#include <iostream>
#include <fstream>
using namespace std;
int i, eloca, find, total=0;
string alg, s;
char count, box;
class rubik{
    public:
        char a;
        char b;
        char c;
        char d;
        char n;
        char w;
        char x;
        char y;
        char z;
};
rubik u, d, f, b, r, l;
void setcolor(){                //set color coordinte for rubik from file .txt| thiet lap toa do mau cho khoi rubik tu tep txt
    ifstream ru;
	ru.open("C://Users//fptshop//Documents//C++//rubik.txt");
    i=1;
    while( i>=1 && i<=54){
        ru>>u.a; ru>>u.w; ru>>u.b; ru>>u.x; ru>>u.n; ru>>u.y; ru>>u.c; ru>>u.z; ru>>u.d;
        ru>>f.a; ru>>f.w; ru>>f.b; ru>>f.x; ru>>f.n; ru>>f.y; ru>>f.c; ru>>f.z; ru>>f.d;
        ru>>d.a; ru>>d.w; ru>>d.b; ru>>d.x; ru>>d.n; ru>>d.y; ru>>d.c; ru>>d.z; ru>>d.d;
        ru>>l.a; ru>>l.w; ru>>l.b; ru>>l.x; ru>>l.n; ru>>l.y; ru>>l.c; ru>>l.z; ru>>l.d;
        ru>>r.a; ru>>r.w; ru>>r.b; ru>>r.x; ru>>r.n; ru>>r.y; ru>>r.c; ru>>r.z; ru>>r.d;
        ru>>b.a; ru>>b.w; ru>>b.b; ru>>b.x; ru>>b.n; ru>>b.y; ru>>b.c; ru>>b.z; ru>>b.d;
        i++;
    }
}
class mov{                      //move notation| ki hieu xoay rubik
    public:
        void R(){
            box=u.d; u.d=f.d; f.d=d.d; d.d=b.d; b.d=box;
            box=u.y; u.y=f.y; f.y=d.y; d.y=b.y; b.y=box;
            box=u.b; u.b=f.b; f.b=d.b; d.b=b.d; b.b=box;
            box=r.a; r.a=r.c; r.c=r.d; r.d=r.b; r.b=box;
            box=r.w; r.w=r.x; r.x=r.z; r.z=r.y; r.y=box;
            cout<<"R ";
            total++;
        }
        void R2(){
            R(); R();
            cout<<"\b\b\b\bR2 ";
            total--;
        }
        void R1(){
            R(); R(); R();
            cout<<"\b\b\b\b\b\bR' ";
            cout<<"  \b\b";
            total-=2;
        }
        void L(){
            box=u.a; u.a=b.a; b.a=d.a; d.a=f.a; f.a=box;
            box=u.x; u.x=b.x; b.x=d.x; d.x=f.x; f.x=box;
            box=u.c; u.c=b.c; b.c=d.c; d.c=f.c; f.c=box;
            box=l.a; l.a=l.c; l.c=l.d; l.d=l.b; l.b=box;
            box=l.w; l.w=l.x; l.x=l.z; l.z=l.y; l.y=box;
            cout<<"L ";
            total++;
        }
        void L2(){
            L(); L();
            cout<<"\b\b\b\bL2 ";
            total--;
        }
        void L1(){
            L(); L(); L();
            cout<<"\b\b\b\b\b\bL' ";
            cout<<"  \b\b";
            total-=2;
        }
        void F(){
            box=u.c; u.c=l.d; l.d=d.b; d.b=r.a; r.a=box;
            box=u.z; u.z=l.y; l.y=d.w; d.w=r.x; r.x=box;
            box=u.d; u.d=l.b; l.b=d.a; d.a=r.c; r.c=box;
            box=f.a; f.a=f.c; f.c=f.d; f.d=f.b; f.b=box;
            box=f.w; f.w=f.x; f.x=f.z; f.z=f.y; f.y=box;
            cout<<"F ";
            total++;
        }
        void F2(){
            F(); F();
            cout<<"\b\b\b\bF2 ";
            total--;
        }
        void F1(){
            F(); F(); F();
            cout<<"\b\b\b\b\b\bF' ";
            cout<<"  \b\b";
            total-=2;
        }
        void B(){
            box=u.b; u.b=r.d; r.d=d.c; d.c=l.a; l.a=box;
            box=u.w; u.w=r.y; r.y=d.z; d.z=l.x; l.x=box;
            box=u.a; u.a=r.b; r.b=d.d; d.d=l.c; l.c=box;
            box=b.a; b.a=b.c; b.c=b.d; b.d=b.b; b.b=box;
            box=b.w; b.w=b.x; b.x=b.z; b.z=b.y; b.y=box;
            cout<<"B ";
            total++;
        }
        void B2(){
            B(); B();
            cout<<"\b\b\b\bB2 ";
            total--;
        }
        void B1(){
            B(); B(); B();
            cout<<"\b\b\b\b\b\bB' ";
            cout<<"  \b\b";
            total-=2;
        }
        void U(){
            box=f.b; f.b=r.b; r.b=b.c; b.c=l.b; l.b=box;
            box=f.w; f.w=r.w; r.w=b.z; b.z=l.w; l.w=box;
            box=f.a; f.a=r.a; r.a=b.d; b.d=l.a; l.a=box;
            box=u.a; u.a=u.c; u.c=u.d; u.d=u.b; u.b=box;
            box=u.w; u.w=u.x; u.x=u.z; u.z=u.y; u.y=box;
            cout<<"U ";
            total++;
        }
        void U2(){
            U(); U();
            cout<<"\b\b\b\bU2 ";
            total--;
        }
        void U1(){
            U(); U(); U();
            cout<<"\b\b\b\b\b\bU' ";
            cout<<"  \b\b";
            total-=2;
        }
        void D(){
            box=f.c; f.c=l.c; l.c=b.b; b.b=r.c; r.c=box;
            box=f.z; f.z=l.z; l.z=b.w; b.w=r.z; r.z=box;
            box=f.d; f.d=l.d; l.d=b.a; b.a=r.d; r.d=box;
            box=d.a; d.a=d.c; d.c=d.d; d.d=d.d; d.d=box;
            box=d.w; d.w=d.x; d.x=d.z; d.z=d.y; d.y=box;
            cout<<"D ";
            total++;
        }
        void D2(){
            D(); D();
            cout<<"\b\b\b\bD2 ";
            total--;
        }
        void D1(){
            D(); D(); D();
            cout<<"\b\b\b\b\b\bD' ";
            cout<<"  \b\b";
            total-=2;
        }
};
mov m;
int writeAlg( string alg){      //writle move algorithm| viet thuat toan xoay      
    for( i=0; i<=alg.length()-1; i++){
        if( alg[i]=='R' || alg[i]=='L' || alg[i]=='F' || alg[i]=='B' || alg[i]=='U' || alg[i]=='D'){
            if( alg[i+1]==' ' || alg[i+1]=='\0') s=alg.substr( i, 1);
            else if( alg[i+1]=='2' || alg[i+1]=='`') s=alg.substr( i, 2);
            if( s=="R") m.R();
            if( s=="R2") m.R2();
            if( s=="R`") m.R1();
            if( s=="L") m.L();
        }
    }
    return 0;
}
int locationEdge( char e, char f){
    eloca=int(e)%int(f);
    return eloca;
}
int cross1( char e, char f ){
    switch( locationEdge( e,f)){
        case 5: break;
        case 7:
        case 8:
        case 10:
        default:cout<<"sai cmnr :(( ";
    }
return 0;
}
int main(){
setcolor();
m.R(); m.L(); m.F(); m.B(); m.U(); m.D();
cout<<endl;
cout<<total;
system("pause");
}