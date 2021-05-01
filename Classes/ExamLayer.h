#ifndef TG__EXAMLAYER__H
#define TG__EXAMLAYER__H

#include "SceneManager.h"
class CExamLayer : public ALayer
{
public:
	CExamLayer():count_(0), x_(0), y_(0), radius_(15), delta_(0), anotherX_(0), anotherY_(0), anotherRadius_(10)
	{}
	virtual void update();
	virtual void render();
private:
	int count_;
	int x_,y_;
	int anotherX_, anotherY_;

	int radius_, anotherRadius_;
	float delta_;
};

void CExamLayer::update()
{
	if(count_ < 120)
	{
		++count_;
	}

	x_ = (int)(sin(delta_) * radius_ * 2);
	y_ = (int)(cos(delta_) * radius_);

	// x좌표 값에 *2를 해준 이유는, 화면 버퍼의 크기가 x 축이 2배 크기 때문. 그래야 균형이 맞음. [1/23/2014 Um]
	anotherX_ = (int)(sin(-delta_) * anotherRadius_ * 2);
	anotherY_ = (int)(cos(-delta_) * anotherRadius_);

	delta_ += 0.1f;
}

void CExamLayer::render()
{
	CSceneManager& layer_manager = CSceneManager::GetInstanceRef();

	setColor(Color::WHITE);
	draw(5, 1,"CExamLayer");
	draw(5,5,"count = ");
	draw(5,10,"fps = ");

	setColor(Color::YELLOW);
	draw(11,5,count_);

	setColor(Color::RED);
	draw(11,10,layer_manager.getFPS());

	setColor(Color::BLUE);
	draw(x_ + 50, y_ + 20, "★");

	setColor(Color::GREEN);
	draw(anotherX_ + 50, anotherY_ + 20, "☆");
}

#endif // TG__EXAMLAYER__H