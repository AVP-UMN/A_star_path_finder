#include "data.h"
#include <iostream>
#include <unordered_map>
#include <fstream>
using namespace std;

int coor_to_int(int x, int y) {
	return (((x + y) * (x + y + 1) / 2) + y);
}

void print_data_picked(unordered_map<int, Info> data) {
	bool picked;
	int i,j;
	int raw_index;
	ofstream out;
	out.open("result.txt", ios::out);
	for(i=400; i>0; i--) {
		for(j=0; j<70; j++) {
			raw_index = coor_to_int(j,i);
			if(data[raw_index].picked){ 
//				out << data[raw_index].x.tostring() << " ," + data[raw_index].y<< ")" << "\n";
				out << "(" + to_string(data[raw_index].x) + " ,";
				out << to_string(data[raw_index].y) + ")\n";
				cout << "1 ";
			}
			else
				cout << "  ";
		}
		cout << endl;
	}
	out.close();
}

void print_data(unordered_map<int, Info> data) {
	bool blocked;
	int i,j;
	int raw_index;

	for(i=400; i>200; i--) {
		for(j=0; j<70; j++) {
			raw_index = coor_to_int(j,i);
			if(data[raw_index].blocked) 
				cout << "1 ";
			else
				cout << "  ";
		}
		cout << endl;
	}
	cout << "------------ end of print_data ------------" << endl;
}

//DATA SET for phase_2. 0 means safe and 1 means obstacle
unordered_map<int, Info> import_phase_2_data() {
	unordered_map<int, Info> data;
	int raw_index;
	int i,j;

	for(i=0; i<PHASE_2_LONGTH; i++) {
		for(j=0; j<PHASE_2_WIDTH; j++) {
			raw_index = coor_to_int(j,i);
			Info *n = new Info(j,i);
			n->blocked = false;
			n->picked = false;
			data.insert( pair<int, Info>(raw_index, *n) );
		}
	}

	/* Add first Barrel */
	for(i=BARREL_1_START_Y; i<BARREL_1_END_Y; i++) {
		for(j=0; j<BARREL_1_END_X; j++) {
			raw_index = coor_to_int(j,i);
			data[raw_index].blocked = true;
		}
	}

	/* Add second Barrel */
	for(i=BARREL_2_START_Y; i<BARREL_2_END_Y; i++) {
		for(j=BARREL_2_START_X; j<PHASE_2_WIDTH; j++) {
			raw_index = coor_to_int(j,i);
			data[raw_index].blocked = true;
		}
	}

	/* Add third Barrel */
	for(i=BARREL_3_START_Y; i<BARREL_3_END_Y; i++) {
		for(j=0; j<BARREL_3_END_X; j++) {
			raw_index = coor_to_int(j,i);
			data[raw_index].blocked = true;
		}
	}

	/* Add fourth Barrel */
	for(i=BARREL_4_START_Y; i<BARREL_4_END_Y; i++) {
		for(j=BARREL_4_START_X; j<PHASE_2_WIDTH; j++) {
			raw_index = coor_to_int(j,i);
			data[raw_index].blocked = true;
		}
	}

	/* For test */
	// print_data(data);
	return data;
}

unordered_map<int, Info> importData(int choice) {
		return import_phase_2_data();
}
