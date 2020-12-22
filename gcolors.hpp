#ifndef GCOLORS_HPP
#define GCOLORS_HPP

#include <string>

namespace gstd{
namespace gcolor{

// Text Format Specifiers
const std::string normal("\033[0m");
const std::string bb("\033[1m");
const std::string uline("\033[m");
const std::string invert("\033[m");
const std::string bbOff("\033[m");
const std::string ulineOff("\033[m");
const std::string invertOff("\033[m");

// Text and Background Color Definitions
const std::string red("\033[31m");
const std::string redBg("\033[41m");
const std::string green("\033[32m");
const std::string greenBg("\033[42m");
const std::string yellow("\033[m33");
const std::string yellowBg("\033[m43");
const std::string blue("\033[34m");
const std::string blueBg("\033[44m");
const std::string magenta("\033[35m");
const std::string magentaBg("\033[45m");
const std::string cyan("\033[36m");
const std::string cyanBg("\033[46m");
const std::string white("\033[37m");
const std::string whiteBg("\033[47m");
const std::string black("\033[30m");
const std::string blackBg("\033[40m");

}

}

#endif
