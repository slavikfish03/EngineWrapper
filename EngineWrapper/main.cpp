#include <iostream>
#include "Engine.hpp"


int main() {
	
	Subject subj;

	Wrapper<int> wrapper(&subj, &Subject::f3i, { {"arg1",0},{"arg2",0} });
	Engine engine;
	engine.registerCommand<int>(&wrapper, "command1");
	std::cout << engine.execute<int>("command1", { {"arg1",4},{"arg2",5} }) << std::endl;


	Wrapper<double> wrapper_d(&subj, &Subject::f3d, { {"arg1",0.0},{"arg2",0.0} });
	Engine engine_d;
	engine_d.registerCommand<double>(&wrapper_d, "command1");
	std::cout << engine_d.execute<double>("command1", { {"arg1",3.5},{"arg2",4.5} }) << std::endl;
	
	Wrapper<std::string> wrapper_s(&subj, &Subject::f3s, { {"arg1",""},{"arg2",""} });
	Engine engine_s;
	engine_s.registerCommand<std::string>(&wrapper_s, "command1");
	std::cout << engine_s.execute<std::string>("command1", { {"arg1","Hello"},{"arg2","world"} });

	return 0;
}