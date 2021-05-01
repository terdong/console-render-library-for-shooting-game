//////////////////////////////////////////////////////////////////////////
/*
 *	테스트용 코드들입니다. [12/28/2013 Um]
 */
//////////////////////////////////////////////////////////////////////////

static int g_nScreenIndex;  //화면을 표시할 스크린의 번호
static HANDLE g_hScreen[2];  //화면 스크린

//AllocConsole();
//freopen( "CONOUT$",  "wt", stderr);

//printf_s("This is Console Test! \n");

// 해제할때
//FreeConsole();

//============================================================
//Desc : ScreenInit()는 두개의 화면 버퍼를 설정
//Date : 2013.09.12
void ScreenInit()
{
	//화면 생성
	g_hScreen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
		0, NULL,
		CONSOLE_TEXTMODE_BUFFER, NULL);
	g_hScreen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
		0, NULL,
		CONSOLE_TEXTMODE_BUFFER, NULL);
	//커서를 보이지 않도록
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 1;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(g_hScreen[0], &cci);
	SetConsoleCursorInfo(g_hScreen[1], &cci);
}

//============================================================
//Desc : 화면 두 개를 번갈아가면서 출력
void ScreenFlipping()
{
	SetConsoleActiveScreenBuffer(g_hScreen[g_nScreenIndex]); //화면 출력
	g_nScreenIndex = !g_nScreenIndex;       //0과 1로 계속 바뀜
}

//============================================================
//Desc : 화면 버퍼를 깨끗이 만들어 줌
void ScreenClear()
{
	COORD Coor = {0,0};
	DWORD dw;
	FillConsoleOutputCharacter(g_hScreen[g_nScreenIndex], ' ',
		80*25,Coor, &dw);
}

//============================================================
//Desc : 화면을 메모리로부터 제거
void ScreenRelease()
{
	CloseHandle(g_hScreen[0]);
	CloseHandle(g_hScreen[1]);
}

//============================================================
//Desc : 화면에 글자 출력
//Input : x, y는 화면에 출력할 좌표
//   string은 출력할 문자열
void ScreenPrint(int x, int y, char *string)
{
	DWORD dw;
	COORD CursorPosition = {x,y};
	SetConsoleCursorPosition(g_hScreen[g_nScreenIndex], CursorPosition);
	WriteFile(g_hScreen[g_nScreenIndex], string, strlen(string), &dw, NULL);
	//WriteConsoleOutputCharacter()
}

//============================================================
//Desc : 화면에 출력된 글자의 색을 바꾼다
//Input : color는 색 지정(범위 : 0~15)
void SetColor(unsigned short color)
{
	SetConsoleTextAttribute(g_hScreen[g_nScreenIndex], color);
}

#include "CppUnitTest.h"
#include "MyProjectUnderTest.h"
#include <Cpp>