#ifndef TG__RENDERTIMER__H
#define TG__RENDERTIMER__H

using namespace chrono;

class CRenderTimer
{
public:
	CRenderTimer()
		:tick_(kDEFAULT_FPS)
		,fps_(kDEFAULT_FPS)
	{}
	~CRenderTimer(){}

	inline void setFps(int fps) { tick_ = milliseconds((int)fps); }
	inline __int64 getFps() { return fps_; }

	bool updateTick()
	{
		auto current_time = system_clock::now();
		milliseconds elapsed = duration_cast<milliseconds>(current_time - start_time_);
		if(elapsed >= tick_)
		{
			start_time_ = current_time;
			fps_ = elapsed.count();
			return true;
		}
		return false;
	}
private:
	static const int kDEFAULT_FPS = 30;

	system_clock::time_point start_time_;
	milliseconds tick_;
	__int64 fps_;
	

};

#endif // TG__RENDERTIMER__H