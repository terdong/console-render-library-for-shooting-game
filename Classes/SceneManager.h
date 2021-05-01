#ifndef TG__LAYERMANAGER__H
#define TG__LAYERMANAGER__H

#include "RenderTimer.h"

class CSceneManager : public CSingleton<CSceneManager>
{
public:
	CSceneManager()
		:main_scene_(nullptr)
		,scheduled_scene_(nullptr)
		,run_game_(false) 
	{ }

	~CSceneManager()
	{
		releaseLayer();
	}

	// 최초 시작시 호출. [12/28/2013 Um]
	void startCreateLayerAndPlay(AScene* a_scene)
	{
		if(main_scene_ == nullptr)
		{
			main_scene_ = a_scene;
			play();
		}
	}
	// 이후 Scene 변경 할 때 호출. [12/28/2013 Um]
	void changeScene(AScene* a_scene)
	{
		scheduled_scene_ = a_scene;
		stop();
	}

	// 레이어 루틴 시작 시 호출. [12/28/2013 Um]
	void play(){ if(run_game_) { return; } run_game_ = true; run(); }

	// 레이어 루틴 멈출 때 시 호출. [12/28/2013 Um]
	void stop(){ run_game_ = false; }

	// FPS 변경 시. [12/28/2013 Um]
	void setFPS(int fps) { render_timer_.setFps(fps); }

	// FPS 값을 가지고 올때. [12/28/2013 Um]
	__int64 getFPS(){ return render_timer_.getFps(); }
private:
	void run()
	{
		assert(main_scene_ != nullptr);

		main_scene_->initialize();
		main_scene_->onEnter();

		while(run_game_)
		{
			if(render_timer_.updateTick())
			{
				main_scene_->doPreLoop();
				main_scene_->doMainLoop();

				preRender();

				for(ALayer* layer : main_scene_->getLayerVector())
				{
					layer->doMainLoop();
				}

				postRender();

				main_scene_->doPostLoop();
			}
		}

		main_scene_->onExit();
		releaseLayer();
		changeScene();
	}

	void preRender()    // 렌더링 하기전에 호출되는 함수. [12/28/2013 Um]
	{
		CRenderManager& renderManager = CRenderManager::GetInstanceRef();
		renderManager.cleanScreen();
	}	
	void postRender()   // 렌더링 후에 호출되는 함수. [12/28/2013 Um]
	{
		CRenderManager& renderManager = CRenderManager::GetInstanceRef();
		renderManager.flippingScreen();
	}

	void releaseLayer()
	{
		if(main_scene_ != nullptr)
		{
			delete main_scene_;
			main_scene_ = nullptr;
		}
	}

	void changeScene()
	{
		if(scheduled_scene_ != nullptr)
		{
			main_scene_ = scheduled_scene_;
			scheduled_scene_= nullptr;
			play();
		}
	}

private:
	AScene* main_scene_;
	AScene* scheduled_scene_;
	bool run_game_;

	CRenderTimer render_timer_;
};

#endif // TG__LAYERMANAGER__H