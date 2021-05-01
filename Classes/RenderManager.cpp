#include "PreCompiled.h"

CRenderManager::~CRenderManager()
{
	for(int i=0; i<2; ++i)
	{
		CloseHandle(render_handle_[i]);
	}
}

//void CRenderManager::initialize(CRenderInfo& a_renderInfo)
//{
//	setRenderInfo(a_renderInfo);
//	render_info_[1] = CRenderInfo(a_renderInfo.getBufferSize().X, a_renderInfo.getBufferSize().Y);
//
//	for(int i=0; i<2; ++i)
//	{
//		SetConsoleScreenBufferSize(render_info_[i].getHandle(), render_info_[i].getBufferSize());
//		setCursor(render_info_[i].getHandle(), false);
//		setWindowSize(render_info_[i].getHandle(), render_info_[i].getBufferSize());
//	}
//	sub_init();
//
//	ke = (KeyEvent)keyEvent;
//}

void CRenderManager::initialize( int widthSize, int heightSize )
{
	buffer_size_.X = widthSize;
    buffer_size_.Y = heightSize;
	for(int i=0; i<2; ++i)
	{
		render_handle_[i] = CreateConsoleScreenBuffer( GENERIC_READ | GENERIC_WRITE,0,NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
		SetConsoleScreenBufferSize(render_handle_[i], buffer_size_);
		setWindowSize(render_handle_[i], buffer_size_);
		setCursor(render_handle_[i], false);
	}
}

int CRenderManager::setWindowSize(HANDLE& a_handle, COORD& a_bufferSize)
{
	int width = a_bufferSize.X;
	int height = a_bufferSize.Y;

	SMALL_RECT rect;

	rect.Left = 0;

	rect.Right = width - 1;

	rect.Top = 0;

	rect.Bottom = height - 1;

	return SetConsoleWindowInfo(a_handle, TRUE, &rect);
}

void CRenderManager::setCursor(HANDLE& a_handle, bool bVisible)
{
	CONSOLE_CURSOR_INFO ConsoleCursor;

	ConsoleCursor.bVisible = bVisible; // true 보임, false 안보임

	ConsoleCursor.dwSize = 1; // 커서사이즈

	SetConsoleCursorInfo(a_handle , &ConsoleCursor); // 설정
}

//void CRenderManager::draw( int x, int y, char* a_out_put )
//{
//	setPos(x,y);
//	cout << a_out_put;
//}

void CRenderManager::setColor(int color , int bgcolor )
{
	color   &= 0xf;

	bgcolor &= 0xf ;

	SetConsoleTextAttribute(render_handle_[render_info_number_], (bgcolor << 4)  | color  );
}

void CRenderManager::setPos(int x, int y)
{
	COORD pos = {x-1,y-1};
	//SetConsoleCursorPosition(render_info_[render_info_number_].getHandle(),pos);
}

COORD CRenderManager::getPos()
{
	CONSOLE_SCREEN_BUFFER_INFO curInfo;
	GetConsoleScreenBufferInfo(render_handle_[render_info_number_],&curInfo);
	return curInfo.dwCursorPosition;
}

void CRenderManager::draw( int x, int y, const char* a_out_put )
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	DWORD dw;
	SetConsoleCursorPosition(render_handle_[render_info_number_], pos);
	WriteFile(render_handle_[render_info_number_], a_out_put, strlen(a_out_put), &dw, NULL);
}

void CRenderManager::flippingScreen()
{
	SetConsoleActiveScreenBuffer(render_handle_[render_info_number_]);
	render_info_number_ = !render_info_number_;       
}

void CRenderManager::cleanScreen()
{
	COORD Coor = {0,0};
	DWORD dw;
	FillConsoleOutputCharacter(render_handle_[render_info_number_], ' ', buffer_size_.X * buffer_size_.Y,Coor, &dw);
	FillConsoleOutputAttribute(render_handle_[render_info_number_], 0x0F, buffer_size_.X * buffer_size_.Y,Coor, &dw);
}

COORD CRenderManager::getBufferSize()
{
	return buffer_size_;
}


