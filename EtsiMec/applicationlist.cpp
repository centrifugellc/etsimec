/*
 ___ ___ __     __ ____________
|   |   |  |   |__|__|__   ___/  Ubiquitout Internet @ IIT-CNR
|   |   |  |  /__/  /  /  /      C++ ETSI MEC library
|   |   |  |/__/  /   /  /       https://github.com/ccicconetti/etsimec/
|_______|__|__/__/   /__/

Licensed under the MIT License <http://opensource.org/licenses/MIT>.
Copyright (c) 2019 Claudio Cicconetti https://ccicconetti.github.io/

Permission is hereby  granted, free of charge, to any  person obtaining a copy
of this software and associated  documentation files (the "Software"), to deal
in the Software  without restriction, including without  limitation the rights
to  use, copy,  modify, merge,  publish, distribute,  sublicense, and/or  sell
copies  of  the Software,  and  to  permit persons  to  whom  the Software  is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE  IS PROVIDED "AS  IS", WITHOUT WARRANTY  OF ANY KIND,  EXPRESS OR
IMPLIED,  INCLUDING BUT  NOT  LIMITED TO  THE  WARRANTIES OF  MERCHANTABILITY,
FITNESS FOR  A PARTICULAR PURPOSE AND  NONINFRINGEMENT. IN NO EVENT  SHALL THE
AUTHORS  OR COPYRIGHT  HOLDERS  BE  LIABLE FOR  ANY  CLAIM,  DAMAGES OR  OTHER
LIABILITY, WHETHER IN AN ACTION OF  CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE  OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "applicationlist.h"

namespace uiiit {
namespace etsimec {

ApplicationList::ApplicationList(const std::vector<AppInfo>& aAppInfos)
    : rest::DataType() {
  theObject["appInfo"] = web::json::value::array(aAppInfos.size());
  auto& myArray        = theObject["appInfo"].as_array();
  for (size_t i = 0; i < aAppInfos.size(); i++) {
    myArray.at(i) = aAppInfos.at(i).toJson();
  }
}

ApplicationList::ApplicationList(
    const std::map<std::string, AppInfo>& aAppInfos)
    : rest::DataType() {
  theObject["appInfo"] = web::json::value::array(aAppInfos.size());
  size_t i             = 0;
  auto&  myArray       = theObject["appInfo"].as_array();
  for (const auto& elem : aAppInfos) {
    myArray.at(i) = elem.second.toJson();
    i++;
  }
}

} // namespace etsimec
} // namespace uiiit
