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
		// �θ� �Լ� ȣ��. [1/23/2014 Um]
		if(AScene::initialize())
		{
			// ������ ���ÿ� �߰��� layer�� �θ� Scene�� release(=delete) �Ǹ鼭 �ڵ����� release ��. [1/23/2014 Um]
			addLayer(new CExamLayer2);
			addLayer(new CExamLayer3);
		}
		return true;
	}
};

#endif // TG__EXAMSCENE00__H