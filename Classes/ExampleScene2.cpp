#include "PreCompiled.h"
#include "ExampleScene2.h"

#include "ExamLayer2_1.h"

CExampleScene2::CExampleScene2()
{

}

CExampleScene2::~CExampleScene2()
{

}

bool CExampleScene2::initialize()
{
	if(AScene::initialize())
	{
		addLayer(new CExamLayer2_1);
		return true;
	}
	return false;
}