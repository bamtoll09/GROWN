#pragma once
#include <windows.h>
#include "ZeroVec.h"

class ZeroRect : public RECT{
public:
	ZeroRect(){Zero();}
	ZeroRect(ZeroVec left_top,ZeroVec bottom_right){Set(left_top,bottom_right);}
	template<typename T,typename U,typename V,typename W>
	ZeroRect(T _left,U _top,V _right,W _bottom){Set(_left,_top,_right,_bottom);}

	void Zero(){left=0L;top=0L;bottom=0L;right=0L;}
	void Set(ZeroVec left_top,ZeroVec bottom_right){
		left = (LONG)left_top.x; top = (LONG)left_top.y;
		right = (LONG)bottom_right.x; bottom = (LONG)bottom_right.y;
	}
	template<typename T,typename U,typename V,typename W>
	void Set(T _left,U _top,V _right,W _bottom){
		left = (LONG)_left; top = (LONG)_top;
		right = (LONG)_right; bottom = (LONG)_bottom;
	}

	void FlipH(){
		Set(-right,top,-left,bottom);
	}
	void FlipV(){
		Set(left,-bottom,right,-top);
	}
};