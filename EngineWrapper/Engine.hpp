#pragma once

#include "Wrapper.hpp"

class Engine {
private:
	std::map<std::string, void*> commands;
public:
	template <typename T>
	bool registerCommand(Wrapper<T>* wrapper, const std::string& command_name) {
		if (commands.find(command_name) != commands.end()) {
			std::cout << "ERROR: This command already registered" << std::endl;
			return false;
		}
		commands[command_name] = wrapper;
		return true;
	}

	template <typename T>
	T execute(const std::string& command_name, const MapArgs<T> map_args) {
		auto it = commands.find(command_name);
		if (it == commands.end()) {
			std::cout << "ERROR: Command was not registered" << std::endl;
			throw std::exception{};
		}
		Wrapper<T>* wrapper = static_cast<Wrapper<T>*>(it->second);
		return wrapper->execute(map_args);
	}
};