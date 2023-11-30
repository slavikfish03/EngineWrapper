#include "Subject.hpp"

#include <vector>
#include <utility>
#include <string>
#include <functional>
#include <map>

template <typename T>
using InputArgs = std::vector<std::pair<std::string, T>>;

template <typename T>
using MapArgs = std::map<std::string, T>;


template <typename T>
class Wrapper {
private:
	std::function<T(const std::vector<T>& args_vec)> function;
	std::vector<std::string> args_names;
	std::vector<T> args_values;

	template<typename Object, typename Method, size_t... Is>
	T callFunc(Subject* subject, Method method,
		const std::vector<int> args, std::index_sequence<Is...>)
	{
		return((subject->*method)(args[Is]...));
	}

public:
	template <typename Object, typename ...Arguments>

	Wrapper(Object* object, T(Object::* method)(Arguments...), const InputArgs<T> input_args) {
		if (input_args.size() != sizeof...(Arguments)) {
			throw std::exception{ "ERROR: The number of function arguments and input arguments does not match" };
		}
		for (auto& arg : input_args) {
			args_names.push_back(arg.first);
			args_values.push_back(arg.second);
		}

		function = [this, object, method](const std::vector<T> vector_args) {
			return(callFunc(object, method, vector_args, std::make_index_sequence<sizeof...(Arguments)>{}));
		};

	}

	T execute(const MapArgs map_args) {
		if (map_args.size() != args_names.size()) {
			return function(args_values);
		}

		std::vector<T> func_args;
		for (auto& name : args_names) {
			auto it = map_args.find(name);
			if (it == map_args.end()) {
				return function(args_values);
			}
			func_args.push_back(it->second);
		}
		return function(func_args);
	}


};