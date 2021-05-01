#ifndef TG__EXAMLAYER2_1__H
#define TG__EXAMLAYER2_1__H

class CExamLayer2_1 : public ALayer
{
public:
	CExamLayer2_1():temp_value_(0){}
	~CExamLayer2_1(){}

	virtual void update();
	virtual void render();
private:
	int temp_value_;
};

#endif // TG__EXAMLAYER2_1__H