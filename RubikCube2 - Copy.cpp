#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
int  eposi, cposi, fposi, total=0, count=0,
    UB, UL, UF, UR, DB, DL, DF, DR, FR, RB, BL, LF, 
    BU, LU, FU, RU, BD, LD, FD, RD, RF, BR, LB, FL,
    UBL, ULF, UFR, URB, DBR, DRF, DFL, DLB, 
    BLU, LFU, FRU, RBU, BRD, RFD, FLD, LBD, 
    LUB, FUL, RUF, BUR, RDB, FDR, LDF, BDL;
string alg, s, sw;
char box;
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
int convertEdgetoNum( char e, char g){     //convert edge position to number | chuyen vi tri vien canh sang chu so
    eposi=e*1000+g;
    return eposi;
}
int convertCornertoNum( char j, char k, char p){
    cposi=j*1000000 + k*1000 + p;
    return cposi;
}
int convertF2LtoNum( char j, char k, char p, char e, char g){
    fposi = convertEdgetoNum( e, g) + convertCornertoNum( j, k, p);
    return fposi;
}
void pEdge(){                   //save edge position | luu vi tri vien canh   
    UB = convertEdgetoNum( u.w, b.z);
    UL = convertEdgetoNum( u.x, l.w);
    UR = convertEdgetoNum( u.y, r.w);
    UF = convertEdgetoNum( u.z, f.w);

    DF = convertEdgetoNum( d.w, f.z);
    DL = convertEdgetoNum( d.x, l.z);
    DR = convertEdgetoNum( d.y, r.z);
    DB = convertEdgetoNum( d.z, b.w);

    FR = convertEdgetoNum( f.y, r.x);
    RB = convertEdgetoNum( r.y, b.y);
    BL = convertEdgetoNum( b.x, l.x);
    LF = convertEdgetoNum( l.y, f.x);

    BU = convertEdgetoNum( b.z, u.w);
    LU = convertEdgetoNum( l.w, u.x);
    RU = convertEdgetoNum( r.w, u.y);
    FU = convertEdgetoNum( f.w, u.z);

    FD = convertEdgetoNum( f.z, d.w);
    LD = convertEdgetoNum( l.z, d.x);
    RD = convertEdgetoNum( r.z, d.y);
    BD = convertEdgetoNum( b.w, d.z);

    RF = convertEdgetoNum( r.x, f.y );
    BR = convertEdgetoNum( b.y, r.y );
    LB = convertEdgetoNum( l.x, b.x );
    FL = convertEdgetoNum( f.x, l.y );
}
void pCorner(){
    UBL = convertCornertoNum( u.a, b.c, l.a);
    ULF = convertCornertoNum( u.c, l.b, f.a);
    UFR = convertCornertoNum( u.d, f.b, r.a);
    URB = convertCornertoNum( u.b, r.b, b.d);

    BLU = convertCornertoNum( b.c, l.a, u.a);
    LFU = convertCornertoNum( l.b, f.a, u.c);
    FRU = convertCornertoNum( f.b, r.a, u.d);
    RBU = convertCornertoNum( r.b, b.d, u.b);

    LUB = convertCornertoNum( l.a, u.a, b.c);
    FUL = convertCornertoNum( f.a, u.c, l.b);
    RUF = convertCornertoNum( r.a, u.d, f.b);
    BUR = convertCornertoNum( b.d, u.b, r.b);

    DBR = convertCornertoNum( d.d, b.b, r.d);
    DRF = convertCornertoNum( d.b, r.c, f.d);
    DFL = convertCornertoNum( d.a, f.c, l.d);
    DLB = convertCornertoNum( d.c, l.c, b.a);

    BRD = convertCornertoNum( b.b, r.d, d.d);
    RFD = convertCornertoNum( r.c, f.d, d.b);
    FLD = convertCornertoNum( f.c, l.d, d.a);
    LBD = convertCornertoNum( l.c, b.a, d.c);

    RDB = convertCornertoNum( r.d, d.d, b.b);
    FDR = convertCornertoNum( f.d, d.b, r.c);
    LDF = convertCornertoNum( l.d, d.a, f.c);
    BDL = convertCornertoNum( b.a, d.c, l.c);
}
void setcolor(){                //set color coordinate for rubik | thiet lap toa do mau cho khoi rubik
    ifstream ru;
	ru.open("rubik.txt");
    ru>>u.a>>u.w>>u.b>>u.x>>u.n>>u.y>>u.c>>u.z>>u.d;
    ru>>f.a>>f.w>>f.b>>f.x>>f.n>>f.y>>f.c>>f.z>>f.d;
    ru>>d.a>>d.w>>d.b>>d.x>>d.n>>d.y>>d.c>>d.z>>d.d;
    ru>>l.a>>l.w>>l.b>>l.x>>l.n>>l.y>>l.c>>l.z>>l.d;
    ru>>r.a>>r.w>>r.b>>r.x>>r.n>>r.y>>r.c>>r.z>>r.d;
    ru>>b.a>>b.w>>b.b>>b.x>>b.n>>b.y>>b.c>>b.z>>b.d;
    pEdge(); pCorner();
}
class movenotation{             //move notation| ki hieu xoay rubik
    public:
        void R(){
            box=u.d; u.d=f.d; f.d=d.d; d.d=b.d; b.d=box;
            box=u.y; u.y=f.y; f.y=d.y; d.y=b.y; b.y=box;
            box=u.b; u.b=f.b; f.b=d.b; d.b=b.b; b.b=box;
            box=r.a; r.a=r.c; r.c=r.d; r.d=r.b; r.b=box;
            box=r.w; r.w=r.x; r.x=r.z; r.z=r.y; r.y=box;
            pEdge(); pCorner();
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
            pEdge(); pCorner();
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
            pEdge(); pCorner();
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
            pEdge(); pCorner();
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
           pEdge(); pCorner();
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
            box=d.a; d.a=d.c; d.c=d.d; d.d=d.b; d.b=box;
            box=d.w; d.w=d.x; d.x=d.z; d.z=d.y; d.y=box;
            pEdge(); pCorner();
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
        void M(){
            box=u.w; u.w=b.w; b.w=d.w; d.w=f.w; f.w=box;
            box=u.n; u.n=b.n; b.n=d.n; d.n=f.n; f.n=box;
            box=u.z; u.z=b.z; b.z=d.z; d.z=f.z; f.z=box;
            pEdge(); pCorner();
            cout<<"M ";
            total++;
        }
        void M2(){
            M(); M();
            cout<<"\b\b\b\bM2 ";
            total--;
        }
        void E(){
            box=f.x; f.x=l.x; l.x=b.y; b.y=r.x; r.x=box;
            box=f.n; f.n=l.n; l.n=b.n; b.n=r.n; r.n=box;
            box=f.y; f.y=l.y; l.y=b.x; b.x=r.y; r.y=box;
            pEdge(); pCorner();
            cout<<"E ";
            total++;
        }
        void S(){
            box=u.x; u.x=l.z; l.z=d.y; d.y=r.w; r.w=box;
            box=u.n; u.n=l.n; l.n=d.n; d.n=r.n; r.n=box;
            box=u.y; u.y=l.w; l.w=d.x; d.x=r.z; r.z=box;
            pEdge(); pCorner();
            cout<<"S ";
            total++;
        }
        void d1(){
            E(); E(); E(); D1();
            cout<<"\b\b\b\b\b\b\b\b\bd' ";
            cout<<"     \b\b\b\b\b";
            total-=3;
        }
        void uu(){
            E(); E(); E(); U();
            cout<<"\b\b\b\b\b\b\b\bu ";
            cout<<"     \b\b\b\b\b";
            total-=3;
        }
        void u1(){
            E(); U1();
            cout<<"\b\b\b\b\bu' ";
            cout<<" \b";
            total--;
        }
};
movenotation m;
int writeAlg( string alg){      //write move algorithm | viet thuat toan xoay      
    for( int i=0; i<=alg.length()-1; i++){
        if( alg[i]=='R' || alg[i]=='L' || alg[i]=='F' || alg[i]=='B' || alg[i]=='U' || alg[i]=='D' || alg[i]=='M' || alg[i]=='u'){
            if( alg[i+1]==' ' || alg[i+1]=='\0') s=alg.substr( i, 1);
            else if( alg[i+1]=='2' || alg[i+1]=='1') s=alg.substr( i, 2);
            if( s=="R")  m.R();
            if( s=="R2") m.R2();
            if( s=="R1") m.R1();
            if( s=="L")  m.L();
            if( s=="L2") m.L2();
            if( s=="L1") m.L1();
            if( s=="U")  m.U();
            if( s=="U2") m.U2();
            if( s=="U1") m.U1();
            if( s=="D")  m.D();
            if( s=="D2") m.D2();
            if( s=="D1") m.D1();
            if( s=="F")  m.F();
            if( s=="F2") m.F2();
            if( s=="F1") m.F1();
            if( s=="B")  m.B();
            if( s=="B2") m.B2();
            if( s=="B1") m.B1();
            if( s=="M")  m.M();
            if( s=="M2") m.M2();
            if( s=="u")  m.uu();
            if( s=="u1") m.u1();
        }
    }
    return 0;
}
int cross1( int edge){
    if( edge == UB) writeAlg( "U2 F2");
    if( edge == UL) writeAlg( "U1 F2");
    if( edge == UR) writeAlg( "U F2");
    if( edge == UF) writeAlg( "F2");
    if( edge == DF) {}
    if( edge == DL) writeAlg( "D");
    if( edge == DR) writeAlg( "D1 F D F1");
    if( edge == DB) writeAlg( "L1 D2 L");
    if( edge == FR) writeAlg( "F1 U1 R1 F R");
    if( edge == RB) writeAlg( "R2 F R2");
    if( edge == BL) writeAlg( "L U1 L1 F2");
    if( edge == LF) writeAlg( "F1");
    if( edge == BU) writeAlg( "U R1 F R");
    if( edge == LU) writeAlg( "L F1 L1");
    if( edge == RU) writeAlg( "R1 F R");
    if( edge == FU) writeAlg( "U1 R1 F R");
    if( edge == FD) writeAlg( "D R D1 F");
    if( edge == LD) writeAlg( "L1 F1");
    if( edge == RD) writeAlg( "R F");
    if( edge == BD) writeAlg( "D1 R D F");
    if( edge == RF) writeAlg( "F");
    if( edge == BR) writeAlg( "R1 U R F2");
    if( edge == LB) writeAlg( "L2 F1 L2");
    if( edge == FL) writeAlg( "L1 U1 L F2");
    m.D1();
    return 0;
}
int f2l( int corner, int edge){
    int multiplied = (corner/1000000)*((corner%1000000)/1000)*((corner%1000000)%1000);
    int addition   = (edge/1000)*(edge%1000);
    if( multiplied == u.a*b.c*l.a) m.U2();
    if( multiplied == u.b*r.b*b.d) m.U();
    if( multiplied == u.c*l.b*f.a) m.U1();
    if( multiplied == d.a*f.c*l.d) writeAlg( "L1 U1 L");
    if( multiplied == d.c*l.c*b.a) writeAlg( "L U2 L1");
    if( multiplied == d.d*b.b*r.d) writeAlg( "R1 U2 R U1");

    if( addition == f.x*l.y) writeAlg( "L1 U1 L U");
    if( addition == l.x*b.x) writeAlg( "L U1 L1 U");
    if( addition == b.y*r.y) writeAlg( "R1 U R");
    
    int CoEd = corner+edge;

    if( CoEd == DRF+RF) {}
    if( CoEd == DRF+FR) writeAlg( "R U2 R1 U R U2 R1 U F1 U1 F");
    if( CoEd == DRF+UB) writeAlg( "U");
    if( CoEd == DRF+UF) writeAlg( "U1");
    if( CoEd == DRF+UR) writeAlg( "U2");
    if( CoEd == DRF+LU) writeAlg( "U");
    if( CoEd == DRF+RU) writeAlg( "U1");
    if( CoEd == DRF+FU) writeAlg( "U2");
    if( CoEd == DRF+UL) writeAlg( "R U1 R1 F R1 F1 R");
    if( CoEd == DRF+BU) writeAlg( "F1 U F U R U1 R1");

    if( CoEd == RFD+FR) writeAlg( "R2 B U B1 U1 R1 U R1");
    if( CoEd == RFD+RF) writeAlg( "R U1 R1 U R U2 R2 F R F1");
    if( CoEd == RFD+UR) writeAlg( "U");
    if( CoEd == RFD+UL) writeAlg( "U1");
    if( CoEd == RFD+UB) writeAlg( "U2");
    if( CoEd == RFD+BU) writeAlg( "U");
    if( CoEd == RFD+FU) writeAlg( "U1");
    if( CoEd == RFD+LU) writeAlg( "U2");
    if( CoEd == RFD+UF) writeAlg( "R U R1 U1 F R1 F1 R");
    if( CoEd == RFD+RU) writeAlg( "R U R1 U1 R U R1");

    if( CoEd == FDR+FR) writeAlg( "R U1 R U B U1 B1 R2");
    if( CoEd == FDR+RF) writeAlg( "R U R1 U1 R U2 R1 U1 R U R1");
    if( CoEd == FDR+UR) writeAlg( "U");
    if( CoEd == FDR+UL) writeAlg( "U1");
    if( CoEd == FDR+UB) writeAlg( "U2");
    if( CoEd == FDR+BU) writeAlg( "U");
    if( CoEd == FDR+FU) writeAlg( "U1");
    if( CoEd == FDR+LU) writeAlg( "U2");
    if( CoEd == FDR+UF) writeAlg( "F1 U1 F U F1 U1 F");
    if( CoEd == FDR+RU) writeAlg( "R U1 R2 F R F1");

    if( CoEd == UFR+UB) writeAlg( "U2 R U R1 F1 U1 F");
    if( CoEd == UFR+BU) writeAlg( "U R U2 R2 F R F1");
    if( CoEd == UFR+UL) writeAlg( "U1 F1 U2 F2 R1 F1 R");
    if( CoEd == UFR+LU) writeAlg( "U2 R U R2 F R F1");
    if( CoEd == UFR+UR) writeAlg( "U2 F2 U2 F U F1 U F2");
    if( CoEd == UFR+RU) writeAlg( "R U2 R1 U1 R U R1");
    if( CoEd == UFR+UF) writeAlg( "F1 U2 F U F1 U1 F");
    if( CoEd == UFR+FU) writeAlg( "U2 R2 U2 R1 U1 R U1 R2");
    if( CoEd == UFR+FR) writeAlg( "R U1 R1 F1 U2 F");
    if( CoEd == UFR+RF) writeAlg( "R U R1 U1 R U R1 U1 R U R1");

    if( CoEd == RUF+UB) writeAlg( "U F1 U2 F U1 F R1 F1 R");
    if( CoEd == RUF+BU) writeAlg( "R U R1");
    if( CoEd == RUF+UL) writeAlg( "U F1 U1 F U1 F R1 F1 R");
    if( CoEd == RUF+LU) writeAlg( "U1 R U R1 U R U R1");
    if( CoEd == RUF+UR) writeAlg( "R U1 R1 U2 F1 U1 F");
    if( CoEd == RUF+RU) writeAlg( "U1 R U1 R1 U R U R1");
    if( CoEd == RUF+UF) writeAlg( "F R1 F1 R");
    if( CoEd == RUF+FU) writeAlg( "U F1 U2 F U1 R U R1");
    if( CoEd == RUF+FR) writeAlg( "U F1 U1 F U1 R U R1");
    if( CoEd == RUF+RF) writeAlg( "U F1 U F U1 F R1 F1 R");

    if( CoEd == FRU+UB) writeAlg( "U1 R U1 R1 U F1 U1 F");
    if( CoEd == FRU+BU) writeAlg( "U1 R U R1 U R1 F R F1");
    if( CoEd == FRU+UL) writeAlg( "F1 U1 F");
    if( CoEd == FRU+LU) writeAlg( "U1 R U2 R1 U R1 F R F1");
    if( CoEd == FRU+UR) writeAlg( "U1 R U2 R1 U F1 U1 F");
    if( CoEd == FRU+RU) writeAlg( "R1 F R F1");
    if( CoEd == FRU+UF) writeAlg( "U F1 U F U1 F1 U1 F");
    if( CoEd == FRU+FU) writeAlg( "F1 U F U2 R U R1");
    if( CoEd == FRU+FR) writeAlg( "U1 R U R1 U F1 U1 F");
    if( CoEd == FRU+RF) writeAlg( "U1 R U1 R1 U R1 F R F1");  
    m.d1();
    return 0;
}
void CROSS(){
    cross1( 119114);
    cross1( 119103);
    cross1( 119111);
    cross1( 119098);
}
void F2L(){
    f2l( 119103114, 103114);
    f2l( 119111103, 111103); cout<<endl<<"            ";
    f2l( 119098111,  98111);
    f2l( 119114098, 114098);
}
void OBB(){
    if( FU + RU + BU + LU - 484000 == 426) writeAlg( "F1 U1 L1 U L F");
    if( u.w + u.x == 242 && u.y + u.z != 242) m.U();
    if( u.x + u.z == 242 && u.w + u.y != 242) m.U2();
    if( u.y + u.z == 242 && u.w + u.x != 242) m.U1();
    if( u.w + u.z == 242 && u.x + u.y != 242) m.U();
    if( u.w + u.y == 242 && u.x + u.z != 242) writeAlg( "F1 U1 L1 U L F");
    if( u.x + u.y == 242 && u.w + u.z != 242) writeAlg( "F1 L1 U1 L U F");

    if( l.a + l.b + r.a + r.b == 484) writeAlg( "B U2 B1 U1 B U B1 U1 B U1 B1");
    if( f.a + f.b + b.c + b.d == 484) writeAlg( "R U2 R1 U1 R U R1 U1 R U1 R1");

    if( f.a + f.b + l.a + r.b == 484) writeAlg( "B1 U F U1 B U1 F1 U1 F U1 F1");
    if( r.a + r.b + b.c + f.a == 484) writeAlg( "L U1 R1 U L1 U R U R1 U R");
    if( b.c + b.d + l.b + r.a == 484) writeAlg( "F1 U B U1 F U1 B1 U1 B U1 B1");
    if( l.a + l.b + b.d + f.b == 484) writeAlg( "R1 U L U1 R U1 L1 U1 L U1 L1");

    if( l.a + f.a + r.a + u.b == 484) writeAlg( "R U2 R1 U1 R U1 R1");
    if( f.a + r.a + b.d + u.a == 484) writeAlg( "R1 U L U1 R U L1");
    if( r.a + b.d + l.a + u.c == 484) writeAlg( "L U2 L1 U1 L U1 L1");
    if( b.d + l.a + f.a + u.d == 484) writeAlg( "L1 U R U1 L U R1");

    if( b.c + l.b + f.b + u.b == 484) writeAlg( "L U1 R1 U L1 U1 R");
    if( l.b + f.b + r.b + u.a == 484) writeAlg( "L1 U2 L U L1 U L");
    if( f.b + r.b + b.c + u.c == 484) writeAlg( "R U1 L1 U R1 U1 L");
    if( r.b + b.c + l.b + u.d == 484) writeAlg( "R1 U2 R U R1 U R");

    if( u.a + u.b + l.b + r.a == 484) writeAlg( "F R B1 R1 F1 R B R1");
    if( u.c + u.a + f.b + b.d == 484) writeAlg( "R1 F1 L F R F1 L1 F");
    if( u.d + u.c + r.b + l.a == 484) writeAlg( "B1 R1 F R B R1 F1 R ");
    if( u.b + u.d + b.c + f.a == 484) writeAlg( "L F R1 F1 L1 F R F1");

    if( u.a + u.c + r.a + r.b == 484) writeAlg( "B2 D B1 U2 B D1 B1 U2 B1");
    if( u.c + u.d + b.c + b.d == 484) writeAlg( "L2 D L1 U2 L D1 L1 U2 L1");
    if( u.d + u.b + l.a + l.b == 484) writeAlg( "F2 D F1 U2 F D1 F1 U2 F1");
    if( u.b + u.a + f.a + f.b == 484) writeAlg( "R2 D R1 U2 R D1 R1 U2 R1");

    if( u.b + u.c + r.a + b.c == 484) writeAlg( "R B1 R1 F R B R1 F1");
    if( u.a + u.d + b.d + l.b == 484) writeAlg( "B L1 B1 R B L B1 R1");
    if( u.c + u.b + l.a + f.b == 484) writeAlg( "L F1 L1 B L F L1 B1");
    if( u.a + u.d + f.a + r.b == 484) writeAlg( "F R1 F1 L F R F1 L1");
}
void PLL(){
    count = 1;
    while( count <=4){
    if( f.a==f.b && f.b==l.w &&
        r.a==r.b && r.b==f.w &&
        l.a==l.b && l.b==r.w &&
        b.c==b.z && b.z==b.d) { writeAlg( "R U1 R U R U R U1 R1 U1 R2");  break;}

    if( f.a==f.b && f.b==r.w &&
        r.a==r.b && r.b==l.w &&
        l.a==l.b && l.b==f.w &&
        b.c==b.z && b.z==b.d) { writeAlg( "R2 U R U R1 U1 R1 U1 R1 U R1");  break;}

    if( f.a==f.b && f.b==b.z &&
        r.a==r.b && r.b==l.w &&
        l.a==l.b && l.b==r.w &&
        b.c==b.d && b.d==f.w) { writeAlg( "M2 U1 M2 U2 M2 U1 M2");  break;}

    if( f.a==f.b && f.b==l.w &&
        r.a==r.b && r.b==b.z &&
        l.a==l.b && l.b==f.w &&
        b.c==b.d && b.d==r.w) { writeAlg( "M2 U1 M2 U1 M U2 M2 U2 M U2");  break;}

    if( f.w==r.a && r.a==r.b &&
        r.w==b.d && b.d==l.b &&
        l.a==l.w && l.w==f.b &&
        b.c==b.z && b.z==f.a) { writeAlg( "R2 F2 R1 B1 R F2 R1 B R1");  break;}

    if( f.w==b.d && b.d==l.b &&
        r.w==f.a && f.a==f.b &&
        l.a==l.w && l.w==r.b &&
        b.c==b.z && b.z==r.a) { writeAlg( "R B1 R F2 R1 B R F2 R2");  break;}

    if( f.w==r.b && r.b==l.a &&
        r.w==b.d && b.d==f.b &&
        l.w==f.a && f.a==b.c &&
        b.z==l.b && l.b==r.a) { writeAlg( "R B1 R1 F R B R1 F1 R B R1 F R B1 R1 F1");  break;}

    if( f.a==f.w && f.w==r.b &&
        r.a==b.c && b.c==b.z &&
        l.a==l.b && l.b==r.w &&
        b.d==l.w && l.w==f.b) { writeAlg( "R U R1 U1 R1 F R2 U1 R1 U1 R U R1 F1");  break;}

    if( f.w==r.a && r.a==l.b &&
        r.w==l.a && l.a==f.b &&
        l.w==f.a && f.a==r.b &&
        b.c==b.z && b.z==b.d) { writeAlg( "R1 U2 R1 U1 B1 R1 B2 U1 B1 U B1 R B U1 R");  break;}

    if( f.a==f.w && f.w==r.b &&
        r.a==r.w && r.w==b.c &&
        l.a==l.w && l.w==l.b &&
        b.d==b.z && b.z==f.b) { writeAlg( "L1 R1 U2 R U R1 U2 L U1 R U");  break;}

    if( f.a==b.c && b.c==b.z &&
        r.a==r.w && r.w==r.b &&
        l.a==f.w && f.w==f.b &&
        b.d==l.w && l.w==l.b) { writeAlg( "R L U2 L1 U1 L U2 R1 U L1 U1");  break;}

    if( f.a==f.b && f.b==r.w &&
        r.a==b.c && b.c==f.w &&
        l.a==r.b && r.b==b.z &&
        b.d==l.w && l.w==l.b) { writeAlg( "R1 U2 R U2 R1 F R U R1 U1 R1 F1 R2 U1");  break;}

    if( f.a==f.b && f.b==l.w &&
        r.a==r.w && r.w==b.c &&
        l.a==r.b && r.b==b.z &&
        b.d==l.b && l.b==f.w) { writeAlg( "L U2 L1 U2 L F1 L1 U1 L U L F L2 U");  break;}

    if( f.a==b.c && b.c==b.z &&
        r.a==l.b && l.b==f.w &&
        l.a==l.w && l.w==r.b &&
        b.d==f.b && f.b==r.w) { writeAlg( "L1 U R U1 L U L1 U R1 U1 L U2 R U2 R1");  break;}

    if( f.a==f.w && f.w==b.c &&
        r.a==b.z && b.z==l.b &&
        l.a==r.w && r.w==r.b &&
        b.d==l.w && l.w==f.b) { writeAlg( "F R U1 R1 U1 R U R1 F1 R U R1 U1 R1 F R F1");  break;}

    if( f.a==b.a && b.c==b.z &&
        r.a==l.w && l.w==l.w &&
        l.a==r.w && r.w==r.b &&
        b.d==f.w && f.w==f.b) { writeAlg( "L U1 R U2 L1 U R1 L U1 R U2 L1 U R1 U1");  break;}

    if( f.a==f.w && f.w==b.c &&
        r.a==r.w && r.w==l.b &&
        l.a==l.w && l.w==r.b &&
        b.d==b.z && b.z==f.b) { writeAlg( "R1 U L1 U2 R U1 L R1 U L1 U2 R U1 L U");  break;}

    if( f.a==r.b && r.b==b.z &&
        r.a==r.w && r.w==b.c &&
        l.a==l.b && l.b==f.w &&
        b.d==l.w && l.w==f.b) { writeAlg( "R U R1 F2 u1 F U1 F1 U F1 u F2");  break;}

    if( f.a==r.w && r.w==b.c &&
        r.a==r.b && r.b==f.w &&
        l.a==f.b && f.b==b.z &&
        b.d==l.w && l.w==l.b) { writeAlg( "L1 U1 L F2 u F1 U F U1 F u1 F2");  break;}

    if( f.a==r.b && r.b==l.w &&
        r.a==r.w && r.w==l.b &&
        l.a==f.b && f.b==b.z &&
        b.c==f.w && f.w==b.d) { writeAlg( "F2 u1 F U1 F U F1 u F2 R U1 R1");  break;}

    if( f.a==r.b && r.b==b.z &&
        r.a==l.w && l.w==l.b &&
        l.a==f.b && f.b==r.w &&
        b.c==f.w && f.w==b.d) { writeAlg( "F2 u F1 U F1 U1 F u1 F2 L1 U L");  break;}
    m.U();
    count++;
   }
   while( f.w != f.n) m.U();
}
void scramble(){
	srand(time(NULL));
	cout<<"  - Scramble: ";
	for(int j=1;j<=20;j++){
		int random=rand()%17;
		switch (random){
			case  0: m.R();  break;
			case  1: m.R2(); break;
			case  2: m.R1(); break;
			case  3: m.L();  break;
			case  4: m.L2(); break;
			case  5: m.L1(); break;
			case  6: m.F();  break;
			case  7: m.F2(); break;
			case  8: m.F1(); break;
			case  9: m.B();  break;
			case 10: m.B2(); break;
			case 11: m.B1(); break;
			case 12: m.U();  break;
			case 13: m.U2(); break;
			case 14: m.U1(); break;
			case 15: m.D();  break;
			case 16: m.D2(); break;
			case 17: m.D1(); break;
		}
	}
    total=0;
    cout<<endl;
}
void setcolorfromkeyboard(){
    cout<<"Set color on UP surface    : ";
    cin>>u.a>>u.w>>u.b>>u.x>>u.n>>u.y>>u.c>>u.z>>u.d;
	cout<<"Set color on FRONT surface : ";
    cin>>f.a>>f.w>>f.b>>f.x>>f.n>>f.y>>f.c>>f.z>>f.d;
	cout<<"Set color on DOWN surface  : ";
    cin>>d.a>>d.w>>d.b>>d.x>>d.n>>d.y>>d.c>>d.z>>d.d;
	cout<<"Set color on LEFT surface  : ";
    cin>>l.a>>l.w>>l.b>>l.x>>l.n>>l.y>>l.c>>l.z>>l.d;
	cout<<"Set color on RIGHT surface : ";
    cin>>r.a>>r.w>>r.b>>r.x>>r.n>>r.y>>r.c>>r.z>>r.d;
	cout<<"Set color on BEHIND surface: ";
    cin>>b.a>>b.w>>b.b>>b.x>>b.n>>b.y>>b.c>>b.z>>b.d;
    pEdge(); pCorner();
}
void input(){
    cout<<"Wanna scramble? Yes or No ? "; cin>>sw;
    if( sw=="yes" || sw=="Yes" || sw=="y" || sw=="YES" || sw=="ok" || sw=="Ok" || sw=="OK"){
        setcolor(); 
        scramble();
    }
    else setcolorfromkeyboard();
}
void solve(){
    cout<<endl<<"  - CROSS : "; CROSS(); cout<<total<<endl;
    cout<<endl<<"  - F2L   : "; F2L(); cout<<total<<endl;
    cout<<endl<<"  - OBB   : "; OBB(); cout<<total<<endl;
    cout<<endl<<"  - PLL   : "; PLL(); cout<<total<<endl;
    cout<<endl<<"	Total: "<<total<<" moves"<<endl;
}
int main(){
    /*clock_t start, end;
    double time;
    cout<<endl<<endl;
    cout<<"     ||||||||||||||||||||||||||||||||||||||||||||||||||||||||  "<<endl;
    cout<<"    ||                                                      || "<<endl;
    cout<<"    ||                  SOLVING RUBIK CUBE:                 || "<<endl;
    cout<<"    ||                                                      || "<<endl;
    cout<<"    ||                   WISH YOU HAVE FUN                  || "<<endl;
    cout<<"    ||                                                      || "<<endl;
    cout<<"    ||                                                      || "<<endl;
    cout<<"    ||                                    author: kant      || "<<endl;
    cout<<"     ||||||||||||||||||||||||||||||||||||||||||||||||||||||||  "<<endl<<endl<<endl;
    input();
    start=clock();
    solve();
    end=clock();
    time=(double)(end-start)/CLOCKS_PER_SEC;
    cout<<endl<<"   Time to solve: "<<time<<"s"<<endl;*/
    int dem = 0;
    setcolor();
    writeAlg("F R B L");
    while (f.x != 'r' or f.a != 'r' or f.y != 'r' or f.b !='r' or f.c !='r' or f.z != 'r' or f.w !='r' or f.d != 'r'){
        writeAlg("F R B L");
        dem ++;
    }
    cout<<dem;
    cout<<endl<<u.a<<u.w<<u.b<<u.x<<u.n<<u.y<<u.c<<u.z<<u.d<<endl;
cout<<f.a<<f.w<<f.b<<f.x<<f.n<<f.y<<f.c<<f.z<<f.d<<endl;
cout<<d.a<<d.w<<d.b<<d.x<<d.n<<d.y<<d.c<<d.z<<d.d<<endl;
cout<<l.a<<l.w<<l.b<<l.x<<l.n<<l.y<<l.c<<l.z<<l.d<<endl;
cout<<r.a<<r.w<<r.b<<r.x<<r.n<<r.y<<r.c<<r.z<<r.d<<endl;
cout<<b.a<<b.w<<b.b<<b.x<<b.n<<b.y<<b.c<<b.z<<b.d<<endl;




    system("pause");
}