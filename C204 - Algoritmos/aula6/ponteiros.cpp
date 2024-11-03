#include<iostream>
using namespace std;

struct ponto {
	int x, y;
};

int main(){
	
	int a;
	a = 5;
	
	cout << "Conteudo de a: " << a << endl;
	cout << "endereco de a: " << &a << endl;
	cout << "Conteudo armazenado no endereco de a: " << *&a << endl;
		
	int * p;
	
	p = &a;
	
	cout << "Conteudo de p: " << p << endl;
	cout << "endereco de p: " << &p << endl;
	cout << "Conteudo armazenado no endereco apontado por p: " << *p << endl;
	
	*p = 7;
	
	cout << "Conteudo de a alterado por p: " << a << endl;
	
	
	int b[10] = {0,1,2,3,4,5,6,7,8,9};
	
	cout << "Conteudo de b: " << b << endl;
	cout << "endereco de b: " << &b << endl;
	cout << "Conteudo armazenado no endereco de b: " << *&b << endl;
	
	p = b;
	
	cout << "Conteudo de p: " << p << endl;
	cout << "endereco de p: " << &p << endl;
	cout << "Conteudo armazenado no endereco apontado por p: " << *p << endl;
	
	
	cout << "Conteudo de b na terceira posicao: " << b[4] << endl;
	cout << "endereco de b na quarta posicao: " << &b[4] << endl;
	
	cout << "Conteudo de b na terceira posicao usando p: " << *(p+4) << endl;
	
	ponto ponto1 = {5,10};
	
	cout << "Conteudo de x de ponto1: " << ponto1.x << endl;
	cout << "Conteudo de y de ponto1: " << ponto1.y << endl;
	cout << "endereco de ponto1: " << &ponto1 << endl;
	cout << "endereco de x de ponto1: " << &ponto1.x << endl;
	cout << "endereco de y de ponto1: " << &ponto1.y << endl;
	
	ponto * ptr_ponto;
	
	ptr_ponto = &ponto1;
	
	cout << "Conteudo de ptr_ponto: " << ptr_ponto << endl;
	cout << "Conteudo de x do endereco apontado por ptr_ponto: " 
	<< ptr_ponto->x << endl;
	cout << "Conteudo de y do endereco apontado por ptr_ponto: " 
	<< ptr_ponto->y << endl;
	
	
	ptr_ponto = new ponto;
	ptr_ponto->x = 13;
	ptr_ponto->y = 34;
	
	cout << "Conteudo de ptr_ponto alocado dinamicamente: " << ptr_ponto << endl;
	cout << "Conteudo de x do endereco apontado por ptr_ponto: " 
	<< ptr_ponto->x << endl;
	cout << "Conteudo de y do endereco apontado por ptr_ponto: " 
	<< ptr_ponto->y << endl;
	
	
	delete ptr_ponto;
	
	return 0;
}