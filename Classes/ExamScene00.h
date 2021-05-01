#ifndef TG__EXAMSCENE00__H
#define TG__EXAMSCENE00__H

#include "ExamLayer.h"
#include "ExamLayer2.h"
#include "ExamLayer3.h"
#include "ExamLayer4Fire.h"

class CExamScene00 : public AScene
{
public:
	virtual bool initialize()
	{
		// 부모 함수 호출. [1/23/2014 Um]
		if(AScene::initialize())
		{
			// 생성과 동시에 추가된 layer는 부모 Scene이 release(=delete) 되면서 자동으로 release 됨. [1/23/2014 Um]
			addLayer(new CExamLayer2);
			addLayer(new CExamLayer3);
		}
		return true;
	}
};

#endif // TG__EXAMSCENE00__H