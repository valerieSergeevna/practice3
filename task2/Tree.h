#pragma once

ref class Tree_Node
{
public:
	Tree_Node(float data1, float data2, float data1_2, float data2_2, float data3, float data4, float dif, float height) {
		this->x1 = data1;
		this->y1 = data2;
		this->x2 = data1_2;
		this->y2 = data2_2;
		this->treeX = data3;
		this->treeY = data4;
		this->next_one = nullptr;
		this->next_two = nullptr;
		this->next_three = nullptr;
		this->next_four = nullptr;
		this->level = height;
		this->treeX_dif = dif;
	};
	~Tree_Node() {};

	float x1, y1,x2,y2, treeX, treeY;
	Tree_Node ^next_one, ^next_two, ^next_three, ^next_four;
	float level, treeX_dif;
};
	