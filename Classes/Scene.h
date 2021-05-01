#ifndef TG__SCENE__H
#define TG__SCENE__H

#include <vector>
#include <tuple>

class AScene : public ASceneHandler
{
public:
	AScene() {}
	virtual ~AScene();

	virtual bool initialize(); // �ʱ�ȭ �Լ�. ���� �� �θ� �Լ��� ȣ��������. [1/23/2014 Um]
	
	virtual void onEnter(); // Scene ���� �� �� ȣ��Ǵ� �Լ�. [1/22/2014 Um]

	virtual void onExit();  // Scene�� ���� �� ���������� ȣ��Ǵ� �Լ�. [1/22/2014 Um]   

	virtual void doMainLoop() {} // Scene main loop ���� �̺�Ʈ ����. [1/23/2014 Um]

	void doPreLoop();
	void doPostLoop();

	void addLayer(ALayer* a_layer);
	void addLayer(ALayer* a_layer, int first_order);
	void removeLayer(ALayer* a_layer);
	void removeLayer(int a_layer_tag);
	//ILayer* findLayerbyTag(int a_layer_tag); ISceneHandler���� ������.

private:
	void release();
	void addLayerInner(ALayer* a_layer, int first_order);
	void removeLayerInner(int a_layer_tag);
	void removeLayerInner(ALayer* a_layer);
	void removeForLayer(ALayer* a_layer);

};

#endif // TG__SCENE__H