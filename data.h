#ifndef DATA_HEAD
#define DATA_HEAD
#define PHASE_2_LONGTH 480
#define PHASE_2_WIDTH 120
#define BARREL_1_START_X 31
#define BARREL_1_END_X 47
#define BARREL_1_START_Y 152
#define BARREL_1_END_Y 168
#define BARREL_2_START_X 67
#define BARREL_2_END_X 83
#define BARREL_2_START_Y 214
#define BARREL_2_END_Y 230
#define BARREL_3_START_X 52
#define BARREL_3_END_X 68
#define BARREL_3_START_Y 301
#define BARREL_3_END_Y 317
#define BARREL_4_START_X 67
#define BARREL_4_END_X 83
#define BARREL_4_START_Y 379
#define BARREL_4_END_Y 394
#define START_X 0
#define START_Y 0
#define GOAL_X 60
#define GOAL_Y 400
#include <unordered_map>

using namespace std;

class Info {
	public:
		int x,y;
		float gscore;
		float fscore;
		bool blocked;
		bool picked;
		Info( const Info &obj) {
			x = obj.x;
			y = obj.y;
			gscore = obj.gscore;
			fscore = obj.fscore;
			blocked = obj.blocked;
			picked = obj.picked;
		}
		Info(int _x, int _y) { x = _x; y = _y; }
		Info(){}
		bool operator<( const Info& other) const {
			if( x == other.x )
				return y < other.y;
			return x < other.x;
		}

		bool operator==( const Info& right) {
			return x == right.x && y == right.y;
		}

};

unordered_map<int, Info> importData(int choice) ;
void print_data_picked(unordered_map<int, Info> data) ;
int coor_to_int(int x, int y) ;
#endif
