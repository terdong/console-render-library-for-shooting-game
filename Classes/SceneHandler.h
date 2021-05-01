#ifndef TG__SCENEHANDLER__H
#define TG__SCENEHANDLER__H

#include <vector>

class ASceneHandler
{
protected:
	ASceneHandler(){}
	virtual ~ASceneHandler(){}
public:
	// 레이어 추가 함수. [1/23/2014 Um]
	virtual void addLayer(ALayer* a_layer) = 0;
	// 지정 위치에 레이어 추가. [1/23/2014 Um]
	virtual void addLayer(ALayer* a_layer, int order) = 0;

	virtual void removeLayer(int a_layer_tag) = 0;
	virtual void removeLayer(ALayer* a_layer) = 0;

	virtual ALayer* findLayerbyTag(int a_layer_tag) 
	{
		auto found_iterator = find_if(layer_vector_.begin(), layer_vector_.end(),
			[a_layer_tag](ALayer* layer) -> bool
			{
				if(layer->getLayerTag() == a_layer_tag)
				{
					return true;
				}
				return false;
			}
		);
		return *found_iterator;
	}

	vector<ALayer*>& getLayerVector() { return layer_vector_; }

protected:
	vector<ALayer*> layer_vector_;
	vector<tuple<int, ALayer*>> scheduled_layer_vector_;
	vector<tuple<int, ALayer*>> scheduled_remove_layer_vector_;
};

#endif // TG__SCENEHANDLER__H