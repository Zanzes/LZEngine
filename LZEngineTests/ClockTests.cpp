#include <gtest\gtest.h>
#include <Qt\qtest.h>
#include <Qt\qdebug.h>
#include <iostream>
#include <Timing/SplitTimer.h>
using std::cout;
using LZSoft::Timing::SplitTimer;

TEST(Clock, FrameTimeMeasuring)
{
	SplitTimer clock;

#ifdef OVERNIGHT_TESTS
	EXPECT_TRUE(clock.initialize());
	QTest::qSleep(1000);
	clock.SplitAndReset();
	float timedTime = clock.lastLapTime();
	EXPECT_TRUE(0.9f < timedTime);
	EXPECT_TRUE(timedTime < 1.1f);							
	clock.SplitAndReset();										
	QTest::qSleep(500);
	clock.SplitAndReset();					
	timedTime = clock.lastLapTime();
	EXPECT_TRUE(0.4f < timedTime);
	EXPECT_TRUE(timedTime < 0.6f);

	const int NUM_TESTS = 10 + rand() % 100;
	const float THRESHOLD = 0.01f;
	for (int i = 0; i < NUM_TESTS; i++)
	{
		std::cout << ".";
		int thisTestTimeMiliseconds = rand() % 10000;
		float thisTestTimeSeconds = thisTestTimeMiliseconds / 1000.0f;
		clock.SplitAndReset();
		QTest::qSleep(thisTestTimeMiliseconds);
		clock.SplitAndReset();
		float elapsedSeconds = clock.lastLapTime();
		EXPECT_TRUE((thisTestTimeSeconds - THRESHOLD) < elapsedSeconds);
		EXPECT_TRUE(elapsedSeconds < (thisTestTimeSeconds + THRESHOLD));
	}
#endif

	clock.SplitAndReset();
}