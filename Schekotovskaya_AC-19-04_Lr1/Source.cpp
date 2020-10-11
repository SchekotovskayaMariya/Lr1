#include <iostream>
#include <string>

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

pipe createpipe()
{
	pipe p;

	//cout << "Type the pipe ID: ";
	p.id = 0;

	cout << "Type the length of the pipe: ";
	cin >> p.length;

	cout << "Type the diameter of the pipe: ";
	cin >> p.diameter;

	cout << "Type the status of the repeir pipe: ";
	cin >> p.repair_status;
}

KC createKC()
{
	KC s;

	//cout << "Type the KC ID: " << endl;
	s.id = 0;

	cout << "Type a name of the KC: ";
	cin >> s.name;

	cout << "Type the number of workshops: ";
	cin >> s.n_ws;

	cout << "Type the number of workshops in operation: ";
	cin >> s.n_ws_op;

	cout << "Type the efficiency of the KC: ";
	cin >> s.ef;
}

void menu()
{
	cout << "Main menu" << endl << "1. Add a pipe" << endl << "2. Add a KC" << endl << "3. View all objects" << endl << "4. Edit the pipe" << endl << "5. Edit the KC" << endl << "6. Save" << endl << "7. Upload" << endl << "0. Exit" << endl<< "Select the desired number from the menu: ";

}

int main()
{
	menu();
	int n;
	cin >> n;
	
	switch (n)
	{
	case 1:
		createpipe();
		break;
	case 2:
		createKC();
		break;
	case 3 :
	case 4 :
	case 5 :
	case 6 :
	case 7 :
	case 8 :
	}
}
