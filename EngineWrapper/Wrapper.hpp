#include "Subject.hpp"

#include <vector>
#include <utility>
#include <string>
#include <functional>


template <typename T>
using InputArgs = std::vector<std::pair<std::string, T>>;


template <typename T>
class Wrapper {
private:
	std::function<T(const std::vector<T>& args_vec)> function;
	std::vector<std::string> args_names;
	std::vector<T> args_values;
public:
	template <typename Object, typename ...Arguments>

	Wrapper(Object* object, T(Object::* func)(Arguments...), const InputArgs<T> input_args) {
		if (input_args.size() != sizeof...(Arguments)) {
			throw std::exception{ "ERROR: The number of function arguments and input arguments does not match" };
		}
		for (auto& arg : input_args) {
			args_names.push_back(arg.first);
			args_values.push_back(arg.second);
		}


	}
};