#include <fstream>
#include <iostream>
#include"number.h"
#include <cstdlib>
#include "FloatNumber.h"
using namespace std;

void TextTest() {
	cout << "Writing to a text file"<<endl;
	Number object1 = "2905981565662626262";
	Number object2 = "135";
	ofstream f1("text.txt");
	f1 << object1 << object2;
	f1.close();
	ifstream f("text.txt");
	Number object3, object4;
    f >> object4 >> object3;
	f.close();
	if (object3.getlength() == object2.getlength()) {
		int flag = 1;
		for (int i = 0; i < object3.getlength(); i++) {
			if (object3.getnumber(i) != object2.getnumber(i))
				flag = 0;
		}
		if (flag == 1)
			cout << "object3=object2" << endl <<"Object3- "<< object3<<endl << "Object2- " << object2 << endl;
		else cout << "Error with program!";
	}
	if (object4.getlength() == object1.getlength()) {
		int flag = 1;
		for (int i = 0; i < object1.getlength(); i++) {
			if (object4.getnumber(i) != object1.getnumber(i))
				flag = 0;
		}
		if (flag == 1)
			cout << "object4=object1" << endl << "Object4- "<< object4<<endl << "Object1- " << object1 << endl;
		else cout << "Error with program!";
	}
	Number object5;
	f >> object5;
	cout << "Expected message: File don't open!" << endl;
	cout << endl;
}

void BinnaryTest() {
	cout << "Writing to a binnary file" << endl;
	Number object6 = "369552255";
	Number object7 = "9856";
	Number object8 = "1345670000000000000000000";
	Number object9;
	Number object10;
	Number object11;
	fstream fin("test.dat", ios::in | ios::out | ios::binary | ios::cur);
	object6.writetobin(fin);
	object7.writetobin(fin);
	object8.writetobin(fin);
	fin.close();
	fstream fin1("test.dat", ios::in | ios::out | ios::binary | ios::cur);
	object9.readfrombin(fin1);
	object10.readfrombin(fin1);
	object11.readfrombin(fin1);
	fin1.close();
	if (object6.getlength() == object9.getlength()) {
		int flag = 1;
		for (int i = 0; i < object6.getlength(); i++) {
			if (object6.getnumber(i) != object9.getnumber(i))
				flag = 0;
		}
		if (flag == 1)
			cout << "object6=object9" << endl << "Object6- " << object6<<endl << "Object9- " << object9 << endl;
		else cout << "Error with program!";
	}
	if (object7.getlength() == object10.getlength()) {
		int flag = 1;
		for (int i = 0; i < object7.getlength(); i++) {
			if (object7.getnumber(i) != object10.getnumber(i))
				flag = 0;
		}
		if (flag == 1)
			cout << "object7=object10" << endl << "Object7- " << object7<<endl << "Object10- " << object10 << endl;
		else cout << "Error with program!";
	}
	if (object8.getlength() == object11.getlength()) {
		int flag = 1;
		for (int i = 0; i < object8.getlength(); i++) {
			if (object8.getnumber(i) != object11.getnumber(i))
				flag = 0;
		}
		if (flag == 1)
			cout << "object8=object11" << endl << "Object8- " << object8<<endl << "Object11- " << object11 << endl;
		else cout << "Error with program!";
	}
	Number object12;
	object12.writetobin(fin);
	cout << "Expected message: File don't open!" << endl;
}
void main() {
	TextTest();
	BinnaryTest();
	cin.get();
	cin.get();
}
