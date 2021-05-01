#ifndef TG__EXAMLAYER4FIRE__H
#define TG__EXAMLAYER4FIRE__H

#include "SceneManager.h"
class CExamLayer4Fire : public ALayer
{
public:
	CExamLayer4Fire(COORD a_start_point):missile_point_(a_start_point)
	{}
	virtual void update();
	virtual void render();
private:
	COORD missile_point_;
};

void CExamLayer4Fire::update()
{
	if(missile_point_.Y<=1)
	{
		parent_scene_->removeLayer(this);
	}
	missile_point_.Y -= 1;
}
void CExamLayer4Fire::render()
{
	setColor(Color::SKYBLUE);
	draw(missile_point_.X, missile_point_.Y, "бу");
}



#endif // TG__EXAMLAYER4FIRE__H