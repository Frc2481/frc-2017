#include "pch.h"
#include "RigidTransform2D.h"

RigidTransform2D::RigidTransform2D()
	: m_translation(Translation2D()), m_rotation(Rotation2D())
{

}

RigidTransform2D::RigidTransform2D(const Translation2D &translation, const Rotation2D &rotation)
	: m_translation(translation), m_rotation(rotation)
{

}

RigidTransform2D::RigidTransform2D(const RigidTransform2D &other)
	: m_translation(other.m_translation), m_rotation(other.m_rotation)
{

}

RigidTransform2D::~RigidTransform2D()
{

}

RigidTransform2D RigidTransform2D::fromTranslation(const Translation2D &translation)
{
	return RigidTransform2D(translation, Rotation2D());
}

RigidTransform2D RigidTransform2D::fromRotation(const Rotation2D &rotation)
{
	return RigidTransform2D(Translation2D(), rotation);
}

Translation2D RigidTransform2D::getTranslation() const
{
	return m_translation;
}

Rotation2D RigidTransform2D::getRotation()const
{
	return m_rotation;
}

void RigidTransform2D::setTranslation(const Translation2D &translation) {
	m_translation = translation;
}

void RigidTransform2D::setRotation(const Rotation2D &rotation) {
	m_rotation = rotation;
}

RigidTransform2D RigidTransform2D::transformBy(const RigidTransform2D &other)
{
	return RigidTransform2D(m_translation.translateBy(other.getTranslation().rotateBy(m_rotation)),
		m_rotation.rotateBy(other.getRotation()));
}

RigidTransform2D RigidTransform2D::inverse() {
	Rotation2D rotation_inverted = m_rotation.inverse();
	return RigidTransform2D(m_translation.inverse().rotateBy(rotation_inverted), rotation_inverted);
}

RigidTransform2D RigidTransform2D::interpolate(const RigidTransform2D &other, double x) const {
	if (x <= 0) {
		return RigidTransform2D(*this);
	}
	else if (x >= 1) {
		return RigidTransform2D(other);
	}
	return RigidTransform2D(m_translation.interpolate(other.getTranslation(), x), m_rotation.interpolate(other.getRotation(), x));
}
