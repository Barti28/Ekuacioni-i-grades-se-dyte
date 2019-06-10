#include <iostream>
#include<cmath>
using namespace std;

class llogaritRrenjet{
	public:
		llogaritRrenjet();
		llogaritRrenjet(double a,double b, double c);
	private:
		double a,b,c,x1;
		double x,rezultatrrenja[3],rezultatvlera[3]; //vektoret qe ruajne zgjidhjet e rrenjeve te ekuacionit
		double Dallori;
		bool kontrolluesi;

		void te_dhenat(); // funksioni ku perdoruesi fut te dhenat sipas deshires per koeficientat e ekuacionit
		void zgjidhdallorin(); // funksioni qe zgjidh dallorin
		void rrenja0();  // funksioni i cili zgjidh "x" ne rastin kur dallori eshte 0
		void rrenjalineare();  //funksioni qe zgjidh "x" kur ekuacioni behet i fuqise se pare
		void rrenjaepare();  //funksioni zgjidh rrenjen e pare te ekuacionit
		void rrenjaedyte();  //funksioni zgjidh rrenjen e dyte te ekuacionit
		void printorezultat();  //funksion i cili printon rezultatet e ekuacionit
		void vendosA(double);  //funksioni vendos te dhenat per vleren e A
		void vendosB(double);  //funksioni vendos te dhenat per vleren e B
		void vendosC(double);   //funksioni vendos te dhenat per vleren e C

};
void llogaritRrenjet::te_dhenat(){
cout<<"Ky eshte nje program qe do tiu ndihmoj ju per te zgjidhur ekuacionin e fuqise se dyte."<<endl;
	cout<<"\nVendosni koeficientin qe deshironi per A:"<<endl;
	cin>>a;
	vendosA(a);
	cout<<"\nVendosni koeficientin qe deshironi per B:"<<endl;
	cin>>b;
	vendosB(b);
	cout<<"\nVendosni koeficientin qe deshironi per C:"<<endl;
	cin>>c;
	vendosC(c);
}
// konstruktor qe krijon objektin
llogaritRrenjet::llogaritRrenjet()
{
	te_dhenat();
	zgjidhdallorin();
	printorezultat();
}
//konstruktor
llogaritRrenjet::llogaritRrenjet(double a, double b, double c)
{
	vendosA(a);
	vendosB(b);
	vendosC(c);
	zgjidhdallorin();
	printorezultat();
}
// funksioni qe zgjidh dallorin e ekuacionit dhe i jep vlere booleane variablit kontrolluesi e cila nevojitet me vone
void llogaritRrenjet::zgjidhdallorin()
{
	Dallori= (b*b)+(-4*a*c);
	if (Dallori>=0)
	kontrolluesi = false;
else
kontrolluesi = true;
}
void llogaritRrenjet::rrenjalineare()
{	x=(0-c)/b;
rezultatrrenja[0]=x;
}
void llogaritRrenjet::rrenja0()
{
	x=(0-b)/(2*a);
	 rezultatrrenja[1]=x;
}
void llogaritRrenjet::rrenjaepare()
{
	x=(0-b+ sqrt(Dallori))/(2*a);
	 rezultatrrenja[2]=x;
}

void llogaritRrenjet::rrenjaedyte()
{
    x1=(0-b- sqrt(Dallori))/(2*a);
     rezultatrrenja[3]=x1;
}
void llogaritRrenjet::printorezultat()    // trajtohen raste te ndryshme te vlerave te dhena nga perdoruesi per tre koeficientat e ekuacionit, atehere kur te tre jane 0
                                          // atehere kur a eshte 0 dhe rastet ku behet kontrolli nga variabli boolean kontrolluesi ne lidhje me vleren e dallorit
{
	if((a==0 ) && (b==0) && (c==0))
 	{cout<<"Ekuacioni nuk ka trajte kanonike te rregullt.\n";
 	cout<<"Ekuacioni ka zgjidhje te pafundme.";}

	else if(a==0) {
    	rrenjalineare();
    	cout<<"Ekuacioni ka trajte lineare:\n"<<"y="<<b<<"*x+"<<c<<endl;
    	if(c!=0) {
         cout<<"Pikeprerjet me boshtet gjysmedrejteza qe kalon nga pikat ("<<x<<";0)"<<" dhe (0;"<<c<<")"<<endl;}
         else{
         cout<<"Pikeprerja me boshtin kordinativ (0;0)"<<endl;
		 if (b<0){
		 cout<<"Vlerat e dhena per x dhe y do te gjenden ne gjysmedrejtezen qe kalon nga origjina ne kuadratin e 2 dhe te 4"<<endl;}
		 else {
		 cout<<"Vlerat e dhena per x dhe y do te gjenden ne gjysmedrejtezen qe kalon nga origjina ne kuadratin e 1 dhe te 3"<<endl;} 
		}}
	  else if(kontrolluesi)
	 {
	 cout<<"Ekuacioni ka trajte kanonike:\n"<<"y="<<a<<"x*x +"<<b<<"*x +"<<c<<endl;
	 cout<<"Vlera e Dallorit eshte:"<<Dallori<<endl;
 	cout<<"Ekuacioni qe keni vendosur nuk ka rrenje"<<endl;}
	 else
 	  {if(Dallori==0)
 	   {
 	    rrenja0() ;
	    cout<<"Ekuacioni ka trajte kanonike:\n"<<" y="<<a<<"x*x +"<<b<<"*x + "<<c<<endl;
 	   	cout<<"Vlera e Dallorit eshte: 0"<<endl;
		cout<< "Vlera e x(rrenja) eshte:"<<x<<endl;
		rezultatvlera[1]=a*x*x+b*x+c;
		cout<<"Vlera e ekuacionit eshte"<<rezultatvlera[1];}
 	  if (Dallori>0)
		{
		rrenjaepare();
		rrenjaedyte();
		cout<<"Ekuacioni ka trajte kanonike:\n"<<" y="<<a<<"x*x+"<<b<<"*x+"<<c<<endl;
		cout<<"Vlera e Dallorit eshte:"<<Dallori<<endl;
		cout<< "Vlera e x1(rrenja e pare) eshte:"<< x<<endl;
		cout<<" Vlera e x2(rrenja e dyte) eshte"<<x1<<endl;
        rezultatvlera[2]=a*x*x+b*x+c;
	    cout<<"Vlera e ekuacionit per x1 te gjetur eshte:"<<rezultatvlera[2]<<endl;
		rezultatvlera[3]=a*x1*x1+b*x1+c;
		cout<<"Vlera e ekuacionit per x2 te gjetur eshte:"<<rezultatvlera[3];}
	}
// vendos te dhenat e koeficientave
}
void llogaritRrenjet::vendosA(double A)
{
	a=A;
}
void llogaritRrenjet::vendosB(double B)
{
	b=B;
}
void llogaritRrenjet::vendosC(double C)
{
	c=C;
}
int main()  // pjesa e mainit qe ben thirrjen e te gjitha funksioneve te krijuara dhe ben qe programi te perseritet sa here deshiron perdoruesi
{
	perserit:
	llogaritRrenjet zgjidhja;
	cout<<"\nDo vazhdoni:Shtyp p per te vazhduar dhe cdo gje tjeter per te mbyllur programin.\n";
		string pergjigje;
		cin>>pergjigje;
		if(pergjigje =="p"||pergjigje=="P")
		goto perserit;
		else
	return 0;
}

