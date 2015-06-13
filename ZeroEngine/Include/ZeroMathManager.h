#pragma once
#include <math.h>
#include <limits>
#include <stdlib.h>

#define ZeroMathMgr ZeroMathManager::Instance()

class ZeroMathManager{
private:
	float m_Sin[360];
	float m_Cos[360];

	ZeroMathManager();
public:
	~ZeroMathManager();

	static ZeroMathManager* Instance();

	template <typename T>
	float DegToRad(T deg){
		return static_cast<float>(Pi * (deg/180.0f));
	}

	template <typename T>
	float RadToDeg(T rad){
		return static_cast<float>(rad * 180.0f/ Pi);
	}

	template <typename T>
	bool InRange(T start,T end,T val){
		if(start < end){
			if( (val > start) && (val < end) ) return true;
			else return false;
		}else{
			if( (val < start) && (val > end) ) return true;
			else return false;
		}
	}

	template <typename T>
	T Max(const T& v1,const T& v2){
		return (v1 > v2) ? v1 : v2;
	}

	template <typename T>
	T Min(const T& v1,const T& v2){
		return (v1 > v2) ? v2 : v1;
	}

	template <typename T,typename U,typename V>
	void Clamp(T& arg,const U& minVal,const V& maxVal){
		if( arg < (T)minVal )
			arg = (T)minVal;
		if( arg > (T)maxVal )
			arg = (T)maxVal;
	}
	//-------------------------- Rand Functions --------------------------//

	int RandInt(int x,int y);
	float RandFloat(float x,float y);

	//-------------------------- Tri Functions --------------------------//

	template <typename T>
	float Sin(T sin){
		while(sin < 0)
			sin += 360;
		return m_Sin[static_cast<int>(sin)%360];
	}
	template <typename T>
	float Cos(T cos){
		while(cos < 0)
			cos += 360;
		return m_Cos[static_cast<int>(cos)%360];
	}

	//-------------------------- Constants --------------------------//

	const int MaxInt;
	const double MaxDouble;
	const double MinDouble;
	const float MaxFloat;
	const float MinFloat;

	const float Pi;
};