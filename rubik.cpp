#include <iostream>
#include <fstream>
#include <windows.h>
#include <ctime>
using namespace std;
char w[9], wh[9], y[9], ye[9], r[9], re[9], o[9], oe[9], b[9], bl[9], g[9], gr[9];
int i, total=0, random, pastrandom=-2, j, check1=0, check2=0, total2, total3, total4, e=0, k=0;
char x, z, t;
					//lap trinh ki tu xoay cua rubik

void R(){
	for( i=3; i<=9; i=i+3){
		re[i]=r[i]; r[i]=w[i]; w[i]=o[i]; o[i]=y[i]; y[i]=re[i];
    }
	gr[1]=g[1]; g[1]=g[7]; g[7]=g[9]; g[9]=g[3]; g[3]=gr[1];
	gr[2]=g[2]; g[2]=g[4]; g[4]=g[8]; g[8]=g[6]; g[6]=gr[2];
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
	for( i=1; i<=7; i=i+3){
		re[i]=r[i]; r[i]=y[i]; y[i]=o[i]; o[i]=w[i]; w[i]=re[i];		
	}
	bl[1]=b[1]; b[1]=b[7]; b[7]=b[9]; b[9]=b[3]; b[3]=bl[1];
	bl[2]=b[2]; b[2]=b[4]; b[4]=b[8]; b[8]=b[6]; b[6]=bl[2];
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
	for( i=1; i<=3; i++){
		bl[3*i]=b[3*i]; b[3*i]=w[i]; w[i]=g[10-3*i]; g[10-3*i]=y[10-i]; y[10-i]=bl[3*i];
	}
	re[1]=r[1]; r[1]=r[7]; r[7]=r[9]; r[9]=r[3]; r[3]=re[1];
	re[2]=r[2]; r[2]=r[4]; r[4]=r[8]; r[8]=r[6]; r[6]=re[2];
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
	for( i=1; i<=3; i++){
		gr[3*i]=g[3*i]; g[3*i]=w[10-i]; w[10-i]=b[10-3*i]; b[10-3*i]=y[i]; y[i]=gr[3*i];
	}
	oe[1]=o[1]; o[1]=o[7]; o[7]=o[9]; o[9]=o[3]; o[3]=oe[1];
	oe[2]=o[2]; o[2]=o[4]; o[4]=o[8]; o[8]=o[6]; o[6]=oe[2];
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
	for( i=1; i<=3; i++){
		re[i]=r[i]; r[i]=g[i]; g[i]=o[10-i]; o[10-i]=b[i]; b[i]=re[i];
	}
	ye[1]=y[1]; y[1]=y[7]; y[7]=y[9]; y[9]=y[3]; y[3]=ye[1];
	ye[2]=y[2]; y[2]=y[4]; y[4]=y[8]; y[8]=y[6]; y[6]=ye[2];
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
	for( i=7; i<=9; i++){
		re[i]=r[i]; r[i]=b[i]; b[i]=o[10-i]; o[10-i]=g[i]; g[i]=re[i]; 
	}
	wh[1]=w[1]; w[1]=w[7]; w[7]=w[9]; w[9]=w[3]; w[3]=wh[1];
	wh[2]=w[2]; w[2]=w[4]; w[4]=w[8]; w[8]=w[6]; w[6]=wh[2];
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
void d1(){
	D1();
	for( i=4; i<=6; i++){
		re[i]=r[i]; r[i]=g[i]; g[i]=o[10-i]; o[10-i]=b[i]; b[i]=re[i]; 
	}
	cout<<"\b\b\b\b d1 ";
}

					//nhap mau cho rubik

void setcolor(){
	ifstream ru;
	ru.open("C://Users//fptshop//Documents//C++//rubik.txt");
	//cout<<"Set color on White plane surface:  ";
		for( i=1; i<=9; i++){
			ru>>w[i];
		}
	//cout<<"Set color on Orange plane surface: ";
		for( i=1; i<=9; i++){
			ru>>o[i];
		}
	//cout<<"Set color on  Blue plane surface:   ";
		for( i=1; i<=9; i++){
			ru>>b[i];
		}
	//cout<<"Set color on  Green plane surface:  ";
		for( i=1; i<=9; i++){
			ru>>g[i];
		}
	//cout<<"Set color on  Red plane surface:    ";
		for( i=1; i<=9; i++){
			ru>>r[i];
		}
	//cout<<"Set color on  Yellow plane surface: ";
		for( i=1; i<=9; i++){
			ru>>y[i];
		}
}
					//scramble rubik

void scramble(){
	srand(time(NULL));
	cout<<"  - Scramble: ";
	for(j=1;j<=20;j++){
		random=rand()%17;
		switch (random){
			case  0: R();  break;
			case  1: R2(); break;
			case  2: R1(); break;
			case  3: L();  break;
			case  4: L2(); break;
			case  5: L1(); break;
			case  6: F();  break;
			case  7: F2(); break;
			case  8: F1(); break;
			case  9: B();  break;
			case 10: B2(); break;
			case 11: B1(); break;
			case 12: U();  break;
			case 13: U2(); break;
			case 14: U1(); break;
			case 15: D();  break;
			case 16: D2(); break;
			case 17: D1(); break;
		}
	}
}
void checkS(){
	if( w[2]=='w' && w[4]=='w' && w[6]=='w' && w[8]=='w' && r[8]=='r' && b[8]=='b' && g[8]=='g' && o[2]=='o'){ check1=1;}
	if( w[2]=='w' && w[4]=='w' && w[6]=='w' && w[8]=='w' && r[8]=='b' && b[8]=='o' && g[8]=='r' && o[2]=='g'){ D1(); check1=1;}
	if( w[2]=='w' && w[4]=='w' && w[6]=='w' && w[8]=='w' && r[8]=='g' && b[8]=='r' && g[8]=='o' && o[2]=='b'){ D(); check1=1;}
	if( w[2]=='w' && w[4]=='w' && w[6]=='w' && w[8]=='w' && r[8]=='o' && b[8]=='g' && g[8]=='b' && o[2]=='r'){ D2(); check1=1;}
	if( w[1]=='w' && w[3]=='w' && w[7]=='w' && w[9]=='w' && r[9]=='r' && b[9]=='b' && g[9]=='g' && o[1]=='o'){ check2=1;}
	if( w[1]=='w' && w[3]=='w' && w[7]=='w' && w[9]=='w' && r[9]=='b' && b[9]=='o' && g[9]=='r' && o[1]=='g'){ D1(); check2=1;}
	if( w[1]=='w' && w[3]=='w' && w[7]=='w' && w[9]=='w' && r[9]=='g' && b[9]=='r' && g[9]=='o' && o[1]=='b'){ D(); check2=1;}
	if( w[1]=='w' && w[3]=='w' && w[7]=='w' && w[9]=='w' && r[9]=='o' && b[9]=='g' && g[9]=='b' && o[1]=='r'){ D2(); check2=1;}
}
					//lam tang mot

int cross1( char x, char z){
			if( w[2]==x && r[8]==z){ F2();}
	
		if( r[4]==z && b[6]==x){ F();}
		if( r[6]==z && g[4]==x){ F1();}

	if( o[8]==x && y[2]==z){ U2(); F2();}
	if( o[8]==z && y[2]==x){ U(); R1(); F(); R();}	
	if( b[2]==x && y[4]==z){ U1(); F2();}
	if( b[2]==z && y[4]==x){ L(); F1(); L1();}
	if( g[2]==x && y[6]==z){ U(); F2();}
	if( g[2]==z && y[6]==x){ R1(); F(); R();}	
	if( r[2]==x && y[8]==z){ F2();}
	if( r[2]==z && y[8]==x){ U1(); R1(); F(); R();}

			if( o[2]==z && w[8]==x){ B();}
			if( g[8]==z && w[6]==x){ R();}

		if( r[4]==x && b[6]==z){ F1();}
		if( r[6]==x && g[4]==z){ F();}
		if( o[4]==x && b[4]==z){ L2(); F1(); L2();}
		if( o[4]==z && b[4]==x){ L(); U1(); L1(); F2();}
		if( o[6]==x && g[6]==z){ R2(); F(); R2();}
		if( o[6]==z && g[6]==x){ R1(); U(); R(); F2();}

			if( g[8]==x && w[6]==z){ D1(); F(); D(); F1();}
			if( b[8]==x && w[4]==z){ D();}
			if( o[2]==x && w[8]==z){L1(); D2(); L();}
			if( b[8]==z && w[4]==x){ L1(); F1();}
	D1();
	return 0;
}
int corner1( char x, char z, char t){
	if(e==2) cout<<endl<<"                  ";
	while(( r[9]==t && w[3]==z && g[7]==x)==false){
		if(( b[7]==x && w[7]==z && o[1]==t) || ( b[7]==t && w[7]==x && o[1]==z))
			{ L(); U1(); L1();}
		if(( g[9]==t && w[9]==z && o[3]==x) || ( g[9]==x && w[9]==t && o[3]==z))
			{ R1(); U(); R();}
		if(( r[3]==x && y[9]==z && g[1]==t) || ( b[3]==z && y[7]==t && r[1]==x) || ( r[9]==z && w[3]==x && g[7]==t))
			{ R(); U1(); R1();}
		if(( o[7]==x && y[1]==z && b[1]==t) || ( r[3]==t && y[9]==x && g[1]==z) || ( r[9]==x && w[3]==t && g[7]==z))
			{ R(); U(); R1();}
		if(( b[3]==x && y[7]==z && r[1]==t) || ( b[3]==t && y[7]==x && r[1]==z) || ( o[7]==z && y[1]==t && b[1]==x))
			{ U1();}
		if(( g[3]==x && y[3]==z && o[9]==t) || ( o[7]==t && y[1]==x && b[1]==z) || ( r[3]==z && y[9]==t && g[1]==x))
			{ U();}
			if( g[3]==z && y[3]==t && o[9]==x){ U2();}
			if( g[3]==t && y[3]==x && o[9]==z){ F1(); U(); F();}
			if( r[7]==t && w[1]==x && b[9]==z){ L1(); U1(); L();}
			if( r[7]==z && w[1]==t && b[9]==x){ L1(); U(); L();}
			if( b[7]==z && w[7]==t && o[1]==x){ L(); U(); L1();}
			if( r[7]==x && w[1]==z && b[9]==t){ D();}
			if( g[9]==z && w[9]==x && o[3]==t){ R1(); U1(); R();}
	
	}
	D1();
	e++;
	return 0;
}
void firstlayer(){
	cout<<"	+ Cross : ";
	cross1( 'r', 'w'); 
	cross1( 'g', 'w'); 
	cross1( 'o', 'w'); 
	cross1( 'b', 'w');
	cout<<endl<<"	+ Corner: ";
	corner1( 'g', 'w', 'r');
	corner1( 'o', 'w', 'g');
	corner1( 'b', 'w', 'o');
	corner1( 'r', 'w', 'b');
}

					//lam tang hai

int middle( char x, char z){ 
	if(e==2) cout<<endl<<"                  ";
		if( r[6]==z && g[4]==x){ R(); U1(); R1();U(); F1(); U2(); F(); U1(); F(); R1(); F1(); R();}
		if(( r[4]==x && b[6]==z) || ( r[4]==z && b[6]==x)){ L1(); U(); L(); U(); F(); U1(); F1();}
		if(( o[4]==x && b[4]==z) || ( o[4]==z && b[4]==x)){ L(); U1(); L1(); U1(); B1(); U(); B();}
		if(( o[6]==x && g[6]==z) || ( o[6]==z && g[6]==x)){ R1(); U(); R(); U(); B(); U1(); B1(); }
	if(( y[4]==x && b[2]==z) || ( y[8]==z && r[2]==x)){ U();}
	if(( y[6]==x && g[2]==z) || ( y[2]==z && o[8]==x)){ U1();}
	if(( y[8]==x && r[2]==z) || ( y[6]==z && g[2]==x)){ U2();}
	if( y[2]==x && o[8]==z){ F1(); U(); F(); U(); R(); U1(); R1();}
	if( y[4]==z && b[2]==x){ R(); U1(); R1(); U1(); F1(); U(); F();}
	d1();
	e++;
	return 0;
}
void secondlayer(){
	e=0;
	middle( 'r', 'g');
	middle( 'g', 'o');
	middle( 'o', 'b');
	middle( 'b', 'r');
}

					//lam tang cuoi
int cross3( char x, char z){
	if( y[2]!='y' && y[4]!='y' && y[6]!='y' && y[8]!='y'){ F1(); L1(); U1(); L(); U(); F();}
	if( y[2]=='y' && y[6]=='y' && y[8]!='y' && y[4]!='y'){ F1(); U1(); L1(); U(); L(); F();}
	if( y[4]=='y' && y[2]=='y' && y[6]!='y' && y[8]!='y'){ F(); U(); R(); U1(); R1(); F1();}
	if( y[6]=='y' && y[8]=='y' && y[4]!='y' && y[2]!='y'){ L1(); U1(); B1(); U(); B(); L();}
	if( y[8]=='y' && y[4]=='y' && y[2]!='y' && y[6]!='y'){ R(); U(); B(); U1(); B1(); R1();}
	if( y[2]=='y' && y[8]=='y' && y[4]!='y' && y[6]!='y'){ R(); U(); B(); U1(); B1(); R1();}
	if( y[4]=='y' && y[6]=='y' && y[2]!='y' && y[8]!='y'){ F1(); U1(); L1(); U(); L(); F();}
	/*if( r[2])
	*/return 0;
}
//int corner3(){}
void lastlayer(){}
int main(){
total=0;
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
setcolor();
scramble(); cout<<endl<<endl;
//if( k%2!=0) cout<<" CAN'T SOLVE. PLEASE CHECK THE RUBIK CUBE ^.^ "; goto cannot;
checkS();
if( check1==1){ 
	cout<<"  - FIRST LAYER :  IT'S SOLVED "<<endl;
	goto sl;
}
cout<<"  - FIRST LAYER :  "<<endl; firstlayer();cout<<endl;
sl: 
if( check2==1){
	cout<<"  - SECOND LAYER: IT'S SOLVED "<<endl;
	goto ll;
}
cout<<endl<<"  - SECOND LAYER: "; secondlayer();
ll:
cout<<endl<<"	Total: "<<total-20<<" moves"<<endl;
cannot:
//ru.close();
system("pause");
}
