#ifndef TG__LAYER__H
#define TG__LAYER__H

#include "RenderManager.h"

class ASceneHandler;
class ALayer : public CLayerOption, public AKeyEventCallback
{
public:
	ALayer():parent_scene_(nullptr){}
	virtual ~ALayer(){}
	virtual void onEnter(){}	// 최초 진입 시 호출되는 함수. [12/28/2013 Um]
	virtual void onExit(){}	    // 레이어 루프가 끝난 후 최후에 호출되는 함수. [12/28/2013 Um]
	
	void doMainLoop()
	{
		triggerOnKeyEvents();
		update();
		render();
	}

	void setParentSceneHandler(ASceneHandler* a_scene_handler) { parent_scene_ = a_scene_handler; }
protected:

	virtual void update(){};  // 로직 부분이 호출되는 함수. [12/28/2013 Um]
	virtual void render(){}; 	// 렌더링 시에 호출되는 함수. [12/28/2013 Um]

	void draw(int x/* X축 */, int y/* Y축 */, char* a_value/* 출력할 값 */)
	{
		CRenderManager& renderManager = CRenderManager::GetInstanceRef();
		renderManager.draw(x, y, a_value);
	}

	template <typename T>
	void draw(int x/* X축 */, int y/* Y축 */, T a_value/* 출력할 값 */)
	{
		CRenderManager& renderManager = CRenderManager::GetInstanceRef();
		stringstream ss;
		ss << a_value;
		renderManager.draw(x, y, ss.str().c_str());
	}

	void setColor(int color , int bgcolor = 0 /* BLACK */ )
	{
		CRenderManager& renderManager = CRenderManager::GetInstanceRef();
		renderManager.setColor(color, bgcolor);
	}
protected:
	ASceneHandler* parent_scene_;
};

#endif // TG__LAYER__H