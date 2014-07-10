barrel_1_start_x = 31;
barrel_1_end_x = 47;
barrel_1_start_y = 152;
barrel_1_end_y = 168;
barrel_2_start_x = 67;
barrel_2_end_x = 83;
barrel_2_start_y = 214;
barrel_2_end_y = 230;
barrel_3_start_x = 52;
barrel_3_end_x = 68;
barrel_3_start_y = 301;
barrel_3_end_y = 317;
barrel_4_start_x = 67;
barrel_4_end_x = 83;
barrel_4_start_y = 379;
barrel_4_end_y = 394;

b1_X = [barrel_1_start_x, barrel_1_end_x, barrel_1_end_x, barrel_1_start_x, barrel_1_start_x];
b1_Y = [barrel_1_start_y, barrel_1_start_y, barrel_1_end_y, barrel_1_end_y, barrel_1_start_y];
b2_X = [barrel_2_start_x, barrel_2_end_x, barrel_2_end_x, barrel_2_start_x, barrel_2_start_x];
b2_Y = [barrel_2_start_y, barrel_2_start_y, barrel_2_end_y, barrel_2_end_y, barrel_2_start_y];
b3_X = [barrel_3_start_x, barrel_3_end_x, barrel_3_end_x, barrel_3_start_x, barrel_3_start_x];
b3_Y = [barrel_3_start_y, barrel_3_start_y, barrel_3_end_y, barrel_3_end_y, barrel_3_start_y];
b4_X = [barrel_4_start_x, barrel_4_end_x, barrel_4_end_x, barrel_4_start_x, barrel_4_start_x];
b4_Y = [barrel_4_start_y, barrel_4_start_y, barrel_4_end_y, barrel_4_end_y, barrel_4_start_y];

X_point = [];
Y_point = [];
data_point = dlmread('result.txt');

for j = 1:400
	X_point(j) = data_point(j,1);
	Y_point(j) = data_point(j,2);
end

plot(b1_X, b1_Y, b2_X, b2_Y, b3_X, b3_Y, b4_X, b4_Y, X_point, Y_point);
xlim([0, 480]);
ylim([0, 480]);


