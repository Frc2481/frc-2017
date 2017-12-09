#pragma once
class Command {
	;
public:

	Command();
	Command(const std::string& name);
	Command(double timeout);
	Command(const std::string& name, double timepout);
}