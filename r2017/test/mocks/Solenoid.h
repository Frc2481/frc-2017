#pragma once

class Solenoid {
public:
	Solenoid();
	Solenoid(int moduleNumber, int channel);
	~Solenoid();
	void Set(bool on);
	bool Get() const;
private:
	bool m_on;
};
