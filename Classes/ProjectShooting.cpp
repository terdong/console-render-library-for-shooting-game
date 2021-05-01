// ProjectShooting.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "PreCompiled.h"
#include "ExamScene00.h"
#include "ExampleScene2.h"

int _tmain(int argc, _TCHAR argv[])
{
	// 싱글턴 객체라 따로 생성하지말고(생성도 안됨), GetInstanceRef 나 GetInstance 함수를 호출해서 사용. [12/28/2013 Um]
	CRenderManager& render_manager = CRenderManager::GetInstanceRef();
	// 화면 사이즈 입력 [12/28/2013 Um]
	const COORD window_size = {100, 50};
	render_manager.initialize(window_size.X, window_size.Y);

	// 싱글턴 객체라 따로 생성하지말고(생성도 안됨), GetInstanceRef 나 GetInstance 함수를 호출해서 사용. [12/28/2013 Um]
	CSceneManager& scene_manager = CSceneManager::GetInstanceRef();
	
	// FPS 변경할 경우 해당 함수 호출 [12/28/2013 Um]
	scene_manager.setFPS(30);
	
	// 최초 시작할 때 이 함수를 호출해줌. [12/28/2013 Um]
	// 이 함수를 호출하면서 매개변수에 구현한 layer class(예제의 경우 new CExamLayer)를 생성하여 넘겨준다.
	// CLayerManager::Release 호출시 넘겨받은 layer class도 같이 릴리즈(delete) 하므로 따로 delete 해줄 필요가 없다.
	scene_manager.startCreateLayerAndPlay(new CExamScene00);
     
	// 싱글턴 객체 릴리즈. [12/28/2013 Um]
	CRenderManager::Release();
	CSceneManager::Release();

	return 0;
}