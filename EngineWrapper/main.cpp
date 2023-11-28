#include <iostream>
#include "Subject.hpp"


int main() {
	
	Subject subj;

	Wrapper wrapper(&subj, &Subject::f3i, { {"arg1",0},{"arg2",0} });

	Engine engine;

	engine.register_command(&wrapper, "command1");

	std::cout << engine.execute("command1", { {"arg1",4},{"arg2",5} }) << std::endl;

	return 0;
}