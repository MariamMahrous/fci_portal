#include<iostream>
#include<string>
#include<fstream>
#include "file_project.h"
using namespace std;


  // START IN STUDENT -------------
  void write_posts(){
	  char data[200];
	  fstream posts;
	  posts.open("stage1_post.txt", ios::out|ios::in|ios::app);
	  cout << "enter the post you went to enter" << endl;
	  cin.ignore();
	  cin.getline(data, 200);
	  posts << data << endl;
	  posts.close();
  }
  void display_all_data() {
  
	  fstream display;
	  display.open("all_data.txt", ios::in);
	  string line;
	  if (display.is_open()) {
		  while (getline(display, line)) {
			  cout << line << endl;
		  }
		  display.close();

	  }
	 
	  else
		  cout << "file is not opened" << endl;
	  cin.get();
  }
  void displaynew_data() {

	  fstream new_data;
	  new_data.open("stage1_post.txt", ios::in);
	  string li;
	  if (new_data.is_open()) {
		  while (getline(new_data, li)) {
			  cout << li << endl;
		  }
		  new_data.close();

	  }

	  else
		  cout << "file is not opened" << endl;
	  cin.get();
  }
void student_search() {
	// search for par_code to enter to the program
	int y = 0;
	
		fstream stud;
		stud.open("student_data.txt", ios::in | ios::out);
		char name[25];
		char par_code[25];
		char stage[3];
		char a[50];
		cin.ignore();
		cin.getline(a, 50);
		int stag;

		while (!stud.eof())
		{
			stud.getline(name, 25, '|');
			stud.getline(par_code, 25, '|');
			stud.getline(stage, 3);
			if (strcmp(par_code, a) == 0) {
				cout << "\n \t name  \t par_code \t stage \n";
				cout << "welcome : " << name << "\t" << par_code << "\t \t" << stage << endl;
				y = 1;

				cout << "enter the stage you went to enter to it " << endl;

				cin >> stag;
				// enter 
				if (stag == 1) {
					cout << " if you went to\t post enter :1 \t diplay all data enter:2 \t  see the new posts enter : 3 to update enter :4 " << endl;
					int num;
					cin >> num;
					bool flag = true;
					while (flag) {

						switch (num)
						{
						case 1:
							write_posts();
							break;
						case 2:
							display_all_data();
							break;
						case 3:
							displaynew_data();
							break;

						default:
							cout << " enter the rigth number " << endl;
						}


					}


				}



			}
			else if (stag == 2) {
				cout << " if you went to\t post enter :1 \t diplay all data enter:2 \t search for adata enter :3 to update enter :4 " << endl;




			}
			else if (stag == 3) {
				cout << " if you went to\t post enter :1 \t diplay all data enter:2 \t search for adata enter :3" << endl;




			}
			else if (stag == 4) {
				cout << " if you went to\t post enter :1 \t diplay all data enter:2 \t search for adata enter :3" << endl;




			}
			else
				cout << " error enter the right number" << endl;

			break;

		}
		if (y == 0) {
			cout << " sorry ur data is not found !!" << endl;

		}

	

	}


// END OF STUDENT *************************
void doctor_search() {
	fstream doc;
	doc.open("doctor_data.txt", ios::in | ios::out);
	char name[25];
	char par_code[25];
	char matrial[50];
	char a[50];
	cin.ignore();
	cin.getline(a, 50);
	int y = 0;
	while (doc.eof())
	{
		doc.getline(name, 25, '|');
		doc.getline(par_code, 25, '|');
		doc.getline(matrial, 50);
		if (strcmp(par_code, a) == 0) {
			cout << "\n \t name  \t par_code \t matrial \n";
			cout << "welcome : " << name << "\t" << par_code << "\t \t" << matrial << endl;
			y = 1;
		}
		doc.close();

	}
	if (y == 0) {
		cout << " sorry ur data is not found !!" << endl;

	}
}



int main() {

	bool flag = true;
	while (flag) {
		cout << "\t \t welcome in Fci _ Portal _ project " << endl;
		int x;
		cout << " to register as a student enter : 1 " << endl;
		cout << " to register as a doctor enter : 2  " << endl;
		cin >> x;

		switch (x)
		{
		case 1:
			cout << " you regist as a student  enter ur par_code to enter to fci_portal" << endl;
			student_search();
			
			break;
		case 2:
			cout << " you regist as a doctor  enter ur par_code to enter to fci_portal" << endl;
			doctor_search();

			break;
		default:
			cout << " enter the rigth number " << endl;
		}
	cout << "if you went to contiue enter ' y ' " << endl;
			char c;
			cin >> c;
			if (c != 'y') {
				flag = false;}
}
	return 0;
}