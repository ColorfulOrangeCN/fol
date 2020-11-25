#ifndef _FOL_DEFINATION_
#define _FOL_DEFINATION_

#include <utility>

#define range(container) (std::make_pair((container).begin(), (container).end()))
#define apply_pair(pr) (pr).first, (pr).second
#define apply_container(container) (container).begin(), (container).end()

#endif
