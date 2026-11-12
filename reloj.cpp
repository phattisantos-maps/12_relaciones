#include<iostream>
#include<string>
using namespace std;
class Display{
	private:
		string tipo;
	public:
		Display(string tipo);
		string getTipo();
};
class Hora{
	private:
		int hora;
		int minutos;
		int segundos;
	public:
		Hora(int h,int m,int s);
		int getHora();
		int getMinutos();
		int getSegundos();
};
class Reloj{
	private:
		Display *pDisplay;
		Hora *pHora;
	public:
		Reloj(int h,int m,int s);
		void asignarDisplay(Display *pD);
		void mostrarReloj();
};
Display::Display(string tipo){
	this->tipo=tipo;
}
string Display::getTipo(){
	return tipo;
}
Hora::Hora(int h,int m,int s){
	hora=h;
	minutos=m;
	segundos=s;
}
int Hora::getHora(){
	return hora;
}
int Hora::getMinutos(){
	return minutos;
}
int Hora::getSegundos(){
	return segundos;
}
Reloj::Reloj(int h,int m,int s){
	pHora=new Hora(h,m,s);
	pDisplay=NULL;
}
void Reloj::asignarDisplay(Display *pD){
	pDisplay=pD;
}
void Reloj::mostrarReloj(){
	if(pDisplay!=NULL){
		if(pDisplay->getTipo()=="digital"){
			cout<<"[";
		}
		else{
			cout<<"-->";
		}
		if(pHora->getHora()<10)
			cout<<"0";
		cout<<pHora->getHora()<<":";
		if(pHora->getMinutos()<10)
			cout<<"0";
		cout<<pHora->getMinutos()<<":";
		if(pHora->getSegundos()<10)
			cout<<"0";
		cout<<pHora->getSegundos();
		if(pDisplay->getTipo()=="digital"){
			cout<<"]";
		}
		else{
			cout<<"<--";
		}
		cout<<endl;
	}
}
int main(){
	Display d1("digital");
	Display d2("analogico");
	Reloj reloj1(10,15,55);
	Reloj reloj2(10,15,55);
	reloj1.asignarDisplay(&d1);
	reloj2.asignarDisplay(&d2);
	reloj1.mostrarReloj();
	reloj2.mostrarReloj();
	return 0;
}
