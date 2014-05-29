#ifndef SPAN_H_
#define SPAN_H_

#include "vector2.h"

class span {
public:
	span(vector2 a, int x_1, vector2 b, int x_2);
	int get_x_1();
	int get_x_2();
	vector2* get_uv_a();
	vector2* get_uv_b();
	void set_x_1(int i);
	void set_x_2(int i);
	void set_uv_a(vector2* v);
	void set_uv_b(vector2* v);
	virtual ~span();
private:
	vector2 uv_a;
	vector2 uv_b;
	int x_1;
	int x_2;
};

#endif /* SPAN_H_*/