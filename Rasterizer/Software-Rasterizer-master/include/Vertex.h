#pragma once
#include "Mat4.h"
#include "Color.h"
#include "Vec2.h"

struct Vertex
{
	Toolbox::Vec3 position;
	Toolbox::Vec4 normal;
	Color color;
	Toolbox::Vec2 texCoordinate;

	Vertex(const float p_x, const float p_y, const float p_z)
	{
		position.x = p_x;
		position.y = p_y;
		position.z = p_z;
		normal.x = 0;
		normal.y = 0;
		normal.z = 0;
		normal.w = 0;
	}

	Vertex(const Toolbox::Vec3& p_position)
	{
		position.x = p_position.x;
		position.y = p_position.y;
		position.z = p_position.z;
		normal.x = 0;
		normal.y = 0;
		normal.z = 0;
		normal.w = 0;
	}

	Vertex(const Toolbox::Vec3& p_position, const Toolbox::Vec2& p_textureCoordinates)
	{
		position.x = p_position.x;
		position.y = p_position.y;
		position.z = p_position.z;
		normal.x = 0;
		normal.y = 0;
		normal.z = 0;
		normal.w = 0;
		texCoordinate.x = p_textureCoordinates.x;
		texCoordinate.y = p_textureCoordinates.y;
	}

	void SetColor(Color& p_color)
	{
		color.r = p_color.r;
		color.g = p_color.g;
		color.b = p_color.b;
		color.a = p_color.a;
	}
	void SetColor(const float p_r, const float p_g, const float p_b, const float p_a)
	{
		color.a = p_a;
		color.r = p_r;
		color.g = p_g;
		color.b = p_b;
	}

	Vertex& NormalTransform(const Toolbox::Mat4& p_transform)
	{
		this->normal = (p_transform * this->normal);
		normal.Normalize();
		return *this;
	}

	Vertex& VertexTransform(const Toolbox::Mat4& p_transform)
	{
		Toolbox::Vec4 vector4 = p_transform * Toolbox::Vec4(position);
		vector4.Homogenize();
		this->position.x = vector4.x;
		this->position.y = vector4.y;
		this->position.z = vector4.z;
		return *this;
	}

	Vertex FirstTransform(const Toolbox::Mat4& p_transform, const Toolbox::Mat4& p_normaltransform)
	{
		const Toolbox::Vec4 vector4 = p_transform * Toolbox::Vec4(position);
		Vertex temp(Toolbox::Vec3(vector4.x, vector4.y, vector4.z));
		temp.normal = p_normaltransform * normal;
		temp.normal.Normalize();
		return temp;
	}

	Vertex& operator=(const Vertex& p_other)
	{
		this->position = p_other.position;
		this->normal = p_other.normal;
		this->color = p_other.color;
		this->texCoordinate = p_other.texCoordinate;
		return *this;
	}
};