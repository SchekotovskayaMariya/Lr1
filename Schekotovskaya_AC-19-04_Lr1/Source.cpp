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