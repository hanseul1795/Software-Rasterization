#include "../include/Triangle.h"

using namespace Toolbox;

Triangle::Triangle(Vertex& p_v0, Vertex& p_v1, Vertex& p_v2) : m_v0(p_v0.position.x, p_v0.position.y), m_v1(p_v1.position.x, p_v1.position.y), m_v2(p_v2.position.x, p_v2.position.y), m_aabb(Vec2(0, 0), Vec2(0, 0))
{
	m_V0 = Vec2(m_v2.x - m_v0.x, m_v2.y - m_v0.y);
	m_V1 = Vec2(m_v1.x - m_v0.x, m_v1.y - m_v0.y);
	m_d00 = m_V0.x * m_V0.x + m_V0.y * m_V0.y;
	m_d01 = m_V0.x * m_V1.x + m_V0.y * m_V1.y;
	m_d10 = m_V1.x * m_V0.x + m_V1.y * m_V1.y;
	m_d11 = m_V1.x * m_V1.x + m_V1.y * m_V1.y;
	m_Denom = 1.0f / (m_d00 * m_d11 - m_d01 * m_d01);
}
	

Vec3& Triangle::Barycentric(Vec2& p_v0, Vec2& p_point)
{
	const float x = p_point.x - p_v0.x;
	const float y = p_point.y - p_v0.y;

	const float d02 = m_V0.x * x + m_V0.y * y;
	const float d12 = m_V1.x * x + m_V1.y * y;
	const float v = (m_d11 * d02 - m_d01 * d12) * m_Denom;
	const float u = (m_d00 * d12 - m_d01 * d02) * m_Denom;

	m_barycentric.x = v;
	m_barycentric.y = u;
	m_barycentric.z = 1.0f - v - u;

	return m_barycentric;
}

Toolbox::Vec3& Triangle::Barycentric2(const float p_vertexX, const float p_vertexY, const float p_pointX, const float p_pointY)
{
	const float x = p_pointX - p_vertexX;
	const float y = p_pointY - p_vertexY;

	const float d02 = m_V0.x * x + m_V0.y * y;
	const float d12 = m_V1.x * x + m_V1.y * y;
	const float v = (m_d11 * d02 - m_d01 * d12) * m_Denom;
	const float u = (m_d00 * d12 - m_d01 * d02) * m_Denom;

	m_barycentric.x = v;
	m_barycentric.y = u;
	m_barycentric.z = 1.0f - v - u;

	return m_barycentric;
}

AABB& Triangle::GetAABB()
{
	m_aabb.minPoint.x = std::min(std::min(m_v0.x, m_v1.x), m_v2.x);
	m_aabb.minPoint.y = std::min(std::min(m_v0.y, m_v1.y), m_v2.y);

	m_aabb.maxPoint.x = std::max(std::max(m_v0.x, m_v1.x), m_v2.x);
	m_aabb.maxPoint.y = std::max(std::max(m_v0.y, m_v1.y), m_v2.y);

	return m_aabb;
}

float Triangle::CrossProduct(Vertex& p_v0, Vertex& p_v1, Vertex& p_v2)
{
	return	  (p_v1.position.x - p_v0.position.x)
			* (p_v2.position.y - p_v0.position.y)
			- (p_v1.position.y - p_v0.position.y)
			* (p_v2.position.x - p_v0.position.x);
}

Vec2& Triangle::getV0()
{
	return m_v0;
}

Vec2& Triangle::getV1()
{
	return m_v1;
}

Vec2& Triangle::getV2()
{
	return m_v2;
}