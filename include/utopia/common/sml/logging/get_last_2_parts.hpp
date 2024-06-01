#pragma once
#include <boost/regex.hpp>

#include <string>


namespace utopia::common {

inline std::string get_last_two_parts(const std::string &full_name) {
  boost::regex e(".*::(.*)::(.*)$");
  boost::smatch match;

  if (boost::regex_search(full_name, match, e) && match.size() > 2) {
    std::string result = match[1] + "::" + match[2];
    if (!result.empty() && result.back() == '>') {
      result.pop_back(); // remove the trailing '>'
    }
    return result;
  } else {
    return full_name;
  }
}

} // namespace utopia::common

