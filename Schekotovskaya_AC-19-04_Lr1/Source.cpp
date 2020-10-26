#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct pipe
{
	int id;
	float length, diameter;
	bool repair_status;
};

struct KC
{
	int id, n_ws, n_ws_op; // n_ws - number of workshops, n_ws_op - number of workshops in operation
	string name;
	float ef; // ef - efficiency
};

pipe CreatePipe()
{
	pipe p;

	//cout << "Type the pipe ID: ";
	p.id = 0;

	cout << "\nType the length of the pipe: ";
	cin >> p.length;

	cout << "\nType the diameter of the pipe: ";
	cin >> p.diameter;

	cout << "\nType the status of the repair pipe: ";
	cin >> p.repair_status;
	
	return p;
}

void ViewPipe(const pipe& p)
{
	cout << "\nID: " << p.id << endl
		<< "Length: " << p.length << endl
		<< "Diametr: " << p.diameter << endl
		<< "Repair status: " << p.repair_status << endl;
}

void SavePipe(const pipe& p)
{
	ofstream fout;
	fout.open("data1.txt", 'w');

	fout << "\nID: " << p.id << endl
		<< "Length: " << p.length << endl
		<< "Diametr: " << p.diameter << endl
		<< "Repair status: " << p.repair_status << endl;
}

void EditPipe(pipe& p)
{
	if (p.repair_status == 1)
	{
		p.repair_status = 0;
		cout << "\nStatus changed to pipe not under repair\n";
	}
	else
	{
		p.repair_status = 1;
		cout << "\nStatus changed to pipe under repair\n";
	}

}

KC CreateKC()
{
	KC s;

	//cout << "Type the KC ID: ";
	s.id = 0;

	cout << "\nType a name of the KC: ";
	cin >> s.name;

	cout << "\nType the number of workshops: ";
	cin >> s.n_ws;

	cout << "\nType the number of workshops in operation: ";
	cin >> s.n_ws_op;

	cout << "\nType the efficiency of the KC: ";
	cin >> s.ef;

	return s;
}

void ViewKC(const KC& s)
{
	cout << "\nID: " << s.id << endl
		<< "Name: " << s.name << endl
		<< "Number of workshops: " << s.n_ws << endl
		<< "Number of workshops in operation: " << s.n_ws_op << endl
		<< "Efficiency: " << s.ef << endl;
}

void SaveKC(const KC& s)
{
	ofstream fout;
	fout.open("data2.txt", 'w');

	fout << "\nID: " << s.id << endl
		<< "Name: " << s.name << endl
		<< "Number of workshops: " << s.n_ws << endl
		<< "Number of workshops in operation: " << s.n_ws_op << endl
		<< "Efficiency: " << s.ef << endl;
}

void EditKC(KC& s)
{

	cout << "\n1. Turn on the workshop ";
	cout << "\n2. Turn off the workshop";
	cout << "\nChoose: ";
	int choiñe;
	cin >> choiñe;
	if (choiñe == 1)
	{
		s.n_ws_op += 1;
	}
	else
	{
		s.n_ws_op -= 1;
	}
}

void Menu()
{
	cout << "\nMain menu\n" << "1. Add a pipe\n" << "2. Add a KC\n" << "3. View all objects\n" << "4. Edit the pipe\n" << "5. Edit the KC\n"<< "6. Save\n" << "7. Upload\n" << "0. Exit\n" << "Select the desired number from the menu: ";

}

void SaveAll(const pipe& p, const KC& s)
{
	ofstream fout;
	fout.open("data3.txt", 'w');


	fout << "\nID: " << p.id << endl
		<< "Length: " << p.length << endl
		<< "Diametr: " << p.diameter << endl
		<< "Repair status: " << p.repair_status << endl;

	fout << "\nID: " << s.id << endl
		<< "Name: " << s.name << endl
		<< "Number of workshops: " << s.n_ws << endl
		<< "Number of workshops in operation: " << s.n_ws_op << endl
		<< "Efficiency: " << s.ef << endl;

}

void ViewThat(int m,const pipe& pi,const KC& st)
{
	switch (m)
	{
	case 1:
		ViewPipe(pi);
		break;
	case 2:
		ViewKC(st);
		break;
	}
}
void SaveThat(int l,const pipe& pi,const KC& st)
{
	switch (l)
	{
	case 1:
		SavePipe(pi);
		break;
	case 2:
		SaveKC(st);
		break;
	case 3:
		SaveAll(pi, st);
		break;
	}
}

int main()
{ 
	pipe pi;
	KC st; // óçíàòü ïî÷åìó íå ðàáîòàåò â ñâè÷å
	

	while (true)
	{
		Menu();
		int n;
		cin >> n;

		switch (n)
		{
		case 1:
			pi = CreatePipe();
			break;
		case 2:
			st = CreateKC();
			break;
		case 3:
			cout << "Select object 1-Pipe 2-KC: ";
			int m;
			cin >> m;
			ViewThat(m, pi, st);
			break;
		case 4:
			EditPipe(pi);
			break;
		case 5:
			EditKC(st);
			break;
		case 6 :
			cout << "Select object 1-Pipe 2-KC 3-All: ";
			int l;
			cin >> l;
			SaveThat(l, pi, st);
			break;
			//case 7 :
		case 0 :
			return 0;
		}
	} 
	return 0;
	
}
