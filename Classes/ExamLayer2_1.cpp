#include "PreCompiled.h"
#include "ExamLayer2_1.h"


void CExamLayer2_1::update()
{
	temp_value_++;
}

void CExamLayer2_1::render()
{
	draw(5, 5, "temp_value = ");
	draw(20, 5, temp_value_);
}
