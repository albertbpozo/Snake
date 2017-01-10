#include "Snake.h"

void Snake::Aumentar() {

	body.push_back(temp);


}

Snake::Snake() {
	temp.objectID = ObjectID::S_08;
	temp.transform = { 0, 0, 30, 30 };
	body.push_back(temp);
	body.push_back(temp);
	body.push_back(temp);
}


void Snake::Draw() {
	for (int i = 0; i< body.size(); i++)
	{
		body[i].Draw();
	}
}

void Snake::InitialPos(int x, int y) {
	for (int i = 0; i< body.size(); i++)
	{
		body[i].transform.x = x;
		body[i].transform.y = y;
	}
}

void Snake::Die(int cols, int rows) {

	if (body[0].transform.x < 0 || body[0].transform.y < 0 || body[0].transform.x >= rows * 30 || body[0].transform.y >= cols * 30) {
		body.erase(body.begin(), body.end());
		dir = 3;
		temp.objectID = ObjectID::S_08;
		temp.transform = { 0, 0, 30, 30 };
		body.push_back(temp);
		body.push_back(temp);
		body.push_back(temp);
		}
}

void Snake::Move() {
	x = body[0].transform.x;
	y = body[0].transform.y;

	if (IM.IsKeyUp<KEY_BUTTON_DOWN>()) {
		dir = 1;
	}
	else if (IM.IsKeyUp<KEY_BUTTON_UP>()) {
		dir = 0;
	}
	else if (IM.IsKeyUp<KEY_BUTTON_LEFT>()) {
		dir = 2;
	}
	else if (IM.IsKeyUp<KEY_BUTTON_RIGHT>()) {
		dir = 3;
	}

	switch (dir) {
	case UP:
		body[0].transform.y -= 30;
		break;
	case DOWN:
		body[0].transform.y += 30;
		break;
	case LEFT:
		body[0].transform.x -= 30;
		break;
	case RIGHT:
		body[0].transform.x += 30;
		break;
	default:
		break;
	}

	temp.objectID = ObjectID::S_08;
	temp.transform = { x, y, 30, 30 };
	body.pop_back(); 
	body.insert(body.begin()+1, temp); 
	
}