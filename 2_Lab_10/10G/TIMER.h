#pragma once
class TIMER
{
private:
	int secounds=0;
	int minutes=0;
	
public:

	TIMER() {
		secounds = 0;
		minutes = 0;
	}

	TIMER(int Value_secounds) {
		secounds = Value_secounds;
	}

	TIMER(int Value_secounds, int Value_minutes) {
		this->secounds = Value_secounds;
		this->minutes = Value_minutes;
	}
	TIMER(TIMER &obj) {
		this->secounds = obj.secounds;
		this->minutes = obj.minutes;
	}

	void Output();
};

