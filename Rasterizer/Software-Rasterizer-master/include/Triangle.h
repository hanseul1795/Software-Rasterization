#pragma once
#include "Vertex.h"
#include "Vec2.h"
#include <algorithm>

struct AABB
{
	Toolbox::Vec2 minPoint;
	Toolbox::Vec2 maxPoint;
	AABB(const Toolbox::Vec2& p_minPoint,const Toolbox::Vec2& p_maxPoint) : minPoint(p_minPoint), maxPoint(p_maxPoint) {};
};

class Triangle
{
public:
	Triangle(Vertex& p_v0, Vertex& p_v1, Vertex& p_v2);
	Toolbox::Vec3& Barycentric(Toolbox::Vec2& p_v0, Toolbox::Vec2&p_point);
	Toolbox::Vec3& Barycentric2(const float p_vertexX, const float p_vertexY, const float p_pointX, const float p_pointY);
	AABB& GetAABB();
	static float CrossProduct(Vertex& p_v0, Vertex& p_v1, Vertex& p_v2);
	Toolbox::Vec2& getV0();
	Toolbox::Vec2& getV1();
	Toolbox::Vec2& getV2();
private:
	Toolbox::Vec2 m_v0;
	Toolbox::Vec2 m_v1;
	Toolbox::Vec2 m_v2;
	Toolbox::Vec2 m_V0;
	Toolbox::Vec2 m_V1;
	float m_d00;
	float m_d11;
	float m_d01;
	float m_d10;
	float m_Denom;

	AABB m_aabb;
	Toolbox::Vec3 m_barycentric;
};