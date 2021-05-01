#ifndef TG__EXAMLAYER2__H
#define TG__EXAMLAYER2__H

#include "SceneManager.h"
#include "ExampleScene2.h"

class CExamLayer2 : public ALayer
{
public:
	CExamLayer2():x_(0), y_(0), count_(0){}
	virtual void onEnter()
	{
		CRenderManager& renderManager = CRenderManager::GetInstanceRef();
		bufferSize_ = renderManager.getBufferSize();
		setLayerTag(100);

		object_move_.X = 10;
		object_move_.Y = 10;
	}
	virtual void update();
	virtual void render();
private:
	int x_,y_;
	int count_;
	COORD bufferSize_;

	static const int kADD_X = 2;
	static const int kADD_Y = 1;
	COORD object_move_;
};

void CExamLayer2::update()
{
	static int temp_switch = 0;
	static ALayer* temp_layer = nullptr;

	if(count_++ > 300)
	{
		CSceneManager& Scene_manager = CSceneManager::GetInstanceRef();
		//Scene_manager.changeScene(new CExampleScene2);
		//Scene_manager.stop();
	}
	else if(count_ > 200)
	{
		if(temp_switch <= 1)
		{
			parent_scene_->removeLayer(temp_layer);
			++temp_switch;
		}
	}
	else if(count_ > 50)
	{
		parent_scene_->findLayerbyTag(getLayerTag());

		if(temp_switch == 0)
		{
			temp_layer = new CExamLayer;
			parent_scene_->addLayer(temp_layer, 0);
			++temp_switch;
		}
	}
}
void CExamLayer2::render()
{
	CSceneManager& layer_manager = CSceneManager::GetInstanceRef();

	setColor(Color::WHITE);
	/*for(int i = 0; i < bufferSize_.X; i+=2)
	{
		for(int j = 0; j < bufferSize_.Y; ++j)
		{
			draw(i,j,".");
		}
	}*/

	setColor(Color::BLACK, Color::WHITE);

	draw(5,18,"CExamLayer2");
	draw(5,20,"buuferSize_X = ");
	draw(5,25,"buuferSize_Y = ");
	draw(5,30,"count = ");

	draw(5,37,"ī��Ʈ�� 50�� ������ ���ο� ���̾ �߰��˴ϴ�.");
	draw(5,39,"ī��Ʈ�� 200�� ������ �߰��ƴ� ���̾ �����˴ϴ�.");
	draw(5,41,"ī��Ʈ�� 300�� ������ �ڵ� ���� �˴ϴ�.");

	draw(20,20,bufferSize_.X);
	draw(20,25,bufferSize_.Y);
	draw(13,30,count_);
}



#endif // TG__EXAMLAYER2__H