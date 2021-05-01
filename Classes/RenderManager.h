#ifndef TG__RENDERMANAGER__H
#define TG__RENDERMANAGER__H

enum Color{
	BLACK,
	D_BLUE,
	D_GREEN,
	D_SKYBLUE,
	D_RED,
	D_VIOLET,
	D_YELLOW,
	GRAY,
	D_GRAY,
	BLUE,
	GREEN,
	SKYBLUE,
	RED,
	VIOLET,
	YELLOW,
	WHITE,
};

class CRenderManager : public CSingleton<CRenderManager>
{
public:
	CRenderManager():render_info_number_(0) { }
	~CRenderManager();
	//void initialize(CRenderInfo& a_renderInfo);
	void initialize(int widthSize, int heightSize);

	void cleanScreen();
	void flippingScreen();
	void draw(int x, int y, const char* a_out_put);
	void setColor(int color , int bgcolor );
	COORD getPos();
	COORD getBufferSize();
private:
	int setWindowSize(HANDLE& a_handle, COORD& a_bufferSize);
	void setCursor(HANDLE& a_handle, bool bVisible);
	//inline void setRenderInfo(CRenderInfo& a_renderInfo)
	//{
		//render_info_[0] = a_renderInfo;
	//}
	void setPos(int x, int y);

private:
	//static const int kDefaultFps = 30;

	//CRenderInfo render_info_[2];
	HANDLE render_handle_[2];
	int render_info_number_;
	COORD buffer_size_;
};

#endif // TG__RENDERMANAGER__H