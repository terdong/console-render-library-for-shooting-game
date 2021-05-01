#ifndef TG__LAYERINDEXING__H
#define TG__LAYERINDEXING__H

class CLayerOption
{
protected:
	CLayerOption()
		:layer_unique_id_(ID_COUNTER_++)
		,layer_tag_(-1)
		,layer_order_first_(kMIN_LAYER_ORDER)
	    ,layer_order_second_(kMIN_LAYER_ORDER)
	{ 
		initialize(); 
	}
	virtual ~CLayerOption(){}
public:
	inline int  getLayerUniqueId()			{ return layer_unique_id_; }

	inline void setLayerTag(int a_tag)		{ layer_tag_ = a_tag; }
	inline int  getLayerTag()				{ return layer_tag_; }

	inline void setLayerOrder(int a_order)  { layer_order_first_ = a_order; }
	inline void setLayerOrder(int a_order_first, int a_order_second)   
	{ 
		layer_order_first_  = a_order_first;
		layer_order_second_ = a_order_second; 
	}

	inline int  getLayerOrderFirst()		{ return layer_order_first_;    }
	inline int  getLayerOrderSecond()		{ return layer_order_second_;    }
private:
	void initialize()
	{	
	}
private:
	static const int kMIN_LAYER_ORDER = 0;
	static int ID_COUNTER_;
	const int layer_unique_id_;
	int layer_tag_;
	int layer_order_first_;
	int layer_order_second_;
};

__declspec(selectany) int CLayerOption::ID_COUNTER_ = 0;

#endif // TG__LAYERINDEXING__H