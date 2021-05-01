#ifndef TG__EXAMLAYER3__H
#define TG__EXAMLAYER3__H

#include "SceneManager.h"
#include "ExamLayer4Fire.h"

class CExamLayer3 : public ALayer
{
public:
	CExamLayer3(){object_move_.X = 0; object_move_.Y = 0;}
	virtual void update();
	virtual void render();
	virtual void onEnter();
private:
	void keyEvent(int key_value);
	void fire();
private:
	static const int kADD_X = 2;
	static const int kADD_Y = 1;
	COORD object_move_;
};

void CExamLayer3::onEnter()
{
	addOnKeyEventCallback(LAMBDA_KEY_PRESSED_EVENT(VK_UP,
	{
		object_move_.Y-=kADD_Y;
	}
	));

	addOnKeyEventCallback(LAMBDA_KEY_PRESSED_EVENT(VK_DOWN,
	{
		object_move_.Y+=kADD_Y;
	}
	));

	addOnKeyEventCallback(LAMBDA_KEY_PRESSED_EVENT(VK_RIGHT,
	{
		object_move_.X+=kADD_X;
	}
	));

	addOnKeyEventCallback(LAMBDA_KEY_PRESSED_EVENT(VK_LEFT,
	{
		object_move_.X-=kADD_X;
	}
	));

	addOnKeyEventCallback(LAMBDA_KEY_PRESSED_EVENT_ONLY_ONE(VK_SPACE,
	{
		parent_scene_->addLayer(new CExamLayer4Fire(object_move_));
	}
	));
}

void CExamLayer3::update()
{
}

void CExamLayer3::render()
{
	setColor(Color::WHITE);
	draw(5,46,"x = ");
	draw(5,48,"y = ");
	draw(10,46,object_move_.X);
	draw(10,48,object_move_.Y);
	draw(object_move_.X, object_move_.Y, "¢Á");
}

void CExamLayer3::fire()
{

}

#endif // TG__EXAMLAYER3__H