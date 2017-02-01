#pragma once
class Subsystem {
public:
	explicit Subsystem(const std::string& name);
	virtual ~Subsystem();


	void SetDefaultCommand(command* comand);
};


