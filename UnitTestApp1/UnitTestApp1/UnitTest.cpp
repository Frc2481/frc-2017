#include "pch.h"
#include "CppUnitTest.h"
#include "util\Rotation2D.h"
#include "util\Translation2D.h"
#include "util\RigidTransform2D.h"
#include "util\InterpolatingDouble.h"
#include "util\InterpolatingMap.h"
#include "util\GoalTrack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

//namespace UnitTestApp1
//{
    TEST_CLASS(Translation2Dtest)
    {
	public:
		TEST_METHOD(testTranslateBy)
        {
			Translation2D translation(1, 2);
			Translation2D actual = translation.translateBy(Translation2D(2, 3));
			Assert::AreEqual(3.0, actual.getX());
			Assert::AreEqual(5.0, actual.getY());
        }

		TEST_METHOD(testTranslateByNeg) {
			Translation2D translation(1, 2);
			Translation2D actual = translation.translateBy(Translation2D(-2, -3));
			Assert::AreEqual( -1.0, actual.getX());
			Assert::AreEqual(-1.0, actual.getY());
		}

		TEST_METHOD(testNorm)
		{
			Translation2D translation(1, 2);
			double actual = translation.norm();
			Assert::AreEqual( 2.23607, actual, 1E-3);
		}

		TEST_METHOD(testInverse)
		{
			Translation2D translation(1, 2);
			Translation2D  actual = translation.inverse();
			Assert::AreEqual(-1.0, actual.getX());
			Assert::AreEqual( -2.0, actual.getY());
		}

		TEST_METHOD(testRotateBy)
		{
			Translation2D translation(1, 2);
			Translation2D actual = translation.rotateBy(Rotation2D::fromDegrees(90));
			Assert::AreEqual(-2.0, actual.getX(), 1E-3);
			Assert::AreEqual( 1.0, actual.getY(), 1E-3);
		}

		TEST_METHOD(testInterpolate)
		{
			Translation2D translation1(1.5, 2);
			Translation2D translation2(-4, -3);
			Translation2D interpolated = translation1.interpolate(translation2, 0.5);
			Assert::AreEqual(-1.25, interpolated.getX(), 1E-3);
			Assert::AreEqual(-0.5, interpolated.getY(), 1E-3);
		}
    };
	TEST_CLASS(Rotation2DTest)
	{
		TEST_METHOD(testFromRadadians)
		{
			Rotation2D actual = Rotation2D::fromRadians(M_PI/3);
			Assert::AreEqual(0.866, actual.getSin(), 1E-3);
			Assert::AreEqual(0.5, actual.getCos(), 1E-3);
		}

		TEST_METHOD(testFromDegrees)
		{
			Rotation2D actual = Rotation2D::fromDegrees(60);
			Assert::AreEqual(0.866, actual.getSin(), 1E-3);
			Assert::AreEqual(0.5, actual.getCos(), 1E-3);
		}

		TEST_METHOD(testRotateBy)
		{
			Rotation2D rotation = Rotation2D::fromDegrees(60);
			Rotation2D actual = rotation.rotateBy(Rotation2D::fromDegrees(90));
			Assert::AreEqual(0.5, actual.getSin(), 1E-3);
			Assert::AreEqual(-0.866, actual.getCos(), 1E-3);
		}

		TEST_METHOD(testInverse)
		{
			Rotation2D rotation = Rotation2D::fromDegrees(-60);
			Rotation2D actual = rotation.inverse();
			Assert::AreEqual(0.866, actual.getSin(), 1E-3);
			Assert::AreEqual(.5, actual.getCos(), 1E-3);
		}

		TEST_METHOD(testNorm)
		{
			//TODO Figure this out.
		}
		
		TEST_METHOD(testInterpolate)
		{
			Rotation2D rotation1 = Rotation2D::fromDegrees(75);
			Rotation2D rotation2 = Rotation2D::fromDegrees(-40);
			Rotation2D interpolated = rotation1.interpolate(rotation2, 0.5);
			Assert::AreEqual(sin(17.5 * M_PI / 180), interpolated.getSin(), 1E-3);
			Assert::AreEqual(cos(17.5 * M_PI / 180), interpolated.getCos(), 1E-3);
		}
	};

	TEST_CLASS(RigidTransform2DTest) {
		TEST_METHOD(testInverse) {
			RigidTransform2D transform = RigidTransform2D(Translation2D(3, 4), Rotation2D::fromDegrees(45));
			RigidTransform2D actual = transform.inverse();
			Assert::AreEqual(-4.949, actual.getTranslation().getX(), 1E-3);
			Assert::AreEqual(-0.707, actual.getTranslation().getY(), 1E-3);
			Assert::AreEqual(-45, actual.getRotation().getDegrees(), 1E-3);
			RigidTransform2D actual2 = transform.transformBy(actual);
			Assert::AreEqual(0.0, actual2.getTranslation().getX(), 1E-3);
			Assert::AreEqual(0.0, actual2.getTranslation().getY(), 1E-3);
			Assert::AreEqual(0.0, actual2.getRotation().getDegrees(), 1E-3);
		}
		TEST_METHOD(testInterpolate) {
			RigidTransform2D transform1 = RigidTransform2D(Translation2D(1,2), Rotation2D::fromDegrees(45));
			RigidTransform2D transform2 = RigidTransform2D(Translation2D(3,4), Rotation2D::fromDegrees(90));
			RigidTransform2D interpolated = transform1.interpolate(transform2, 0.5);
			Assert::AreEqual(2.0, interpolated.getTranslation().getX(), 1E-3);
			Assert::AreEqual(3.0, interpolated.getTranslation().getY(), 1E-3);
			Assert::AreEqual(sin(67.5 * M_PI / 180), interpolated.getRotation().getSin(), 1E-3);
			Assert::AreEqual(cos(67.5 * M_PI / 180), interpolated.getRotation().getCos(), 1E-3);
		}
	};
	TEST_CLASS(testInterpolatingDouble) {
		TEST_METHOD(interpolate) {
			InterpolatingDouble double1 = InterpolatingDouble(1.0);
			InterpolatingDouble double2 = InterpolatingDouble(2.0);
			InterpolatingDouble interpolated = double1.interpolate(double2, 0.5);
			Assert::AreEqual(1.5, interpolated.m_value, 1E-3);
		}
		TEST_METHOD(inverseInterpolate) {
			InterpolatingDouble double1 = InterpolatingDouble(1.0);
			InterpolatingDouble double2 = InterpolatingDouble(2.0);
			InterpolatingDouble query = InterpolatingDouble(1.5);
			double inversed = double1.inverseInterpolate(double2, query);
			Assert::AreEqual(0.5, inversed, 1E-3);
		}
		TEST_METHOD(testOverrideOperator) {
			InterpolatingDouble double1 = InterpolatingDouble(1.0);
			InterpolatingDouble double2 = InterpolatingDouble(2.0);
			Assert::AreEqual(true, double1 < double2);
			Assert::AreEqual(false, double2 < double1);
		}
	};
	TEST_CLASS(testInterpolatingMap) {
		TEST_METHOD(putTest) {
			InterpolatingMap<InterpolatingDouble, InterpolatingDouble> map1(50);
			map1.put(InterpolatingDouble(1.0), InterpolatingDouble(0.0));
			map1.put(InterpolatingDouble(2.0), InterpolatingDouble(10.0));
			Assert::AreEqual(7.5, map1.getInterpolated(InterpolatingDouble(1.75)).m_value);
		}
	};
	TEST_CLASS(testGoalTrack) {
		TEST_METHOD(smoothTest) {
			GoalTrack gt = GoalTrack(10.0, Translation2D(1, 1), 1);
			gt.tryUpdate(10.01, Translation2D(4, 4));	
			gt.tryUpdate(10.02, Translation2D(5, 5));
			gt.tryUpdate(10.03, Translation2D(2, 2));
			Translation2D actual = gt.getSmoothPosition();
			Assert::AreEqual(3.0, actual.getX());
			Assert::AreEqual(3.0, actual.getY());
		}
		TEST_METHOD(tryUpdateTest) {
			GoalTrack gt = GoalTrack(10.0, Translation2D(1, 1), 1);
			Assert::AreEqual(true, gt.tryUpdate(10.2, Translation2D(2, 2)));
			Assert::AreEqual(false, gt.tryUpdate(10.2, Translation2D(30, 30)));
			
			//Force track to die
			gt.tryUpdate(11.0, Translation2D(30, 30));
			Assert::AreEqual(false, gt.tryUpdate(11.1, Translation2D(33, 33)));
		}
		TEST_METHOD(latestTimestampTest) {
			GoalTrack gt = GoalTrack(10.0, Translation2D(1, 1), 1);
			Assert::AreEqual(10.0, gt.getLatestTimestamp());
			gt.tryUpdate(11.0, Translation2D(1, 1));
			Assert::AreEqual(11.0, gt.getLatestTimestamp());
			gt.tryUpdate(12.0, Translation2D(30, 30));
			Assert::AreEqual(0.0, gt.getLatestTimestamp());
		}
	};
//}