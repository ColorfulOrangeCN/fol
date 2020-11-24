#ifndef _FOL_DEFINATION_
#define _FOL_DEFINATION_
#include <utility>
#define range(container) (std::make_pair((container).begin(), (container).end()))
#define apply_pair(pr) (rg).first, (rg).second
#define apply_container(container) (container).begin() (container).end()
// You can do like this:
// sort(apply_container(container));
#endif
