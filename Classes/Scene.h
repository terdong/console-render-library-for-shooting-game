#ifndef TG__SCENE__H
#define TG__SCENE__H

#include <vector>
#include <tuple>

class AScene : public ASceneHandler
{
public:
	AScene() {}
	virtual ~AScene();

	virtual bool initialize(); // 초기화 함수. 구현 시 부모 함수도 호출해주자. [1/23/2014 Um]
	
	virtual void onEnter(); // Scene 시작 할 때 호출되는 함수. [1/22/2014 Um]

	virtual void onExit();  // Scene이 끝날 때 마지막으로 호출되는 함수. [1/22/2014 Um]   

	virtual void doMainLoop() {} // Scene main loop 에서 이벤트 구현. [1/23/2014 Um]

	void doPreLoop();
	void doPostLoop();

	void addLayer(ALayer* a_layer);
	void addLayer(ALayer* a_layer, int first_order);
	void removeLayer(ALayer* a_layer);
	void removeLayer(int a_layer_tag);
	//ILayer* findLayerbyTag(int a_layer_tag); ISceneHandler에서 구현됨.

private:
	void release();
	void addLayerInner(ALayer* a_layer, int first_order);
	void removeLayerInner(int a_layer_tag);
	void removeLayerInner(ALayer* a_layer);
	void removeForLayer(ALayer* a_layer);

};

#endif // TG__SCENE__H