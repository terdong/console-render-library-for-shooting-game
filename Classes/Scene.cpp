#include "PreCompiled.h"

AScene::~AScene()
{
	release();
}

bool AScene::initialize()
{
	return true;
}

void AScene::release()
{
	for (ALayer* layer : layer_vector_)
	{
		delete layer;
		layer = nullptr;
	}
	layer_vector_.clear();
}

void AScene::onEnter()
{
	doPreLoop();
}

void AScene::onExit()
{
	doPostLoop();

	for(ALayer* layer : layer_vector_)
	{
		layer->onExit();
	}
}

void AScene::addLayer( ALayer* a_layer )
{
	scheduled_layer_vector_.push_back(make_tuple(-1, a_layer));
}


void AScene::addLayer( ALayer* a_layer, int first_order )
{
	assert(first_order >= 0);

	scheduled_layer_vector_.push_back(make_tuple(first_order, a_layer));
}

void AScene::removeLayer( ALayer* a_layer )
{
	scheduled_remove_layer_vector_.push_back(make_tuple(-1, a_layer));
}

void AScene::removeLayer( int a_layer_tag )
{
	scheduled_remove_layer_vector_.push_back(make_tuple(a_layer_tag, nullptr));
}


void AScene::addLayerInner( ALayer* a_layer, int first_order )
{
	auto iterator_begin = layer_vector_.begin();

	int second_order = 0;

	while(iterator_begin != layer_vector_.end())
	{
		ALayer* layer = *iterator_begin;
		if(layer->getLayerOrderFirst() == first_order)
		{
			for( iterator_begin; iterator_begin != layer_vector_.end() && layer->getLayerOrderFirst() <= first_order; ++iterator_begin )
			{
				++second_order;
			}
			break;
		}else if(layer->getLayerOrderFirst() > first_order)
		{
			--iterator_begin;
			break;
		}
		++iterator_begin;
	}

	a_layer->setLayerOrder(first_order, second_order);
	layer_vector_.insert(iterator_begin, a_layer);

	a_layer->setParentSceneHandler(this);
}


void AScene::removeLayerInner( int a_layer_tag )
{
	auto iterator_begin = layer_vector_.begin();
	while(iterator_begin != layer_vector_.end())
	{
		ALayer* layer = *iterator_begin;
		if(layer->getLayerTag() == a_layer_tag)
		{
			layer_vector_.erase(iterator_begin);
			removeForLayer(layer);
			break;
		}
	}
}

void AScene::removeLayerInner( ALayer* a_layer )
{
	auto iterator_begin = layer_vector_.begin();
	while(iterator_begin != layer_vector_.end())
	{
		ALayer* layer = *iterator_begin;
		if(layer->getLayerUniqueId() == a_layer->getLayerUniqueId())
		{
			layer_vector_.erase(iterator_begin);
			removeForLayer(layer);
			break;
		}
		++iterator_begin;
	}
}

void AScene::removeForLayer( ALayer* a_layer )
{
	a_layer->onExit();
	delete a_layer;
}

void AScene::doPreLoop()
{
	if(!scheduled_layer_vector_.empty())
	{
		for(tuple<int, ALayer*> a_tuple : scheduled_layer_vector_)
		{
			int first_order = get<0>(a_tuple);
			ALayer* layer = get<1>(a_tuple);
			if(first_order == -1)
			{
				layer_vector_.push_back(layer);
			}else
			{
				addLayerInner(layer, first_order);
			}
			layer->setParentSceneHandler(this);
			layer->onEnter();
		}
		scheduled_layer_vector_.clear();
	}
}

void AScene::doPostLoop()
{
	if(!scheduled_remove_layer_vector_.empty())
	{
		for(tuple<int, ALayer*> a_tuple : scheduled_remove_layer_vector_)
		{
			int layer_tag = get<0>(a_tuple);
			ALayer* layer = get<1>(a_tuple);
			if(layer_tag == -1)
			{
				removeLayerInner(layer);
			}else
			{
				removeLayerInner(layer_tag);
			}
		}
		scheduled_remove_layer_vector_.clear();
	}
}