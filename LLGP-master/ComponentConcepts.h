#pragma once
#include "Component.h"
#include <concepts>

template<class T>
concept isComponent = std::derived_from<T, LLGP::Component> == true;


