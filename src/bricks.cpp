#include "bricks.h"
#include <cmath>
#include <iostream>
#include <vector>

void Bricks::InitBricks()
{
	bricks_vector.clear();
	int horizontal_spacing = 20;

	for (int i = 0; i < brick_row; i++)
	{
		int vertical_spacing = 10;
		for (int j = 0; j < brick_col; j++)
		{
			std::vector<int> brick_vector = {vertical_spacing, horizontal_spacing, int(collide)};
			bricks_vector.emplace_back(brick_vector);
			vertical_spacing += 130;
		}
		horizontal_spacing += 50;
	}
}

void Bricks::UpdateBricks(Ball &ball) {
	collide = false;
	for (auto &brick_vector : bricks_vector) {
		if  (CheckCollsion(ball.head_x, ball.head_y, brick_vector)) {
			collide = true;
			if (re_bound == "X" && brick_vector[2] == 0) {
				ball.y_velocity = -1 * ball.y_velocity;
			} else if (re_bound == "Y" && brick_vector[2] == 0) {
				ball.x_velocity = -1 * ball.x_velocity;
			}
			brick_vector[2] = 1;

		}
	}
}

bool Bricks::CheckCollsion(int ball_x, int ball_y, std::vector<int> brick_vector) {
	int delta_x = std::min(std::abs(ball_x - brick_vector[0]), std::abs(ball_x - (brick_vector[0] + 90)));
	int delta_y = std::min(std::abs(ball_y - brick_vector[1]), std::abs(ball_y - (brick_vector[1] + 40)));
	if (delta_x <= 32 && delta_y <= 32) {
		if (delta_y > delta_x) {
			re_bound = "Y";
		} else {
			re_bound = "X";
		}
		return true;
	}
	return false;
}

void Bricks::Update(Ball &ball) {
	UpdateBricks(ball);
}

