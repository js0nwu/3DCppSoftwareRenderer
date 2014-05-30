#ifndef SPAN_H_
#define SPAN_H_

#include "vector2.h"

class span {
public:
	span(vector2 a, float z_1, int x_1, vector2 b, float z_2, int x_2);
	int get_x_1();
	int get_x_2();
	vector2* get_uv_a();
	vector2* get_uv_b();
	void set_x_1(int i);
	void set_x_2(int i);
	void set_uv_a(vector2* v);
	void set_uv_b(vector2* v);
	float get_z_1();
	float get_z_2();
	void set_z_1(float z);
	void set_z_2(float z);
	virtual ~span();
private:
	vector2 uv_a;
	vector2 uv_b;
	float z_1;
	float z_2;
	int x_1;
	int x_2;
};

#endif /* SPAN_H_*/