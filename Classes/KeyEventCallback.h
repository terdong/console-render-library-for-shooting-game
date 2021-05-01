#ifndef TG__KEYEVENTCALLBACK__H
#define TG__KEYEVENTCALLBACK__H

#include <functional>
#include <vector>

#define LAMBDA_KEY_PRESSED_EVENT(vk_value, func)[&](){ if(GetAsyncKeyState(vk_value)&0x8000){func}}
#define LAMBDA_KEY_PRESSED_EVENT_ONLY_ONE(vk_value, event_routine)\
[&](){ static bool is_press = true;\
short reulst_key = GetAsyncKeyState(vk_value);\
if(reulst_key&0x8000)\
{\
	if(is_press)\
	{\
		event_routine\
		is_press = false;\
	}\
}else\
{\
	is_press = true;\
}\
}

class AKeyEventCallback
{
protected:
	typedef std::function<void(void)> OnKeyEventCallback;
protected:
	AKeyEventCallback(){}
	virtual ~AKeyEventCallback(){}

	void addOnKeyEventCallback(OnKeyEventCallback onKeyEventCallback)
	{
		key_events_vector_.push_back(onKeyEventCallback);
	}
	void triggerOnKeyEvents()
	{
		for(OnKeyEventCallback onKeyEventCallback: key_events_vector_)
		{
			onKeyEventCallback();
		}
	}

protected:
	std::vector<OnKeyEventCallback> key_events_vector_;
};

#endif // TG__KEYEVENTCALLBACK__H