#include <iostream>
#include <string>
#include <time.h>
#include <iomanip>

using namespace std;

struct Time
{
	int hours;
	int minutes;
	int seconds;
};



void timeToSeconds(const Time start, const Time end, long& totalSeconds)
{
	totalSeconds = start.hours * 3600 + start.minutes * 60 + start.seconds + end.hours * 3600 + end.minutes * 60 + end.seconds;
}

void secondsToTime(const long totalSeconds, Time& totalTime) {

	totalTime.hours = totalSeconds / 3600 >= 24 ? totalSeconds / 3600 % 24 : totalSeconds / 3600;
	
	int remainingSeconds = totalSeconds % 3600;
	totalTime.minutes = remainingSeconds / 60;
	totalTime.seconds = remainingSeconds % 60;
}


int main()
{
	Time start, end;
	char ch;
	cout << "Input start time: ";
	cin >> start.hours >> ch >> start.minutes >> ch >> start.seconds;
	cout << "Input end time: ";
	cin >> end.hours >> ch >> end.minutes >> ch >> end.seconds;


	long totalSeconds;
	timeToSeconds(start, end, totalSeconds);

	Time totalTime;
	secondsToTime(totalSeconds, totalTime);
	cout << "Total time: " << setw(2) << setfill('0') << totalTime.hours << ":" << setw(2) << setfill('0') << totalTime.minutes << ":" << setw(2) << setfill('0') << totalTime.seconds;

}

