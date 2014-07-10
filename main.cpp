#include <iostream>
#include <map>
#include <list>
#include <cmath>
#include <unordered_map>
#include "data.h"

using namespace std;

float dist(int a, int b) {
	return sqrt( pow(a,2) + pow(b,2) );
}

void print_Info(Info info) {
	cout << "Info info" << endl;
	cout << "x:" << info.x <<endl;
	cout << "y:" << info.y <<endl;
	cout << "fscore:" << info.fscore <<endl;
	cout << "gscore:" << info.gscore <<endl;
}

Info lowest_fscore(list<Info> list) {
	Info lowest = list.front();
	Info current;
	for (std::list<Info>::iterator it=list.begin(); it != list.end(); ++it) {
		current = *it;
		if(lowest.fscore > current.fscore)
			lowest = current;
	}
	return lowest;
}

void reconstruct_path(unordered_map<int, Info> &data, map<Info, Info> &came_from, Info current) {
	int current_raw_index = coor_to_int(current.x, current.y);
	map<Info, Info>::const_iterator it = came_from.find ( current ) ;
	if( it != came_from.end() ) {
		reconstruct_path ( data, came_from, came_from[ current ] );
		data[current_raw_index].picked = true;
	}
	else
		data[current_raw_index].picked = true;
}

float estimate(int x, int y) {
	return (float)(abs(GOAL_X - x) + abs(GOAL_Y - y));
}

bool valid(int x, int y) {
	return x >= 0 && x < PHASE_2_WIDTH &&
					y >= 0 && y < PHASE_2_LONGTH;
}

bool contain(Info info, list<Info> list) {
	for (std::list<Info>::iterator it=list.begin(); it != list.end(); ++it) {
		if (*it == info)
			return true;
	}
	return false;
}

int main (int argc, const char *argv[]) {
	list<Info> openset, closedset;
	unordered_map<int, Info> data;
	map<Info, Info> come_from;
	Info neighbor_info, current_info, start_info;
	int current_raw_index, neighbor_raw_index;
	float tentative_g_score;

	int diff_x=0, diff_y=0, i;
	int start_raw_index = coor_to_int(START_X, START_Y);
	int goal_raw_index = coor_to_int(GOAL_X, GOAL_Y);

	data = importData(2);
	
	start_info = data[start_raw_index];
	start_info.gscore = 0;
	start_info.fscore = 0 + estimate(START_X, START_Y); 
	openset.push_back(start_info);

	while( !openset.empty() ) {
//		cout << "open set is " << endl;
//		for (std::list<Info>::iterator it=openset.begin(); it != openset.end(); ++it)
//			print_Info(*it);
		current_info = lowest_fscore(openset);
		current_raw_index = coor_to_int(current_info.x, current_info.y);
		if(current_raw_index == goal_raw_index) {
		//	for (std::list<Info>::iterator it=closedset.begin(); it != closedset.end(); ++it)
		//		print_Info(*it);
			reconstruct_path(data, come_from, data[goal_raw_index]);
			//print_data_picked(data);
			return 0;
		}
		openset.remove(current_info);
		closedset.push_back(current_info);

		for(i=0; i<5; i++) {
			switch(i) {
				case 0:
					diff_x = -1;
					diff_y = 0;
					break;
				case 1:
					diff_x = -1;
					diff_y = 1;
					break;
				case 2:
					diff_x = 0;
					diff_y = 1;
					break;
				case 3:
					diff_x = 1;
					diff_y = 1;
					break;
				case 4:
					diff_x = 1;
					diff_y = 0;
					break;
				case 5:
					diff_x = 1;
					diff_y = -1;
					break;
				case 6:
					diff_x = 1;
					diff_y = 0;
					break;
				case 7:
					diff_x = 1;
					diff_y = 1;
					break;
			}
			if(!valid(current_info.x + diff_x, current_info.y + diff_y))
				continue;
			neighbor_raw_index = coor_to_int(current_info.x + diff_x, current_info.y + diff_y);
			neighbor_info = data.at(neighbor_raw_index);
			if(!neighbor_info.blocked) {
				if(contain(neighbor_info, closedset))
					continue;
				tentative_g_score = current_info.gscore + dist(diff_x, diff_y);
				if( !contain( neighbor_info, openset ) || tentative_g_score < neighbor_info.fscore ) {
					come_from[neighbor_info] = current_info;
					neighbor_info.gscore = tentative_g_score;
					neighbor_info.fscore = neighbor_info.gscore + estimate(neighbor_info.x, neighbor_info.y);
					if( !contain( neighbor_info,openset ) ) 
						openset.push_back(neighbor_info);
				}
			}
		}
	}
	cout << "path finding fails" << endl;
}
